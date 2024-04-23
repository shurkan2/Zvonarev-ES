#pragma once

namespace ThrGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для PetName
	/// </summary>
	public ref class PetName : public System::Windows::Forms::Form
	{
	public:
		PetName(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~PetName()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^  label1;
	public: System::Windows::Forms::TextBox^  textBox1;
	private:
	private: System::Windows::Forms::Button^  button1;
	public:
	protected:


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"hooge 05_55", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(20, 47);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(397, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Как Вы назовёте своего питомца\?";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(81, 95);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(258, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &PetName::textBox1_KeyPress);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(150, 141);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(135, 27);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Готово";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &PetName::button1_Click);
			// 
			// PetName
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(429, 197);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"PetName";
			this->Text = L"PetName";
			this->Load += gcnew System::EventHandler(this, &PetName::PetName_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
	{
		if (e->KeyChar == (char)Keys::Enter) { button1->PerformClick(); return; }
	}
	private: System::Void PetName_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		textBox1->Font = label1->Font;
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		this->Close();
	}
	};
}
