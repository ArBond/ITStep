//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//void main()
//{
//	FILE* file = fopen("D:\\1.bond", "r");
//	char* buff = malloc(256);
//	while (fgets(buff, 256, file))
//	{
//		char* pointer = strstr(buff, "\n");
//		if (pointer != NULL)
//		{
//			*pointer = 0;
//			printf("%s", buff);
//			break;
//		}
//		else
//		{
//			printf("%s", buff);
//		}
//	}
//	free(buff);
//	fclose(file);
//}





#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	FILE* fileFrom = fopen("D:\\main.bond", "r");

	printf("How many files you want to create: ");
	int fileQuantity;
	scanf("%i", &fileQuantity);
	while (fileQuantity < 1 || fileQuantity > 10)
	{
		printf(fileQuantity < 1 ? "Quantity can't be 0 or less.\n" : "Too many files.\n");
		scanf("%i", &fileQuantity);
	}

	printf("Enter the size of files(mb): ");
	int fileSize;
	scanf("%i", &fileSize);
	while (fileSize < 1 || fileSize > 100)
	{
		printf(fileSize < 1 ? "Size can't be 0 or less.\n" : "Too big file size.\n");
		scanf("%i", &fileSize);
	}

	char* nameBuff = malloc(10);
	char* strBuff = malloc(256);
	fgets(strBuff, 256, fileFrom);
	char* fileToName = malloc(100);

	for (int i = 0; i < fileQuantity; i++)
	{
		strcpy(fileToName, "D:\\");
		sprintf(nameBuff, "%d", i + 1);  // -  можно обойтись только этим  ->>   sprintf(fileToName, "D:\\%d.bond", i + 1);
		strcat(fileToName, nameBuff);
		strcat(fileToName, ".bond");

		FILE* fileTo = fopen(fileToName, "w");
		long position = 0;
		while (position < fileSize * 1024 * 1024)
		{
			fputs(strBuff, fileTo);
			position = ftell(fileTo);
		}
		fclose(fileTo);
	}

	free(fileToName);
	free(nameBuff);
	free(strBuff);
	fclose(fileFrom);
}


//fflush();  -  записывание сразу на физ диск (часто делать не стоит)
