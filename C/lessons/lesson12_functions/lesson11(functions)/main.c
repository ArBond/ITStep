#include <stdio.h>

enum Menu
{
	None,
	Add = 43,
	Deduct = 45,
	Multiply = 42,
	Divided = 47,
	Final
};

int add(int a, int b);
int deduct(int a, int b);
int multiply(int a, int b);
float divided(int a, int b);

int main()
{
	int a;
	int b;
	printf("Kalkuljator.\n\nDostupny tolko prostejshie arifmeticheskie dejstvija s celymi chislami.\n\n");
	printf(" chislo 1: ");
	scanf("%i", &a);
	char symbol;
	printf(" operacija: ");
	do {
		symbol = getchar();
	} while (symbol != '\n' && symbol != EOF);
	scanf("%c", &symbol);
	while (symbol != 42 && symbol != 43 && symbol != 45 && symbol != 47)
	{
		printf("Ne podderzhivaemaja operacija.\n");
		do {
			symbol = getchar();
		} while (symbol != '\n' && symbol != EOF);
		scanf("%c", &symbol);
	}
	printf(" chislo 2: ");
	scanf("%i", &b);
	while (b == 0)
	{
		printf("Na 0 delit' nelzja!\n");
		scanf("%i", &b);
	}
	enum Menu choice;
	choice = symbol;
	float result;
	switch (choice)
	{
	case Add:
		result = add(a, b);
		break;
	case Deduct:
		result = deduct(a, b);
		break;
	case Multiply:
		result = multiply(a, b);
		break;
	default:
		result = divided(a, b);
		break;
	}
	if (choice == 47)
	{
		printf("Rezultat = %.2f\n", result);
	}
	else
	{
		printf("Rezultat = %.0f\n", result);
	}
	return 0;
}

int add(int a, int b)
{
	return a + b;
}

int deduct(int a, int b)
{
	return a - b;
}

int multiply(int a, int b)
{
	return a * b;
}

float divided(int a, int b)
{
	return a / (float)b;
}