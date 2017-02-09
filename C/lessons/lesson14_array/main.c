
               // Одномерные статические массивы

#include <stdio.h>
#define MONTH 31

float findMaxTemperature(float temperatures[], float maxTemperature);
float findMinTemperature(float temperatures[], float minTemperature);

int main()
{
	float totalTemperature = 0;
	float temperatures[MONTH];
	int days[MONTH];
	float maxTemperature = -273;
	float minTemperature = 200;
	printf("Vvedine temperaty(C) i dni v kotorye zapominali temperaturu v techenie mesjaca.\n");
	int count = 0;
	for (int i = 0; i < MONTH; i++)
	{
		printf("day: ");
		scanf("%i", &days[i]);
		if (days[i] < 1)
		{
			break;
		}
		while (days[i] > 31)
		{
			printf("Ne byvaet stolko dnej v mesjace\nday: ");
			scanf("%i", &days[i]);
		}
		printf("temperature: ");
		scanf("%f", &temperatures[i]);
		while (temperatures[i] <= -273 || temperatures[i] >= 200)
		{
			printf("Takoj temperatury ne byvaet!\ntemperature: ");
			scanf("%f", &temperatures[i]);
		}
		totalTemperature += temperatures[i];


		count = i + 1;
	}
	printf("\tDay:\tTemperature\n");
	for (int i = 0; i < count; i++)
	{
		printf("\t %i\t %.1f\n", days[i], temperatures[i]);
	}
	printf("Srednjaja temperatura  = %.1f (C)\nMaksimalnaja temperatura = %.1f (C)\nMinimaknaja temperatura = %.1f (C)\n", totalTemperature / count, maxTemperature, minTemperature);
	return 0;
}

float findMaxTemperature(float temperatures[], float maxTemperature)
{
	if (maxTemperature < temperatures[i])
	{
		maxTemperature = temperatures[i];
	}
}

float findMinTemperature(float temperatures[], float minTemperature)
{
	if (minTemperature > temperatures[i])
	{
		minTemperature = temperatures[i];
	}
}


// sizeof(mas)/sizeof(int) - узнать количество элементов массива