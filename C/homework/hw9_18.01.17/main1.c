/* Задание 1
   Пользователь вводит число.Определить количество цифр в этом числе, посчитать их
   сумму и среднее арифметическое.Определить количество нулей в этом числе.Общение с
   пользователем организовать через меню. */



#include <stdio.h>

enum Action
{
	None,
	QuantityOfNumerals,
	SumOfNumerals,
	ArithmeticalMean,
	QuantityOfZero,
	Final
};

int main()
{
	double const maxNumber = 2147483645;
	double const minNumber = 2147483646;
	double presUserNubmer;
	int userNubmer;
	int forExit = 1;
	while (forExit > 0)
	{
		if (forExit == 1)
		{
			printf("Vvedite chislo: ");
			scanf("%lf", &presUserNubmer);
			while (presUserNubmer > maxNumber || presUserNubmer < -minNumber)
			{
				printf("Slishkom bolshoe chislo. Vvedite pozhalujsta menshee.\n");
				scanf("%lf", &presUserNubmer);
			}
			userNubmer = (int)presUserNubmer;
		}
		else
		{
			printf("Vashe chislo: %i\n", userNubmer);
		}
		int newUserNubmer;
		if (userNubmer < 0)
		{
			newUserNubmer = -userNubmer;
		}
		else
		{
			newUserNubmer = userNubmer;
		}
		printf("Chto hotite sdelat' s chislom?\n");
		printf(" %i - opredelit'kolichestvo cifr\n %i - podschitat' summu cifr\n", QuantityOfNumerals, SumOfNumerals);
		printf(" %i - podschitat' srednee arifmeticheskoe cifr\n %i - opredelit'kolichestvo nulej\n", ArithmeticalMean, QuantityOfZero);
		enum Action userChoice;
		scanf("%i", &userChoice);
		while (userChoice <= None || userChoice >= Final)
		{
			printf("Error!\nVyberite operaciju: ");
			scanf("%i", &userChoice);
		}
		switch (userChoice)
		{
		case 1:
			if (newUserNubmer < 10)
			{
				printf("Kolichestvo cifr v chisle %i = 1\n", userNubmer);
			}
			else
			{
				int numeralCounter = 0;
				for (long long i = 1; i <= newUserNubmer; i *= 10)
				{
					numeralCounter++;
				}
				printf("Kolichestvo cifr v chisle %i = %i\n", userNubmer, numeralCounter);
			}
			break;
		case 2:
			if (newUserNubmer < 10)
			{
				printf("Summa cifr v chisle %i = %i\n", userNubmer, newUserNubmer);
			}
			else
			{
				int sumOfNumerals = 0;
				for (int i = newUserNubmer; i > 0; i /= 10)
				{
					sumOfNumerals += i % 10;
				}
				printf("Summa cifr v chisle %i = %i\n", userNubmer, sumOfNumerals);
			}
			break;
		case 3:
			if (newUserNubmer < 10)
			{
				printf("Srednee arifmeticheskoe cifr v chisle %i = %i\n", userNubmer, userNubmer);
			}
			else
			{
				int numeralCounter = 0;
				int sumOfNumerals = 0;
				for (int i = newUserNubmer; i > 0; i /= 10)
				{
					numeralCounter++;
					sumOfNumerals += i % 10;
				}
				float arithmeticalMean = (float)sumOfNumerals / numeralCounter;
				printf("Srednee arifmeticheskoe cifr v chisle %i = %.2f\n", userNubmer, arithmeticalMean);
			}
			break;
		default:
			if (newUserNubmer == 0)
			{
				printf("Kolichestvo nulej v chicle 0 = 1\n");
			}
			else
			{
				int zeroCounter = 0;
				for (int i = newUserNubmer; i > 0; i /= 10)
				{
					if (i % 10 == 0)
					{
						zeroCounter++;
					}
				}
				printf("Kolichestvo nulej v chicle %i = %i\n", userNubmer, zeroCounter);
			}
		break;
		}
		printf("\n 1 - prodolzi i vvesti novoe chislo\n 2 - prodolzhit' s proslym chislom\n 0 - vyjti\n");
		scanf("%i", &forExit);
		while (forExit > 2 || forExit < 0)
		{
			printf("Error!\n");
			scanf("%i", &forExit);
		}
	}
	return 0;
}