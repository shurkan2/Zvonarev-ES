#pragma once
#include "AboutPet.cpp"
#include "HelpWithDirections.cpp"
#include "Number.h"
#include "Options.h"
#include "PetName.h"
#include "RatGame.cpp"
#include "AboutGame.h"
//#define debug
//#define debugonsave



namespace ThrGame{
	MyAnimal pet; int colllor; 
	bool Lampa = false;
	double tn_wak_boried = (1/0.7);
	double tn_sl_boried = (1/0);
	double tn_wak_drain = (1/1.4);
	double tn_sl_drain = (1/1.1111);
	double tn_wak_carees = (1/0.75);
	double tn_sl_carees = (1/0);
	double tn_wak_ness = (1/0.5);
	double tn_sl_ness = (1/0.3);
	double tn_sl_slumb = (1/1.6);
	double tn_wak_slumb = (1/0.7);
	double tn_wak_hung = (1/1);
	double tn_sl_hung = (1/0.7);
	int CurrentImageOfCat = 0;
	int CurrentImageOfFon = 0;
	bool isgamepause = false;
	int stati[8] = {-1,120,120,120,120,120,120,120};
	int g_time = 2500; // òî æå, ÷òî è èãğîâîå âğåìÿ n. Äëÿ ãîëîäà ñ êîııôèöåíòîì 1 îïğåäåëÿåòñÿ
	int DrawIndex = 0;
	string	DIRECTION = fu1nc();
	bool StopInLeave = false;
	bool issaveonquit = true;
	string petname = "";
}

namespace nastroiki 
{
	int CurrentImageOfCat = 0;
	int CurrentImageOfFon = 0;
	
}


namespace ThrGame
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Ñâîäêà äëÿ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: äîáàâüòå êîä êîíñòğóêòîğà
			//
		}

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ğåñóğñû.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  òàìàãî÷÷èToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ñîçäàòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  îòêğûòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ñîõğàíèòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ğàáîòàToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ïîêèíóòüÏèòîìöàToolStripMenuItem;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Label^  label2;

	public: System::Windows::Forms::Timer^  MainTimer;

	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenudrain;




	private: System::Windows::Forms::ToolStripMenuItem^  âîäóToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ìîëîêîToolStripMenuItem;






	private: System::Windows::Forms::ImageList^  ForMoodFirstTry;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  l_boried;
	private: System::Windows::Forms::Button^  b_boried;
	private: System::Windows::Forms::Button^  b_hunger;
	private: System::Windows::Forms::Label^  l_hunger;
	private: System::Windows::Forms::Button^  b_drain;
	private: System::Windows::Forms::Label^  l_drain;
	private: System::Windows::Forms::Button^  b_carees;
	private: System::Windows::Forms::Label^  l_carees;
	private: System::Windows::Forms::Button^  b_ness;
	private: System::Windows::Forms::Label^  l_ness;
	private: System::Windows::Forms::Button^  b_slumb;
	private: System::Windows::Forms::Label^  l_slumb;

	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuhunger;
	private: System::Windows::Forms::ToolStripMenuItem^  ìÿñîToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  õëåáToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ëèñòüÿToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  êîğìToolStripMenuItem;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Timer^  t_hunger;
	private: System::Windows::Forms::Timer^  t_sleep;
	private: System::Windows::Forms::Timer^  t_active_timer;
	private: System::Windows::Forms::Timer^  t_boried;
	private: System::Windows::Forms::Timer^  t_drain;
	private: System::Windows::Forms::Button^  b_start;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuGames;
	private: System::Windows::Forms::ToolStripMenuItem^  óãàäàòüĞàíäîìíîå×èñëîToolStripMenuItem;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuLove;
	private: System::Windows::Forms::ToolStripMenuItem^  ïîãëàäèòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  îáíÿòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ïîöåëîâàòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ëå÷üĞÿäîìÈÏîãîâîğèèòüToolStripMenuItem;

	private: System::Windows::Forms::Timer^  t_carees;
	private: System::Windows::Forms::Timer^  t_ness;
	private: System::Windows::Forms::Button^  b_pause;
	private: System::Windows::Forms::Timer^  t_action;
	private: System::Windows::Forms::ToolStripMenuItem^  êèñåëüToolStripMenuItem;
	private: System::Windows::Forms::Button^  b_quit;
	private: System::Windows::Forms::ToolStripMenuItem^  íàéòèÏàğóÊàğòToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  g1_easy;

private: System::Windows::Forms::ToolStripMenuItem^  g1_medium;
private: System::Windows::Forms::ToolStripMenuItem^  g1_hard;








private: System::Windows::Forms::PictureBox^  pictureBox2;
private: System::Windows::Forms::Label^  l_money;


private: System::Windows::Forms::ToolStripMenuItem^  íàñòğîéêèToolStripMenuItem;


