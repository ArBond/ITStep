/* Задание 2
   Написать программу, которая выводит на экран шахматную доску с заданным размером
   клеточки. */


#include <stdio.h>

int main()
{
	const char topLeftAngle = 218;
	const char topRightAngle = 191;
	const char lowLeftAngle = 192;
	const char lowRightAngle = 217;
	const char line = 196;
	const char verticalLine = 179;
	const int quantityOfCells = 8;
	int cellSize;
	printf("Narisuem shahmatnuju dosku!\nVvedite razmer kletki: ");
	scanf("%i", &cellSize);
	while (cellSize < 1 || cellSize > 9)
	{
		if (cellSize < 1)
		{
			printf("Nevozvozhnyj razmer!\n");
		}
		else
		{
			printf("Slishkom bolshoj razmer.\n");
		}
		scanf("%i", &cellSize);
	}
	printf("%c", topLeftAngle);
	for (int i = 0; i < quantityOfCells * cellSize; i++)
	{
		printf("%c", line);
	}
	printf("%c\n", topRightAngle);
	int counterOfCellsInWidth = 0;
	int counterOfCellsInHight = 0;
	for (int i = 0; i < quantityOfCells; i++)
	{
		for (int j = 0; j < cellSize; j++)
		{
			printf("%c", verticalLine);
			for (int k = 0; k < quantityOfCells; k++)
			{
				for (int l = 0; l < cellSize; l++)
				{
					if (counterOfCellsInHight % 2 == 0)
					{
						if (counterOfCellsInWidth % 2 == 0)
						{
							printf(" ");
						}
						else
						{
							printf("*");
						}
					}
					else
					{
						if (counterOfCellsInWidth % 2 == 0)
						{
							printf("*");
						}
						else
						{
							printf(" ");
						}
					}
				}
				counterOfCellsInWidth++;
			}
			printf("%c", verticalLine);
			printf("\n");
		}
		counterOfCellsInHight++;
	}
	printf("%c", lowLeftAngle);
	for (int i = 0; i < quantityOfCells * cellSize; i++)
	{
		printf("%c", line);
	}
	printf("%c\n", lowRightAngle);
	return 0;
}