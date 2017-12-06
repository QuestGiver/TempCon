#pragma once
#include<assert.h>
#include"Iterator.h"
template<typename T>
class tVector
{
	T * data;
	size_t Capacity;
	size_t size;



	bool grow(size_t minSize);
public:
	tVector();

	~tVector();


	iterator<tVector<T>> begin()
	{
		return iterator<tVector<T>>(*this, 0);
	}

	iterator<tVector<T>> end()
	{
		return iterator<tVector<T>>(*this, size);
	}



	T& at(size_t idx);

	T& append(T val);

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

	void pop();

	void EraseRange(size_t & idx_start, size_t & idx_end);

};


template<typename T>
inline bool tVector<T>::grow(size_t minSize)
{
	assert(minSize <= 64000);

	if (minSize <= capacity)
	{
		return true;
	}

	while (capacity < minSize)
	{
		capacity *= 2;
	}

	T* newData = new T[capacity];
	memcpy(newData, data, sizeof(T) * size);

	delete[] data;

	data = newData;

	return true;
}

template<typename T>
inline tVector<T>::tVector()
{
	Capacity = 2;
	data = new T[Capacity];
	size = 0;
}

template<typename T>
inline tVector<T>::~tVector()
{
	delete[] data;
}

template<typename T>
inline T & tVector<T>::at(size_t idx)
{
	assert(idx >= 0 && "index must be greater than -1");
	assert(idx < size);

	return data[idx];
}

template<typename T>
inline T & tVector<T>::append(T val)
{
	if (size == capacity)
	{
		bool didGrow = grow(size + 1);

		assert(didGrow);
	}

	data[size] = val;
	++size;
	return data[size + 1];
}

template<typename T>
inline int * tVector<T>::c_ptr() const
{
	return data;
}

template<typename T>
inline size_t tVector<T>::getCapacity() const
{
	return Capacity;
}

template<typename T>
inline size_t tVector<T>::getSize() const
{
	return size;
}

template<typename T>
inline bool tVector<T>::empty() const
{
	if (size == 0)
	{
		return true;
	}

	return false;
}

template<typename T>
inline int tVector<T>::front() const
{
	return at(0);
}

template<typename T>
inline int tVector<T>::back() const
{
	return at(size - 1);
}

template<typename T>
inline int & tVector<T>::operator[](size_t idx) const
{
	assert(idx >= 0 && "index must be greater than or equal to 0");
	assert(idx < size);

	return at(idx);
}

template<typename T>
inline void tVector<T>::clearDat()
{
	size = 0;
}

template<typename T>
inline void tVector<T>::Erase(size_t idx)
{
	for (int i = 0; i < size - idx; i++)
	{
		data[idx + i] = data[(idx + i) + 1];
	}

	size = size - 1;
	assert(size > 0);
}

template<typename T>
inline int tVector<T>::count(size_t idx) const
{
	int counter = 0;

	for (int i = 0; i < size - 1; i++)
	{
		if (data[idx] == data[i])
		{
			counter += 1;
		}
	}

	return counter;
}

template<typename T>
inline void tVector<T>::insert(size_t idx, size_t val)
{
	append(val);

	assert(idx >= 0);
	assert(idx < size);

	if (idx < size - 1)
	{
		for (int i = size - 1; i > idx; i--)
		{
			/*int temp = data[i];
			data[i] = data[i - 1];
			data[i - 1] = temp;*/







			/*int a = data[i-1];
			int b = data[i];*/

			data[i - 1] = data[i - 1] + data[i];
			data[i] = data[i - 1] - data[i];
			data[i - 1] = data[i - 1] - data[i];



		}
	}
}

template<typename T>
inline void tVector<T>::Reserve(size_t newCapacity)
{
	assert(newCapacity > capacity);

	if (newCapacity > capacity)
	{
		T * newData = new T[newCapacity];
		memcpy(newData, data, sizeof(T) * size);
		delete[] data;
		data = newData;
		capacity = newCapacity;
	}
}

template<typename T>
inline void tVector<T>::Compact()
{
	if (size < capacity)
	{
		T * newData = new T[size];
		memcpy(newData, data, sizeof(T) * size);
		delete[] data;
		data = newData;
		capacity = size;
	}
}

template<typename T>
inline void tVector<T>::pop()
{
	assert(size > 0);
	size -= 1;
}

template<typename T>
inline void tVector<T>::EraseRange(size_t & idx_start, size_t & idx_end)
{
	assert(idx_end > idx_start && idx_end < size);

	int range = idx_end - idx_start + 1;

	for (int i = 0; i < range; i++)
	{
		int readIndex = idx_end + (i + 1);

		if (readIndex > size)
		{
			break;
		}

		data[idx_start + i] = data[readIndex];
	}

	size -= range;



	//int * fill = new int[];
	//
	//for (int i = idx_end; i < size-1; i++)
	//{
	//	fill[size - idx_end] = data[i];
	//}
	//
	//for (int i = idx_start; i < idx_end; i++)
	//{
	//	data[i] = fill[size - idx_start];
	//}
	//
	//size -= idx_end - idx_start;
	//
	//delete[] fill;
	//for (int i = idx_start; i < idx_end; i++)
	//{
	//	Erase(i);
	//}
}
