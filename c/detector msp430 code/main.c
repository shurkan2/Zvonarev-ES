#include <intrinsics.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <msp430.h> // тут есть для всех контроллеров

#define TIME_TA0 511 // Сейчас 32 Гц (в 2 раза занижена) 
#define TimeToADJ 255 //ШИМ на регултор напряжения для 28.5 Вольт
#define TimeToComp_default 34 //(1/15 периода сигнала) (чтото вроде ДНУ)

unsigned char intrpt_TA0 = 0;
unsigned char intrpt_TB0 = 0;

// Мой спектр
unsigned short Spectrum[513]; // (в последнем канале  время накопления спектра в секундах)

//Ожидание настройки всех параметров + вычисление времени
#define WaitTIME 2880 //Время ожидания в единицах 1/64 сек. (Сейчас 45 сек) 
unsigned short isWaiting= 1; //Флаг для детектора и сётчик для выдержки времени после запуска
unsigned short timeToConfVoltage = 64*45;

short TimerADetectTime = 0; //Накопления периодов таймера А (сейчас на 64 периода)

unsigned short pulses[10];
unsigned short avg_impuls = 0; // Среднее количесство импульсов
unsigned char i_puls = 0; //Счётчик для импульсов
unsigned char porg_pulses = 100; // В процентах
float EDR = 1.5528285e6; // МЭД. Пока что не определяется

//Измерение Температуры
float tempCurr = 0.0f; // Температура в вольтах
#define CALADC12_15V_30C (*((unsigned int *)0x1A22)) //константа перевода для питания от 2.5 вольт
#define CALADC12_15V_85C (*((unsigned int *)0x1A24))  //константа перевода для питания от 2.5 вольт
float Temperature = -1.0f; // Температура в градусах цельсия

//Стабилизатор напряжения накачки
int Time_TB0 = 120;//209; // Началное время таймера (автоподберётся)
float valL= 1.85,valM = 1+1.125, valH = 2.05; //Константы для альфа 
unsigned short inRangeV_SPM = 0; // Флаг для проверки какое время значение напряжения находится в интересующем нас диапазоне
float spmCurrent = 0; 
float sipmVoltage = 3.0f; // Ток на SPM (при включении ~4,4 Вольта)

void SetVcore (unsigned int level);
 
// Для UART
#define START_BYTE 0x55
char buffer[256];
int buffer_index = 0;
int data_length = 0;
int data_received = 0;

void SendData();
void readMeasures(); //Команда чтения текущих измерений


unsigned int CRC_16_11021( char *buf, int num ){ //Высчитывание CRC
	int i;
	CRCINIRES = 0xFFFF;
	for ( i = 0; i < num; i++)	{CRCDI_L = *buf++;}
	return CRCRESR;
}

void makeTimer_TA0( void ){ // Кодирование таймера
  TA0CCR0 = TIME_TA0; //задаём время работы таймера >> время так же подправить ??
  
  /*Задаём работу таймера:использовать АCLK, считать вверх до значения TIME, Таймер лучше тактировать от ACLK
   частоту делить на 8 и обнуляем его.*/
  TA0CCTL3 = OUTMOD_7;      // CCR3 reset/set
  TA0CCR3 = TimeToADJ;      // CCR3 PWM duty cycle
  
  TA0CCTL4 = OUTMOD_7;          // CCR4 reset/set
  TA0CCR4 = TimeToComp_default; // CCR4 PWM duty cycle
  
  TA0CTL = TASSEL_1 + MC__UP + TACLR; // на 8 делим >> Таймер лучше тактировать от ACLK. и без деления
  TA0CTL |= TAIE;  //(Включить обработчик прерываний таймера) 
}

void makeTimer_TB0( void ){

  TB0CCR0 = Time_TB0; //задаём время работы таймера (есть саморегулирование)
  // Задаём работу таймера:использовать ACLK, считать вверх до значения TIME, и без деления
  TB0CTL = TBSSEL_1 + MC__UP + TBCLR;
  TB0CTL |= TBIE;  //(Включить обработчик прерываний таймера)
}

