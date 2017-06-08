#include <iostream>

#include "stack.h"
#include "Student.h"
#include "string.h"


template <class T>
void bubbleSort(T* arr, int count)
{
	for (int i = count - 1; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				T tmp = std::move(arr[j]);
				arr[j] = std::move(arr[j + 1]);
				arr[j + 1] = std::move(tmp);
			}
		}
	}
}

template <class T>
T const& max(T const& a1, T const& a2)
{
	return a1 > a2 ? a1 : a2;
}

template <class T>
T const& min(T const& a1, T const& a2)
{
	return a1 < a2 ? a1 : a2;
}

template <class T>
T* find(T* array, int count, T const& element)
{
	for (int i = 0; i < count; i++)
	{
		if (array[i] == element)
		{
			return array + 1;
		}
	}
	return nullptr;
}




template<class T, int N>
class Array
{
public:
	T m_array[N];
	Array();


	template<class T1, int N1>
	Array(const Array<T1, N1>& rhs)
	{
		for (int i = 0; i < min(N, N1); ++i)
		{
			m_array[i] = (T)rhs.m_array[i];
		}
	}

	T& operator[](int idx);
	int GetSize() const;
};

template<class T, int N>
Array<T, N>::Array()
{
	memset(m_array, 0, N);
}

template<class T, int N>
T& Array<T, N>::operator[](int idx)
{
	if (idx < 0 || idx >= N)
	{
		std::cout << "Invalid index\n";
		exit(1);
	}
	return m_array[idx];
}

template<class T1, int N>
int Array<T1, N>::GetSize() const
{
	return N;
}


void main()
{
	double arr1[] = { 12.2, 3.2, - 5.21, 9.2, -0.02 };
	int arr2[] = { 2, -5, 8, 0, -2 };
	String arr3[] = { "qwerr", "awer", "sdgs", "wert", "sfdzf" };
	Student arr4[] = { Student("Petrov", 8), Student("Ivanov", 4), Student("Kruglov", 7), Student("Anisimov", 9), Student("Bolshov", 5) };

	bubbleSort(arr1, 5);
	for (int i = 0; i < 5; i++)
	{
		std::cout << i + 1 << ": " << arr1[i] << "\n";
	}

	bubbleSort(arr2, 5);
	for (int i = 0; i < 5; i++)
	{
		std::cout << i + 1 << ": " << arr2[i] << "\n";
	}

	bubbleSort(arr3, 5);
	for (int i = 0; i < 5; i++)
	{
		std::cout << i + 1 << ": " << arr3[i] << "\n";
	}

	bubbleSort(arr4, 5);
	for (int i = 0; i < 5; i++)
	{
		arr4[i].Print();
	}

	Array<int, 11> arr9;

	for (int i = 0; i < arr9.GetSize(); i++)
	{
		arr9[i] = i + 1;
	}
	Array<double, 10> arr8 = arr9;
	for (int i = 0; i < arr8.GetSize(); i++)
	{
		std::cout << arr8[i] << "  ";
	}
}

// Вандервуд Джосаттис
