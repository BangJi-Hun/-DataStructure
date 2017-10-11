#pragma once
#include <iostream>
using namespace std;

class Sets
{
private:
	int* par;
	int num;
public:
	Sets(void);
	Sets(int numberOfElements);
	~Sets(void);

	void WeightedUnion(int i,int j);
	int CollapsingFind(int i); 
	int getNumber(){return num;}
};

