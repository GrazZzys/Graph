#include "MyGraph.h"

void MyGraph::reload()
{
	for (int i = 0; i < this->vertexs->Length; i++)
	{
		vertexs[i]->Used = '0';
	}
	path = "";
	work = "";
	this->path_found = '0';
}

MyGraph::MyGraph(array<Vertex^>^ vertexs)
{
	this->vertexs = gcnew array<Vertex^>(vertexs->Length);
	this->vertexs = vertexs;

	this->path_found = '0';

	this->path = "";
	this->work = "";
}

void MyGraph::swap(int index)
{
	Vertex^ vert_tmp = this->vertexs[index];
	this->vertexs[index] = this->vertexs[0];
	this->vertexs[0] = vert_tmp;
}

void MyGraph::drowOutPath(System::Windows::Forms::TextBox^ out_path)
{
	if (this->path_found == '1')
		out_path->Text = "Путь, найденный поиском в глубину: " + this->path;
	else if (this->path_found == '2')
		out_path->Text = "Путь, найденный поиском в ширину: " + this->path;
	else if (this->path_found == '0')
		out_path->Text = "Путь до вершины не найден";
}

void MyGraph::drowOutwork(System::Windows::Forms::TextBox^ out_work)
{
	if (this->path_found == '1')
		out_work->Text = "Работа, проделанная поиском в глубину: " + this->work;
	else if (this->path_found == '2')
		out_work->Text = "Работа, проделанная поиском в ширину: " + this->work;
	if (this->path_found == '0') 
	{
		this->work = this->work->Substring(0, work->Length - 2);
		out_work->Text = "Проделанная работа: " + this->work;
	}
		
}

void MyGraph::drowOut(System::Windows::Forms::TextBox^ out_path, System::Windows::Forms::TextBox^ out_work)
{
	this->drowOutPath(out_path);
	this->drowOutwork(out_work);
	this->reload();
}

void MyGraph::dfs(int v, int finish)
{
	vertexs[v]->Used = '1';

//	if (this->path_found != '1')
//	{
		this->path += vertexs[v]->Number + "->";
		this->work += vertexs[v]->Number + "->";		
//	}

	if (vertexs[v]->Number != vertexs[finish]->Number)
		for (int i = 0; i < vertexs[v]->Edge_with->Length; i++)
		{
			for (int j = 0; j < vertexs->Length; j++)
			{
				if ((vertexs[v]->Edge_with[i] == vertexs[j]->Number) && (vertexs[j]->Used == '0')) 
				{
					dfs(j, finish);
					if (this->path_found != '1')
					{
						this->work = this->work->Substring(0, work->Length - 2);
						this->work += "<-" + vertexs[v]->Number + "->";
					}
					else
						return;

				}
					
			}
		}
	else
	{
		this->path = this->path->Substring(0, path->Length - 2);
		this->work = this->work->Substring(0, work->Length - 2);
		this->path_found = '1';
		return;
	}
		
//	if (this->path_found != '1')
//	{
		this->path = this->path->Substring(0, path->Length - 3);
//	}

		//this->path = this->path->Substring(0, path->Length - 2);
		//return;
	//}
	//this->path = this->path->Substring(0, path->Length - 3);
}

void MyGraph::bfs(int v, int finish)
{
	array<int>^ prev = gcnew array<int>(vertexs->Length);
	Queue<int>^ queue = gcnew Queue<int>();
	vertexs[v]->Used = '1';
	queue->Enqueue(v);

	prev[0] = -1;

	while (queue->Count != 0)
	{
		int index = queue->Dequeue();

		this->work += vertexs[index]->Number + "->";

		if (vertexs[index]->Number != vertexs[finish]->Number)
		{
			for (int i = 0; i < vertexs[index]->Edge_with->Length; i++)
			{
				for (int j = 0; j < vertexs->Length; j++)
				{
					if (vertexs[index]->Edge_with[i] == vertexs[j]->Number && vertexs[j]->Used == '0')
					{
						queue->Enqueue(j);
						vertexs[j]->Used = '1';
						prev[j] = index;
					}
				}
			}
		}
		else
		{
			this->work = this->work->Substring(0, work->Length - 2);
			this->path_found = '2';
			break;
		}
	}

	if (this->path_found == '2')
	{
		Stack<int>^ tmp = gcnew Stack<int>();
		//array<int>^ tmp = gcnew array<int>(0);
		int cur = finish;
		tmp->Push(cur);
		while (prev[cur] != -1)
		{
			cur = prev[cur];
			tmp->Push(cur);
			//this->path += vertexs[]->Number + "->";
		}

		while (tmp->Count)
		{
			this->path += vertexs[tmp->Peek()]->Number + "->";
			tmp->Pop();
		}
		this->path = this->path->Substring(0, path->Length - 2);
	}

}
