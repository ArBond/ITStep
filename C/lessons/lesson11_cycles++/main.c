#include <stdio.h>

int main()
{
	const char blackRectangle = 219;
	const char lightRectangle = 176;
	const char topLeftCornerOfTables = 218;
	const char topRightCornerOfTables = 191;
	const char lowLeftCornerOfTables = 192;
	const char lowRightCornerOfTables = 217;
	const char topSideOfTables = 194;
	const char leftSideOfTables = 195;
	const char lowSideOfTables = 193;
	const char rightSideOfTables = 182;
	const char dash = 196;
	const char verticalDash = 179;
	int maxTaskForStudent;
	printf("Skolko zadach dali trem uchenicam?\n");
	scanf("%i", &maxTaskForStudent);
	while (maxTaskForStudent < 1)
	{
		printf("Error!\n");
		scanf("%i", &maxTaskForStudent);
	}
	int progres1;
	int progres2;
	int progres3;
	printf("Skolko vypolnil 1 uchenik?\n");
	scanf("%i", &progres1);
	while (progres1 < 0 || progres1 > maxTaskForStudent)
	{
		printf("Error!\n");
		scanf("%i", &progres1);
	}
	printf("2 uchenik?\n");
	scanf("%i", &progres2);
	while (progres1 < 0 || progres1 > maxTaskForStudent)
	{
		printf("Error!\n");
		scanf("%i", &progres2);
	}
	printf("3 uchenik?\n");
	scanf("%i", &progres3);
	while (progres1 < 0 || progres1 > maxTaskForStudent)
	{
		printf("Error!\n");
		scanf("%i", &progres3);
	}
	int maxLenпthOfGafhik;
	printf("Kakaja maximalnaja dlinna grafika?\n");
	scanf("%i", &maxLenпthOfGafhik);
	while (maxLenпthOfGafhik < 2 || maxLenпthOfGafhik > 81)
	{
		printf("Error!\n");
		scanf("%i", &maxLenпthOfGafhik);
	}
	int maxTaskFor1 = maxLenпthOfGafhik * progres1 / maxTaskForStudent;
	int maxTaskFor2 = maxLenпthOfGafhik * progres2 / maxTaskForStudent;
	int maxTaskFor3 = maxLenпthOfGafhik * progres3 / maxTaskForStudent;
	printf("Vyvodim graphik:\n");
	for (int i = 0; i < maxLenпthOfGafhik + 8; i++)
	{
		if (i != 0 && i != maxLenпthOfGafhik + 7)
		{
			printf("%c", dash);
		}
		else if (i == 0)
		{
			printf("%c", topLeftCornerOfTables);
		}
		else
		{
			printf("%c", topRightCornerOfTables);
		}
	}
	printf("\n%c%c%c%c%c%c", verticalDash, topLeftCornerOfTables, dash, dash, dash, topSideOfTables);
	for (int i = 0; i < maxLenпthOfGafhik; i++)
	{
		printf("%c", dash);
	}
	printf("%c%c\n%c%c#1:%c", topRightCornerOfTables, verticalDash, verticalDash, verticalDash, verticalDash);
	for (int i = 0; i < maxLenпthOfGafhik; i++)
	{
		if (i <= maxTaskFor1)
		{
			printf("%c", blackRectangle);
		}
		else
		{
			printf("%c", lightRectangle);
		}
	}
	printf("%c%c\n%c%c%c%c%c%c", verticalDash, verticalDash, verticalDash, lowLeftCornerOfTables, dash, dash, dash, lowSideOfTables);
	for (int i = 0; i < maxLenпthOfGafhik; i++)
	{
		printf("%c", dash);
	}
	printf("%c%c\n", lowRightCornerOfTables, verticalDash);
	for (int i = 0; i < maxLenпthOfGafhik + 8; i++)
	{
		if (i != 0 && i != maxLenпthOfGafhik + 7)
		{
			printf("%c", dash);
		}
		else if (i == 0)
		{
			printf("%c", lowLeftCornerOfTables);
		}
		else
		{
			printf("%c", lowRightCornerOfTables);
		}
	}
	printf("\n");
	for (int i = 0; i < maxLenпthOfGafhik + 8; i++)
	{
		if (i != 0 && i != maxLenпthOfGafhik + 7)
		{
			printf("%c", dash);
		}
		else if (i == 0)
		{
			printf("%c", topLeftCornerOfTables);
		}
		else
		{
			printf("%c", topRightCornerOfTables);
		}
	}
	printf("\n%c%c%c%c%c%c", verticalDash, topLeftCornerOfTables, dash, dash, dash, topSideOfTables);
	for (int i = 0; i < maxLenпthOfGafhik; i++)
	{
		printf("%c", dash);
	}
	printf("%c%c\n%c%c#2:%c", topRightCornerOfTables, verticalDash, verticalDash, verticalDash, verticalDash);
	for (int i = 0; i < maxLenпthOfGafhik; i++)
	{
		if (i <= maxTaskFor2)
		{
			printf("%c", blackRectangle);
		}
		else
		{
			printf("%c", lightRectangle);
		}
	}
	printf("%c%c\n%c%c%c%c%c%c", verticalDash, verticalDash, verticalDash, lowLeftCornerOfTables, dash, dash, dash, lowSideOfTables);
	for (int i = 0; i < maxLenпthOfGafhik; i++)
	{
		printf("%c", dash);
	}
	printf("%c%c\n", lowRightCornerOfTables, verticalDash);
	for (int i = 0; i < maxLenпthOfGafhik + 8; i++)
	{
		if (i != 0 && i != maxLenпthOfGafhik + 7)
		{
			printf("%c", dash);
		}
		else if (i == 0)
		{
			printf("%c", lowLeftCornerOfTables);
		}
		else
		{
			printf("%c", lowRightCornerOfTables);
		}
	}
	printf("\n");
	for (int i = 0; i < maxLenпthOfGafhik + 8; i++)
	{
		if (i != 0 && i != maxLenпthOfGafhik + 7)
		{
			printf("%c", dash);
		}
		else if (i == 0)
		{
			printf("%c", topLeftCornerOfTables);
		}
		else
		{
			printf("%c", topRightCornerOfTables);
		}
	}
	printf("\n%c%c%c%c%c%c", verticalDash, topLeftCornerOfTables, dash, dash, dash, topSideOfTables);
	for (int i = 0; i < maxLenпthOfGafhik; i++)
	{
		printf("%c", dash);
	}
	printf("%c%c\n%c%c#3:%c", topRightCornerOfTables, verticalDash, verticalDash, verticalDash, verticalDash);
	for (int i = 0; i < maxLenпthOfGafhik; i++)
	{
		if (i <= maxTaskFor3)
		{
			printf("%c", blackRectangle);
		}
		else
		{
			printf("%c", lightRectangle);
		}
	}
	printf("%c%c\n%c%c%c%c%c%c", verticalDash, verticalDash, verticalDash, lowLeftCornerOfTables, dash, dash, dash, lowSideOfTables);
	for (int i = 0; i < maxLenпthOfGafhik; i++)
	{
		printf("%c", dash);
	}
	printf("%c%c\n", lowRightCornerOfTables, verticalDash);
	for (int i = 0; i < maxLenпthOfGafhik + 8; i++)
	{
		if (i != 0 && i != maxLenпthOfGafhik + 7)
		{
			printf("%c", dash);
		}
		else if (i == 0)
		{
			printf("%c", lowLeftCornerOfTables);
		}
		else
		{
			printf("%c", lowRightCornerOfTables);
		}
	}
	printf("\n");
	return 0;
}



// system("cls");       - очистка экрана
// system("color 1A");  - смена цвета текста консоли
// sleep(300);          - спасть (нужно подключить <windows.h>)
// system("calc");      - открыть калькулятор