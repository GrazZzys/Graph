#include "MyForm.h"


using namespace Graph;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MyForm());
    return 0;
}

System::Void Graph::MyForm::dataButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    comboBox1->Items->Clear();
    comboBox2->Items->Clear();
    out_path->Text = "Путь до вершины";
    out_work->Text = "Работа программы";

    int rows_count = dataGridView1->Rows->Count - 1;

    //array<String^, 2>^ data = gcnew array<String^, 2>(rows_count, 2);
    String^ str = "";
    for (int i = 0; i < rows_count; i++)
    {   
        String^ start;
        String^ finish;
        
        if (dataGridView1->Rows[i]->Cells[0]->Value == nullptr && dataGridView1->Rows[i]->Cells[1]->Value != nullptr)
        {
            MessageBox::Show("Данные введены некорректно");
            return System::Void();
        }
        else if (dataGridView1->Rows[i]->Cells[0]->Value == nullptr && dataGridView1->Rows[i]->Cells[1]->Value == nullptr)
        {
            dataGridView1->Rows->RemoveAt(i);
            rows_count = dataGridView1->Rows->Count - 1;
            if (i == rows_count)
                break;
            else
            {
                i--;
                continue;
            }
            
        }

        start = dataGridView1->Rows[i]->Cells[0]->Value->ToString();
        if(dataGridView1->Rows[i]->Cells[1]->Value != nullptr)
            finish = dataGridView1->Rows[i]->Cells[1]->Value->ToString();
        else
            finish = "";
        str += start + ":" + finish + "|";
    }

    if (rows_count == 0)
    {
        MessageBox::Show("Заполните список смежности и подтвердите граф");
        return System::Void();
    }

    str = str->Substring(0, str->Length - 1);
    array<String^>^ str2 = str->Split('|');
    array<String^>^ str3;
    array<Vertex^>^ vertex_array = gcnew array<Vertex^>(str2->Length);

    for (int i = 0; i < vertex_array->Length; i++)
    {
        str3 = str2[i]->Split(':');
        String^ number = str3[0];
        array<String^>^ edge_with = str3[1]->Split(',');
        Vertex^ myVertex = gcnew Vertex(number, edge_with);
        vertex_array[i] = myVertex;
        
        comboBox1->Items->Add(number);
        comboBox2->Items->Add(number);
    }

    myGraph = gcnew MyGraph(vertex_array);

    return System::Void();
}


System::Void Graph::MyForm::depthButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ startStr = comboBox1->Text;
    String^ finishStr = comboBox2->Text;
    int startInt = 0;
    int finishIn = 0;

    if (myGraph == nullptr)
    {
        MessageBox::Show("Заполните список смежности и подтвердите граф");
        return System::Void();
    }

    if (startStr == "")
    {
        MessageBox::Show("Введите начальную вершину");
        return System::Void();
    }
    if (finishStr == "")
    {
        MessageBox::Show("Введите конечную вершину");
        return System::Void();
    }
    if (!comboBox1->Items->Contains(startStr))
    {
        MessageBox::Show("Выберите начальную вершину из предложенных");
        return System::Void();
    }
    if (!comboBox1->Items->Contains(finishStr))
    {
        MessageBox::Show("Выберите конечную вершину из предложенных");
        return System::Void();
    }

    for (int i = 0; i < myGraph->Vertexs->Length; i++)
    {
        if (myGraph->Vertexs[i]->Number == startStr)
            startInt = i;
        if (myGraph->Vertexs[i]->Number == finishStr)
            finishIn = i;
    }

    myGraph->dfs(startInt, finishIn);
    myGraph->drowOut(out_path, out_work);

    return System::Void();
}

System::Void Graph::MyForm::breadthButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ startStr = comboBox1->Text;
    String^ finishStr = comboBox2->Text;
    int startInt = 0;
    int finishInt = 0;

    if (myGraph == nullptr)
    {
        MessageBox::Show("Заполните список смежности и подтвердите граф");
        return System::Void();
    }

    if (startStr == "")
    {
        MessageBox::Show("Введите начальную вершину");
        return System::Void();
    }
    if (finishStr == "")
    {
        MessageBox::Show("Введите конечную вершину");
        return System::Void();
    }
    if (!comboBox1->Items->Contains(startStr))
    {
        MessageBox::Show("Выберите начальную вершину из предложенных");
        return System::Void();
    }
    if (!comboBox1->Items->Contains(finishStr))
    {
        MessageBox::Show("Выберите конечную вершину из предложенных");
        return System::Void();
    }

    if (myGraph->Vertexs[0]->Number != startStr)
        for (int i = 0; i < myGraph->Vertexs->Length; i++)
        {
            if (myGraph->Vertexs[i]->Number == startStr)
                myGraph->swap(i);
        }
        

    for (int i = 0; i < myGraph->Vertexs->Length; i++)
    {
        if (myGraph->Vertexs[i]->Number == startStr)
            startInt = i;
        if (myGraph->Vertexs[i]->Number == finishStr)
            finishInt = i;
    }

    myGraph->bfs(startInt, finishInt);
    myGraph->drowOut(out_path, out_work);

    return System::Void();
}


