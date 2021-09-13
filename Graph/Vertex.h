#pragma once

using namespace System;

ref class Vertex
{
private:
	String^ number;
	array<String^>^ edge_with;
	char used;
public:

	Vertex(String^ number, array<String^>^ edge_with);

	property String^ Number
	{
		String^ get()
		{
			return this->number;
		}
	}

	property array<String^>^ Edge_with
	{
		array<String^>^ get()
		{
			return this->edge_with;
		}
	}

	property char Used
	{
		char get()
		{
			return this->used;
		}
		void set(char c)
		{
			this->used = c;
		}
	}
};