private: System::Windows::Forms::Label^  l_petname;
private: System::Windows::Forms::Label^  l_become;
private: System::Windows::Forms::ToolTip^ TtNotinnes;
private: System::Windows::Forms::ToolStripMenuItem^ îÏğîãğàììåToolStripMenuItem;







	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåğåìåííàÿ êîíñòğóêòîğà.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òğåáóåìûé ìåòîä äëÿ ïîääåğæêè êîíñòğóêòîğà — íå èçìåíÿéòå 
		/// ñîäåğæèìîå ıòîãî ìåòîäà ñ ïîìîùüş ğåäàêòîğà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->òàìàãî÷÷èToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ñîçäàòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îòêğûòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ñîõğàíèòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ğàáîòàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->íàñòğîéêèToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïîêèíóòüÏèòîìöàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->MainTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->contextMenudrain = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->âîäóToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ìîëîêîToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->êèñåëüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ForMoodFirstTry = (gcnew System::Windows::Forms::ImageList(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->l_boried = (gcnew System::Windows::Forms::Label());
			this->b_boried = (gcnew System::Windows::Forms::Button());
			this->b_hunger = (gcnew System::Windows::Forms::Button());
			this->l_hunger = (gcnew System::Windows::Forms::Label());
			this->b_drain = (gcnew System::Windows::Forms::Button());
			this->l_drain = (gcnew System::Windows::Forms::Label());
			this->b_carees = (gcnew System::Windows::Forms::Button());
			this->l_carees = (gcnew System::Windows::Forms::Label());
			this->b_ness = (gcnew System::Windows::Forms::Button());
			this->l_ness = (gcnew System::Windows::Forms::Label());
			this->b_slumb = (gcnew System::Windows::Forms::Button());
			this->l_slumb = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->contextMenuhunger = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->ìÿñîToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->õëåáToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ëèñòüÿToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->êîğìToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->t_hunger = (gcnew System::Windows::Forms::Timer(this->components));
			this->t_sleep = (gcnew System::Windows::Forms::Timer(this->components));
			this->t_active_timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->t_boried = (gcnew System::Windows::Forms::Timer(this->components));
			this->t_drain = (gcnew System::Windows::Forms::Timer(this->components));
			this->b_start = (gcnew System::Windows::Forms::Button());
			this->contextMenuGames = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->óãàäàòüĞàíäîìíîå×èñëîToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->g1_easy = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->g1_medium = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->g1_hard = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->íàéòèÏàğóÊàğòToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuLove = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->ïîãëàäèòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îáíÿòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïîöåëîâàòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ëå÷üĞÿäîìÈÏîãîâîğèèòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->t_carees = (gcnew System::Windows::Forms::Timer(this->components));
			this->t_ness = (gcnew System::Windows::Forms::Timer(this->components));
			this->b_pause = (gcnew System::Windows::Forms::Button());
			this->t_action = (gcnew System::Windows::Forms::Timer(this->components));
			this->b_quit = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->l_money = (gcnew System::Windows::Forms::Label());
			this->l_petname = (gcnew System::Windows::Forms::Label());
			this->l_become = (gcnew System::Windows::Forms::Label());
			this->TtNotinnes = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->îÏğîãğàììåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->contextMenudrain->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->contextMenuhunger->SuspendLayout();
			this->contextMenuGames->SuspendLayout();
			this->contextMenuLove->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(654, 238);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(163, 20);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Ñîçäàòü æèâîòíîå";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(698, 286);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->òàìàãî÷÷èToolStripMenuItem,
					this->ğàáîòàToolStripMenuItem, this->ïîêèíóòüÏèòîìöàToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(984, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// òàìàãî÷÷èToolStripMenuItem
			// 
			this->òàìàãî÷÷èToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->òàìàãî÷÷èToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->ñîçäàòüToolStripMenuItem,
					this->îòêğûòüToolStripMenuItem, this->ñîõğàíèòüToolStripMenuItem
			});
			this->òàìàãî÷÷èToolStripMenuItem->Name = L"òàìàãî÷÷èToolStripMenuItem";
			this->òàìàãî÷÷èToolStripMenuItem->Size = System::Drawing::Size(73, 20);
			this->òàìàãî÷÷èToolStripMenuItem->Text = L"Òàìàãî÷è";
			// 
			// ñîçäàòüToolStripMenuItem
			// 
			this->ñîçäàòüToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ñîçäàòüToolStripMenuItem->Name = L"ñîçäàòüToolStripMenuItem";
			this->ñîçäàòüToolStripMenuItem->Size = System::Drawing::Size(141, 22);
			this->ñîçäàòüToolStripMenuItem->Text = L"Íà÷àòü èãğó";
			this->ñîçäàòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ñîçäàòüToolStripMenuItem_Click);
			// 
			// îòêğûòüToolStripMenuItem
			// 
			this->îòêğûòüToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->îòêğûòüToolStripMenuItem->Name = L"îòêğûòüToolStripMenuItem";
			this->îòêğûòüToolStripMenuItem->Size = System::Drawing::Size(141, 22);
			this->îòêğûòüToolStripMenuItem->Text = L"Îòêğûòü";
			this->îòêğûòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::îòêğûòüToolStripMenuItem_Click);
			// 
			// ñîõğàíèòüToolStripMenuItem
			// 
			this->ñîõğàíèòüToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->ñîõğàíèòüToolStripMenuItem->Name = L"ñîõğàíèòüToolStripMenuItem";
			this->ñîõğàíèòüToolStripMenuItem->Size = System::Drawing::Size(141, 22);
			this->ñîõğàíèòüToolStripMenuItem->Text = L"Ñîõğàíèòü";
			this->ñîõğàíèòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ñîõğàíèòüToolStripMenuItem_Click);
			// 
			// ğàáîòàToolStripMenuItem
			// 
			this->ğàáîòàToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ğàáîòàToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->íàñòğîéêèToolStripMenuItem,
					this->îÏğîãğàììåToolStripMenuItem
			});
			this->ğàáîòàToolStripMenuItem->Name = L"ğàáîòàToolStripMenuItem";
			this->ğàáîòàToolStripMenuItem->Size = System::Drawing::Size(126, 20);
			this->ğàáîòàToolStripMenuItem->Text = L"Ğàáîòà ïğîãğàììû";
			this->ğàáîòàToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ğàáîòàToolStripMenuItem_Click);
			// 
			// íàñòğîéêèToolStripMenuItem
			// 
			this->íàñòğîéêèToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(132)),
				static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->íàñòğîéêèToolStripMenuItem->Name = L"íàñòğîéêèToolStripMenuItem";
			this->íàñòğîéêèToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->íàñòğîéêèToolStripMenuItem->Text = L"Íàñòğîéêè";
			this->íàñòğîéêèToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::íàñòğîéêèToolStripMenuItem_Click);
			// 
			// ïîêèíóòüÏèòîìöàToolStripMenuItem
			// 
			this->ïîêèíóòüÏèòîìöàToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->ïîêèíóòüÏèòîìöàToolStripMenuItem->Name = L"ïîêèíóòüÏèòîìöàToolStripMenuItem";
			this->ïîêèíóòüÏèòîìöàToolStripMenuItem->Size = System::Drawing::Size(123, 20);
			this->ïîêèíóòüÏèòîìöàToolStripMenuItem->Text = L"Ïîêèíóòü ïèòîìöà";
			this->ïîêèíóòüÏèòîìöàToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ïîêèíóòüÏèòîìöàToolStripMenuItem_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Red;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->Location = System::Drawing::Point(421, 451);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 15);
			this->label1->TabIndex = 3;
			this->label1->Text = L"          ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(495, 286);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"label2";
			// 
			// MainTimer
			// 
			this->MainTimer->Interval = 250;
			this->MainTimer->Tick += gcnew System::EventHandler(this, &MyForm::MainTimer_Tick);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(592, 286);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 6;
			this->textBox2->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::textBox2_MouseDoubleClick);
			// 
			// contextMenudrain
			// 
			this->contextMenudrain->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->âîäóToolStripMenuItem,
					this->ìîëîêîToolStripMenuItem, this->êèñåëüToolStripMenuItem
			});
			this->contextMenudrain->Name = L"contextMenuStrip1";
			this->contextMenudrain->Size = System::Drawing::Size(120, 70);
			// 
			// âîäóToolStripMenuItem
			// 
			this->âîäóToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(200)));
			this->âîäóToolStripMenuItem->Name = L"âîäóToolStripMenuItem";
			this->âîäóToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->âîäóToolStripMenuItem->Text = L"Âîäó";
			this->âîäóToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::âîäóToolStripMenuItem_Click);
			// 
			// ìîëîêîToolStripMenuItem
			// 
			this->ìîëîêîToolStripMenuItem->Name = L"ìîëîêîToolStripMenuItem";
			this->ìîëîêîToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->ìîëîêîToolStripMenuItem->Text = L"Ìîëîêî";
			this->ìîëîêîToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ìîëîêîToolStripMenuItem_Click);
			// 
			// êèñåëüToolStripMenuItem
			// 
			this->êèñåëüToolStripMenuItem->Name = L"êèñåëüToolStripMenuItem";
			this->êèñåëüToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->êèñåëüToolStripMenuItem->Text = L"Êèñåëü";
			this->êèñåëüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::êèñåëüToolStripMenuItem_Click);
			// 
			// ForMoodFirstTry
			// 
			this->ForMoodFirstTry->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"ForMoodFirstTry.ImageStream")));
			this->ForMoodFirstTry->TransparentColor = System::Drawing::Color::Transparent;
			this->ForMoodFirstTry->Images->SetKeyName(0, L"Happy.png");
			this->ForMoodFirstTry->Images->SetKeyName(1, L"hungry.png");
			this->ForMoodFirstTry->Images->SetKeyName(2, L"Imloved.png");
			this->ForMoodFirstTry->Images->SetKeyName(3, L"Ininterest.png");
			this->ForMoodFirstTry->Images->SetKeyName(4, L"inned.png");
			this->ForMoodFirstTry->Images->SetKeyName(5, L"insleep.png");
			this->ForMoodFirstTry->Images->SetKeyName(6, L"normal.png");
			this->ForMoodFirstTry->Images->SetKeyName(7, L"sad.png");
			this->ForMoodFirstTry->Images->SetKeyName(8, L"verywell.png");
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(566, 326);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 9;
			this->button2->Text = L"ß áàòòîí 2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(389, 59);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(572, 420);
			this->pictureBox1->TabIndex = 10;
			this->pictureBox1->TabStop = false;
			// 
			// l_boried
			// 
			this->l_boried->AllowDrop = true;
			this->l_boried->AutoSize = true;
			this->l_boried->BackColor = System::Drawing::Color::White;
			this->l_boried->Cursor = System::Windows::Forms::Cursors::Hand;
			this->l_boried->ForeColor = System::Drawing::Color::Black;
			this->l_boried->Location = System::Drawing::Point(85, 289);
			this->l_boried->Name = L"l_boried";
			this->l_boried->Size = System::Drawing::Size(238, 13);
			this->l_boried->TabIndex = 11;
			this->l_boried->Text = L"                                                                             ";
			this->l_boried->Visible = false;
			// 
			// b_boried
			// 
			this->b_boried->BackColor = System::Drawing::SystemColors::Control;
			this->b_boried->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->b_boried->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"b_boried.Image")));
			this->b_boried->Location = System::Drawing::Point(15, 275);
			this->b_boried->Name = L"b_boried";
			this->b_boried->Size = System::Drawing::Size(64, 40);
			this->b_boried->TabIndex = 12;
			this->b_boried->UseVisualStyleBackColor = false;
			this->b_boried->Visible = false;
			this->b_boried->Click += gcnew System::EventHandler(this, &MyForm::b_boried_Click);
			// 
			// b_hunger
			// 
			this->b_hunger->BackColor = System::Drawing::Color::White;
			this->b_hunger->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"b_hunger.Image")));
			this->b_hunger->Location = System::Drawing::Point(15, 138);
			this->b_hunger->Name = L"b_hunger";
			this->b_hunger->Size = System::Drawing::Size(64, 40);
			this->b_hunger->TabIndex = 14;
			this->b_hunger->UseVisualStyleBackColor = false;
			this->b_hunger->Visible = false;
			this->b_hunger->Click += gcnew System::EventHandler(this, &MyForm::b_hunger_Click);
			// 
			// l_hunger
			// 
			this->l_hunger->AllowDrop = true;
			this->l_hunger->AutoSize = true;
			this->l_hunger->BackColor = System::Drawing::Color::White;
			this->l_hunger->Cursor = System::Windows::Forms::Cursors::Hand;
			this->l_hunger->ForeColor = System::Drawing::Color::Black;
			this->l_hunger->Location = System::Drawing::Point(85, 152);
			this->l_hunger->Name = L"l_hunger";
			this->l_hunger->Size = System::Drawing::Size(160, 13);
			this->l_hunger->TabIndex = 13;
			this->l_hunger->Text = L"                                                   ";
			this->l_hunger->Visible = false;
			// 
			// b_drain
			// 
			this->b_drain->BackColor = System::Drawing::Color::White;
			this->b_drain->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"b_drain.Image")));
			this->b_drain->Location = System::Drawing::Point(15, 182);
			this->b_drain->Name = L"b_drain";
			this->b_drain->Size = System::Drawing::Size(64, 40);
			this->b_drain->TabIndex = 16;
			this->b_drain->UseVisualStyleBackColor = false;
			this->b_drain->Visible = false;
			this->b_drain->Click += gcnew System::EventHandler(this, &MyForm::b_drain_Click);
			// 
			// l_drain
			// 
			this->l_drain->AllowDrop = true;
			this->l_drain->AutoSize = true;
			this->l_drain->BackColor = System::Drawing::Color::White;
			this->l_drain->Cursor = System::Windows::Forms::Cursors::Hand;
			this->l_drain->ForeColor = System::Drawing::Color::White;
			this->l_drain->Location = System::Drawing::Point(85, 196);
			this->l_drain->Name = L"l_drain";
			this->l_drain->Size = System::Drawing::Size(160, 13);
			this->l_drain->TabIndex = 15;
			this->l_drain->Text = L"                                                   ";
			this->l_drain->Visible = false;
			// 
			// b_carees
			// 
			this->b_carees->BackColor = System::Drawing::Color::White;
			this->b_carees->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"b_carees.Image")));
			this->b_carees->Location = System::Drawing::Point(15, 366);
			this->b_carees->Name = L"b_carees";
			this->b_carees->Size = System::Drawing::Size(64, 40);
			this->b_carees->TabIndex = 18;
			this->b_carees->UseVisualStyleBackColor = false;
			this->b_carees->Visible = false;
			this->b_carees->Click += gcnew System::EventHandler(this, &MyForm::b_carees_Click);
			// 
			// l_carees
			// 
			this->l_carees->AllowDrop = true;
			this->l_carees->AutoSize = true;
			this->l_carees->BackColor = System::Drawing::Color::White;
			this->l_carees->Cursor = System::Windows::Forms::Cursors::Hand;
			this->l_carees->ForeColor = System::Drawing::Color::White;
			this->l_carees->Location = System::Drawing::Point(85, 380);
			this->l_carees->Name = L"l_carees";
			this->l_carees->Size = System::Drawing::Size(160, 13);
			this->l_carees->TabIndex = 17;
			this->l_carees->Text = L"                                                   ";
			this->l_carees->Visible = false;
			// 
			// b_ness
			// 
			this->b_ness->BackColor = System::Drawing::Color::White;
			this->b_ness->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"b_ness.Image")));
			this->b_ness->Location = System::Drawing::Point(15, 320);
			this->b_ness->Name = L"b_ness";
			this->b_ness->Size = System::Drawing::Size(64, 40);
			this->b_ness->TabIndex = 20;
			this->b_ness->UseVisualStyleBackColor = false;
			this->b_ness->Visible = false;
			this->b_ness->Click += gcnew System::EventHandler(this, &MyForm::b_ness_Click);
			// 
			// l_ness
			// 
			this->l_ness->AllowDrop = true;
			this->l_ness->AutoSize = true;
			this->l_ness->BackColor = System::Drawing::Color::White;
			this->l_ness->Cursor = System::Windows::Forms::Cursors::Hand;
			this->l_ness->ForeColor = System::Drawing::Color::White;
			this->l_ness->Location = System::Drawing::Point(85, 334);
			this->l_ness->Name = L"l_ness";
			this->l_ness->Size = System::Drawing::Size(160, 13);
			this->l_ness->TabIndex = 19;
			this->l_ness->Text = L"                                                   ";
			this->l_ness->Visible = false;
			// 
			// b_slumb
			// 
			this->b_slumb->BackColor = System::Drawing::Color::White;
			this->b_slumb->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"b_slumb.Image")));
			this->b_slumb->Location = System::Drawing::Point(15, 228);
			this->b_slumb->Name = L"b_slumb";
			this->b_slumb->Size = System::Drawing::Size(64, 40);
			this->b_slumb->TabIndex = 22;
			this->b_slumb->UseVisualStyleBackColor = false;
			this->b_slumb->Visible = false;
			this->b_slumb->Click += gcnew System::EventHandler(this, &MyForm::b_slumb_Click);
			// 
			// l_slumb
			// 
			this->l_slumb->AllowDrop = true;
			this->l_slumb->AutoSize = true;
			this->l_slumb->BackColor = System::Drawing::Color::White;
			this->l_slumb->Cursor = System::Windows::Forms::Cursors::Hand;
			this->l_slumb->ForeColor = System::Drawing::Color::Black;
			this->l_slumb->Location = System::Drawing::Point(85, 242);
			this->l_slumb->Name = L"l_slumb";
			this->l_slumb->Size = System::Drawing::Size(160, 13);
			this->l_slumb->TabIndex = 21;
			this->l_slumb->Text = L"                                                   ";
			this->l_slumb->Visible = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(513, 348);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(52, 30);
			this->button3->TabIndex = 24;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label3->Location = System::Drawing::Point(653, 320);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(73, 52);
			this->label3->TabIndex = 23;
			this->label3->Text = L"                      \r\n                      \r\n                      \r\n         "
				L"             ";
			// 
			// contextMenuhunger
			// 
			this->contextMenuhunger->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->ìÿñîToolStripMenuItem,
					this->õëåáToolStripMenuItem, this->ëèñòüÿToolStripMenuItem, this->êîğìToolStripMenuItem
			});
			this->contextMenuhunger->Name = L"contextMenudrain";
			this->contextMenuhunger->Size = System::Drawing::Size(122, 92);
			// 
			// ìÿñîToolStripMenuItem
			// 
			this->ìÿñîToolStripMenuItem->Name = L"ìÿñîToolStripMenuItem";
			this->ìÿñîToolStripMenuItem->Size = System::Drawing::Size(121, 22);
			this->ìÿñîToolStripMenuItem->Text = L"Ìÿñî";
			this->ìÿñîToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ìÿñîToolStripMenuItem_Click);
			// 
			// õëåáToolStripMenuItem
			// 
			this->õëåáToolStripMenuItem->Name = L"õëåáToolStripMenuItem";
			this->õëåáToolStripMenuItem->Size = System::Drawing::Size(121, 22);
			this->õëåáToolStripMenuItem->Text = L"Ñìåòàíà";
			this->õëåáToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::õëåáToolStripMenuItem_Click);
			// 
			// ëèñòüÿToolStripMenuItem
			// 
			this->ëèñòüÿToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(200)));
			this->ëèñòüÿToolStripMenuItem->Name = L"ëèñòüÿToolStripMenuItem";
			this->ëèñòüÿToolStripMenuItem->Size = System::Drawing::Size(121, 22);
			this->ëèñòüÿToolStripMenuItem->Text = L"Ëèñòüÿ";
			this->ëèñòüÿToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ëèñòüÿToolStripMenuItem_Click);
			// 
			// êîğìToolStripMenuItem
			// 
			this->êîğìToolStripMenuItem->Name = L"êîğìToolStripMenuItem";
			this->êîğìToolStripMenuItem->Size = System::Drawing::Size(121, 22);
			this->êîğìToolStripMenuItem->Text = L"Êîğì";
			this->êîğìToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::êîğìToolStripMenuItem_Click);
			// 
			// label4
			// 
			this->label4->AllowDrop = true;
			this->label4->BackColor = System::Drawing::Color::White;
			this->label4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(85, 152);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(247, 13);
			this->label4->TabIndex = 25;
			this->label4->Text = L"                                                                                 "
				L"                                                                                "
				L"                                 ";
			// 
			// label5
			// 
			this->label5->AllowDrop = true;
			this->label5->BackColor = System::Drawing::Color::White;
			this->label5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(85, 289);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(247, 13);
			this->label5->TabIndex = 26;
			this->label5->Text = L"                                                                                 "
				L"                                                                                "
				L"                                 ";
			// 
			// label6
			// 
			this->label6->AllowDrop = true;
			this->label6->BackColor = System::Drawing::Color::White;
			this->label6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(85, 242);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(247, 13);
			this->label6->TabIndex = 27;
			this->label6->Text = L"                                                                                 "
				L"                                                                                "
				L"                                 ";
			// 
			// label7
			// 
			this->label7->AllowDrop = true;
			this->label7->BackColor = System::Drawing::Color::White;
			this->label7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(85, 196);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(247, 13);
			this->label7->TabIndex = 28;
			this->label7->Text = L"                                                                                 "
				L"                                                                                "
				L"                                 ";
			// 
			// label8
			// 
			this->label8->AllowDrop = true;
			this->label8->BackColor = System::Drawing::Color::White;
			this->label8->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label8->ForeColor = System::Drawing::Color::White;
			this->label8->Location = System::Drawing::Point(85, 334);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(247, 13);
			this->label8->TabIndex = 29;
			this->label8->Text = L"                                                                                 "
				L"                                                                                "
				L"                                 ";
			// 
			// label9
			// 
			this->label9->AllowDrop = true;
			this->label9->BackColor = System::Drawing::Color::White;
			this->label9->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label9->ForeColor = System::Drawing::Color::White;
			this->label9->Location = System::Drawing::Point(85, 380);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(247, 13);
			this->label9->TabIndex = 30;
			this->label9->Text = L"                                                                                 "
				L"                                                                                "
				L"                                 ";
			// 
			// t_hunger
			// 
			this->t_hunger->Tick += gcnew System::EventHandler(this, &MyForm::t_hunger_Tick);
			// 
			// t_sleep
			// 
			this->t_sleep->Tick += gcnew System::EventHandler(this, &MyForm::t_sleep_Tick);
			// 
			// t_boried
			// 
			this->t_boried->Tick += gcnew System::EventHandler(this, &MyForm::t_boried_Tick);
			// 
			// t_drain
			// 
			this->t_drain->Tick += gcnew System::EventHandler(this, &MyForm::t_drain_Tick);
			// 
			// b_start
			// 
			this->b_start->Cursor = System::Windows::Forms::Cursors::AppStarting;
			this->b_start->Location = System::Drawing::Point(471, 234);
			this->b_start->Name = L"b_start";
			this->b_start->Size = System::Drawing::Size(96, 30);
			this->b_start->TabIndex = 31;
			this->b_start->Text = L"Start";
			this->b_start->UseVisualStyleBackColor = true;
			this->b_start->Click += gcnew System::EventHandler(this, &MyForm::b_start_Click);
			// 
			// contextMenuGames
			// 
			this->contextMenuGames->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->óãàäàòüĞàíäîìíîå×èñëîToolStripMenuItem,
					this->íàéòèÏàğóÊàğòToolStripMenuItem
			});
			this->contextMenuGames->Name = L"contextMenuGames";
			this->contextMenuGames->Size = System::Drawing::Size(168, 48);
			// 
			// óãàäàòüĞàíäîìíîå×èñëîToolStripMenuItem
			// 
			this->óãàäàòüĞàíäîìíîå×èñëîToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->g1_easy,
					this->g1_medium, this->g1_hard
			});
			this->óãàäàòüĞàíäîìíîå×èñëîToolStripMenuItem->Name = L"óãàäàòüĞàíäîìíîå×èñëîToolStripMenuItem";
			this->óãàäàòüĞàíäîìíîå×èñëîToolStripMenuItem->Size = System::Drawing::Size(167, 22);
			this->óãàäàòüĞàíäîìíîå×èñëîToolStripMenuItem->Text = L"Íàéòè ïàğû êàğò";
			this->óãàäàòüĞàíäîìíîå×èñëîToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::óãàäàòüĞàíäîìíîå×èñëîToolStripMenuItem_Click);
			// 
			// g1_easy
			// 
			this->g1_easy->Name = L"g1_easy";
			this->g1_easy->Size = System::Drawing::Size(148, 22);
			this->g1_easy->Text = L"Easy (10$)";
			this->g1_easy->Click += gcnew System::EventHandler(this, &MyForm::g1_game_click);
			// 
			// g1_medium
			// 
			this->g1_medium->Name = L"g1_medium";
			this->g1_medium->Size = System::Drawing::Size(148, 22);
			this->g1_medium->Text = L"Medium (21$)";
			this->g1_medium->Click += gcnew System::EventHandler(this, &MyForm::g1_game_click);
			// 
			// g1_hard
			// 
			this->g1_hard->Name = L"g1_hard";
			this->g1_hard->Size = System::Drawing::Size(148, 22);
			this->g1_hard->Text = L"Hard (34$)";
			this->g1_hard->Click += gcnew System::EventHandler(this, &MyForm::g1_game_click);
			// 
			// íàéòèÏàğóÊàğòToolStripMenuItem
			// 
			this->íàéòèÏàğóÊàğòToolStripMenuItem->Name = L"íàéòèÏàğóÊàğòToolStripMenuItem";
			this->íàéòèÏàğóÊàğòToolStripMenuItem->Size = System::Drawing::Size(167, 22);
			this->íàéòèÏàğóÊàğòToolStripMenuItem->Text = L"Ïîéìàòü ìûøêó";
			this->íàéòèÏàğóÊàğòToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::íàéòèÏàğóÊàğòToolStripMenuItem_Click);
			// 
			// contextMenuLove
			// 
			this->contextMenuLove->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->ïîãëàäèòüToolStripMenuItem,
					this->îáíÿòüToolStripMenuItem, this->ïîöåëîâàòüToolStripMenuItem, this->ëå÷üĞÿäîìÈÏîãîâîğèèòüToolStripMenuItem
			});
			this->contextMenuLove->Name = L"contextMenuLove";
			this->contextMenuLove->Size = System::Drawing::Size(224, 92);
			// 
			// ïîãëàäèòüToolStripMenuItem
			// 
			this->ïîãëàäèòüToolStripMenuItem->Name = L"ïîãëàäèòüToolStripMenuItem";
			this->ïîãëàäèòüToolStripMenuItem->Size = System::Drawing::Size(223, 22);
			this->ïîãëàäèòüToolStripMenuItem->Text = L"Ïîãëàäèòü";
			this->ïîãëàäèòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ïîãëàäèòüToolStripMenuItem_Click);
			// 
			// îáíÿòüToolStripMenuItem
			// 
			this->îáíÿòüToolStripMenuItem->Name = L"îáíÿòüToolStripMenuItem";
			this->îáíÿòüToolStripMenuItem->Size = System::Drawing::Size(223, 22);
			this->îáíÿòüToolStripMenuItem->Text = L"Îáíÿòü";
			this->îáíÿòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::îáíÿòüToolStripMenuItem_Click);
			// 
			// ïîöåëîâàòüToolStripMenuItem
			// 
			this->ïîöåëîâàòüToolStripMenuItem->Name = L"ïîöåëîâàòüToolStripMenuItem";
			this->ïîöåëîâàòüToolStripMenuItem->Size = System::Drawing::Size(223, 22);
			this->ïîöåëîâàòüToolStripMenuItem->Text = L"Ïîöåëîâàòü";
			this->ïîöåëîâàòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ïîöåëîâàòüToolStripMenuItem_Click);
			// 
			// ëå÷üĞÿäîìÈÏîãîâîğèèòüToolStripMenuItem
			// 
			this->ëå÷üĞÿäîìÈÏîãîâîğèèòüToolStripMenuItem->Name = L"ëå÷üĞÿäîìÈÏîãîâîğèèòüToolStripMenuItem";
			this->ëå÷üĞÿäîìÈÏîãîâîğèèòüToolStripMenuItem->Size = System::Drawing::Size(223, 22);
			this->ëå÷üĞÿäîìÈÏîãîâîğèèòüToolStripMenuItem->Text = L"Ëå÷ü ğÿäîì è ïîãîâîğèèòü";
			this->ëå÷üĞÿäîìÈÏîãîâîğèèòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ëå÷üĞÿäîìÈÏîãîâîğèèòüToolStripMenuItem_Click);
			// 
			// t_carees
			// 
			this->t_carees->Tick += gcnew System::EventHandler(this, &MyForm::t_carees_Tick);
			// 
			// t_ness
			// 
			this->t_ness->Tick += gcnew System::EventHandler(this, &MyForm::t_ness_Tick);
			// 
			// b_pause
			// 
			this->b_pause->Location = System::Drawing::Point(573, 238);
			this->b_pause->Name = L"b_pause";
			this->b_pause->Size = System::Drawing::Size(75, 23);
			this->b_pause->TabIndex = 32;
			this->b_pause->Text = L"Pause";
			this->b_pause->UseVisualStyleBackColor = true;
			this->b_pause->Click += gcnew System::EventHandler(this, &MyForm::b_pause_Click);
			// 
			// t_action
			// 
			this->t_action->Interval = 1498;
			this->t_action->Tick += gcnew System::EventHandler(this, &MyForm::t_action_Tick);
			// 
			// b_quit
			// 
			this->b_quit->Location = System::Drawing::Point(742, 346);
			this->b_quit->Name = L"b_quit";
			this->b_quit->Size = System::Drawing::Size(75, 23);
			this->b_quit->TabIndex = 33;
			this->b_quit->Text = L"Quit";
			this->b_quit->UseVisualStyleBackColor = true;
			this->b_quit->Click += gcnew System::EventHandler(this, &MyForm::b_quit_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(15, 32);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(58, 100);
			this->pictureBox2->TabIndex = 34;
			this->pictureBox2->TabStop = false;
			// 
			// l_money
			// 
			this->l_money->AutoSize = true;
			this->l_money->Location = System::Drawing::Point(106, 38);
			this->l_money->Name = L"l_money";
			this->l_money->Size = System::Drawing::Size(0, 13);
			this->l_money->TabIndex = 35;
			// 
			// l_petname
			// 
			this->l_petname->AutoSize = true;
			this->l_petname->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->l_petname->Location = System::Drawing::Point(744, 38);
			this->l_petname->Name = L"l_petname";
			this->l_petname->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->l_petname->Size = System::Drawing::Size(0, 23);
			this->l_petname->TabIndex = 36;
			this->l_petname->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// l_become
			// 
			this->l_become->BackColor = System::Drawing::SystemColors::Control;
			this->l_become->Font = (gcnew System::Drawing::Font(L"Courier New", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->l_become->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->l_become->Location = System::Drawing::Point(39, 59);
			this->l_become->Name = L"l_become";
			this->l_become->Size = System::Drawing::Size(922, 413);
			this->l_become->TabIndex = 37;
			this->l_become->Text = L"Íà÷àòü íîâóş èãğó";
			this->l_become->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->l_become->Click += gcnew System::EventHandler(this, &MyForm::l_become_Click);
			// 
			// TtNotinnes
			// 
			this->TtNotinnes->ToolTipTitle = L"Êîòèê íå õî÷åò âûãóëèâàòüñÿ";
			// 
			// îÏğîãğàììåToolStripMenuItem
			// 
			this->îÏğîãğàììåToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->îÏğîãğàììåToolStripMenuItem->Name = L"îÏğîãğàììåToolStripMenuItem";
			this->îÏğîãğàììåToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->îÏğîãğàììåToolStripMenuItem->Text = L"Î ïğîãğàììå";
			this->îÏğîãğàììåToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::îÏğîãğàììåToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 501);
			this->Controls->Add(this->l_become);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->l_petname);
			this->Controls->Add(this->l_money);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->b_quit);
			this->Controls->Add(this->b_pause);
			this->Controls->Add(this->b_start);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->b_slumb);
			this->Controls->Add(this->b_ness);
			this->Controls->Add(this->b_carees);
			this->Controls->Add(this->b_drain);
			this->Controls->Add(this->b_hunger);
			this->Controls->Add(this->b_boried);
			this->Controls->Add(this->l_slumb);
			this->Controls->Add(this->l_ness);
			this->Controls->Add(this->l_carees);
			this->Controls->Add(this->l_drain);
			this->Controls->Add(this->l_hunger);
			this->Controls->Add(this->l_boried);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1000, 540);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(1000, 540);
			this->Name = L"MyForm";
			this->Text = L"Ïğèëîæåíüêà";
			this->Activated += gcnew System::EventHandler(this, &MyForm::MyForm_MEnter);
			this->Deactivate += gcnew System::EventHandler(this, &MyForm::MyForm_MLeave);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Enter += gcnew System::EventHandler(this, &MyForm::MyForm_MEnter);
			this->Leave += gcnew System::EventHandler(this, &MyForm::MyForm_MLeave);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->contextMenudrain->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->contextMenuhunger->ResumeLayout(false);
			this->contextMenuGames->ResumeLayout(false);
			this->contextMenuLove->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{	
		textBox1 ->Text = Convert::ToString(RatGame());
	}
	private: System::Void ñîõğàíèòüToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{

#ifdef debugonsave
		int i = Convert::ToInt32(textBox2->Text);
		pet.stati[i] = 10;
		ExtraChange(pet);
#endif
		if (SaveToFile(pet,petname) && (petname!="_")) { MessageBox::Show("Ñîõğàíåíî", "Óñïåõ"); }
		else if(petname != "_") { MessageBox::Show("Íå óäàëîñü ñîõğàíèòü", "Îøèïêà"); }
	}
	private: System::Void îòêğûòüToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (petname == "") { std::string name1 = petname;  petname += "_"; ñîõğàíèòüToolStripMenuItem->PerformClick(); petname = name1; }
		PetName^ ff = gcnew(PetName);
		ff->label1->Text = "Êëè÷êà ïèòîìöà, êîòîğîãî íàäî îòêğûòü?";
		ff->ShowDialog();
		std::string nname = msclr::interop::marshal_as<std::string>(ff->textBox1->Text);
		if (LoadFromFile(pet, nname)) { MessageBox::Show("Çàãğóæåíî", "Óñïåõ"); petname = nname; b_start->PerformClick(); }
		else { MessageBox::Show("Íå óäàëîñü çàãğóçèòü, ïğîâåğòå ïğàâèëüíîñòü ââåä¸ííîãî èìåíè: <"+gcnew System::String(nname.c_str())+">.", "ããâï"); }
	}
	private: System::Void ïîêèíóòüÏèòîìöàToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		auto i = MessageBox::Show("Ïèòîìåö îñòàíåòñÿ Âàñ æäàòü. Âû óéä¸òå?", "Çàêğûòü ëè ïğèëîæåíèå", MessageBoxButtons::YesNo);
		if (i == System::Windows::Forms::DialogResult::Yes) 
		{ 
			
			if (issaveonquit && (pet.mood != "dead")) ñîõğàíèòüToolStripMenuItem->PerformClick();
			this->Close();
		}
	}
	private: System::Void MainTimer_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		System::Resources::ResourceManager^ resources = gcnew System::Resources::ResourceManager("ThrGame.ImagesForProject", Assembly::GetExecutingAssembly());
		
		l_money->Text = "Áàëàíñ: "+ Convert::ToString(pet.money) + "$";
		if (!t_action->Enabled)
	 {
		
		
		bool sovp = true;
		for (int i = 0; i < 7; i++) {
			if (pet.stati[i] == stati[i]) continue;
			else
			{
				sovp = false;
				break;
			}
		}

		if (!sovp) 
		{
			for (int i = 0; i < 8; i++) stati[i]=pet.stati[i];
			
		}
		std::string hi = pet.ChekMood();
		pet.mood = hi;

		if (Lampa) 
		{
			if (pet.mood == "dead")
			{
				string s = CheckKill(pet);
				System::String^ text = gcnew System::String(s.c_str());
				
				for (int i = 1; i < 7; i++)
				{
					if (pet.stati[i] <= 0) {
						if (i == 1) label5->BackColor = System::Drawing::Color::FromArgb(0, 0, 0);
						else if (i == 2) label4->BackColor = System::Drawing::Color::FromArgb(0, 0, 0);
						else if (i == 3) label7->BackColor = System::Drawing::Color::FromArgb(0, 0, 0);
						else if (i == 4) label9->BackColor = System::Drawing::Color::FromArgb(0, 0, 0);
						else if (i == 5) label8->BackColor = System::Drawing::Color::FromArgb(0, 0, 0);
						else if (i == 6) label6->BackColor = System::Drawing::Color::FromArgb(0, 0, 0);
					}
				}
				b_quit->PerformClick();
				MessageBox::Show(text,"Óâåäîìëåíèå î êîíöå èãğû");
				
				
			}
			else if (pet.mood == "normal") { pictureBox1->Image = (Bitmap^)resources->GetObject("Fellgood"); }
			else if (pet.mood == "happy") {pictureBox1->Image = (Bitmap^)resources->GetObject("Happy");}
			else if (pet.mood == "bad") {pictureBox1->Image = (Bitmap^)resources->GetObject("Whenboried");}
			else if (pet.mood == "critical") {	pictureBox1->Image = (Bitmap^)resources->GetObject("Itsucks");  }
			else if (pet.mood == "crit_boried") {pictureBox1->Image = (Bitmap^)resources->GetObject("Quitesad");}
			else if (pet.mood == "crit_hunger") {pictureBox1->Image = (Bitmap^)resources->GetObject("Veryhungry");}
			else if (pet.mood == "crit_drain") {pictureBox1->Image = (Bitmap^)resources->GetObject("Lazycry");}
			else if (pet.mood == "crit_carees") {pictureBox1->Image = (Bitmap^)resources->GetObject("Brokenheart");}
			else if (pet.mood == "crit_ness") {pictureBox1->Image = (Bitmap^)resources->GetObject("Wantgoout");}
			else if (pet.mood == "crit_slumb") {pictureBox1->Image = (Bitmap^)resources->GetObject("Wantsleep"); }
		}
		
		if (!sovp) {
			int r, g, b;
			int r1, g1, b1;
			for (int i = 1; i < 7; i++)
			{
				if (pet.stati[i] <= 0) pet.stati[i]=0;
				if (DrawIndex==0) {
					Space_HSVtoRGB::HSVintoRGB(pet.stati[i], 78, 90, r, g, b, DrawIndex);
					Space_HSVtoRGB::HSVintoRGB(pet.stati[i], 64, 41, r1, g1, b1, DrawIndex);
				}
				else {
					Space_HSVtoRGB::HSVintoRGB(pet.stati[i], 80-(int)(pet.stati[i] /4), 99, r, g, b, DrawIndex);
					Space_HSVtoRGB::HSVintoRGB(pet.stati[i], 67 - (int)(pet.stati[i]/4), 60, r1, g1, b1, DrawIndex);
				}
				if (i == 1) {
					l_boried->BackColor = System::Drawing::Color::FromArgb(r, g, b); l_boried->ForeColor = System::Drawing::Color::FromArgb(r1, g1, b1); System::String^ s = "";
					for (int j = 0; j < round(2 * (pet.stati[i] + 1) / 3); j++)
					{
						s += "I";
					}
					l_boried->Text = s;;


				}
				else if (i == 2) {
					l_hunger->BackColor = System::Drawing::Color::FromArgb(r, g, b); l_hunger->ForeColor = System::Drawing::Color::FromArgb(r1, g1, b1);
					System::String^ s = "";
					for (int j = 0; j < round(2 * (pet.stati[i] + 1) / 3); j++)
					{
						s += "I";
					}
					l_hunger->Text = s;
				}
				else if (i == 3) {
					l_drain->BackColor = System::Drawing::Color::FromArgb(r, g, b); l_drain->ForeColor = System::Drawing::Color::FromArgb(r1, g1, b1);
					System::String^ s = "";
					for (int j = 0; j < round(2 * (pet.stati[i] + 1) / 3); j++)
					{
						s += "I";
					}
					l_drain->Text = s;
				}
				else if (i == 4) {
					l_carees->BackColor = System::Drawing::Color::FromArgb(r, g, b); l_carees->ForeColor = System::Drawing::Color::FromArgb(r1, g1, b1);
					System::String^ s = "";
					for (int j = 0; j < round(2 * (pet.stati[i] + 1) / 3); j++)
					{
						s += "I";
					}
					l_carees->Text = s;
				}
				else if (i == 5) {
					l_ness->BackColor = System::Drawing::Color::FromArgb(r, g, b); l_ness->ForeColor = System::Drawing::Color::FromArgb(r1, g1, b1);
					System::String^ s = "";
					for (int j = 0; j < round(2 * (pet.stati[i] + 1) / 3); j++)
					{
						s += "I";
					}
					l_ness->Text = s;
				}
				else if (i == 6) {
					l_slumb->BackColor = System::Drawing::Color::FromArgb(r, g, b); l_slumb->ForeColor = System::Drawing::Color::FromArgb(r1, g1, b1);
					System::String^ s = "";
					for (int j = 0; j < round(2 * (pet.stati[i] + 1) / 3); j++)
					{
						s += "I";
					}
					l_slumb->Text = s;
				}
			}
			{
				b_boried->BringToFront();
				b_carees->BringToFront();
				b_drain->BringToFront();
				b_hunger->BringToFront();
				b_ness->BringToFront();
				b_slumb->BringToFront();
			}
			
		  }
		}
	}
	private: System::Void ïğîâåğêàÂñÿêàÿToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{	
		b_start->Visible = true;
		b_start->PerformClick();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		int i = Convert::ToInt32(textBox2->Text);
		pet.stati[i] = 10;
		i = Convert::ToInt32(textBox1->Text);
		pet.stati[i] = 120;
		

	}
	private: System::Void ïğîâåğêàĞàáîòûËàéáëîâToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if ((label3->Visible == true) && (button3->Visible == true)) { label3->Visible = true; button3->Visible = false; }
		else if ((label3->Visible == true) && (button3->Visible == false)) { label3->Visible = false; button3->Visible = true; }
		else if ((label3->Visible == false) && (button3->Visible == true)) { label3->Visible = false; button3->Visible = false; }
		else if ((label3->Visible == false) && (button3->Visible == false)) { label3->Visible = true; button3->Visible = true; }
	}
	private: System::Void b_boried_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if ((pet.slumber < 40)||(pet.stati[6]<40)) 
		{
			ShowAction("Angry",1200);
		}
		else {int x = this->Location.X + b_boried->Size.Width + b_boried->Location.X;
		int y = this->Location.Y + b_boried->Size.Height + b_boried->Location.Y;
		contextMenuGames->Show(x, y); }
	}
	private: System::Void b_hunger_Click(System::Object^  sender, System::EventArgs^  e)
	{
		int x = this->Location.X + b_hunger->Size.Width + b_hunger->Location.X;
		int y = this->Location.Y + b_hunger->Size.Height + b_hunger->Location.Y;

		if (pet.money < 3* 1) { 
			contextMenuhunger->Items[0]->BackColor = System::Drawing::Color::FromArgb(255, 195, 210); contextMenuhunger->Items[0]->Enabled = false;
			contextMenuhunger->Items[1]->BackColor = System::Drawing::Color::FromArgb(255, 195, 210); contextMenuhunger->Items[1]->Enabled = false;
			contextMenuhunger->Items[3]->BackColor = System::Drawing::Color::FromArgb(255, 195, 210); contextMenuhunger->Items[3]->Enabled = false;
		}
		else if (pet.money < 3* 2) 
			{
			contextMenuhunger->Items[0]->BackColor = System::Drawing::Color::FromArgb(255, 195, 210); contextMenuhunger->Items[0]->Enabled = false;
			contextMenuhunger->Items[1]->BackColor = System::Drawing::Color::FromArgb(199, 255, 199); contextMenuhunger->Items[1]->Enabled = true;
			contextMenuhunger->Items[3]->BackColor = System::Drawing::Color::FromArgb(255, 195, 210); contextMenuhunger->Items[3]->Enabled = false;
			}
		else if (pet.money < 3* 3)
		{
			contextMenuhunger->Items[0]->BackColor = System::Drawing::Color::FromArgb(199, 255, 199); contextMenuhunger->Items[0]->Enabled = true;
			contextMenuhunger->Items[1]->BackColor = System::Drawing::Color::FromArgb(199, 255, 199); contextMenuhunger->Items[1]->Enabled = true;
			contextMenuhunger->Items[3]->BackColor = System::Drawing::Color::FromArgb(255, 195, 210); contextMenuhunger->Items[3]->Enabled = false;
		}
		else if (pet.money >= 3*3)
		{
			contextMenuhunger->Items[0]->BackColor = System::Drawing::Color::FromArgb(199, 255, 199); 
			contextMenuhunger->Items[0]->Enabled = true;
			contextMenuhunger->Items[1]->BackColor = System::Drawing::Color::FromArgb(199, 255, 199); contextMenuhunger->Items[1]->Enabled = true;
			contextMenuhunger->Items[3]->BackColor = System::Drawing::Color::FromArgb(199, 255, 199); contextMenuhunger->Items[3]->Enabled = true;
		}
		contextMenuhunger->Show(x, y);		
	}
	private: System::Void b_drain_Click(System::Object^  sender, System::EventArgs^  e)
	{
		/*Óñëîâèÿ ïîÿâëåíèÿ êîíòåñòíîãî ìåíş*/
		int x = this->Location.X + b_drain->Size.Width + b_drain->Location.X;
		int y = this->Location.Y + b_drain->Size.Height + b_drain->Location.Y;
		if (pet.money < 3* 1) {
			contextMenudrain->Items[1]->BackColor = System::Drawing::Color::FromArgb(255, 195, 210); contextMenudrain->Items[1]->Enabled = false;
			contextMenudrain->Items[2]->BackColor = System::Drawing::Color::FromArgb(255, 195, 210); contextMenudrain->Items[2]->Enabled = false;
			
		}
		else if (pet.money < 3* 3)
		{
			contextMenudrain->Items[1]->BackColor = System::Drawing::Color::FromArgb(199, 255, 199); contextMenudrain->Items[1]->Enabled = true;
			contextMenudrain->Items[2]->BackColor = System::Drawing::Color::FromArgb(255, 195, 210); contextMenudrain->Items[2]->Enabled = false;
		}
		else if (pet.money >=3* 3)
		{
			contextMenudrain->Items[1]->BackColor = System::Drawing::Color::FromArgb(199, 255, 199); contextMenudrain->Items[1]->Enabled = true;
			contextMenudrain->Items[2]->BackColor = System::Drawing::Color::FromArgb(199, 255, 199); contextMenudrain->Items[2]->Enabled = true;
		}
		contextMenudrain->Show(x, y);
	}
	private: System::Void b_carees_Click(System::Object^  sender, System::EventArgs^  e) {
		int x = this->Location.X + b_carees->Size.Width + b_carees->Location.X;
		int y = this->Location.Y + b_carees->Size.Height + b_carees->Location.Y;
		contextMenuLove->Show(x, y);
	}
	private: System::Void b_ness_Click(System::Object^  sender, System::EventArgs^  e) {
		if (pet.necessity <= 85)
		{
			pet.necessity = 120;
			pet.stati[5] = 120;
			b_pause->Visible = true;
			b_pause->PerformClick();
			ShowAction("Innes", 5000);
			
		}
		 
		else if (pet.necessity > 86) ///Íå õî÷åò âûãóëèâàòüñÿ)
		{ 
				TtNotinnes->SetToolTip(b_ness,L"Âîçìîæíî... ñòîèò åù¸ ïîêîğìèòü åãî");
			
			//toolTip1->SetToolTip(b_ness,toolTip1->ToolTipTitle);
		} 
		
	}
	private: System::Void b_slumb_Click(System::Object^  sender, System::EventArgs^  e)
	{
		
		System::Resources::ResourceManager^ resources = gcnew System::Resources::ResourceManager("ThrGame.ImagesForProject", Assembly::GetExecutingAssembly());
		
		if (pet.hunger > 20) {
			if (Lampa)
			{
				Lampa = false;
				t_boried->Enabled = false;
				t_hunger->Interval = (int)(g_time * tn_sl_hung);
				t_drain->Interval = (int)(g_time * tn_sl_drain);
				t_carees->Enabled = false;
				t_ness->Interval = (int)(g_time * tn_sl_ness);
				t_sleep->Interval = (int)(g_time * tn_sl_slumb);
				pictureBox1->Image = (Bitmap^)resources->GetObject("Issleeping");
				{
					b_boried->Enabled = false;
					b_carees->Enabled = false;
					b_drain->Enabled = false;
					b_hunger->Enabled = false;
					b_ness->Enabled = false;
				}
				pictureBox2->Image = (Bitmap^)resources->GetObject("DimLamp");
			}
			else if (!Lampa)
			{
				Lampa = true;
				t_boried->Enabled = true;
				t_boried->Interval = (int)(g_time*tn_wak_boried);
				t_hunger->Interval = (int)(g_time * tn_wak_hung);
				t_drain->Interval = (int)(g_time * tn_wak_drain);
				t_carees->Enabled = true;
				t_carees->Interval = (int)(g_time*tn_wak_carees);
				t_ness->Interval = (int)(g_time * tn_wak_ness);
				t_sleep->Interval = (int)(g_time * tn_wak_slumb);
				pictureBox2->Image = (Bitmap^)resources->GetObject("Lihghtning");

				{
					b_boried->Enabled = true;
					b_carees->Enabled = true;
					b_drain->Enabled = true;
					b_hunger->Enabled = true;
					b_ness->Enabled = true;
				}
			}
			
			
		}
		else {};
		

	}
	
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)
	{	
		
		/*System::String^ s = "";
		for (int i = 0; i < 60; i++)
		{
			s += "I";
		}
		label3->Text = s;/*/

		label4->Visible = false;
		label5->Visible = false;
		label6->Visible = false;
		label7->Visible = false;
		label8->Visible = false;
		label9->Visible = false;
		Lampa = false;
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		b_pause->PerformClick();
		t_action->Enabled = true;
	};
	private: System::Void b_quit_Click(System::Object^  sender, System::EventArgs^  e) 
{	
		
		{
			t_boried->Enabled = false;
			t_carees->Enabled = false;
			t_hunger->Enabled = false;
			t_drain->Enabled = false;
			t_ness->Enabled = false;
			t_sleep->Enabled = false;
		}
		{
			l_boried->Visible = false;
			l_carees->Visible = false;
			l_drain->Visible = false;
			l_hunger->Visible = false;
			l_ness->Visible = false;
			l_slumb->Visible = false;
			b_boried->Visible = false;
			b_carees->Visible = false;
			b_drain->Visible = false;
			b_hunger->Visible = false;
			b_ness->Visible = false;
			b_slumb->Visible = false;


			label4->Visible = false;
			label5->Visible = false;
			label6->Visible = false;
			label7->Visible = false;
			label8->Visible = false;
			label9->Visible = false;

		}
		if (pet.mood != "dead") {
			System::Resources::ResourceManager^ resources = gcnew System::Resources::ResourceManager("ThrGame.ImagesForProject", Assembly::GetExecutingAssembly());
			pictureBox1->Image = (Bitmap^)resources->GetObject("NoData");
			pictureBox2->Image = (Bitmap^)resources->GetObject("NoData");
		}
		else if (pet.mood == "dead")
		{
			System::Resources::ResourceManager^ resources = gcnew System::Resources::ResourceManager("ThrGame.ImagesForProject", Assembly::GetExecutingAssembly());
			pictureBox1->Image = (Bitmap^)resources->GetObject("Gameover");
		}
		
		MainTimer->Enabled = false;
		ToolStripMenuItem^ s = safe_cast<ToolStripMenuItem^>(sender);
		s->Enabled = true;
}
	public: System::Void b_start_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//start.
		b_quit->PerformClick();
		if (petname == "") pet.reset_stati();
		l_become->Visible = false;
		if (petname == "") {
#ifndef debug
			PetName^ form = gcnew(PetName);
			form->ShowDialog();
			petname = msclr::interop::marshal_as<std::string>(form->textBox1->Text);
			if (petname == "") petname = "ÌîéÊîòèê";
#else
			petname = "MyPet";
#endif
		}
		l_petname->Text = gcnew System::String(petname.c_str());
		b_slumb->Visible = true;
		b_slumb->PerformClick();
		stati[3] = 0;
		{
			t_boried->Enabled = Lampa;
			t_carees->Enabled = Lampa;
			t_hunger->Enabled = true;
			t_drain->Enabled = true;
			t_ness->Enabled = true;
			t_sleep->Enabled = true;
		}
		{
			l_boried->Visible = true;
			l_carees->Visible = true;
			l_drain->Visible = true;
			l_hunger->Visible = true;
			l_ness->Visible = true;
			l_slumb->Visible = true;
			b_boried->Visible = true;
			b_carees->Visible = true;
			b_drain->Visible = true;
			b_hunger->Visible = true;
			b_ness->Visible = true;
			b_slumb->Visible = true;


			label4->Visible = true;
			label5->Visible = true;
			label6->Visible = true;
			label7->Visible = true;
			label8->Visible = true;
			label9->Visible = true;

		}
		MainTimer->Enabled = true;

	}
	private: System::Void t_status_Tick(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void t_hunger_Tick(System::Object^  sender, System::EventArgs^  e) {
	pet.hunger--;
	pet.stati[2]--;
}
private: System::Void t_boried_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (!isgamepause) {pet.boried--;
	pet.stati[1]--; }
	else if ((isgamepause) && (pet.boried<120)) 
	{
		pet.boried++;
		pet.stati[1]++;
		int r, g, b;
		int r1, g1, b1;
		if (DrawIndex == 0) {
			Space_HSVtoRGB::HSVintoRGB(pet.stati[1], 78, 90, r, g, b, DrawIndex);
			Space_HSVtoRGB::HSVintoRGB(pet.stati[1], 64, 41, r1, g1, b1, DrawIndex);
		}
		else {
			Space_HSVtoRGB::HSVintoRGB(pet.stati[1], 80 - (int)(pet.stati[1] / 4), 99, r, g, b, DrawIndex);
			Space_HSVtoRGB::HSVintoRGB(pet.stati[1], 67 - (int)(pet.stati[1] / 4), 60, r1, g1, b1, DrawIndex);
		}
			l_boried->BackColor = System::Drawing::Color::FromArgb(r, g, b); l_boried->ForeColor = System::Drawing::Color::FromArgb(r1, g1, b1); System::String^ s = "";
			for (int j = 0; j < round(2 * (pet.stati[1] + 1) / 3); j++)
			{
				s += "I";
			}
			l_boried->Text = s;;		
	}
}
private: System::Void t_drain_Tick(System::Object^  sender, System::EventArgs^  e) {
	pet.drain--;
	pet.stati[3]--;
}
private: System::Void t_sleep_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (Lampa) {
		pet.slumber--;
		pet.stati[6]--;
	}
	else if ((!Lampa) && (pet.stati[6]<120)){
		pet.slumber++;
		pet.stati[6]++;
	}
	if ((!Lampa) && ((pet.stati[6]==120) || (pet.hunger < 30) || (pet.drain < 30) || (pet.necessity < 30))) { b_slumb->PerformClick(); }
}
private: System::Void t_carees_Tick(System::Object^  sender, System::EventArgs^  e) {
	pet.caress--;
	pet.stati[4]--;
}
private: System::Void t_ness_Tick(System::Object^  sender, System::EventArgs^  e) {
	pet.necessity--;
	pet.stati[5]--;
}
private: System::Void b_pause_Click(System::Object^  sender, System::EventArgs^  e) 
{	
	if (l_become->Visible) exit;
	if (isgamepause) 
	{
		isgamepause = false;
		{
			MainTimer->Enabled = true;
			t_boried->Enabled = Lampa;
			t_carees->Enabled = Lampa;
			t_hunger->Enabled = true;
			t_drain->Enabled = true;
			t_ness->Enabled = true;
			t_sleep->Enabled = true;

			b_boried->Enabled = true;
			b_carees->Enabled = true;
			b_drain->Enabled = true;
			b_hunger->Enabled = true;
			b_ness->Enabled = true;
			b_slumb->Enabled = true;
			b_drain->BackColor = System::Drawing::Color::FromArgb(255, 255, 255);
			b_carees->BackColor = System::Drawing::Color::FromArgb(255, 255, 255);
			íàñòğîéêèToolStripMenuItem->Enabled = true;
		}
	}
	else if (!isgamepause) 
	{
		isgamepause = true;
		{
			MainTimer->Enabled = false;
			t_boried->Enabled = false;
			t_carees->Enabled = false;
			t_hunger->Enabled = false;
			t_drain->Enabled = false;
			t_ness->Enabled = false;
			t_sleep->Enabled = false;

			b_boried->Enabled = false;
			b_carees->Enabled = false;
			b_drain->Enabled = false;
			b_hunger->Enabled = false;
			b_ness->Enabled = false;
			b_slumb->Enabled = false;
			b_drain->BackColor = System::Drawing::Color::FromArgb(227, 227, 227);
			b_carees->BackColor = System::Drawing::Color::FromArgb(227, 227, 227);
			íàñòğîéêèToolStripMenuItem->Enabled = false;
		}
	}
	isgamepause ? label3->Text = "Paused" : label3->Text = "Game on";
}
private: System::Void t_action_Tick(System::Object^  sender, System::EventArgs^  e) {
	t_action->Enabled = false;
	t_action->Interval = 1500;
	b_pause->Visible = true;
	b_pause->PerformClick();
	//b_pause->Visible = false;
}
private: System::Void ìÿñîToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	pet.money -= 3* 2;
	pet.necessity -= 4;
	pet.stati[5] -= 4;
	if (pet.hunger < 120) 
		{
		ShowAction("Activeeating");
	if (pet.hunger <= 30) { pet.hunger += 40; pet.stati[2] += 40; }
	else if (pet.hunger <= 60) { pet.hunger += 25; pet.stati[2] += 25; }
	else if (pet.hunger <= 80) { pet.hunger += 15; pet.stati[2] += 15; }
	else if (pet.hunger <= 112) { pet.hunger += 8; pet.stati[2] += 8; }
	else if (pet.hunger > 116) { pet.hunger = 120; pet.stati[2] = 120; }
	}

}
private: System::Void õëåáToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	pet.money -= 3* 1;
	pet.necessity -= 3;
	pet.stati[5] -= 3;
	if (pet.hunger < 120)
		{
			ShowAction("Activeeating");
	if (pet.hunger <= 30) { pet.hunger += 30; pet.stati[2] += 30; }
	else if (pet.hunger <= 60) { pet.hunger += 20; pet.stati[2] += 20; }
	else if (pet.hunger <= 80) { pet.hunger += 9; pet.stati[2] += 9; }
	else if (pet.hunger <= 116) { pet.hunger += 4; pet.stati[2] += 4; }
	else if (pet.hunger > 116) { pet.hunger = 120; pet.stati[2] = 120; }
	}
}
private: System::Void ëèñòüÿToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//pet.money -= 3* 0;
	pet.necessity -= 10;
	pet.stati[5] -= 10;
	if (pet.hunger < 120)
		{
			ShowAction("Activeeating");
		}
	if (pet.hunger <= 116) { pet.hunger += 4; pet.stati[2] += 4; }
	else if (pet.hunger > 116) { pet.hunger = 120; pet.stati[2] = 120; }
	
}
private: System::Void êîğìToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	pet.money -= 3* 3;
	pet.necessity -= 3;
	pet.stati[5] -= 3;
	if (pet.hunger < 120)
		{
			
			ShowAction("Activeeating");
			
		}
	if (pet.hunger <= 112) { pet.hunger += 8; pet.stati[2] += 8; }
	else if (pet.hunger > 113) { pet.hunger = 120; pet.stati[2] = 120; }
	if (pet.hunger <= 30) { pet.hunger += 50; pet.stati[2] += 50; }
	else if (pet.hunger <= 60) { pet.hunger += 35; pet.stati[2] += 35; }
	else if (pet.hunger <= 80) { pet.hunger += 25; pet.stati[2] += 25; }
	else if (pet.hunger <= 106) { pet.hunger += 14; pet.stati[2] += 14; }
	else if (pet.hunger > 106) { pet.hunger = 120; pet.stati[2] = 120; }
	
}

 private: System::Void âîäóToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
 {
	 //pet.money -= 3* 0;
	 pet.necessity -= 3;
	 pet.stati[5] -= 3;
	if (pet.drain < 120)
	{	 
		ShowAction("Ôîí");
	 if (pet.drain <= 30) { pet.drain += 20; pet.stati[3] += 20; }
	 else if (pet.drain <= 60) { pet.drain += 15; pet.stati[3] += 15; }
	 else if (pet.drain <= 80) { pet.drain += 9; pet.stati[3] += 9; }
	 else if (pet.drain <= 115) { pet.drain += 5; pet.stati[3] += 5; }
	 else if (pet.drain > 115) { pet.drain = 120; pet.stati[3] = 120; }
	 }
 }
