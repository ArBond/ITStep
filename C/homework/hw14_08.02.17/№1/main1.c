/* Задание 1:
   В одномерном массиве, состоящем из N вещественных чисел вычислить :
     • Сумму отрицательных элементов
     • Произведение элементов, находящихся между min и max элементами
     • Произведение элементов с четными номерами
     • Сумму элементов, находящихся между первым и последним отрицательными
   элементами. */


#include <stdio.h>

void printfArray(float mas[], int masSize);
float calculateTheSumOfNegativeElements(float mas[], int masSize);
float calculateTheIncreaseOfElementsBetweenMinAndMax(float mas[], int masSize);
float calculateTheIncreaseOfEvenElements(float mas[], int masSize);
float calculateTheSumOfElementsBetweenFirstAndLastNegativeElements(float mas[], int masSize);

int main()
{
	float mas[] = { 5.3, -4.25, 0.27, 9.13, -7.39, -21.2, 18.6, -0.1, 2.88, -5.52 };
	int masSize = sizeof(mas) / sizeof(float);
	printf("Vash massiv:\n");
	printfArray(mas, masSize);
	printf("\nSumma otricatelnyh elementov = %.2f\n", calculateTheSumOfNegativeElements(mas, masSize));
	printf("Proizvedenije elementov, nahodjashihsja mezhdu min i max elementami = %.2f\n", calculateTheIncreaseOfElementsBetweenMinAndMax(mas, masSize));
	printf("Proizvedenije elementov s chetnymi nomerami = %.2f\n", calculateTheIncreaseOfEvenElements(mas, masSize));
	printf("Summa elementov, nahodjashihsja mezhdu pervym i poslednim otricatelnymi elementami = %.2f\n", calculateTheSumOfElementsBetweenFirstAndLastNegativeElements(mas, masSize));
	return 0;
}

void printfArray(float mas[], int masSize)
{
	for (int i = 0; i < masSize; i++)
	{
		printf("#%i: %.2f\n", i + 1, mas[i]);
	}
}

float calculateTheSumOfNegativeElements(float mas[], int masSize)
{
	float sum = 0;
	for (int i = 0; i < masSize; i++)
	{
		if (mas[i] < 0)
		{
			sum += mas[i];
		}
	}
	return sum;
}

float calculateTheIncreaseOfElementsBetweenMinAndMax(float mas[], int masSize)
{
	int indexOfMaxElement = 0;
	int indexOfMinElement = 0;
	for (int i = 0; i < masSize; i++)
	{
		if (mas[indexOfMaxElement] < mas[i])
		{
			indexOfMaxElement = i;
		}
		if (mas[indexOfMinElement] > mas[i])
		{
			indexOfMinElement = i;
		}
	}
	if (indexOfMaxElement - indexOfMinElement > -2 && indexOfMaxElement - indexOfMinElement < 2)  // (" индексы равны или отличаются на еденицу? ")
	{
		return 0;
	}
	if (indexOfMinElement > indexOfMaxElement)
	{
		int buffer = indexOfMaxElement;
		indexOfMaxElement = indexOfMinElement;
		indexOfMinElement = buffer;
	}
	float increase = 1;
	for (int i = indexOfMinElement + 1; i < indexOfMaxElement; i++)
	{
		increase *= mas[i];
	}
	return increase;
}

float calculateTheIncreaseOfEvenElements(float mas[], int masSize)
{
	if (masSize == 1)
	{
		return 0;
	}
	float increase = 1;
	for (int i = 1; i < masSize; i += 2)
	{
		increase *= mas[i];
	}
	return increase;
}

float calculateTheSumOfElementsBetweenFirstAndLastNegativeElements(float mas[], int masSize)
{
	int indexOfFirstNegativeElements = 0;
	for (int i = 0; i < masSize; i++)
	{
		if (mas[i] < 0)
		{
			indexOfFirstNegativeElements = i;
			break;
		}
	}
	int indexOfLastNegativeElements = 0;
	for (int i = masSize - 1; i >= 0; i--)
	{
		if (mas[i] < 0)
		{
			indexOfLastNegativeElements = i;
			break;
		}
	}
	float sum = 0;
	for (int i = indexOfFirstNegativeElements + 1; i < indexOfLastNegativeElements; i++)
	{
		sum += mas[i];
	}
	return sum;
}