void makeTimer_TA1( void ){
  TA1CCR0 = 6; 
  TA1CTL = TASSEL_1 + MC_0 + TACLR; // выбираем источник тактирования ACLK, останавливаем таймер и обнуляем его
  //TA1CCTL0 = CCIE; // разрешаем прерывание по достижению значения счетчика
  TA1CTL |= TAIE; // разрешаем общее прерывание таймера
}


void makeSMCLK( void ){
 
//первым делом настроим питание ядра
  SetVcore (0x01);
  SetVcore (0x02);
 // SetVcore (0x03);
  
  __bis_SR_register(SCG0);                  // Disable the FLL control loop
  UCSCTL3 |= SELREF_2;        // Выбираем опорный сигнал для DCO (пункт 5.6.2)	>> все так. но делать это надо в начале настроек, как минимум перед настройкой UCSCTL2
  
  UCSCTL0 = 0x0000;           // устанавливаем DCOx=0, MODx=0 () >> Поле сброса там находится 0х0000. эту команду можно не делать, но она и не мешает.
  UCSCTL1 = DCORSEL_7;        // устанавливаем интервал частот от 8.5 до 19.6 МГц   
  UCSCTL2 = FLLD_0 + 487;     // Через FLL устанавливаем DCOCLK в 16,002MHz ()                    <- 16e6/32768=488. записывать нужно на 1 менше тоесть 487.

  __bic_SR_register(SCG0);    // и после настройки включаем (Enable the FLL control loop)

  __delay_cycles(500000);

  // Loop until XT1,XT2 & DCO fault flag is cleared
  UCSCTL4 = 0 + (SELA__REFOCLK |SELS__DCOCLK | SELM__DCOCLK);  // ACLK будет использовать REFOCLK, SMCLK - DCOCLK, MCLK - DCOCLK
  UCSCTL5 = 0;  // устанаввливаем делитель для ACLK, SMCLK и MCLK в 1 
  do
  {
    UCSCTL7 &= ~(XT2OFFG | XT1LFOFFG | DCOFFG);
                                            // Clear XT2,XT1,DCO fault flags
    SFRIFG1 &= ~OFIFG;                      // Clear fault flags
  }while (SFRIFG1&OFIFG);                   // Test oscillator fault flag

  //далее полезно сделать следующее:

  // Disable SVS
  PMMCTL0_H = PMMPW_H;                // PMM Password
  SVSMHCTL &= ~(SVMHE|SVSHE);         // Disable High side SVS
  SVSMLCTL &= ~(SVMLE|SVSLE);         // Disable Low side SVS
}


void makeADC( void ){
  // настройка АЦП. Ловить будем порядка 30-40 воль, значит делить будем ~ на 16 
  // Analog input A2 for the ADC -> P6.2
   
  REFCTL0 &= ~REFMSTR; //Сброс REFMSTR для передачи управления регистрам управления АЦП12_А  
  
  ADC12CTL0 = ADC12ON + ADC12SHT0_8 + ADC12REFON + ADC12REF2_5V + ADC12MSC; // Включаем АЦП, задаем время дискретизации + ВКЛЮЧАЕМ МУЛЬТИРЕЖИМ
  ADC12CTL1 = ADC12SHP + ADC12CONSEQ_1; // Используем внутренний источник тактирования 
  
  ADC12MCTL0 = ADC12INCH_2; // Выбираем канал АЦП 
  ADC12MCTL1 = ADC12INCH_10  + ADC12SREF_1; // Выбираем встроенный датчик температуры
  ADC12MCTL2 = ADC12INCH_5 ; // Считывать значения с порта 6.5
}

void makeCompB(void){ // Настраиваем компаратор B
  
    CBCTL0 |= (CBIPEN | CBIMEN); // Enable V+, V-;
    CBCTL0 |= (CBIMSEL_4 | CBIPSEL_3);//V+ = CB3 , V- = CB4  
    CBCTL1 &= ~(CBSHORT_L | CBEX); // НЕ (закорачиваем, меняем вход и выход на 0)
    CBCTL1 |= CBF; // ВКЛЮЧИЛ фильтр
    CBCTL1 |= CBPWRMD_1; //Выскоскоросстной режим
    CBCTL3 |= BIT3 | BIT4; // Отключаем буфер на входе P6.3/CB3 и P6.4/CB4
    
    CBCTL3 |= CBPD5; //  Пытаемся выключить CBPD5 P6.5/CB5s
    
    CBCTL1 &= ~CBON;
    CBINT &= ~(CBIFG | CBIIFG); // Clear any errant interrupts
    __delay_cycles(75); // delay for the reference to settle
    
    CBINT |= (CBIE);      // Разрешение прерываний
    CBCTL1 &= ~CBIES; // Выбор активного края прерывания (= Rising edge for CBIFG, falling edge for CBIIFG)
    CBCTL1 |= CBON; //Включение компаратора
}

