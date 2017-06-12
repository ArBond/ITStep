#include "Set.h"

#include <iostream>

void Set::ReAllocateMemory(size_t newCapacity)
{

}

Set::Set():
	m_capacity(10), m_count(0)
{
	m_elements = new int[10];
}

Set::Set(int number):
	m_capacity(10), m_count(1)
{
	m_elements = new int[10];
	m_elements[0] = number;
}

Set::Set(Set const& rhs):
	m_capacity(rhs.m_capacity), m_count(rhs.m_count)
{
	m_elements = new int[rhs.m_capacity];
	memcpy(m_elements, rhs.m_elements, m_count * sizeof(int));
}

Set::~Set()
{
	delete[] m_elements;
}

size_t Set::GetCount() const
{
	return m_count;
}

bool Set::Contains(int element) const
{
	for (size_t i = 0; i < m_count; i++)
	{
		if (m_elements[i] == element)
		{
			return true;
		}
	}
	return false;
}

Set& Set::operator=(Set const& rhs)
{
	if (this != &rhs)
	{
		m_capacity = rhs.m_capacity;
		m_count = rhs.m_count;
		delete[] m_elements;
		m_elements = new int[rhs.m_capacity];
		memcpy(m_elements, rhs.m_elements, m_count * sizeof(int));
	}
	return *this;
}

void Set::operator+=(int element)
{
	if (!Contains(element))
	{
		if (m_capacity == m_count)
		{
			ReAllocateMemory(m_capacity * 2);
		}
		m_elements[m_count++] = element;
	}
}

void Set::operator-=(int element)
{
	for (size_t i = 0; i < m_count; i++)
	{
		if (m_elements[i] == element)
		{
			m_count--;
			for (size_t j = i; j < m_count; j++)
			{
				m_elements[j] = m_elements[j + 1];
			}
			if (m_capacity / 4 >= m_count && m_capacity >= 20)
			{
				ReAllocateMemory(m_capacity / 2);
			}
			break;
		}
	}
}

bool Set::operator==(Set const& rhs) const
{
	if (m_count == rhs.m_count)
	{
		for (size_t i = 0; i < m_count; i++)
		{
			if (!Contains(rhs.m_elements[i]))
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

bool Set::operator!=(Set const& rhs) const
{
	return !(*this == rhs);
}

Set::operator bool() const
{
	return m_count > 0;
}

Set operator&(Set const& set1, Set const& set2)
{
	Set result;
	for (size_t i = 0; i < set2.m_count; i++)
	{
		if (set1.Contains(set2.m_elements[i]))
		{
			result += set1.m_elements[i];
		}
	}
	return result;
}

Set operator|(Set const& set1, Set const& set2)
{
	Set result(set1);
	for (size_t i = 0; i < set2.m_count; i++)
	{
		if (!set1.Contains(set2.m_elements[i]))
		{
			result += set2.m_elements[i];
		}
	}
	return result;
}

Set operator^(Set const& set1, Set const& set2)
{
	Set result;
	for (size_t i = 0; i < set1.m_count; i++)
	{
		if (!set2.Contains(set1.m_elements[i]))
		{
			result += set1.m_elements[i];
		}
	}
	for (size_t i = 0; i < set2.m_count; i++)
	{
		if (!set1.Contains(set2.m_elements[i]))
		{
			result += set2.m_elements[i];
		}
	}
	return result;
}

std::ostream& operator<<(std::ostream& stream, Set const& set)
{
	for (size_t i = 0; i < set.m_count; i++)
	{
		stream << set.m_elements[i] << " ";
	}
	return stream;
}

std::istream& operator>>(std::istream& stream, Set& set)
{
	char* buffer = new char[1000];
	stream.getline(buffer, 999);
	char* begin = buffer;
	do
	{
		set += strtol(begin, &begin, 10);
		if (*begin != ' ' && *begin != 0)
		{
			std::cout << "Wrong format\n";
			exit(-1);
		}
	} while (*begin != 0);
	delete[] buffer;
	return stream;
}