#pragma once
#include <cmath>
#include <fstream>
double** mass;
int N, M, cuur_numb = 0;
bool go = false;
namespace Lab6 {

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
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	public: System::Windows::Forms::Timer^ timer1;
	private:

	private: System::ComponentModel::IContainer^ components;

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea3->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea3);
			legend3->Name = L"Legend1";
			this->chart1->Legends->Add(legend3);
			this->chart1->Location = System::Drawing::Point(267, 32);
			this->chart1->Name = L"chart1";
			series5->ChartArea = L"ChartArea1";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series5->Color = System::Drawing::Color::LimeGreen;
			series5->Legend = L"Legend1";
			series5->Name = L"U(x,0)";
			series6->ChartArea = L"ChartArea1";
			series6->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series6->Color = System::Drawing::Color::DarkViolet;
			series6->Legend = L"Legend1";
			series6->Name = L"U(x,1/2)";
			this->chart1->Series->Add(series5);
			this->chart1->Series->Add(series6);
			this->chart1->Size = System::Drawing::Size(929, 555);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &MyForm::chart1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(18, 202);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(186, 55);
			this->button1->TabIndex = 1;
			this->button1->Text = L"рисовать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Location = System::Drawing::Point(18, 46);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(227, 139);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Началлные параметры ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 99);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(66, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Шаг по t: τ=";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 96);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 13);
			this->label3->TabIndex = 8;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(80, 96);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(37, 20);
			this->textBox3->TabIndex = 7;
			this->textBox3->Text = L"0,05";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 58);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(74, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Шаг по x: h = ";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(80, 58);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(37, 20);
			this->textBox2->TabIndex = 5;
			this->textBox2->Text = L"0,1";
			// 
			// timer1
			// 
			this->timer1->Interval = 333;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1223, 619);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->chart1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		double h = 0, tau = 0;
		bool mistake = false;
		try {
			h = Convert::ToDouble(textBox2->Text);
			tau = Convert::ToDouble(textBox3->Text);
		}
		catch (...)
		{
			System::Windows::Forms::MessageBox::Show("неверно введены данные!", "Возможно тут кроется ошибка");
			mistake = true;
		}
		if (!mistake) {
			int n = (int)(1 / h);
			int m = (int)(0.5 / tau);

			double** U = new double* [n + 1];
			for (int i = 0; i <= n; i++)
			{
				U[i] = new double[m + 1];
			}
			for (int i = 0; i <= n; i++) U[i][0] = fi(h * i);
			for (int j = 1; j <= m; j++) U[0][j] = nu1(tau * j);
			for (int j = 1; j <= m; j++) U[n][j] = nu2(tau * j);
			for (int i = 0; i <= n; i++) U[i][1] = U[i][0] + tau * psi(i * h) + tau * tau * d2fi(i * h) / 2;

			double alpha = pow((tau / h), 2);
			for (int j = 1; j < m; j++)
			{
				for (int i = 1; i < n; i++)
				{
					U[i][j + 1] = alpha * (U[i + 1][j] + U[i - 1][j]) + 2 * (1 - alpha) * U[i][j] - U[i][j - 1];
				}
			}
			N = n, M = m; cuur_numb = 0;
			mass = new double* [n + 1];
			for (int i = 0; i <= n; i++) mass[i] = new double[m + 1];
			for (int i = 0; i <= N; i++)
			{
				for (int j = 0; j <= M; j++)
				{
					mass[i][j] = U[i][j];
				}
			}
			timer1->Enabled = true;

			chart1->Series[1]->Points->AddXY(0, 2);
			chart1->Series[1]->Points->AddXY(0, -2);
			/*	using namespace std;
				ofstream file;
				file.open("MyFile.txt");
				if (file.is_open())
				{
					for (int j = 0; j <= m; j++)
					{
						if (j!=0) file << endl;
						file << "t=" << tau * j << endl;
						for (int i = 0; i <= n; i++)
							file << U[i][j] << ',';
					}
				}
				file.close();*/

			for (int i = 0; i <= n; i++) delete[] U[i];
			delete[] U;
		}
	}

	private: System::Double nu1(const double t)
	{
		return 0.4;
	}
	private: System::Double nu2(const double t)
	{
		return 1.2 * t;
	}
	private: System::Double fi(const double x)
	{
		return (x + 0.4) * cos(3.1415926535 * x / 2);
	}
	private: Double d2fi(const double x)
	{
		return -((pow(3.1415926535, 2) * (x + 0.4) * cos(3.1415926535 * x / 2) / 4) + sin(3.1415926535 * x / 2));
	}
	private: System::Double psi(const double x)
	{
		return 0.3 * (x * x + 1);
	}
	public: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		chart1->Series[0]->Points->Clear();
		for (int i = 0; i <= N; i++)
		{
			chart1->Series[0]->Points->AddXY(i * Convert::ToDouble(textBox2->Text), mass[i][cuur_numb]);
		}
		cuur_numb++;
		if (cuur_numb > M)
			timer1->Enabled = false;
	}
	private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
