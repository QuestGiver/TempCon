#pragma once
class intLinkedList
{
public:
	intLinkedList();
	~intLinkedList();

	struct intLinkedListNode
	{
		int value;
		intLinkedListNode * next;
	};

	void clear();
	
	void append(int value);

	int at(int index);

	int getSize();

	bool empty();
	
	int front();

	int back();

	void pop();

	int count(int val);

	//int & operator[](size_t index) const;

	void Erase(int index);

	void insert(int index,int val);

private:
	intLinkedListNode* head;

};











template<typename T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	struct LinkedListNode
	{
		T value;
		LinkedListNode * next;
	};

	void append(T value);

	int at(T index);




private:
	LinkedListNode* head;

};

#include "tLinkedList.inl"
