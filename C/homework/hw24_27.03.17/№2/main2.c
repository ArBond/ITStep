/*	Задание 2:
	Написать программу, которая хранит информацию об автомобиле(марка, модель, цвет
	(enum), тип топлива(enum) и год) в динамическом массиве.Пользователь определяет
	размерность массива и вводит 5 автомобилей.Реализовать возможность поиска всех
	автомобилей младше определенного года. */

#include <stdio.h>
#include <stdlib.h>

#define AUTOS 5

enum FuelsType
{
	BeginFuels,
	EndFuels
};

struct Autos
{
	char* mark;
	char* model;
	char* color;
	char* fuelType;
	char* year;
};

#define CHARACTERISTICS 5

char*** memoryAllocForStruct(int userLength)
{
	char*** autosStruct = malloc(AUTOS * 4);
	for (int i = 0; i < AUTOS; i++)
	{
		*(autosStruct + i) = malloc(CHARACTERISTICS * 4);
		for (int j = 0; j < CHARACTERISTICS; j++)
		{
			*(*(autosStruct + i) + j) = malloc(userLength);
		}
	}
	return autosStruct;
}

void freeMemoryStruct(char*** Autos, int userLength)
{
	for (int i = 0; i < AUTOS; i++)
	{
		for (int j = 0; j < CHARACTERISTICS; j++)
		{
			free(*(*(Autos + i) + j));
		}
	}
	for (int i = 0; i < AUTOS; i++)
	{
		free(*(Autos + i));
	}
	free(Autos);
}

void main()
{
	printf("How many bytes you want to alloc for characteristic description?\n");
	int userLength;
	scanf("%i", &userLength);
	while (userLength <= 0)
	{
		printf("Length cannot be 0 or less bytes!\n");
		scanf("%i", &userLength);
	}
	char*** Autos = memoryAllocForStruct(userLength);
	freeMemoryStruct(Autos, userLength);
}