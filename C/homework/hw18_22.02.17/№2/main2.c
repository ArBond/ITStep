/* Задание 2:
   Используя указатель на массив целых чисел, изменить порядок следования элементов
   массива на противоположный.Использовать в программе арифметику указателей для
   продвижения по массиву, а также оператор разыменования. */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 9

void fillArray(int* array, int* arraySize);
void printArray(int* array, int* arraySize);
void reverseArray(int* array, int* arraySize);

int main()
{
	srand(time(0));
	int array[ARRAY_SIZE];
	int arraySize = ARRAY_SIZE;
	fillArray(&array, &arraySize);
	printf("Vash Massiv:\n");
	printArray(&array, &arraySize);
	reverseArray(&array, &arraySize);
	printf("\nReversiruem massiv...\n\nVot chto poluchilos:\n");
	printArray(&array, &arraySize);
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

void reverseArray(int* array, int* arraySize)
{
	for (int i = 0; i < *arraySize / 2; i++)
	{
		int buffer = *(array + i);
		*(array + i) = *(array + *arraySize - 1 - i);
		*(array + *arraySize - 1 - i) = buffer;
	}
}