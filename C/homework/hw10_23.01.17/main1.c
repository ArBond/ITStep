/* Задание 1
   Написать программу, которая выводит на экран линию заданным символом,
   вертикальную или горизонтальную, причем линия может выводиться быстро, нормально и
   медленно.Общение с пользователем организовать через меню. */


#include <stdio.h>
#include <windows.h>

enum SpeedOfdrawing
{
	None,
	Slow,
	Normal,
	Fast,
	Final
};
int main()
{
	char symbolOfLine;
	printf("Narisuem linijy!\nVvedite simvol dlja linii: ");
	scanf("%c", &symbolOfLine);
	int lineType;
	printf("Kakuju liniju hotite\n 1 - verticalnuju\n 2 - gorizontalnuju\n");
	scanf("%i", &lineType);
	while (lineType > 2 || lineType < 1)
	{
		printf("Error!\nVyberite tip linii.\n");
		scanf("%i", &lineType);
	}
	int maxLength;
	if (lineType == 2)
	{
		maxLength = 80;
	}
	else
	{
		maxLength = 1000;
	}
	enum SpeedOfdrawing choiceOfSpeed;
	printf("S kakoj skorost'ju dolzhna vvoditsja linija?\n %i - medlenno\n %i - normalno\n %i - bystro\n", Slow, Normal, Fast);
	scanf("%i", &choiceOfSpeed);
	while (choiceOfSpeed >= Final || choiceOfSpeed <= None)
	{
		printf("Error!\nVyberite skorost' risovanija.\n");
		scanf("%i", &choiceOfSpeed);
	}
	switch (choiceOfSpeed)
	{
	case Slow:
		for (int i = 0; i < maxLength; i++)
		{
			printf("%c", symbolOfLine);
			if (lineType == 1)
			{
				printf("\n");
			}
			Sleep(1000);
		}
		break;
	case Normal:
		for (int i = 0; i < maxLength; i++)
		{
			printf("%c", symbolOfLine);
			if (lineType == 1)
			{
				printf("\n");
			}
			Sleep(250);
		}
		break;
	default:
		for (int i = 0; i < maxLength; i++)
		{
			printf("%c", symbolOfLine);
			if (lineType == 1)
			{
				printf("\n");
			}
			Sleep(50);
		}
		break;
	}
	return 0;
}