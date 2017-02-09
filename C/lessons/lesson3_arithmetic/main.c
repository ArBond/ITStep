#include<stdio.h>
#include<stdbool.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "0");
	int hour = 21;
	int min = 00;
	int time = 60 * hour + min;
	int const nightBegin = 1260;
	int const dayBegin = 360;

	printf("%s\n", time > nightBegin - 1 || time < dayBegin ? "night" : "day");
}