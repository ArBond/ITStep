#pragma once

int const MaxCount = 5;

template<class T>
class Queue
{
	T m_data[MaxCount];
	int m_bottom = 0;
	int m_top = 0;

public:
	void Push(T const& element)
	{
		if (GetCount() != MaxCount - 1)
		{
			m_data[m_top++] = element;
		}
		else
		{
			std::cout << "Queue is full\n";
		}
		if (m_top == MaxCount)
		{
			m_top = 0;
		}
	}

	T Pop()
	{
		if (IsEmpty())
		{
			std::cout << "Queue is empty\n";
			exit(-1);
		}
		int bottom = m_bottom++;
		if (m_bottom == MaxCount)
		{
			m_bottom = 0;
		}
		return m_data[bottom];
	}

	bool IsEmpty()
	{
		return m_bottom == m_top;
	}

	int GetCount()
	{
		int result = 0;
		if (m_top < m_bottom)
		{
			result += MaxCount;
		}
		return m_top + result - m_bottom;
	}
};