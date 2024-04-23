#pragma once
#include "Solving(Gauss).cpp"



namespace KSR1lab {
	SLAU eq(1);
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:

	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button3;

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->Column2, this->Column3
			});
			this->dataGridView1->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->dataGridView1->Location = System::Drawing::Point(12, 35);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(720, 270);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellBeginEdit += gcnew System::Windows::Forms::DataGridViewCellCancelEventHandler(this, &MyForm::dataGridView1_CellBeginEdit);
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			this->dataGridView1->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellEndEdit);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Column1";
			this->Column1->Name = L"Column1";
			this->Column1->Width = 73;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Column2";
			this->Column2->Name = L"Column2";
			this->Column2->Width = 73;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Column3";
			this->Column3->Name = L"Column3";
			this->Column3->Width = 73;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(23, 249);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(104, 249);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(155, 9);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(24, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"4";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(20, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(129, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Размерность матрицы: ";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(22, 365);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(142, 57);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Находить что-то там...";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1242, 604);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) 
	{
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	
		int n = dataGridView1->ColumnCount;
		if (n == 0) 
		{ 
			dataGridView1->Columns->Add("sv_chleni", "Св. члены"); 
			dataGridView1->Columns->Add("none", "-//-//-//-");
			dataGridView1->Columns[1]->ReadOnly= true;
		}
		n = dataGridView1->ColumnCount-2;
		dataGridView1->Columns->Add(Convert::ToString(n+1),"X"+Convert::ToString(n+1));
		dataGridView1->Rows->Add("", "|");
		
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
			dataGridView1->Columns->Clear();
	}

private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) 
{
	dataGridView1->AutoSize = false;
	button2->PerformClick();
}



	private: System::Void dataGridView1_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
	{
		//TextBox^ tbx = safe_cast<TextBox^>(sender);
		int j = e->RowIndex;
		int i = e->ColumnIndex;
		DataGridView^ grd = safe_cast<DataGridView^>(sender);
		DataGridViewTextBoxCell^ cell = safe_cast<DataGridViewTextBoxCell^>(grd->CurrentCell);
		String^ s = cell->FormattedValue->ToString();
		double valueincell;
		while (s->IndexOf('.') != -1)
		{
			int pos = s->IndexOf('.');
			s = s->Remove(pos, 1);
			s = s->Insert(pos, ",");
		}
		if (s->IndexOf('/') != -1)
		{
			String^ s2 = s->Copy(s);
			int pos = s->IndexOf('/');
			s2 = s2->Remove(0, pos + 1);
			String^ s1 = s->Copy(s);
			s1 = s1->Remove(pos, s1->Length - pos);
			try
			{
				valueincell = Convert::ToDouble(s1) / Convert::ToDouble(s2);
				if (valueincell == INFINITY) valueincell = 0;
			}
			catch (...)
			{
				valueincell = 0;
				grd->CurrentCell->Value = 0;
			}

		}

		else
		{
			try
			{
				valueincell = Convert::ToDouble(s);
			}
			catch (...)
			{
				grd->CurrentCell->Value = 0;
				valueincell = 0;
			}
		}
		if (i == 0) { eq.Set(j+1, valueincell); }
		else if (i > 1) { eq.Set(i-1, j+1, valueincell); }	
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) 
{	
	button2->PerformClick();
	try 
	{ 
		eq.Set(Convert::ToInt32(textBox1->Text)); 
	}
	catch (...) {};
	if ((textBox1->Text != "0") && (textBox1->Text != "") && (textBox1->Text->Length < 3)) 
	{
		for (int i = 0; i < Convert::ToInt32(textBox1->Text); i++) button1->PerformClick();
	}
}
private: System::Void dataGridView1_CellBeginEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^ e) 
{
	
	
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	SLAU equation(Convert::ToInt32(textBox1->Text));
	double g1 = eq.Get(3, 4);
	// Здесь заполняем массивчик :)
	eq.privod();
}
};
}
