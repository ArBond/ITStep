//#include <stdio.h>
//#include <stdbool.h>
//
//int countWords(char* const userEnter);
//bool isSymbolNotSpase(char* userEnter, int i);
//
//void main()
//{
//	char userEnter[1000];
//	printf("Vvedite stroku (do 1000 simvolov): ");
//	fgets(userEnter, 1000, stdin);
//	printf("kolichestvo slov: %i\n", countWords(userEnter));
//}
//
//int countWords(char* const userEnter)
//{
//	int counterOfwords = 0;
//	int i = 0;
//	while (userEnter[i] != '\0' && userEnter[i] != '\n')
//	{
//		if (isSymbolNotSpase(userEnter, i))
//		{
//			counterOfwords++;
//			while (isSymbolNotSpase(userEnter, i))
//			{
//				i++;
//			}
//		}
//		else
//		{
//			i++;
//		}
//	}
//	return counterOfwords;
//} 
//
//bool isSymbolNotSpase(char* userEnter, int i)
//{
//	return userEnter[i] != ' ';
//}





#include <stdio.h>

#define ROW 25
#define COL 1

void main()
{
	char userEnter[100];
	printf("Vvedite stroku (do 10 simvolov): ");
	fgets(userEnter, 100, stdin);
	char matrixChar[ROW][COL];
	int matrixInt[ROW][COL];
	int elementsCounter = 0;
	int firstElementForRecording = 0;
	while (userEnter[elementsCounter] != '\0' && userEnter[elementsCounter] != '\n')
	{
		if (userEnter[elementsCounter] != ' ')
		{
			int symbol = 0;
			for (int i = 0; i < ROW; i++)
			{
				if (userEnter[elementsCounter] == matrixChar[i][0])
				{
					matrixInt[i][0]++;
					symbol++;
				}
			}
			if (symbol == 0)
			{
				matrixChar[firstElementForRecording][0] = userEnter[elementsCounter];
				matrixInt[firstElementForRecording][0] = 1;
				firstElementForRecording++;
			}
		}
		elementsCounter++;
	}


	for (int i = 0; i < firstElementForRecording; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (matrixChar[i][j] >= 'a' && matrixChar[i][j] <= 'z')
			{
				printf(" %c ", matrixChar[i][j]);
			}
			printf(" %i ", matrixInt[i][j]);
		}
		printf("\n");
	}
}
