//#include <stdio.h>
//
//int main()
//{
//	const int max = 1024;
//	for (int i = 0; i <= max; i++)
//	{
//		printf("%i\n", i);
//	}
//	return 0;
//}

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main()
{
	int gameChoiñe;
	printf("V kakuju igru vy hotite igat'?\n 1 - otgadyvanije chisel\n 2 - Zagadyvanije chisel\n");
	scanf("%i", &gameChoiñe);
	while (gameChoiñe > 2 || gameChoiñe < 1)
	{
		printf("Error!\n");
		scanf("%i", &gameChoiñe);
	}
	switch (gameChoiñe)
	{
	case 1:
		srand(time(0));
		int computerNumber = rand() % 10;
		int userNumber;
		printf("Compjuter zagadal chislo ot 0 do 9. Ugadaj ego!\n");
		for (int i = 1; i < 4; i++)
		{
			scanf("%i", &userNumber);
			if (computerNumber == userNumber)
			{
				printf("Pozdravljaju, vy ugadali za %i popytki! Eto chislo %i\n", i, computerNumber);
				break;
			}
			else
			{
				if (computerNumber > userNumber && i < 3)
				{
					printf("Bolse!\n");
				}
				else if (computerNumber < userNumber && i < 3)
				{
					printf("Menshe!\n");
				}
				else
				{
					printf("U vas zaconchilis' popytki. Eto bylo shislo %i.\n", computerNumber);
				}
			}
		}
		break;
	default:
		printf("Zagadajte chislo i compjuter poprobuet otgadat' ego.\n");
		int userSecretNumber;
		scanf("%i", &userSecretNumber);
		int min = 0;
		int max = 10;
		srand(time(0));
		for (int i = 1; i < 4; i++)
		{
			int computerNumber = min + rand() % max;
			printf("%i\n", computerNumber);
			if (computerNumber == userSecretNumber)
			{
				printf("Kompjuter molodec! On ugadal vashe schislo za %i popynki.\n", i);
				break;
			}
			else
			{
				if (computerNumber > userSecretNumber && i < 3)
				{
					printf("Menshe!\n");
					max = computerNumber - 1;
				}
				else if (computerNumber < userSecretNumber && i < 3)
				{
					printf("Bolse!\n");
					min = computerNumber + 1;
					max -= computerNumber;
				}
				else
				{
					printf("U compjutera zaconchilis' popytki. Eto bylo shislo %i.\n", userSecretNumber);
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			int computerNumber = min + rand() % max;
			printf("%i\n", computerNumber);
		}
		break;
	}
	return 0;
}