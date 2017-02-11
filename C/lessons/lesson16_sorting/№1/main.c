////        сортировка пузырьком
//
//#include <stdio.h>
//#include <time.h>
//
//#define MAS_SIZE1 10
//
//void printMas(int mas[], int size);
//void fillMas(int mas[], int size);
//int bubleSort(int mas[], int size);
//
//// Добавить через енамы массив состоящий из счетчика перестановок и счетчика проверок
//
//int main()
//{
//	int mas[MAS_SIZE1];
//	fillMas(mas, MAS_SIZE1);
//	printf("Massiv do sortirovki:\n");
//	printMas(mas, MAS_SIZE1);
//	printf("\nKolichestvo perestanovok v mssive = %i\n", bubleSort(mas, MAS_SIZE1));
//	printf("\nMassiv posle sortirovki:\n");
//	printMas(mas, MAS_SIZE1);
//	return 0;
//}
//
//void printMas(int mas[], int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		printf("%i\n", mas[i]);
//	}
//}
//
//void fillMas(int mas[], int size)
//{
//	srand(time(0));
//	for (int i = 0; i < size; i++)
//	{
//		mas[i] = rand() % 20 + 1;
//	}
//}
//
//int bubleSort(int mas[], int size)
//{
//	int shiftCount = 0;
//	for (int i = 0; i < size - 1; i++)
//	{
//		for (int j = 0; j < size - 1 - i; j++)
//		{
//			int firstElement = mas[j];
//			int secondElement = mas[j + 1];
//			if (firstElement > secondElement)
//			{
//				int buffer = firstElement;
//				mas[j] = secondElement;
//				mas[j + 1] = buffer;
//				shiftCount++;
//			}
//		}
//	}
//	return shiftCount;
//}






//      Сортировка вставками

#include <stdio.h>
#include <time.h>

#define MAS_SIZE1 15

void printMas(int mas[], int size);
void fillMas(int mas[], int size);
int pasteSort(int mas[], int size);

// Добавить через енамы массив состоящий из счетчика перестановок и счетчика проверок

int main()
{
	int mas[MAS_SIZE1];
	fillMas(mas, MAS_SIZE1);
	printf("Massiv do sortirovki:\n");
	printMas(mas, MAS_SIZE1);
	printf("\nKolichestvo perestanovok v mssive = %i\n", pasteSort(mas, MAS_SIZE1));
	printf("\nMassiv posle sortirovki:\n");
	printMas(mas, MAS_SIZE1);
	return 0;
}

void printMas(int mas[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%i\n", mas[i]);
	}
}

void fillMas(int mas[], int size)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		mas[i] = rand() % 20 + 1;
	}
}

int pasteSort(int mas[], int size)
{
	int shiftCount = 0;
	for (int i = 0; i < size - 1; i++)
	{
		if (mas[i] > mas[i + 1])
		{
			int buffer = mas[i];
			mas[i] = mas[i + 1];
			mas[i + 1] = buffer;
			shiftCount++;
			int j = i;
			while (j > 0 && mas[j] < mas[j - 1])
			{
				int buffer = mas[j];
				mas[j] = mas[j - 1];
				mas[j - 1] = buffer;
				j--;
				shiftCount++;
			}
		}
	}
	return shiftCount;
}