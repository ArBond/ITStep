/* Задание 2
   Напишите программу, которая вычисляет сумму целых чисел от а до 500 (значение a вводится с клавиатуры). */


#include <stdio.h>

int main()
{
	int userNumber = 501;
	printf("Vvedite celoe chislo. Ono dolzno byt' ne bolshe 500!\n");
	while (userNumber > 500)
	{
		scanf("%i", &userNumber);
		if (userNumber > 500)
		{
			printf("Nepravilnoe chislo!\n");
		}
	}
	int sum = 0;
	int startNumber = userNumber;
	while (userNumber <= 500)
	{
		sum += userNumber;
		userNumber++;
	}
	printf("Summa celyh shisel ot %i do 500 = %i\n", startNumber, sum);
	return 0;
}