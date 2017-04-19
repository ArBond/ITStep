//#include <stdio.h>
//#include <stdlib.h>
//
//void writeToFile(char* string)
//{
//	FILE* file = fopen("D:\\binary.bond", "wb");
//	scanf("%s", string);
//	fwrite(string, 256, 1, file);
//	fclose(file);
//}
//
//void readFile(char* string)
//{
//	FILE* file = fopen("D:\\binary.bond", "rb");
//	fread(string, 256, 1, file);
//	printf("%s\n", string);
//	fclose(file);
//}
//
//void clearBuff(char* string)
//{
//	while (*string != 0)
//	{
//		*string = 0;
//		string++;
//	}
//}
//
//void main()
//{
//	char* buff = malloc(256);
//	printf("Please enter string: ");
//	writeToFile(buff);
//	clearBuff(buff);
//	printf("Your string: ");
//	readFile(buff);
//	free(buff);
//}





//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//#define STRING_LENGTH 50
//
//void writeString(char* string, int position, char* file)
//{
//	scanf("%s", string);
//	fseek(file, position, SEEK_SET);
//	fwrite(string, STRING_LENGTH, 1, file);
//}
//
//void getAndWriteToFile(char* string)
//{
//	FILE* file = fopen("D:\\binary.bin", "wb");
//	printf("Surname: ");
//	writeString(string, 0, file);
//	printf("Name: ");
//	writeString(string, 58, file);
//	printf("Middle name: ");
//	writeString(string, 120, file);
//	fclose(file);
//}
//
//void readAndPrintString(char* string, int position, char* file)
//{
//	fseek(file, position, SEEK_SET);
//	fread(string, STRING_LENGTH, 1, file);
//	printf("%s\n", string);
//}
//
//bool readFile(char* string)
//{
//	FILE* file = fopen("D:\\binary.bin", "rb");
//	if (file == NULL)
//	{
//		return false;
//	}
//	printf("Surname: ");
//	readAndPrintString(string, 0, file);
//	printf("Name: ");
//	readAndPrintString(string, 58, file);
//	printf("Middle name: ");
//	readAndPrintString(string, 120, file);
//	fclose(file);
//	return true;
//}
//
//void main()
//{
//	char* string = malloc(STRING_LENGTH);
//	if (!readFile(string))
//	{
//		getAndWriteToFile(string);
//		printf("\nYour file:\n");
//		readFile(string);
//	}
//	free(string);
//}











//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <locale.h>
//
//#define FILE_SIZE 170
//#define STRING_SIZE 50
//
//enum StringPositions
//{
//	FirstNamePosition = 0,
//	LastNamePosition = 57,
//	MiddleNamePosition = 119,
//};
//
//void writeString(char* string, int offset,
//	FILE* f)
//{
//	fseek(f, offset, SEEK_SET);
//	fwrite(string, STRING_SIZE, 1, f);
//}
//
//void readString(char* string, int offset,
//	FILE* f)
//{
//	fseek(f, offset, SEEK_SET);
//	fread(string, STRING_SIZE, 1, f);
//}
//
//int main()
//{
//	setlocale(LC_ALL, "rus");
//	FILE* f = fopen("d:\\t.bin", "rb");
//	char* buff = malloc(FILE_SIZE);
//
//	if (f == NULL)
//	{
//		// need to write
//		f = fopen("d:\\t.bin", "wb");
//		memset(buff, 0, FILE_SIZE);
//		fwrite(buff, FILE_SIZE, 1, f);
//
//		strcpy(buff, "Sergey");
//		writeString(buff, FirstNamePosition,
//			f);
//		strcpy(buff, "Gradovich");
//		writeString(buff, LastNamePosition,
//			f);
//		strcpy(buff, "Pavlovich");
//		writeString(buff, MiddleNamePosition,
//			f);
//	}
//	else
//	{
//		// need to read
//		readString(buff, FirstNamePosition, f);
//		printf("FirstName: %s\n", buff);
//		readString(buff, LastNamePosition, f);
//		printf("LastName: %s\n", buff);
//		readString(buff, MiddleNamePosition, f);
//		printf("MiddleName: %s\n", buff);
//
//	}
//
//	fclose(f);
//}





#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

#define FILE_SIZE 170
#define STRING_SIZE 50

struct FIO
{
	char FirstName[53];
	int k;
	char LastName[58];
	char MiddleName[50];
	bool b;
};

enum StringPositions
{
	FirstNamePosition = 0,
	LastNamePosition = 57,
	MiddleNamePosition = 119,
};

void writeString(char* string, int offset,
	FILE* f)
{
	fseek(f, offset, SEEK_SET);
	fwrite(string, STRING_SIZE, 1, f);
}

void readString(char* string, int offset,
	FILE* f)
{
	fseek(f, offset, SEEK_SET);
	fread(string, STRING_SIZE, 1, f);
}

int main()
{
	setlocale(LC_ALL, "rus");
	FILE* f = fopen("d:\\t.bin", "wb");

	/*double pi = 3.14;
	fwrite(&pi, sizeof(double), 1, f);
	long long n = 2378462378;
	fwrite(&n, sizeof(long long), 1, f);*/

	struct FIO fio = { "Vasya", 678, "Pupkin",
		"Vasilyevich", true };
	fwrite(&fio, sizeof(struct FIO),
		1, f);

	fclose(f);
	///////////////////

	f = fopen("d:\\t.bin", "rb");

	/*double pi2;
	fread(&pi2, sizeof(double), 1, f);
	long long n2;
	fread(&n2, sizeof(long long), 1, f);*/

	struct FIO fio2;
	fread(&fio2, sizeof(struct FIO),
		1, f);

	printf("%s\n", fio2.FirstName);
	printf("%s\n", fio2.LastName);
	printf("%s\n", fio2.MiddleName);
	printf("%i\n", fio2.k);
	printf("%i\n", fio2.b);

	fclose(f);
}
