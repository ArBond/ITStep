//  разобрать для себя

//#include <string.h>
//
//#define STRUCT_SIZE 5
//
//union Data
//{
//	int valueInt;
//	float valueFloat;
//	char valueStr[10];
//};
//
//struct DataItem
//{
//	enum valueType type;
//	union Data data;
//};
//
//void main()
//{
//	struct DataItem values[STRUCT_SIZE];
//	for (int i = 0; i < STRUCT_SIZE; i++)
//	{
//
//	}
//}





//              ДИНАМИЧЕСКАЯ  ПАМЯТЬ

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <Windows.h>

#define BOOKS 3

void main()
{
	char** books = malloc(BOOKS * sizeof(char*));

	for (int i = 0; i < BOOKS; i++)
	{
		*(books + i) = malloc(2000 * sizeof(char));
	}

	for (int i = 0; i < BOOKS; i++)
	{
		printf("Book %i: ", i + 1);
		fgets(*(books + i), 2000, stdin);
	}

	for (int i = 0; i < BOOKS; i++)
	{
		printf("Book %i: ", i + 1);
		printf("%s", *(books + i));
		free(*(books + i));
	}
	free(books);
	system("pause");
}
