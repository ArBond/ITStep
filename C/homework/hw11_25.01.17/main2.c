/*  Задание 2
    Реализовать программу нахождения факториала числа(без рекурсии, т.е.вызова функции
	самой себя).
	Факториал числа — это произведение натуральных чисел от 1 до самого числа(включая
		данное число).Примеры: 3!= 1 * 2 * 3 = 6. 6!= 1 * 2 * 3 * 4 * 5 * 6 = 720.
	Пример прототипа функции : int getFactorial(int n);  */



#include <stdio.h>

long long getFactorial(int number);

int main()
{
	int number;
	printf("Faktorial kakogo chisla hotite poschitat?\n");
	scanf("%i", &number);
	while (number > 13 || number < 0)
	{
		if (number > 15)
		{
			printf("Slishkom bolshoe chislo!\n");
		}
		else
		{
			printf("Faktorial ne opredelen dlja otricatelnyh chisel\n");
		}
		scanf("%i", &number);
	}
	printf("factorial '%i' = %ld\n", number, getFactorial(number));
	return 0;
}

long long getFactorial(int number)
{
	if (number > 2)
	{
		for (int i = number; i > 2; i--)
		{
			number *= i - 1;
		}
	}
	else if (number == 0)
	{
		number = 1;
	}
	return number;
}