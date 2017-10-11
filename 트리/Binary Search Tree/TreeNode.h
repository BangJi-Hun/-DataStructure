#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T> class BsTree;

template <class T>
class TreeNode
{
private:
	T name;
	TreeNode<T>* leftChild;
	TreeNode<T>* rightChild;
public:
	friend class BsTree<T>;
	TreeNode(void){}
	TreeNode(T theName){name = theName;leftChild = nullptr; rightChild = nullptr;}
	~TreeNode(void){}
};

