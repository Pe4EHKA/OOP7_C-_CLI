#pragma once
#include "DrawingCanvas.h"
#include "AbstractFactory.h"

namespace OOP7CCLI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для OOP7
	/// </summary>
	public ref class OOP7 : public System::Windows::Forms::Form
	{
	public:
		OOP7(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			proto = gcnew cli::array<CShape^> { gcnew CCircle(), gcnew CSquare(), gcnew CTriangle() };
			shapes = gcnew DrawingCanvas();
			RightBottom = gcnew Point(pictureBox1->Width, pictureBox1->Height);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~OOP7()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
	private:
		int dxy = 10;  // Длина сдвига фигур
		int dsize = 10;  // Величина на которую будут увеличиваться/уменьшаться фигуры
		cli::array<CShape^>^ proto;  // Массив с прототипами фигур
		DrawingCanvas^ shapes;  // Контейнер с фигурами и методами для них
		CShape^ shape;
		String^ filename;
		Point^ RightBottom;

	private: System::Windows::Forms::Button^ buttonColor;

	private: System::Windows::Forms::Button^ buttonTriangle;
	private: System::Windows::Forms::Button^ buttonSquare;
	private: System::Windows::Forms::Button^ buttonCircle;
	private: System::Windows::Forms::CheckBox^ checkBoxMulti;
	private: System::Windows::Forms::CheckBox^ checkBoxCtrl;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::Button^ buttonGroup;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::Button^ buttonLoad;
	private: System::Windows::Forms::Button^ buttonSave;
	private: System::Windows::Forms::Button^ buttonUngroup;
	private: System::Windows::Forms::ColorDialog^ colorDialog;



#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Требуемый метод для поддержки конструктора — не изменяйте 
		   /// содержимое этого метода с помощью редактора кода.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->buttonColor = (gcnew System::Windows::Forms::Button());
			   this->buttonTriangle = (gcnew System::Windows::Forms::Button());
			   this->buttonSquare = (gcnew System::Windows::Forms::Button());
			   this->buttonCircle = (gcnew System::Windows::Forms::Button());
			   this->checkBoxMulti = (gcnew System::Windows::Forms::CheckBox());
			   this->checkBoxCtrl = (gcnew System::Windows::Forms::CheckBox());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->colorDialog = (gcnew System::Windows::Forms::ColorDialog());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->buttonLoad = (gcnew System::Windows::Forms::Button());
			   this->buttonSave = (gcnew System::Windows::Forms::Button());
			   this->buttonUngroup = (gcnew System::Windows::Forms::Button());
			   this->buttonGroup = (gcnew System::Windows::Forms::Button());
			   this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			   this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   this->panel1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // buttonColor
			   // 
			   this->buttonColor->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			   this->buttonColor->Location = System::Drawing::Point(81, 331);
			   this->buttonColor->Name = L"buttonColor";
			   this->buttonColor->Size = System::Drawing::Size(62, 60);
			   this->buttonColor->TabIndex = 6;
			   this->buttonColor->TabStop = false;
			   this->buttonColor->UseVisualStyleBackColor = false;
			   this->buttonColor->Click += gcnew System::EventHandler(this, &OOP7::buttonColor_Click);
			   // 
			   // buttonTriangle
			   // 
			   this->buttonTriangle->Location = System::Drawing::Point(44, 246);
			   this->buttonTriangle->Name = L"buttonTriangle";
			   this->buttonTriangle->Size = System::Drawing::Size(121, 48);
			   this->buttonTriangle->TabIndex = 5;
			   this->buttonTriangle->TabStop = false;
			   this->buttonTriangle->Text = L"Triangle";
			   this->buttonTriangle->UseVisualStyleBackColor = true;
			   this->buttonTriangle->Click += gcnew System::EventHandler(this, &OOP7::buttonTriangle_Click);
			   // 
			   // buttonSquare
			   // 
			   this->buttonSquare->Location = System::Drawing::Point(44, 183);
			   this->buttonSquare->Name = L"buttonSquare";
			   this->buttonSquare->Size = System::Drawing::Size(122, 48);
			   this->buttonSquare->TabIndex = 4;
			   this->buttonSquare->TabStop = false;
			   this->buttonSquare->Text = L"Square";
			   this->buttonSquare->UseVisualStyleBackColor = true;
			   this->buttonSquare->Click += gcnew System::EventHandler(this, &OOP7::buttonSquare_Click);
			   // 
			   // buttonCircle
			   // 
			   this->buttonCircle->Location = System::Drawing::Point(44, 116);
			   this->buttonCircle->Name = L"buttonCircle";
			   this->buttonCircle->Size = System::Drawing::Size(118, 48);
			   this->buttonCircle->TabIndex = 3;
			   this->buttonCircle->TabStop = false;
			   this->buttonCircle->Text = L"Circle";
			   this->buttonCircle->UseVisualStyleBackColor = true;
			   this->buttonCircle->Click += gcnew System::EventHandler(this, &OOP7::buttonCircle_Click);
			   // 
			   // checkBoxMulti
			   // 
			   this->checkBoxMulti->AutoSize = true;
			   this->checkBoxMulti->Location = System::Drawing::Point(44, 72);
			   this->checkBoxMulti->Name = L"checkBoxMulti";
			   this->checkBoxMulti->Size = System::Drawing::Size(179, 29);
			   this->checkBoxMulti->TabIndex = 2;
			   this->checkBoxMulti->TabStop = false;
			   this->checkBoxMulti->Text = L"MultiSelection";
			   this->checkBoxMulti->UseVisualStyleBackColor = true;
			   this->checkBoxMulti->Click += gcnew System::EventHandler(this, &OOP7::checkBoxMulti_Click);
			   // 
			   // checkBoxCtrl
			   // 
			   this->checkBoxCtrl->AutoSize = true;
			   this->checkBoxCtrl->Location = System::Drawing::Point(44, 20);
			   this->checkBoxCtrl->Name = L"checkBoxCtrl";
			   this->checkBoxCtrl->Size = System::Drawing::Size(99, 29);
			   this->checkBoxCtrl->TabIndex = 1;
			   this->checkBoxCtrl->TabStop = false;
			   this->checkBoxCtrl->Text = L"CTRL";
			   this->checkBoxCtrl->UseVisualStyleBackColor = true;
			   this->checkBoxCtrl->Click += gcnew System::EventHandler(this, &OOP7::checkBoxCtrl_Click);
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->pictureBox1->Location = System::Drawing::Point(0, 0);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(1110, 845);
			   this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			   this->pictureBox1->TabIndex = 1;
			   this->pictureBox1->TabStop = false;
			   this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &OOP7::pictureBox1_Paint);
			   this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &OOP7::pictureBox1_MouseDown);
			   // 
			   // panel1
			   // 
			   this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			   this->panel1->BackColor = System::Drawing::SystemColors::Info;
			   this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->panel1->Controls->Add(this->buttonLoad);
			   this->panel1->Controls->Add(this->buttonSave);
			   this->panel1->Controls->Add(this->buttonUngroup);
			   this->panel1->Controls->Add(this->buttonGroup);
			   this->panel1->Controls->Add(this->buttonColor);
			   this->panel1->Controls->Add(this->buttonTriangle);
			   this->panel1->Controls->Add(this->buttonSquare);
			   this->panel1->Controls->Add(this->buttonCircle);
			   this->panel1->Controls->Add(this->checkBoxMulti);
			   this->panel1->Controls->Add(this->checkBoxCtrl);
			   this->panel1->Location = System::Drawing::Point(1116, 0);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(239, 845);
			   this->panel1->TabIndex = 0;
			   // 
			   // buttonLoad
			   // 
			   this->buttonLoad->Location = System::Drawing::Point(33, 698);
			   this->buttonLoad->Name = L"buttonLoad";
			   this->buttonLoad->Size = System::Drawing::Size(166, 74);
			   this->buttonLoad->TabIndex = 10;
			   this->buttonLoad->TabStop = false;
			   this->buttonLoad->Text = L"Load";
			   this->buttonLoad->UseVisualStyleBackColor = true;
			   this->buttonLoad->Click += gcnew System::EventHandler(this, &OOP7::buttonLoad_Click);
			   // 
			   // buttonSave
			   // 
			   this->buttonSave->Location = System::Drawing::Point(33, 618);
			   this->buttonSave->Name = L"buttonSave";
			   this->buttonSave->Size = System::Drawing::Size(166, 74);
			   this->buttonSave->TabIndex = 9;
			   this->buttonSave->TabStop = false;
			   this->buttonSave->Text = L"Save";
			   this->buttonSave->UseVisualStyleBackColor = true;
			   this->buttonSave->Click += gcnew System::EventHandler(this, &OOP7::buttonSave_Click);
			   // 
			   // buttonUngroup
			   // 
			   this->buttonUngroup->Location = System::Drawing::Point(33, 498);
			   this->buttonUngroup->Name = L"buttonUngroup";
			   this->buttonUngroup->Size = System::Drawing::Size(166, 74);
			   this->buttonUngroup->TabIndex = 8;
			   this->buttonUngroup->TabStop = false;
			   this->buttonUngroup->Text = L"Ungroup";
			   this->buttonUngroup->UseVisualStyleBackColor = true;
			   this->buttonUngroup->Click += gcnew System::EventHandler(this, &OOP7::buttonUngroup_Click);
			   // 
			   // buttonGroup
			   // 
			   this->buttonGroup->Location = System::Drawing::Point(33, 418);
			   this->buttonGroup->Name = L"buttonGroup";
			   this->buttonGroup->Size = System::Drawing::Size(166, 74);
			   this->buttonGroup->TabIndex = 7;
			   this->buttonGroup->TabStop = false;
			   this->buttonGroup->Text = L"GroupSelected";
			   this->buttonGroup->UseVisualStyleBackColor = true;
			   this->buttonGroup->Click += gcnew System::EventHandler(this, &OOP7::buttonGroup_Click);
			   // 
			   // openFileDialog1
			   // 
			   this->openFileDialog1->FileName = L"openFileDialog1";
			   // 
			   // OOP7
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1379, 851);
			   this->Controls->Add(this->pictureBox1);
			   this->Controls->Add(this->panel1);
			   this->Name = L"OOP7";
			   this->Text = L"OOP7";
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &OOP7::OOP7_KeyDown);
			   this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &OOP7::OOP7_KeyUp);
			   this->Resize += gcnew System::EventHandler(this, &OOP7::OOP7_Resize);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void buttonCircle_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonSquare_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonTriangle_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void checkBoxMulti_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void checkBoxCtrl_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonColor_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
	private: System::Void OOP7_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);
	private: System::Void OOP7_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);
	private: System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void pictureBox1_Resize(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonGroup_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonUngroup_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void OOP7_Resize(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonSave_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonLoad_Click(System::Object^ sender, System::EventArgs^ e);
};
};