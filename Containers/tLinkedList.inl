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
inline int LinkedList<T>::at(T index)
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


