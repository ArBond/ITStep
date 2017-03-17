/* Задание 1
   Написать функцию, которая получает указатель на статический двумерный массив(3x5) и
   его размер.Функция распределяет положительные, отрицательные и нулевые элементы в
   3 отдельных массива, указатели на которые также переданы в функцию. */



// не знаю, можно ли так делать, как я сделал ниже, но мне показалось что я неплохо оптимизировал программу
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 3
#define COLUMN 5

void fillMatrixByRandomElements(int* const matrix, int const* const quantityOfElements);
void printMatrix(int const* const matrix, int const* const quantityOfElements);
void spreadElements(int const* const mainMatrix, int* const matrixOfNullElements, int* const matrixOfPosElements, int* const matrixOfNegElements, int const* const quantityOfElements,
	int* const counterOfNullElements, int* const counterOfPosElements, int* const counterOfNegElements);

void main()
{
	srand(time(0));
	int mainMatrix[ROW][COLUMN];
	int quantityOfElements = ROW * COLUMN;
	fillMatrixByRandomElements((int*)mainMatrix, &quantityOfElements);
	printf("Vasha matrica:\n");
	printMatrix((int*)mainMatrix, &quantityOfElements);
	int matrixOfNullElements[ROW][COLUMN];
	int matrixOfPosElements[ROW][COLUMN];
	int matrixOfNegElements[ROW][COLUMN];
	int counterOfNullElements = 0;
	int counterOfPosElements = 0;
	int counterOfNegElements = 0;
	spreadElements((int*)mainMatrix, (int*)matrixOfNullElements, (int*)matrixOfPosElements, (int*)matrixOfNegElements, &quantityOfElements,
		&counterOfNullElements, &counterOfPosElements, &counterOfNegElements);
	printf("\nMatrica nulevyh elementov:\n");
	printMatrix((int*)matrixOfNullElements, &counterOfNullElements);
	printf("\nMatrica polozhitel'nyh elementov:\n");
	printMatrix((int*)matrixOfPosElements, &counterOfPosElements);
	printf("\nMatrica otricatel'nyh elementov:\n");
	printMatrix((int*)matrixOfNegElements, &counterOfNegElements);
	printf("\n");
}

void fillMatrixByRandomElements(int* const matrix, int const* const quantityOfElements)
{
	for (int i = 0; i < *quantityOfElements; i++)
	{
		*(matrix + i) = rand() % 7 - 3;
	}
}

void printMatrix(int const* const matrix, int const* const quantityOfElements)
{
	for (int i = 0; i < *quantityOfElements; i++)
	{
		printf(" %i\t", *(matrix + i));
		if ((i + 1) % COLUMN == 0)
		{
			printf("\n");
		}
	}
}

void spreadElements(int const* const mainMatrix, int* const matrixOfNullElements, int* const matrixOfPosElements, int* const matrixOfNegElements, int const* const quantityOfElements,
	int* const counterOfNullElements, int* const counterOfPosElements, int* const counterOfNegElements)
{
	for (int i = 0; i < *quantityOfElements; i++)
	{
		if (*(mainMatrix + i) > 0)
		{
			*(matrixOfPosElements + *counterOfPosElements) = *(mainMatrix + i);
			(*counterOfPosElements)++;
		}
		else if (*(mainMatrix + i) < 0)
		{
			*(matrixOfNegElements + *counterOfNegElements) = *(mainMatrix + i);
			(*counterOfNegElements)++;
		}
		else
		{
			*(matrixOfNullElements + *counterOfNullElements) = *(mainMatrix + i);
			(*counterOfNullElements)++;
		}
	}
}