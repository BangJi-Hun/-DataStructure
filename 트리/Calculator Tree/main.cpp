#include <iostream>
#include <string>

#include "Stack.h"
#include "Converter.h"
#include "TokenList.h"
#include "Tree.h"

using namespace std;

int main()
{
	string inputStr;
	Converter c;

	while(true)
	{
		Tree<Token> t;
		TokenList tl;
		int flag = 0;

		cout << endl;
		cout << "������ �Է��Ͻÿ� (����� quit): ";

		getline(cin,inputStr);
		if(inputStr == "quit")
		{
			cout << "���α׷� �����մϴ�" << endl;
			exit(1);
		}

		tl.insertToken(inputStr,flag);

		if(flag != 0)
		{
			continue;
		}

		c.expressionConvert(tl);  
		t.makeTree(tl);
	}
}