#pragma once
#include <iostream>

#include "Stack.cpp"
#include "TokenList.h"

using namespace std;

class Converter
{
private:
	char* arr;
	static const int TILDE = 0;
	static const int BRACKET = 4;
	static const int SQUARE = 1;
	static const int MULT = 2;
	static const int DIVIDE = 2;
	static const int MOD = 2;
	static const int ADD = 3;
	static const int MINUS = 3;
	int priority(char value);
public:
	Converter(void);
	~Converter(void);

	void expressionConvert(TokenList& tl);
	void taewon(int index);
};

