#pragma once
#include "Stack.h"
#include "Converter.h"
#include "TokenList.h"
#include "TreeNode.h"
#include <iomanip>

template <class T>

class Tree
{
private:
	float Operator(TreeNode<Token>* current);
	Stack<TreeNode<T>*> data;
	int count;
	
public:
	Tree(void){count = 0;}
	~Tree(void){}

	void showTree(TreeNode<Token>* current);
	void makeTree(TokenList tl);
	void calculate(TreeNode<Token>* current);
};

template <class T>
float Tree<T>::Operator(TreeNode<Token>* current)          
{
	float result = 1;
	switch(current->data.getOperator())
	{
	case '~':
		return current->data.getNumber();
	case '^':
		for(int i = 0 ; i < current->rightChild->data.getNumber() ; i++)
		{
			result = result * current->leftChild->data.getNumber();
		}
		return result;
	case '*':
		result = current->leftChild->data.getNumber() * current->rightChild->data.getNumber();
		return result;
	case '/':
		result = current->leftChild->data.getNumber() / current->rightChild->data.getNumber();
		return result;
	case '%':
		result = (int)current->leftChild->data.getNumber() % (int)current->rightChild->data.getNumber();
		return result;
	case '+':
		result = current->leftChild->data.getNumber() + current->rightChild->data.getNumber();
		return result;
	case '-':
		result = current->leftChild->data.getNumber() - current->rightChild->data.getNumber();
		return result;
	}
}

template <class T>
void Tree<T>::showTree(TreeNode<Token>* current)
{
	if(current->data.getIsOper() == true)
	{
		cout << setw(1) <<"---"<< current->data.getNumber() <<" " << setw(1);
	}
	else if(current->data.getIsOper() == false)
	{
		if(current->data.getOperator() == '~')
			cout << setw(1) << "---" << "(" << current->data.getOperator() << ")" << " " << setw(1);
		else
			cout << setw(1) <<"---"<< "(" << current->data.getOperator() << ")" << current->data.getNumber() <<" " << setw(1);
	}
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
			cout<<"         ";
		count++;
		showTree(current->rightChild);
		count--;
   }
}

template <class T>
void Tree<T>::makeTree(TokenList tl)
{
	for(int i = 0 ; i < tl.getCnt() ; i++)
	{
		if(tl.getTokeList(i).getIsOper())            
		{
			TreeNode<Token>* newNode = new TreeNode<Token>(tl.getTokeList(i));
			data.push(newNode);
		}
		else
		{
			TreeNode<Token>* newNode = new TreeNode<Token>(tl.getTokeList(i));
			if(newNode->data.getOperator() == '~')
			{
				newNode -> leftChild = data.Top();
				data.pop();
				newNode->data.setNumber(-(newNode->leftChild->data.getNumber()));
				data.push(newNode);
			}
			else
			{
				newNode->rightChild = data.Top();
				data.pop();
				newNode->leftChild = data.Top();
				data.pop();
				data.push(newNode);
			}
		}
	}
	TreeNode<Token>* root;
	root = data.Top();
	calculate(root);
	showTree(root);
	cout << endl << "°á°ú : " << root->data.getNumber() << endl;
}

template <class T>
void Tree<T>::calculate(TreeNode<Token>* current)
{
	float result = 0;
	if(current->leftChild != nullptr)
	{
		calculate(current->leftChild);
	}
	if(current->rightChild != nullptr)
	{
		calculate(current->rightChild);
	}
	if(current->data.getIsOper() == false)
	{
		current->data.setNumber(Operator(current));
	}
}