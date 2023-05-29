#include "OOP7.h"

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
    OOP7CCLI::OOP7 form;  // OOP7 имя проекта
    Application::Run(% form);
    return 0;
}

System::Void OOP7CCLI::OOP7::buttonCircle_Click(System::Object^ sender, System::EventArgs^ e)
{
    shape = proto[0];
    this->ActiveControl = nullptr;
}

System::Void OOP7CCLI::OOP7::buttonSquare_Click(System::Object^ sender, System::EventArgs^ e)
{
    shape = proto[1];
    this->ActiveControl = nullptr;
}

System::Void OOP7CCLI::OOP7::buttonTriangle_Click(System::Object^ sender, System::EventArgs^ e)
{
    shape = proto[2];
    this->ActiveControl = nullptr;
}

System::Void OOP7CCLI::OOP7::checkBoxMulti_Click(System::Object^ sender, System::EventArgs^ e)
{
    shapes->setMultiple();
    this->ActiveControl = nullptr;
}

System::Void OOP7CCLI::OOP7::checkBoxCtrl_Click(System::Object^ sender, System::EventArgs^ e)
{
    CheckBox^ box = dynamic_cast<CheckBox^>(sender);
    shapes->setCtrl(box->Checked, sender);
    this->ActiveControl = nullptr;
}

System::Void OOP7CCLI::OOP7::buttonColor_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (colorDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        buttonColor->BackColor = colorDialog->Color;
        shapes->setShapeColor(colorDialog->Color);
        pictureBox1->Invalidate();
    }
    this->ActiveControl = nullptr;
}

System::Void OOP7CCLI::OOP7::pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
    shapes->drawShapes(e->Graphics);
}

System::Void OOP7CCLI::OOP7::OOP7_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
    if (e->KeyCode == Keys::ControlKey) {
        shapes->setCtrl(false, checkBoxCtrl);
    }
}

System::Void OOP7CCLI::OOP7::OOP7_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
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
        shapes->changeSizes(-dsize, pictureBox1->Location, RightBottom);
        pictureBox1->Invalidate();
        break;
    case Keys::OemCloseBrackets:
        shapes->changeSizes(dsize, pictureBox1->Location, RightBottom);
        pictureBox1->Invalidate();
        break;
    case Keys::Q:
        Close();
        break;
    }
}

System::Void OOP7CCLI::OOP7::pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    auto a = pictureBox1->Location;
    if (!shapes->containShape(e->X, e->Y)) {
        shapes->addNewShape(shape, e->X, e->Y);
    }
    pictureBox1->Invalidate();
}

System::Void OOP7CCLI::OOP7::pictureBox1_Resize(System::Object^ sender, System::EventArgs^ e)
{
    if (shapes) {
        shapes->moveALL(pictureBox1->Location, pictureBox1->Width, pictureBox1->Height);
    }
}

System::Void OOP7CCLI::OOP7::buttonGroup_Click(System::Object^ sender, System::EventArgs^ e)
{
    shapes->groupShapes();
    pictureBox1->Invalidate();
    this->ActiveControl = nullptr;
}

System::Void OOP7CCLI::OOP7::buttonUngroup_Click(System::Object^ sender, System::EventArgs^ e)
{
    shapes->ungroupShapes();
    pictureBox1->Invalidate();
    this->ActiveControl = nullptr;
}


System::Void OOP7CCLI::OOP7::OOP7_Resize(System::Object^ sender, System::EventArgs^ e)
{
    if (RightBottom) {
        RightBottom->X = pictureBox1->Width;
        RightBottom->Y = pictureBox1->Height;
    }
    if (shapes) {
        shapes->moveALL(pictureBox1->Location, pictureBox1->Width, pictureBox1->Height);
    }
}

System::Void OOP7CCLI::OOP7::buttonSave_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        filename = saveFileDialog1->FileName;
        String^ resolution = OOP7::Width.ToString() + " " + OOP7::Height.ToString();
        shapes->save(filename, resolution);
    }
    this->ActiveControl = nullptr;
    
}

System::Void OOP7CCLI::OOP7::buttonLoad_Click(System::Object^ sender, System::EventArgs^ e)
{
    
    if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        filename = openFileDialog1->FileName;
        AbstractFactory^ factory = gcnew AbstractFactory();  
        Point^ resolution = shapes->getResolution(filename); 
        OOP7::Width = resolution->X;
        OOP7::Height = resolution->Y;
        shapes->load(filename, factory);

    }
    this->ActiveControl = nullptr;
    pictureBox1->Invalidate();
}
