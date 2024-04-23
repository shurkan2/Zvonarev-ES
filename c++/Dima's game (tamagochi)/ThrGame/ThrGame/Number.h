#pragma once
#include <ctime>
//#include "resource.h"
int num;
int c_time = 1800;
bool Over = false;
bool wasopened = false;
int tagname = 0; 
int ntry = 0;
int n_buttons;
string DIRECT = fu1nc();

namespace ThrGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Reflection;

	/// <summary>
	/// Сводка для Number
	/// </summary>
	public ref class Number : public System::Windows::Forms::Form
	{
	public:
		Number(void)
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
		~Number()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^  l_value;
	public: System::Windows::Forms::Button^  b_start;

	public:


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Timer^  t_time;

	private:

	private: System::Windows::Forms::Timer^  t_slide;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::Button^  button16;
	private: System::Windows::Forms::Label^  label3;
	public: System::Windows::Forms::Label^  l_n_pobed;
	private:

	private:

	private: System::Windows::Forms::Label^  l1;
	private: System::Windows::Forms::Label^  l2;
	private: System::Windows::Forms::Button^  b_quit;
	private: System::Windows::Forms::Label^  label4;



	private: System::ComponentModel::IContainer^  components;
	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			//System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Number::typeid));
			this->l_value = (gcnew System::Windows::Forms::Label());
			this->b_start = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->t_time = (gcnew System::Windows::Forms::Timer(this->components));
			this->t_slide = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->l_n_pobed = (gcnew System::Windows::Forms::Label());
			this->l1 = (gcnew System::Windows::Forms::Label());
			this->l2 = (gcnew System::Windows::Forms::Label());
			this->b_quit = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// l_value
			// 
			this->l_value->AutoSize = true;
			this->l_value->Location = System::Drawing::Point(1, 1);
			this->l_value->Name = L"l_value";
			this->l_value->Size = System::Drawing::Size(0, 13);
			this->l_value->TabIndex = 0;
			// 
			// b_start
			// 
			this->b_start->Location = System::Drawing::Point(52, 14);
			this->b_start->Name = L"b_start";
			this->b_start->Size = System::Drawing::Size(10, 8);
			this->b_start->TabIndex = 1;
			this->b_start->UseVisualStyleBackColor = true;
			this->b_start->Click += gcnew System::EventHandler(this, &Number::b_start_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(108, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Времени осталось: ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label2->Location = System::Drawing::Point(136, 7);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(2, 15);
			this->label2->TabIndex = 6;
			// 
			// t_time
			// 
			this->t_time->Interval = 1000;
			this->t_time->Tick += gcnew System::EventHandler(this, &Number::t_time_Tick);
			// 
			// t_slide
			// 
			this->t_slide->Interval = 700;
			this->t_slide->Tick += gcnew System::EventHandler(this, &Number::t_slide_Tick);
			// 
			// button1
			// 
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button1->Location = System::Drawing::Point(10, 35);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 125);
			this->button1->TabIndex = 1;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Number::btn_Click);
			// 
			// button2
			// 
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button2->Location = System::Drawing::Point(110, 35);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 125);
			this->button2->TabIndex = 2;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Number::btn_Click);
			// 
			// button3
			// 
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button3->Location = System::Drawing::Point(210, 35);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(85, 125);
			this->button3->TabIndex = 9;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Number::btn_Click);
			// 
			// button4
			// 
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button4->Location = System::Drawing::Point(310, 35);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(85, 125);
			this->button4->TabIndex = 10;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Number::btn_Click);
			// 
			// button5
			// 
			this->button5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button5->Location = System::Drawing::Point(310, 175);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(85, 125);
			this->button5->TabIndex = 14;
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Number::btn_Click);
			// 
			// button6
			// 
			this->button6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button6->Location = System::Drawing::Point(210, 175);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(85, 125);
			this->button6->TabIndex = 13;
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Number::btn_Click);
			// 
			// button7
			// 
			this->button7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button7->Location = System::Drawing::Point(110, 175);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(85, 125);
			this->button7->TabIndex = 12;
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Number::btn_Click);
			// 
			// button8
			// 
			this->button8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button8->Location = System::Drawing::Point(10, 175);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(85, 125);
			this->button8->TabIndex = 11;
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Number::btn_Click);
			// 
			// button9
			// 
			this->button9->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button9->Location = System::Drawing::Point(10, 315);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(85, 125);
			this->button9->TabIndex = 15;
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Number::btn_Click);
			// 
			// button10
			// 
			this->button10->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button10->Location = System::Drawing::Point(110, 315);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(85, 125);
			this->button10->TabIndex = 16;
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Number::btn_Click);
			// 
			// button11
			// 
			this->button11->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button11->Location = System::Drawing::Point(210, 315);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(85, 125);
			this->button11->TabIndex = 17;
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Number::btn_Click);
			// 
			// button12
			// 
			this->button12->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button12->Location = System::Drawing::Point(310, 315);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(85, 125);
			this->button12->TabIndex = 18;
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &Number::btn_Click);
			// 
			// button13
			// 
			this->button13->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button13->Location = System::Drawing::Point(10, 455);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(85, 125);
			this->button13->TabIndex = 19;
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &Number::btn_Click);
			// 
			// button14
			// 
			this->button14->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button14->Location = System::Drawing::Point(110, 455);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(85, 125);
			this->button14->TabIndex = 20;
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &Number::btn_Click);
			// 
			// button15
			// 
			this->button15->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button15->Location = System::Drawing::Point(210, 455);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(85, 125);
			this->button15->TabIndex = 21;
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &Number::btn_Click);
			// 
			// button16
			// 
			this->button16->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button16->Location = System::Drawing::Point(310, 455);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(85, 125);
			this->button16->TabIndex = 22;
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &Number::btn_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(275, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 13);
			this->label3->TabIndex = 23;
			this->label3->Text = L"Кол-во угаданных:";
			// 
			// l_n_pobed
			// 
			this->l_n_pobed->AutoSize = true;
			this->l_n_pobed->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->l_n_pobed->Location = System::Drawing::Point(374, 9);
			this->l_n_pobed->Name = L"l_n_pobed";
			this->l_n_pobed->Size = System::Drawing::Size(2, 15);
			this->l_n_pobed->TabIndex = 24;
			// 
			// l1
			// 
			this->l1->Location = System::Drawing::Point(1, 1);
			this->l1->Name = L"l1";
			this->l1->Size = System::Drawing::Size(1, 1);
			this->l1->TabIndex = 25;
			// 
			// l2
			// 
			this->l2->Location = System::Drawing::Point(1, 1);
			this->l2->Name = L"l2";
			this->l2->Size = System::Drawing::Size(1, 1);
			this->l2->TabIndex = 26;
			// 
			// b_quit
			// 
			this->b_quit->Location = System::Drawing::Point(1, 1);
			this->b_quit->Name = L"b_quit";
			this->b_quit->Size = System::Drawing::Size(1, 1);
			this->b_quit->TabIndex = 27;
			this->b_quit->UseVisualStyleBackColor = true;
			this->b_quit->Click += gcnew System::EventHandler(this, &Number::b_quit_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(185, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 13);
			this->label4->TabIndex = 28;
			// 
			// Number
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Inherit;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(409, 308);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->l2);
			this->Controls->Add(this->l1);
			this->Controls->Add(this->l_n_pobed);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->b_start);
			this->Controls->Add(this->l_value);
			this->Controls->Add(this->b_quit);
			this->HelpButton = true;
			//this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon.ico")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Number";
			this->ShowInTaskbar = false;
			this->Text = L"Найди пару";
			this->Load += gcnew System::EventHandler(this, &Number::Number_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void b_start_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		System::Resources::ResourceManager^ resources = gcnew System::Resources::ResourceManager("ThrGame.ImagesForProject", Assembly::GetExecutingAssembly());
		b_start->Visible = false;
		num = Convert::ToInt16(l_value->Text);
		l_value->Visible = false;
		srand((int)time(0));
		l_n_pobed->Text = "0";

		if (num == 16) 
		{
			n_buttons = 16;
			int arr[17];
			int carr[9] = {0,0,0,0,0,0,0,0,0};
			int k =  0;
			for (int i = 1; i < 17; i++)
			{
				k = rand() % 8 + 1;
				while (carr[k] == 2)
				{
					k = rand() % 8 + 1;
				}
				carr[k]++;
				arr[i] = k;
			}
			
			button1->Text = Convert::ToString(arr[1]); button1->Image = (Bitmap^)resources->GetObject("Title");
			button2->Text = Convert::ToString(arr[2]); button2->Image = (Bitmap^)resources->GetObject("Title");
			button3->Text = Convert::ToString(arr[3]); button3->Image = (Bitmap^)resources->GetObject("Title");
			button4->Text = Convert::ToString(arr[4]); button4->Image = (Bitmap^)resources->GetObject("Title");
			button5->Text = Convert::ToString(arr[5]); button5->Image = (Bitmap^)resources->GetObject("Title");
			button6->Text = Convert::ToString(arr[6]); button6->Image = (Bitmap^)resources->GetObject("Title");
			button7->Text = Convert::ToString(arr[7]); button7->Image = (Bitmap^)resources->GetObject("Title");
			button8->Text = Convert::ToString(arr[8]); button8->Image = (Bitmap^)resources->GetObject("Title");
			button9->Text = Convert::ToString(arr[9]); button9->Image = (Bitmap^)resources->GetObject("Title");
			button10->Text = Convert::ToString(arr[10]); button10->Image = (Bitmap^)resources->GetObject("Title");
			button11->Text = Convert::ToString(arr[11]); button11->Image = (Bitmap^)resources->GetObject("Title");
			button12->Text = Convert::ToString(arr[12]); button12->Image = (Bitmap^)resources->GetObject("Title");
			button13->Text = Convert::ToString(arr[13]); button13->Image = (Bitmap^)resources->GetObject("Title");
			button14->Text = Convert::ToString(arr[14]); button14->Image = (Bitmap^)resources->GetObject("Title");
			button15->Text = Convert::ToString(arr[15]); button15->Image = (Bitmap^)resources->GetObject("Title");
			button16->Text = Convert::ToString(arr[16]); button16->Image = (Bitmap^)resources->GetObject("Title");
				
		}
		else if (num == 12) 
		{				
			n_buttons = 12;
			int arr[13];
			int carr[9] = { 0,0,0,0,0,0,0,0,0 };
			int k = 0;
			for (int i = 1; i < 13; i++)
			{
				k = rand() % 6 + 1;
				while (carr[k] == 2)
				{
					k = rand() % 6 + 1;
				}
				carr[k]++;
				arr[i] = k;
			}
			button1->Text = Convert::ToString(arr[1]); button1->Image = (Bitmap^)resources->GetObject(L"Title");
			button2->Text = Convert::ToString(arr[2]); button2->Image = (Bitmap^)resources->GetObject(L"Title");
			button3->Text = Convert::ToString(arr[3]); button3->Image = (Bitmap^)resources->GetObject(L"Title");
			button4->Text = Convert::ToString(arr[4]); button4->Image = (Bitmap^)resources->GetObject(L"Title");
			button5->Text = Convert::ToString(arr[5]); button5->Image = (Bitmap^)resources->GetObject(L"Title");
			button6->Text = Convert::ToString(arr[6]); button6->Image = (Bitmap^)resources->GetObject(L"Title");
			button7->Text = Convert::ToString(arr[7]); button7->Image = (Bitmap^)resources->GetObject(L"Title");
			button8->Text = Convert::ToString(arr[8]); button8->Image = (Bitmap^)resources->GetObject(L"Title");
			button9->Text = Convert::ToString(arr[9]); button9->Image = (Bitmap^)resources->GetObject(L"Title");
			button10->Text = Convert::ToString(arr[10]); button10->Image = (Bitmap^)resources->GetObject(L"Title");
			button11->Text = Convert::ToString(arr[11]); button11->Image = (Bitmap^)resources->GetObject(L"Title");
			button12->Text = Convert::ToString(arr[12]); button12->Image = (Bitmap^)resources->GetObject(L"Title");
			//button13->Disposing;
			this->Controls->Remove(button13);
			this->Controls->Remove(button14);
			this->Controls->Remove(button15);
			this->Controls->Remove(button16);


			
		}
		else if (num == 8) 
		{
			n_buttons = 8;
			int arr[9];
			int carr[9] = { 0,0,0,0,0,0,0,0,0 };
			int k = 0;
			for (int i = 1; i < 9; i++)
			{
				k = rand() % 4 + 1;
				while (carr[k] == 2)
				{
					k = rand() % 4 +1;
				}
				carr[k]++;
				arr[i] = k;
			}
			button1->Text = Convert::ToString(arr[1]); button1->Image = (Bitmap^)resources->GetObject(L"Title");
			button2->Text = Convert::ToString(arr[2]); button2->Image = (Bitmap^)resources->GetObject(L"Title");
			button3->Text = Convert::ToString(arr[3]); button3->Image = (Bitmap^)resources->GetObject(L"Title");
			button4->Text = Convert::ToString(arr[4]); button4->Image = (Bitmap^)resources->GetObject(L"Title");
			button5->Text = Convert::ToString(arr[5]); button5->Image = (Bitmap^)resources->GetObject(L"Title");
			button6->Text = Convert::ToString(arr[6]); button6->Image = (Bitmap^)resources->GetObject(L"Title");
			button7->Text = Convert::ToString(arr[7]); button7->Image = (Bitmap^)resources->GetObject(L"Title");
			button8->Text = Convert::ToString(arr[8]); button8->Image = (Bitmap^)resources->GetObject(L"Title");
			this->Controls->Remove(button12);
			this->Controls->Remove(button11);
			this->Controls->Remove(button10);
			this->Controls->Remove(button9);
			this->Controls->Remove(button13);
			this->Controls->Remove(button14);
			this->Controls->Remove(button15);
			this->Controls->Remove(button16);
		}
		
		t_time->Enabled = true;
		
	}
