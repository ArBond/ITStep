/* Задание 1: Написать программу «справочник».Создать два одномерных массива.Один
   массив хранит номера ICQ, второй – телефонные номера.Реализовать меню для
   пользователя :
   • Отсортировать по номерам ICQ
   • Отсортировать по номерам телефона
   • Вывести список пользователей
   • Выход */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define ARRAY_SIZE 20

void clearChar(char toContinue);
void arraysFormat(int icqArray[], int phoneNubmersArray[], int arraysSize);
int printMenuAndSelectAction();
void printArrays(int icqArray[], int phoneNubmersArray[], int firstFreeCellForRecording);
void addUser(int icqArray[], int phoneNubmersArray[], int firstFreeCellForRecording);
void deleteUser(int icqArray[], int phoneNubmersArray[], int firstFreeCellForRecording);
void sortByIcq(int icqArray[], int phoneNubmersArray[], int firstFreeCellForRecording);
void sortByNumbers(int icqArray[], int phoneNubmersArray[], int firstFreeCellForRecording);

int main()
{
	int icqArray[ARRAY_SIZE];
	int phoneNubmersArray[ARRAY_SIZE];
	arraysFormat(icqArray, phoneNubmersArray, ARRAY_SIZE);
	int firstFreeCellForRecording = 0;
	int forExit = 1;
	while (forExit != 0)
	{
		int selection = printMenuAndSelectAction();
		switch (selection)
		{
		case 1:
			if (firstFreeCellForRecording == 0)
			{
				printf("Spisok pust!\n");
			}
			else
			{
				printArrays(icqArray, phoneNubmersArray, firstFreeCellForRecording);
			}
			break;
		case 2:
			if (firstFreeCellForRecording < ARRAY_SIZE)
			{
				addUser(icqArray, phoneNubmersArray, firstFreeCellForRecording);
				printf("Pol'zovatel' dobavlen.\n");
				firstFreeCellForRecording++;
			}
			else
			{
				printf("Zakonchilas' pamjat'!\n");
			}
			break;
		case 3:
			if (firstFreeCellForRecording == 0)
			{
				printf("Spisok pust!\n");
			}
			else
			{
				deleteUser(icqArray, phoneNubmersArray, firstFreeCellForRecording);
				printf("Pol'zovatel' udalen.\n");
				firstFreeCellForRecording--;
			}
			break;
		case 4:
			sortByIcq(icqArray, phoneNubmersArray, firstFreeCellForRecording);
			printf("Spisok otsortirovan.\n");
			break;
		case 5:
			sortByNumbers(icqArray, phoneNubmersArray, firstFreeCellForRecording);
			printf("Spisok otsortirovan.\n");
			break;
		case 6:
			printf("Vy tochno hotite otformatirovat' spisok?\n 1 - da\n 2 - net\n");
			scanf("%i", &selection);
			while (selection > 2 || selection < 1)
			{
				printf("Error!\n");
				scanf("%i", &selection);
			}
			if (selection == 1)
			{
				arraysFormat(icqArray, phoneNubmersArray, ARRAY_SIZE);
				printf("Spisok otformatirovan.\n");
				firstFreeCellForRecording = 0;
			}
			break;
		default:
			forExit = 0;
			break;
		}
		if (forExit != 0)
		{
			printf("\nNazhmite 'Enter' chtoby prodolzhit'.\n");
			char toContinue;
			scanf("%c", &toContinue);
			clearChar(toContinue);
			system("cls");
		}
	}
	return 0;
}

void clearChar(char toContinue)
{
	do {
		toContinue = getchar();
	} while (toContinue != '\n' && toContinue != EOF);
}

void arraysFormat(int icqArray[], int phoneNubmersArray[], int arraysSize)
{
	for (int i = 0; i < arraysSize; i++)
	{
		icqArray[i] = INT_MIN;
		phoneNubmersArray[i] = INT_MIN;
	}
}

