

/// Как в идентифай
#ifndef DRAWSPEC_H_INCLUDED
#define DRAWSPEC_H_INCLUDED

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wingdi.h>
#include <math.h>
#include <time.h>
#include "resource.h"

#define UPD InvalidateRect(hChildWnd, NULL, TRUE);

HINSTANCE instance;
HWND hChildWnd; // окно для рисования спектра
static HWND borderFrame; // Выделение области графика для приближения
static HWND hwndBTNPlusSize, hwndBTNMinusSize, hwndBTNMoveLeft, hwndBTNMoveRight;
static HWND hwndLabelCursor, hwndBTNFullView;

extern HWND hwnd; // Главное окно программы

extern unsigned short Spectrum[512] = {0}; // Наш спектр

double lx,ly,bx,by,umax,umin,vmax,vmin;
int xmax=511,xmin=0,ymax=1,ymin=0;
int xcur = 110;//текущее положение курсора
//Для рисования
int xView, yView; // Размеры экрана
POINT pt = {0};

// Для рамочки выделения
int xPos0, yPos0, lenX=1, lenY=1;
char isFrame = 0;

int randn(double, double);
void updateControls(); // обновляем положение кнопочек и таблички
void xcurMove(signed char); // Обработка передвижения курсора
void zoom(); // Нажатие клавиши "+"
void shrink(); // Нажатие клавиши "-"
void fullView();
void vertChange(BOOL);

void fullView(){
    xmin = 0;
    xmax = 511;
    ymin = 0;
    ymax = Spectrum[xmin];
    for(int i=xmin+1; i<=xmax; i++){
        if(Spectrum[i]>ymax) ymax = Spectrum[i];
    }
    UPD
}

void zoom(){ //Увеличение масштаба
    int dmin = xcur - xmin, dmax = xmax - xcur, dcur = 0; // cur - будем устанавливать
    if (dmin == dmax){
            dcur = dmin/2;
    } else if (dmin < dmax){ dcur = dmin;
    } else if (dmin > dmax) { dcur = dmax;
    }
    if (dcur < 2) dcur = 2;
    xmin = xcur-dcur; xmax = xcur + dcur;
    UPD
}

void shrink(){//Уменьшение масштаба
    int dmin = xcur - xmin, dmax = xmax - xcur, dcur = 0; // cur - будем устанавливать
    if (dmin == dmax){
            dcur = dmin*2;
    } else if (dmin < dmax){ dcur = dmax*1.5;
    } else if (dmin > dmax) { dcur = dmin*1.5;
    }
    if (dcur < 2) dcur = 2;
    xmin = xcur-dcur; xmax = xcur + dcur;
    (xmax > 511)? (xmax = 511) : (xmin < 0)? (xmin=0): (xmin=xmin); // На свякий случай
    UPD
}

int f_x(double x){ // пересчёт физических x в пиксели
    return lx*x+bx;
}

int f_y(double y){ // пересчёт физических y в пиксели
    return ly*y+by;
}

void xcurMove(signed char dx){// Обработка передвижения курсора
    xcur += dx;
    if (xcur > 511) xcur = 511;
    if (xcur > xmax) xmax++;
    if (xcur < 0) xcur = 0; // Не лишаем пользователя возможности смотреть время
    if (xcur < xmin) xmin--;
    UPD
}

void vertChange(BOOL param){
    if (param) ymax*=2;
    else ymax/=2;
    UPD
}

BOOL Line(HDC hdc, int x1, int y1, int x2, int y2){
MoveToEx(hdc, x1, y1, NULL); //сделать текущими координаты x1, y1
return LineTo(hdc, x2, y2); //нарисовать линию
}

