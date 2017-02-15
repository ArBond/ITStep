//#include <stdio.h>
//
//int main()
//{
//	int matrix[2][5] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			printf("matrix[%i][%i] = %i\n", i, j, matrix[i][j]);
//		}
//	}
//	return 0;
//}


//#include <stdio.h>
//
//void fillMatrix(int matrix[2][5], int rowCount, int columnCount);
//void printMatrix(int matrix[2][5], int rowCount, int columnCount);
//
//int main()
//{
//	int matrix[2][5];
//	printf("Zapolnite massiv:\n");
//	fillMatrix(matrix[2][5], 2, 5);
//	printf("Vash massiv:\n");
//	printMatrix(matrix[2][5], 2, 5);
//	return 0;
//}
//
//void fillMatrix(int matrix[2][5], int rowCount, int columnCount)
//{
//	for (int i = 0; i < rowCount; i++)
//	{
//		for (int j = 0; j < columnCount; j++)
//		{
//			printf("element [i][j]: ");
//			scanf("%i", &matrix[i][j]);
//		}
//	}
//}
//
//void printMatrix(int matrix[2][5], int rowCount, int columnCount)
//{
//	for (int i = 0; i < rowCount; i++)
//	{
//		for (int j = 0; j < columnCount; j++)
//		{
//			printf("%i  ", matrix[i][j]);
//		}
//		printf("\n");
//	}
//}


#include <stdio.h>
#include <limits.h>

#define SIZE_OF_FIRST_ARRAY 3
#define SIZE_OF_SECOND_ARRAY 5

void fillArray(int arr[], int arraySize);
void combineArrays(int firstArray[], int secondArray[], int finalMatrix[][5], int arraySize);

int main()
{
	int firstArray[SIZE_OF_FIRST_ARRAY];
	printf("zapolnite 1 massiv:\n");
	fillArray(firstArray, SIZE_OF_FIRST_ARRAY);
	int secondArray[SIZE_OF_SECOND_ARRAY];
	printf("Zapolnite 2 massiv:\n");
	fillArray(secondArray, SIZE_OF_SECOND_ARRAY);
	int finalMatrix[2][SIZE_OF_FIRST_ARRAY > SIZE_OF_SECOND_ARRAY ? SIZE_OF_FIRST_ARRAY : SIZE_OF_SECOND_ARRAY];
	int finalSize = SIZE_OF_FIRST_ARRAY > SIZE_OF_SECOND_ARRAY ? SIZE_OF_FIRST_ARRAY : SIZE_OF_SECOND_ARRAY;
	printf("Itogovyj massiv:\n");
	combineArrays(firstArray, secondArray, finalMatrix, finalSize);
	return 0;
}

void fillArray(int arr[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		printf("#%i: ", i + 1);
		scanf("%i", &arr[i]);
	}
}

void combineArrays(int firstArray[], int secondArray[], int finalMatrix[][5], int arraySize)
{
	const char dash = 45;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			if (i == 0)
			{
				finalMatrix[i][j] = j < SIZE_OF_FIRST_ARRAY ? firstArray[j] : INT_MIN;
			}
			else
			{
				finalMatrix[i][j] = j < SIZE_OF_SECOND_ARRAY ? secondArray[j] : INT_MIN;
			}
			if (finalMatrix[i][j] != INT_MIN)
			{
				printf("%i ", finalMatrix[i][j]);
			}
			else
			{
				printf("%c ", dash);
			}
		}
		printf("\n");
	}
}
