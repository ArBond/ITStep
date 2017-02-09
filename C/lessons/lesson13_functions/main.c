
//#include <stdio.h>
//
//enum FuelType
//{
//	FuelType92,
//	FuelType95,
//	FuelType98,
//	FuelTypeDisel
//};
//
//void printCarDetails(float weight, float engineVOlume, enum FuelType fuelType);
//
//void main()
//{
//	printCarDetails(2.0, 1.6, FuelType92);
//	printCarDetails(3.0, 2,0, FuelType95);
//	printCarDetails(1.5, 1.4, FuelType98);
//	printCarDetails(1.7, 2.0, FuelTypeDisel);
//}
//
//void printCarDetails(float weight, float engineVOlume, enum FuelType fuelType)
//{
//	printf("weight: %.2f, engineVolume: %.2f, fielType: %.2f\n", weight, engineVOlume, fuelType);
//}






                             // –исование без рекурсии

//#include <stdio.h>
//
//void printStars(int starCount);
//
//void main()
//{
//	int const starCount = 10;
//	printStars(starCount);
//}
//
//void printStars(int starCount)
//{
//	for (int i = 0; i < starCount; i++)
//	{
//		printf("*");
//	}
//}






                                       // –екурсии

//#include <stdio.h>
//
//void printStars(int starCount);
//
//void main()
//{
//	int const starCount = 10;
//	printStars(starCount);
//}
//
//void printStars(int starCount)
//{
//	if (starCount > 0)
//	{
//		printf("*");
//		printStars(starCount - 1);
//	}
//}




//#include <stdio.h>
//
//long long factorial(int number);
//
//int main()
//{
//	int number;
//	printf("Factorial kakogo chisla hotite poschitat'?\n");
//	scanf("%i", &number);
//	printf("factorial %i = %ld\n", number, factorial(number));
//	return 0;
//}
//
//long long factorial(int number)
//{
//	if (number < 2)
//	{
//		return 1;
//	}
//	return number * factorial(number - 1);
//}






                                  // ќбласть видимости и врем€ жизни переменных 


#include <stdio.h>
#include "random.h"

int main()
{
	printf("maxRandNubmer = %i\n", maxRandNubmer);
	printf("rand10() = %i\n", rand10());
	return 0;
}



static int  number;  //  - объ€вление переменной глобальной