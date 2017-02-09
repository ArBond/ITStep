/* Задание 3:
   Вычислить пройденное расстояние при прямолинейном равноускоренном движении по
   формуле S = v*t + (a*t2) / 2, где v – скорость, t – время, а – ускорение. */

#include<stdio.h>

int main()
{
	float a = 3.5;
	float t = 7;
	float v = 13;
	float s;
	s = v * t + (a * t * t) / 2;
	printf("projdennoe rasstojanie = %.3f\n", s);
	return 0;
}