//#include <stdio.h>
//#include <stdbool.h>
//
//#define ROW 100
//#define COL 100
//
//void printPhoneBook(char* phoneBook, int firstFreeRowForRecording);
//void addUser(char* phoneBook, int firstFreeRowForRecording);
//void deleteUser(char* phoneBook, int firstFreeRowForRecording);
//enum Menu printMenuAndChooseSelection();
//
//enum Menu
//{
//	Exit,
//	Print,
//	Add,
//	Delete,
//	End
//};
//
//int main()
//{
//	printf("Phone Book!\n");
//	char phoneBook[2][ROW][COL];
//	int firstFreeRowForRecording = 0;
//	while (true)
//	{
//		switch (printMenuAndChooseSelection())
//		{
//		case Print:
//			if (firstFreeRowForRecording == 0)
//			{
//				printf("No users in Phone Book.\n");
//			}
//			else
//			{
//				printPhoneBook((char*)phoneBook, firstFreeRowForRecording);
//			}
//			break;
//		case Add:
//			addUser((char*)phoneBook, firstFreeRowForRecording);
//			firstFreeRowForRecording++;
//			printf("User added.\n");
//			break;
//		case Delete:
//			if (firstFreeRowForRecording > 0)
//			{
//				addUser((char*)phoneBook, firstFreeRowForRecording);
//				firstFreeRowForRecording--;
//				printf("User deleted.\n");
//			}
//			else
//			{
//				printf("No users in Phone Book.\n");
//			}
//			break;
//		default:
//			return 0;
//		}
//	}
//}
//
//int printMenuAndChooseSelection()
//{
//	enum Menu selection;
//	printf(" %i - Print\n %i - Add\n %i - Delete\n %i - Exit\n", Print, Add, Delete, Exit);
//	scanf("%i", &selection);
//	while (selection < Exit || selection >= End)
//	{
//		printf("No such item!\n");
//		scanf("%i", &selection);
//	}
//	return selection;
//}
//
//void printPhoneBook(char* phoneBook, int firstFreeRowForRecording)
//{
//	
//}
//
//void addUser(char* phoneBook, int firstFreeRowForRecording)
//{
//
//}
//
//void deleteUser(char* phoneBook, int firstFreeRowForRecording)
//{
//
//}





#include <stdio.h>

void strCopy(char* from, char* to)
{
	while (*from != 0 && *from != '\n')
	{
		*to = *from;
		from++;
		to++;
	}
	*to = 0;
}

void clearArray(char array[][10][256],
	int colCount, int rowCount)
{
	for (int col = 0; col < colCount;
		col++)
	{
		for (int row = 0; row < rowCount;
			row++)
		{
			array[col][row][0] = 0;
		}
	}
}

void printArray(char array[][10][256],
	int colCount, int rowCount)
{
	printf("Name\tPhone\n");
	for (int row = 0; row < rowCount;
		row++)
	{
		for (int col = 0; col < colCount;
			col++)
		{
			printf("%s\t",
				array[col][row]);
		}
		printf("\n");
	}
}

int main()
{
	char addressBook[2][10][256];
	clearArray(addressBook, 2, 10);

	char name[256];
	char phone[256];
	for (int user = 0; user < 2; user++)
	{
		printf("Enter name: ");
		fgets(name, 256, stdin);
		strCopy(name, addressBook[0][user]);
		printf("Enter phone: ");
		fgets(phone, 256, stdin);
		strCopy(phone, addressBook[1][user]);
	}

	printArray(addressBook, 2, 10);
}
