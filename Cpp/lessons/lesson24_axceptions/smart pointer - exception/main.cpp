#include "SmartPtr.h"
#include "Stack.h"

#include <iostream>
#include <exception>
#include <cstring>

class SmartIntArray
{
	int* m_arr = nullptr;

public:
	SmartIntArray(int* arr) :
		m_arr(arr)
	{
	}

	~SmartIntArray()
	{
		std::cout << "clear memory\n";
		delete[] m_arr;
	}

	void Reset()
	{
		delete[] m_arr;
		m_arr = nullptr;
	}
	void Attach(int* arr)
	{
		Reset();
		m_arr = arr;
	}

	int* GetArr()
	{
		return m_arr;
	}

	int* operator*()
	{
		return m_arr;
	}
};

void throwable()
{
	throw std::exception("error");
}

void print(int* arr, int count)
{
	for (int i = 0; i <= count; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

void generate(int* arr, int count)
{
	for (int i = 0; i < count; ++i)
	{
		arr[i] = i * 100;
	}
}

class FileGuard
{
	FILE* m_file = 0;

public:
	FileGuard(char const* filename)
	{
		m_file = fopen(filename, "r");
	}
	~FileGuard()
	{
		fclose(m_file);
	}

	FILE* GetDescriptor()
	{
		return m_file;
	}
};

void func()
{
	SmartIntArray arr(new int[10]);

	generate(arr.GetArr(), 10);

	FileGuard fg("blabla.txt");

	char buff[100] = "some string";

	fwrite(buff, strlen(buff), 1, fg.GetDescriptor());

	throwable();
	print(arr.GetArr(), 10);

	std::cout << "clear array\n";
}

void func2()
{
	SmartPtr<Stack> ptrSt(new Stack());
	ptrSt->Push(1);
	ptrSt->Pop();
	ptrSt->Pop();
}

void main()
{
	try
	{
		func2();
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << "\n";
	}
}
