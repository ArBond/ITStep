

/*  Œœ≈–¿“Œ– SWITCH  */



//#include <stdio.h>
//
//enum color
//{
//	none = -1,
//	red = 0,
//	orange,
//	yellow,
//	green
//};
//int main()
//{
//	enum color color = none;
//	printf("Pozalujsta vvedite cod cveta(0-3):");
//	scanf("%i", &color);
//	printf("%s", color == red ? "red\n" : (color == orange ? "orange\n" : (color == yellow ? "yellow\n" : (color == green ? "green\n" : "error!\n"))));
//	return 0;
//}






//#include <stdio.h>
//
//enum color
//{
//	red = 0,
//	orange,
//	yellow,
//	green
//};
//
//
//int main()
//{
//	enum color color;
//	printf("Pozalujsta vvedite cod cveta(0-3):");
//	scanf("%i", &color);
//	switch (color)
//	{
//	case red:
//		printf("red\n");
//		break;
//	case orange:
//		printf("orange\n");
//		break;
//	case yellow:
//		printf("yellow\n");
//		break;
//	case green:
//		printf("green\n");
//		break;
//	default:
//		printf("error!\n");
//		break;
//	}
//	return 0;
//}




#include <stdio.h>

enum Gorod
{
	orsha = 1,
	brest,
	gomel,
	mogilev
};


int main()
{
	enum Gorod gorod;
	int biletov;
	int const stoimostDoOrshi = 5;
	int const stoimostDoBresta = 4;
	int const stoimostDoGomelja = 7;
	int const stoimostDoMogiljova = 6;
	printf("My v Minske. Kuda hotite poehat'?\n\n");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196);
	printf(" gorod\t\t%cprice\t\t%cnumber\t %c\n", 179, 179, 179);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196);
	printf(" Orsha\t\t%c(5 BYN)\t%c1\n Brest\t\t%c(4 BYN)\t%c2\n Gomel\t\t%c(7 BYN)\t%c3\n Mogilev\t%c(6 BYN)\t%c4\n", 179, 179, 179, 179, 179, 179, 179, 179);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196);
	scanf("%i", &gorod);
	switch (gorod)
	{
	case orsha:
		printf("Skol'ko chelivek edet?\n");
		scanf("%i", &biletov);
		printf("Poezdka obojdotsja vam v %i rub.\n", biletov * stoimostDoOrshi);
		break;
	case brest:
		printf("Skol'ko chelivek edet?\n");
		scanf("%i", &biletov);
		printf("Poezdka obojdotsja vam v %i rub.\n", biletov * stoimostDoBresta);
		break;
	case gomel:
		printf("Skol'ko chelivek edet?\n");
		scanf("%i", &biletov);
		printf("Poezdka obojdotsja vam v %i rub.\n", biletov * stoimostDoGomelja);
		break;
	case mogilev:
		printf("Skol'ko chelivek edet?\n");
		scanf("%i", &biletov);
		printf("Poezdka obojdotsja vam v %i rub.\n", biletov * stoimostDoMogiljova);
		break;
	default:
		printf("Nepravil'nyj gorod!\n");
		break;
	}
	return 0;
}