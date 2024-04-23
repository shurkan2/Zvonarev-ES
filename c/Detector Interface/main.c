#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <commctrl.h>
#include <tchar.h>

#include "DrawSpec.h"

#define ID_LISTVIEW_LOG 3
#define ID_LISTVIEW_STATE 2
#define cbPorts_id 1
// ���������� ����������
// ��� ����������
HWND hwndComboBox;
HWND hwndButtonReadState;
HWND hwndButtonDrawSpec;
HWND hwndButtonReadSpec;
HWND hwndButtonRefresh;
HWND hwndButtonConnect;
HWND hwndButtonSave;
HWND hwndButtonClearSpec; // ��������� ������
HWND hListViewState; LVCOLUMN lvColumnState; LVITEM lvItemState;
HWND hListViewLog;  LVCOLUMN lvColumnLog;
        LVITEM itemLog; unsigned short itemLogNumber=0; //������� �����
HWND infoLabel; // ������� ���������� ������������
HWND hwnd; // ������� ���� ���������
HWND hTable[21]; // ������ ��� �������� ������������ ���� ����� �������
// ���������, ��������� �� �������������
short avg_impuls = -1; // �������� ����� (CPS)
short pgr_impuls = -1; // ����������� �������� �����
unsigned char detStatus = 3; // ������ ��������� (0-���������, 1-������������, 2-���������� 3-������� ����� ������)
char temper = 0; // ����������� � �������� �������
float med = 0.0; // ���, ��� �����
float capVoltage = -1.0; // ���������� �� ������������ (�������)
unsigned short specTime = 0; // ����� ���������� �������
// ��� �����
HANDLE hSerial;
DCB dcbSerialParams = {0};


// ��������� �������
uint16_t crc16_8408(const uint8_t*, size_t); //����������� CRC
int drawSpec(); //��������� ������� (� ��������� ����)
void GetAvailableComPorts(); // �������� ��������� com-������
int makePorts(char*); // ����������� � ����� �� �����
int getSpectrum(); //���������� ������� � ���������
int ClearSpectrum(); // ������� �������
int getState(); // �������� ������ ��������� (������ ������� ������ ������� � ����. ������������)
void updateTable(); // ���������� ������� � �������
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM); // ��������� ��������� ��������� ����
LRESULT CALLBACK ChildWindowProc(HWND, UINT, WPARAM, LPARAM); // ���� ��������� ���� � ��������
void AddLOG(const char, LPTSTR);
int saveToFile();

int ClearSpectrum(){
    BYTE command[] = {0x23, 0x08, 0x00, 0x41, 0x02, 0x00, 0x57, 0xb4};
    BYTE buffer[7];
    DWORD dwBytesRead, dwBytesWritten;
    printf("Step 1 \n");
    if (!SetCommState(hSerial, &dcbSerialParams)){
        printf("Error configuring serial port\n");
        AddLOG(1,"��� ����� � ������ ��� ������� �������");
        CloseHandle(hSerial);
        return 1;
    }

    printf("Step 2 \n");
    if (!WriteFile(hSerial, command, sizeof(command), &dwBytesWritten, NULL)){
        printf("Error writing to serial port\n");
        AddLOG(1,"�� ������� ������� ������� ��� ������� ������� �������");
        CloseHandle(hSerial);
        return 1;
    }

    printf("Step 3 \n");
    if (!ReadFile(hSerial, buffer, sizeof(buffer), &dwBytesRead, NULL)){

        printf("Error reading from serial port\n");
        AddLOG(1,"���������� ��������� ���� ��� ��������� ������ � ������ �������");
        CloseHandle(hSerial);
        return 1;
    }

    printf("Step 4 \n");
    if (dwBytesRead)
        printf("Received %d bytes: %s\n", dwBytesRead, buffer);

    printf("Step 5 \n");
    if (!crc16_8408(buffer, sizeof(buffer))) {
        printf("All done, Received %d bytes: %s\n", dwBytesRead, buffer);
        AddLOG(0,"������ ������, ����� �������");
        }
    else {
        printf("not calculated CRC in getStage \n");
        AddLOG(1,"������ ������ (?), ����� �� �������");
        return 1;
    }
    return 0;
}

