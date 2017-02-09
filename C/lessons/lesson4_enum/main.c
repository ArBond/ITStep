#include<stdio.h>
#include<stdbool.h>
enum Operator
{
	MTS = 1,
	Velcom,
	Life
};

int main()
{
	/*printf("Vvedite kilometry: ");
	int km = 0;
	scanf("%i", &km);
	printf("%i km\n", km);                               
	int num = 13;
	printf("%i / 2 = %i\n", num, num / 2);
	printf("%i %% 2 = %i\n", num, num % 2); */

	/*int num = 0; 
	printf("%i", num > 0 || num < 0);
	printf("%i", num >= 0);
	printf("%i", num <= 0);*/ 

	int god;
	printf("Vvedite god: "); 
	scanf("%i", &god);
	printf("%i - %s", god, god % 4 == 0 && (god % 100 !=0 || god % 400 == 0)? "visokosnyj god\n" : "ne visocosnyj god\n");  /*  <-- почему-то не очень ему понравилось */

	/*enum Operator operatorFrom = MTS;
	printf("%s\n", operatorFrom == MTS ? "MTS" : "Ne MTS");
	printf("%s\n", operatorFrom == Velcom ? "Velcom" : "Ne Velcom");
	printf("%s\n\n", operatorFrom == Life ? "Life" : "Ne Life");*/

	/*enum Operator operatorTo;
	printf("Kuda zvonim?\nMTS - 1\nVelcom - 2\nLife - 3\n");
	scanf("%i", &operatorTo);
	printf("%s\n", operatorTo == MTS ? "MTS" : (operatorTo == Velcom ? "Velcom" : (operatorTo == Life? "Life" : "Nepravil'nyj operator")));*/

	/*приведение типов*/

	float number = (float)5 / 7; /*явное приведение*/
	int num = 6.36;  /*неявное приведение*/
}