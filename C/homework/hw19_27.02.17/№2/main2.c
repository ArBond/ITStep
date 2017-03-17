/* Задание 2
   Написать программу, которая содержит функцию, принимающую в качестве аргумента,
   указатели на три массива и размер массивов.Функция заносит в массив C суммы
   элементов массивов А и В.Размер массивов одинаковый. */


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 3
#define COLUMN 5

void fillMatrixByRandomElements(int* const matrix, int const* const quantityOfElements);
void printMatrix(int const* const matrix, int const* const row, int const* const col);
void fillThirdMatrix(int const* const matrixA, int const* const matrixB, int* const matrixC, int const* const quantityOfElements);

void main()
{
	srand(time(0));
	int matrixA[ROW][COLUMN];
	int matrixB[ROW][COLUMN];
	int row = ROW;
	int col = COLUMN;
	int quantityOfElements = ROW * COLUMN;
	fillMatrixByRandomElements((int*)matrixA, &quantityOfElements);
	fillMatrixByRandomElements((int*)matrixB, &quantityOfElements);
	printf("Vasha matrica 1:\n");
	printMatrix((int*)matrixA, &row, &col);
	printf("\nMatrica 2:\n");
	printMatrix((int*)matrixB, &row, &col);
	int matrixC[ROW][COLUMN];
	fillThirdMatrix((int*)matrixA, (int*)matrixB, (int*)matrixC, &quantityOfElements);
	printf("\nZanosim summy elementov v matricu 3...\n\nVot chto poluchilos':\n");
	printMatrix((int*)matrixC, &row, &col);
	printf("\n");
}

void fillMatrixByRandomElements(int* const matrix, int const* const quantityOfElements)
{
	for (int i = 0; i < *quantityOfElements; i++)
	{
		*(matrix + i) = rand() % 11 - 5;
	}
}

void printMatrix(int const* const matrix, int const* const row, int const* const col)
{
	for (int i = 0; i < *row; i++)
	{
		for (int j = 0; j < *col; j++)
		{
			printf(" %i\t", *(matrix + i * *col + j));
		}
		printf("\n");
	}
}

void fillThirdMatrix(int const* const matrixA, int const* const matrixB, int* const matrixC, int const* const quantityOfElements)
{
	for (int i = 0; i < *quantityOfElements; i++)
	{
		*(matrixC + i) = *(matrixA + i) + *(matrixB + i);
	}
}