/* Задание 2:
   Напишите программу возведения чисел в степень, используйте указатели для передачи
   результирующего значения в функцию и из нее.Числа необходимо получать от
   пользователя. */


#include <stdio.h>

void findNumber(int number, int degree, double* result);

int main()
{
	printf("Vozvedem chislo v stepen'!\nVvedite chislo: ");
	int number;
	scanf("%i", &number);
	while (number > 99 || number < -99)
	{
		printf(number > 99 ? "Slishkom bol'shoe chislo\n":"Slishkom malen'koe chislo\n");
		scanf("%i", &number);
	}
	printf("Stepen': ");
	int degree;
	scanf("%i", &degree);
	while (degree > 9 || degree < 0)
	{
		printf(degree > 9 ? "Slishkom bol'shaja stepen'\n" : "Vozvedenije v oticatel'nuju stepen' ne podderzhivaetsa programmoj\n");
		scanf("%i", &degree);
	}
	double result = number;
	findNumber(number, degree, &result);
	printf("%i ^ %i = %.0lf\n", number, degree, result);
	return 0;
}

void findNumber(int number, int degree, double* result)
{
	if ((number > 1 || number < 0) && degree > 1)
	{
		findNumber(number, degree - 1, result);
		*result *= number;
	}
	if (degree == 0 && number != 0)
	{
		*result = 1;
	}
}