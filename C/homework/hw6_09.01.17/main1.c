/* Задание 1
   Пользователь вводит с клавиатуры символ.Определить, какой это символ : Буква, цифра,
   знак препинания или другое. */


#include <stdio.h>

int main()
{
	unsigned char userSymbol;
	printf("Enter symbol: ");
	scanf("%c", &userSymbol);
	if ((userSymbol > 64 && userSymbol < 123) || (userSymbol > 127 && userSymbol < 176) || (userSymbol > 223 && userSymbol < 248))
	{
		printf("'%c' - letter.\n", userSymbol);
	}
	else if (userSymbol > 47 && userSymbol < 58)
	{
		printf("'%c' - number.\n", userSymbol);
	}
	else if (userSymbol == 33 || userSymbol > 43 && userSymbol < 47 || userSymbol == 58 || userSymbol == 59 || userSymbol == 63)
	{
		printf("'%c' - punctuation mark.\n", userSymbol);
	}
	else
	{
		printf("'%c' - something another.\n", userSymbol);
	}
	return 0;
}

