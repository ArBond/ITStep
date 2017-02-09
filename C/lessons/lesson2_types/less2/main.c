#include <stdio.h>
int main()
{


	                /* Целые типы данных: */

	/* char       1 byte
	   short      2 byte
	   int        2 - 4 byte
	   long       4 byte
	   long long  4-8 byte

	   %i - целые */

	printf("sizeof(unsigned char) =        \t%i", sizeof(char));
	printf("\tsizeof(signed char) =        \t%i", sizeof(signed char));

	printf("\nsizeof(unsigned short) =     \t%i", sizeof(short));
	printf("\tsizeof(signed short) =       \t%i", sizeof(signed short));

	printf("\nsizeof(unsigned int) =       \t%i", sizeof(int));
	printf("\tsizeof(signed int) =         \t%i", sizeof(signed int));

	printf("\nsizeof(unsigned long) =      \t%i", sizeof(long));
	printf("\tsizeof(signed long) =        \t%i", sizeof(signed long));

	printf("\nsizeof(unsigned long long) = \t%i", sizeof(long long));
	printf("\tsizeof(signed long long) =   \t%i\n", sizeof(signed long long));

	// %8d - 8 количество отступаемых делений

	printf("\n%10s%8i\n\n", "hello", sizeof(short));





	              /*Вещественные типы данных*/

	/* float;           4 byte
	   double;          8 byte
	   long float;      8 byte
	   long double;     8 byte

	   %d, %f - дробные */





	             /* Символьный тип данных */

	// char    %с - строковый

	printf("%5c - %i\n", 'h','h');
	printf("%5c - %i\n", 'e','e');
	printf("%5c - %i\n", 'l','l');
	printf("%5c - %i\n", 'l', 'l');
	printf("%5c - %i\n", 'o','o');

	printf("\n%5c\n", 'h' - 32);
	printf("%5c\n", 'e' - 32);
	printf("%5c\n", 'l' - 32);
	printf("%5c\n", 'l' - 32);
	printf("%5c\n", 'o' - 32);

	printf("\n%5c - %i\n", 'h' - 32, 'h' - 32);
	printf("%5c - %i\n", 'e' - 32, 'e' - 32);
	printf("%5c - %i\n", 'l' - 32, 'l' - 32);
	printf("%5c - %i\n", 'l' - 32, 'l' - 32);
	printf("%5c - %i\n\n", 'o' - 32, 'o' - 32);



	char letterH = 'h';
	char letterE = 'e';
	char letterL = 'l';
	char letterO = 'o';

	letterH = letterH - 32;     /* letterH -= 32; */
	letterE = letterE - 32;
	letterL = letterL - 32;
	letterO = letterO - 32;

	printf("%5c - %i\n", letterH, letterH);
	printf("%5c - %i\n", letterE, letterE);
	printf("%5c - %i\n", letterL, letterL);
	printf("%5c - %i\n", letterL, letterL);
	printf("%5c - %i\n", letterO, letterO);
}