//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//void sort(char** elements, int quantity)
//{
//	for (int i = 0; i < quantity - 1; i++)
//	{
//		for (int j = 0; j < quantity - 1 - i; j++)
//		{
//			if (strcmp(*(elements + j), *(elements + j + 1)) > 0)
//			{
//				char* buffer = *(elements + j);
//				*(elements + j) = *(elements + j + 1);
//				*(elements + j + 1) = buffer;
//			}
//		}
//	}
//}
//
//void enteringElement(char** elements, int quantity)
//{
//	for (int i = 0; i < quantity; i++)
//	{
//		do
//		{
//			printf("#%i: ", i + 1);
//			fgets(*(elements + i), 50, stdin);
//		} while (**(elements + i) == '\n');
//	}
//}
//
//void printElements(char** elements, int quantity)
//{
//	for (int i = 0; i < quantity; i++)
//	{
//		printf("#%i: %s", i + 1, *(elements + i));
//	}
//}
//
//char** allocList(int quantity)
//{
//	char** elements = malloc(quantity * 4);
//	for (int i = 0; i < quantity; i++)
//	{
//		*(elements + i) = malloc(500000);
//	}
//	return elements;
//}
//
//void freeList(char** elements, int quantity)
//{
//	for (int i = 0; i < quantity; i++)
//	{
//		free(*(elements + i));
//	}
//	free(elements);
//}
//
//void clearChar()
//{
//	char ch;
//	do
//	{
//		ch = getchar();
//	} while (ch != '\n' && ch != EOF);
//}
//
//void main()
//{
//	int quantity;
//	do
//	{
//		printf("How many elements you want to enter: ");
//		scanf("%i", &quantity);
//	} while (quantity < 1);
//	clearChar();
//	char** elements = allocList(quantity);
//	printf("Enter %i elements:\n", quantity);
//	enteringElement(elements, quantity);
//	sort(elements, quantity);
//	printf("Your elements:\n");
//	printElements(elements, quantity);
//	freeList(elements, quantity);
//}





//                   ПОЛЕЗНОСТЬ UNION

#include <stdio.h>
#include <stdlib.h>

#define STRUCT_SIZE 3

enum Type
{
	BeginType,
	Int,
	Float,
	Char,
	EndType
};

union Data
{
	int valueInt;
	float valueFloat;
	char valueStr[50];
};

struct DataItem
{
	enum valueType type;
	union Data data;
};

void print(struct DataItem* values)
{
	for (int i = 0; i < STRUCT_SIZE; i++)
	{
		switch (values[i].type)
		{
		case Int:
			printf("%i\n", values[i].data.valueInt);
			break;
		case Float:
			printf("%.2f\n", values[i].data.valueFloat);
			break;
		default:
			printf("%s", values[i].data.valueStr);
			break;
		}
	}
}

void clearChar()
{
	char ch;
	do
	{
		ch = getchar();
	} while (ch != '\n' && ch != EOF);
}

void entering(struct DataItem* values)
{
	enum Type type;
	for (int i = 0; i < STRUCT_SIZE; i++)
	{
		do
		{
			printf("#%i: Enter the type: ", i + 1);
			scanf("%i", &type);
		} while (type >= EndType || type <= BeginType);
		switch (type)
		{
		case Int:
			printf("Enter int: ");
			scanf("%i", &values[i].data.valueInt);
			values[i].type = Int;
			break;
		case Float:
			printf("Enter float: ");
			scanf("%f", &values[i].data.valueFloat);
			values[i].type = Float;
			break;
		default:
			printf("Enter char: ");
			fgets(values[i].data.valueStr, 50, stdin);
			clearChar();
			values[i].type = Char;
			break;
		}
	}
}

void main()
{
	struct DataItem* values = malloc(STRUCT_SIZE * 4);
	printf("Types:\n %i - int\n %i - float\n %i - char\n", Int, Float, Char);
	entering(values);
	print(values);
	free(values);
}
