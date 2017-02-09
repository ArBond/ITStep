/* Задание 3
   Зарплата менеджера составляет 200$ + процент от продаж, продажи до 500$ - 3 % , от 500
   до 1000 – 5 % , свыше 1000 – 8 % .Пользователь вводит с клавиатуры уровень продаж для
   трех менеджеров.Определить их зарплату, определить лучшего менеджера, начислить
   ему премию 200$, вывести итоги на экран. */

#include <stdio.h>

int main()
{
	int const baseSalary = 200;
	int const premium = 200;
	float salesOfManager1;
	float salesOfManager2;
	float salesOfManager3;
	printf("Kakaoy uroven' prodaz menedzerov(USD)?\nMenedzer1: ");
	scanf("%f", &salesOfManager1);
	printf("Menedzer2: ");
	scanf("%f", &salesOfManager2);
	printf("Menedzer3: ");
	scanf("%f", &salesOfManager3);

	int persentOfManager1;
	if (salesOfManager1 < 500)
	{
		persentOfManager1 = 3;
	}
	else if (salesOfManager1 >= 500 && salesOfManager1 < 1000)
	{
		persentOfManager1 = 5;
	}
	else
	{
		persentOfManager1 = 8;
	}
	float salaryOfMenedzer1 = baseSalary + salesOfManager1 * persentOfManager1 / 100;
	printf("Zarplata menedzera1 = %.2f$\n", salaryOfMenedzer1);

	int persentOfManager2;
	if (salesOfManager2 < 500)
	{
		persentOfManager2 = 3;
	}
	else if (salesOfManager2 >= 500 && salesOfManager2 < 1000)
	{
		persentOfManager2 = 5;
	}
	else
	{
		persentOfManager2 = 8;
	}
	float salaryOfMenedzer2 = baseSalary + salesOfManager2 * persentOfManager2 / 100;
	printf("Zarplata menedzera2 = %.2f$\n", salaryOfMenedzer2);

	int persentOfManager3;
	if (salesOfManager3 < 500)
	{
		persentOfManager3 = 3;
	}
	else if (salesOfManager3 >= 500 && salesOfManager3 < 1000)
	{
		persentOfManager3 = 5;
	}
	else
	{
		persentOfManager3 = 8;
	}
	float salaryOfMenedzer3 = baseSalary + salesOfManager3 * persentOfManager3 / 100;
	printf("Zarplata menedzera3 = %.2f$\n", salaryOfMenedzer3);

	if (salaryOfMenedzer1 > salaryOfMenedzer2 && salaryOfMenedzer1 > salaryOfMenedzer3)
	{
		printf("luchshij menedzer - menedzer1. Nachislit' emy premiju v 200$!\nEgo itogovaja zarplata: %.2f$\n", salaryOfMenedzer1 + premium);
	}
	else if (salaryOfMenedzer2 > salaryOfMenedzer1 && salaryOfMenedzer2 > salaryOfMenedzer3)
	{
		printf("luchshij menedzer - menedzer2. Nachislit' emy premiju v 200$!\nEgo itogovaja zarplata: %.2f$\n", salaryOfMenedzer2 + premium);
	}
	else
	{
		printf("luchshij menedzer - menedzer3. Nachislit' emy premiju v 200$!\nEgo itogovaja zarplata: %.2f$\n", salaryOfMenedzer3 + premium);
	}
	return 0;
}