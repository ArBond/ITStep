#include "distance.h"
#include "string.h"
#include <iostream>

void main()
{
	/*Distance d1, d2;
	std::cout << "Enter first: ";
	std::cin >> d1;
	std::cout << "Enter second: ";
	std::cin >> d2;
	Distance summ = d1 + d2;
	summ++;
	std::cout << "Summ: " << summ << "\n";*/

	String str1("qwe");
	String str2;
	std::cout << "Str1: " << str1.GetString() << "\nEnter your string: ";
	std::cin >> str2;
	std::cout << "Total string: " << str1+(str2) << "\n";
}
