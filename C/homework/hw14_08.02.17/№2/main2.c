/* Задание 2:
   Написать программу, копирующую последовательно элементы одного массива размером
   10 элементов в 2 массива размером 5 элементов каждый. */


#include <stdio.h>

#define SIZE_OF_PRIMORDIAL_ARR 10
#define SIZE_OF_NEW_ARR 5

// использовал 1 функцию для печатания всех массивов
void printArray(int array[], int arrSize);
void copyInNewArrays(int array[], int firstNewArray[], int secondNewArray[], int arrSize);

int main()
{
	int primordialArray[SIZE_OF_PRIMORDIAL_ARR] = { 1, 2, 3, 4, 5, 5, 4, 3, 2, 1 };
	printf("Iznachal'nyj massiv:\n");
	printArray(primordialArray, SIZE_OF_PRIMORDIAL_ARR);
	int firstNewArray[SIZE_OF_NEW_ARR];
	int secondNewArray[SIZE_OF_NEW_ARR];
	copyInNewArrays(primordialArray, firstNewArray, secondNewArray, SIZE_OF_NEW_ARR);
	printf("Novyj massiv #1:\n");
	printArray(firstNewArray, SIZE_OF_NEW_ARR);
	printf("Novyj massiv #2:\n");
	printArray(secondNewArray, SIZE_OF_NEW_ARR);
	return 0;
}

void printArray(int array[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		printf("%i\n", array[i]);
	}
}

void copyInNewArrays(int array[], int firstNewArray[], int secondNewArray[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		firstNewArray[i] = array[i];
		secondNewArray[i] = array[i + 5];
	}
}