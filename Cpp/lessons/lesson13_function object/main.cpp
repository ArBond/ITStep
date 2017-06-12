#include "student.h"
#include "dinArray.h"

#include <cstring>
#include <iostream>

template<class T>
T const& max(T const& a, T const& b)
{
	return a > b ? a : b;
}

char const* max(char const* a, char const* b)
{
	return strcmp(a, b) > 0 ? a : b;
}

template<class T>
T const& min(T const& a, T const& b)
{
	return a < b ? a : b;
}

template<class T>
T const& max(T const& a, T const& b, T const& c)
{
	return max(max(a, b), c);
}

template<class T>
bool IsGreater(T const& a, T const& b)
{
	return a > b;
}

bool IsGreater(int const& a, double const& b)
{
	return (double)a > b;
}

template<typename T>
class AccumulationTraits;

template<>
class AccumulationTraits<int>
{
public:
	typedef int AccT;
};

template<>
class AccumulationTraits<char>
{
public:
	typedef int AccT;
};

template<>
class AccumulationTraits<const char>
{
public:
	typedef int AccT;
};

template<>
class AccumulationTraits<double>
{
public:
	typedef double AccT;
};

template<>
class AccumulationTraits<float>
{
public:
	typedef double AccT;
};

template<typename T>
T Average(T* array, int count)
{
	AccumulationTraits<T>::AccT alisa = 0;
	for (int i = 0; i < count; i++)
	{
		alisa += array[i];
	}
	return alisa / count;
}

template<class T>
class Compare
{
	T m_value;
public:
	Compare() = default;
	Compare(T value) : m_value(value)
	{
	};

	bool operator()(T const& value) const
	{
		return m_value == value;
	}
};

template<class T>
class Greater
{
	T m_value;
public:
	Greater() = default;
	Greater(T value) : m_value(value)
	{
	};

	bool operator()(T const& value) const
	{
		return m_value < value;
	}
};

typedef bool(*CompareFunc)(int const&);

bool CompareWith5(int const& value)
{
	return value == 5;
}

bool GreaterThan5(int const& value)
{
	return value > 5;
}

template<class T1, class T2>
T1* Find(T1* array, int count, T2 compare)
{
	for (int i = 0; i < count; i++)
	{
		if (compare(array[i]))
		{
			return array + i;
		}
	}
	return nullptr;
}

template<class T>
class GreaterFromTwo
{
public:
	GreaterFromTwo() = default;

	bool operator()(T const& value1,
		T const& value2) const
	{
		return value1 > value2;
	}
};

class GreaterFromTwoStudentByRating
{
public:
	GreaterFromTwoStudentByRating() = default;

	bool operator()(Student const& value1,
		Student const& value2) const
	{
		return value1.GetRating() > value2.GetRating();
	}
};

template<class T, class Pred = GreaterFromTwo<T> >
void BubbleSort(T* arr, int count, Pred compare = GreaterFromTwo<T>())
{
	for (int i = count - 1; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (compare(arr[j], arr[j + 1]))
			{
				// swap(arr[j], arr[j + 1]);
				T tmp = std::move(arr[j]);
				arr[j] = std::move(arr[j + 1]);
				arr[j + 1] = std::move(tmp);
			}
		}
	}
}

void main()
{
	int a = 5, b = 6;
	int arr[] = { 1, 10, 5, 6, 7 };
	Compare<int> cmp1(3);
	int* result = Find(arr, 5, cmp1);
	if (result)
	{
		std::cout << *result << "\n";
	}

	Greater<int> cmp2(2);
	int* result2 = Find(arr, 5, cmp2);
	if (result)
	{
		std::cout << *result2 << "\n";
	}
	
	GreaterFromTwo<int> greaterFromTwo;
	BubbleSort(arr, 5);

	Student studArray[] = { Student("Petrov", 5), Student("Ivanov", 7) };
	BubbleSort(studArray, 2);
	BubbleSort(studArray, 2, GreaterFromTwoStudentByRating());

	DynArray<int> d = { 200, 300, 100 };
}
