#pragma once

class Stack
{
private:
	int* m_elements;
	size_t m_capacity;
	size_t m_count;

	void ReallocateMemory(int newCapacity);

public:
	Stack();
	Stack(Stack const& stack);
	Stack(Stack && stack);
	~Stack();

	void Push(int element);
	int Pop();
	size_t GetQuantity();
	int Top();
	void Clear();

	Stack& operator=(Stack const& stack);
	Stack& operator=(Stack && stack);
	Stack& operator<<(int element);
	Stack& operator >> (int& element);
};




//					TEMPLARE 

//#pragma once
//
//template<class T>
//class Stack
//{
//private:
//	T* m_elements;
//	size_t m_capacity;
//	size_t m_count;
//
//	void ReallocateMemory(size_t newCapacity);
//
//public:
//	Stack();
//	Stack(Stack const& stack);
//	~Stack();
//
//	void Push(T element);
//	T& Pop();
//
//	Stack& operator=(Stack const& stack);
//	Stack& operator<<(int element);
//	Stack& operator >> (int& element);
//};
//
//template<class T>
//void Stack<T>::ReallocateMemory(size_t newCapacity)
//{
//	m_capacity = newCapacity;
//	T* newMemory = new T[m_capacity];
//	for (size_t i = 0; i < m_count; ++i)
//	{
//		newMemory[i] = m_elements[i];
//	}
//	delete[] m_elements;
//	m_elements = newMemory;
//}
//
//template<class T>
//Stack<T>::Stack() :
//	m_capacity(10),
//	m_count(0)
//{
//	m_elements = new T[10];
//}
//
//template<class T>
//Stack<T>::Stack(Stack const& stack)
//{
//	m_capacity = stack.m_capacity;
//	m_count = stack.m_count;
//	m_elements = new T[m_capacity];
//	for (size_t i = 0; i < m_count; ++i)
//	{
//		m_elements[i] = stack.m_elements[i];
//	}
//}
//
//template<class T>
//Stack<T>& Stack<T>::operator=(Stack<T> const& stack)
//{
//	if (this != &stack)
//	{
//		m_capacity = stack.m_capacity;
//		m_count = stack.m_count;
//		delete[] m_elements;
//		m_elements = new T[m_capacity];
//		for (size_t i = 0; i < stack.m_count; ++i)
//		{
//			m_elements[i] = stack.m_elements[i];
//		}
//	}
//	return *this;
//}
//
//template<class T>
//Stack<T>::~Stack()
//{
//	delete[] m_elements;
//}
//
//template<class T>
//void Stack<T>::Push(T element)
//{
//	if (m_count == m_capacity)
//	{
//		ReallocateMemory(m_capacity * 2);
//	}
//	m_elements[m_count] = element;
//	m_count++;
//}
//
//template<class T>
//T& Stack<T>::Pop()
//{
//	m_count--;
//	if (m_count * 4 <= m_capacity && m_count >= 10)
//	{
//		ReallocateMemory(m_capacity / 2);
//	}
//	return m_elements[m_count];
//}