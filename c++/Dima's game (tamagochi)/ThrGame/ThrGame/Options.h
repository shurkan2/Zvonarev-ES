#pragma once

namespace ThrGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Options
	/// </summary>
	public ref class Options : public System::Windows::Forms::Form
	{
	public:
		Options(void)
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
		~Options()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label10;
	public: System::Windows::Forms::TrackBar^  trackBar1;
	private:
	protected:

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	public: System::Windows::Forms::TextBox^  textBox1;
	private:
	public: System::Windows::Forms::TextBox^  textBox2;
	public: System::Windows::Forms::TextBox^  textBox3;
	public: System::Windows::Forms::TextBox^  textBox4;
	public: System::Windows::Forms::TextBox^  textBox5;
	public: System::Windows::Forms::TextBox^  textBox6;






	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	public: System::Windows::Forms::TextBox^  textBox7;
	private:
	public: System::Windows::Forms::TextBox^  textBox8;
	public: System::Windows::Forms::TextBox^  textBox9;
	public: System::Windows::Forms::TextBox^  textBox10;
	public: System::Windows::Forms::TextBox^  textBox11;
	public: System::Windows::Forms::TextBox^  textBox12;






	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Button^  button1;
	public: System::Windows::Forms::RadioButton^  radioButton1;
	private:
	public: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label14;
	public: System::Windows::Forms::CheckBox^  cb_gamestop;
	public: System::Windows::Forms::CheckBox^  cb_onsave;
	private:


	public:


	private:


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Options::typeid));
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->cb_gamestop = (gcnew System::Windows::Forms::CheckBox());
			this->cb_onsave = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// label10
			// 
			this->label10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label10->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label10->Font = (gcnew System::Drawing::Font(L"Courier New", 6, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label10.Image")));
			this->label10->Location = System::Drawing::Point(494, 34);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(235, 12);
			this->label10->TabIndex = 39;
			this->label10->Text = L"Скорость игры";
			this->label10->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// trackBar1
			// 
			this->trackBar1->Cursor = System::Windows::Forms::Cursors::Cross;
			this->trackBar1->Location = System::Drawing::Point(489, 12);
			this->trackBar1->Maximum = 5000;
			this->trackBar1->Minimum = 500;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(241, 45);
			this->trackBar1->TabIndex = 38;
			this->trackBar1->Value = 2500;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(16, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(37, 13);
			this->label1->TabIndex = 40;
			this->label1->Text = L"Скука";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(16, 54);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(37, 13);
			this->label2->TabIndex = 41;
			this->label2->Text = L"Голод";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(16, 84);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 13);
			this->label3->TabIndex = 42;
			this->label3->Text = L"Жажда";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(16, 110);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 13);
			this->label4->TabIndex = 43;
			this->label4->Text = L"Забота";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(16, 136);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(40, 13);
			this->label5->TabIndex = 44;
			this->label5->Text = L"Нужда";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(16, 162);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(26, 13);
			this->label6->TabIndex = 45;
			this->label6->Text = L"Сон";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(80, 29);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(98, 20);
			this->textBox1->TabIndex = 46;
			this->textBox1->Text = L"0,7";
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Options::textBox1_KeyPress);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(80, 55);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(98, 20);
			this->textBox2->TabIndex = 47;
			this->textBox2->Text = L"1";
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Options::textBox1_KeyPress);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(80, 81);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(98, 20);
			this->textBox3->TabIndex = 48;
			this->textBox3->Text = L"1,4";
			this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Options::textBox1_KeyPress);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(80, 107);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(98, 20);
			this->textBox4->TabIndex = 49;
			this->textBox4->Text = L"0,75";
			this->textBox4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Options::textBox1_KeyPress);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(80, 133);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(98, 20);
			this->textBox5->TabIndex = 50;
			this->textBox5->Text = L"0,5";
			this->textBox5->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Options::textBox1_KeyPress);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(80, 159);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(98, 20);
			this->textBox6->TabIndex = 51;
			this->textBox6->Text = L"0,7";
			this->textBox6->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Options::textBox1_KeyPress);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox6);
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(8, 18);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(214, 197);
			this->groupBox1->TabIndex = 52;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Скорость уменьшения параметров днём";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox7);
			this->groupBox2->Controls->Add(this->textBox8);
			this->groupBox2->Controls->Add(this->textBox9);
			this->groupBox2->Controls->Add(this->textBox10);
			this->groupBox2->Controls->Add(this->textBox11);
			this->groupBox2->Controls->Add(this->textBox12);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->label12);
			this->groupBox2->Controls->Add(this->label13);
			this->groupBox2->Location = System::Drawing::Point(242, 18);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(214, 197);
			this->groupBox2->TabIndex = 53;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Скорость уменьшения параметров ночью";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(80, 159);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(98, 20);
			this->textBox7->TabIndex = 51;
			this->textBox7->Text = L"1,6";
			this->textBox7->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Options::textBox1_KeyPress);
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(80, 133);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(98, 20);
			this->textBox8->TabIndex = 50;
			this->textBox8->Text = L"0,3";
			this->textBox8->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Options::textBox1_KeyPress);
			// 
			// textBox9
			// 
			this->textBox9->Enabled = false;
			this->textBox9->Location = System::Drawing::Point(80, 107);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(98, 20);
			this->textBox9->TabIndex = 49;
			this->textBox9->Text = L"0";
			this->textBox9->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Options::textBox1_KeyPress);
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(80, 81);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(98, 20);
			this->textBox10->TabIndex = 48;
			this->textBox10->Text = L"1,1111";
			this->textBox10->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Options::textBox1_KeyPress);
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(80, 55);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(98, 20);
			this->textBox11->TabIndex = 47;
			this->textBox11->Text = L"0,7";
			this->textBox11->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Options::textBox1_KeyPress);
			// 
			// textBox12
			// 
			this->textBox12->Enabled = false;
			this->textBox12->Location = System::Drawing::Point(80, 29);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(98, 20);
			this->textBox12->TabIndex = 46;
			this->textBox12->Text = L"0";
			this->textBox12->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Options::textBox1_KeyPress);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(16, 162);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(35, 13);
			this->label7->TabIndex = 45;
			this->label7->Text = L"Сон +";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(16, 136);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(40, 13);
			this->label8->TabIndex = 44;
			this->label8->Text = L"Нужда";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(16, 110);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(43, 13);
			this->label9->TabIndex = 43;
			this->label9->Text = L"Забота";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(16, 84);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(44, 13);
			this->label11->TabIndex = 42;
			this->label11->Text = L"Жажда";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(16, 54);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(37, 13);
			this->label12->TabIndex = 41;
			this->label12->Text = L"Голод";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(16, 32);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(37, 13);
			this->label13->TabIndex = 40;
			this->label13->Text = L"Скука";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(533, 346);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(255, 41);
			this->button1->TabIndex = 54;
			this->button1->Text = L"Применить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Options::button1_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(14, 18);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(70, 17);
			this->radioButton1->TabIndex = 55;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Зелёный";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(14, 44);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(56, 17);
			this->radioButton2->TabIndex = 56;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Синий";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label15);
			this->groupBox3->Controls->Add(this->label14);
			this->groupBox3->Controls->Add(this->radioButton2);
			this->groupBox3->Controls->Add(this->radioButton1);
			this->groupBox3->Location = System::Drawing::Point(494, 63);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(232, 67);
			this->groupBox3->TabIndex = 57;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Цветовая схема параметров";
			// 
			// label15
			// 
			this->label15->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label15.Image")));
			this->label15->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label15->Location = System::Drawing::Point(100, 20);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(118, 10);
			this->label15->TabIndex = 60;
			// 
			// label14
			// 
			this->label14->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label14.Image")));
			this->label14->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label14->Location = System::Drawing::Point(100, 51);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(118, 10);
			this->label14->TabIndex = 59;
			// 
			// cb_gamestop
			// 
			this->cb_gamestop->AutoSize = true;
			this->cb_gamestop->Location = System::Drawing::Point(494, 150);
			this->cb_gamestop->Name = L"cb_gamestop";
			this->cb_gamestop->Size = System::Drawing::Size(224, 17);
			this->cb_gamestop->TabIndex = 58;
			this->cb_gamestop->Text = L"Останавливать игру при сворачивании";
			this->cb_gamestop->UseVisualStyleBackColor = true;
			// 
			// cb_onsave
			// 
			this->cb_onsave->AutoSize = true;
			this->cb_onsave->Location = System::Drawing::Point(494, 173);
			this->cb_onsave->Name = L"cb_onsave";
			this->cb_onsave->Size = System::Drawing::Size(251, 17);
			this->cb_onsave->TabIndex = 59;
			this->cb_onsave->Text = L"Сохранять питомца при завершении работы";
			this->cb_onsave->UseVisualStyleBackColor = true;
			// 
			// Options
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 408);
			this->Controls->Add(this->cb_onsave);
			this->Controls->Add(this->cb_gamestop);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->trackBar1);
			this->Name = L"Options";
			this->Text = L"Options";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
	{
		TextBox^ tbx = safe_cast<TextBox^>(sender);
		if (e->KeyChar == '.') e->KeyChar = ',';
		if (e->KeyChar == ',') 
			{
			if (tbx->Text->IndexOf(',') == -1) return;
			else { e->Handled = true; return; }
			}
		else if (Char::IsDigit(e->KeyChar))return;
		else if (e->KeyChar == (char)Keys::Back) return;
		
		else e->Handled = true;
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
{
	this->Close();
}
};
}
