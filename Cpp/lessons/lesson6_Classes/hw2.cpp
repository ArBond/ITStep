#include "hw2.h"

#include <cstring>
#include <iostream>



void Set::ExpandMemory()
{
	m_capacity *= 2;
	int* newMemory = new int[m_capacity];
	memcpy(newMemory, m_elements, m_count);
	delete[] m_elements;
	m_elements = newMemory;
}



Set::Set()
{
	m_elements = new int[5];
	m_capacity = 5;
	m_count = 0;
}

Set::Set(int number)
{
	m_elements = new int[5];
	m_capacity = 5;
	m_elements[0] = number;
	m_count = 1;
}

Set::Set(Set const& set)
{

}




bool Set::Contains(int element) const
{
	for (int i = 0; i < m_count; i++)
	{
		if (element == m_elements[i])
		{
			return true;
		}
	}
	return false;
}

size_t Set::GetCount() const
{
	return m_count;
}

void Set::AddElement(int element)
{
	if (Contains(element))
	{
		return;
	}
	if (m_count == m_capacity)
	{
		ExpandMemory();
	}
	m_elements[m_count] = element;
	m_count++;
}

void Set::DeleteElement(int element)
{
	for (int i = 0; i < m_count; i++)
	{
		if (m_elements[i] == element)
		{
			for (int j = i; i < element - 1; i++)
			{
				m_elements[j] = m_elements[j + 1];
			}
			m_count--;
			break;
		}
	}
}