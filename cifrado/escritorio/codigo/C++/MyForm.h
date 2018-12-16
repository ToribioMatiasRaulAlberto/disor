#pragma once
#include "Cesar.h"
#include "Transposicion.h"
namespace Interfaz_cifrados {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;

	protected:

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::RichTextBox^  Dsc;

	private: System::Windows::Forms::NumericUpDown^  num;

	private: System::Windows::Forms::Label^  Desplazamiento;

	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  cifrar;
	private: System::Windows::Forms::RichTextBox^  richTextBox3;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->Dsc = (gcnew System::Windows::Forms::RichTextBox());
			this->num = (gcnew System::Windows::Forms::NumericUpDown());
			this->Desplazamiento = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cifrar = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->num))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Texto a cifrar:";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->Dsc);
			this->groupBox1->Controls->Add(this->num);
			this->groupBox1->Controls->Add(this->Desplazamiento);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(13, 58);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(214, 191);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Cifrado Cesar";
			// 
			// Dsc
			// 
			this->Dsc->Location = System::Drawing::Point(6, 82);
			this->Dsc->Name = L"Dsc";
			this->Dsc->Size = System::Drawing::Size(202, 103);
			this->Dsc->TabIndex = 2;
			this->Dsc->Text = L"";
			// 
			// num
			// 
			this->num->Location = System::Drawing::Point(122, 39);
			this->num->Name = L"num";
			this->num->Size = System::Drawing::Size(72, 20);
			this->num->TabIndex = 1;
			this->num->ValueChanged += gcnew System::EventHandler(this, &MyForm::num_ValueChanged);
			// 
			// Desplazamiento
			// 
			this->Desplazamiento->AutoSize = true;
			this->Desplazamiento->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Desplazamiento->Location = System::Drawing::Point(16, 41);
			this->Desplazamiento->Name = L"Desplazamiento";
			this->Desplazamiento->Size = System::Drawing::Size(100, 13);
			this->Desplazamiento->TabIndex = 0;
			this->Desplazamiento->Text = L"Desplazamiento:";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->richTextBox3);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(233, 58);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(203, 191);
			this->groupBox2->TabIndex = 0;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Transposicion inversa";
			// 
			// richTextBox3
			// 
			this->richTextBox3->Location = System::Drawing::Point(6, 82);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(191, 110);
			this->richTextBox3->TabIndex = 0;
			this->richTextBox3->Text = L"";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->richTextBox2);
			this->groupBox3->Controls->Add(this->numericUpDown2);
			this->groupBox3->Controls->Add(this->label3);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox3->Location = System::Drawing::Point(443, 58);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(213, 191);
			this->groupBox3->TabIndex = 3;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Transposicion inv. agrupacion";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(6, 89);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(201, 96);
			this->richTextBox2->TabIndex = 2;
			this->richTextBox2->Text = L"";
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(87, 34);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(57, 20);
			this->numericUpDown2->TabIndex = 1;
			this->numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown2_ValueChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(15, 38);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(75, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Agrupacion:";
			// 
			// cifrar
			// 
			this->cifrar->Location = System::Drawing::Point(117, 25);
			this->cifrar->Name = L"cifrar";
			this->cifrar->Size = System::Drawing::Size(512, 20);
			this->cifrar->TabIndex = 4;
			this->cifrar->TextChanged += gcnew System::EventHandler(this, &MyForm::cifrar_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(666, 261);
			this->Controls->Add(this->cifrar);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->num))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		transposcionGrupos();
		reverso();
		cesar();
	}
			 string MarshalString(System::String^ s)
			 {
				 string os;
				 using namespace System::Runtime::InteropServices;
				 const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
				 os = chars;
				 Marshal::FreeHGlobal(IntPtr((void*)chars));
				 return os;
			 }
			 private: System::Void transposcionGrupos()
			 {
				 //invertir_en_grupos(string mensaje, int elementos_en_elgrupo, string nuevo_mensaje)
				 String^ msj = cifrar->Text;
				 string msjs = MarshalString(msj);
				 int elem = Int32::Parse(numericUpDown2->Value.ToString());
				 string msjd = "";
				 String^ cifrado = gcnew String(invertir_en_grupos(msjs, elem, msjd).c_str());

				 richTextBox2->Text = cifrado;
				  
			 }
			private: System::Void reverso()
			{
				String^ msj = cifrar->Text;
				string msjs = MarshalString(msj);
				
				String^ cifrado = gcnew String(invertir(msjs).c_str());

				richTextBox3->Text = cifrado;
			}
					 private: System::Void cesar()
					 {
						 //Cifrar
						 String^ msj = cifrar->Text;
						 string msj2 = MarshalString(msj);

						 int despl = int::Parse(num->Value.ToString());

						 String^ cifrado = gcnew String(Cifrar(msj2,despl).c_str());
						 Dsc->Text = cifrado;

					 }
private: System::Void numericUpDown2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	transposcionGrupos();
}
private: System::Void num_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	cesar();
}
private: System::Void cifrar_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	reverso();
	cesar();
	transposcionGrupos();
}
};
}
