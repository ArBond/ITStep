/* Задание 2: Пользователь вводит прибыль фирмы за год(12 месяцев).Затем пользователь
   вводит диапазон(например, 3 и 6 – поиск между 3 - м и 6 - м месяцем).Необходимо
   определить месяц, в котором прибыль была максимальна и месяц, в котором прибыль
   была минимальна с учетом выбранного диапазона. */


#include <stdio.h>

#define MAS_SIZE 12

void fillArry(int mas[], int masSize);
int findMonthWithMaxIncome(int mas[], int lowBorder, int topBorder);
int findMonthWithMinIncome(int mas[], int lowBorder, int topBorder);

int main()
{
	int mas[MAS_SIZE];
	printf("Vvedite pribyl' firmy za god (pomesjachno):\n");
	fillArry(mas, MAS_SIZE);
	printf("Vvedite diapazon issleduemyh mesjacev:\nlow: ");
	int lowBorder;
	scanf("%i", &lowBorder);
	while (lowBorder > 12 || lowBorder < 1)
	{
		printf("Takogo mesjacs net!\nlow: ");
		scanf("%i", &lowBorder);
	}
	int topBorder;
	printf("top: ");
	scanf("%i", &topBorder);
	while (topBorder > 12 || topBorder < 1)
	{
		printf("Takogo mesjacs net!\ntop: ");
		scanf("%i", &topBorder);
	}
	if (lowBorder > topBorder)
	{
		int choice;
		printf("Vozmpzhno %i - %i?\n 1 - da\n 0 - net\n", topBorder, lowBorder);
		do
		{
			scanf("%i", &choice);
		} while (choice > 1 || choice < 0);
		if (choice == 0)
		{
			printf("Error!\n");
			return 1;
		}
		else
		{
			int buffer = lowBorder;
			lowBorder = topBorder;
			topBorder = buffer;
		}
	}
	printf("Min pribyl' byla v %i mecjace.\n", findMonthWithMinIncome(mas, lowBorder, topBorder));
	printf("Max pribyl' byla v %i mecjace.\n", findMonthWithMaxIncome(mas, lowBorder, topBorder));
	return 0;
}

void fillArry(int mas[], int masSize)
{
	for (int i = 0; i < masSize; i++)
	{
		printf("%i mesjac: ", i + 1);
		scanf("%i", &mas[i]);
	}
}

int findMonthWithMinIncome(int mas[], int lowBorder, int topBorder)
{
	int MonthWithMinIncome = lowBorder;
	for (int i = lowBorder; i < topBorder; i++)
	{
		if (mas[MonthWithMinIncome - 1] > mas[i])
		{
			MonthWithMinIncome = i + 1;
		}
	}
	return MonthWithMinIncome;
}

int findMonthWithMaxIncome(int mas[], int lowBorder, int topBorder)
{
	int MonthWithMaxIncome = lowBorder;
	for (int i = lowBorder; i < topBorder; i++)
	{
		if (mas[MonthWithMaxIncome - 1] < mas[i])
		{
			MonthWithMaxIncome = i + 1;
		}
	}
	return MonthWithMaxIncome;
}