/* Задание 1: В одномерном массиве, заполненном случайными числами, определить
   минимальный и максимальный элементы. */


#include <stdio.h>
#include <time.h>

#define MAS_SIZE 10

void fillAndPrintArray(int mas[], int masSize);
int findMaxElement(int mas[], int masSize);
int findMinElement(int mas[], int masSize);

int main()
{
	int mas[MAS_SIZE];
	srand(time(0));
	printf("Vash massiv:\n");
	fillAndPrintArray(mas, MAS_SIZE);
	printf("\nMax element: %i\n", findMaxElement(mas, MAS_SIZE));
	printf("Min element: %i\n", findMinElement(mas, MAS_SIZE));
	return 0;
}

void fillAndPrintArray(int mas[], int masSize)
{
	for (int i = 0; i < MAS_SIZE; i++)
	{
		mas[i] = rand() % 50;
		printf("%i\n", mas[i]);
	}
}

int findMaxElement(int mas[], int masSize)
{
	int max = mas[0];
	for (int i = 1; i < masSize; i ++)
	{
		if (max < mas[i])
		{
			max = mas[i];
		}
	}
	return max;
}

int findMinElement(int mas[], int masSize)
{
	int min = mas[0];
	for (int i = 1; i < masSize; i ++)
	{
		if (min > mas[i])
		{
			min = mas[i];
		}
	}
	return min;
}