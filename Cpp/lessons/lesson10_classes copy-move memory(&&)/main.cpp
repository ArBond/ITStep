#include <iostream>

#include "Student.h"
#include "string.h"
#include "Stack.h"

void swap(String& s1, String& s2)
{
	String tmp = std::move(s1);
	s1 = std::move(s2);
	s2 = std::move(tmp);
}

void bubbleSort(String* arr, int count)
{
	for (int i = count - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void main()
{
	//  STRING
	/*String s1 = "11";
	String s2 = "22";
	String s3 = s1 + s2;
	String s4 = s3 + s1;
	std::cout << s1 << "\n" << s2 << "\n" << s3 << "\n" << s4 << "\n";
	swap(s1, s2);
	std::cout << s1 << "\n" << s2 << "\n";
	String arr[] = { "qwed", "asdsd", "zxc", "were", "sd" };
	bubbleSort(arr, 5);
	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << "\n";
	}*/

	Student st1("Ivanov", 5);
	Student st2 = std::move(st1);

	//st1.Print();
	st2.Print();
}
