/* Задание 1
   Пользователь вводит четырехзначное число.Необходимо поменять в этом числе 1 и 2
   цифры, а также 3 и 4 цифры.Если пользователь вводит не четырехзначное число –
   вывести сообщение об ошибке. */

#include <stdio.h>

int main()
{
	int number;
	printf("Vvedite chetyrohznachnoe chislo:\n");
	scanf("%i", &number);
	if (number > 999 && number<10000 || number > -10000 && number < -999)
	{
		int numeral1 = number / 1000;
		int numeral2 = number / 100 % 10;
		int numeral3 = number / 10 % 10;
		int numeral4 = number % 10;
		int newNubmer = numeral2 * 1000 + numeral1 * 100 + numeral4 * 10 + numeral3;
		printf("Vashe novoe chislo: %04i\n", newNubmer);
	}
	else
	{
		printf("Error!\n%i - ne chetyrohznachnoe chislo!\n", number);
	}
	return 0;
}