void makeUART(void){  // Используем USCI_A0 UART (RS-485)

  UCA0CTL1 |= UCSWRST; // **Put state machine in reset**
                      
  UCA0CTL1 |= UCSSEL_2;                     // SMCLK
  
  UCA0BR0 = 138;                              // 16MHz 115200 b/r
  UCA0BR1 = 0;                              // 16MHz 115200 baudrate
  UCA0MCTL = 0;//UCBRS_7;

  // initializate bits
  //Настройка портов USCI UART
  P3DIR |= (BIT1 + BIT2); //Для приёма--передачи
  P3SEL |= (BIT4 + BIT3);
  //Настройка на приём данных
  P3OUT &= ~(BIT1 + BIT2);
  
  
  UCA0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
  UCA0IE |= UCRXIE;                         // Enable USCI_A0 RX interrupt
}

 void stable(void){ // Стабилизация напряжения на SiPM 
   // Значения, в которы я буду стараться держать мою величину  от 32 до 35 В
   float val1 = 32.5, val2 = 34.5;
   float avgVal = (val1+val2)/2, alpha;// alpha - Коэффициент сглаживания
   
   // получаем текущее значение тока, в зависимсти от того, в како мы диапазоне значений,
   // Больше требуеого, в требуемом или выше требуемого, устанавливаем alpha
   ADC12IE = ADC12IE0; // Включаем прерывание АЦП; // Выбираем канал АЦП - P6.2
   ADC12CTL0 |= ADC12ON + ADC12ENC + ADC12SC; // Разрешаем преобразование и запускаем его
   float k=0.01795087, b=0.37080318; // Подобраные параметры (b подобрано "руками")
   sipmVoltage = spmCurrent*k+b;
   (sipmVoltage > val2)?(alpha=valH):(alpha=valL);
   if ((sipmVoltage > val1)&(sipmVoltage < val2)) {
     // Главное, чтобы попытки отрегулироват внутри диапазона не выкидывали за его пределы
     alpha = valM; 
     inRangeV_SPM = 1;
   }
   else inRangeV_SPM=0;
   
   int adiitional_TB0 = round(alpha*(avgVal-sipmVoltage)); //Считаем поправку
   Time_TB0 -= (adiitional_TB0);
   if (Time_TB0 < 1) { // Не даём устоновить время <1. 
     Time_TB0=100; // Выбрасываем на 100 (устойчивость) + 
   }
  TB0CCR0 = Time_TB0; //задаём время работы таймера
  }

void bitInit(void){ //инициализация портов, нужных для программы
  // Сигналы небольшой продолжительности (~1 мкс) будут
  // подавать на выход Р5.7 
  P5DIR |= BIT7;
  P5SEL = 0;
  P5OUT = 0;
  
  // Настраиваем порт для АЦП
  P6SEL |= BIT2; //Чтение напряжения накачки
  P6DIR |= BIT5;  //Выход для сброса конденсатора усилителя
  
  //Для регулирования напряжения в SiPM после стабилизатора (вход FB/ADJ)
  P1DIR |= BIT4;
  P1SEL |= BIT4;
  
  // ДНУ
  P1DIR |= BIT5;
  P1SEL |= BIT5;
  
  //Выход компаратора
  P1DIR |= BIT6;
  P1SEL |= BIT6;
  //Вход компаратора
  P6DIR &= ~(BIT3 | BIT4);      // Как входы компаратора
  P6SEL |= BIT3 | BIT4;         // P6.3 and P6.4 selection for Comparator
  // на ножку "in" TS5A3167DCKR
  P1DIR |= BIT2;
  P1OUT |= BIT2;
}

