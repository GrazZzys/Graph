 #pragma once

#include "Vertex.h"

using namespace System;
using namespace System::Collections::Generic;

ref class MyGraph
{
private:
	array<Vertex^>^ vertexs;
	String^ path;
	String^ work;
	char path_found; //'0' - path not found. '1' - depth - first search. '2' - Breadth First Search
	void reload();

public:
	MyGraph(array<Vertex^>^ vertexs);

	property array<Vertex^>^ Vertexs
	{
		array<Vertex^>^ get()
		{
			return this->vertexs;
		}
		void set(array<Vertex^>^ vertexs)
		{
			this->vertexs = vertexs;
		}
	}
	void swap(int index);
	void drowOutPath(System::Windows::Forms::TextBox^ out_path);
	void drowOutwork(System::Windows::Forms::TextBox^ out_work);
	void drowOut(System::Windows::Forms::TextBox^ out_path, System::Windows::Forms::TextBox^ out_work);
	void dfs(int v, int finish);
	void bfs(int v, int finish);
};

