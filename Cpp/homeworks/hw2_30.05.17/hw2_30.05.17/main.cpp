// hw -> https://github.com/bugslayer312/CppStudentHomeWorks/blob/master/OperatorsOverloading.pdf

#include "Set.h"

#include <iostream>

void main()
{
	Set s1;
	Set s2(3);
	Set s3(s2);
	
	s2 += 2;
	s2 += 1;
	s2 += 0;
	s2 += 1;
	std::cout << "S2: " << s2 << "\n";
	s2 -= 0;
	std::cout << "S2: " << s2 << "\n";

	std::cout << "Enter s1: ";
	std::cin >> s1;
	std::cout << "S1: " << s1 << "\n";

	std::cout << "Size S2: " << s2.GetCount() << "\n";
	std::cout << "S2 contains 2? - " << (s2.Contains(2)? "yes\n" : "no\n");

	std::cout << "S1 == S2? - " << (s2 == s1 ? "yes\n" : "no\n");

	s3 = s1 & s2;
	std::cout << "s1 & s2: " << s3 << "\n";

	s3 = s1 | s2;
	std::cout << "s1 | s2: " << s3 << "\n";

	s3 = s1 ^ s2;
	std::cout << "s1 ^ s2: " << s3 << "\n";
}