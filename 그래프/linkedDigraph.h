#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "graphNode.h"
#include "Stack.h"
using namespace std;

class linkedDigraph
{
private:
	graphNode* graphList[20];
	graphNode* currentNode;
	Stack<int> s;
	int count;
	bool* visited;
public:
	linkedDigraph();
	~linkedDigraph(void);

	void loadFile(string msg);
	void insertList(int vt,int vt2);
	void makeRoad();
};