LRESULT CALLBACK ChildWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
    HDC hdc; //создаёvoid vertChange(BOOLм контекст устройства
    HPEN hPen; //создаём перо
    //if(hWnd != hChildWnd) return(DefWindowProc(hWnd, message, wParam, lParam)); //освобождаем очередь приложения от нераспознаных
    switch(message){
        case WM_PAINT:{
            //break;
            (xmax > 511)? (xmax = 511) : (xmin < 0)? (xmin=0): (xmin=xmin); // На свякий случай
            PAINTSTRUCT ps; //создаём экземпляр структуры графического вывода
            hdc = BeginPaint(hWnd, &ps);

            //Очистим экран
            ///HPEN hfillpen = CreatePen(PS_NULL,1,RGB(255,255,255));
            ///SelectObject(hdc, hfillpen);

            Rectangle(hdc, umin,vmin-2,umax,vmax+20);
            ///SelectObject(hdc,hPen);

            SetMapMode(hdc, MM_ISOTROPIC); //логические единицы отображаем, как физические
            SetWindowExtEx(hdc, xView, yView, NULL); //Длина осей
            SetViewportExtEx(hdc, xView, -yView, NULL); //Определяем область вывода
            SetViewportOrgEx(hdc, (int)umin, (int)vmax, NULL); //Начало координат

           //Рисуем оси координат
            Line(hdc,0, 0,0,(int)(vmax-vmin));//ось У
            Line(hdc, 0,0,(int)(umax-umin),0);//ось Х
            MoveToEx(hdc,0,0,NULL); //перемещаемся в начало координат

            /* нулю по x соотвесствует всегда  umin. Пересчитываем на lx  рисуем что надо*/
            /* нулю по y соотвесствует всегда  ymin. Пересчитываем на ly  рисуем что надо*/

            hPen=CreatePen(PS_SOLID,1,RGB(255,25,0));
            SelectObject(hdc, hPen);

            //Определение границ рисования

            lx = (umax-umin)/(xmax-xmin);   bx = -xmin*lx;
            ly = (vmax-vmin)/(ymax);   by = -ymin*ly;

            // Риссуем график. Будем последовательно проходится по физ. значениям x. Положение для рисоввания
            BOOL firstCollision = 1;
            for(int i=xmin+1; i<=xmax; i++){
                if (Spectrum[i]<=ymax){
                    LineTo(hdc,  f_x(i), f_y(Spectrum[i]));
                    firstCollision = 1;
                }
                else {
                    if (firstCollision){
                        LineTo(hdc,  f_x(i), f_y(ymax));
                        firstCollision = 0;
                        }
                    MoveToEx(hdc,  f_x(i), f_y(ymax),NULL);
                }
            }

            { // Тут оботражение курсора
                hPen=CreatePen(PS_DASH,2,RGB(0,0,255));
                SelectObject(hdc, hPen);
                Line(hdc,f_x(xcur),f_y(ymin),f_x(xcur),f_y(ymax));
            }
            //синим штришочки
            hPen=CreatePen(1,1,RGB(0,0,255));
            SelectObject(hdc, hPen);

            /// Деления будут наносится по 20 штук на одну ось, можно исправить на нормальные подписи
            // Определение шага между подписями на осях
            int num_x_ticks = 20, num_y_ticks = 20; //Количество штришков
            int y_step = (vmax - vmin) / (num_y_ticks - 1);
            int x_step = (1+xmax-xmin)/15;
            if (x_step < 1) x_step = 1;

            // Подпись оси x
            for (int i = xmin; i <= (xmax); i += x_step) {
                char buf[16];
                Line(hdc,f_x(i),4,f_x(i),-4);
                sprintf(buf, "%d", i);
                TextOut(hdc, f_x(i)-(5+3*log10(1+i)), -10, buf, strlen(buf));
            }
            // Подпись оси y
            for (int i = 0; i <= (vmax-vmin); i += y_step) {
                char buf[16];
                Line(hdc,-3,i,3,i);
                sprintf(buf, "%.0f", (i-by)/ly);
                TextOut(hdc, -(16+7*log10(1+(i-by)/ly)), i+4, buf, strlen(buf));
            }
            ValidateRect(hWnd, NULL); //Обновляем экран
            EndPaint(hWnd, &ps);
            updateControls();
        }//сообщение выхода - разрушение окна
        case WM_DESTROY:
            DeleteObject(hPen); //не забываем уничтожать перья
            return 0;
        case WM_LBUTTONDOWN:{
           if ((LOWORD(lParam)>umin)&(HIWORD(lParam)<vmax)){
                xcur = ((LOWORD(lParam) - (int)umin) - bx)/lx;
                UPD
            }


           //В данный момент не рисуем ничего, приближения нет
           /* isFrame = 1;
            xPos0 = LOWORD(lParam);
            yPos0 = HIWORD(lParam);
            ScreenToClient(hWnd,&pt);
            //pt.x = xPos0; pt.y = yPos0;
            printf("mousedown [%d,%d] ",pt.x,pt.y);
            printf("also known as [%d,%d] \n",xPos0,yPos0);
            borderFrame = CreateWindow("STATIC", "Выделение", WS_VISIBLE | WS_CHILD
                                        | WS_BORDER, xPos0-pt.x, yPos0-pt.y, 1, 1, hChildWnd, NULL, NULL, NULL);*/
        }
        case WM_MOUSEMOVE: {
            /*if(!isFrame) break;
            lenX = LOWORD(lParam) - xPos0;
            lenY = HIWORD(lParam) - yPos0;
            MoveWindow(borderFrame,xPos0,yPos0,lenX,lenY,TRUE);*/
        }
        case WM_LBUTTONUP: {
           /* if(!isFrame) break;
            isFrame = 0;
            int xPos1 = LOWORD(lParam);
            int yPos1 = HIWORD(lParam);
            if ((xPos1-xPos0) <= 0)break; // Рисовать можно српава налево
            printf("mouseup [%d,%d] \n",xPos1,yPos1);
            int newMinX = ((xPos0 - (int)umin) - bx)/lx;
            int newMaxX = ((xPos1 - (int)umin) - bx)/lx;
            xmin = newMinX; xmax = 2+ newMaxX;
            DestroyWindow(borderFrame);
            InvalidateRect(hChildWnd, NULL, TRUE);*/
        }
        case WM_COMMAND: {
            SetFocus(hChildWnd); // Перенаправляем фокус на родит. окно
            // Обработка нажатий на кнопки
            if (lParam == (LPARAM)hwndBTNPlusSize)
                zoom();
            else if (lParam == (LPARAM)hwndBTNMinusSize)
                shrink();
            else if (lParam == (LPARAM)hwndBTNMoveLeft)
                xcurMove(-1);
            else if (lParam == (LPARAM)hwndBTNMoveRight)
                xcurMove(1);
            else if (lParam == (LPARAM)hwndBTNFullView)
                fullView();
        }
        case WM_KEYDOWN: {
            //MessageBox(hWnd,"Нажата клавиша","сообщение", MB_OK);
            if (wParam == VK_RIGHT)
                xcurMove(1);
            else if (wParam == VK_LEFT)
                xcurMove(-1);
            else if (wParam == VK_UP)
                vertChange(1);
            else if (wParam == VK_DOWN)
                vertChange(0);

            break;
        }
        case WM_SIZE:{
            xView=LOWORD(lParam); // Считывание размеров окна
            yView=HIWORD(lParam); //
            umax = (double)(16.8*xView/17);
            umin = (double)(0.5*xView/17);
            vmax = (double)(13*yView/16);
            vmin = (double)(1*yView/40);
            if (umin<33) umin = 33;
            break;
        }
        default:
            return(DefWindowProc(hWnd, message, wParam, lParam)); //освобождаем очередь приложения от нераспознаных
    }
    return 0;
}

