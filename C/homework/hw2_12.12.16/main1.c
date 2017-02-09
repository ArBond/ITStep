/* Задание 1
   Пользователь задает время в секундах(в переменной в коде программы).Необходимо
   написать программу, которая переведет введенные пользователем секунды в часы,
   минуты, секунды и выводит их на экран. */

#include<stdio.h>

int main()
{
	int secAll = 7200+720+61;
	int hour = secAll / 3600;
	int min = (secAll - hour * 3600) / 60;
	int sec = (secAll - hour * 3600 - min * 60) % 60;
	printf("Vremja: %02i:%02i:%02i (hour:min:sec)\n", hour, min, sec);
	return 0;
}