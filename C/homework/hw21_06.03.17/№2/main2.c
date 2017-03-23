/*	Задание 2:
	Написать функцию, которая удаляет из строки все вхождения в нее заданного символа. */



#include <stdio.h>

#define STRING_SIZE 51

void deleteSymbol(char* userString, char symbolForDelete);
void clearChar();

enum Register
{
	CaseInsensitive,
	CaseSensitive
};

void main()
{
	char userString[STRING_SIZE];
	do
	{
		printf("Vvedite stroku(do %i simvolov):\n", STRING_SIZE - 1);
		fgets(userString, STRING_SIZE, stdin);
	} while (userString[0] == '\n');
	printf("Vasha stroka:\n%s", userString);
	if (userString[STRING_SIZE - 1] != -52 && userString[STRING_SIZE - 1] != '\n')  // -52 - число, которое по умолчанию лежит в элементах массива
	{
		clearChar();
		printf("\n");
	}
	char symbolForDelete;
	do
	{
		printf("Kakoj simvol hotite udalit': ");
		scanf("%c", &symbolForDelete);
	} while (symbolForDelete == '\n');
	deleteSymbol(userString, symbolForDelete);
	printf("Vot chto poluchilos':\n%s", userString);
}

void deleteSymbol(char* userString, char symbolForDelete)
{
	enum Register selection = CaseSensitive;
	if (symbolForDelete >= 'a' && symbolForDelete <= 'z' || symbolForDelete >= 'A' && symbolForDelete <= 'Z')
	{
		printf("Uchityvat' registr?\n %i - da    %i - net\n", CaseSensitive, CaseInsensitive);
		scanf("%i", &selection);
		while (selection > CaseSensitive || selection < CaseInsensitive)
		{
			printf("Net takogo punkta!\n");
			scanf("%i", &selection);
		}
	}
	int pasteCounter = 0;
	for (int i = 0; *(userString + i) != 0; i++)
	{
		if (*(userString + i) == symbolForDelete || selection == CaseInsensitive && (symbolForDelete >= 'a' && symbolForDelete < 'z' && *(userString + i) == symbolForDelete - 32 ||
			symbolForDelete >= 'A' && symbolForDelete < 'Z' && *(userString + i) == symbolForDelete + 32))
		{
		}
		else
		{
			pasteCounter++;
		}
		*(userString + pasteCounter) = *(userString + i + 1);
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