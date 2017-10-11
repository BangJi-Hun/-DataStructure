#pragma once
#include "Queue.h"
#include "TreeNode.h"

template <class T>
class Tree
{
private:
	TreeNode<T>* root;
	int count;
public:
	Tree(void){root = new TreeNode<T>(1),count = 0;}
	~Tree(void){}

	void makeTree(int nodeCount);
	void showTree(TreeNode<T>* curr);
	void show(){showTree(root);}

	void preorder(TreeNode<T>* curr);
	void showPreorder(){preorder(root);}

	void inorder(TreeNode<T>* curr);
	void showInorder(){inorder(root);}

	void postorder(TreeNode<T>* curr);
	void showPostorder(){postorder(root);}

	void levelorder(TreeNode<T>* curr);
	void showLevelorder(){levelorder(root);}
};


template <class T>
void Tree<T>::makeTree(int nodeCount)
{
	TreeNode<T>* currentNode = root;
	Queue<TreeNode<T>*> q;
	T data = 2;

	while(1)
	{
		if(data <= nodeCount)
		{
			currentNode->leftNode = new TreeNode<T>(data);
			q.push(currentNode->leftNode);
			data++;
		}

		if(data <= nodeCount)
		{
			currentNode->rightNode = new TreeNode<T>(data);
			q.push(currentNode->rightNode);
			data++;
		}

		if(data > nodeCount)
		{
			return;
		}

		currentNode = q.Front();
		q.pop();
	}
}

template <class T>
void Tree<T>::showTree(TreeNode<T>* current)
{
	if (current != NULL)
	{
		if (current->data== 1)
		{
			cout << current->data;
		}

		else 
		{
			cout << "---" << current->data;
		}

		count++;
		showTree(current->leftNode);
		cout << endl;
		cout << " ";

		for (int i = 0; i < count - 1; i++)
		{
			cout << "    ";
		}

		showTree(current->rightNode);
		count--;
	}
}

template <class T>
void Tree<T>::preorder(TreeNode<T>* curr)
{
	if(curr != nullptr)
	{
		cout << curr->data << " ";
		preorder(curr->leftNode);
		preorder(curr->rightNode);
	}
}

template <class T>
void Tree<T>::inorder(TreeNode<T>* curr)
{
	if(curr != nullptr)
	{
		inorder(curr->leftNode);
		cout << curr->data << " ";
		inorder(curr->rightNode);
	}
}

template <class T>
void Tree<T>::postorder(TreeNode<T>* curr)
{
	if(curr != nullptr)
	{
		postorder(curr->leftNode);
		postorder(curr->rightNode);
		cout << curr->data << " ";
	}
}

template <class T>
void Tree<T>::levelorder(TreeNode<T>* curr)
{
	Queue<TreeNode<T>*> q;
	while(1)
	{
		cout << curr->data << " ";
		if(curr->leftNode)
		{
			q.push(curr->leftNode);
		}
		if(curr->rightNode)
		{
			q.push(curr->rightNode);
		}
		if(q.isEmpty())
		{
			return;
		}
		curr = q.Front();
		q.pop();
	}
}