void sendSpec() { // отправляем текущий спектр (0x4D)
    P3OUT |= (BIT1+BIT2); //Включаем отправку
    
    char mass[1030]; 
    mass[0]=0xAA; mass[1]=0x07; mass[2]=0x04;  mass[3]=0xAD; //Передаём всего 1032 байта с CRC
    mass[4] = avg_impuls & 0xFF; mass[5] = (avg_impuls >> 8) & 0xFF;
    for (int i = 0; i<1024; i++){
      if (i%2) mass[6+i] = (Spectrum[i/2] >> 8) & 0xFF;
      else mass[6+i] = Spectrum[i/2] & 0xFF;
    }
    
    short crc = CRC_16_11021(mass,sizeof(mass));   
    char crc0 = crc & 0xFF;
    char crc1 = (crc >> 8) & 0xFF;
    
    // Send the data packet
    for(int i = 0; i < sizeof(mass); i++){
        UCA0TXBUF = mass[i];
        while(!(UCA0IFG & UCTXIFG));
    }
    UCA0TXBUF = crc0;
    while(!(UCA0IFG & UCTXIFG));
    UCA0TXBUF = crc1;
    while(!(UCA0IFG & UCTXIFG)); 
    
    TA1CTL |= (MC_1 + TBIE); // Включаем приём
}

void clearSpec() { // Очищаем спектр (0x41)
  
    P3OUT |= (BIT1+BIT2); //Включаем отправку
    
    for (unsigned short i; i<sizeof(Spectrum);i++) Spectrum[i]=0;
   
    char mass[] = {0xAA,0x06,0x00,0x41, 0x01}; // 0x02  адрес детектора :)
    
    short crc = CRC_16_11021(mass,sizeof(mass));   
    char crc0 = crc & 0xFF;
    char crc1 = (crc >> 8) & 0xFF;
    
    // Send the data packet
    for(int i = 0; i < sizeof(mass); i++){
        UCA0TXBUF = mass[i];
        while(!(UCA0IFG & UCTXIFG));
    }
    UCA0TXBUF = crc0;
    while(!(UCA0IFG & UCTXIFG));
    UCA0TXBUF = crc1;
    while(!(UCA0IFG & UCTXIFG)); 
    
    TA1CTL |= (MC_1 + TBIE); // Включаем приём
}

void Measures(){ // Чтение измерений, 0x52
    P3OUT |= (BIT1+BIT2); //Включаем отправку
    char* edr_bytes = (char*)&EDR; // От младшего к старшему биту
    char mass[] = {0xAA,0x0E,0x00,0x52, avg_impuls & 0xFF,(avg_impuls >> 8)&0xFF,porg_pulses,
    (short)Temperature,0x02,0x00,edr_bytes[0],edr_bytes[1],edr_bytes[2],edr_bytes[3]};
    
    //Установить статус детектора!! ------------------------------------------------------------------------------------- <<<<<<<<<<<<<<--------------------
    if (!isWaiting){
      mass[8] = 0x00;
    }
    else mass[8] = 0x01;
    
    long crc = CRC_16_11021(mass,sizeof(mass));    
    char crc0 = crc & 0xFF;
    char crc1 = (crc >> 8) & 0xFF;
    
    // Send the data packet
    for(int i = 0; i < sizeof(mass); i++){
        UCA0TXBUF = mass[i];
        while(!(UCA0IFG & UCTXIFG));
    }
    UCA0TXBUF = crc0;
    while(!(UCA0IFG & UCTXIFG));
    UCA0TXBUF = crc1;
    while(!(UCA0IFG & UCTXIFG));
    
    TA1CTL |= (MC_1 + TBIE); // Включаем приём
}

void readMeasures(){ //отправка значений из примера
  P3OUT |= (BIT1+BIT2); //Включаем отправку
  // Construct the data packet
    char data[] = {0xAA,0x00,0x00,0x52,0x08, 0x00, 0x13, 0x14, 0x00, 0x00, 0xCA, 0x4F, 0x2D, 0x33};
    char n0 = sizeof(data) + 5;
    char n1 = (5+sizeof(data)) >> 8;
    data[1]=n0; data[2]=n1;

    short crc = CRC_16_11021(data,sizeof(data));    
    char crc0 = crc & 0xFF;
    char crc1 = (crc >> 8) & 0xFF;

    // Send the data packet
    
    for(int i = 0; i < sizeof(data); i++){
        UCA0TXBUF = data[i];
        while(!(UCA0IFG & UCTXIFG));
    }
    
    UCA0TXBUF = crc0;
    while(!(UCA0IFG & UCTXIFG));
    UCA0TXBUF = crc1;
    while(!(UCA0IFG & UCTXIFG));
    
    TA1CTL |= (MC_1 + TBIE); // Включаем приём
}

