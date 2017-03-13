//#include <stdio.h>
//
//#define ARRAYSIZE 200
//
//void modifyString(char* userEnter, enum Register selection);
//void printString(char* const userEnter);
//
//enum Register
//{
//	Start,
//	Upper,
//	lower,
//	End
//};
//
//void main()
//{
//	char userEnter[ARRAYSIZE];
//	printf("Vvedite stroku(max ARRAYSIZE): ");
//	fgets(userEnter, ARRAYSIZE, stdin);
//	enum Register selection;
//	printf("%i - Upper   %i - lower\n", Upper, lower);
//	scanf("%i", &selection);
//	while (selection <= Start && selection >= End)
//	{
//		printf("No such item");
//		scanf("%i", &selection);
//	}
//	modifyString(userEnter, selection);
//	printf("Vasa stroka: ");
//	printString(userEnter);
//	printf("\n");
//}
//
//void modifyString(char* userEnter, enum Register selection)
//{
//	while (*userEnter != 0)
//	{
//		if (*userEnter >= 'a' && *userEnter <= 'z' && selection == Upper)
//		{
//			*userEnter -= 32;
//		}
//		else if (*userEnter > 'A' && *userEnter < 'Z' && selection == lower)
//		{
//			*userEnter += 32;
//		}
//		userEnter++;
//	}
//}
//
//void printString(char* const userEnter)
//{
//	for (int i = 0; userEnter[i] != '\n'; i++)
//	{
//		printf("%c", userEnter[i]);
//	}
//}





//#include <stdio.h>
//
//#define USER_NAME_SIZE 20
//#define RESULT_ARRAY_SIZE 200
//
//void sayHello(char const* userName, char const* greatingStart, char const* greatingEnd, char* result);
//
//int main()
//{
//	char greatingStart[] = "Hello, ";
//	char greatingEnd[] = "! Nice to meet you.\n";
//	char userName[USER_NAME_SIZE];
//	printf("What is your name: ");
//	fgets(userName, USER_NAME_SIZE, stdin);
//	while (userName[0] == '\n')
//	{
//		printf("What is your name: ");
//		fgets(userName, USER_NAME_SIZE, stdin);
//	}
//	char result[RESULT_ARRAY_SIZE];
//	sayHello(userName, greatingStart, greatingEnd, result);
//}
//
//void sayHello(char const* userName, char const* greatingStart, char const* greatingEnd, char* result)
//{
//	int resultCount = 0;
//	while (*greatingStart != 0)
//	{
//		*(result + resultCount) = *greatingStart;
//		greatingStart++;
//		resultCount++;
//	}
//	while (*userName != 0 && *userName != '\n')
//	{
//		*(result + resultCount) = *userName;
//		userName++;
//		resultCount++;
//	}
//	while (*greatingEnd != 0)
//	{
//		*(result + resultCount)= *greatingEnd;
//		greatingEnd++;
//		resultCount++;
//	}
//	for (int i = 0; i < resultCount; i++)
//	{
//		printf("%c", result[i]);
//	}
//}




#include <stdio.h>

#define ARRAT_SIZE 100

void main()
{
	char userEnter[ARRAT_SIZE];
	fgets(userEnter, ARRAT_SIZE, stdin);
	int srtingSize = 0;
	while (userEnter[srtingSize] != '\n')
	{
		srtingSize++;
	}
	int i = 0;
	while (userEnter[i] == userEnter[srtingSize - 1 - i])
	{
		i++;
	}
	printf(i == srtingSize ? "+" : "-");
}
