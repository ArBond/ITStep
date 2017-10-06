#pragma once

#include <vector>
#include <algorithm>



template<typename T>
class ReverceSortFunctor
{
	typedef typename T::iterator myIt;
	myIt m_begin;
	myIt m_end;

public:

	ReverceSortFunctor(myIt begin, myIt end)
	{
		m_begin = begin;
		m_end = end;
	}

	void operator()() const
	{
		std::sort(m_begin, m_end);
		std::reverse(m_begin, m_end);
	}
};



template<typename T>
class SortFunctor
{
	typedef typename T::iterator myIt;
	myIt m_begin;
	myIt m_end;

public:

	SortFunctor(myIt begin, myIt end) :m_begin(begin), m_end(end)
	{
	}

	void operator()() const
	{
		T::sort(m_begin);
	}
};



template<typename T>
class MaxFunctor
{
	typedef typename T::iterator myIt;
	myIt m_begin;
	myIt m_end;

public:

	MaxFunctor(myIt begin, myIt end)
	{
		m_begin = begin;
		m_end = end;
	}

	myIt operator()() const
	{
		myIt iteratorAtMax = m_begin;
		for (auto it = m_begin; it < m_end; it++)
		{
			if (*iteratorAtMax < *it)
				iteratorAtMax = it;
		}
		return iteratorAtMax;
	}
};




template<typename T>
class MinFunctor
{
	typedef typename T::iterator myIt;
	myIt m_begin;
	myIt m_end;

public:

	MinFunctor(myIt begin, myIt end)
	{
		m_begin = begin;
		m_end = end;
	}

	myIt operator()() const
	{
		myIt iteratorAtMin = m_begin;
		for (auto it = m_begin; it < m_end; it++)
		{
			if (*iteratorAtMin > *it)
				iteratorAtMin = it;
		}
		return iteratorAtMin;
	}
};




template<typename T>
class IncreaseByFunctor
{
	typedef typename T::iterator myIt;
	myIt m_begin;
	myIt m_end;

public:

	IncreaseByFunctor(myIt begin, myIt end)
	{
		m_begin = begin;
		m_end = end;
	}

	void operator()(T increaser)
	{
		for (auto it = m_begin; it < m_end; it++)
			*it += increaser;
	}
};



template<typename T>
class ReduceByFunctor
{
	typedef typename T::iterator myIt;
	myIt m_begin;
	myIt m_end;

public:

	ReduceByFunctor(myIt begin, myIt end)
	{
		m_begin = begin;
		m_end = end;
	}

	void operator()(T reducer)
	{
		for (auto it = m_begin; it < m_end; it++)
			*it -= reducer;
	}
};




template<typename T>
class DeleterFunctor
{
	typedef typename T::iterator myIt;
	myIt m_begin;
	myIt m_end;

public:

	DeleterFunctor(myIt begin, myIt end)
	{
		m_begin = begin;
		m_end = end;
	}

	int operator()(T deleter)
	{
		int deleteCount = 0;
		int count = 0;
		for (auto it = m_begin; it < m_end; it++)
		{
			count++;
			if (*it == deleter)
			{
				deleteCount++;
			}
			else
			{
				*(it - deleteCount) = *it;
			}	
		}
		return count - deleteCount;
	}
};
