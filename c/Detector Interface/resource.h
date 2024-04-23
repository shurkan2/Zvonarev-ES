#define MI__ABOUT 100
#define MI_EXIT 101
#define ID_OK 100
/*��������� ������� ��� �������� ����*/
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
void OnCommand(HWND,int,HWND,UINT);
void OnDestroy(HWND);
/*��������� ������� ��� ���� �������*/
BOOL CALLBACK DlgProc (HWND, UINT, WPARAM, LPARAM) ;
BOOL DlgOnlnitDialog(HWND,HWND,LPARAM);
void DlgOnCommand(HWND,int);


