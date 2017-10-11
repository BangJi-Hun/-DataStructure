#include "Converter.h"


Converter::Converter(void)
{
	arr = new char[100];
}
Converter::~Converter(void)
{
	delete[] arr;
}
int Converter::priority(char value)
{
	switch(value)
	{
	case '~':
		return TILDE;
	case '(':  
		return BRACKET;
	case '^':  
		return SQUARE;
	case '*':  
		return MULT;
	case '/':  
		return DIVIDE;
	case '%':
		return MOD;
	case '+':
		return ADD;
	case '-':
		return MINUS;
	}
}

void Converter::expressionConvert(TokenList& tl)
{
	Stack<char>stack;
	int count = 0;
	for(int i = 0 ; i < tl.getCount() ; i++)
	{
		if(tl.getTokeList(i).getOperator() == ' ') 
			tl.setOperand(tl.getTokeList(i).getNumber());
		else
		{
			if(tl.getTokeList(0).getOperator() == '-')
				stack.push('~');
			else if(stack.IsEmpty())
				stack.push(tl.getTokeList(i).getOperator());
			else
			{
				int p1 = priority(tl.getTokeList(i).getOperator());
				int p2 = priority(stack.Top());
				if(tl.getTokeList(i).getOperator() == '(')
					stack.push('(');
				else if(tl.getTokeList(i).getOperator() == ')')
				{
					while(stack.Top() != '(')
					{
						tl.setOperator(stack.Top());
						stack.pop();
					}
					stack.pop();
				}
				else if(tl.getTokeList(i).getOperator() == '^'|| tl.getTokeList(i).getOperator() == '*' || tl.getTokeList(i).getOperator() == '/' || tl.getTokeList(i).getOperator() == '%'|| tl.getTokeList(i).getOperator() == '+' ||tl.getTokeList(i).getOperator() == '-')
				{
					if(tl.getTokeList(i).getOperator() == '-')
					{
						if(tl.getTokeList(i-1).getOperator() == '^' ||tl.getTokeList(i-1).getOperator() == '*' ||tl.getTokeList(i-1).getOperator() == '/' ||tl.getTokeList(i-1).getOperator() == '%' ||tl.getTokeList(i-1).getOperator() == '+' ||tl.getTokeList(i-1).getOperator() == '-' ||tl.getTokeList(i-1).getOperator() == '~')
						{
							stack.push('~');
							continue;
						}
					}
					if(tl.getTokeList(i).getOperator() == '^')
					{
						if(stack.Top() == '^')
						{
							stack.push(tl.getTokeList(i).getOperator());
							continue;
						}
					}
					if(p1 < p2)
						stack.push(tl.getTokeList(i).getOperator());
					else if((p1 == priority(stack.Top()) ) || (p1 > priority(stack.Top()))) 
					{
						while(true)
						{
							if((stack.getTop() == -1) || (p1 < priority(stack.Top())))
								break;
							tl.setOperator(stack.Top());
							stack.pop();
						}
						stack.push(tl.getTokeList(i).getOperator());
					}
				}
			}
		}
	}
	while(stack.getTop() != -1 )
	{
		tl.setOperator(stack.Top());
		stack.pop();
	}
	cout << "후위연산식: "<< tl;
}
