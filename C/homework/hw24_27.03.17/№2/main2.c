/*	Задание 2:
	Написать программу, которая хранит информацию об автомобиле(марка, модель, цвет
	(enum), тип топлива(enum) и год) в динамическом массиве.Пользователь определяет
	размерность массива и вводит 5 автомобилей.Реализовать возможность поиска всех
	автомобилей младше определенного года. */

#include <stdio.h>
#include <stdlib.h>

#define STRING_LENGTH 2000000

enum FuelsType
{
	BeginFuelsType,
	FuelsType95,
	FuelsType92,
	FuelsTypeDisel,
	FuelsTypeGas,
	EndFuelsType
};

enum Colors
{
	BeginColors,
	WhiteColor,
	YellowColor,
	RedColor,
	GrayColor,
	BlackColor,
	EndColors,
};

struct Cars
{
	char* mark;
	char* model;
	enum Colors color;
	enum FuelsType fuelType;
	int year;
};

char** allocMemoryForCarsStruct(int carCount)
{
	struct Cars** Cars = malloc(carCount * 4);
	for (int i = 0; i < carCount; i++)
	{
		*(Cars + i) = malloc(sizeof(struct Cars));
		(*(Cars + i))->mark = malloc(STRING_LENGTH);
		(*(Cars + i))->model = malloc(STRING_LENGTH);
	}
	return Cars;
}

void freeMemoryOfCarsStruct(struct Cars** Cars, int carCount)
{
	for (int i = 0; i < carCount; i++)
	{
		free((*(Cars + i))->mark);
		free((*(Cars + i))->model);
		free(*(Cars + i));
	}
	free(Cars);
}

void clearChar()
{
	char ch;
	do
	{
		ch = getchar();
	} while (ch != '\n' && ch != EOF);
}

void getСharacteristic(int* сategory, int beginEnum, int endEnum)
{

	scanf("%i", сategory);
	while (*сategory <= beginEnum || *сategory >= endEnum)
	{
		printf("There is no such item!\n");
		scanf("%i", сategory);
	}
}

void clearEnterSymbol(char* string)
{
	while (*string != 0)
	{
		if (*string == '\n')
		{
			*string = 0;
			return;
		}
		string++;
	}
}

void carsEntering(struct Cars** Cars, int carCount)
{
	for (int i = 0; i < carCount; i++)
	{
		clearChar();
		printf("Car %i:\nMark: ", i + 1);
		fgets((*(Cars + i))->mark, STRING_LENGTH, stdin);
		clearEnterSymbol((*(Cars + i))->mark);

		printf("Model: ");
		fgets((*(Cars + i))->model, STRING_LENGTH, stdin);
		clearEnterSymbol((*(Cars + i))->model);

		printf("Color: %i - white  %i - yellow  %i - red  %i - gray  %i - black\n", WhiteColor, YellowColor, RedColor, GrayColor, BlackColor);
		getСharacteristic(&(*(Cars + i))->color, BeginColors, EndColors);

		printf("Fuel type: %i - 95  %i - 92  %i - disel  %i - gas\n", FuelsType95, FuelsType92, FuelsTypeDisel, FuelsTypeGas);
		getСharacteristic(&(*(Cars + i))->fuelType, BeginFuelsType, EndFuelsType);
		
		printf("Year: ");
		scanf("%i", &(*(Cars + i))->year);
	}
}

void printCars(struct Cars** Cars, int carCount, int sortYear)
{
	printf("\tMark\tModel\tColor\tFuel\tYear\n");
	for (int i = 0; i < carCount; i++)
	{
		if ((*(Cars + i))->year > sortYear)
		{
			printf("Car %i\t", i + 1);
			printf("%s\t", (*(Cars + i))->mark);
			printf("%s\t", (*(Cars + i))->model);
			printf("%i\t", (*(Cars + i))->color);
			printf("%i\t", (*(Cars + i))->fuelType);
			printf("%i\n", (*(Cars + i))->year);
		}
	}
}

void main()
{
	printf("Haw many cars you want to enter?\n");
	int carCount;
	scanf("%i", &carCount);
	while (carCount < 1)
	{
		printf("Car quantity cannot be 0 or less");
		scanf("%i", &carCount);
	}
	struct Cars** Cars = allocMemoryForCarsStruct(carCount);
	carsEntering(Cars, carCount);
	printf("\n\t\t=======  Cars  =======\n");
	printCars(Cars, carCount, INT_MIN);
	int sortYear;
	printf("Please enter the year to sort the cars by that year: ");
	scanf("%i", &sortYear);
	printf("\n\t=======  Cars under the year %i  =======\n", sortYear);
	printCars(Cars, carCount, sortYear);
	freeMemoryOfCarsStruct(Cars, carCount);
}