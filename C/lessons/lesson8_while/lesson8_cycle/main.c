

/* #include <stdio.h>

int main()
{
	int a = 1;
	while (a < 100)
	{
		printf("Schetchik: %i\n", a);
		a = a + 3;
	}
}
*/






/* #include <stdio.h>

int main()
{
	int x1;
	int x2;
	int delitel = 0;
	printf("Vvedite niznuju i verhnuju granici.\n");
	scanf("%i%i", &x1, &x2);
	if (x1 > x2)
	{
		int dop = x1;
		x1 = x2;
		x2 = dop;
		int answer;
		printf("Vozmozno Vy imeli vvidu ot %i do %i?\n1 - da\n2 - net\n", x1, x2);
		scanf("%i", &answer);
		if (answer == 2)
		{
			printf("Error!\n");
			return 1;
		}
	}
	while (delitel == 0)
	{
		printf("Vvedite delitel.\n");
		scanf("%i", &delitel);
		if (delitel == 0)
		{
			printf("Na 0 dilit nelzja!\n");
		}
	}
	if (delitel > x2)
	{
		printf("delitel bolshe verhnej granicy.\n");
		return 2;
	}
	printf("poslednie 3 chisla kotorye deljatza na %i\n", delitel);
	int counter = 0;
	while (x2 >= x1)
	{
		if (x2%delitel == 0)
		{
			counter++;
		}
		if (counter == 3)
		{
			break;
		}
		x2--;
	}
	while (counter !=0)
	{
		if (x2%delitel == 0)
		{
			printf("%i\n", x2);
			counter--;
		}
		x2++;
	}
	return 0;
}
*/






/*
#include <stdio.h>

int main()
{
	int god1;
	int god2;
	int step = 1;
	printf("Vvedite niznuju i verhnuju granici godov.\n");
	scanf("%i%i", &god1, &god2);
	while (god1 <= god2)
	{
		if (god1 % 400 == 0)
		{
			printf("%i\n", god1);
			god1 += step;
			continue;
		}
		if (god1 % 100 == 0)
		{
			god1 += step;
			continue;
		}
		if (god1 % 4 == 0)
		{
			printf("%i\n", god1);
			step = 4;
			god1 += step;
			continue;
		}
		god1++;
	}
	return 0;
}
*/




/* 
#include <stdio.h>

int main()
{
	int god1;
	int god2;
	int step = 1;
	printf("Vvedite niznuju i verhnuju granici godov.\n");
	scanf("%i%i", &god1, &god2);
	while (god1 <= god2)
	{
		if (god1 % 4 == 0)
		{
			step = 4;
			if (god1 % 400 == 0)
			{
				printf("%i\n", god1);
			}
			else if (god1 % 100 == 0)
			{
				god1 += step;
				continue;
			}
			else
			{
				printf("%i\n", god1);
			}
		}
		god1 += step;
	}
}
*/






#include <stdio.h>

int main()
{
	int levelTree = 0;
	while (levelTree < 1)
	{
		printf("Vvedite vysotu jolki: ");
		scanf("%i", &levelTree);
		if (levelTree < 1)
		{
			printf("Nevozmoznaja vysota!\n");
		}
		if (levelTree > 50)
		{
			printf("jolki takie ne byvajut!=)!\n");
			levelTree = 0;
		}
	}
	int counterOfLevel = 0;
	int counterOfStick = 0;
	int counterOfWidth = 0;
	int numberOfStick = 0;
	int grade = 0;
	if (levelTree >= 6 && levelTree <= 12)
	{
		grade = 1;
		levelTree --;
	}
	if (levelTree > 12 && levelTree <= 28)
	{
		grade = 2;
		levelTree -= 2;
	}
	if (levelTree > 28)
	{
		grade = 3;
		levelTree -= 3;
	}
	int counterOfWidthForSpase = 0;
	int counterOfStickForSpase = 0;
	int numberOfStickForSpase = 0;
	int levelTreeForSpase = levelTree / 2;
	int levelTreeForCase = levelTree / 2;
	while (counterOfLevel < levelTree)
	{
		while (counterOfWidthForSpase <= levelTreeForSpase)
		{
			printf(" ");
			counterOfWidthForSpase++;
		}
		while (counterOfWidth <= counterOfLevel)
		{
			printf("**");
			counterOfWidth++;
		}
		printf("\n");
		counterOfLevel++;
		counterOfStick++;
		levelTreeForSpase--;
		counterOfWidth = numberOfStick;
		counterOfWidthForSpase = numberOfStickForSpase;

		if (counterOfStick >= 3)
		{
			counterOfWidth += 2;
			numberOfStick += 2;
			counterOfStick = 0;

			counterOfWidthForSpase -=2;
			numberOfStickForSpase -=2;
		}
	}
	int counterForCase2 = 0;
	int counterForCase3 = 0;
	switch (grade)
	{
	case 1:
		while (levelTreeForCase > -1)
		{
			printf(" ");
			levelTreeForCase--;
		}
		printf("**\n");
		break;
	case 2:
		while (counterForCase2 < 2)
		{
			levelTree = levelTreeForCase;
			while (levelTree > 0)
			{
				printf(" ");
				levelTree--;
			}
			printf("****\n");
			counterForCase2++;
		}
		break;
	case 3:
		while (counterForCase3 < 3)
		{
			levelTree = levelTreeForCase;
			while (levelTree > 1)
			{
				printf(" ");
				levelTree--;
			}
			printf("******\n");
			counterForCase3++;
		}
		break;
	default:
		break;
	}
	return 0;
}










//#include <stdio.h>
//
//int main()
//{
//	int levelTree = 0;
//	while (levelTree < 1)
//	{
//		printf("Vvedite vysotu jolki: ");
//		scanf("%i", &levelTree);
//		if (levelTree < 1)
//		{
//			printf("Nevozmoznaja vysota!\n");
//		}
//		if (levelTree > 50)
//		{
//			printf("jolki takie ne byvajut!=)!\n");
//			levelTree = 0;
//		}
//	}
//	int counterOfLevel = 0;
//	int counterOfStick = 0;
//	int counterOfWidth = 0;
//	int numberOfStick = 0;
//	int grade = 0;
//	if (levelTree >= 6 && levelTree <= 12)
//	{
//		grade = 1;
//		levelTree--;
//	}
//	if (levelTree > 12 && levelTree <= 28)
//	{
//		grade = 2;
//		levelTree -= 2;
//	}
//	if (levelTree > 28)
//	{
//		grade = 3;
//		levelTree -= 3;
//	}
//	while (counterOfLevel < levelTree)
//	{
//		while (counterOfWidth <= counterOfLevel)
//		{
//			printf("*");
//			counterOfWidth++;
//		}
//		printf("\n");
//		counterOfLevel++;
//		counterOfStick++;
//		counterOfWidth = numberOfStick;
//		if (counterOfStick >= 3)
//		{
//			counterOfWidth += 2;
//			numberOfStick += 2;
//			counterOfStick = 0;
//		}
//	}
//	switch (grade)
//	{
//	case 1:
//		printf("*\n");
//		break;
//	case 2:
//		printf("**\n**\n");
//		break;
//	case 3:
//		printf("***\n***\n***\n");
//		break;
//	default:
//		break;
//	}
//	return 0;
//}