#include <iostream>
#include <string>
#include "BsTree.h"

using namespace std;

int main()
{
	while(1)
	{
		string inputStr;
		cout << "���ڿ����� �Է��ϼ��� : (�������� 0)";
		cin >> inputStr;
		BsTree<string> bst(inputStr);
		if(inputStr == "0")
		{
			cout << "�����մϴ�. " << endl;
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
