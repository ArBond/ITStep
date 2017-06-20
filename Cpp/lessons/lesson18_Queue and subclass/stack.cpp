#include "Stack.h"

#include <iostream>

void Stack::ReallocateMemory(int newCapacity)
{
	m_capacity = newCapacity;
	int* newMwmory = new int[m_capacity];
	memcpy(newMwmory, m_elements, m_capacity);
	delete[] m_elements;
	m_elements = newMwmory;
}

Stack::Stack() :
	m_capacity(10),
	m_count(0)
{
	m_elements = new int[10];
}

Stack::Stack(Stack const& stack)
{
	m_capacity = stack.m_capacity;
	m_count = stack.m_count;
	m_elements = new int[m_capacity];
	memcpy(m_elements, stack.m_elements, m_capacity);
}

Stack::~Stack()
{
	delete[] m_elements;
}

void Stack::Push(int element)
{
	if (m_count == m_capacity)
	{
		ReallocateMemory(m_capacity * 2);
	}
	m_elements[m_count] = element;
	m_count++;
}

int Stack::Pop()
{
	m_count--;
	if (m_count * 4 <= m_capacity && m_count >= 10)
	{
		ReallocateMemory(m_capacity / 2);
	}
	return m_elements[m_count];
}

size_t Stack::GetQuantity()
{
	return m_count;
}

int Stack::Top()
{
	return m_elements[m_count - 1];
}

void  Stack::Clear()
{
	m_count = 0;
}

Stack& Stack::operator=(Stack const& stack)
{
	if (this != &stack)
	{
		m_capacity = stack.m_capacity;
		m_count = stack.m_count;
		delete[] m_elements;
		m_elements = new int[m_capacity];
		memcpy(m_elements, stack.m_elements, m_capacity);
	}
	return *this;
}

Stack& Stack::operator=(Stack&& st1)
{
	if (this != &st1)
	{
		delete[] m_elements;
		m_count = st1.m_count;
		m_capacity = st1.m_capacity;
		m_elements = st1.m_elements;

		st1.m_elements = nullptr;
		st1.m_capacity = 0;
		st1.m_count = 0;
	}
	return *this;
}

Stack::Stack(Stack&& st1)
{
	m_count = st1.m_count;
	m_capacity = st1.m_capacity;
	m_elements = st1.m_elements;

	st1.m_elements = nullptr;
	st1.m_capacity = 0;
	st1.m_count = 0;
}

Stack& Stack::operator<<(int element)
{
	Push(element);
	return *this;
}

Stack& Stack::operator >> (int& element)
{
	if (m_count != 0)
	{
		element = Pop();
	}
	return *this;
}