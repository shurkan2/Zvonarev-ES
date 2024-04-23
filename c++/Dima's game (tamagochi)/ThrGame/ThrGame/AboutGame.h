#pragma once

namespace ThrGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AboutGame
	/// </summary>
	public ref class AboutGame : public System::Windows::Forms::Form
	{
	public:
		AboutGame(void)
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
		~AboutGame()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton4;



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AboutGame::typeid));
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(32, 31);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(130, 17);
			this->radioButton1->TabIndex = 1;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Параметры питомца";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &AboutGame::radioButton3_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(32, 65);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(82, 17);
			this->radioButton2->TabIndex = 2;
			this->radioButton2->Text = L"Экономика";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &AboutGame::radioButton3_CheckedChanged);
			this->radioButton2->Click += gcnew System::EventHandler(this, &AboutGame::radioButton2_Click);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(32, 98);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(117, 17);
			this->radioButton3->TabIndex = 3;
			this->radioButton3->Text = L"Сохранение петов";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &AboutGame::radioButton3_CheckedChanged);
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(32, 512);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(96, 17);
			this->radioButton4->TabIndex = 4;
			this->radioButton4->Text = L"Разработчики";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &AboutGame::radioButton3_CheckedChanged);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Font = (gcnew System::Drawing::Font(L"Dungeon", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(371, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(801, 527);
			this->label1->TabIndex = 8;
			this->label1->Text = resources->GetString(L"label1.Text");
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Font = (gcnew System::Drawing::Font(L"Dungeon", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(371, 12);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(801, 527);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Развлекайте питомца, и вы будете получать деньги. Деньги необходимы на пропитание"
				L" питомца. Пока ни на что более\r\n\r\n";
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label3->Font = (gcnew System::Drawing::Font(L"Dungeon", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(371, 15);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(801, 527);
			this->label3->TabIndex = 10;
			this->label3->Text = resources->GetString(L"label3.Text");
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label4->Font = (gcnew System::Drawing::Font(L"Eras Bold ITC", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(371, 15);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(801, 527);
			this->label4->TabIndex = 11;
			this->label4->Text = resources->GetString(L"label4.Text");
			// 
			// AboutGame
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::SeaShell;
			this->ClientSize = System::Drawing::Size(1184, 562);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->radioButton4);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Name = L"AboutGame";
			this->Text = L"AboutGame";
			this->Load += gcnew System::EventHandler(this, &AboutGame::AboutGame_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void radioButton2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
	}
	private: System::Void radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		RadioButton^ rb = safe_cast<RadioButton^>(sender);
		if (rb->Name == "radioButton1") { label1->BringToFront(); }
		else if (rb->Name == "radioButton2") { label2->BringToFront(); }
		else if (rb->Name == "radioButton3") { label3->BringToFront(); }
		else if (rb->Name == "radioButton4") { label4->BringToFront(); }
		else { label1->BringToFront(); radioButton1->Checked = true; }
	}
private: System::Void AboutGame_Load(System::Object^ sender, System::EventArgs^ e) 
{
	label1->BringToFront();
}
};
}
