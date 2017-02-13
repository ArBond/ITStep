//            СОРТИРОВКА ВСТВКАМИ

//#include <stdio.h>
//#include <time.h>
//
//#define MAS_SIZE 10
//
//void fillArray(int mas[], int masSize);
//void printArray(int mas[], int masSize);
//void pasteSortOfArray(int mas[], int masSize);
//
//int main()
//{
//	int mas[MAS_SIZE];
//	srand(time(0));
//	fillArray(mas, MAS_SIZE);
//	printf("Vash massiv:\n");
//	printArray(mas, MAS_SIZE);
//	pasteSortOfArray(mas, MAS_SIZE);
//	printf("Vash massiv posle sortirovki:\n");
//	printArray(mas, MAS_SIZE);
//	return 0;
//}
//
//void fillArray(int mas[], int masSize)
//{
//	for (int i = 0; i < masSize; i++)
//	{
//		mas[i] = rand() % 20 + 1;
//	}
//}
//
//void printArray(int mas[], int masSize)
//{
//	for (int i = 0; i < MAS_SIZE; i++)
//	{
//		printf("%i ", mas[i]);
//	}
//}
//
//void pasteSortOfArray(int mas[], int masSize)
//{
//	for (int i = 0; i < MAS_SIZE - 1; i++)
//	{
//		if (mas[i + 1] < mas[i])
//		{
//			int j = i + 1;
//			int buffer = mas[i + 1];
//			while (j >= 0)
//			{
//				if (buffer < mas[j - 1])
//				{
//					mas[j] = mas[j - 1];
//					j--;
//				}
//				else
//				{
//					mas[j] = buffer;
//					break;
//				}
//			}
//		}
//	}
//}





//          СОРТИРОВКА  ВЫБОРОМ

//#include <stdio.h>
//
//#define ARRAY_SIZE 5
//
//void printArray(int mas[], int masSize);
//
//int main()
//{
//	int mas[ARRAY_SIZE] = { 4, 1, 6, 2, 3 };
//	printf("Vash massiv:\n");
//	printArray(mas, ARRAY_SIZE);
//	for (int i = 0; i < ARRAY_SIZE - 1; i++)
//	{
//		int idxOfMinElement = i;
//		int minElement = mas[i];
//		for (int j = i + 1; j < ARRAY_SIZE; j++)
//		{
//			int currentElement = mas[j];
//			if (minElement > currentElement)
//			{
//				idxOfMinElement = j;
//				minElement = currentElement;
//			}
//		}
//		if (idxOfMinElement != i)
//		{
//			int buffer = mas[idxOfMinElement];
//			mas[idxOfMinElement] = mas[i];
//			mas[i] = buffer;
//		}
//	}
//	printf("Vash massiv posle sortirovki:\n");
//	printArray(mas, ARRAY_SIZE);
//	return 0;
//}
//
//void printArray(int mas[], int masSize)
//{
//	for (int i = 0; i < ARRAY_SIZE; i++)
//	{
//		printf("%i\n", mas[i]);
//	}
//}



//          СОРТИРОВКА  ВЫБОРОМ  В  ОБРАТНОМ  ПОРЯДКЕ

#include <stdio.h>

#define ARRAY_SIZE 5

void printArray(int mas[], int masSize);
void selectionSortOfArray(int mas[], int masSize, enum Direction sortTipe);

enum Direction
{
	Ascending = 1,
	Descending
};

int main()
{
	int mas[ARRAY_SIZE] = { 4, 1, 6, 2, 3 };
	printf("Vash massiv:\n");
	printArray(mas, ARRAY_SIZE);
	enum Direction choice;
	printf("Kak hotite otsortirovat' massiv?\n %i - Ascending    %i - Descending\n", Ascending, Descending);
	scanf("%i", &choice);
	selectionSortOfArray(mas, ARRAY_SIZE, choice);
	printf("Vash massiv posle sortirovki:\n");
	printArray(mas, ARRAY_SIZE);
	return 0;
}

void printArray(int mas[], int masSize)
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%i\n", mas[i]);
	}
}

void selectionSortOfArray(int mas[], int masSize, enum Direction sortTipe)
{
	for (int i = 0; i < ARRAY_SIZE - 1; i++)
	{
		int idxOfMinElement = i;
		int minElement = mas[i];
		for (int j = i + 1; j < ARRAY_SIZE; j++)
		{
			if (sortTipe = Ascending)
			{
				int currentElement = mas[j];
				if (minElement > currentElement)
				{
					idxOfMinElement = j;
					minElement = currentElement;
				}
			}
			else
			{
				int currentElement = mas[j];
				if (minElement < currentElement)
				{
					idxOfMinElement = j;
					minElement = currentElement;
				}
			}
		}
		if (idxOfMinElement != i)
		{
			int buffer = mas[idxOfMinElement];
			mas[idxOfMinElement] = mas[i];
			mas[i] = buffer;
		}
	}
}
