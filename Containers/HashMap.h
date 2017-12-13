#pragma once
#include "tvector.h"
#include "IntVector.h"
#include "intLinkedList.h"
//template<typename T>
//struct hashData
//{
//	size_t key;
//	T _data = NULL;
//};

template<typename T>
class HashMap
{

public:
	HashMap();

	int hash(int key);//idx of map = (hash(key))

	void put(size_t idx, T val);//(hash(key),T val), inserts a value at the designated index

	T getRead(size_t key);//(hash(key)), return value at index

	void clear();

	bool equals(HashMap map1, HashMap map2);

	void remove(size_t idx);//(hash(key)

	int size(HashMap map1);//returns how many objects exist in the map

	bool containsKey(size_t idx);//Returns true if a key has a corresponding value;

	bool isEmpty(HashMap Hmap);

	intVector Keys(HashMap & map1);

	T & operator[](T idx);//Selects the value associated with key

	bool & operator==(T rhs);

	bool & operator!=(T rhs);







private:

	
	intVector keys;
	tVector<T> map;


	//used is as large as map capacity.
	tVector<bool> used;
};




template<typename T>
inline HashMap<T>::HashMap()
{
	map.Reserve(100);
	used.Reserve(map.getCapacity());
	//map.size = 100;
}

template<typename T>
inline int HashMap<T>::hash(int key)
{
	assert(key > 0);
	return key % map.getCapacity();
}

template<typename T>
inline void HashMap<T>::put(size_t idx, T val)
{	
	
	keys.append(idx);
	used[hash(idx)] = true;

	int actualIDX = hash(idx);
	map[actualIDX] = val;
	//std::cout << map[actualIDX];
}


//Returns a value corresponding to a hashed key
template<typename T>
inline T HashMap<T>::getRead(size_t key) 
{
	//auto q = map.at(key);
	return map.at(key);
}
//poop
template<typename T>
inline void HashMap<T>::clear()
{
	map.clearDat();
}

template<typename T>
inline bool HashMap<T>::equals(HashMap map1, HashMap map2)
{
	assert(map1.map.size() == map2.map.size() && map1.map.Capacity() == map2.map.Capacity(), "Map size & capacity must be the same must be the same");
	int counter = 0;
	for (int i = 0; i < map.getCapacity() - 1; i++)
	{
		
		if (map1.map[i] == map2.map[i])
		{
			counter++;
		}
	}
	if (map.getCapacity() == counter + 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
inline void HashMap<T>::remove(size_t idx)
{
	map.Erase(idx);
}

template<typename T>
inline int HashMap<T>::size(HashMap map1)
{

	return map1.map.size();
}

template<typename T>
inline bool HashMap<T>::containsKey(size_t idx)
{
	//assert(idx < map.getCapacity());
	if (used[hash(idx)] == true) 
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
// poop
template<typename T>
inline bool HashMap<T>::isEmpty(HashMap Hmap)
{
	return Hmap.map.empty();
}

template<typename T>
inline intVector HashMap<T>::Keys(HashMap & map1)
{
	/*intVector temp;


	for (int i = 0; i < map1.keys.getCapacity(); i++)
	{
		if (map1.map.at(i) != NULL)
		{
			temp.append(i);
		}
	}*/
	return keys;
}

template<typename T>
inline T & HashMap<T>::operator[](T idx)
{
	return map.at(idx);// TODO: insert return statement here
}

template<typename T>
inline bool & HashMap<T>::operator==(T rhs)
{
	if (*this == rhs)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
inline bool & HashMap<T>::operator!=(T rhs)
{
	if (*this != rhs)
	{
		return true;
	}
	else
	{
		return false;
	}
}