int main( void ){
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  
  {bitInit(); // Инициализация всех нужных для программы битов 
  makeSMCLK();
  
  makeTimer_TA0(); // Устанавливаем таймер A0
  makeTimer_TB0(); // Установим таймер накачки
  makeTimer_TA1(); //Выжидание посылки последнего бита
    
  makeCompB(); // Настройка компаратора
  makeADC(); // Запукаем АЦП
  
  makeUART(); 
  }
  while(1){

    if (intrpt_TB0){ // Прерывание для проверки правильности настройки SMCLK
      intrpt_TB0 = 0;//сбрасываем флаг  
      _DINT();
        P5OUT |= BIT7;
        __delay_cycles(55);; // меньше 15 не надо 
        P5OUT &= ~BIT7;
      _EINT();
      
      //stable(); //Стабилизируем значение напряжения
    }  
    
   if (intrpt_TA0){ // Прерывание для проверки правильности настройки SMCLK
      intrpt_TA0 = 0;//сбрасываем флаг  
      if (isWaiting==timeToConfVoltage) TB0CCR0 = 750; // Чтобы долго не набиралось 
      if ((!(isWaiting%5))&(isWaiting>timeToConfVoltage)) stable(); //Стабилизируем значение напряжения 6 раз в сек после выдержки
      if(isWaiting){ //Если пока ждём
        // и не дождаались  ждём ещё. Если время ожидания подошло к концу  больше не ждём перед измереением        
        (isWaiting == WaitTIME) ? (isWaiting=0) : (isWaiting++);
      }
      else{ // Если перестали ждать измерение - начинаем считать время изммерения
        TimerADetectTime++;
        if (TimerADetectTime >= 64){
          TimerADetectTime = 0;
          Spectrum[512]++;
          
          //Вычиление среднего значения
          unsigned long sum = 0;
          for (char i=0;i<10;i++){
            sum+=pulses[i];
          }
          avg_impuls = sum/10;
          sum = 0; //определение погрешности
          for(int i =0; i<sizeof(pulses);i++) sum+=fabs(pulses[i]-avg_impuls);
          porg_pulses = (short)(100*sum/(10*avg_impuls));
          
          (i_puls==9)?(i_puls=0):(i_puls++);
          pulses[i_puls] = 0;
          //Измеряем температуру
             ADC12IE = ADC12IE1; // Включаем прерывание АЦП; // Выбираем датчик теммпературы
             ADC12CTL0 &= ~ADC12SHT0_1;
             ADC12CTL0 |= ADC12ON + ADC12ENC + ADC12SC + ADC12SHT0_8;; // Разрешаем преобразование и запускаем его
             Temperature = (float)(((long)tempCurr - CALADC12_15V_30C) * (85 - 30)) /
              (CALADC12_15V_85C - CALADC12_15V_30C) + 30.0f; 
             ADC12CTL0 &= ~ADC12SHT0_8;
             ADC12CTL0 |= ADC12SHT0_1;
             __bis_SR_register(LPM0_bits + GIE); // Входим в режим LPM3 и включаем глобальные прерывания
          stable(); //Стабилизируем значение напряжения 
          
          
          if (!(Spectrum[512] % 5)){
               /// readMeasures();
               // P3OUT |= (BIT1+BIT2); //Включаем отправку
               // UCA0TXBUF = 0x55;
               // while(!(UCA0IFG & UCTXIFG));
               /// UCA0TXBUF = 0x50;
               /// while(!(UCA0IFG & UCTXIFG));
               /// TA1CTL |= (MC_1 + TBIE); // Включаем приём    
          }
        }
      }
   } 
   
   if(data_received){ //Уже сформированная команда

        // Обработка команды
        unsigned int CRC16;
        int n0 = buffer[1];
        int n1 = buffer[2];
        int cmd = buffer[3];
        int addr = buffer[4];
        
        CRC16 = CRC_16_11021(buffer,(buffer[1] + (buffer[2] << 8)+1));
        
        if(CRC16 == 0){_NOP(); //Тут
            //Что-то делааем с командой
        _DINT();
          switch (cmd){
            case 0x52: {
              Measures();
              break;
            }
            case 0x41: {
              clearSpec();
              break;
            }
            case 0x4D: {
              sendSpec();
              break;
            }
          default: break;
          }
        _EINT();
        }

        // Очитка флагов
        buffer_index = 0;
        data_length = 0;
        data_received = 0;
    }
    __bis_SR_register(LPM0_bits | GIE); //Включаем сон и прерывания c LPM3 (потом все равно придется)
  }
  return 0;
}



