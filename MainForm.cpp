#include "MainForm.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
		Application::SetCompatibleTextRenderingDefault(false);
		Application::EnableVisualStyles();
		lab9::MainForm form;
		lab9::MainForm::mainForm = %form;
		Application::Run(% form);
}