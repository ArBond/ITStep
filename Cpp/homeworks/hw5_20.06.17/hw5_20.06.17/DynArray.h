#pragma once

#include <iostream>

template<class T>
class DynArrayIterator
{
public:
	T* m_ptr;

	DynArrayIterator(T* ptr) :m_ptr(ptr)
	{
	}

	T& operator*()
	{
		return *m_ptr;
	}

	DynArrayIterator<T> operator++()
	{
		m_ptr++;
		return *this;
	}

	DynArrayIterator<T> operator++(int)
	{
		T* result = m_ptr;
		m_ptr++;
		return result;
	}

	DynArrayIterator<T> operator--()
	{
		m_ptr--;
		return *this;
	}

	DynArrayIterator<T> operator--(int)
	{
		T* result = m_ptr;
		m_ptr--;
		return result;
	}
	DynArrayIterator<T> operator+(int step)
	{
		T* result = m_ptr;
		result += step;
		return result;
	}
	DynArrayIterator<T> operator-(int step)
	{
		T* result = m_ptr;
		result -= step;
		return result;
	}

	bool operator==(DynArrayIterator<T> const& rhs) const
	{
		return m_ptr == rhs.m_ptr;
	}

	bool operator!=(DynArrayIterator<T> const& rhs) const
	{
		return !(*this == rhs);
	}
};



template<class T>
class DynArray
{
public:
	T* m_data = nullptr;
	size_t m_capacity = 0;
	size_t m_size = 0;

public:
	typedef DynArrayIterator<T> iterator;

	DynArray() = default;
	DynArray(size_t capacity);
	DynArray(DynArray const& rhs);
	DynArray(DynArray&& rhs);
	DynArray(std::initializer_list<T> const& list);
	DynArray& operator=(DynArray const& rhs);
	DynArray& operator=(DynArray&& rhs);

	void reserve(size_t newCapacity);
	size_t size() const;
	size_t capacity() const;

	void push_back(T const& item);
	void pop_back();
	void clear();

	T& operator[](size_t idx);
	T const& operator[](size_t idx) const;

	iterator begin();
	iterator end();

	void insert(iterator const& it, T const& element);
	void erase(iterator const& it);
};

template<class T>
std::ostream& operator<<(std::ostream& stream, DynArray<T> const& array)
{
	for (size_t i = 0; i < array.size(); ++i)
	{
		stream << array[i] << " ";
	}
	return stream;
}

template<class T>
DynArray<T>::DynArray(size_t capacity) :
	m_capacity(capacity)
{
	if (m_capacity > 0)
	{
		m_data = new T[m_capacity];
	}
}

template<class T>
DynArray<T>::DynArray(DynArray const& rhs) :
	m_capacity(rhs.m_capacity),
	m_size(rhs.m_size)
{
	if (m_capacity > 0)
	{
		m_data = new T[m_capacity];
		for (size_t i = 0; i < m_size; ++i)
		{
			m_data[i] = rhs.m_data[i];
		}
	}
}

template<class T>
DynArray<T>::DynArray(DynArray&& rhs) :
	m_capacity(rhs.m_capacity),
	m_size(rhs.m_size),
	m_data(rhs.m_data)
{
	rhs.m_capacity = 0;
	rhs.m_size = 0;
	rhs.m_data = nullptr;
}

template<class T>
DynArray<T>::DynArray(std::initializer_list<T> const& list)
{
	size_t size = list.size();
	if (size > 0)
	{
		m_size = m_capacity = size;
		m_data = new T[m_capacity];
		T* ptr = m_data;
		typedef typename std::initializer_list<T>::iterator iterator;
		for (iterator it = list.begin(); it != list.end(); ++it)
		{
			*(ptr++) = *it;
		}
	}
}

template<class T>
DynArray<T>& DynArray<T>::operator=(DynArray<T> const& rhs)
{
	if (&rhs != this)
	{
		DynArray<T> temp(rhs);      // copy to temp
		*this = std::move(temp);    // grabbing data from temp
	}
	return *this;
}

template<class T>
DynArray<T>& DynArray<T>::operator=(DynArray<T>&& rhs)
{
	if (&rhs != this)
	{
		delete[] m_data;
		m_capacity = rhs.m_capacity;
		m_size = rhs.m_size;
		m_data = rhs.m_data;

		rhs.m_capacity = 0;
		rhs.m_size = 0;
		rhs.m_data = nullptr;
	}
	return *this;
}

template<class T>
void DynArray<T>::reserve(size_t newCapacity)
{
	if (m_capacity == newCapacity)
	{
		return;
	}

	m_capacity = newCapacity;
	if (m_size >= m_capacity)
	{
		m_size = m_capacity;
	}
	DynArray<T> temp(*this);    // copy to temp
	*this = std::move(temp);    // grabbing data from temp
}

template<class T>
size_t DynArray<T>::size() const
{
	return m_size;
}

template<class T>
size_t DynArray<T>::capacity() const
{
	return m_capacity;
}

template<class T>
void DynArray<T>::push_back(T const& item)
{
	if (m_size == m_capacity)
	{
		reserve(m_capacity > 0 ? m_capacity * 2 : 5);
	}
	m_data[m_size++] = item;
}

template<class T>
void DynArray<T>::pop_back()
{
	if (m_size)
	{
		--m_size;
		if (m_size < m_capacity / 4 && m_capacity > 5)
		{
			reserve(m_capacity / 2);
		}
	}
}

template<class T>
void DynArray<T>::clear()
{
	m_size = 0;
	m_capacity = 0;
	delete[] m_data;
	m_data = nullptr;
}

template<class T>
T& DynArray<T>::operator[](size_t idx)
{
	if (idx >= m_size)
	{
		std::cout << "DynArray: Invalid index: " << idx << std::endl;
		exit(1);
	}
	return m_data[idx];
}

template<class T>
T const& DynArray<T>::operator[](size_t idx) const
{
	DynArray<T>* nonConstThis = const_cast<DynArray<T>*>(this);
	return (*nonConstThis)[idx];
}


template<class T>
DynArrayIterator<T> DynArray<T>::begin()
{
	DynArrayIterator<T> it(m_data);
	return it;
}

template<class T>
DynArrayIterator<T> DynArray<T>::end()
{
	DynArrayIterator<T> it(m_data + m_size);
	return it;
}

template<class T>
void DynArray<T>::insert(iterator const& it, T const& element)
{
	if (it.m_ptr == nullptr)
	{
		std::cout << "DynArray: Invalid iterator!\n";
		exit(-1);
	}
	iterator buff = begin();
	size_t i = 0;
	while (buff != end() + 1)
	{
		if (buff == it)
		{
			if (m_size == m_capacity)
			{
				reserve(m_capacity > 0 ? m_capacity * 2 : 5);
			}
			for (int j = m_size; j != i; j--)
			{
				m_data[j] = m_data[j - 1];
			}
			m_data[i] = element;
			m_size++;
			return;
		}
		buff++;
		i++;
	}
}

template<class T>
void DynArray<T>::erase(iterator const& it)
{
	if (it.m_ptr == nullptr)
	{
		std::cout << "DynArray: Invalid iterator!\n";
		exit(-1);
	}
	iterator buff = begin();
	size_t i = 0;
	while (buff != end())
	{
		if (buff == it)
		{
			for (; i < m_size - 1; i++)
			{
				m_data[i] = m_data[i + 1];
			}
			m_size--;
			if (m_size * 4 <= m_capacity)
			{
				reserve(m_capacity / 2);
			}
			break;
		}
		buff++;
		i++;
	}
}