#pragma once
#include <iostream>
using namespace std;

typedef struct
{
	int num;
	char anNum;
}token;

class Token
{
private:
	token toke;
	bool isOper;
public:
	Token(){toke.num = 0; toke.anNum = ' ';}
	Token(int n){toke.num = n; toke.anNum = ' '; isOper=true; }
	Token(char an){toke.anNum = an; toke.num = 0; isOper= false;}
	~Token(){}

	int getNumber(){return toke.num;}
	char getOperator(){return toke.anNum;}
	bool getIsOper(){ return isOper; }

	void setNumber(int num){toke.num = num;}
};
