#include <iostream>

#include "Array.h"
#include "Complex.h"

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
bool Greater(T const& a, T const& b)
{
	return a > b;
}

bool Greater(int const& a, double const& b)
{
	return (double)a > b;
}

template<class T>
void BubbleSort(T* arr, int count)
{
	for (int i = count - 1; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				// swap(arr[j], arr[j + 1]);
				T tmp = std::move(arr[j]);
				arr[j] = std::move(arr[j + 1]);
				arr[j + 1] = std::move(tmp);
			}
		}
	}
}

template<class T>
T* Find(T* array, int count, T const& element)
{
	for (int i = 0; i < count; i++)
	{
		if (array[i] == element)
		{
			return array + i;
		}
	}
	return nullptr;
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



void main()
{
	int arr1[] = { 12, 3, -5, 9, -1 };
	//String arr3[] = { "qwerr", "awer", "sdgs", "wert", "sfdzf" };
	//Student arr4[] = { Student("Petrov", 8), Student("Ivanov", 4), Student("Kruglov", 7), Student("Anisimov", 9), Student("Bolshov", 5) };

	BubbleSort(arr1, 5);
	for (int i = 0; i < 5; i++)
	{
		std::cout << i + 1 << ": " << arr1[i] << "\n";
	}

	/*bubbleSort(arr3, 5);
	for (int i = 0; i < 5; i++)
	{
		std::cout << i + 1 << ": " << arr3[i] << "\n";
	}

	bubbleSort(arr4, 5);
	for (int i = 0; i < 5; i++)
	{
		arr4[i].Print();
	}*/

	Array<int, 11> arr9;
	for (int i = 0; i < arr9.GetSize(); i++)
	{
		arr9[i] = i + 1;
	}

	Array<int, 10> arr8 = arr9;
	for (int i = 0; i < arr8.GetSize(); i++)
	{
		std::cout << arr8[i] << "  ";
	}

	arr8 = arr9;

	std::cout << Average("aaaaeeeeeee", 11) << "\n";

	Complex<float> c1(2.4, 3.1);
	Complex<double> c2(c1);
	Complex<double> c3 = c1 + c2;

	Complex<float> c4 = c3 * c1;
	std::cout << c4 << "\n";

	c4 = c1;
	std::cout << c4 << "\n";
}
