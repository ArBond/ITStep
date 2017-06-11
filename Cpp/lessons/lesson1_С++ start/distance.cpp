#include "distance.h"
#include <iostream>

Distance Summ(Distance const& d1, Distance const& d2)
{
	Distance result;
	result.Feet = d1.Feet + d2.Feet;
	result.Inches = d1.Inches + d2.Inches;
	if (result.Inches >= 12.0f)
	{
		result.Inches -= 12.0f;
		result.Feet += 1;
	}
	return result;
}

Distance Diff(Distance const& d1, Distance const& d2)
{
	Distance result;
	result.Feet = d1.Feet - d2.Feet;
	result.Inches = d1.Inches - d2.Inches;
	if (result.Inches < 0)
	{
		result.Feet -= 1;
		result.Inches += 12.0f;
	}
	return result;
}

void Print(Distance const& d)
{
	std::cout << d.Feet << "\'" << d.Inches << "\"" << std::endl;
}

Distance Read()
{
	Distance result;
	std::cout << "Enter Feet and Inches: " << std::endl;
	std::cin >> result.Feet >> result.Inches;
	return result;
}