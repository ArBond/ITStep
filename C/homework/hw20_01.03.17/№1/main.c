/*	Задание 1
	Написать программу, которая содержит функцию Action, принимающую в качестве
	аргумента, указатели на два массива(А и В) и размеры массивов, а также указатель на
	функцию.
	Пользователю отображается меню, в котором он может выбрать max, min, avg.
	Если выбран max - передается указатель на функцию, которая ищет максимум, если
	выбран min - передается указатель на функцию, которая ищет минимум, если выбран avg -
	передается указатель на функцию, которая ищет среднее.
	Возвращаемое значение функции Action результат выбора пользователя max, min, avg. */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE_A 5
#define ARRAY_SIZE_B 7

void fillArray(int* const array, int const* const arraySize);
void printArray(int const* const array, int const* const arraySize);
float findMaxElement(int const* const arrayA, int const* const arrayB, int const* const arraySizeA, int const* const arraySizeB);
float findMinElement(int const* const arrayA, int const* const arrayB, int const* const arraySizeA, int const* const arraySizeB);
float findAvgValue(int const* const arrayA, int const* const arrayB, int const* const arraySizeA, int const* const arraySizeB);
void printMenuAndChooseAction(int const* const arrayA, int const* const arrayB, int const* const arraySizeA, int const* const arraySizeB);

enum Action
{
	Begin,
	Max,
	Min,
	Avg,
	End
};

void main()
{
	srand(time(0));
	int arrayA[ARRAY_SIZE_A];
	int arrayB[ARRAY_SIZE_B];
	int arraySizeA = ARRAY_SIZE_A;
	int arraySizeB = ARRAY_SIZE_B;
	fillArray(arrayA, &arraySizeA);
	fillArray(arrayB, &arraySizeB);
	printf("Vash massiv 1:\n");
	printArray(arrayA, &arraySizeA);
	printf("\nMassiv 2:\n");
	printArray(arrayB, &arraySizeB);
	printMenuAndChooseAction(arrayA, arrayB, &arraySizeA, &arraySizeB);
}

void fillArray(int* const array, int const* const arraySize)
{
	for (int i = 0; i < *arraySize; i++)
	{
		*(array + i) = rand() % 11 - 5;
	}
}

void printArray(int const* const array, int const* const arraySize)
{
	for (int i = 0; i < *arraySize; i++)
	{
		printf(" %i ", *(array + i));
	}
}

void printMenuAndChooseAction(int const* const arrayA, int const* const arrayB, int const* const arraySizeA, int const* const arraySizeB)
{
	printf("\n\n %i - Max   %i - min   %i - Avg\n\n", Max, Min, Avg);
	enum Action selection;
	scanf("%i", &selection);
	while (selection <= Begin || selection >= End)
	{
		printf("No such item!\n");
		scanf("%i", &selection);
	}
	float(*action)() = findAvgValue;
	switch (selection)
	{
	case Max:
		action = findMaxElement;
		printf("Max: ");
		break;
	case Min:
		action = findMinElement;
		printf("Min: ");
		break;
	default:
		printf("Avg: ");
		break;
	}
	printf(selection == Avg ? "%.1f\n" : "%.0f\n", action(arrayA, arrayB, arraySizeA, arraySizeB));
}

float findMaxElement(int const* const arrayA, int const* const arrayB, int const* const arraySizeA, int const* const arraySizeB)
{
	int max = *arrayA;
	for (int i = 1; i < *arraySizeA; i++)
	{
		if (max < *(arrayA + i))
		{
			max = *(arrayA + i);
		}
	}
	for (int i = 0; i < *arraySizeB; i++)
	{
		if (max < *(arrayB + i))
		{
			max = *(arrayB + i);
		}
	}
	return (float)max;
}

float findMinElement(int const* const arrayA, int const* const arrayB, int const* const arraySizeA, int const* const arraySizeB)
{
	int min = *arrayA;
	for (int i = 1; i < *arraySizeA; i++)
	{
		if (min > *(arrayA + i))
		{
			min = *(arrayA + i);
		}
	}
	for (int i = 0; i < *arraySizeB; i++)
	{
		if (min > *(arrayB + i))
		{
			min = *(arrayB + i);
		}
	}
	return (float)min;
}

float findAvgValue(int const* const arrayA, int const* const arrayB, int const* const arraySizeA, int const* const arraySizeB)
{
	int sum = 0;
	for (int i = 0; i < *arraySizeA; i++)
	{
		sum += *(arrayA + i);
	}
	for (int i = 0; i < *arraySizeB; i++)
	{
		sum += *(arrayB + i);
	}
	float avarage = (float)sum / (*arraySizeA + *arraySizeB);
	return avarage;
}