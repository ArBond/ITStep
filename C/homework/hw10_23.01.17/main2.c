/* Задание 2
   Написать игру «Кубики».Пользователь и компьютер по очереди бросают 2 кубика.
   Победитель – тот, у кого по результатам 3х бросков сумма больше.Предусмотреть
   красивый интерфейс игры. */



#include <stdio.h>
#include <Windows.h>
#include <time.h>

int main()
{
	const char topLeftAngle = 218;
	const char topRightAngle = 191;
	const char lowLeftAngle = 192;
	const char lowRightAngle = 217;
	const char dash = 196;
	const char verticalDash = 179;
	const char topAngle = 194;
	const char lowAngle = 193;
	const char leftAngle = 195;
	const char rightAngle = 3;
	const char white = 219;
	const char lightGray = 178;
	const char gray = 176;
	const char star = 42;
	const char spase = 32;
	const char crossing = 197;
	const char numberSign = 252;
	int continuee;
	printf("\n\t*   *  *   *  *****  *   *  *   *  *   *\n");
	printf("\t*  *   *   *  *      *   *  *  *   *   *\n");
	printf("\t* *    *   *  *      *  **  * *    *  **\n");
	printf("\t**      ****  ****   * * *  **     * * *\n");
	printf("\t* *        *  *   *  **  *  * *    **  *\n");
	printf("\t*  *      *   *   *  *   *  *  *   *   *\n");
	printf("\t*   *  ***    ****   *   *  *   *  *   *\n\n\n");
	Sleep(1500);
	printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n      Vy i kompjuter po ocheredi brosaete 2 kubika.\n  Pobedit tot, kto za 3 broska vybrosit bol'shuju summu.\n");
	printf("\n\t\t   Prijatnoj igry!\n - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n");
	printf("%8c%c%c%c%c %26c%c%c%c%c\n", topLeftAngle, dash, dash, dash, topRightAngle, topLeftAngle, dash, dash, dash, topRightAngle);
	printf("%8c 1 %c - nachat' igru. %10c 0 %c - vyjti.\n", verticalDash, verticalDash, verticalDash, verticalDash);
	printf("%8c%c%c%c%c %26c%c%c%c%c\n", lowLeftAngle, dash, dash, dash, lowRightAngle, lowLeftAngle, dash, dash, dash, lowRightAngle);
	scanf("%i", &continuee);
	while (continuee != 0 && continuee != 1)
	{
		printf("Error!\n");
		scanf("%i", &continuee);
	}
	if (continuee == 0)
	{
		return 0;
	}
	int numberOfComputerWin = 0;
	int numberOfUserWin = 0;
	int numberOfDraw = 0;
	int action = 1;
	while (action == 1)
	{
		system("cls");
		for (int i = 0; i < 3; i++)
		{
			printf("\n\n\n\t\t\tZagruzka .");
			Sleep(400);
			system("cls");
			printf("\n\n\n\t\t\tZagruzka . .");
			Sleep(400);
			system("cls");
			printf("\n\n\n\t\t\tZagruzka . . .");
			Sleep(400);
			system("cls");
		}
		char tableSectorForUser11 = spase;
		char tableSectorForUser12 = spase;
		char tableSectorForUser21 = spase;
		char tableSectorForUser22 = spase;
		char tableSectorForUser31 = spase;
		char tableSectorForUser32 = spase;
		char tableSectorForUser41 = spase;
		char tableSectorForUser42 = 48;
		char tableSectorForPc11 = spase;
		char tableSectorForPc12 = spase;
		char tableSectorForPc21 = spase;
		char tableSectorForPc22 = spase;
		char tableSectorForPc31 = spase;
		char tableSectorForPc32 = spase;
		char tableSectorForPc41 = spase;
		char tableSectorForPc42 = 48;
		int whoIsFirst;
		printf("\n\n       Razreshit' kompjuteru brosat' kubiki pervym?\n\n\n");
		printf("%13c%c%c%c%c %14c%c%c%c%c\n", topLeftAngle, dash, dash, dash, topRightAngle, topLeftAngle, dash, dash, dash, topRightAngle);
		printf("%13c 1 %c - da. %8c 0 %c - net.\n", verticalDash, verticalDash, verticalDash, verticalDash);
		printf("%13c%c%c%c%c %14c%c%c%c%c\n", lowLeftAngle, dash, dash, dash, lowRightAngle, lowLeftAngle, dash, dash, dash, lowRightAngle);
		scanf("%i", &whoIsFirst);
		while (whoIsFirst < 0 || whoIsFirst > 1)
		{
			printf("Error!\n");
			scanf("%i", &whoIsFirst);
		}
		int userTotal = 0;
		int computerTotal = 0;
		int i;
		int throwCounter;
		if (whoIsFirst == 1)
		{
			i = 0;
			throwCounter = 6;
		}
		else
		{
			i = 1;
			throwCounter = 7;
		}
		for (; i < throwCounter; i++)
		{
			system("cls");
			char sector11 = spase;
			char sector12 = spase;
			char sector13 = spase;
			char sector14 = spase;
			char sector15 = spase;
			char sector16 = spase;
			char sector17 = spase;
			char sector18 = spase;
			char sector19 = spase;
			char sector21 = spase;
			char sector22 = spase;
			char sector23 = spase;
			char sector24 = spase;
			char sector25 = spase;
			char sector26 = spase;
			char sector27 = spase;
			char sector28 = spase;
			char sector29 = spase;
			int throwPower;
			if (whoIsFirst == 1 && i % 2 == 1 || whoIsFirst == 0 && i % 2 == 1)
			{
				printf("\n\n\t\t\tVash hod.\n\n\t\tS kakoj siloj brosaete kubiki?\n\n\n\n");
				printf("%5c%c%c%c%c  %12c%c%c%c%c  %16c%c%c%c%c\n", topLeftAngle, dash, dash, dash, topRightAngle, topLeftAngle, dash, dash, dash, topRightAngle, topLeftAngle, dash, dash, dash, topRightAngle);
				printf("%5c 1 %c - slabo.  %3c 2 %c - umerenno.  %4c 3 %c - sil'no.\n", verticalDash, verticalDash, verticalDash, verticalDash, verticalDash, verticalDash);
				printf("%5c%c%c%c%c  %12c%c%c%c%c  %16c%c%c%c%c\n", lowLeftAngle, dash, dash, dash, lowRightAngle, lowLeftAngle, dash, dash, dash, lowRightAngle, lowLeftAngle, dash, dash, dash, lowRightAngle);
				fflush(stdin);
				scanf("%i", &throwPower);
				while (throwPower > 3 || throwPower < 1)
				{
					printf("Error!\n");
					scanf("%i", &throwPower);
				}
			}
			else
			{
				srand(time(0));
				throwPower = rand() % 3 + 1;
			}
			system("cls");
			int forSleep;
			int counterOfThrowAnimation;
			switch (throwPower)
			{
			case 1:
				counterOfThrowAnimation = 3;
				forSleep = 300;
				break;
			case 2:
				counterOfThrowAnimation = 6;
				forSleep = 100;
				break;
			default:
				counterOfThrowAnimation = 9;
				forSleep = 15;
				break;
			}
			int counterOfStep = 0;
			for (int j = 0; j < counterOfThrowAnimation; j++)
			{
				if (i % 2 == 0)
				{
					printf("\n\n\t\t   Kompjuter brosaet.\n\n\n");
				}
				else
				{
					printf("\n\n\t\t     Vy brosaete.\n\n\n");
				}
				printf("\t");
				for (int l = 0; l < 2; l++)
				{
					for (int k = 0; k < counterOfStep; k++)
					{
						printf(" ");
					}
					printf(" %c%c%c%c", topLeftAngle, dash, dash, topRightAngle);
				}
				printf("\n\t");
				for (int l = 0; l < 2; l++)
				{
					for (int k = 0; k < counterOfStep; k++)
					{
						printf(" ");
					}
					printf(" %c%c%c%c", verticalDash, white, white, verticalDash);
				}
				printf("\n\t");
				for (int l = 0; l < 2; l++)
				{
					for (int k = 0; k < counterOfStep; k++)
					{
						printf(" ");
					}
					printf(" %c%c%c%c", lowLeftAngle, dash, dash, lowRightAngle);
				}
				printf("\n");
				counterOfStep++;
				Sleep(forSleep);
				forSleep += 10;
				system("cls");
				if (i % 2 == 0)
				{
					printf("\n\n\t\t   Kompjuter brosaet..\n\n\n");
				}
				else
				{
					printf("\n\n\t\t     Vy brosaete..\n\n\n");
				}
				printf("\t");
				for (int l = 0; l < 2; l++)
				{
					for (int k = 0; k < counterOfStep; k++)
					{
						printf(" ");
					}
					printf(" %c%c%c%c", topLeftAngle, topAngle, dash, topRightAngle);
				}
				printf("\n\t");
				for (int l = 0; l < 2; l++)
				{
					for (int k = 0; k < counterOfStep; k++)
					{
						printf(" ");
					}
					printf(" %c%c%c%c", verticalDash, verticalDash, lightGray, verticalDash);
				}
				printf("\n\t");
				for (int l = 0; l < 2; l++)
				{
					for (int k = 0; k < counterOfStep; k++)
					{
						printf(" ");
					}
					printf(" %c%c%c%c", lowLeftAngle, lowAngle, dash, lowRightAngle);
				}
				counterOfStep++;
				Sleep(forSleep);
				forSleep += 10;
				system("cls");
				if (i % 2 == 0)
				{
					printf("\n\n\t\t   Kompjuter brosaet...\n\n\n");
				}
				else
				{
					printf("\n\n\t\t     Vy brosaete...\n\n\n");
				}
				printf("\t");
				for (int l = 0; l < 2; l++)
				{
					for (int k = 0; k < counterOfStep; k++)
					{
						printf(" ");
					}
					printf(" %c%c%c%c", topLeftAngle, dash, topAngle, topRightAngle);
				}
				printf("\n\t");
				for (int l = 0; l < 2; l++)
				{
					for (int k = 0; k < counterOfStep; k++)
					{
						printf(" ");
					}
					printf(" %c%c%c%c", verticalDash, gray, verticalDash, verticalDash);
				}
				printf("\n\t");
				for (int l = 0; l < 2; l++)
				{
					for (int k = 0; k < counterOfStep; k++)
					{
						printf(" ");
					}
					printf(" %c%c%c%c", lowLeftAngle, dash, lowAngle, lowRightAngle);
				}
				counterOfStep++;
				Sleep(forSleep);
				forSleep += 10;
				system("cls");
			}
			int throwOfTheFirstDice;
			int throwOfTheSecondDice;
			srand(time(0));
			for (int j = 0; j < throwPower; j++)
			{
				throwOfTheFirstDice = rand() % 6 + 1;
				throwOfTheSecondDice = rand() % 6 + 1;
			}
			switch (throwOfTheFirstDice)
			{
			case 1:
				sector15 = star;
				break;
			case 2:
				sector11 = star;
				sector19 = star;
				break;
			case 3:
				sector11 = star;
				sector15 = star;
				sector19 = star;
				break;
			case 4:
				sector11 = star;
				sector13 = star;
				sector17 = star;
				sector19 = star;
				break;
			case 5:
				sector11 = star;
				sector13 = star;
				sector15 = star;
				sector17 = star;
				sector19 = star;
				break;
			default:
				sector11 = star;
				sector13 = star;
				sector14 = star;
				sector16 = star;
				sector17 = star;
				sector19 = star;
				break;
			}
			switch (throwOfTheSecondDice)
			{
			case 1:
				sector25 = star;
				break;
			case 2:
				sector21 = star;
				sector29 = star;
				break;
			case 3:
				sector21 = star;
				sector25 = star;
				sector29 = star;
				break;
			case 4:
				sector21 = star;
				sector23 = star;
				sector27 = star;
				sector29 = star;
				break;
			case 5:
				sector21 = star;
				sector23 = star;
				sector25 = star;
				sector27 = star;
				sector29 = star;
				break;
			default:
				sector21 = star;
				sector23 = star;
				sector24 = star;
				sector26 = star;
				sector27 = star;
				sector29 = star;
				break;
			}
			printf("\n\t\t    %c%c%c%c%c%c%c  %c%c%c%c%c%c%c\n", topLeftAngle, dash, dash, dash, dash, dash, topRightAngle, topLeftAngle, dash, dash, dash, dash, dash, topRightAngle);
			printf("\t\t    %c%c %c %c%c  %c%c %c %c%c\n", verticalDash, sector11, sector12, sector13, verticalDash, verticalDash, sector21, sector22, sector23, verticalDash);
			printf("\t\t    %c%c %c %c%c  %c%c %c %c%c\n", verticalDash, sector14, sector15, sector16, verticalDash, verticalDash, sector24, sector25, sector26, verticalDash);
			printf("\t\t    %c%c %c %c%c  %c%c %c %c%c\n", verticalDash, sector17, sector18, sector19, verticalDash, verticalDash, sector27, sector28, sector29, verticalDash);
			printf("\t\t    %c%c%c%c%c%c%c  %c%c%c%c%c%c%c\n\n", lowLeftAngle, dash, dash, dash, dash, dash, lowRightAngle, lowLeftAngle, dash, dash, dash, dash, dash, lowRightAngle);
			if (i % 2 == 0)
			{
				printf("\t\tKompjuter vybrosil: %i %i\n", throwOfTheFirstDice, throwOfTheSecondDice);
				computerTotal += throwOfTheFirstDice + throwOfTheSecondDice;
				if (whoIsFirst == 0)
				{
					i -= 2;
				}
				switch (i)
				{
				case 0:
					tableSectorForPc11 = throwOfTheFirstDice + 48;
					tableSectorForPc12 = throwOfTheSecondDice + 48;
					break;
				case 2:
					tableSectorForPc21 = throwOfTheFirstDice + 48;
					tableSectorForPc22 = throwOfTheSecondDice + 48;
					break;
				default:
					tableSectorForPc31 = throwOfTheFirstDice + 48;
					tableSectorForPc32 = throwOfTheSecondDice + 48;
					break;
				}
				if (whoIsFirst == 0)
				{
					i += 2;
				}
				if (computerTotal > 9)
				{
					tableSectorForPc41 = computerTotal / 10 + 48;
				}
				tableSectorForPc42 = computerTotal % 10 + 48;
			}
			else
			{
				printf("\t\t   Vy vybrosili:  %i %i\n", throwOfTheFirstDice, throwOfTheSecondDice);
				userTotal += throwOfTheFirstDice + throwOfTheSecondDice;
				switch (i)
				{
				case 1:
					tableSectorForUser11 = throwOfTheFirstDice + 48;
					tableSectorForUser12 = throwOfTheSecondDice + 48;
					break;
				case 3:
					tableSectorForUser21 = throwOfTheFirstDice + 48;
					tableSectorForUser22 = throwOfTheSecondDice + 48;
					break;
				default:
					tableSectorForUser31 = throwOfTheFirstDice + 48;
					tableSectorForUser32 = throwOfTheSecondDice + 48;
					break;
				}
				if (userTotal > 9)
				{
					tableSectorForUser41 = userTotal / 10 + 48;
				}
				tableSectorForUser42 = userTotal % 10 + 48;
			}
			printf("\n\n\t\t      Progress igry:\n");
			printf("\t%11c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", topLeftAngle, dash, dash, dash, dash, dash, topAngle, dash, dash, dash, dash, dash, topAngle, dash, dash, dash, dash, dash, topAngle, dash, dash, dash, dash, dash, topRightAngle);
			printf("\t%11c %c 1 %c %c 2 %c %c 3 %c sum %c\n", verticalDash, numberSign, verticalDash, numberSign, verticalDash, numberSign, verticalDash, verticalDash);
			printf("\t%5c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", topLeftAngle, dash, dash, dash, dash, dash, crossing, dash, dash, dash, dash, dash, crossing, dash, dash, dash, dash, dash, crossing, dash, dash, dash, dash, dash, crossing, dash, dash, dash, dash, dash, crossing);
			printf("\t%5c you %c %c %c %c %c %c %c %c %c %c  %c%c %c\n", verticalDash, verticalDash, tableSectorForUser11, tableSectorForUser12, verticalDash, tableSectorForUser21, tableSectorForUser22, verticalDash, tableSectorForUser31, tableSectorForUser32, verticalDash, tableSectorForUser41, tableSectorForUser42, verticalDash);
			printf("\t%5c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", leftAngle, dash, dash, dash, dash, dash, crossing, dash, dash, dash, dash, dash, crossing, dash, dash, dash, dash, dash, crossing, dash, dash, dash, dash, dash, crossing, dash, dash, dash, dash, dash, crossing);
			printf("\t%5c  pc %c %c %c %c %c %c %c %c %c %c  %c%c %c\n", verticalDash, verticalDash, tableSectorForPc11, tableSectorForPc12, verticalDash, tableSectorForPc21, tableSectorForPc22, verticalDash, tableSectorForPc31, tableSectorForPc32, verticalDash, tableSectorForPc41, tableSectorForPc42, verticalDash);
			printf("\t%5c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n", lowLeftAngle, dash, dash, dash, dash, dash, lowAngle, dash, dash, dash, dash, dash, lowAngle, dash, dash, dash, dash, dash, lowAngle, dash, dash, dash, dash, dash, lowAngle, dash, dash, dash, dash, dash, lowRightAngle);
			printf("%22c%c%c%c%c\n", topLeftAngle, dash, dash, dash, topRightAngle);
			printf("\t    Nazhmite %c 1 %c chtoby prodolzhit'.\n", verticalDash, verticalDash);
			printf("%22c%c%c%c%c\n", lowLeftAngle, dash, dash, dash, lowRightAngle);
			scanf("%i", &continuee);
			while (continuee != 1)
			{
				printf("Error!\n");
				scanf("%i", &continuee);
			}
		}
		system("cls");
		if (computerTotal > userTotal)
		{
			printf("\n\n\n\t\t   Kompjuter pobedil.\n\n\n");
			numberOfComputerWin++;
		}
		else if (computerTotal < userTotal)
		{
			printf("\n\n\n\t\t       Vy pobedili!\n\n\n");
			numberOfUserWin++;
		}
		else
		{
			printf("\n\n\n\t\t       Nichja...\n\n\n");
			numberOfDraw++;
		}
		printf("\tVasha summa: %i \tSumma kompjutera: %i\n\n\n\n\n\n", userTotal, computerTotal);
		printf("%4c%c%c%c%c  %12c%c%c%c%c  %16c%c%c%c%c\n", topLeftAngle, dash, dash, dash, topRightAngle, topLeftAngle, dash, dash, dash, topRightAngle, topLeftAngle, dash, dash, dash, topRightAngle);
		printf("%4c 1 %c - igrat'.  %2c 2 %c - statistika.  %2c 0 %c - vyjti.\n", verticalDash, verticalDash, verticalDash, verticalDash, verticalDash, verticalDash);
		printf("%4c%c%c%c%c  %12c%c%c%c%c  %16c%c%c%c%c\n", lowLeftAngle, dash, dash, dash, lowRightAngle, lowLeftAngle, dash, dash, dash, lowRightAngle, lowLeftAngle, dash, dash, dash, lowRightAngle);
		scanf("%i", &action);
		while (action > 2 || action < 0)
		{
			scanf("%i", &action);
		}
		if (action == 2)
		{
			system("cls");
			printf("\n\n\t\t\tStatistika:\n\n\n");
			printf("\t   wins: %i      losses: %i      draws: %i\n\n\n\n\n\n", numberOfUserWin, numberOfComputerWin, numberOfDraw);
			printf("%13c%c%c%c%c %18c%c%c%c%c\n", topLeftAngle, dash, dash, dash, topRightAngle, topLeftAngle, dash, dash, dash, topRightAngle);
			printf("%13c 1 %c - igrat'. %8c 0 %c - vyjti.\n", verticalDash, verticalDash, verticalDash, verticalDash);
			printf("%13c%c%c%c%c %18c%c%c%c%c\n", lowLeftAngle, dash, dash, dash, lowRightAngle, lowLeftAngle, dash, dash, dash, lowRightAngle);
			scanf("%i", &action);
			while (action > 1 || action < 0)
			{
				scanf("%i", &action);
			}
		}
	}
	return 0;
}