int printMenuAndSelectAction()
{
	printf("\tSpravochnik:\n\n 1 - vyvesti spisok polzovatelej\n 2 - dobavit' pol'zovatelja\n 3 - udalit' pol'zovatelja\n");
	printf(" 4 - otsortirovat' po ICQ\n 5 - otsortirovat' po nomeram telefona\n 6 - otformatirovat' spisok\n 0 - vyjti\n");
	int selection;
	scanf("%i", &selection);
	while (selection > 6 || selection < 0)
	{
		printf("Error!\n");
		scanf("%i", &selection);
	}
	return selection;
}

void printArrays(int icqArray[], int phoneNubmersArray[], int firstFreeCellForRecording)
{
	printf("\n \tICQ\t\tPhone number\n\n");
	for (int i = 0; i < firstFreeCellForRecording; i++)
	{
		printf("#%i:\t%i\t%i\n", i + 1, icqArray[i], phoneNubmersArray[i]);
	}
}

void addUser(int icqArray[], int phoneNubmersArray[], int firstFreeCellForRecording)
{
	printf("\n#%i\nICQ: ", firstFreeCellForRecording + 1);
	scanf("%i", &icqArray[firstFreeCellForRecording]);
	printf("Phone: ");
	scanf("%i", &phoneNubmersArray[firstFreeCellForRecording]);
}

void deleteUser(int icqArray[], int phoneNubmersArray[], int firstFreeCellForRecording)
{
	int selection;
	printf("\nKakogo polzovatelja hotite udaliy'?\n# ");
	scanf("%i", &selection);
	while (selection > firstFreeCellForRecording || selection < 1)
	{
		printf("Error!\n");
		scanf("%i", &selection);
	}
	for (int i = selection; i < firstFreeCellForRecording; i++)
	{
		icqArray[i - 1] = icqArray[i];
		phoneNubmersArray[i - 1] = phoneNubmersArray[i];
	}
	icqArray[firstFreeCellForRecording - 1] = INT_MIN;
	phoneNubmersArray[firstFreeCellForRecording - 1] = INT_MIN;
}

void sortByIcq(int icqArray[], int phoneNubmersArray[], int firstFreeCellForRecording)
{
	for (int i = 0; i < firstFreeCellForRecording - 1; i++)
	{
		if (icqArray[i] > icqArray[i + 1])
		{
			int icqBuffer = icqArray[i + 1];
			int phoneNubmerBuffer = phoneNubmersArray[i + 1];
			icqArray[i + 1] = icqArray[i];
			phoneNubmersArray[i + 1] = phoneNubmersArray[i];
			int j = i;
			while (j > 0 && icqBuffer < icqArray[j - 1])
			{
				icqArray[j] = icqArray[j - 1];
				phoneNubmersArray[j] = phoneNubmersArray[j - 1];
				j--;
			}
			icqArray[j] = icqBuffer;
			phoneNubmersArray[j] = phoneNubmerBuffer;
		}
	}
}

void sortByNumbers(int icqArray[], int phoneNubmersArray[], int firstFreeCellForRecording)
{
	for (int i = 0; i < firstFreeCellForRecording - 1; i++)
	{
		if (phoneNubmersArray[i] > phoneNubmersArray[i + 1])
		{
			int icqBuffer = icqArray[i + 1];
			int phoneNubmerBuffer = phoneNubmersArray[i + 1];
			icqArray[i + 1] = icqArray[i];
			phoneNubmersArray[i + 1] = phoneNubmersArray[i];
			int j = i;
			while (j > 0 && phoneNubmerBuffer < phoneNubmersArray[j - 1])
			{
				icqArray[j] = icqArray[j - 1];
				phoneNubmersArray[j] = phoneNubmersArray[j - 1];
				j--;
			}
			icqArray[j] = icqBuffer;
			phoneNubmersArray[j] = phoneNubmerBuffer;
		}
	}
}