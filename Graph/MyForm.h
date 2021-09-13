#pragma once
#include <Windows.h>
#include "MyGraph.h"
#include "Vertex.h"

namespace Graph {

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
	private: System::Windows::Forms::TextBox^ out_path;
	private: System::Windows::Forms::TextBox^ out_work;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ vertex;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ edge_with;

	public:


	public:

	public:

	public:

	public:

	protected:
		MyGraph^ myGraph;
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
	private: System::Windows::Forms::Button^ depthButton;
	private: System::Windows::Forms::Button^ breadthButton;













































	private: System::Windows::Forms::DataGridView^ dataGridView1;








	private: System::Windows::Forms::Button^ dataButton;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;











	protected:















































































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
			this->depthButton = (gcnew System::Windows::Forms::Button());
			this->breadthButton = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dataButton = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->out_path = (gcnew System::Windows::Forms::TextBox());
			this->out_work = (gcnew System::Windows::Forms::TextBox());
			this->vertex = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->edge_with = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// depthButton
			// 
			this->depthButton->Location = System::Drawing::Point(13, 260);
			this->depthButton->Name = L"depthButton";
			this->depthButton->Size = System::Drawing::Size(212, 75);
			this->depthButton->TabIndex = 0;
			this->depthButton->Text = L"Поиск в глубину";
			this->depthButton->UseVisualStyleBackColor = true;
			this->depthButton->Click += gcnew System::EventHandler(this, &MyForm::depthButton_Click);
			// 
			// breadthButton
			// 
			this->breadthButton->Location = System::Drawing::Point(13, 360);
			this->breadthButton->Name = L"breadthButton";
			this->breadthButton->Size = System::Drawing::Size(212, 75);
			this->breadthButton->TabIndex = 1;
			this->breadthButton->Text = L"Поиск в ширину";
			this->breadthButton->UseVisualStyleBackColor = true;
			this->breadthButton->Click += gcnew System::EventHandler(this, &MyForm::breadthButton_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->vertex,
					this->edge_with
			});
			this->dataGridView1->Location = System::Drawing::Point(13, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(461, 216);
			this->dataGridView1->TabIndex = 37;
			this->dataGridView1->TabStop = false;
			// 
			// dataButton
			// 
			this->dataButton->Location = System::Drawing::Point(502, 12);
			this->dataButton->Name = L"dataButton";
			this->dataButton->Size = System::Drawing::Size(212, 75);
			this->dataButton->TabIndex = 40;
			this->dataButton->Text = L"Подтвердить граф";
			this->dataButton->UseVisualStyleBackColor = true;
			this->dataButton->Click += gcnew System::EventHandler(this, &MyForm::dataButton_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(549, 135);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(120, 24);
			this->comboBox1->TabIndex = 41;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(549, 204);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(120, 24);
			this->comboBox2->TabIndex = 42;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(504, 107);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(211, 17);
			this->label1->TabIndex = 43;
			this->label1->Text = L"Выберите начальную вершину";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(504, 178);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(203, 17);
			this->label2->TabIndex = 44;
			this->label2->Text = L"Выберите конечную вершину";
			// 
			// out_path
			// 
			this->out_path->Location = System::Drawing::Point(240, 260);
			this->out_path->Multiline = true;
			this->out_path->Name = L"out_path";
			this->out_path->ReadOnly = true;
			this->out_path->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->out_path->Size = System::Drawing::Size(234, 175);
			this->out_path->TabIndex = 46;
			this->out_path->TabStop = false;
			this->out_path->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// out_work
			// 
			this->out_work->Location = System::Drawing::Point(480, 260);
			this->out_work->Multiline = true;
			this->out_work->Name = L"out_work";
			this->out_work->ReadOnly = true;
			this->out_work->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->out_work->Size = System::Drawing::Size(234, 175);
			this->out_work->TabIndex = 47;
			this->out_work->TabStop = false;
			this->out_work->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// vertex
			// 
			this->vertex->HeaderText = L"Вершина";
			this->vertex->MinimumWidth = 100;
			this->vertex->Name = L"vertex";
			this->vertex->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->vertex->Width = 125;
			// 
			// edge_with
			// 
			this->edge_with->HeaderText = L"Соединена с";
			this->edge_with->MinimumWidth = 100;
			this->edge_with->Name = L"edge_with";
			this->edge_with->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->edge_with->Width = 125;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(730, 447);
			this->Controls->Add(this->out_work);
			this->Controls->Add(this->out_path);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->dataButton);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->breadthButton);
			this->Controls->Add(this->depthButton);
			this->Name = L"MyForm";
			this->Text = L"Граф";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void depthButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void breadthButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void dataButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
