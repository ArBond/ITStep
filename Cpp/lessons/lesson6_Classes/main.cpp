#include "string.h"
#include <cstring>
#include <iostream>

void main()
{
	String s1 = "Hello ";
	char s2[10];
	strcpy(s2, s1);
	s2[3] = 'q';
	std::cout << s2;
	String s3;
	std::cout << "\nEnter your name: ";
	std::cin >> s3;
	s3 = s1 + s3;
	std::cout << s3 << "!\n";
	std::cout << s3.GetLength() << "\n";
}
