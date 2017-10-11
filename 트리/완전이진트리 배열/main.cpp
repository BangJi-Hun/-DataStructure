#include <iostream>
using namespace std;

#include "Tree.h"

int main()
{
	int nodeCnt;
	int root = 1;

	cout << "��� ���� �Է� : ";
	cin >> nodeCnt;

	Tree<int> t(nodeCnt);
	t.makeTree(root,nodeCnt);
	cout << "preorder : ";
	t.preOrder(root,nodeCnt);
	cout << endl << "inorder : ";
	t.inOrder(root,nodeCnt);
	cout << endl << "postOrder : ";
	t.postOrder(root,nodeCnt);
	cout << endl << "level : ";
	t.level(nodeCnt);
	cout << endl;
}