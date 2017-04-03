//                              MY

//#include <stdio.h>
//#include <stdlib.h>
//
//enum FuelsType
//{
//	BeginFuels,
//	Fuel80,
//	Fuel95,
//	Fuel93,
//	Fuel91,
//	Fuel92,
//	Disel,
//	EndFuels
//};
//
//enum Colors
//{
//	BeginColor,
//	WhiteColor,
//	YellowColor,
//	RedColor,
//	BlueColor,
//	SilverColor,
//	BlueColor,
//	EndColor,
//};
//
//struct Autos
//{
//	char* mark;
//	char* model;
//	enum Colors color;
//	enum FuelsType fuelType;
//	int year;
//};
//
//#define CHAR_CHARACTERISTICS 2
//
//char*** memoryAllocForStruct(int carCount)
//{
//	char*** autosStruct = malloc(carCount * 4);
//	for (int i = 0; i < carCount; i++)
//	{
//		*(autosStruct + i) = malloc(CHAR_CHARACTERISTICS * 4);
//		for (int j = 0; j < CHAR_CHARACTERISTICS; j++)
//		{
//			*(*(autosStruct + i) + j) = malloc(50);
//		}
//	}
//	return autosStruct;
//}
//
//void freeMemoryStruct(char*** Autos, int carCount)
//{
//	for (int i = 0; i < carCount; i++)
//	{
//		for (int j = 0; j < CHAR_CHARACTERISTICS; j++)
//		{
//			free(*(*(Autos + i) + j));
//		}
//	}
//	for (int i = 0; i < carCount; i++)
//	{
//		free(*(Autos + i));
//	}
//	free(Autos);
//}
//
//void enteringCars(char*** Autos, int carCount)
//{
//
//}
//
//void printCars(char*** Autos, int carCount)
//{
//
//}
//
//void main()
//{
//	printf("How many autos you want to enter?\n");
//	int carCount;
//	scanf("%i", &carCount);
//	while (carCount <= 0)
//	{
//		printf("Quantitty of car cannot be 0 or less!\n");
//		scanf("%i", &carCount);
//	}
//	char*** Autos = memoryAllocForStruct(carCount);
//	printf("Please enter %i cars:\n", carCount);
//	enteringCars(Autos, carCount);
//	printCars(Autos, carCount);
//	freeMemoryStruct(Autos, carCount);
//}











//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//enum Color
//{
//	ColorRed = 1,
//	ColorGreen,
//	ColorBlack,
//	ColorWhile,
//	ColorGrey
//};
//
//enum FuelType
//{
//	FuelTypeBenzine80 = 1,
//	FuelTypeBenzine92,
//	FuelTypeBenzine95,
//	FuelTypeGas,
//	FuelTypeDiesel
//};
//
//struct Car
//{
//	char* Brand;
//	char* Model;
//	enum Color Color;
//	enum FuelType FuelType;
//	int Year;
//};
//
//void getString(char* message, char* st, int maxStringSize);
//void cleanInput();
//void printCarsFilteredByYear(struct Car* cars, int carsCount, int year);
//void getInt(char* message, int* value);
//
//int main()
//{
//	printf("Please enter car count: ");
//	int carCount;
//	scanf("%i", &carCount);
//	cleanInput();
//
//	struct Car* car = malloc(carCount * sizeof(struct Car));
//
//	int i = 0;
//	while (i < carCount)
//	{
//		printf("=== Please enter #%i car: ===\n", i + 1);
//		car[i].Brand = malloc(30);
//		getString("Brand: ", car[i].Brand, 30);
//		car[i].Model = malloc(30);
//		getString("Model: ", car[i].Model, 30);
//		getInt("Year: ", (int*)&car[i].Year);
//		getInt("Color: ", (int*)&car[i].Color);
//		getInt("FuelType: ", (int*)&car[i].FuelType);
//		cleanInput();
//		i++;
//	}
//
//	printf("Please enter the year: ");
//	int year;
//	scanf("%i", &year);
//
//	printCarsFilteredByYear(car, carCount, year);
//	system("pause");
//}
//
//void getString(char* message, char* st, int maxStringSize)
//{
//	char* find;
//
//	printf("%s", message);
//	char* result = fgets(st, maxStringSize, stdin);
//	if (result != NULL)
//	{
//		find = strchr(st, '\n');
//		if (find != NULL)
//		{
//			*find = 0;
//		}
//		else
//		{
//			cleanInput();
//		}
//	}
//}
//
//void getInt(char* message, int* value)
//{
//	printf("%s", message);
//	scanf("%i", value);
//}
//
//void cleanInput()
//{
//	char ch;
//	do
//	{
//		ch = getchar();
//	} while (ch != '\n' && ch != EOF);
//}
//
//void printCar(struct Car* car)
//{
//	printf("Brand:\t%s\n", car->Brand);
//	printf("Model:\t%s\n", car->Model);
//	printf("FuelType:\t%i\n", car->FuelType);
//	printf("Color:\t%i\n", car->Color);
//	printf("Year:\t%i\n\n", car->Year);
//}
//
//void printCarsFilteredByYear(struct Car* cars, int carsCount, int year)
//{
//	for (int i = 0; i < carsCount; i++)
//	{
//		if (cars[i].Year > year)
//		{
//			printCar(&cars[i]);
//		}
//	}
//}






