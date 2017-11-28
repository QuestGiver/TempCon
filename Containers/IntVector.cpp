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

int & intVector::operator[](size_t idx)
{
	assert(idx >= 0 && "index must be greater than or equal to 0");
	assert(idx < size);

	return at(idx);
}
