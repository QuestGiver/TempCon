#pragma once
#include<iostream>
#include<string>
#include<conio.h>
#include<assert.h>

class intVector
{
	int * data;//ptr to your dynamically allocated array
	size_t capacity;//total size (or rather, the total capacity)
	size_t size;//the total number of elements stored

public:

	intVector();

	~intVector();


	int& at(size_t idx) const;

	int& append(int val);

	int * c_ptr() const;

	size_t getCapacity() const;

	size_t getSize() const;

	bool empty() const;

	int front() const;

	int back() const;

	int & operator[](size_t idx) const;

	void clearDat();

	void Erase(size_t idx);

	int count(size_t idx) const;

	void insert(size_t idx, size_t val);

	void Reserve(size_t newCapacity);

	void Compact();

	void EraseRange(size_t idx_start, size_t idx_end);

private:

	bool grow(size_t minSize);






};



template<typename T>
T add(T a, T b)
{
	return a + b;
}

template<typename T>
T sub(T a, T b)
{
	return a - b;
}

template<typename T>
void print(T a)
{
	std::cout << a << std::endl;

}



template<typename T>
T min(T a, T b)
{
	return a < b ? b < a, a : b;
}

template<typename T>
T max(T a, T b)
{
	return a > b ? b > a, a : b;
}

//value/min/max
template<typename T>
T clamp(T a, T b, T c)
{
	return min(max(a, b), c);
}

//class Person
//{
//public:
//	std::string name;
//	int age = 15;
//	int height = 6;
//};

//template<>
//void print(Person value)
//{
//	std::cout << value.name << std::endl;
//	std::cout << value.age << std::endl;
//	std::cout << value.height << std::endl;
//}

//void printCstr(char *val)
//{
//	for (int i = 0; i < strlen(val); i++)
//	{
//		std::cout << val[i];
//	}
//	std::cout << "\n";
//}

template<int N>
char* CreateEmptyString()
{
	char* myString = new char[N];
	myString[0] = '\0';
	return myString;
}

template<typename T>
void swap(T &a, T &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

template<bool T>
void BoolAssert(bool a)
{
	assert(T == a);
}

// templated function that accepts two values of the same type and halts execution if they are not the same
template<typename T>
void TAssert(T a, T b)
{
	assert(a == b);
}

// templated function that accepts two values of the same type and halts execution if they are the same.
template<typename T>
void notTAssert(T a, T b)
{
	assert(a != b);
}



//void pause()
//{
//	bool menuItem = true;
//	while (menuItem == true)
//	{
//		if (_getch())
//		{
//			menuItem = false;
//		}
//	}
//}