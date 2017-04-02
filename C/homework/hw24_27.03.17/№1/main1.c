/*	Задание 1:
	Написать программу, которая дает пользователю ввести 5 фамилий студентов и хранит их
	в динамическом массиве, а затем сортирует их по возрастанию. */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define	STUDENTS 5
#define STRING_LENGTH 50

void sort(char** elements, int quantity)
{
	for (int i = 0; i < quantity - 1; i++)
	{
		for (int j = 0; j < quantity - 1 - i; j++)
		{
			if (strcmp(*(elements + j), *(elements + j + 1)) > 0)
			{
				char* buffer = *(elements + j);
				*(elements + j) = *(elements + j + 1);
				*(elements + j + 1) = buffer;
			}
		}
	}
}

void enteringElement(char** elements, int quantity)
{
	for (int i = 0; i < quantity; i++)
	{
		do
		{
			printf("#%i: ", i + 1);
			fgets(*(elements + i), STRING_LENGTH, stdin);
		} while (**(elements + i) == '\n');
	}
}

void printElements(char** elements, int quantity)
{
	for (int i = 0; i < quantity; i++)
	{
		printf("#%i: %s", i + 1, *(elements + i));
	}
}

char** allocList(int quantity)
{
	char** elements = malloc(quantity * 4);
	for (int i = 0; i < quantity; i++)
	{
		*(elements + i) = malloc(STRING_LENGTH);
	}
	return elements;
}

void freeList(char** elements, int quantity)
{
	for (int i = 0; i < quantity; i++)
	{
		free(*(elements + i));
	}
	free(elements);
}

void main()
{
	char** elements = allocList(STUDENTS);
	printf("Please enter %i surnames:\n", STUDENTS);
	enteringElement(elements, STUDENTS);
	sort(elements, STUDENTS);
	printf("Your surnames:\n");
	printElements(elements, STUDENTS);
	freeList(elements, STUDENTS);
}