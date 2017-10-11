#include <iostream>
using namespace std;

#include "Tree.h"

int main()
{
	int nodeCount = 0;
	Tree<int> t;

	cout << "노드의 개수를 입력하시오 : ";
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