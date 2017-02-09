/* Задание 2:
   По заданной длине окружности найти площадь круга по формуле S = pi*R2, радиус
   вычислить из формулы длины окружности : L = 2 * pi *R Примечание pi = 3.14 */

#include<stdio.h>

int main()
{
	float const pi = 3.14;
	float l = 11.5;
	float s;
	s = l * l / (4 * pi);
	printf("ploshad' kruga = %f\n", s);
	return 0;
}