private: System::Void Number_Load(System::Object^  sender, System::EventArgs^  e) 
{
	num;
	c_time = 60;
	Over = false;
	wasopened = false;
	tagname = 0;
	DIRECT = fu1nc();
	t_time->Enabled = true; 
	ntry = 0;
	b_start->PerformClick();
}
private: System::Void t_time_Tick(System::Object^  sender, System::EventArgs^  e) 
{
	if (!Over) {
		c_time--;
		int min = c_time / 60;
		int sec = c_time - 60 * min;
		std::string s = "0";
		label2->Text = gcnew System::String(s.c_str());
		label2->Text += min.ToString();
		s = ":";
		if (((int)(sec / 10)) == 0) s += "0";
		label2->Text += gcnew System::String(s.c_str());
		label2->Text += sec.ToString();
		if (c_time == 0) { label1->Text = "Game Over"; Over = true; }
	}
	else { t_time->Enabled = false; b_quit->PerformClick(); }
	if (ntry == 5) { t_time->Enabled = false; label4->Text = "Попытка №" + Convert::ToString(ntry); b_quit->PerformClick(); }
	label4->Text = "Попытка №" + Convert::ToString(ntry);
	if (n_buttons == 0) {
		t_time->Enabled = false;
	}
}

private: System::Void t_slide_Tick(System::Object^  sender, System::EventArgs^  e) 
{
	System::Resources::ResourceManager^ resources = gcnew System::Resources::ResourceManager("ThrGame.ImagesForProject", Assembly::GetExecutingAssembly());
	for (int i = 0; i < this->Controls->Count; i++)
	{
		if ( (this->Controls[i]->Name == l1->Text) || (this->Controls[i]->Name == l2->Text))
		{
			Button^ bt = dynamic_cast<Button^>(this->Controls[i]); 
			bt->Image = (Bitmap^)resources->GetObject("Title");
		}
	}
	t_slide->Enabled = false;
	l1->Text = ""; l2->Text = "";
	ntry++;
}
private: System::Void b_quit_Click(System::Object^  sender, System::EventArgs^  e) 
 {
	int vict = Convert::ToInt32(l_n_pobed->Text);
	if (num == 8)
	{
		if (vict == 3) { l_n_pobed->Text = "10"; }
		else if (vict == 2) { l_n_pobed->Text = "6"; }
		else if (vict == 1) { l_n_pobed->Text = "3"; }
		else if (vict < 1) { l_n_pobed->Text = "0"; }
		else if (vict>3) { l_n_pobed->Text = "20"; }
	}
	else if (num == 12)
	{
		if (vict == 3) { l_n_pobed->Text = "21"; }
		else if (vict == 2) { l_n_pobed->Text = "14"; }
		else if (vict == 1) { l_n_pobed->Text = "7"; }
		else if (vict < 1) { l_n_pobed->Text = "0"; }
		else if (vict > 3) { l_n_pobed->Text = "42"; }
	}
	if (num == 16)
	{
		if (vict == 3) { l_n_pobed->Text = "34"; }
		else if (vict == 2) { l_n_pobed->Text = "22"; }
		else if (vict == 1) { l_n_pobed->Text = "11"; }
		else if (vict < 1) { l_n_pobed->Text = "0"; }
		else if (vict > 3) { l_n_pobed->Text = "64"; }
	}	
	MessageBox::Show("Заработано: "+l_n_pobed->Text+"$","Игра окончена");
	this->Close();
 }
	private: System::Void btn_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (!t_slide->Enabled) {
			System::Resources::ResourceManager^ resources = gcnew System::Resources::ResourceManager("ThrGame.ImagesForProject", Assembly::GetExecutingAssembly());
			Button^ btn = safe_cast<Button^>(sender);
			if (((wasopened) && ((l1->Text == btn->Name) || (l2->Text == btn->Name)))||(btn->Text == "0")) {}
			else {
				if (!wasopened)
				{
					wasopened = true;
					tagname = Convert::ToInt32(btn->Text);
					l1->Text = btn->Name;
					btn->Image = (Bitmap^)resources->GetObject(btn->Text);
				}
				else if (wasopened)
				{
					if (tagname == Convert::ToInt32(btn->Text)) 
					{ 
						wasopened = false; 
						int npobed = Convert::ToInt32(l_n_pobed->Text); 
						npobed++; 
						l_n_pobed->Text = Convert::ToString(npobed); 
						n_buttons-= 2;
						delete btn;
						delete this->Controls[l1->Text];
						if (n_buttons == 0) { b_quit->PerformClick(); }
					}
					else
					{
						l2->Text = btn->Name;
						wasopened = false;
						t_slide->Enabled = true;
						btn->Image = (Bitmap^)resources->GetObject(btn->Text);
					};
				}
				
			}
		}
		
	}
};
}
