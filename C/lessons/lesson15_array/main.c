//                Передача массива в функцию
//  sublime


//#include <stdio.h>
//
//void printArray(int mas[], int masCount);
//
//int main()
//{
//	int mas[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 7, 6, 5, 4, 3, 2, 1 };
//	int const masCount = sizeof(mas) / sizeof(int);
//	printArray(mas, masCount);
//	return 0;
//}
//
//void printArray(int mas[], int masCount)
//{
//	for (int i = 0; i < masCount; i++)
//	{
//		printf("mas[%i] = %i\n", i, mas[i]);
//	}
//}



//#include <stdio.h>
//
//void enterArray(int mas[]);
//void printNotNullElement(int mas[]);
//
//int main()
//{
//	int mas[10];
//	printf("Vvedite 10 elementov masuva.\n");
//	enterArray(mas);
//	printf("Ne nulevye elementy massiva:\n");
//	printNotNullElement(mas);
//	return 0;
//}
//
//void enterArray(int mas[])
//{
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%i element massiva: ", i + 1);
//		scanf("%i", &mas[i]);
//	}
//}
//
//void printNotNullElement(int mas[])
//{
//	for (int i = 0; i < 10; i++)
//	{
//		if (mas[i] != 0)
//		{
//			printf("#%i) %i\n", i + 1, mas[i]);
//		}
//	}
//}


//#include <stdio.h>
//
//void fillArray(int mas[]);
//int findAverageValue(int mas[]);
//
//int main()
//{
//	int mas[10];
//	srand(time(0));
//	fillArray(mas);
//	printf("Srednee arifmeticheskoe bez max i min = %.2f", findAverageValue(mas) / 8.0);
//	return 0;
//}
//
//void fillArray(int mas[])
//{
//	for (int i = 0; i < 10; i++)
//	{
//		mas[i] = rand() % 11 - 5;
//		int j = 0;
//		while (j < i)
//		{
//			if (mas[i] == mas[j])
//			{
//				mas[i] = rand() % 10 - 5;
//				j = 0;
//			}
//			else
//			{
//				j++;
//			}
//		}
//		printf("%i\n", mas[i]);
//	}
//}
//
//int findAverageValue(int mas[])
//{
//	int maxElement = mas[0];
//	int minElement = mas[0];
//	int total = 0;
//	for (int i = 1; i < 10; i++)
//	{
//		if (mas[i] > maxElement)
//		{
//			maxElement = mas[i];
//		}
//		if (mas[i] < minElement)
//		{
//			minElement = mas[i];
//		}
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		if (mas[i] != maxElement && mas[i] != minElement)
//		{
//			total += mas[i];
//		}
//	}
//	return total;
//}


#include <stdio.h>

void enterArray(int mas[]);
void printReversArray(int mas[]);

int main()
{
	int mas[10];
	printf("Vvedite 10 elementov massiva:\n");
	enterArray(mas);
	printf("A vot onu v obratnim porjadke:\n");
	printReversArray(mas);
	return 0;
}

void enterArray(int mas[])
{
	int count = 9;
	for (int i = 0; i < 10; i++)
	{
		printf("#%i: ", i + 1);
		scanf("%i", &mas[i + count]);
		count -= 2;
	}
}

void printReversArray(int mas[])
{
	for (int i = 0; i < 10; i++)
	{
		printf("#%i = %i\n", i + 1, mas[i]);
	}
}