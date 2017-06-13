#pragma once

#include <initializer_list>
#pragma once

#include <initializer_list>
#include <iostream>

template<class T>
class DynArray
{
public:
	DynArray(int capacity);

	DynArray(std::initializer_list<T> const& list);
	DynArray() = default;
	DynArray(DynArray<T> const& dynArray);
	DynArray<T>& operator=(DynArray<T> const& dynArray);
	DynArray<T>& operator=(DynArray<T>&& dynArray);
	DynArray(DynArray<T>&& dynArray);
	DynArray<T> operator*(T element);

	template<class T>
	friend std::ostream& operator<<(std::ostream& stream, DynArray<T> const& array);

	~DynArray();
	int GetCount() const;
	void PushBack(T const& element);
	T& operator[](int idx);
	T const& operator[](int idx) const;

	void Reserve(int newCapacity);


private:
	T* m_data = nullptr;
	int m_capacity = 0;
	int m_count = 0;
};

template<class T>
DynArray<T>::~DynArray()
{
	delete[] m_data;
};

template<class T>
int DynArray<T>::GetCount() const
{
	return m_count;
}

template<class T>
std::ostream& operator<<(std::ostream& stream, DynArray<T> const& array)
{
	for (int i = 0; i < array.m_count; i++)
	{
		stream << array.m_data[i] << " ";
	}
	return stream;
}

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
	m_data = new T[m_capacity];
	T* ptr = m_data;
	/*std::initializer_list<T>::iterator it = list.begin();
	for (; it != list.end(); ++it)
	{
	*(ptr++) = *it;
	} */

	for (T const& element : list)
	{
		*(ptr++) = element;
	}
	m_count = m_capacity;
}

template<class T>
DynArray<T>::DynArray(DynArray<T> const& dynArray)
{
	m_capacity = dynArray.m_capacity;
	m_count = dynArray.m_count;
	m_data = new T[m_capacity];

	for (int i = 0; i < m_count; i++)
	{
		m_data[i] = dynArray.m_data[i];
	}
}

template<class T>
DynArray<T>& DynArray<T>::operator=(DynArray<T> const& dynArray)
{
	if (this != &dynArray)
	{
		DynArray<T> tmp(dynArray);
		*this = std::move(tmp);
	}
	return *this;
}

template<class T>
DynArray<T>& DynArray<T>::operator=(DynArray<T>&& dynArray)
{
	if (this != &dynArray)
	{
		delete[] m_data;
		m_data = dynArray.m_data;
		m_capacity = dynArray.m_capacity;
		m_count = dynArray.m_count;
		dynArray.m_data = nullptr;
		dynArray.m_capacity = 0;
		dynArray.m_count = 0;
	}
	return *this;
}

template<class T>
DynArray<T> DynArray<T>::operator*(T element)
{
	DynArray result(*this);
	for (int i = 0; i < m_count; i++)
	{
		result.m_data[i] *= element;
	}
	return result;
}

template<class T>
DynArray<T>::DynArray(DynArray<T>&& dynArray)
{
	m_data = dynArray.m_data;
	m_capacity = dynArray.m_capacity;
	m_count = dynArray.m_count;
	dynArray.m_data = nullptr;
	dynArray.m_capacity = 0;
	dynArray.m_count = 0;
}

template<class T>
void DynArray<T>::PushBack(T const& element)
{
	if (m_count == m_capacity)
	{
		Reserve(m_capacity == 0 ? 1 : m_capacity * 2);
	}
	m_data[m_count++] = element;
}

template<class T>
T& DynArray<T>::operator[](int idx)
{
	if (!(idx >= 0 && idx < m_count))
	{
		std::cout << "Invalid index\n";
		exit(-1);
	}
	return m_data[idx];
}

template<class T>
T const& DynArray<T>::operator[](int idx) const
{
	DynArray<T>* nonConstThis = const_cast<DynArray<T>*>(this);
	return (*nonConstThis)[idx];
}


template<class T>
void DynArray<T>::Reserve(int newCapacity)
{
	m_capacity = newCapacity;
	if (m_count > m_capacity)
	{
		m_count = m_capacity;
	}
	T* newMemory = nullptr;
	if (m_capacity > 0)
	{
		newMemory = new T[m_capacity];
		for (int i = 0; i < m_count; i++)
		{
			newMemory[i] = std::move(m_data[i]);
		}
	}
	delete[] m_data;
	m_data = newMemory;
}