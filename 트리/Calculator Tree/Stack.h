#pragma once
#include <iostream>
using namespace std;
template <class T>
class Stack
{
private:
	int capacity;
	T * stack;
	int top;
public:
	Stack(int stackCapacity = 20);
	~Stack(void);

	void ChangeSizeID();
	bool IsEmpty()const;
	T& Top()const;
	void push(const T& x);
	void pop();

	int getTop(){return top;}
};

