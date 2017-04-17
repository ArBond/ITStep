/*	Задание 1:
	Написать программу, которая получает от пользователя количество дней измерений
	температуры (дата, температура), затем получает эти измерения и записывает их в
	динамический массив. Затем программа спрашивает еще несколько дней измерений и
	программа, используя realloc перевыделяет память. Вывести полученный массив на экран.
		Пример:
		1. Пользователь вводит количество дней – 5
		2. Программа выделяет динамический массив из 5 элементов
		3. Программа спрашивает еще количество дней – 3
		4. Программа перевыделяет динамический массив на 8 элементов (5+3) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DATE_LENGTH 10

struct Temperature
{
	char* Date;
	int Temperature;
};

void clearChar()
{
	char ch;
	do
	{
		ch = getchar();
	} while (ch != '\n' && ch != EOF);
}

void getTemperatures(struct Temperature* Days, int daysQuantity, int* posirionForRecording)
{
	for (int i = *posirionForRecording; i < daysQuantity; i++)
	{
		(Days + i)->Date = malloc(DATE_LENGTH);
		printf("Day %i: ", i + 1);
		clearChar();
		fgets((Days + i)->Date, DATE_LENGTH + 1, stdin);
		char* pointerOnEnterSymbol = strstr((Days + i)->Date, "\n");
		if (pointerOnEnterSymbol)
		{
			*pointerOnEnterSymbol = 0;
		}
		else
		{
			clearChar();
		}
		printf("Temperature(C): ");
		scanf("%i", &(Days + i)->Temperature);
	}
	*posirionForRecording = daysQuantity;
}

void printTemperatures(struct Temperature* Days, int daysQuantity)
{
	printf("Date(dd.mm.yyyy)\tTemperature(C)\n");
	for (int i = 0; i < daysQuantity; i++)
	{
		printf("%s\t\t%i\n", (Days + i)->Date, (Days + i)->Temperature);
	}
}

void freeStructMemory(struct Temperature* Days, int daysQuantity)
{
	for (int i = 0; i < daysQuantity; i++)
	{
		free((Days + i)->Date);
	}
	free(Days);
}

void main()
{
	int posirionForRecording = 0;
	printf("How many days you want to enter: ");
	int daysQuantity;
	scanf("%i", &daysQuantity);
	while (daysQuantity < 1)
	{
		printf("Days quantity can't be 0 or less!\n");
		scanf("%i", &daysQuantity);
	}
	struct Temperature* Days = malloc(daysQuantity * sizeof(struct Temperature));
	printf("Please enter date - dd.mm.yyyy.\n");
	getTemperatures(Days, daysQuantity, &posirionForRecording);

	while (true)
	{
		printf("Do you want to enter more days?\n 1 - yes\t0 - no\n");
		int toContinue;
		scanf("%i", &toContinue);
		while (toContinue < 0 || toContinue > 1)
		{
			printf("There is no such item!\n");
			scanf("%i", &toContinue);
		}
		if (toContinue == 0)
		{
			break;
		}
		printf("How many days you want to add: ");
		scanf("%i", &daysQuantity);
		while (daysQuantity < 1)
		{
			printf("Days quantity can't be 0 or less!\n");
			scanf("%i", &daysQuantity);
		}
		daysQuantity += posirionForRecording;
		Days = realloc(Days, daysQuantity * sizeof(struct Temperature));
		getTemperatures(Days, daysQuantity, &posirionForRecording);
	}

	printf("\nYour temperature list:\n");
	printTemperatures(Days, daysQuantity);
	freeStructMemory(Days, daysQuantity);
}