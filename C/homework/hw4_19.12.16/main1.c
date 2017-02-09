/* Задание 1
   Пользователь вводит с клавиатуры целое шестизначное число.Написать программу,
   которая определяет, является ли введенное число – счастливым(Счастливым считается
   шестизначное число, у которого сумма первых 3 цифр равна сумме вторых трех цифр).
   Если пользователь ввел не шестизначное число – сообщение об ошибке. */

#include <stdio.h>

int main()
{
	int number;
	printf("Vvedite shestiznachnoe chislo:\n");
	scanf("%i", &number);
	if ((number > 99999 && number < 1000000) || (number > -1000000 && number < -99999))
	{
		//   первая цифра     +     вторая цифра      +    третья цифра      ==   четвертая цифра   +    пятая цифра     +  шестая цифра
		//         |                      |                      |                         |                  |                   |
		if ((number / 100000) + (number / 10000 % 10) + (number / 1000 % 10) == (number / 100 % 10) + (number / 10 % 10) + (number % 10))
		{
			printf("Bravo!\n%i - schastlivoe chislo!\n", number);
		}
		else
		{
			printf("%i - ne schastlivoe chislo :( \n", number);
		}
	}
	else
	{
		printf("Error!!!\n%i - ne shestiznachnoe chislo!\n", number);
	}
	return 0;
}