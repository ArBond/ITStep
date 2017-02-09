/* Задание 2
   Пользователь вводит с клавиатуры 7 целых чисел.Напишите программу, которая
   определяет максимальное из этих 7 чисел(Подсказка – решение должно быть простым). */

#include <stdio.h>

int main()
{
	int nubmer1;
	int nubmer2;
	int nubmer3;
	int nubmer4;
	int nubmer5;
	int nubmer6;
	int nubmer7;
	printf("Vvedite 7 chisel:\n");
	scanf("%i%i%i%i%i%i%i", &nubmer1, &nubmer2, &nubmer3, &nubmer4, &nubmer5, &nubmer6, &nubmer7);
	int maxNumber = nubmer1;
	if (maxNumber < nubmer2)
	{
		maxNumber = nubmer2;
	}
	if (maxNumber < nubmer3)
	{
		maxNumber = nubmer3;
	}
	if (maxNumber < nubmer4)
	{
		maxNumber = nubmer4;
	}
	if (maxNumber < nubmer5)
	{
		maxNumber = nubmer5;
	}
	if (maxNumber < nubmer6)
	{
		maxNumber = nubmer6;
	}
	if (maxNumber < nubmer7)
	{
		maxNumber = nubmer7;
	}
	printf("%i - maximal'noe chislo!\n", maxNumber);
	return 0;
}