private: System::Void ìîëîêîToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) { 
	pet.money -= 3* 1;
	pet.necessity -= 6;
	pet.stati[5] -= 6;
	if (pet.drain < 120) 
	{
		ShowAction("Ôîí");
		if (pet.drain <= 30) { pet.drain += 40; pet.stati[3] += 40; }
		else if (pet.drain <= 60) { pet.drain += 25; pet.stati[3] += 35; }
		else if (pet.drain <= 80) { pet.drain += 15; pet.stati[3] += 15; }
		else if (pet.drain <= 112) { pet.drain += 8; pet.stati[3] += 8; }
		else if (pet.drain > 116) { pet.drain = 120; pet.stati[3] = 120; }
	}
	
}
private: System::Void êèñåëüToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{
	pet.money -= 3* 3;
	pet.necessity -= 6;
	pet.stati[5] -= 6;
	if (pet.drain < 120)
		{
			ShowAction("Ôîí");
			if (pet.drain <= 30) { pet.drain += 60; pet.stati[3] += 60; }
			else if (pet.drain <= 60) { pet.drain += 45; pet.stati[3] += 45; }
			else if (pet.drain <= 80) { pet.drain += 35; pet.stati[3] += 35; }
			else if (pet.drain <= 100) { pet.drain += 20; pet.stati[3] += 20; }
			else if (pet.drain > 116) { pet.drain = 120; pet.stati[3] = 120; }
	}
}
private: System::Void ïîãëàäèòüToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	
	if (pet.caress <= 116) { pet.caress += 4; pet.stati[4] += 4; }
	else if (pet.caress > 117) { pet.caress = 120; pet.stati[4] = 120; }
	ShowAction("Flykiss");
}
private: System::Void îáíÿòüToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (pet.caress <= 107) { pet.caress += 13; pet.stati[4] += 13; }
	else if (pet.caress > 108) { pet.caress = 120; pet.stati[4] = 120; }
	ShowAction("Wowlove", 2100);
}
private: System::Void ïîöåëîâàòüToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (pet.caress <= 107) { pet.caress += 13; pet.stati[4] += 13; }
	else if (pet.caress > 108) { pet.caress = 120; pet.stati[4] = 120; }
	ShowAction("Flykiss");
}
private: System::Void ëå÷üĞÿäîìÈÏîãîâîğèèòüToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (pet.caress <= 85) { pet.caress += 35; pet.stati[4] += 35; }
	else if (pet.caress > 86) { pet.caress = 120; pet.stati[4] = 120; }
	{
		ShowAction("Calm", 3000);
	}
}
public: System::Void ShowAction(System::String^ der)
	{
		b_pause->Visible = true;
		b_pause->PerformClick();
		System::Resources::ResourceManager^ resources = gcnew System::Resources::ResourceManager("ThrGame.ImagesForProject", Assembly::GetExecutingAssembly());
		pictureBox1->Image = (Bitmap^)resources->GetObject(der);
		t_action->Enabled = true;
	}
