#pragma once
#include <iostream>
using namespace std;

template <class T>
class Tree
{
private:
	T* arr;
	int count;
public:
	Tree(T nodeCnt)
	{
		arr = new int[100];
		for(int i = 1 ; i <= nodeCnt ; i ++ )
		{
			arr[i] = i;
		}
		count = 0;
	}
	~Tree(void){}

	int makeTree(int curr,int nodeCnt);

	int preOrder(int curr,int nodeCnt);
	int inOrder(int curr,int nodeCnt);
	int postOrder(int curr,int nodeCnt);
	void level(int nodeCnt);
};


template <class T>
int Tree<T>::makeTree(int curr,int nodeCnt)
{
	if(curr > nodeCnt)
	{
		cout << endl;
		return 0;
	}

	if(curr == 1)
	{
		cout << curr;
	}

	else
	{
		cout << "---" << curr;
	}

	count++;
	makeTree(2*curr,nodeCnt);

	cout << " ";

	for(int i = 0 ; i < count-1 ; i++)
	{
		cout << "    " ;
	}

	makeTree(2*curr+1,nodeCnt);
	count--;
}

template <class T>
int Tree<T>::preOrder(int curr,int nodeCnt)
{
	if(curr > nodeCnt)
	{
		return 0;
	}

	cout << arr[curr] << " " ;
	preOrder(2*curr,nodeCnt);
	preOrder(2*curr+1,nodeCnt);
}

template <class T>
int Tree<T>::inOrder(int curr,int nodeCnt)
{
	if(curr > nodeCnt)
		return 0;
	inOrder(2*curr,nodeCnt);
	cout << arr[curr] << " " ;
	inOrder(2*curr+1,nodeCnt);
}

template <class T>
int Tree<T>::postOrder(int curr,int nodeCnt)
{
	if(curr > nodeCnt)
	{
		return 0;
	}

	postOrder(2*curr,nodeCnt);
	postOrder(2*curr+1,nodeCnt);
	cout << arr[curr] << " " ;
}

template <class T>
void Tree<T>::level(int nodeCnt)
{
	for(int i = 1 ; i <= nodeCnt ; i++)
	{
		cout << arr[i] << " ";
	}
}