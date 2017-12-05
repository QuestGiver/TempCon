#include "intLinkedList.h"
#include <cassert>

intLinkedList::intLinkedList()
	: head(nullptr)
{


}

intLinkedList::~intLinkedList()
{
	intLinkedListNode* iter = head;
	while (iter != nullptr)
	{
		intLinkedListNode * next = iter->next;
		delete iter;
		iter = next;
	}
}

void intLinkedList::clear()
{
	intLinkedListNode* iter = head;
	while (iter != nullptr)
	{
		intLinkedListNode * next = iter->next;
		delete iter;
		iter = next;
	}
	head = nullptr;
	
}

void intLinkedList::append(int value)
{
	intLinkedListNode * newNode = new intLinkedListNode;
	newNode->value = value;
	newNode->next = nullptr;

	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		intLinkedListNode* iter = head;
		while (iter->next != nullptr)
		{
			iter = iter->next;
		}

		iter->next = newNode;


	}
}

int intLinkedList::at(int index)
{

	int idx = 0;
	intLinkedListNode* iter = head;
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

int intLinkedList::getSize()
{
	int idx = 0;
	intLinkedListNode* iter = head;
	while (iter->next != nullptr)
	{
		iter = iter->next;

		//if (idx == index)
		//{
		//	return iter->value;
		//}

		idx += 1;
	}
	return idx+1;
}

bool intLinkedList::empty()
{
	if (head == nullptr)
	{
		return true;
	}
	return false;
}

int intLinkedList::front()
{
	assert(!empty());
	return head->value;
}

int intLinkedList::back()
{
	assert(!empty());

	intLinkedListNode* iter = head;
	while (iter->next != nullptr)
	{
		iter = iter->next;
	}
	return iter->value;
}

void intLinkedList::pop()
{
	intLinkedListNode* iter = head;
	while (iter->next != nullptr)
	{
		iter = iter->next;
	}
	delete iter;
}

int intLinkedList::count(int val)
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

//int & intLinkedList::operator[](size_t index) const
//{
//
//	int idx = 0;
//	intLinkedListNode* iter = head;
//	while (iter->next != nullptr && idx != index)
//	{
//		iter = iter->next;
//
//		//if (idx == index)
//		//{
//		//	return iter->value;
//		//}
//
//		idx += 1;
//	}
//	assert(iter != nullptr, "Index value must be shorter than list length");
//	return iter->value;
//}

void intLinkedList::Erase(int index)
{

	assert(index < getSize());

	//assert(index < getSize());
	int idx = 0;
	intLinkedListNode* iter = head;
	intLinkedListNode* prev = head;
	while (iter->next != nullptr )
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

void intLinkedList::insert(int index, int val)
{
	assert(index <= getSize());

	/*
	intLinkedListNode* iter = head;
	intLinkedListNode* newItem = new intLinkedListNode;
	newItem->next = nullptr;
	intLinkedListNode* temp = head;
	newItem->value = val;
	int idx = 0;
	while (iter != nullptr)
	{
		if (idx == index - 1)
		{
			temp = iter;
		}

		if (idx == index)
		{
			temp->next = newItem;
			newItem->next = iter;
			//    iter->next->value = iter->value;
			//    iter->value = num;

		}
		idx++;
		iter = iter->next;

	*/

	intLinkedListNode* newItem = new intLinkedListNode;
	newItem->value = val;
	newItem->next = nullptr;

	int idx = 0;
	intLinkedListNode* iter = head;
	while (iter != nullptr && idx < index - 1)
	{
		iter = iter->next;
		idx++;
	}

	intLinkedListNode* next = iter->next;
	iter->next = newItem;
	newItem->next = next;

}