int drawSpec(){ // Авторисование включено
    // Отображение окна
    fullView();

    WNDCLASS wcChild = { 0 };
    wcChild.lpszClassName = "ChildWindowClass";
    wcChild.hInstance = instance;
    wcChild.lpfnWndProc = ChildWindowProc;// Создание кнопки "Залить экран белым"
    wcChild.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcChild.hIcon = 0;
    wcChild.lpszMenuName = 0;
    wcChild.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wcChild.style = CS_HREDRAW | CS_VREDRAW;
    wcChild.cbClsExtra = 0;
    wcChild.cbWndExtra = 0;

    RegisterClass(&wcChild);

    ///// -------------------------------------------------------------------------------------------------------------------------------------ДЛЯ ДЕБАГА
    srand(time(NULL));
    for(int i=0;i<512;i++){
        //Spectrum[i] = (unsigned short)(500+(3000+350*rand()*randn(200,75))+15000*randn(315,20));
        //Spectrum[i] = (unsigned short)(100*randn(i,1)+500*randn(400,2));
        /// Spectrum[i] = (unsigned short)(i*(log(1+i)+cos(i*M_PI/180))-i*sin(i/5));
    }

    /*Spectrum[133] = 10000;
    Spectrum[134] = 8000;
    Spectrum[135] = 7000;
    Spectrum[136] = 100;
    Spectrum[137] = 6500;
    Spectrum[138] = 75000;
    Spectrum[139] = 95000;*/

   /* Spectrum[133] = 10000;
    Spectrum[134] = 10004;
    Spectrum[135] = 10003;
    Spectrum[136] = 10050;
    Spectrum[137] = 9999;
    Spectrum[138] = 10002;
    Spectrum[139] = 10003;
    fullView();*/
    ///// ----------------------------------------------------------------------------------------------------------------------------конец---ДЛЯ ДЕБАГА

    hChildWnd = CreateWindow("ChildWindowClass", "Spec", WS_MAXIMIZE |
                             WS_OVERLAPPEDWINDOW , 100, 100, 1680, 868, hwnd, NULL, instance, NULL);
    // Создание кнопки "Залить экран белым"
    hwndBTNPlusSize = CreateWindow("BUTTON", "+",  WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            100, 710, 100, 30, hChildWnd, NULL, instance, NULL);
    hwndBTNMinusSize = CreateWindow("BUTTON", "-",  WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            100, 710, 100, 30, hChildWnd, NULL, instance, NULL);
    hwndBTNMoveLeft = CreateWindow("BUTTON", "<-",  WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            100, 710, 100, 30, hChildWnd, NULL, instance, NULL);
    hwndBTNMoveRight = CreateWindow("BUTTON", "->",  WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            100, 710, 100, 30, hChildWnd, NULL, instance, NULL);
    hwndBTNFullView = CreateWindow("BUTTON", "<-|->",  WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            100, 710, 100, 30, hChildWnd, NULL, instance, NULL);
    hwndLabelCursor = CreateWindow("STATIC", "текст",  WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            100, 710, 100, 30, hChildWnd, NULL, instance, NULL);

    ShowWindow(hChildWnd, SW_SHOWNORMAL);
    UPD
    return 0;
}

