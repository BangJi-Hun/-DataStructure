#pragma once
#include "TreeNode.h"
#include "Queue.h"

template <class T>
class BsTree
{
private:
	TreeNode<T>* root;
	int count;
public:
	BsTree(string name){root = new TreeNode<T>(name) , count = 0;}
	~BsTree(void){}

	void insertName(TreeNode<T>* current,string name);
	void makeTree(string name){insertName(root,name);}
	void showTree(TreeNode<T>* current);
	void show(){showTree(root);}
};

template <class T>
void BsTree<T>::insertName(TreeNode<T>* current,string name)
{
	if(current->name.compare(name) < 0) {
		if(current->rightChild == nullptr || current->rightChild->name == "0")
		{
			TreeNode<T>* newNode = new TreeNode<T>(name);
			current->rightChild = newNode;
			if(current->leftChild == nullptr)
				current->leftChild = new TreeNode<T>("0");
		}
		else
		{
			insertName(current->rightChild,name);
		}
	}
	else if(current->name.compare(name) > 0)	{ 
		if(current->leftChild == nullptr || current->leftChild->name == "0")
		{
			TreeNode<T>* newNode = new TreeNode<T>(name);
			current->leftChild = newNode;
			if(current->rightChild == nullptr)
				current->rightChild = new TreeNode<T>("0");
		}
		else
		{
			insertName(current->leftChild,name);
		}
	}

}

template <class T>
void BsTree<T>::showTree(TreeNode<T>* current)
{
	cout<<"---"<< current->name <<" ";

	if(current->leftChild != 0)
	{
		count++;
		showTree(current->leftChild);
		cout<<endl;
		count--;
	}
	if(current->rightChild != 0)
	{
		for(int i = 0 ;i <= count; i++)
			cout<<"          ";
		count++;
		showTree(current->rightChild);
		count--;
   	}
}