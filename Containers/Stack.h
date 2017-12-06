#pragma once
#include "tvector.h"
#include "intLinkedList.h"

template<typename T>
class Stack
{
public:
	Stack(size_t cap);
	~Stack();

	

	bool empty();

	int size();

	void push(T val);

	void pop();

	T top();
	

private:
	tVector<T> vector;
};

template<typename T>
class Queue
{
public:
	Queue();
	~Queue();



private:
	intLinkedList list;
};

template<typename T>
inline Stack<T>::Stack(size_t cap)
{
	vector.Capacity = cap;
	vector[size - 1] = -1;
}

template<typename T>
inline Stack<T>::~Stack()
{
	vector.~tVector();
}

template<typename T>
inline bool Stack<T>::empty()
{
	return vector.empty();
}

template<typename T>
inline int Stack<T>::size()
{
	return vector.getSize();
}

template<typename T>
inline void Stack<T>::push(T val)
{
	vector.append(val);
}

template<typename T>
inline void Stack<T>::pop()
{
	vector.pop();
}

template<typename T>
inline T Stack<T>::top()
{
	return vector[size-1];
}
//===========================================================================







template<typename T>
inline Queue<T>::Queue()
{

}

template<typename T>
inline Queue<T>::~Queue()
{
}
