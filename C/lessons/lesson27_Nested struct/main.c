//								ВЛОЖЕННЫЕ СТРУКТУРЫ


//#include <stdio.h>
//#include <locale.h>
//#include <string.h>
//
//struct Folder
//{
//	char Name[256];
//	struct Folder* Children;
//	int ChildrenCount;
//};
//
//void addFolder(struct Folder* folder, char* newFolderName)
//{
//	if (folder->Children == NULL)
//	{
//		printf("Error: array is not initialized. Folder: %s\n",
//			folder->Name);
//		return;
//	}
//	struct Folder* newChild =
//		&folder->Children[folder->ChildrenCount];
//	strcpy(newChild->Name, newFolderName);
//	newChild->Children = NULL;
//	newChild->ChildrenCount = 0;
//	folder->ChildrenCount++;
//}
//
//int main()
//{
//	setlocale(LC_ALL, "rus");
//
//	struct Folder diskCFolders[20];
//	struct Folder amdFolders[20];
//	struct Folder apacheFolders[20];
//
//	struct Folder diskC;
//	strcpy(diskC.Name, "C:");
//	diskC.ChildrenCount = 0;
//	diskC.Children = diskCFolders;
//
//	addFolder(&diskC, "AMD");
//
//	struct Folder* amd = &diskC.Children[0];
//	amd->Children = amdFolders;
//	amd->ChildrenCount = 0;
//	addFolder(amd, "SDFF");
//	addFolder(amd, "dsf");
//	addFolder(amd, "234234");
//
//	addFolder(&diskC, "Apache24");
//	diskC.Children[1].Children = apacheFolders;
//	addFolder(&diskC.Children[1], "12345");
//	addFolder(&diskC.Children[1], "123");
//	addFolder(&diskC.Children[1], "dfgfg");
//	addFolder(&diskC.Children[1], "t4545t");
//	addFolder(&diskC, "inetpub");
//
//	printf("%s\n", diskC.Name);
//	for (int i = 0; i < diskC.ChildrenCount; i++)
//	{
//		struct Folder* child = &diskC.Children[i];
//		printf("\t%s\n", child->Name);
//		for (int j = 0; j < child->ChildrenCount; j++)
//		{
//			if (child->Children != NULL)
//			{
//				printf("\t\t%s\n", child->Children[j].Name);
//			}
//		}
//	}
//	return 0;
//}




//							ОБЪЕДЕНЕНИЕ 

//struct Carstruct
//{
//	char model[50];
//	char make[50];
//	int year;
//};
//
//union Car
//{
//	char model[50];
//	char make[50];
//	int year;
//};
//
//void main()
//{
//	printf("struct size: %i\n", sizeof(struct Carstruct));
//	printf("union size: %i\n", sizeof(union Car));
//	union Car car1;
//	strcpy(car1.model, "x5");
//	union Car car2;
//	strcpy(car2.make, "BMW");
//	printf("%s\n", car1.make);
//	printf("%s\n", car2.make);
//}


struct CarStruct
{
	char model[50];
	char make[50];
	int year;
};

enum DataType
{
	Model,
	Make,
	Year,
	Pointer
};

union CarData
{
	char model[50];
	char make[50];
	int year;
	char* pointer;
};

struct Car
{
	union CarData carData;
	enum DataType dataType;
};

int main()
{
	struct Car car1;
	car1.carData.year = 1098;
	car1.dataType = Year;

	/*car1.carData.pointer = &car1;
	car1.dataType = Pointer;*/

	switch (car1.dataType)
	{
	case Year:
		printf("%i\n", car1.carData.year);
		break;
	case Pointer:
		printf("%p\n", car1.carData.pointer);
		break;
	default:
		break;
	}

	struct Car car2;
	strcpy(car2.carData.make, "BMW");

	printf("%s\n", car2.carData.model);
	printf("%s\n", car2.carData.make);
}
