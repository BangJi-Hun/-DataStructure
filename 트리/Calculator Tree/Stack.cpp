#include "Stack.h"

template<class T>
Stack<T>::Stack(int stackCapacity) : capacity(stackCapacity)
{
	if(capacity<1)
	{
		throw "Stack capacity must be > 0 ";
	}
	stack = new T[capacity];
	top = -1;
}

template<class T>
Stack<T>::~Stack(void)
{
	delete[] stack;
}

template<class T>
void Stack<T>::ChangeSizeID()
{
	int newSize = capacity * 2;
	T * temp = new T[newSize];
	for(int i = 0; i < capacity ; i++)
	{
		temp[i] = stack[i];
	}
	delete[] stack;
	stack = temp ;
	capacity = newSize;
}
template<class T>
bool Stack<T>::IsEmpty()const
{
	return top == -1;
}

template<class T>
T& Stack<T>::Top()const
{
	if(IsEmpty())
		throw "Stack is Empty";
	return stack[top];
}

template<class T>
void Stack<T>::push(const T& x)
{
	if(top==capacity-1)
	{
		ChangeSizeID();
	}
	stack[++top] = x;
}

template<class T>
void Stack<T>::pop()
{
	if(IsEmpty())
		throw "Stack is empty. Cannot delete.";
	stack[top--].~T();
}