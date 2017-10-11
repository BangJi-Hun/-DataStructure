#pragma once
using namespace std;

template <class T>
class Queue
{
public:
	Queue( int queueCapacity = 10 );
	~Queue();

	bool isEmpty() const { return front == rear; }
	T& Front() const;
	T& Rear() const;
	void push( const T& item );
	void pop();

private:
	T* queue;
	int front;
	int rear;
	int capacity;
};

template<class T>
Queue<T>::Queue(int queueCapacity) : capacity(queueCapacity)
{
	if( capacity < 1 )
	{
		capacity = 10;
		throw "Queue capacity must be > 0, and capacity set 10";
	}

	queue = new T[capacity];
	front = 0;
	rear = 0;
}

template<class T>
Queue<T>::~Queue(void)
{
	if( !queue )
	{
		delete []queue;
	}
}

template<class T>
T& Queue<T>::Front() const
{
	if( isEmpty() ) throw "Queue is empty. No front element";
	return queue[ (front+1) % capacity ];
}

template<class T>
T& Queue<T>::Rear() const
{
	if( isEmpty() ) throw "Queue is empty. No rear element";
	return queue[rear];
}

template<class T>
void Queue<T>::push(const T& x)
{
	if( (rear + 1) % capacity == front )
	{
		T* newQueue = new T[2 * capacity];

		int start = ( front + 1 ) % capacity;

		if( start < 2 )
			copy( queue + start, queue + start + capacity - 1, newQueue );

		else
		{
			copy( queue + start, queue + capacity, newQueue );
			copy( queue, queue + rear + 1, newQueue + capacity - start );
		}

		front = 2 * capacity - 1;
		rear = capacity - 2;
		capacity *= 2;
		delete []queue;
		queue = newQueue;
	}

	rear = ( rear + 1 ) % capacity;
	queue[rear]= x;
}

template<class T>
void Queue<T>::pop()
{
	if( isEmpty() ) throw "Queue is empty. Cannot delete.";
	front = ( front + 1 ) % capacity;
}
