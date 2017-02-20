/* Задание 2: Есть стопка оладий различного радиуса.Единственная операция, проводимая с
   ними - между любыми двумя суем лопатку и меняем порядок оладий над лопаткой на
   обратный.Необходимо за минимальное количество операций таких отсортировать снизу -
   вверх по убыванию радиуса. */


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

#define ARRAY_SIZE 9

void fillArray(int arr[], int arraySize);
void printArrayInGraphics(int arr[], int arraySize);
void turnOverElements(int arr[], int indexOfTopElementForCoup, int indexOfLowElementForCoup, int quantityOfElementsForCoup);
int analysisAndSortArray(int arr[], int arraySize);

int main()
{
	int arr[ARRAY_SIZE];
	fillArray(arr, ARRAY_SIZE);
	printf("Otsortiruem blinchiki?");
	printArrayInGraphics(arr, ARRAY_SIZE);
	printf("\n\nEnter - nachat' sortirovku blinchikov...\n");
	char toContinue;
	scanf("%c", &toContinue);
	printf("\n\nVy prervernuli blinchiki %i raz.", analysisAndSortArray(arr, ARRAY_SIZE));
	printf("\n\nPrijatnogo appetita! :)\n\n");
	return 0;
}

void fillArray(int arr[], int arraySize)
{
	srand(time(0));
	for (int i = 0; i < arraySize; i++)
	{
		int buffer = rand() % 9 + 1;
		int j = i;
		while (j > 0)
		{
			if (buffer == arr[j - 1])
			{
				j = i;
				buffer = rand() % 9 + 1;
			}
			else
			{
				j--;
			}
		}
		arr[i] = buffer;
	}
}

void printArrayInGraphics(int arr[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		printf("\n%i ", arr[i]);
		for (int j = 0; j < arraySize - arr[i]; j++)
		{
			printf(" ");
		}
		for (int j = 0; j < arr[i]; j++)
		{
			printf("**");
		}
	}
}

int analysisAndSortArray(int arr[], int arraySize)
{
	int coupCounter = 0;
	for (int i = arraySize - 1; i >= 0; i--)
	{
		int maxElement = arr[i];
		int indexOfMaxElement = i;
		for (int j = i - 1; j >= 0; j--)
		{
			int currentElement = arr[j];
			if (currentElement > maxElement)
			{
				maxElement = currentElement;
				indexOfMaxElement = j;
			}
		}
		if (indexOfMaxElement != i)
		{
			int indexOfTopElementForCoup = 0;
			int indexOfLowElementForCoup = indexOfMaxElement;
			int quantityOfElementsForCoup = indexOfMaxElement;
			if (indexOfMaxElement != 0)
			{
				turnOverElements(arr, indexOfTopElementForCoup, indexOfLowElementForCoup, quantityOfElementsForCoup);
				coupCounter++;
				system("cls");
				printArrayInGraphics(arr, arraySize);
				Sleep(1000);
			}
			indexOfLowElementForCoup = i;
			quantityOfElementsForCoup = i;
			turnOverElements(arr, indexOfTopElementForCoup, indexOfLowElementForCoup, quantityOfElementsForCoup);
			coupCounter++;
			system("cls");
			printArrayInGraphics(arr, arraySize);
			Sleep(1000);
		}
	}
	return coupCounter;
}

void turnOverElements(int arr[], int indexOfTopElementForCoup, int indexOfLowElementForCoup, int quantityOfElementsForCoup)
{
	for (int j = 0; j < (quantityOfElementsForCoup + 1) / 2; j++)
	{
		int buffer = arr[indexOfTopElementForCoup];
		arr[indexOfTopElementForCoup] = arr[indexOfLowElementForCoup];
		arr[indexOfLowElementForCoup] = buffer;
		indexOfTopElementForCoup++;
		indexOfLowElementForCoup--;
	}
}