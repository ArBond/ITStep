#include "Stack.h"

#include <iostream>

void Stack::CheckIsEmpty()
{
	if (m_count <= 0)
	{
		// throw m_count;
		// throw "Stack is empty";
		throw StackException(m_count);
		// throw std::string("StackException");
	}
}

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
	if (this != &stack)
	{
		m_capacity = stack.m_capacity;
		m_count = stack.m_count;
		m_elements = new int[m_capacity];
		memcpy(m_elements, stack.m_elements, m_capacity);
	}
}

Stack::~Stack()
{
	delete[] m_elements;
}

void Stack::Push(int element)
{
	if (m_count == 5)
	{
		throw StackIsFullException(m_count);
	}
	if (m_count == m_capacity)
	{
		ReallocateMemory(m_capacity * 2);
	}
	m_elements[m_count] = element;
	m_count++;
}

int Stack::Pop()
{
	try
	{
		CheckIsEmpty();
	}
	catch (StackException& ex)
	{
		throw ex;
	}
	catch (...)
	{
		throw;
	}
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
	CheckIsEmpty();
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

Stack& Stack::operator<<(int element)
{
	Push(element);
	return *this;
}

Stack& Stack::operator >> (int& element)
{
	element = Pop();
	return *this;
}