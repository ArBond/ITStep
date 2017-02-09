/* Задание 3
   Найти произведение всех целых чисел от a до 20 (значение a вводится с клавиатуры : 1 <= a <= 20). */


#include <stdio.h>

int main()
{
	int userNumber = 0;
	printf("Vvedite celoe chislo. Ono dolzhno byt' bolshe 0 i menshe 21!\n");
	while (userNumber < 1 || userNumber > 20)
	{
		scanf("%i", &userNumber);
		if (userNumber < 1 || userNumber > 20)
		{
			printf("Nepravilnoe chislo!\n");
		}
	}
	double total = 1;
	int startNumber = userNumber;
	while (userNumber <= 20)
	{
		total *= userNumber;
		userNumber++;
	}
	printf("Proizvedenie celyh chisel ot %i do 20 = %.0f\n", startNumber, total);
	return 0;
}