int saveToFile(){

    int size = sizeof(Spectrum) / sizeof(Spectrum[0]);
    OPENFILENAME ofn;
    char filename[MAX_PATH] = "";
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFilter = "TexhwndButtonSave;t Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
    ofn.lpstrFile = filename;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
    if (GetSaveFileName(&ofn) == TRUE) {
        FILE* file;
        ///fopen_s(&file, filename, "w");
        file = fopen(filename, "w");
        if (file != NULL) {
            for (int i = 0; i < size; i++) {
                fprintf(file, "%d\n", Spectrum[i]);
            }
            fclose(file);
            printf("Data saved to file.");
            AddLOG(0,"������ ������� � ����");
        } else {
            printf("Error opening file.");
            AddLOG(1,"�� ������� ������� ����");
        }
    } else {
        printf("User cancelled.");
        AddLOG(1,"���������� ����� �������� �������������");
    }
    return 0;
}

uint16_t crc16_8408(const uint8_t *data, size_t length) { //����������� CRC
    uint16_t crc = 0xFFFF;
    for (size_t i = 0; i < length; i++) {
        crc ^= (uint16_t)data[i];
        for (int j = 0; j < 8; j++) {
            if (crc & 0x0001) {
                crc = (crc >> 1) ^ 0x8408;
            } else {
                crc >>= 1;
            }
        }
    }
    if (!crc) AddLOG(1,"H� ������� ����������� �����)");
    return 0;
}

void updateTable(){ // ��������� ������� ������

    lvItemState.iSubItem = 1;
    //LPTSTR str; // ��� ������ �������� ������� ���������
    switch (detStatus){
    case 0: lvItemState.pszText = "��������� � �����"; break;
    case 1: lvItemState.pszText = "������������"; break;
    case 2: lvItemState.pszText = "����������"; break;
    case 3: lvItemState.pszText = "�������, ��������� �����"; break;
    default: lvItemState.pszText = "�� ����������";
    }
    lvItemState.iItem = 0;
    ListView_SetItem(hListViewState, &lvItemState);

    // Update Table:

    wchar_t wstr[5][16]; //����� ��� �������� �������� � ��������� ����
    sprintf(wstr[0],"%d",temper);
    sprintf(wstr[1],"%d",avg_impuls);
    sprintf(wstr[2],"%d",pgr_impuls);

    if (med != 0) {sprintf(wstr[3],"%.4e",med);}
    else {sprintf(wstr[3],"%s","�� ����������");}

    if (specTime != 0) {sprintf(wstr[4],"%.4e",specTime);}
    else {sprintf(wstr[4],"%s","�� ����������");}

    for (char i = 0; i<5; i++){
        lvItemState.iItem = i+1;
        lvItemState.pszText = (LPTSTR)wstr[i];
        ListView_SetItem(hListViewState, &lvItemState);
    }
    AddLOG(0,"������� ������ ���������");
}

int getState(){ // �������� ������ � ��������� ���������
    BYTE command[] = {0x23, 0x08, 0x00, 0x52, 0x02, 0x00 ,0xA6, 0xDE}; //23 08 00 52 02 00 a6 de
    BYTE buffer[13];
    DWORD dwBytesRead, dwBytesWritten;

    if (!SetCommState(hSerial, &dcbSerialParams)){
        printf("Error configuring serial port\n");
        AddLOG(1,"��� ����� � ������ ��� ������ ������");
        CloseHandle(hSerial);
        return 1;
    }

    if (!WriteFile(hSerial, command, sizeof(command), &dwBytesWritten, NULL)){
        printf("Error writing to serial port\n");
        AddLOG(1,"�� ������� ������� ������� ��� ������� ������ ������");
        CloseHandle(hSerial);
        return 1;
    }

        if (!ReadFile(hSerial, buffer, sizeof(buffer), &dwBytesRead, NULL)){

            printf("Error reading from serial port\n");
            AddLOG(1,"���������� ��������� ���� ��� ��������� ������ ��������� ���������");
            CloseHandle(hSerial);
            return 1;
        }
        if (dwBytesRead)
            printf("Received %d bytes: %s\n", dwBytesRead, buffer);

    if (!crc16_8408(buffer, sizeof(buffer))) {
        printf("All done, Received %d bytes: %s\n", dwBytesRead, buffer);
        AddLOG(0,"������ �������, ����� �������");
        }
    else {
        printf("not calculated CRC in getStage \n");
        AddLOG(1,"������ �������, ����� �� �������");
        // return 1;
    }

    avg_impuls = buffer[5];
    avg_impuls += (buffer[6] << 8);
    // pgr_impuls = buffer[6];
    temper = buffer[7];
    if (buffer[9]){
        detStatus = 3;
    }
    else {
        detStatus = buffer[8];
    }

   /* char* med_bytes = (char*)&med; // �� �������� � �������� ����
    for (char i=0;i<4;i++){
        med_bytes[i] = buffer[10+i];
    }*/
    updateTable();
    return 0;
}

