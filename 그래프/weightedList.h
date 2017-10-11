#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "weightNode.h"
#include "Sets.h"

class weightedList
{
private:
	weightNode* sortList;
	int count;
	int vertaxCount;
public:
	weightedList(void);
	~weightedList(void);

	void insertList(int ver1,int ver2,int w);
	void sort();

	void loadFile(string msg,Sets*& s);
	void deleteSortList(int x);
	void selectEdge(Sets* s);
	void print();
};

