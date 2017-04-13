/*	Задание 1:
	Написать программу, которая дает пользователю вести домашнюю бухгалтерию.В начале
	программа спрашивает текущий баланс счета.Затем программа выводит меню :
		1. Снять со счета
		2. Положить на счет
		3. Оплатить
		4. Вывести на экран список транзакций
		5. Вывести баланс
		6. Выход
	Сумма вводится как вещественное число(BYN).К каждой транзакции можно писать
	комментарий с указанием типа / содержания транзакции.
	Используйте структуры и динамические массивы. */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ADDRESSEE_LENGTH 50
#define PURPOSE_LENGTH 50

enum Menu
{
	Exit,
	AddMoney,
	GetMoney,
	Pay,
	PrintTransactionList,
	PrintBalance,
	EndMenu
};

struct TransactionList
{
	float sum;
	char* addressee;
	char* purpose;
};

float calculateBalance(struct TransactionList* data, int positionForRecording)
{
	float balance = 0;
	for (int i = 0; i < positionForRecording; i++)
	{
		balance += (data + i)->sum;
	}
	return balance;
}

void addTransaction(struct TransactionList* data, float sum, char* addressee, char* purpose, int* positionForRecording)
{
	if (sum == 0)
	{
		printf("\nOperation not performed!\n");
		return;
	}
	if (calculateBalance(data, *positionForRecording) < -sum && *positionForRecording != 0)
	{
		printf("\nNot enought money!\n");
		return;
	}
	(data + *positionForRecording)->sum = sum;
	(data + *positionForRecording)->addressee = malloc(ADDRESSEE_LENGTH);
	(data + *positionForRecording)->purpose = malloc(PURPOSE_LENGTH);
	if (addressee == NULL && sum > 0)
	{
		strcpy((data + *positionForRecording)->addressee, " - ");
		strcpy((data + *positionForRecording)->purpose, "add money");
		printf("\nMoney is added.\n");
	}
	else if (addressee == NULL && sum < 0)
	{
		strcpy((data + *positionForRecording)->addressee, " - ");
		strcpy((data + *positionForRecording)->purpose, "get money");
		printf("\nMoney is getted.\n");
	}
	else
	{
		strcpy((data + *positionForRecording)->addressee, addressee);
		strcpy((data + *positionForRecording)->purpose, purpose);
		printf("\nPayment made.\n");
	}
	(*positionForRecording)++;
}

enum Menu printMenuAndSelectionOperation()
{
	printf("\n %i - add money\n %i - get money\n %i - pay\n %i - print transaction list\n %i - print balance\n %i - exit\n",
		AddMoney, GetMoney, Pay, PrintTransactionList, PrintBalance, Exit);
	enum Menu selection;
	scanf("%i", &selection);
	while (selection < Exit || selection >= EndMenu)
	{
		printf("\nThere is no such item!\n");
		scanf("%i", &selection);
	}
	return selection;
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

printTransactionList(struct TransactionList* data, int positionForRecording)
{
	printf(" Sum:\t\tAddressee:\tPurpose:\n");
	for (int i = 0; i < positionForRecording; i++)
	{
		printf("%.2f\t\t%s\t\t%s\n", (data + i)->sum, (data + i)->addressee, (data + i)->purpose);
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

void freeStructMemory(struct TransactionList* data, int positionForRecording)
{
	for (int i = 0; i < positionForRecording; i++)
	{
		free((data + positionForRecording)->addressee);
		free((data + positionForRecording)->purpose);
	}
	free(data);
}

void main()
{
	struct TransactionList* transactions = calloc(50, sizeof(struct TransactionList));
	int positionForRecording = 0;
	printf("For begin you need to enter your balance(BUN): ");
	float sum;
	scanf("%f", &sum);
	while (sum <= 0)
	{
		printf("Your balance can't be 0 or less(BUN).\nEnter your balance: ");
		scanf("%f", &sum);
	}
	addTransaction(transactions, sum, NULL, NULL, &positionForRecording);
	char* addresseeBuffer = malloc(ADDRESSEE_LENGTH);
	char* purposeBuffer = malloc(PURPOSE_LENGTH);
	while (true)
	{
		switch (printMenuAndSelectionOperation())
		{
		case AddMoney:
			printf("How many money do you add(BUN): ");
			scanf("%f", &sum);
			if (sum < 0)
			{
				sum = -sum;
			}
			addTransaction(transactions, sum, NULL, NULL, &positionForRecording);
			break;
		case GetMoney:
			printf("How many money do you get(BUN): ");
			scanf("%f", &sum);
			if (sum > 0)
			{
				sum = -sum;
			}
			addTransaction(transactions, sum, NULL, NULL, &positionForRecording);
			break;
		case Pay:
			printf("payment amount(BUN): ");
			scanf("%f", &sum);
			if (sum > 0)
			{
				sum = -sum;
			}
			clearChar();
			printf("addresse(50 symbols): ");
			fgets(addresseeBuffer, ADDRESSEE_LENGTH, stdin);
			clearEnterSymbol(addresseeBuffer);
			printf("Purpose of payment(50 symbols): ");
			fgets(purposeBuffer, PURPOSE_LENGTH, stdin);
			clearEnterSymbol(purposeBuffer);
			addTransaction(transactions, sum, addresseeBuffer, purposeBuffer, &positionForRecording);
			break;
		case PrintTransactionList:
			printTransactionList(transactions, positionForRecording);
			break;
		case PrintBalance:
			printf("\nYour balance: %.2f(BUN)\n", calculateBalance(transactions, positionForRecording));
			break;
		default:
			freeStructMemory(transactions, positionForRecording);
			free(addresseeBuffer);
			free(purposeBuffer);
			return;
		}
	}
}