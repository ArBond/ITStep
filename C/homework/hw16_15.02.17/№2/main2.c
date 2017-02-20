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

void fillMatrix(int matrix[][MATRIX_COLUMN], int stringCount, int columnCount);
void printMatrix(int matrix[][MATRIX_COLUMN], int stringCount, int columnCount);
int printfMenuAndChooseCourseOfMoving();

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
	switch (printfMenuAndChooseCourseOfMoving())
	{
	case Right:
		printf("Right\n");
		break;
	case Left:
		printf("Left\n");
		break;
	case Up:
		printf("Up\n");
		break;
	default:
		printf("Down\n");
		break;
	}
	printf("Vot chto poluchilos'!\n\n");
	printMatrix(matrix, MATRIX_STRING, MATRIX_COLUMN);
	return 0;
}

void fillMatrix(int matrix[][MATRIX_COLUMN], int stringCount, int columnCount)
{
	srand(time(0));
	for (int i = 0; i < stringCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			matrix[i][j] = rand() % 10;
		}
	}
}

void printMatrix(int matrix[][MATRIX_COLUMN], int stringCount, int columnCount)
{
	for (int i = 0; i < stringCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			printf(" %i", matrix[i][j]);
		}
		printf("\n\n");
	}
}

int printfMenuAndChooseCourseOfMoving()
{
	printf("Kuda hotite sdvinut' elementy mstricy?\n %i - napravo\n %i - nalevo\n %i - vverh\n %i - vniz\n", Right, Left, Up, Down);
	enum Сourse selection;
	scanf("%i", &selection);
	while (selection > 4 || selection < 1)
	{
		printf("Error!\n");
		scanf("%i", &selection);
	}
	return selection;
}