//                MY

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ADDRESSEE_LENGTH 100
#define REASON_LENGTH 50
#define TRANSACTION_LIST_SIZE 50

enum Menu
{
	BeginMenu = -1,
	Exit,
	Pay,
	AddMoney,
	GetMoney,
	PrintTransactionList,
	Balance,
	EndMenu
};

struct TransactionList
{
	int sum;
	char* addressee;
	char* reason;
};

void addTransaction(char* Data, int sum, char* addressee, char* reason, int* transactionCount)
{

}

void main()
{
	struct TransactionList* Data = malloc(sizeof(struct TransactionList) * TRANSACTION_LIST_SIZE);
	int transactionCount = 0;
	printf("Hello! please enter your balance to start($): ");
	int sum;
	scnaf("%i", &sum);
	while (sum <= 0)
	{
		printf("Start balance cannot be 0 or less $!\nEnter you balance: ");
		scnaf("%i", &sum);
	}
	addTransaction(Data, sum, NULL, NULL, &transactionCount);
	while (true)
	{
		printf(" %i - pay\n %i - add money\n %i - get money\n %i - print transaction list\n %i - print balance\n %i - exit\n", Pay, AddMoney, GetMoney, PrintTransactionList, Balance, Exit);
		enum Menu selecton;
		scanf("%i", &selecton);
		while (selecton <= BeginMenu || selecton >= EndMenu)
		{
			printf("There is no such item!\n");
			scanf("%i", &selecton);
		}
		switch (selecton)
		{
		case Pay:
			break;
		case AddMoney:
			printf("How many money you want to add?\n");
			scnaf("%i", &sum);
			while (sum <= 0)
			{
				printf("Sum canot be 0 or less!\n");
				scnaf("%i", &sum);
			}
			addTransaction(Data, sum, NULL, NULL, &transactionCount);
			break;
		case GetMoney:
			printf("How many money you want to get?\n");
			scnaf("%i", &sum);
			while (sum <= 0)
			{
				printf("Sum canot be 0 or less!\n");
				scnaf("%i", &sum);
			}
			addTransaction(Data, sum, NULL, NULL, &transactionCount);
			break;
		case PrintTransactionList:
			break;
		case Balance:
			break;
		default:
			return;
		}
	}
	freeMemory(Data);



	//      realloc

	struct TransactionList* trans = calloc(transactionCount, sizeof(struct TransactionList));
	transactionCount++;
	struct TransactionList* transNew = realloc(transactionCount, sizeof(struct TransactionList));
	if (transNew == NULL)
	{
		printf("Cannot alloc memory\n");
	}
	else
	{
		trans = transNew;
		free(transNew);
	}

	//      realloc

}











//#include <stdlib.h>
//#include <stdbool.h>
//
//struct Transaction
//{
//	float Summ;
//	char* To;
//	char* Reason;
//};
//
//enum Operation
//{
//	Exit = 0,
//	Add,
//	Pay,
//	PrintTransactions,
//	PrintTotal
//};
//
//enum Operation getOperation()
//{
//	printf("==== Menu ====\n");
//	printf("1. Add money\n");
//	printf("2. Pay money\n");
//	printf("3. Print transactions\n");
//	printf("4. Print total\n");
//	printf("0. Exit\n\n");
//
//	enum Operation result;
//	scanf("%i", &result);
//
//	return result;
//}
//
//void addTransaction(struct Transaction* const transations,
//	int* const transactionsCount, float summ,
//	char* to, char* reason)
//{
//	transations[*transactionsCount].Summ = summ;
//	if (to != NULL)
//	{
//		transations[*transactionsCount].To = calloc(1, 100);
//		strcpy(transations[*transactionsCount].To,
//			to);
//	}
//	if (reason != NULL)
//	{
//		transations[*transactionsCount].Reason = calloc(1, 50);
//		strcpy(transations[*transactionsCount].Reason,
//			reason);
//	}
//
//	(*transactionsCount)++;
//}
//
//void printTransactions(struct Transaction* const transations,
//	int* const transactionsCount)
//{
//	printf("Summ\t| To\t| Reason\n");
//	for (int i = 0; i < *transactionsCount; i++)
//	{
//		printf("%.2f\t| %s\t| %s\n", transations[i].Summ,
//			transations[i].To ? transations[i].To : "-",
//			transations[i].Reason ? transations[i].Reason : "-");
//	}
//}
//
//void main()
//{
//	struct Transaction* transations =
//		calloc(50, sizeof(struct Transaction));
//	int transationsCount = 0;
//
//	// Add initial balans
//	float money;
//	printf("Initial balans: ");
//	scanf("%f", &money);
//	addTransaction(transations, &transationsCount, money,
//		NULL, NULL);
//
//	while (true)
//	{
//		enum Operation operation = getOperation();
//		switch (operation)
//		{
//		case Exit:
//			return;
//			break;
//		case Add:
//			printf("Add money: ");
//			scanf("%f", &money);
//			addTransaction(transations, &transationsCount, money,
//				NULL, NULL);
//			break;
//		case Pay:
//			break;
//		case PrintTransactions:
//			printTransactions(transations, &transationsCount);
//			break;
//		case PrintTotal:
//			break;
//		default:
//			break;
//		}
//	}
//}