public: System::Void ShowAction(System::String^ der, const int INTERVAL) 
	{
		b_pause->Visible = true;
		b_pause->PerformClick();
		System::Resources::ResourceManager^ resources = gcnew System::Resources::ResourceManager("ThrGame.ImagesForProject", Assembly::GetExecutingAssembly());
		pictureBox1->Image = (Bitmap^)resources->GetObject(der);
		t_action->Interval = INTERVAL;
		t_action->Enabled = true;
	}
private: System::Void textBox2_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	try {
		pet.money = Convert::ToInt32(textBox2->Text);
		label3->Text = "Äåíüãè íà÷èñëåíû";
	}
	catch (const std::exception & ex) 
	{
		System::String^error = "Âîçíèêëà îøèáêà" + *ex.what();
		label3->Text = error;
		delete error;
	}
		
}

private: System::Void óãàäàòüĞàíäîìíîå×èñëîToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e){}
 private: System::Void g1_game_click(System::Object^  sender, System::EventArgs^  e)
 {
	 
	 ToolStripMenuItem^ tlstrp = safe_cast<ToolStripMenuItem^>(sender);
	 System::String^ name = tlstrp->Name;
	 Number ^formnumber = gcnew Number();
	 if (name == "g1_easy") { formnumber->l_value->Text = "8"; }
	 else if (name == "g1_medium") { formnumber->l_value->Text = "12"; }
	 else if (name == "g1_hard") { formnumber->l_value->Text = "16"; }
	 delete name;
	 this->b_pause->PerformClick();
	 this->b_pause->Visible = false;
	 this->t_boried->Interval = (int)(tn_wak_boried * 4 * g_time);
	 this->t_boried->Enabled = true;
	 System::Resources::ResourceManager^ resources = gcnew System::Resources::ResourceManager("ThrGame.ImagesForProject", Assembly::GetExecutingAssembly());
	 pictureBox1->Image = (Bitmap^)resources->GetObject("Phoneplayng");
	 formnumber->ShowDialog();
	 this->t_boried->Enabled = false;
	 Lampa ? this->t_boried->Interval = (int)(g_time * tn_wak_boried) : this->t_boried->Interval = (int)(g_time * tn_sl_boried);
	 int zarab = Convert::ToInt32(formnumber->l_n_pobed->Text);
	 pet.money += zarab;this->b_pause->Visible = true;
	 if (zarab != 0)
	 {
		 pictureBox1->Image =(Bitmap^)resources->GetObject("Inreech"); 
		 t_action->Enabled = true;
	 }
	 else { b_pause->PerformClick(); 
	 }
	 delete formnumber;
 }
