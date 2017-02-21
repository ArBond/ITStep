/* Задание 2: Создайте двухмерный массив.Заполните его случайными числами и покажите
   на экран.
   Пользователь выбирает количество сдвигов и положение(влево, вправо, вверх, вниз).
   Выполнить сдвиг массива и показать на экран полученный результат.Сдвиг циклический.
   Например, если мы имеем следующий массив
   1 2 0 4 5 3
   4 5 3 9 0 1
   и пользователь выбрал сдвиг на 2 разряда вправо, то мы получим
   5 3 1 2 0 4
   0 1 4 5 3 9 */



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_STRING 5
#define MATRIX_COLUMN 8

void fillMatrix(int matrix[][MATRIX_COLUMN], int string, int column);
void printMatrix(int matrix[][MATRIX_COLUMN], int string, int column);
int printfMenuAndChooseCourseOfMoving();
void moveMatrix(int matrix[][MATRIX_COLUMN], int string, int column, int step, enum Сourse selection);

enum Сourse
{
	Right = 1,
	Left,
	Up,
	Down
};

int main()
{
	int matrix[MATRIX_STRING][MATRIX_COLUMN];
	fillMatrix(matrix, MATRIX_STRING, MATRIX_COLUMN);
	printf("Vasha matrica:\n\n");
	printMatrix(matrix, MATRIX_STRING, MATRIX_COLUMN);
	int toContinue = 1;
	while (toContinue != 0)
	{
		enum Сourse selection = printfMenuAndChooseCourseOfMoving();
		printf("Na skol'ko shagov hotite sdvinut': ");
		int step;
		scanf("%i", &step);
		while (step < 0)
		{
			printf("Ne mozhet byt' oricatel'nym\n");
			scanf("%i", &step);
		}
		switch (selection)
		{
		case Right:
			moveMatrix(matrix, MATRIX_STRING, MATRIX_COLUMN, step, selection);
			break;
		case Left:
			moveMatrix(matrix, MATRIX_STRING, MATRIX_COLUMN, step, selection);
			break;
		case Up:
			moveMatrix(matrix, MATRIX_STRING, MATRIX_COLUMN, step, selection);
			break;
		default:
			moveMatrix(matrix, MATRIX_STRING, MATRIX_COLUMN, step, selection);
			break;
		}
		printf("Vot chto poluchilos'!\n\n");
		printMatrix(matrix, MATRIX_STRING, MATRIX_COLUMN);
		printf(" 1 - prodolzhit'\n 0 - vyjti\n");
		scanf("%i", &toContinue);
		while (toContinue > 1 || toContinue < 0)
		{
			printf("Error!\n");
			scanf("%i", &toContinue);
		}
	}
	return 0;
}

void fillMatrix(int matrix[][MATRIX_COLUMN], int string, int column)
{
	srand(time(0));
	for (int i = 0; i < string; i++)
	{
		for (int j = 0; j < column; j++)
		{
			matrix[i][j] = rand() % 10;
		}
	}
}

void printMatrix(int matrix[][MATRIX_COLUMN], int string, int column)
{
	for (int i = 0; i < string; i++)
	{
		for (int j = 0; j < column; j++)
		{
			printf(" %i", matrix[i][j]);
		}
		printf("\n\n");
	}
}

int printfMenuAndChooseCourseOfMoving()
{
	printf("Kuda hotite sdvinut' elementy mstricy?\n %i - napravo\n %i - nalevo\n %i - vverh\n %i - vniz\n", Right, Left, Up, Down);
	int selection;
	scanf("%i", &selection);
	while (selection > 4 || selection < 1)
	{
		printf("Error!\n");
		scanf("%i", &selection);
	}
	return selection;
}

void moveMatrix(int matrix[][MATRIX_COLUMN], int string, int column, int step, enum Сourse selection)
{
	int border = string;
	if (selection == Up || selection == Down)
	{
		border = column;
	}
	int realStep = step - border * (step / border);
	for (int stepCount = 0; stepCount < realStep; stepCount++)
	{
		for (int i = 0; i < border; i++)
		{
			switch (selection)
			{
			case Right:;
				int buffer = matrix[i][column - 1];
				for (int j = column - 1; j > 0; j--)
				{
					matrix[i][j] = matrix[i][j - 1];
				}
				matrix[i][0] = buffer;
				break;
			case Left:;
				buffer = matrix[i][0];
				for (int j = 0; j < column - 1; j++)
				{
					matrix[i][j] = matrix[i][j + 1];
				}
				matrix[i][column - 1] = buffer;
				break;
			case Up:;
				buffer = matrix[0][i];
				for (int j = 0; j < string - 1; j++)
				{
					matrix[j][i] = matrix[j + 1][i];
				}
				matrix[string - 1][i] = buffer;
				break;
			default:;
				buffer = matrix[string - 1][i];
				for (int j = string - 1; j > 0; j--)
				{
					matrix[j][i] = matrix[j - 1][i];
				}
				matrix[0][i] = buffer;
				break;
			}
		}
	}
}