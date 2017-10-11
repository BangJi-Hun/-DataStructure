#pragma once


template <class T> class Tree;

template <class T>
class TreeNode
{
private:
	T data;
	TreeNode<T>* rightNode;
	TreeNode<T>* leftNode;
public:
	friend class Tree<T>;
	TreeNode(T nodeNumber)
	{
		data = nodeNumber;
		rightNode = nullptr;
		leftNode = nullptr;
	}
	~TreeNode(void){}
};

