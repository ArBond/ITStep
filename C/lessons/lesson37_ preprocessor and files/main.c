//#include <windows.h>
//#include <stdio.h>
//#include <stdbool.h>
//#include <string.h>
//
//void main()
//{
//	WIN32_FIND_DATAA found;
//	HANDLE findResult = FindFirstFileA("D:\\prov\\*.*", &found);
//	if (findResult == INVALID_HANDLE_VALUE)
//	{
//		printf("Error!\n");
//	}
//	else
//	{
//		do
//		{
//			if (strcmp(&found.cFileName, ".") == 0 || strcmp(&found.cFileName, "..") == 0)
//			{
//				continue;
//}
//			if (found.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
//			{
//				printf("Folder: %s", &found.cFileName);
//			}
//			else
//			{
//				printf("File:  %s", &found.cFileName);
//			}
//			
//			SYSTEMTIME time;
//			FileTimeToSystemTime(&found.ftCreationTime, &time);
//			printf("\t[%d:%d:%d]\n", time.wDay, time.wMonth, time.wYear);
//
//		} while (FindNextFileA(findResult, &found) != 0);
//		FindClose(findResult);
//	}
//}


//#include <Windows.h>
//#include <stdio.h>
//#include <stdbool.h>
//
//int main()
//{
//	WIN32_FIND_DATAA found;
//	HANDLE findResult =
//		FindFirstFileA(
//			"d:\\winners\\*.jpg",
//			&found);
//
//	if (findResult == INVALID_HANDLE_VALUE)
//	{
//		printf("Files not found.");
//		return 1;
//	}
//	// WinAPI
//	do
//	{
//		if (strcmp(found.cFileName, ".") == 0 ||
//			strcmp(found.cFileName, "..") == 0)
//		{
//			continue;
//		}
//
//		SYSTEMTIME time;
//		FileTimeToSystemTime(
//			&found.ftLastAccessTime, &time);
//		printf("[%d.%d.%d] ", time.wDay, time.wMonth, time.wYear);
//		bool isDirectory =
//			found.dwFileAttributes &
//			FILE_ATTRIBUTE_DIRECTORY;
//		printf("%s found: \"%s\".\n",
//			(isDirectory ? "Folder" : "File"),
//			found.cFileName);
//	} while (FindNextFileA(findResult,
//		&found));
//
//	FindClose(findResult);
//}







//                      PREPROCESSOR

#include <stdbool.h>
#include <Windows.h>
#include <stdio.h>

#define LOD_FN_START(arg) printf("[%d] %s\n", time(0), #arg " start");
#define LOD_FN_CONTINUEING printf("[%d] %s\n", time(0), __FUNCTION__ " continue");
#define LOG_FN_END(arg) printf("[%d] %s\n", time(0), arg " end");

void foo();
void foo1();

void foo()
{
	LOD_FN_START(foo)
	Sleep(1000);
	LOD_FN_CONTINUEING
	foo1();
	LOG_FN_END("foo")
}

void foo1()
{
	LOD_FN_START(foo1)
	Sleep(1000);
	LOG_FN_END("foo1")
}

int main()
{
	LOD_FN_START(main)
	foo();
	LOG_FN_END("main")
}
