#include <stdio.h>
#include <stdbool.h>

#define ROW 100
#define COL 25
#define GRAPH 2

void clearArray(char* phoneBook);
enum Menu printMenuAndChooseSelection();
void printPhoneBook(char* phoneBook, int firstFreeRowForRecording);
void addUser(char* phoneBook, int firstFreeRowForRecording);
void deleteUser(char* phoneBook, int firstFreeRowForRecording);

enum Menu
{
	Exit,
	Print,
	Add,
	Delete,
	End
};

int main()
{
	printf("Phone Book!\n");
	char phoneBook[ROW][GRAPH][COL];
	clearArray((char*)phoneBook);
	int firstFreeRowForRecording = 0;
	while (true)
	{
		switch (printMenuAndChooseSelection())
		{
		case Print:
			if (firstFreeRowForRecording == 0)
			{
				printf("No users in Phone Book.\n");
			}
			else
			{
				printPhoneBook((char*)phoneBook, firstFreeRowForRecording);
			}
			break;
		case Add:
			addUser((char*)phoneBook, firstFreeRowForRecording);
			firstFreeRowForRecording++;
			printf("User added.\n");
			break;
		case Delete:
			if (firstFreeRowForRecording > 0)
			{
				deleteUser((char*)phoneBook, firstFreeRowForRecording);
				firstFreeRowForRecording--;
				printf("User deleted.\n");
			}
			else
			{
				printf("No users in Phone Book.\n");
			}
			break;
		default:
			return 0;
		}
	}
}

void clearArray(char* phoneBook)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < GRAPH; j++)
		{
			*(phoneBook + i * GRAPH * COL + j * COL + COL - 1) = 0;
		}
	}
}

int printMenuAndChooseSelection()
{
	enum Menu selection;
	printf(" %i - Print\n %i - Add\n %i - Delete\n %i - Exit\n", Print, Add, Delete, Exit);
	scanf("%i", &selection);
	while (selection < Exit || selection >= End)
	{
		printf("No such item!\n");
		scanf("%i", &selection);
	}
	return selection;
}

void printPhoneBook(char* phoneBook, int firstFreeRowForRecording)
{
	printf("Name:\t\t\t\tNumber:\n");
	for (int i = 0; i < firstFreeRowForRecording; i++)
	{
		for (int j = 0; j < GRAPH; j++)
		{
			printf("%s", phoneBook + i * GRAPH * COL + j * COL);
			printf("\t");
		}
		printf("\n");
	}
}

void addUser(char* phoneBook, int firstFreeRowForRecording)
{
	printf("Enter name: ");
	char* name = phoneBook + COL * GRAPH * firstFreeRowForRecording;
	do
	{
		fgets(name, COL - 1, stdin);
	} while (*(name) == '\n');
	while (*(name) != 0)
	{
		if (*(name) == '\n')
		{
			*(name) = ' ';
		}
		name++;
	}
	*(name) = ' ';
	while (*(name) != 0)
	{
		*(name) = ' ';
		name++;
	}
	

	printf("Enter phone number: ");
	char* phone = phoneBook + COL * GRAPH * firstFreeRowForRecording + COL;
	do
	{
		fgets(phone, COL - 1, stdin);
	} while (*(phone) == '\n');
	while (*(phone) != 0)
	{
		if (*(phone) == '\n')
		{
			*(phone) = ' ';
		}
		phone++;
	}
	*(phone) = ' ';
	while (*(phone) != 0)
	{
		*(phone) = ' ';
		phone++;
	}
}

void deleteUser(char* phoneBook, int firstFreeRowForRecording)
{
	char* userForDelete = phoneBook + COL * GRAPH * firstFreeRowForRecording;
	for (int i = 0; i < GRAPH; i++)
	{
		int column = 0;
		while (*(userForDelete + COL * i + column) != 0)
		{
			*(userForDelete + COL * i + column) = ' ';
			column++;
		}
	}
}

// доделать номер удаляемого
// добавить чистку если пользователь ввел больше чем размер графы