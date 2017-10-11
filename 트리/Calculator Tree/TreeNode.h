#pragma once

template <class T> class Tree;

template <class T>
class TreeNode
{
	friend class Tree<T>;
private:
	T data;
	TreeNode<T>* leftChild;
	TreeNode<T>* rightChild;
public:
	TreeNode(void){}
	TreeNode(T data){this->data = data; leftChild = nullptr; rightChild = nullptr;}
	~TreeNode(void){}
	
};