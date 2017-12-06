#include "intLinkedList.h"
#include <cassert>


template<typename T>
inline LinkedList<T>::LinkedList()
	:head(nullptr)
{

}

template<typename T>
inline LinkedList<T>::~LinkedList()
{
	LinkedListNode* iter = head;
	while (iter != nullptr)
	{
		intLinkedListNode * next = iter->next;
		delete iter;
		iter = next;
	}
}

template<typename T>
inline void LinkedList<T>::append(T value)
{
	LinkedListNode * newNode = new intLinkedListNode;
	newNode->value = value;
	newNode->next = nullptr;

	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		LinkedListNode* iter = head;
		while (iter->next != nullptr)
		{
			iter = iter->next;
		}

		iter->next = newNode;


	}
}

template<typename T>
inline int LinkedList<T>::at(int index)
{
	int idx = 0;
	LinkedListNode* iter = head;
	while (iter->next != nullptr && idx != index)
	{
		iter = iter->next;

		//if (idx == index)
		//{
		//	return iter->value;
		//}

		idx += 1;
	}
	assert(iter != nullptr, "Index value must be shorter than list length");
	return iter->value;
}

template<typename T>
inline int LinkedList<T>::getSize()
{
	int idx = 0;
	LinkedListNode* iter = head;
	while (iter->next != nullptr)
	{
		iter = iter->next;

		//if (idx == index)
		//{
		//	return iter->value;
		//}

		idx += 1;
	}
	return idx + 1;
}

template<typename T>
inline bool LinkedList<T>::empty()
{
	if (head == nullptr)
	{
		return true;
	}
	return false;
}

template<typename T>
inline int LinkedList<T>::front()
{
	assert(!empty());
	return head->value;
}

template<typename T>
inline int LinkedList<T>::back()
{
	assert(!empty());

	LinkedListNode* iter = head;
	while (iter->next != nullptr)
	{
		iter = iter->next;
	}
	return iter->value;
}

template<typename T>
inline void LinkedList<T>::pop()
{
	LinkedListNode* iter = head;
	while (iter->next != nullptr)
	{
		iter = iter->next;
	}
	delete iter;
}

template<typename T>
inline int LinkedList<T>::count(T val)
{
	int idx = 0;
	intLinkedListNode* iter = head;
	while (iter->next != nullptr)
	{


		//if (idx == index)
		//{
		//	return iter->value;
		//}
		if (val == iter->value)
		{
			idx += 1;
		}
		iter = iter->next;
	}
	return idx;
}

template<typename T>
inline void LinkedList<T>::Erase(int index)
{

	assert(index < getSize());

	//assert(index < getSize());
	int idx = 0;
	intLinkedListNode* iter = head;
	intLinkedListNode* prev = head;
	while (iter->next != nullptr)
	{
		if (idx == index - 1)
		{
			prev = iter;
		}
		if (idx == index) break;

		idx += 1;
		//prev = iter;
		iter = iter->next;
	}
	prev->next = iter->next;

	delete iter;

}

template<typename T>
inline void LinkedList<T>::insert(int index, int val)
{
}


