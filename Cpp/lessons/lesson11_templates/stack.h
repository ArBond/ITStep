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
	Stack(Stack&& stack);
	~Stack();

	void Push(int element);
	int Pop();
	size_t GetQuantity();
	int Top();
	void Clear();

	Stack& operator=(Stack const& stack);
	Stack& operator=(Stack&& stack);
	Stack& operator<<(int element);
	Stack& operator >> (int& element);
};