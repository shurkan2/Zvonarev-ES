#pragma once

double gunc(const double x, const double y, const double z)
{
	return z;
}

double func(const double x, const double y, const double z)
{
	return 2+3*y-2*z/x;
}

namespace Lab5 {

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
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button2;
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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 187);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(84, 37);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Занятся построением";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(330, 8);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series1->Color = System::Drawing::Color::BlueViolet;
			series1->LabelForeColor = System::Drawing::Color::Violet;
			series1->Legend = L"Legend1";
			series1->Name = L"y(x)";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(682, 284);
			this->chart1->TabIndex = 1;
			this->chart1->Text = L"chart1";
			// 
			// chart2
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart2->Legends->Add(legend2);
			this->chart2->Location = System::Drawing::Point(372, 307);
			this->chart2->Name = L"chart2";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series2->Color = System::Drawing::Color::MediumSpringGreen;
			series2->Legend = L"Legend1";
			series2->Name = L"y\'(x)";
			this->chart2->Series->Add(series2);
			this->chart2->Size = System::Drawing::Size(604, 226);
			this->chart2->TabIndex = 2;
			this->chart2->Text = L"chart2";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Location = System::Drawing::Point(9, 25);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(181, 143);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Параметры";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(8, 106);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(72, 16);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Шаг h = ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(8, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L" λ2 = ";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(8, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L" λ1 = ";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(91, 100);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(66, 22);
			this->textBox3->TabIndex = 2;
			this->textBox3->Text = L"0,001";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(91, 57);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(66, 22);
			this->textBox2->TabIndex = 1;
			this->textBox2->Text = L"2";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(91, 28);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(66, 22);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"1";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(937, 269);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Clear";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(901, 510);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Clear";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1027, 547);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->chart2);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		// y'(gamm) = a, y(gamm) = a
		double a = 1.5, b = 3, b1=0, b2=0, l1=0, l2=1, l=0;
		double h = 0.001;
		int n = 1+(int)((1.1-0.8)/h);
		double** tabl1 = new double* [n], ** tabl2 = new double* [n];
		for (int i = 0; i < n; i++)
		{
			tabl1[i] = new double[3];
			tabl2[i] = new double[3];
		}
		FindRunge(0.8, n, h, l1, a, tabl1);
		FindRunge(0.8, n, h, l2, a, tabl2);

		b1 = tabl1[n - 1][2] + 2 * tabl1[n - 1][1];
		b2 = tabl2[n - 1][2] + 2 * tabl2[n - 1][1];

		l = l1 + (l2 - l1) * ((b - b1) / (b2 - b1));

		double y = 0, z = 0;
		for (int i = 0; i < n; i++)
		{
			
			y = tabl1[i][1] + (tabl2[i][1] - tabl1[i][1]) * ((l - l1) / (l2 - l1));
			z = tabl1[i][2] + (tabl2[i][2] - tabl1[i][2]) * ((l - l1) / (l2 - l1));
			chart1->Series[0]->Points->AddXY(tabl1[i][0], y);
			chart2->Series[0]->Points->AddXY(tabl1[i][0], z);
		}
		{
			for (int i = 0; i < n; i++)
			{
				delete[] tabl1[i];
				delete[] tabl2[i];	
			}
			delete[] tabl1;
			delete[] tabl2;
		}
	}
	private: Void FindRunge(const double xmin, const double n/*Размерность массива*/, const double h, const double l, const double a,double** mass)
	{
		// z' = f(xyz) y'=z=g(xyz)
		double k1, k2, k3, k4, q1, q2, q3, q4;
		double x = xmin, y = l, z = a;
		mass[0][0] = x; mass[0][1] = y; mass[0][2] = z;
		for (int i = 0; i < n;)
		{
				k1 = h * func(x, y, z);
				q1 = h * gunc(x, y, z);

				k2 = h * func(x + h / 2.0, y + q1 / 2.0, z + k1 / 2.0);
				q2 = h * gunc(x + h / 2.0, y + q1 / 2.0, z + k1 / 2.0);

				k3 = h * func(x + h / 2.0, y + q2 / 2.0, z + k2 / 2.0);
				q3 = h * gunc(x + h / 2.0, y + q2 / 2.0, z + k2 / 2.0);

				k4 = h * func(x + h, y + q3, z + k3);
				q4 = h * gunc(x + h, y + q3, z + k3);

				z += (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;
				y += (q1 + 2.0 * q2 + 2.0 * q3 + q4) / 6.0;
				x = xmin + i*h;
				mass[i][0] = x; mass[i][1] = y; mass[i][2] = z;
				i++;		
		}
	 };
 private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
 {
	 chart1->Series[0]->Points->Clear();
 }
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) 
{
	chart2->Series[0]->Points->Clear();
}
};
}


/* С 18:10 по 19:28 происходит неизвестная фигня в функции Рунге, о которой ничего не известно. Просто так вызывается исклюение в программе
(Просто один олух умеет граммотно прописывать размеры динамического массива)*/
