//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//
//void fillArray(int* const array, int const* const size);
//void printfArray(int const* const array, int const* const size);
//
//int main()
//{
//	srand(time(0));
//	int array[5];
//	int size = 5;
//	fillArray(array, &size);
//	printf("Vash massiv:\n");
//	printfArray(array, &size);
//	return 0;
//}
//
//void fillArray(int* const array, int const* const size)
//{
//	for (int i = 0; i < *size; i++)
//	{
//		*(array + i) = rand() % 10;
//	}
//}
//
//void printfArray(int const* const array, int const* const size)
//{
//	*((int*)array) = 10;                                                // опа!
//	for (int i = 0; i < *size; i++)
//	{
//		printf("%i: %i\n", i + 1, array[i]);
//	}
//}




//                                          УКАЗАТЕЛЬ НА ФУНКЦИЮ

#include <stdio.h>
#include <windows.h>

void main()
{
	HMODULE dll = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	int(*pA)(HWND, LPCTSTR, LPCTSTR, UINT);
	pA = (int(*)(HWND, LPCTSTR, LPCTSTR, UINT))GetProcAddress(dll, "MessageBoxA");
	printf("%p\n", pA);
	pA(NULL, "Hello!", "Title", MB_HELP | MB_OKCANCEL);
}
