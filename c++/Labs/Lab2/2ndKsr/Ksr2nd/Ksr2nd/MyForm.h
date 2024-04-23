#pragma once
#include <cmath>
//#define DEBUG
namespace Ksr2nd 
{
	int n = 7;
}

namespace Ksr2nd {

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
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::TextBox^ tb_nizhn;
	private: System::Windows::Forms::TextBox^ tb_verhn;

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tb_nizhn = (gcnew System::Windows::Forms::TextBox());
			this->tb_verhn = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(876, 121);
			this->dataGridView1->TabIndex = 0;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(894, 12);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(90, 20);
			this->numericUpDown1->TabIndex = 1;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 7, 0, 0, 0 });
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown1_ValueChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(894, 50);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(95, 27);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Строить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(12, 153);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(700, 408);
			this->chart1->TabIndex = 3;
			this->chart1->Text = L"chart1";
			// 
			// tb_nizhn
			// 
			this->tb_nizhn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->tb_nizhn->Location = System::Drawing::Point(589, 531);
			this->tb_nizhn->Name = L"tb_nizhn";
			this->tb_nizhn->Size = System::Drawing::Size(59, 20);
			this->tb_nizhn->TabIndex = 4;
			this->tb_nizhn->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::PredeliTextEditing);
			// 
			// tb_verhn
			// 
			this->tb_verhn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->tb_verhn->Location = System::Drawing::Point(654, 531);
			this->tb_verhn->Name = L"tb_verhn";
			this->tb_verhn->Size = System::Drawing::Size(58, 20);
			this->tb_verhn->TabIndex = 5;
			this->tb_verhn->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::PredeliTextEditing);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1010, 573);
			this->Controls->Add(this->tb_verhn);
			this->Controls->Add(this->tb_nizhn);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		//
		if (n < numericUpDown1->Value) 
		{
			n++;
			dataGridView1->Columns->Add("column" + Convert::ToString(numericUpDown1->Value), "X" + Convert::ToString(numericUpDown1->Value));
		}
		else if (n > numericUpDown1->Value)
		{
			--n;
			dataGridView1->Columns->RemoveAt(n);
		}
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		dataGridView1->Columns->Add("column1", "X1");
		dataGridView1->Columns->Add("column2", "X2");
		dataGridView1->Columns->Add("column3", "X3");
		dataGridView1->Columns->Add("column4", "X4");
		dataGridView1->Columns->Add("column5", "X5");
		dataGridView1->Columns->Add("column6", "X6");
		dataGridView1->Columns->Add("column7", "X7");
		dataGridView1->Rows->Add();
		
		{
			for (int i = 0; i < 7; i++) dataGridView1[i, 0]->Value =  1.3 + 0.2 * i;
			dataGridView1[0, 1]->Value = -0.2293;
			dataGridView1[1, 1]->Value = -0.3258;
			dataGridView1[2, 1]->Value = -0.3086;
			dataGridView1[3, 1]->Value = -0.1836;
			dataGridView1[4, 1]->Value = 0.0056;
			dataGridView1[5, 1]->Value = 0.1928;
			dataGridView1[6, 1]->Value = 0.3127;
		}
		tb_nizhn->Text = "1,3";
		tb_verhn->Text = "2,5";
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
{
	chart1->Series[0]->Points->Clear();
	double* x0 = new double[n];
	double* y0 = new double[n];
	for (int i = 0; i < n; i++)
	{
		x0[i] = Convert::ToDouble(dataGridView1[i, 0]->Value);
		y0[i] = Convert::ToDouble(dataGridView1[i, 1]->Value);
	}
	 #ifndef DEBUG
	double* a = new double[n];
	double* b = new double[n];
	double* c= new double[n+1];
	double* d = new double[n];
	//////  Нахождение коэффицентов 

	double* h = new double[n];
	double* w = new double[n];
	double* u = new double[n];
	double* v = new double[n];
	double* k = new double[n];
	double* l = new double[n];
#else
	double a[7] = { 0 };
	double b[7] = { 0 };
	double c[9] = { 0 };
	double d[7] = { 0 };

	double h[7] = { 0 };
	double w[7] = { 0 };
	double u[7] = { 0 };
	double v[7] = { 0 };
	double k[7] = { 0 };
	double l[7] = { 0 };

#endif // !1

	

	for (int i = 1; i < n; i++)
		h[i] = x0[i] - x0[i - 1];
	for (int i = 2; i < n; i++)
	{
		w[i] = h[i - 1];
		u[i] = 2 * (h[i - 1] + h[i]);
		v[i] = 3 * (((y0[i] - y0[i - 1]) / h[i]) - (y0[i - 1] - y0[i - 2]) / h[i - 1]);
	}
	k[1] = 0;
	l[1] = 0;
	for (int i = 2; i < n; i++)
	{
		k[i] = (v[i] - w[i] * k[i - 1]) / (u[i] - w[i] * l[i - 1]);
		l[i] = h[i] / (u[i] - w[i] * l[i - 1]);
	}

	c[0] = 0;
	c[n] = 0;
	for (int i = n - 1; i > 0; i--)
	{
		c[i] = k[i] - l[i] * c[i + 1];
	}

	for (int i = 1; i < n; i++)
	{
		a[i] = y0[i - 1];
		b[i] = ((y0[i] - y0[i - 1]) / h[i]) - (1. / 3.) * h[i] * (c[i + 1] + 2 * c[i]);
		d[i] = (c[i + 1] - c[i]) / (3 * h[i]);
	}
#ifndef  DEBUG
	delete[] h;
	delete[] w;
	delete[] u;
	delete[] v;
	delete[] k;
	delete[] l;
#endif // ! DEBUG

	/////
	double s = 0;
	double xnizh = Convert::ToDouble(tb_nizhn->Text);
	double xverxn = Convert::ToDouble(tb_verhn->Text);
	for (double xr = xnizh; xr <= xverxn; xr += 0.01)
	{
		for (int i = 1; i < n; i++)
		{
			if ((xr >= x0[i - 1]) && (xr < x0[i])) 
			{
				s = a[i] + b[i] * (xr - x0[i - 1]) + c[i] * pow((xr - x0[i - 1]), 2) + d[i] * pow((xr - x0[i - 1]), 3);
				chart1->Series[0]->Points->AddXY(xr, s);
				s = 0;
				break;
			}
		}
	}

	//////
	delete[] x0;
	delete[] y0;
#ifndef  DEBUG
	delete[] a;
	delete[] b;
	delete[] c;
	delete[] d;
#endif // ! DEBUG
}
private: System::Void PredeliTextEditing(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
{
	
	if (e->KeyChar == '.') e->KeyChar = ',';
	else if (e->KeyChar == '-') return;
	else if (Char::IsDigit(e->KeyChar)) return;
	else if (e->KeyChar == (char)Keys::Enter)
	{
		TextBox^ tb = safe_cast<TextBox^>(sender);
		if (tb->Name == "tb_nizhn") tb_verhn->Focus();
		else if (tb->Name == "tb_verhn") button1->Focus();
		else return;
	}
	else if (e->KeyChar == (char)Keys::Back) return;
	else e->Handled = true;
}

};
}
