/* Задание 2
   Пользователь вводит с клавиатуры время начала и время завершения телефонного
   разговора(часы, минуты и секунды).Посчитать стоимость разговора, если стоимость
   минуты – 30 копеек. */

#include <stdio.h>

int main()
{
	int hourBegin;
	int minBegin;
	int secBegin;
	printf("Vo skol'ko vy nachali razgovor (hour,min,sec)?\nhour:");
	scanf("%i", &hourBegin);
	printf("min:");
	scanf("%i", &minBegin);
	printf("sec:");
	scanf("%i", &secBegin);
	int hourEnd;
	int minEnd;
	int secEnd;
	printf("Vo skol'ko vy zakonchili (hour,min,sec)?\nhour:");
	scanf("%i", &hourEnd);
	printf("min:");
	scanf("%i", &minEnd);
	printf("sec:");
	scanf("%i", &secEnd);
	int secTalk = (hourEnd * 3600 + minEnd * 60 + secEnd) - (hourBegin * 3600 + minBegin * 60 + secBegin);
	                                                           //int costTolc = (secTalk / 60 + 1) * 30;
	int rub = (secTalk / 60 + 1) * 3 / 10;                     //int rub = costTolc / 100;
	int cop = (secTalk / 60 + 1) * 30 - rub*100;               //int cop = costTolc - rub*100;
	printf("Stoimost' vsego razgovora - %i rub %i cop (stoimost' minuty - 30 cop).\n", rub, cop);
	return 0;
}