// Echo back RXed character, confirm TX buffer is ready first
#pragma vector=USCI_A0_VECTOR
__interrupt void USCI_A0_ISR(void){
    
  switch(__even_in_range(UCA0IV,4)){
  case 0:break;                             // Vector 0 - no interrupt
  case 2: {                                  // Vector 2 - RXIFG             
     char c = UCA0RXBUF;
     if((buffer_index == 0) || (c == START_BYTE)){
        buffer[buffer_index++] = c;
     }
     else if(buffer_index == 1){
        buffer[buffer_index++] = c;
        data_length = c;
     }
     else if(buffer_index == 2){
      buffer[buffer_index++] = c;
      data_length |= c << 8;
     }
     else if((buffer_index < data_length + 5) && (buffer[0])){//Запись только если что--то есть
       buffer[buffer_index++] = c;
       if ((buffer_index - data_length) == 1) data_received = 1;
     }
     /*else if(buffer_index == data_length + 5){
       buffer[buffer_index++] = c;
       data_received = 1;
     } */
     }
    break;
  case 4:break;                             // Vector 4 - TXIFG
  default: break;
  }
}

// Timer0_A5 Interrupt Vector (TAIV) handler
#pragma vector=TIMER0_A1_VECTOR
__interrupt void TIMER0_A1_ISR(void) {// Обработчик прерываний TA0 таймера
  switch(__even_in_range(TA0IV,14)){
    case  0:  break;                        // No interrupt
    case  2:  break;                        // 
    case  4:  break;                        // 
    case  6:  break;                        // 
    case  8:  break;                        // 
    case 10:  break;                        //
    case 12:  break;                        // 
    case 14:
	intrpt_TA0 = 1; // показывает, что прерывания происходят
        break;
    default: break;
  } 
  _BIC_SR_IRQ(LPM0_bits);         // Clear LPM3 bits from 0(SR)
}

#pragma vector=TIMER0_B1_VECTOR
__interrupt void Timer0_B1_ISR (void){
  switch(__even_in_range(TB0IV,14)){
    case  0: break;                          // No interrupt
    case  2: break;                          // 
    case  4: break;                          // 
    case  6: break;                          // 
    case  8: break;                          // 
    case 10: break;                          // 
    case 12: break;                          // 
    case 14:   
        intrpt_TB0 = 1; // показывает, что прерывания происходят
        break;
    default: break;
  }
  _BIC_SR_IRQ(LPM0_bits);         // Clear LPM3 bits from 0(SR)
}

