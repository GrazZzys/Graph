#include "Vertex.h"

Vertex::Vertex(String^ number, array<String^>^ edge_with)
{
	this->edge_with = gcnew array<String^>(edge_with->Length);

	this->number = number;
	this->edge_with = edge_with;
	this->used = '0';
}
