/*	Задание 1:
	Написать функцию, которая определяет, явдяется ли введенная строка анаграммой */


#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 51

bool isAnagram(char* userString, int stringLengh);
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
	if (isAnagram(userString, stringLengh) == true)
	{
		printf("It's an anagram.\n");
	}
	else
	{
		printf("It's not an anagram.\n");
	}
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

bool isAnagram(char* userString, int stringLengh)
{
	int count = 0;
	while (userString[count] == userString[stringLengh - 1 - count] || 
		userString[count] >= 'a' && userString[count] <= 'z' && userString[count] == userString[stringLengh - 1 - count] + 32 ||
		userString[count] >= 'A' && userString[count] <= 'Z' && userString[count] == userString[stringLengh - 1 - count] - 32)
	{
		count++;
	}
	return count == stringLengh;
}