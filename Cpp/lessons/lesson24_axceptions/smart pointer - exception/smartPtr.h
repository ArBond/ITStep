#pragma once

template<class T>
class SmartPtr
{
	T* m_ptr = nullptr;

public:
	SmartPtr() = default;

	SmartPtr(T* ptr) : m_ptr(ptr)
	{
	}

	~SmartPtr()
	{
		delete m_ptr;
	}

	SmartPtr(SmartPtr const& rhs)
	{
		m_ptr = rhs.m_ptr;
		rhs.m_ptr = nullptr;
	}

	SmartPtr& operator=(SmartPtr const& rhs)
	{
		if (this != &rhs)
		{
			m_ptr = rhs.m_ptr;
			rhs.m_ptr = nullptr;
		}
		return *this;
	}

	void Reset()
	{
		delete m_ptr;
		m_ptr = nullptr;
	}

	T* operator->()
	{
		return m_ptr;
	}

	T& operator*()
	{
		return *m_ptr;
	}
};