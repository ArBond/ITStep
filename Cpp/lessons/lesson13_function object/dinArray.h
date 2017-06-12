#pragma once

#include <initializer_list>

template<class T>
class DynArray
{
public:
	DynArray(int capacity);
	DynArray(std::initializer_list<T> const& list);

private:
	T* m_data = nullptr;
	int m_capacity = 0;
	int m_count = 0;
};

template<class T>
DynArray<T>::DynArray(int capacity) :
	m_capacity(capacity)
{
	m_data = new T[m_capacity];
}

template<class T>
DynArray<T>::DynArray(std::initializer_list<T> const& list)
{
	m_capacity = list.size();
	std::initializer_list<T>::iterator it = list.begin();
	m_data = new T[m_capacity];
	T* ptr = m_data;
	for (; it != list.end(); ++it)
	{
		*(ptr++) = *it;
	}
}