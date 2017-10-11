#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Node.h"
#include "Stack.h"
#include "Queue.h"

class Graph
{
private:
	int** MatrixList;
	Node* adList[100];
	int count;
	bool isCheck[10];
	int flag[10];
	Stack<int> s;
	Queue<int> q;
public:
	Graph();
	~Graph(void);

	void loadFile(string msg);
	void insertMatrix(int x,int y);
	void makeMatrix();
	void makeAdList();
	void showMatrix();
	void showAdList();

	void showAdMatrixDFS(int x);
	void showAdListDFS(int x);
	void showAdMatrixBFS(int x);
	void showAdListBFS(int x);
	void print();
};