private: System::Void íàñòğîéêèToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{
	//Íàñòğîéêè
	if (petname != "")b_pause->PerformClick();
		Options^formoptions = gcnew Options();
		DrawIndex == 0 ? formoptions->radioButton1->Checked=true: formoptions->radioButton2->Checked=true;
		StopInLeave ? formoptions->cb_gamestop->Checked = true : formoptions->cb_gamestop->Checked = false;
		issaveonquit ? formoptions->cb_onsave->Checked = true : formoptions->cb_onsave->Checked = false;
		formoptions->trackBar1->Value=g_time;
		formoptions->ShowDialog();
		 tn_wak_boried = (1 / Convert::ToDouble(formoptions->textBox1->Text));
		 tn_sl_boried = (1 / Convert::ToDouble(formoptions->textBox12->Text));
		 tn_wak_drain = (1 / Convert::ToDouble(formoptions->textBox3->Text));
		 tn_sl_drain = (1 / Convert::ToDouble(formoptions->textBox10->Text));
		 tn_wak_carees = (1 / Convert::ToDouble(formoptions->textBox4->Text));
		 tn_sl_carees = (1 / Convert::ToDouble(formoptions->textBox9->Text));
		 tn_wak_ness = (1 / Convert::ToDouble(formoptions->textBox5->Text));
		 tn_sl_ness = (1 / Convert::ToDouble(formoptions->textBox8->Text));
		 tn_sl_slumb = (1 / Convert::ToDouble(formoptions->textBox7->Text));
		 tn_wak_slumb = (1 / Convert::ToDouble(formoptions->textBox6->Text));
		 tn_wak_hung = (1 / Convert::ToDouble(formoptions->textBox2->Text));
		 tn_sl_hung = (1 / Convert::ToDouble(formoptions->textBox11->Text));
		 StopInLeave = formoptions->cb_gamestop->Checked;
		 issaveonquit = formoptions->cb_onsave->Checked;
		 formoptions->radioButton1->Checked ? DrawIndex = 0 : DrawIndex = 1;

		 g_time = formoptions->trackBar1->Value;
		 if (petname != "") 
		 {
			 if (!Lampa)
			 {
				 t_hunger->Interval = (int)(g_time * tn_sl_hung); 
				 t_drain->Interval = (int)(g_time * tn_sl_drain);
				 t_ness->Interval = (int)(g_time * tn_sl_ness);
				 t_sleep->Interval = (int)(g_time * tn_sl_slumb);
			 }
			 else if (Lampa)
			 {
				 t_boried->Interval = (int)(g_time*tn_wak_boried);
				 t_hunger->Interval = (int)(g_time * tn_wak_hung);
				 t_drain->Interval = (int)(g_time * tn_wak_drain);
				 t_carees->Interval = (int)(g_time*tn_wak_carees);
				 t_ness->Interval = (int)(g_time * tn_wak_ness);
				 t_sleep->Interval = (int)(g_time * tn_wak_slumb);
			 }
			 
			 b_pause->PerformClick();
			 if (!Lampa) {
				 b_slumb->PerformClick();
				 b_slumb->PerformClick();
			 }
		 }
		 delete formoptions;
}
private: System::Void MyForm_MLeave(System::Object^  sender, System::EventArgs^  e) 
{
	if (StopInLeave) b_pause->PerformClick();
}
private: System::Void MyForm_MEnter(System::Object^  sender, System::EventArgs^  e) 
{
	if (StopInLeave) b_pause->PerformClick();
}
private: System::Void íàéòèÏàğóÊàğòToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{

	this->b_pause->PerformClick();
	this->t_boried->Interval = (int)(tn_wak_boried*g_time*4.5);
	this->b_pause->Visible = true;
	System::Resources::ResourceManager^ resources = gcnew System::Resources::ResourceManager("ThrGame.ImagesForProject", Assembly::GetExecutingAssembly());
	pictureBox1->Image = (Bitmap^)resources->GetObject("Phoneplayng");

	int zarab = RatGame();
	this->t_boried->Enabled = false;
	Lampa ? this->t_boried->Interval = (int)(g_time * tn_wak_boried) : this->t_boried->Interval = (int)(g_time * tn_sl_boried);
	pet.money += zarab;
	this->b_pause->Visible = true;
	if (zarab != 0)
	{
		pictureBox1->Image = (Bitmap^)resources->GetObject("Inreech");
		t_action->Enabled = true;
	}
	else { b_pause->PerformClick();}
	
}
private: System::Void ğàáîòàToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void ñîçäàòüToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{
	ToolStripMenuItem^ s = safe_cast<ToolStripMenuItem^>(sender);
	s->Enabled = false;
	petname = "";
	b_start->Visible = true;
	b_start->PerformClick();
}
private: System::Void l_become_Click(System::Object^  sender, System::EventArgs^  e) 
{
	ñîçäàòüToolStripMenuItem->PerformClick();
}

private: System::Void îÏğîãğàììåToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	AboutGame^ about = gcnew(AboutGame);
	if (!l_become->Visible) {
		b_pause->PerformClick();

		System::Resources::ResourceManager^ resources = gcnew System::Resources::ResourceManager("ThrGame.ImagesForProject", Assembly::GetExecutingAssembly());
		pictureBox1->Image = (Bitmap^)resources->GetObject("ReadingInfo");
	}
	about->ShowDialog();
	b_pause->PerformClick();
}
};

}