#include <iostream>
#include <string>
#include "BsTree.h"

using namespace std;

int main()
{
	while(1)
	{
		string inputStr;
		cout << "문자열들을 입력하세요 : (마지막은 0)";
		cin >> inputStr;
		BsTree<string> bst(inputStr);
		if(inputStr == "0")
		{
			cout << "종료합니다. " << endl;
			break;
		}
		while(1)
		{
			cin >> inputStr;
			if(inputStr == "0")
				break;
			bst.makeTree(inputStr);
		}
		bst.show();
		cout << endl;
	}
	return 0;
}
