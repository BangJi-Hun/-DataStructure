#include <iostream>
using namespace std;

#include "Tree.h"

int main()
{
	int nodeCount = 0;
	Tree<int> t;

	cout << "����� ������ �Է��Ͻÿ� : ";
	cin >> nodeCount;

	t.makeTree(nodeCount);
	t.show();

	cout << endl;

	cout << "preorder : ";
	t.showPreorder(); cout << endl;

	cout << "inorder : ";
	t.showInorder(); cout << endl;

	cout << "postorder : ";
	t.showPostorder(); cout << endl;

	cout << "levelorder : ";
	t.showLevelorder(); cout << endl;
}