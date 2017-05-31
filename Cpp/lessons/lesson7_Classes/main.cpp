#include "interval.h"
#include <iostream>

void main()
{
	Interval int1(3, 9);
	std::cout << "First: " << int1;
	Interval int2;
	std::cout << "\nEnter interval begin and end: ";
	std::cin >> int2;
	std::cout << "&: " << int1.operator&(int2) << "\n";
	std::cout << "|: " << int1.operator|(int2) << "\n";
}
