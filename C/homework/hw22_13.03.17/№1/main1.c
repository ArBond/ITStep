/*	Задание 1:
	Написать функцию, которая вставляет в строку в указанную позицию заданный символ */


#include <stdio.h>

int findLengthOfString(char* string);
void incertSymbol(char* string, char userSymbol, int placeForIncert, int stringLength);
void clearChar();

void main()
{
	char string[] = "This is your string in which you can to insert a symbol.\n";
	printf("String: %s", string);
	int stringLength = findLengthOfString(string);
	printf("What symbol do you want to insert: ");
	char userSymbol;
	do
	{
		scanf("%c", &userSymbol);
	} while (userSymbol == '\n');
	clearChar();
	printf("In what place do you want to incert (1 - %i): ", stringLength);
	int placeForIncert;
	scanf("%i", &placeForIncert);
	while (placeForIncert > stringLength || placeForIncert < 1)
	{
		printf(placeForIncert < 1 ? "The symbol number can't to be less then 1.\n" : "String contains only %i symbols.\n", stringLength);
		scanf("%i", &placeForIncert);
	}
	incertSymbol(string, userSymbol, placeForIncert, stringLength);
	printf("New string: %s\n", string);
}

int findLengthOfString(char* string)
{
	int stringLength = 0;
	while(*(string + stringLength) != 0 && *(string + stringLength) != '\n')
	{
		stringLength++;
	}
	return stringLength;
}

void incertSymbol(char* string, char userSymbol, int placeForIncert, int stringLength)
{
	for (int i = stringLength; i > placeForIncert - 1; i--)
	{
		*(string + i) = *(string + i - 1);
	}
	*(string + placeForIncert - 1) = userSymbol;
}

void clearChar()
{
	char ch;
	do
	{
		ch = getchar();
	} while (ch != '\n' && ch != EOF);
}