void GetAvailableComPorts(){ // ��������� combobox �������� ���������� �� ���������
    AddLOG(0,"������� ��������� ������ ��������� ���������");
    SendMessage(hwndComboBox, CB_RESETCONTENT, 0, 0);
    char portNames[256][256];
    DWORD numPorts = 0;
    char allDevices[65535];
    DWORD allDevicesSize = sizeof(allDevices);
    if (QueryDosDevice(NULL, allDevices, allDevicesSize) != 0) {
        char* device = allDevices;
        while (*device != '\0') {
            if (strncmp(device, "COM", 3) == 0) {
                strcpy(portNames[numPorts], device);
                numPorts++;
            }
            device += strlen(device) + 1;
        }
    }
    if (numPorts == 0) {
        SendMessage(hwndComboBox, CB_ADDSTRING, 0, "���������� �� ����������");
    }
    else {
        SendMessage(hwndComboBox, CB_ADDSTRING, 0, "�������� COM-����");
    }
    for (int i = 0; i < numPorts; i++) {
        SendMessage(hwndComboBox, CB_ADDSTRING, 0, (LPARAM)portNames[i]);
        printf("%s\n", portNames[i]);
    }
    SendMessage(hwndComboBox, CB_SETCURSEL, 0, 0);
    //makePorts(portNames[0]);
    AddLOG(0,"������ ��������� ��������� �������");
}

