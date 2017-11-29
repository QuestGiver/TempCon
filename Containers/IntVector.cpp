#include "IntVector.h"

#include <cstring>

intVector::intVector()
{
	capacity = 2;
	data = new int[capacity];
	size = 0;
}

intVector::~intVector()
{
	delete[] data;
}

int & intVector::at(size_t idx) const
{
	assert(idx >= 0 && "index must be greater than -1");
	assert(idx < size);

	return data[idx];
}

int & intVector::append(int val)
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

int * intVector::c_ptr() const
{
	return data;
}

size_t intVector::getCapacity() const
{
	return capacity;
}

size_t intVector::getSize() const
{
	return size;
}

bool intVector::grow(size_t minSize)
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

	int* newData = new int[capacity];
	memcpy(newData, data, sizeof(int) * size);

	delete[] data;

	data = newData;

	return true;
}

bool intVector::empty() const
{
	if (size == 0)
	{
		return true;
	}

	return false;
}

int intVector::front() const
{
	return at(0);
}

int intVector::back() const
{
	return at(size-1);
}

int & intVector::operator[](size_t idx) const
{
	assert(idx >= 0 && "index must be greater than or equal to 0");
	assert(idx < size);

	return at(idx);
}

void intVector::clearDat()
{
	size = 0;
}

void intVector::Erase(size_t idx)
{
	for (int i = 0; i < size-idx; i++)
	{
		data[idx + i] = data[(idx + i) + 1];
	}

	size = size - 1;
	assert(size > 0);
}

int intVector::count(size_t idx) const
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

void intVector::insert(size_t idx, size_t val)
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

void intVector::Reserve(size_t newCapacity)
{
	assert(newCapacity > capacity);

	if (newCapacity > capacity)
	{
		int * newData = new int[newCapacity];
		memcpy(newData, data, sizeof(int) * size);
		delete[] data;
		data = newData;
		capacity = newCapacity;
	}


}

void intVector::Compact()
{

	if (size < capacity)
	{
		int * newData = new int[size];
		memcpy(newData, data, sizeof(int) * size);
		delete[] data;
		data = newData;
		capacity = size;
	}

}

void intVector::EraseRange(size_t idx_start, size_t idx_end)
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
