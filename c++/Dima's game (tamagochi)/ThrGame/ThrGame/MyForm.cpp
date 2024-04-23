#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void main(cli::array<System::String^>^ args) {
	setlocale(LC_ALL, "rus");
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ThrGame::MyForm form;
	Application::Run(%form);
	//return 0;
}
