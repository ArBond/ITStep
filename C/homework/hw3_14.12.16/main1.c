/* задание 1
   Пользователь вводит с клавиатуры расстояние до аэропорта и время, за которое нужно
   доехать. Вычислить скорость, с которой ему нужно ехать. */

#include <stdio.h>

int main()
{
	int distance;
	float time;
	printf("Kakoe rasstojanie do aeroporta (km)?\n");
	scanf("%i", &distance);
	printf("Za kakoe vremja nuzno doehat' (hour)?\n");
	scanf("%f", &time);
	float speed = distance / time;
	printf("Vam nuzno ehat' so skorostju %.0f km/h.\n", speed);
	return 0;
}