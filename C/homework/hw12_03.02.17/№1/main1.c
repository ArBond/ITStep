/* Задание 1
Написать рекурсивную функцию нахождения наибольшего общего делителя двух целых
чисел. */


#include <stdio.h>

int scanNumber(int maxNumer);
int calculate(int a, int b, int nod);

int main()
{
	int const maxNumer = 4500;
	printf("Najdem naibol'shij obshij delitel' dvuh celyh chisel(do 4500).\nVvedine 2 chisla:\n 1) ");
	int a = scanNumber(maxNumer);
	printf(" 2) ");
	int b = scanNumber(maxNumer);
	int nod = a;
	if (a > b)
	{
		nod = b;
	}
	printf("NOD(%i,%i) = %i\n", a, b, calculate(a, b, nod));
	return 0;
}

int calculate(int a, int b, int nod)
{
	if (b % nod == 0 && a % nod == 0)
	{
		return nod;
	}
	calculate(a, b, nod - 1);
}

int scanNumber(int maxNumer)
{
	int number;
	scanf("%i", &number);
	while (number > maxNumer)
	{
		printf("Slishkom bolshoe chislo.\n 1) ");
		scanf("%i", &number);
	}
	return number;
}