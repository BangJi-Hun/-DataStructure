#pragma once

class Matrix;

class Node
{
private:
	int data; 
	Node* rowsLink;
public:
	friend class Graph;
	Node(){data = 0, rowsLink = nullptr;}
	Node(int data){ this->data = data , rowsLink = nullptr;}
	~Node(void){}

};

