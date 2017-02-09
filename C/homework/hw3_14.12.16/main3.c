/* Задание 3
   Пользователь вводит с клавиатуры расстояние, расход бензина на 100 км и стоимость трех
   видов бензина.Вывести на экран сравнительную таблицу со стоимостью поездки на
   разных видах бензина. */

#include <stdio.h>

int main()
{
	int distance;
	float rashod;
	float costPetrol1;
	float costPetrol2;
	float costPetrol3;
	printf("Kakoe rasstojanie?\n");
	scanf("%i", &distance);
	printf("kakov rashod na 100 km?\n");
	scanf("%f", &rashod);
	printf("stoimost' benzina marki 1(rub): ");
	scanf("%f", &costPetrol1);
	printf("stoimost' benzina marki 2(rub): ");
	scanf("%f", &costPetrol2);
	printf("stoimost' benzina marki 3(rub): ");
	scanf("%f", &costPetrol3);
	float costTrip1 = distance * rashod / 100 * costPetrol1;
	float costTrip2 = distance * rashod / 100 * costPetrol2;
	float costTrip3 = distance * rashod / 100 * costPetrol3;
	printf("\n Marka benzina %c Stoimost' poezdki(rub)\n", 179);
	printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196);
	printf("\t1%7c", 179);
	printf("\t%.2f\n", costTrip1);
	printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196);
	printf("\t2%7c", 179);
	printf("\t%.2f\n", costTrip2);
	printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196);
	printf("\t3%7c", 179);
	printf("\t%.2f\n\n", costTrip3);
	return 0;
}