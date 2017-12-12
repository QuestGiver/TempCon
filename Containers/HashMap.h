#pragma once
#include "tvector.h"
#include "IntVector.h"
#include "intLinkedList.h"
template<typename T>
class HashMap
{

public:


	int hash(int key);//idx of map = (hash(key))

	void put(size_t idx, T val);//(hash(key),T val), inserts a value at the designated index

	T getRead(size_t key) const;//(hash(key)), return value at index

	void clear();

	bool equals(HashMap map);

	void remove(size_t idx);//(hash(key)

	int size(HashMap map);//returns how many objects exist in the map

	bool containsKey(size_t idx);//Returns true if a key has a corresponding value;

	bool isEmpty(HashMap map);

	intVector Keys(map);



	T & operator[](T idx);//Selects the value associated with key

	bool & operator==(T idx_a, T idx_b);

	bool & operator!=(T idx_a, T idx_b);


private:
	tVector<int> map;
};


template<typename T>
inline int HashMap<T>::hash(int key)
{
	return key % map.Capacity();
}

template<typename T>
inline void HashMap<T>::put(size_t idx, T val)
{
	map.insert(idx, val);
}


//Returns a value corresponding to a hashed key
template<typename T>
inline T HashMap<T>::getRead(size_t key) const
{
	map[key];
}

template<typename T>
inline void HashMap<T>::clear()
{
}

template<typename T>
inline bool HashMap<T>::equals(HashMap map)
{
	return false;
}

template<typename T>
inline void HashMap<T>::remove(size_t idx)
{
}

template<typename T>
inline int HashMap<T>::size(HashMap map)
{
	return 0;
}

template<typename T>
inline bool HashMap<T>::containsKey(size_t idx)
{
	return false;
}

template<typename T>
inline bool HashMap<T>::isEmpty(HashMap map)
{
	return false;
}

template<typename T>
inline intVector HashMap<T>::Keys(map)
{
	intVector temp;
	for (int i = 0; i < map.Capacity; i++)
	{
		if (map[i] != NULL)
		{
			temp.append(i);
		}
	}
	return temp;
}

template<typename T>
inline T & HashMap<T>::operator[](T idx)
{
	return map.at(idx);// TODO: insert return statement here
}

template<typename T>
inline bool & HashMap<T>::operator==(T idx_a, T idx_b)
{
	// TODO: insert return statement here
}

template<typename T>
inline bool & HashMap<T>::operator!=(T idx_a, T idx_b)
{
	// TODO: insert return statement here
}
