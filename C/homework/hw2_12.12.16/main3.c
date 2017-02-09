/* Задание 3
   Написать программу, вычисляющую, с какой скоростью бегун пробежал дистанцию.
   Рекомендуемый вид экрана во время выполнения программы приведен ниже :
   Вычисление скорости бега
   Длина дистанции = 1000 м
   Время(мин.сек) = 3.25
   Время : 3 мин 25 сек = 205 сек
   Вы бежали со скоростью 17.56 км / ч
   Длина дистанции и время задается в коде программы в переменных. */

#include<stdio.h>

int main()
{
	printf("Vychislenie skorosti bega:\n");
	int dlinna = 1000;
	double vremja = 3.25;
	printf("dlinna distancii = %i m\n", dlinna);
	printf("Vremja (min.sec) = %.2f\n", vremja);
	int min = (int)vremja;
	double sec = (vremja - min)*100;
	double allSec = min * 60 + sec;
	printf("Vremja: %i min %.0f sec = %.0f sec\n", min, sec, allSec);
	double skorost = (dlinna / allSec)*3.6;
	printf("Vy bezali so skorostju %.2f km/h\n", skorost);
	return 0;
}