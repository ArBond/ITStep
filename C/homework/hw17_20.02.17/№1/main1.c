/* Задание 1:
   Напишите программу поиска факториала числа без использования возвращения значения
   из функции факториала(return result;), используйте указатель на переменную с
   результатом и передавайте ее в рекурсивную функцию(например, factor(int* result)) */


#include <stdio.h>

void calculateFactorial(int number, double* result);

int main()
{
	printf("Davajte poschitaem faktorial.\nVvedite chislo(do 22): ");
	int number;
	scanf("%i", &number);
	while (number < 0 || number > 22)
	{
		printf(number < 1 ? "Faktorial otricatel'nogochisla ne opredelen\n":"Slishkom bol'shoe chislo\n");
		scanf("%i", &number);
	}
	double result = 1;
	calculateFactorial(number, &result);
	printf("Faktorial '%i' = %.0lf\n", number, result);
	return 0;
}

void calculateFactorial(int number, double* result)
{
	if (number > 1)
	{
		calculateFactorial(number - 1, result);
		*result *= number;
	}
}