#include <stdio.h>
#include <windows.h>

int main()
{
		const char stem = 176;
		const char workingLight = 30;
		const char offLight = 46;
		int levelTree = 0;
		/*while (levelTree < 1 || levelTree > 50)
		{
			printf("Vvedite vysotu jolki: ");
			scanf("%i", &levelTree);
			if (levelTree < 1)
			{
				printf("Nevozmoznaja vysota!\n");
			}
			if (levelTree > 50)
			{
				printf("Jolki takie ne byvajut!=)!\n");
			}
		}*/
		int counterOfAnimation;
		system("color 02");
		for (int k = 0;; k++)
		{
			if (k % 2 == 0)
			{
				counterOfAnimation = 8;
			}
			else
			{
				counterOfAnimation = 16;
			}
			for (int i = 0; i < counterOfAnimation; i++)
			{
				int levelTree = 50;
				int grade;
				if (levelTree > 5 && levelTree <= 14)
				{
					grade = 1;
					levelTree--;
				}
				else if (levelTree > 14 && levelTree < 29)
				{
					grade = 2;
					levelTree -= 2;
				}
				else if (levelTree > 28)
				{
					grade = 3;
					levelTree -= 3;
				}
				int counterOfLevel = 0;
				int counterOfStick = 0;
				int counterOfWidth = 0;
				int numberOfStick = 0;
				int counterOfWidthForSpase = 0;
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
					while (counterOfWidth <= counterOfLevel * 2)
					{
						if (k % 2 == 0)
						{
							if (i % 4 == 0)
							{
								if (counterOfLevel < levelTree / 4)
								{
									printf("%c", workingLight);
								}
								else
								{
									printf("%c", offLight);
								}
							}
							else if (i % 4 == 1)
							{
								if (counterOfLevel >= levelTree / 2 && counterOfLevel < levelTree * 3 / 4)
								{
									printf("%c", workingLight);
								}
								else
								{
									printf("%c", offLight);
								}
							}
							else if (i % 4 == 2)
							{
								if (counterOfLevel >= levelTree / 4 && counterOfLevel < levelTree / 2)
								{
									printf("%c", workingLight);
								}
								else
								{
									printf("%c", offLight);
								}
							}
							else
							{
								if (counterOfLevel >= levelTree * 3 / 4 && counterOfLevel <= levelTree)
								{
									printf("%c", workingLight);
								}
								else
								{
									printf("%c", offLight);
								}
							}
						}
						else
						{
							if (i % 4 == 0)
							{
								if (counterOfWidth == counterOfLevel * 2 || counterOfWidth > counterOfLevel * 11 / 6)
								{
									printf("%c", workingLight);
								}
								else
								{
									printf("%c", offLight);
								}
							}
							else if (i % 4 == 1)
							{
								if (counterOfWidth <= counterOfLevel * 11 / 6 && counterOfWidth > counterOfLevel * 8 / 5)
								{
									printf("%c", workingLight);
								}
								else
								{
									printf("%c", offLight);
								}
							}
							else if (i % 4 == 2)
							{
								if (counterOfWidth <= counterOfLevel * 8 / 5 && counterOfWidth > counterOfLevel * 8 / 6)
								{
									printf("%c", workingLight);
								}
								else
								{
									printf("%c", offLight);
								}
							}
							else
							{
								if (counterOfWidth <= counterOfLevel * 7 / 5)
								{
									printf("%c", workingLight);
								}
								else
								{
									printf("%c", offLight);
								}
							}
						}
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
						counterOfWidth += 4;
						numberOfStick += 4;
						counterOfStick = 0;
						counterOfWidthForSpase -= 2;
						numberOfStickForSpase -= 2;
					}
				}
				int counterForCase = 0;
				switch (grade)
				{
				case 1:
					while (levelTreeForCase > -1)
					{
						printf(" ");
						levelTreeForCase--;
					}
					printf("%c\n", stem);
					break;
				case 2:
					while (counterForCase < 2)
					{
						levelTree = levelTreeForCase;
						while (levelTree > 0)
						{
							printf(" ");
							levelTree--;
						}
						printf("%c%c%c\n", stem, stem, stem);
						counterForCase++;
					}
					break;
				case 3:
					while (counterForCase < 3)
					{
						levelTree = levelTreeForCase;
						while (levelTree > 1)
						{
							printf(" ");
							levelTree--;
						}
						printf("%c%c%c%c%c\n", stem, stem, stem, stem, stem);
						counterForCase++;
					}
					break;
				default:
					break;
				}
				if (k % 2 == 0)
				{
					Sleep(400);
				}
				else
				{
					Sleep(200);
				}
				system("cls");
				if (i % 4 == 0)
				{
					system("color 01");
				}
				else if (i % 4 == 1)
				{
					system("color 0E");
				}
				else if (i % 4 == 2)
				{
					system("color 04");
				}
				else
				{
					system("color 02");
				}
			}
		}
	return 0;
}