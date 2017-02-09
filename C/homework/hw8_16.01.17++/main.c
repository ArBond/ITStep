/* Задание 1
   Вывести на экран фигуры, заполненные звездочками.Диалог с пользователем реализовать
   при помощи меню. */


#include <stdio.h>

int main()
{
	const char topLeftCorner = 218;
	const char topRighttCorner = 191;
	const char lowLeftCorner = 192;
	const char lowRighttCorner = 217;
	const char dash = 196;
	const char verticalDash = 179;
	const char spase = 32;
	const char star = 42;
	const int minSide = 9;
	const int maxSide = 81;
	int side;
	printf("Vvedite storonu kvadrata. Ona dolzna byt' bolshe 8 i menshe 81.\n");
	scanf("%i", &side);
	while (side < minSide || side > maxSide)
	{
		printf("Error!\nStorona kvadrata dolzna byt' bolshe 8 i menshe 81.\n");
		scanf("%i", &side);
	}
	printf("%c%c%c%c%c%c%c\n", topLeftCorner, dash, dash, dash, dash, dash, topRighttCorner);
	printf("%c\\ 1 /%c\n", verticalDash, verticalDash);
	printf("%c \\ / %c\n", verticalDash, verticalDash);
	printf("%c4 X 2%c\n", verticalDash, verticalDash);
	printf("%c / \\ %c\n", verticalDash, verticalDash);
	printf("%c/ 3 \\%c\n", verticalDash, verticalDash);
	printf("%c%c%c%c%c%c%c\n", lowLeftCorner, dash, dash, dash, dash, dash, lowRighttCorner);
	int numberOfSectors;
	printf("Vy mozhete zakrasit' 1 ili 2 sektora.\nVvedite colichestvo.\n");
	scanf("%i", &numberOfSectors);
	while (numberOfSectors < 1 || numberOfSectors > 2)
	{
		printf("Error!\nVvedite drugoe colichestvo.\n");
		scanf("%i", &numberOfSectors);
	}
	int sector1;
	int sector2;
	char symbolForSector1 = spase;
	char symbolForSector2 = spase;
	char symbolForSector3 = spase;
	char symbolForSector4 = spase;
	switch (numberOfSectors)
	{
	case 1:
		printf("Kakoj sector hotite zakrasit'?\n");
		scanf("%i", &sector1);
		while (sector1 < 1 || sector1 > 4)
		{
			printf("Error!\n");
			scanf("%i", &sector1);
		}
		break;
	default:
		printf("Kakie sectora hotite zakrasit'?\n1) ");
		scanf("%i", &sector1);
		while (sector1 < 1 || sector1 > 4)
		{
			printf("Error!\n1) ");
			scanf("%i", &sector1);
		}
		printf("2) ");
		scanf("%i", &sector2);
		while (sector2 < 1 || sector2 > 4 || sector2 == sector1)
		{
			printf("Error!\n2) ");
			scanf("%i", &sector2);
		}
		break;
	}
	switch (sector1)
	{
	case 1:
		symbolForSector1 = star;
		break;
	case 2:
		symbolForSector2 = star;
		break;
	case 3:
		symbolForSector3 = star;
		break;
	default:
		symbolForSector4 = star;
		break;
	}
	if (numberOfSectors == 2)
	{
		switch (sector2)
		{
		case 1:
			symbolForSector1 = star;
			break;
		case 2:
			symbolForSector2 = star;
			break;
		case 3:
			symbolForSector3 = star;
			break;
		default:
			symbolForSector4 = star;
			break;
		}
	}
	printf("%c", topLeftCorner);
	for (int i = 2; i < side; i++)
	{
		printf("%c", dash);
	}
	printf("%c\n", topRighttCorner);
	int counterForSlash = 1;
	int counterForBackSlash = side - 2;
	int leftCounterForTopSide = 1;
	int rightCounterForTopSide = side - 2;
	int leftCounterForLowSide = side - 2;
	int rightCounterForLowSide = 1;
	for (int i = 1; i < side - 1; i++)
	{
		for (int j = 0; j < side; j++)
		{
			if (j == 0 || j == side - 1)
			{
				printf("%c", verticalDash);
			}
			else if (i == side / 2 && j == side / 2 && side % 2 != 0)
			{
				if (numberOfSectors == 1)
				{
					switch (sector1)
					{
					case 1:
						printf("V");
						break;
					case 2:
						printf("(");
						break;
					case 3:
						printf("^");
						break;
					default:
						printf(")");
						break;
					}
				}
				else
				{
					if (sector1 == 1 && sector2 == 2 || sector1 == 2 && sector2 == 1 || sector1 == 3 && sector2 == 4 || sector1 == 4 && sector2 == 3)
					{
						printf("\\");
					}
					else if (sector1 % 2 == sector2 % 2)
					{
						printf("X");
					}
					else
					{
						printf("/");
					}
				}
			}
			else if (counterForSlash == j && numberOfSectors == 1)
			{
				switch (sector1)
				{
				case 1:
					if (i > side / 2 - 1)
					{
						printf(" ");
					}
					else
					{
						printf("\\");
					}
					break;
				case 2:
					if (j < side / 2)
					{
						printf(" ");
					}
					else
					{
						printf("\\");
					}
					break;
				case 3:
					if (i < side / 2)
					{
						printf(" ");
					}
					else
					{
						printf("\\");
					}
					break;
				default:
					if (j > side / 2 - 1)
					{
						printf(" ");
					}
					else
					{
						printf("\\");
					}
					break;
				}
			}
			else if (counterForSlash == j && numberOfSectors == 2)
			{
				if (sector1 % 2 == sector2 % 2 || sector1 == 1 && sector2 == 2 || sector1 == 2 && sector2 == 1 || sector1 == 3 && sector2 == 4 || sector1 == 4 && sector2 == 3)
				{
					printf("\\");
				}
				else
				{
					if ((sector1 == 1 || sector1 == 4) && j < side / 2)
					{
						printf("*");
					}
					else if ((sector1 == 1 || sector1 == 4) && j > side / 2 - 1)
					{
						printf(" ");
					}
					else if ((sector1 == 2 || sector1 == 3) && j > side / 2 - 1)
					{
						printf("*");
					}
					else
					{
						printf(" ");
					}
				}
			}
			else if (counterForBackSlash == j && numberOfSectors == 1)
			{
				switch (sector1)
				{
				case 1:
					if (i > side / 2 - 1)
					{
						printf(" ");
					}
					else
					{
						printf("/");
					}
					break;
				case 2:
					if (j < side / 2)
					{
						printf(" ");
					}
					else
					{
						printf("/");
					}
					break;
				case 3:
					if (i < side / 2)
					{
						printf(" ");
					}
					else
					{
						printf("/");
					}
					break;
				default:
					if (j > side / 2 - 1)
					{
						printf(" ");
					}
					else
					{
						printf("/");
					}
					break;
				}
			}
			else if (counterForBackSlash == j && numberOfSectors == 2)
			{
				if (sector1 % 2 == sector2 % 2 || sector1 == 1 && sector2 == 4 || sector1 == 4 && sector2 == 1 || sector1 == 3 && sector2 == 2 || sector1 == 2 && sector2 == 3)
				{
					printf("/");
				}
				else
				{
					if ((sector1 == 1 || sector1 == 2) && j > side / 2 - 1)
					{
						printf("*");
					}
					else if ((sector1 == 1 || sector1 == 2) && j < side / 2)
					{
						printf(" ");
					}
					else if ((sector1 == 3 || sector1 == 4) && j < side / 2)
					{
						printf("*");
					}
					else
					{
						printf(" ");
					}
				}
			}
			else
			{
				if (i < side / 2 && j > leftCounterForTopSide && j < rightCounterForTopSide)
				{
					printf("%c", symbolForSector1);
				}
				else if (i + 1 > side / 2 && j > leftCounterForLowSide && j < rightCounterForLowSide)
				{
					printf("%c", symbolForSector3);
				}
				else if (j < side / 2)
				{
					printf("%c", symbolForSector4);
				}
				else
				{
					printf("%c", symbolForSector2);
				}
			}
		}
		leftCounterForTopSide++;
		rightCounterForTopSide--;
		leftCounterForLowSide--;
		rightCounterForLowSide++;
		counterForSlash++;
		counterForBackSlash--;
		printf("\n");
	}
	printf("%c", lowLeftCorner);
	for (int i = 2; i < side; i++)
	{
		printf("%c", dash);
	}
	printf("%c\n", lowRighttCorner);
	return 0;
}