/*	Задание 1:
	Написать функцию, которая определяет, явдяется ли введенная строка анаграммой */


#include <stdio.h>

#define ARRAY_SIZE 51

void isAnagram(char* userString, int stringLengh);
int findStringLength(char* userString);

void main()
{
	char userString[ARRAY_SIZE];
	printf("Enter the string(up to %i symbols): ", ARRAY_SIZE - 1);
	do
	{
		fgets(userString, ARRAY_SIZE, stdin);
	} while (*userString == '\n');
	printf("Your string: %s", userString);
	int stringLengh = findStringLength(userString);
	isAnagram(userString, stringLengh);
}

int findStringLength(char* userString)
{
	int stringLengh = 0;
	while (userString[stringLengh] != '\n' && userString[stringLengh] != 0)
	{
		stringLengh++;
	}
	return stringLengh;
}

void isAnagram(char* userString, int stringLengh)
{
	int count = 0;
	while (userString[count] == userString[stringLengh - 1 - count] || 
		userString[count] >= 'a' && userString[count] <= 'z' && userString[count] == userString[stringLengh - 1 - count] + 32 ||
		userString[count] >= 'A' && userString[count] <= 'Z' && userString[count] == userString[stringLengh - 1 - count] - 32)
	{
		count++;
	}
	printf(count == stringLengh ? "It's an anagram.\n" : "It's not an anagram.\n");
}