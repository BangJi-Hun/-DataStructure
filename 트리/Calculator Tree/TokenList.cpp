#include "TokenList.h"

TokenList::TokenList(void)
{
	tokeList = new Token[100];
	count = 0;
	cnt = 0;
}


TokenList::~TokenList(void)
{
}
void TokenList::exception(int& flag)
{
	int leftCount = 0;
	int rightCount = 0;

	for(int i=0 ; i < count ; i++)
	{
		char anNumber = tokeList[i].getOperator();
		int number = tokeList[i].getNumber();
		if(number == 0)
		{
			if(tokeList[i-1].getOperator() == '%' || tokeList[i-1].getOperator() == '/')
			{
				cout<< "나누기 연산자 뒤 0 불가 "<< endl;
				flag++;
				return;
			}
		}

		if((!tokeList[count-1].getIsOper()) && !(tokeList[count-1].getOperator() == ')'))
		{
			cout << "연산자가 마지막 불가" << endl;
			flag++;
			return;
		}

		if(anNumber == '(')
		{
			leftCount++;
		}

		else if(anNumber == ')')
		{
			rightCount++;
		}

		if(anNumber == '^' || anNumber == '*' || anNumber == '/' || anNumber == '%' || anNumber == '+' || anNumber == ')')
		{
			if(tokeList[i-1].getOperator() == '^' || tokeList[i-1].getOperator()  == '*' || tokeList[i-1].getOperator()  == '/' || tokeList[i-1].getOperator() == '%' || tokeList[i-1].getOperator()  == '+' || tokeList[i-1].getOperator()  == '-' || tokeList[i-1].getOperator()  == '(')
			{
				cout<< "연속된 연산자 불가" << endl;
				flag++;
				return;
			}
		}
	}

	if(!(leftCount == rightCount))
	{
		cout << "괄호 올바르게 입력" << endl;
		flag++;
		
		return;
	}

	else
	{
		return;
	}

}
bool TokenList::isOperand(char value)
{
	if(value == '^' || value == '*' || value == '/' || value == '%' || value == '+' || value == '-' || value == '(' || value == ')')
	{
		return true;
	}
	else
		return false;
}

void TokenList::insertToken(string expression,int& flag)
{
	int rightCount = 0;
	int leftCount = 0;
	for(int i = 0 ; i < expression.length() ; i++)
	{
		if(expression[0] == '^'||expression[0] == '*'||expression[0] == '/'||expression[0] == '%'||expression[0] == '+'||expression[0] == ')')
		{
			cout << "단항연산자를 제외한 연산자 맨 앞 불가"<< endl;
			flag++;
			return;
		}
		else if(expression[i] ==' '){}

		else if(!isOperand(expression[i]))
		{
			if((expression[i] >=65 && expression[i] <= 92) || (expression[i] >=97 && expression[i] <= 122)) 
			{
				cout << "알파벳 불가 " << endl;
				flag++;
				return;
			}
			int result = 0;
			do
			{
				result = result * 10 + expression[i] - '0';
				i++;
				if(!(expression[i] <= '9' && expression[i] >= '0'))
				{
					Token t(result);
					tokeList[count++] = t;
					i--;
					break;
				}
			}while(!isOperand(expression[i]));

		}

		else if(isOperand(expression[i]))                    
		{
			if(expression[i] == '(')
			{
				if(expression[0] == '('){}
				else if(!isOperand(expression[i-1]))
				{
					cout << "연산식 오류" << endl;
					flag++;
					return;
				}
			}
			Token t(expression[i]);
			tokeList[count++] = t;
		}
	}
	exception(flag);
}

ostream& operator <<(ostream& os, TokenList& tl)
{
	for(int i = 0 ; i < tl.getCnt() ; i++)
	{
		if(tl.getTokeList(i).getOperator() == ' ')
			cout << tl.getTokeList(i).getNumber() << " ";
		else
			cout << tl.getTokeList(i).getOperator() << " ";
	}
	cout << endl;
	return os;
}

void TokenList::setOperand(int number)
{
	tokeList[cnt++] = number;
}

void TokenList::setOperator(char anNumber)
{
	tokeList[cnt++] = anNumber;
}