int makePorts(char* name){ // (����������� ��������)
    CloseHandle(hSerial);
    hSerial = CreateFile(name, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (!hSerial == INVALID_HANDLE_VALUE){
        printf("Error opening serial port\n");
        AddLOG(1,"������ ������� ���� ��� ������� �����������");
        return 1;
    }

    TCHAR logMes[255];

    if (!SetCommState(hSerial, &dcbSerialParams))
    {
        printf("Error configuring serial port\n");
        sprintf(logMes, TEXT("%s %s"), "�� ������� ����������� � �����", name);
        AddLOG(1,(LPTSTR)logMes);
        CloseHandle(hSerial);
        return 1;
    }

    sprintf(logMes,TEXT("%s %s"), "���������� � ����� ",name);
    AddLOG(0,(LPTSTR)logMes);
    return 0;
}

int getSpectrum(){ //���������� ������� � ���������

    BYTE command[] = {0x23, 0x08, 0x00, 0x4D, 0x02, 0x00, 0xF4, 0x11}; // 23 08 00 4D 02 00 F4 11
    BYTE buffer[1033];
    DWORD dwBytesRead, dwBytesWritten;

    if (!SetCommState(hSerial, &dcbSerialParams)){
        printf("Error configuring serial port\n");
        AddLOG(1,"��� ����� � ������ ��� ������ �������");
        CloseHandle(hSerial);
        return 1;
    }

    if (!WriteFile(hSerial, command, sizeof(command), &dwBytesWritten, NULL)){
        printf("Error writing to serial port\n");
        AddLOG(1,"�� ���������� �������� ������� ������ �������");
        CloseHandle(hSerial);
        return 1;
    }
        if (!ReadFile(hSerial, buffer, sizeof(buffer), &dwBytesRead, NULL)){

            printf("Error reading from serial port\n");
            AddLOG(1,"�� ������� �������� ������ ��� ������ �������");
            CloseHandle(hSerial);
            return 1;
        }

    if (!crc16_8408(buffer, sizeof(buffer))){
        printf("All done, in getSpectrum \n");
        AddLOG(0,"������ �������, ����������� ����� �������");
        }
    else {
        printf("not calculated CRC in getSpectrum \n");
        AddLOG(1,"������ ������� �������� � ������� (�� ������� �����. �����)");
        return 1;
    }

    avg_impuls = buffer[5];
    avg_impuls += (buffer[6] << 8);

    //specTime = (buffer[5] << 8) + buffer[5] ;

    for (int i = 0; i<1024; i++){
      if (i%2) Spectrum[i/2] += (buffer[7+i] << 8);
      else Spectrum[i/2] = buffer[7+i];
    }

    updateTable();

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) { // ������� ��� ��������� ��������� ����
    switch (uMsg) {
        case WM_CREATE: {
            // �������� ComboBox ��� ������ COM-�����
            hwndComboBox = CreateWindow("COMBOBOX", NULL, CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_CHILD | WS_VISIBLE,
                10, 11, 210, 200, hwnd, cbPorts_id, NULL, NULL);

            // ��������� ������ COM-������
            GetAvailableComPorts();

            // �������� ������ "�������"
            hwndButtonReadState = CreateWindow("BUTTON", "������� ������", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                10, 40, 150, 30, hwnd, NULL, NULL, NULL);

            // �������� ������ "������� ������"
            hwndButtonReadSpec = CreateWindow("BUTTON", "������� ������", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                10, 80, 150, 30, hwnd, NULL, NULL, NULL);
            // �������� ������ "��������"
            hwndButtonDrawSpec = CreateWindow("BUTTON", "�������� ������", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                10, 120, 150, 30, hwnd, NULL, NULL, NULL);
            // �������� ������ "����������� ���������"
            hwndButtonRefresh = CreateWindow("BUTTON", "���������� ���-��", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                230, 10, 200, 30, hwnd, NULL, NULL, NULL);

            // �������� ������ "�������� ������"
            hwndButtonClearSpec = CreateWindow("BUTTON", "�������� ������", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                10, 160, 150, 30, hwnd, NULL, NULL, NULL);

            // �������� ������ "�������� ������"
            hwndButtonSave = CreateWindow("BUTTON", "��������� ������", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                10, 200, 150, 30, hwnd, NULL, NULL, NULL);

            { //�������� �������� � ������� � ��������� ���������
                hListViewState = CreateWindow(WC_LISTVIEW, NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | LVS_REPORT, 200, 100,351, 150, hwnd, (HMENU)ID_LISTVIEW_STATE, NULL, NULL);
                // ��������� �������

                lvColumnState.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
                lvColumnState.cx = 200;
                lvColumnState.pszText = "��������";
                lvColumnState.iSubItem = 0;
                ListView_InsertColumn(hListViewState, 0, &lvColumnState);

                lvColumnState.cx = 100;
                lvColumnState.pszText = "��������";
                lvColumnState.iSubItem = 1;
                ListView_InsertColumn(hListViewState, 1, &lvColumnState);

                lvColumnState.cx = 50;
                lvColumnState.pszText = "��.���.";
                lvColumnState.iSubItem = 2;
                ListView_InsertColumn(hListViewState, 2, &lvColumnState);

                // ��������� ������
                lvItemState.mask = LVIF_TEXT;

                // #define notdef "�� ����������"
                LPTSTR text[6][3] = {{"������ ���������", "�� ����������","-" },
                                    {"�����������","�� ����������","*C"},
                                    {"�������� �����","�� ����������","CPS"},
                                    {"���. ����. �����","�� ����������","%"},
                                    {"���","�� ����������","��/�"},
                                    {"����� ������ �������","�� ����������","�"}};

                for (char i=0;i<6;i++){
                        lvItemState.iItem = i;
                        lvItemState.iSubItem = 0;
                        lvItemState.pszText = text[i][0];
                        ListView_InsertItem(hListViewState, &lvItemState);

                        for(char j=1;j<3;j++){
                            lvItemState.iSubItem = j;
                            lvItemState.pszText = text[i][j];
                            ListView_SetItem(hListViewState, &lvItemState);
                        }
                }
            }

            { //�������� ������� ����
                hListViewLog = CreateWindow(WC_LISTVIEW, NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | LVS_REPORT, 50, 300,  571, 150,  hwnd, (HMENU)ID_LISTVIEW_LOG, NULL, NULL);
                // 0 - ���������� ����� ���������, 1-������ (������/�����), 2- ��������
                // ��������� �������

                lvColumnLog.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;

                lvColumnLog.cx = 22;
                lvColumnLog.pszText = "�";
                lvColumnLog.iSubItem = 0;
                ListView_InsertColumn(hListViewLog, 0, &lvColumnLog);

                lvColumnLog.cx = 75;
                lvColumnLog.pszText = "���������";
                lvColumnLog.iSubItem = 1;
                ListView_InsertColumn(hListViewLog, 1, &lvColumnLog);

                lvColumnLog.cx = 450;
                lvColumnLog.pszText = "��������";
                lvColumnLog.iSubItem = 2;
                ListView_InsertColumn(hListViewLog, 2, &lvColumnLog);

                //������
                itemLog.mask = LVIF_TEXT;
                itemLog.iItem=0; itemLog.iSubItem = 0;
                itemLog.pszText = "0";
                ListView_InsertItem(hListViewLog, &itemLog);

                itemLog.iSubItem = 1;
                itemLog.pszText = "�����";
                ListView_SetItem(hListViewLog, &itemLog);

                itemLog.iSubItem = 2;
                itemLog.pszText = "���������� ��������";
                ListView_SetItem(hListViewLog, &itemLog);

            }


            break;
        }
        case WM_COMMAND: {
            // ��������� ������� �� ������
                if (lParam == (LPARAM)hwndButtonReadState)
                    getState();
                else if (lParam == (LPARAM)hwndButtonDrawSpec)
                    drawSpec();
                else if (lParam == (LPARAM)hwndButtonRefresh)
                    GetAvailableComPorts();
                else if (lParam == (LPARAM)hwndButtonReadSpec)
                    getSpectrum();
                else if (lParam == (LPARAM)hwndButtonSave)
                    saveToFile();
                else if (lParam == (LPARAM)hwndButtonClearSpec)
                    ClearSpectrum();


            switch(LOWORD(wParam))
                case cbPorts_id:{ //��������� � ������ ������ ������
                    if ((HIWORD(wParam)==CBN_SELCHANGE)){
                        //���� ������� ����� ����
                        int id = SendMessage(lParam, CB_GETCURSEL,0,0);
                        if (id == 0) break;
                        char c[100];
                        SendMessage(lParam,CB_GETLBTEXT,id,c); // �������� ����� � ������
                        if (!makePorts(c)) printf("Successfully connected to %s \n",c);
                        else printf("Unable to connect %s \n",c);
                    }
                }
            break;
        }
        case WM_DESTROY: {
            CloseHandle(hSerial);
            PostQuitMessage(0);
            break;
        }
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


// ������� �������
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    instance = hInstance;
    // ������ ��� ������������
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    dcbSerialParams.BaudRate = CBR_115200;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;

    // �������� �������� ����
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "MyWindowClass";
    RegisterClass(&wc);

    hwnd = CreateWindow("MyWindowClass", "Spectrum program", WS_OVERLAPPEDWINDOW, 15, 15, 800, 600,
        NULL, NULL, hInstance, NULL);
    // ����������� ����
    ShowWindow(hwnd, nCmdShow);

    // ���� ��������� ��������� ����
    MSG msg = { 0 };
    while (1) {
            if (PeekMessageA(&msg, NULL, 0, 0,PM_REMOVE)){ // ������������ ���������, ���� ����
                if (msg.message == WM_QUIT) break; // ������� ��� ������
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
            else if (hSerial != INVALID_HANDLE_VALUE) { // � ��������� ����� ������� ����
                /*if (!ReadFile(hSerial, buffer, sizeof(buffer), &dwBytesRead, NULL))
                    printf("Error reading from serial port\n");

                if (dwBytesRead)
                    printf("Received %d bytes: %s\n", dwBytesRead, buffer);*/
            }
    }

    return 0;
}

void AddLOG(const char isError, LPTSTR message) {
    /*TCHAR buffer[6];
    wsprintf(buffer, _T("%hu"), itemLogNumber);

    LPTSTR log[3] = {(LPTSTR)buffer,(LPTSTR)"�����",message};
    if (isError) log[1] = (LPTSTR)"������";

    //ZeroMemory(&itemLog, sizeof(LVITEM));
    itemLog.iItem = itemLogNumber++;
    for (char i = 0; i < 3; i++) {
        itemLog.iSubItem = i;
        itemLog.pszText = (LPTSTR)log[i];
        if (i == 0) {
            ListView_InsertItem(hListViewLog, &itemLog);
        } else {
            ListView_SetItem(hListViewLog, &itemLog);
        }
    }
    itemLog.iSubItem = 1;
    itemLog.pszText = "�����, ��������";
    ListView_SetItem(hListViewLog, &itemLog);*/

    char str[5];
    sprintf(str, "%d", ++itemLog.iItem);
    itemLog.iSubItem = 0;
    itemLog.pszText = str;
    ListView_InsertItem(hListViewLog, &itemLog);

    itemLog.iSubItem = 1;
    if (isError) itemLog.pszText = "������";
    else  itemLog.pszText = "�����";
    ListView_SetItem(hListViewLog, &itemLog);

    itemLog.iSubItem = 2;
    itemLog.pszText = message;
    ListView_SetItem(hListViewLog, &itemLog);

}


