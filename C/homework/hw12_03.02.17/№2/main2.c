/* Задание 2
Написать игру «Быки и коровы».Программа "загадывает" четырёхзначное число и
играющий должен угадать его.После ввода пользователем числа программа сообщает,
сколько цифр числа угадано(быки) и сколько цифр угадано и стоит на нужном месте
(коровы).После отгадывания числа на экран необходимо вывести количество сделанных
пользователем попыток.В программе необходимо использовать рекурсию. */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int guessTheNumber(int secretNumber, int tryCount);
int calculateBull(int secretNumber, int userNumber);
int calculateCow(int secretNumber, int userNumber);
void printRules();
void clearChar(char toContinue);

char toContinue;

int main()
{
	printf("\nByki i korovy!\nJa zagadaju chetyrehznachnoe chislo. Vadha zadacha - ugadat' ego.\n\n");
	printf("'byki' - ugadannye cifry chisla.\n'korovy' - ugadannye i stojashije na nuzhnom meste cifry chisla.\n\n\n\n\n");
	printf("'Enter' - prodolshit'...");
	scanf("%c", &toContinue);
	int secretNumber;
	srand(time(0));
	secretNumber = rand() % 9000 + 1000;
	int tryCount = 0;
	printf("Ja zagadal chislo. Ugadaj ego!\n");
	printf("Pozdravljaju! Vy ugadali za %i popytok.\n", guessTheNumber(secretNumber, tryCount));
	return 0;
}

int guessTheNumber(int secretNumber, int tryCount)
{
	system("cls");
	tryCount++;
	int userNumber;
	printf("\npopytka %i: ", tryCount);
	scanf("%i", &userNumber);
	while (userNumber > 9999 || userNumber < 1000)
	{
		printf("Eto ne chetyrehznachnoe chislo.\npopytka %i: ", tryCount);
		scanf("%i", &userNumber);
	}
	if (userNumber != secretNumber)
	{
		printf("Bykov: %i\n", calculateBull(secretNumber, userNumber));
		printf("Korov: %i\n\n\n\n\n", calculateCow(secretNumber, userNumber));
		printf("1 - prodolzhit'     2 - vyvesti pravila i prodolxhit'     0 - vyjti\n");
		int choice;
		do
		{
			scanf("%i", &choice);
		} while (choice > 2 || choice < 0);
		switch (choice)
		{
		case 1:
			break;
		case 2:
			printRules();
			break;
		default:
			exit(0);
			break;
		}
		guessTheNumber(secretNumber, tryCount);
	}
	else
	{
		return tryCount;
	}
}

int calculateBull(int secretNumber, int userNumber)
{
	int bull = 0;
	for (int i = 1; i < 1001; i *= 10)
	{
		for (int j = 1; j < 1001; j *= 10)
		{
			if (secretNumber / i % 10 == userNumber / j % 10)
			{
				bull++;
				break;
			}
		}
	}
	return bull;
}

int calculateCow(int secretNumber, int userNumber)
{
	int cow = 0;
	for (int i = 1; i < 1001; i *= 10)
	{
		if (userNumber / i % 10 == secretNumber / i % 10)
		{
			cow++;
		}
	}
	return cow;
}

void clearChar(char toContinue)
{
	do {
		toContinue = getchar();
	} while (toContinue != '\n' && toContinue != EOF);
}

void printRules()
{
	system("cls");
	printf("\nByki i korovy!\nZagadano chetyrehznachnoe chislo. Vadha zadacha - ugadat'ego.\n\n");
	printf("'byki' - ugadannye cifry chisla.\n'korovy' - ugadannye i stojashije na nuzhnom meste cifry chisla.\n\n\n\n\n");
	printf("'Enter' - prodolshit'...");
	clearChar(toContinue);
	scanf("%c", &toContinue);
}