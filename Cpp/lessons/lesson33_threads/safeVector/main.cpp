#include <iostream>
#include "Vector.h"
#include <exception>

void main()
{
	SafeVector<int> vector;// = { 3, 4, 5 };
	

	try
	{
		vector.PopBack();
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}


	try
	{
		std::cout << vector[2];
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