#pragma vector=ADC12_VECTOR
__interrupt void ADC12_ISR (void){
  
  switch(__even_in_range(ADC12IV,34))  {
    case ADC12IV_NONE: break;                 // Vector  0:  No interrupt
    case ADC12IV_ADC12OVIFG: break;           // Vector  2:  ADC overflow
    case ADC12IV_ADC12TOVIFG: break;          // Vector  4:  ADC timing overflow
    case ADC12IV_ADC12IFG0:                   // Vector  6:  ADC12IFG0
       spmCurrent = ADC12MEM0; // Записываем данные в переменную
       ADC12IFG &= ~ADC12IFG0; // Очищаем флаг прерывания
       break;
    case ADC12IV_ADC12IFG1:                   // Vector  8:  ADC12IFG1
       tempCurr = ADC12MEM1;
       ADC12IFG &= ~ADC12IFG1;
       break;
    case ADC12IV_ADC12IFG2:     //Обработка сигналов на компаратор                   // Vector 10:  ADC12IFG2
      if (!isWaiting){ 
        P6SEL &= ~BIT5;
        P6OUT &= ~BIT5;
        Spectrum[ADC12MEM2/4]++; //записываю в массив    
        pulses[i_puls]++;
      }      
        ADC12IFG &= ~ADC12IFG2;
      break;
    case ADC12IV_ADC12IFG3: break;            // Vector 12:  ADC12IFG3
    case ADC12IV_ADC12IFG4: break;            // Vector 14:  ADC12IFG4
    case ADC12IV_ADC12IFG5: break;            // Vector 16:  ADC12IFG5
    case ADC12IV_ADC12IFG6: break;            // Vector 18:  ADC12IFG6
    case ADC12IV_ADC12IFG7: break;            // Vector 20:  ADC12IFG7
    case ADC12IV_ADC12IFG8: break;            // Vector 22:  ADC12IFG8
    case ADC12IV_ADC12IFG9: break;            // Vector 24:  ADC12IFG9
    case ADC12IV_ADC12IFG10: break;           // Vector 26:  ADC12IFG10
    case ADC12IV_ADC12IFG11: break;           // Vector 28:  ADC12IFG11
    case ADC12IV_ADC12IFG12: break;           // Vector 30:  ADC12IFG12
    case ADC12IV_ADC12IFG13: break;           // Vector 32:  ADC12IFG13
    case ADC12IV_ADC12IFG14: break;           // Vector 34:  ADC12IFG14
    case ADC12IV_ADC12IFG15: break;           // Vector 34:  ADC12IFG14
    default: break;
  }
  ADC12IE = 0; // Выключаем прерывание АЦП
  ADC12CTL0 &= ~ADC12ON;  
  P6SEL |= BIT5;
  _BIC_SR_IRQ(LPM0_bits);      // Clear LPM3 bits from 0(SR)
}


#pragma vector=COMP_B_VECTOR
__interrupt void Comp_B_ISR(void) {
    switch (__even_in_range(CBIV, 4)) {
        case CBIV_NONE:
            break;                 // No interrupt
        case CBIV_CBIFG:           // Обработка прерывания компаратора 
          if (CBOUT){
            ADC12IE = ADC12IE2; // Включаем прерывание АЦП; // Выбираем канал АЦП - P6.5
            ADC12CTL0 |= ADC12ON + ADC12ENC + ADC12SC; // Разрешаем преобразование и запускаем его
          }
          CBINT &= ~CBIFG;       // Clear Interrupt flag
          break;
        case CBIV_CBIIFG:          // Обработка прерывания инверсной полярности компаратора
          CBINT &= ~CBIIFG;       // Clear Interrupt flag
          break;
        default: break;
    }
    _BIC_SR_IRQ(LPM0_bits);      // Clear LPM3 bits from 0(SR)
}

#pragma vector=TIMER1_A1_VECTOR
__interrupt void Timer1_A1_ISR(void){
    switch(__even_in_range(TA0IV,14)){
    case  0:  break;                        // No interrupt
    case  2:  break;                        // 
    case  4:  break;                        // 
    case  6:  break;                        // 
    case  8:  break;                        // 
    case 10:  break;                        //
    case 12:  break;                        // 
    case 14:
        P3OUT &= ~(BIT1 + BIT2);
	TA1CTL &= ~(MC_1 + TBIE); // выключение таймера Timer1_A3
        break;
    default: break;
  } 
  _BIC_SR_IRQ(LPM0_bits);         // Clear LPM3 bits from 0(SR)
}

void SetVcore (unsigned int level){
  PMMCTL0_H = PMMPW_H;
  SVSMHCTL = SVSHE | SVSHRVL0 * level | SVMHE | SVSMHRRL0 * level;
  SVSMLCTL = SVSLE | SVMLE | SVSMLRRL0 * level;
  while ((PMMIFG & SVSMLDLYIFG) == 0);
  PMMIFG &= ~(SVMLVLRIFG | SVMLIFG);
  PMMCTL0_L = PMMCOREV0 * level;
  if ((PMMIFG & SVMLIFG))
    while ((PMMIFG & SVMLVLRIFG) == 0);
  SVSMLCTL = SVSLE | SVSLRVL0 * level | SVMLE | SVSMLRRL0 * level;
  PMMCTL0_H = 0x00;
}
