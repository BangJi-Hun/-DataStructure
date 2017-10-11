#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "Token.h"
class TokenList
{
private:
	Token* tokeList;
	int count; 
	int cnt; 
public:
	TokenList(void);
	~TokenList(void);

	bool isOperand(char value);
	void insertToken(string expression,int& flag);

	int getCount(){return count;}
	int getCnt(){return cnt;}
	Token getTokeList(int index){return tokeList[index];}

	friend ostream& operator << (ostream& os, TokenList& tl);
	void exception(int& flag);
	void setOperand(int num);
	void setOperator(char anNum);
};
