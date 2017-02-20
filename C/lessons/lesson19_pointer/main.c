//                 УКАЗАТЕЛИ!!!


//#include <stdio.h>
//
//int main()
//{
//	int i = 255;
//	float f = -2347.22;
//	char c = 'c';
//	double d = 62124234.2336437345;
//
//	int* pI = &i;
//	float* pF = &f;
//	char* pC = &c;
//	double* pD = &d;
//
//	printf("%i\t\t\t0x%p\tsize: %i byte\n", *pI, pI, sizeof(pI));
//	printf("%f\t\t0x%p\tsize: %i byte\n", *pF, pF, sizeof(pF));
//	printf("%c\t\t\t0x%p\tsize: %i byte\n", *pC, pC, sizeof(pC));
//	printf("%.10lf\t0x%p\tsize: %i byte\n", *pD, pD, sizeof(pD));
//
//	*pI = 100;
//
//	printf("\n%i\t\t\t0x%p\tsize: %i byte\n", *pI, pI, sizeof(pI));
//
//}




#include <stdio.h>
#include <stdlib.h>

void getTemperature(float* day1, float* day2, float* day3, float* day4, float* day5, float* day6, float* day7);
void printTemperature(float* day1, float* day2, float* day3, float* day4, float* day5, float* day6, float* day7);
void conditionCheсk(float* tepmerature);

int main()
{
	float day1;
	float day2;
	float day3;
	float day4;
	float day5;
	float day6;
	float day7;
	printf("Vvedite temperatury v techenii nedeli:\nTemperatura ne mozhet byt' bolshe 32 i men'she 0\n");
	getTemperature(&day1, &day2, &day3, &day4, &day5, &day6, &day7);
	printTemperature(&day1, &day2, &day3, &day4, &day5, &day6, &day7);
	return 0;
}

void getTemperature(float* day1, float* day2, float* day3, float* day4, float* day5, float* day6, float* day7)
{
	printf("#1: ");
	scanf("%f", day1);
	conditionCheсk(day1);
	printf("#2: ");
	scanf("%f", day2);
	conditionCheсk(day2);
	printf("#3: ");
	scanf("%f", day3);
	conditionCheсk(day3);
	printf("#4: ");
	scanf("%f", day4);
	conditionCheсk(day4);
	printf("#5: ");
	scanf("%f", day5);
	conditionCheсk(day5);
	printf("#6: ");
	scanf("%f", day6);
	conditionCheсk(day6);
	printf("#7: ");
	scanf("%f", day7);
	conditionCheсk(day7);
}

void printTemperature(float* day1, float* day2, float* day3, float* day4, float* day5, float* day6, float* day7)
{
	printf("#1: %.2f\n", *day1);
	printf("#2: %.2f\n", *day2);
	printf("#3: %.2f\n", *day3);
	printf("#4: %.2f\n", *day4);
	printf("#5: %.2f\n", *day5);
	printf("#6: %.2f\n", *day6);
	printf("#7: %.2f\n", *day7);
}

void conditionCheсk(float* tepmerature)
{
	while (*tepmerature < 0 || *tepmerature > 32)
	{
		scanf("%f", tepmerature);
	}
}
