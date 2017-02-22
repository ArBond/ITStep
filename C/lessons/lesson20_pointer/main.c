//#include <stdio.h>
//
//void swap(int* a, int* b);
//
//int main()
//{
//	int a;
//	int b;
//	printf("Vvedite 2 chisla:\n #1: ");
//	scanf("%i", &a);
//	printf(" #2: ");
//	scanf("%i", &b);
//	printf("Menjajem:\n");
//	swap(&a, &b);
//	printf(" #1 = %i\n #2 = %i\n", a, b);
//}
//
//void swap(int* a, int* b)
//{
//	int buffer = *a;
//	*a = *b;
//	*b = buffer;
//}




//					СВЯЗЬ УКАЗАТЕЛЕЙ И МАССИВОВ. ФРИФМЕТИЧЕСКИЕ ОПЕРАЦИИ

#include <stdio.h>

int main()
{
	int arr[5];
	int* pArr = arr;

	printf("&i: %p\n", arr);
	printf("&i: %p\n", &arr);
	printf("&i: %p\n", &arr[0]);

	
	for (int i = 0; i < 5; i++)
	{
		printf("i[%i]: %p\n", i, &arr[i]);
	}

	int last = &arr[5];
	for (int* i = arr; i != last; i++)
	{
		printf("%p\n", i);
	}

	int array[5] = { 1, 5, 3, 4, 2 };
	for (int i = 0; i < 5; i++)
	{
		printf("%i\n", *(array + i));
	}
}
