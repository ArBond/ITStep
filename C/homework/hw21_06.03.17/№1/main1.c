/*	Задание 1:
	Написать функцию, которая удаляет из строки символ с заданным номером. */



#include <stdio.h>
#define STRING_SIZE 51

int findStringLength(char* userString);
void deleteSymbol(char* userString, int position);
void clearChar();

void main()
{
	char userString[STRING_SIZE];
	do
	{
		printf("Vvedite stroku(do %i simvolov):\n", STRING_SIZE - 1);
		fgets(userString, STRING_SIZE, stdin);
	} while (userString[0] == '\n');
	int stringLength = findStringLength(userString);
	printf("Vasha stroka:\n%s", userString);
	if (stringLength == STRING_SIZE - 1)
	{
		clearChar();
		printf("\n");
	}
	int position;
	printf("Kakoj simvol po schetu hotite udalit'(1 - %i): ", stringLength);
	scanf("%i", &position);
	while (position > stringLength || position < 1)
	{
		printf(position < 1 ? "Takogo nomera ne mozhet byt'!\n" : "V stroke tol'ko %i simvolov!\n", stringLength);
		scanf("%i", &position);
	}
	deleteSymbol(userString, position);
	printf("Vot chto poluchilos':\n%s", userString);
}

int findStringLength(char* userString)
{
	int length = 0;
	while (*(userString + length) != 0 && *(userString + length) != '\n')
	{
		length++;
	}
	return length;
}

void deleteSymbol(char* userString, int position)
{
	for (int i = position - 1; *(userString + i) != 0; i++)
	{
		*(userString + i) = *(userString + i + 1);
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