int randn(double mu, double sigma) {
    double u1, u2, z;
    u1 = rand() / (double)RAND_MAX;
    u2 = rand() / (double)RAND_MAX;
    z = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
    return mu + sigma * z;
}

void updateControls() { // Обновляем что-то
    int mid_y = (vmax+yView+20)/2;
    int mid_x = xView / 2;
    int bh = 35, bw = 50, bd=15; // Высота и ширина кнопочек + расстояние между ними
    MoveWindow(hwndBTNPlusSize,mid_x+(bd/2),mid_y-bh/2,bw,bh,1);
    MoveWindow(hwndBTNMinusSize,mid_x-(bd/2+bw),mid_y-bh/2,bw,bh,1);
    MoveWindow(hwndBTNMoveLeft,mid_x-(3*bd/2+2*bw),mid_y-bh/2,bw,bh,1);
    MoveWindow(hwndBTNMoveRight,mid_x+(3*bd/2+bw),mid_y-bh/2,bw,bh,1);
    MoveWindow(hwndBTNFullView,mid_x+(4*bd/2+2*bw),mid_y-bh/2,2*bw,bh,1);
    MoveWindow(hwndLabelCursor,umin,vmax+40,100,28,1);

    char buf[50];
    snprintf(buf,50,"x=%d, y=%d",xcur,Spectrum[xcur]);
    SetWindowText(hwndLabelCursor,buf);

    RECT rect = {0,0,xView,yView};
    InvalidateRect(hwndBTNPlusSize,&rect,1);
    InvalidateRect(hwndBTNMinusSize,&rect,1);
    InvalidateRect(hwndBTNMoveLeft,&rect,1);
    InvalidateRect(hwndBTNMoveRight,&rect,1);
    InvalidateRect(hwndBTNFullView,&rect,1);
    InvalidateRect(hwndLabelCursor,&rect,1);
}

#endif // DRAWSPEC_H_INCLUDED
