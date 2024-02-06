#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Drawing;


[STAThreadAttribute]

void main(array <String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Sokobangame4::MyForm form;
    Application::Run(% form);
}
