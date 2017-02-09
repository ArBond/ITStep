/* Задание 1
   Написать программу - калькулятор.Реализовать 4 основные арифметические действия над
   2 - мя целочисленными значениями, получаемыми от пользователя.Арифметическое
   действие задается путем введения с клавиатуры символов ‘ + ’, ‘ - ’, '/', '*'.    */


#include <stdio.h>

enum Operacion
{
	Add = 43,
	Deduct = 45,
	Multiply = 42,
	Divided = 47,
};

double count(int a, int b, enum Operacion selection);
void clean(char symbol);

int main()
{
	int a;
	int b;
	char symbol = 0;
	printf("Kalkuljator!\nDostupny tolko 4 prostejshih arifmeticheskih dejstvija\ns celymi chislami (do 1 mlrd).\n\n");
	printf("Chislo 1: ");
	scanf("%i", &a);
	clean(symbol);
	printf("Operacija: ");
	scanf("%c", &symbol);
	while (symbol != Add && symbol != Deduct && symbol != Multiply && symbol != Divided)
	{
		printf("Ne podderzhivaemaja operacija.\nOperacija: ");
		clean(symbol);
		scanf("%c", &symbol);
	}
	printf("Chislo 2: ");
	scanf("%i", &b);
	while (symbol == Divided && b == 0)
	{
		printf("Na 0 delit' nelzja.\nChislo 2: ");
		scanf("%i", &b);
	}
	enum Operacion selection = symbol;
	if (selection == Divided)
	{
		printf("Rezultat = %.3f\n", count(a, b, symbol));
	}
	else
	{
		printf("Rezultat = %.0f\n", count(a, b, symbol));
	}
	return 0;
}

double count(int a, int b, enum Operacion selection)
{
	switch (selection)
	{
	case Add:
		return a + b;
		break;
	case Deduct:
		return a - b;
		break;
	case Multiply:
		return a * (double)b;
		break;
	default:
		return a / (double)b;
		break;
	}
}

void clean(char symbol)
{
	do {
		symbol = getchar();
	} while (symbol != '\n' && symbol != EOF);
}