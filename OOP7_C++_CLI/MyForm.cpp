#include "MyForm.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


[STAThread]
int main(array<String^>^ arg) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    OOP7CCLI::MyForm form;  // OOP7 имя проекта
    Application::Run(% form);
    return 0;
}

System::Void OOP7CCLI::MyForm::buttonCircle_Click(System::Object^ sender, System::EventArgs^ e)
{
    shape = proto[0];
    this->ActiveControl = nullptr;
}

System::Void OOP7CCLI::MyForm::buttonSquare_Click(System::Object^ sender, System::EventArgs^ e)
{
    shape = proto[1];
    this->ActiveControl = nullptr;
}

System::Void OOP7CCLI::MyForm::buttonTriangle_Click(System::Object^ sender, System::EventArgs^ e)
{
    shape = proto[2];
    this->ActiveControl = nullptr;
}

System::Void OOP7CCLI::MyForm::checkBoxMulti_Click(System::Object^ sender, System::EventArgs^ e)
{
    shapes->setMultiple();
    this->ActiveControl = nullptr;
}

System::Void OOP7CCLI::MyForm::checkBoxCtrl_Click(System::Object^ sender, System::EventArgs^ e)
{
    CheckBox^ box = dynamic_cast<CheckBox^>(sender);
    shapes->setCtrl(box->Checked, sender);
    this->ActiveControl = nullptr;
}

System::Void OOP7CCLI::MyForm::buttonColor_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (colorDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        buttonColor->BackColor = colorDialog->Color;
        shapes->setShapeColor(colorDialog->Color);
        pictureBox1->Invalidate();
    }
    this->ActiveControl = nullptr;
}

System::Void OOP7CCLI::MyForm::pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
    shapes->drawShapes(penSelect, brush, e->Graphics);
}

System::Void OOP7CCLI::MyForm::MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
    if (e->KeyCode == Keys::ControlKey) {
        shapes->setCtrl(false, checkBoxCtrl);
    }
}

System::Void OOP7CCLI::MyForm::MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
    switch (e->KeyCode)
    {
    case Keys::ControlKey:
        shapes->setCtrl(true, checkBoxCtrl);
        break;
    case Keys::Back:
        shapes->removeSelected();
        pictureBox1->Invalidate();
        break;
    case Keys::Up:
        shapes->moveY(-dxy, pictureBox1->Location.Y, pictureBox1->Height);
        pictureBox1->Invalidate();
        break;
    case Keys::Down:
        shapes->moveY(dxy, pictureBox1->Location.Y, pictureBox1->Height);
        pictureBox1->Invalidate();
        break;
    case Keys::Left:
        shapes->moveX(-dxy, pictureBox1->Location.X, pictureBox1->Width);
        pictureBox1->Invalidate();
        break;
    case Keys::Right:
        shapes->moveX(dxy, pictureBox1->Location.X, pictureBox1->Width);
        pictureBox1->Invalidate();
        break;
    case Keys::OemOpenBrackets:
        shapes->changeSizes(-dsize);
        pictureBox1->Invalidate();
        break;
    case Keys::OemCloseBrackets:
        shapes->changeSizes(dsize);
        pictureBox1->Invalidate();
        break;
    case Keys::Q:
        Close();
        break;
    }
}

System::Void OOP7CCLI::MyForm::pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    auto a = pictureBox1->Location;
    if (!shapes->containShape(e->X, e->Y)) {
        shapes->addNewShape(shape, e->X, e->Y);
    }
    pictureBox1->Invalidate();
}

System::Void OOP7CCLI::MyForm::pictureBox1_Resize(System::Object^ sender, System::EventArgs^ e)
{
    if (shapes) {
        shapes->moveALL(pictureBox1->Location, pictureBox1->Width, pictureBox1->Height);
    }
}


