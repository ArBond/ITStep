/* Задание 1:
   Используя два указателя на массив целых чисел, скопировать один массив в другой.
   Использовать в программе арифметику указателей для продвижения по массиву, а также
   оператор разыменования. */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 9

void fillArray(int* array, int* arraySize);
void printArray(int* array, int* arraySize);
void copyArray(int* startArray, int* finalArray, int* arraySize);

int main()
{
	srand(time(0));
	int startArray[ARRAY_SIZE];
	int arraySize = ARRAY_SIZE;
	fillArray(&startArray, &arraySize);
	printf("Vash Massiv:\n");
	printArray(&startArray, &arraySize);
	int finalArray[ARRAY_SIZE];
	copyArray(&startArray, &finalArray, &arraySize);
	printf("\nCopiruem...\n\nVash novyj massiv:\n");
	printArray(&finalArray, &arraySize);
	return 0;
}

void fillArray(int* array, int* arraySize)
{
	for (int i = 0; i < *arraySize; i++)
	{
		*(array + i) = rand() % 10;
	}
}

void printArray(int* array, int* arraySize)
{
	for (int i = 0; i < *arraySize; i++)
	{
		printf("#%i = %i\n", i + 1, *(array + i));
	}
}

void copyArray(int* startArray, int* finalArray, int* arraySize)
{
	for (int i = 0; i < *arraySize; i++)
	{
		*(finalArray + i) = *(startArray + i);
	}
}