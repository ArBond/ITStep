/* Задание 3
   Написать программу определения названия свадебного юбилея в зависимости от
   продолжительности совместной жизни в браке.Пользователь вводит количество лет в
   годах, а программы вывод, является ли указанный период юбилейным и выводит его
   название в этом случае. */



#include <stdio.h>

enum Anniversary
{
	Derevjannaja = 1,
	Olovjannaja,
	Hrustalnaja,
	Farforovaja,
	Serebrjannaja,
	Zhemchuznaja,
	Polotnjanaja,
	Rubinovaja,
	Sapfirovaja,
	Zolotaja,
	Izumrudnaja,
	Brilliantovaja,
	Zeleznaja,
	Blagodatnaja,
	Koronnaja,
	Dubovaja,
	none1,
	Granitnaja,
	none2,
	Krasnaja
};

int main()
{
	enum Anniversary userChoice;
	printf("Vvedite prodolzhitelinost' sovmestnoj zhizni(let): ");
	scanf("%i", &userChoice);
	if (userChoice < 1)
	{
		printf("Error!\nNevozmozhnaja godovshina.\n");
	}
	else if (userChoice > 100)
	{
		printf("Nikto stolko v brake esho ne prozhival.\n");
	}
	else if (userChoice % 5 == 0)
	{
		printf("Jubilejnaja godovshina.\n");
		userChoice /= 5;
		switch (userChoice)
		{
		case Derevjannaja:
			printf("%i let - Derevjannaja svadba.\n", userChoice * 5);
			break;
		case Olovjannaja:
			printf("%i let - Olovjannaja svadba.\n", userChoice * 5);
			break;
		case Hrustalnaja:
			printf("%i let - Hrustalnaja svadba.\n", userChoice * 5);
			break;
		case Farforovaja:
			printf("%i let - Farforovaja svadba.\n", userChoice * 5);
			break;
		case Serebrjannaja:
			printf("%i let - Serebrjannaja svadba.\n", userChoice * 5);
			break;
		case Zhemchuznaja:
			printf("%i let - Zhemchuznaja svadba.\n", userChoice * 5);
			break;
		case Polotnjanaja:
			printf("%i let - Polotnjanaja svadba.\n", userChoice * 5);
			break;
		case Rubinovaja:
			printf("%i let - Rubinovaja svadba.\n", userChoice * 5);
			break;
		case Sapfirovaja:
			printf("%i let - Sapfirovaja svadba.\n", userChoice * 5);
			break;
		case Zolotaja:
			printf("%i let - Zolotaja svadba.\n", userChoice * 5);
			break;
		case Izumrudnaja:
			printf("%i let - Izumrudnaja svadba.\n", userChoice * 5);
			break;
		case Brilliantovaja:
			printf("%i let - Brilliantovaja svadba.\n", userChoice * 5);
			break;
		case Zeleznaja:
			printf("%i let - Zeleznaja svadba.\n", userChoice * 5);
			break;
		case Blagodatnaja:
			printf("%i let - Blagodatnaja svadba.\n", userChoice * 5);
			break;
		case Koronnaja:
			printf("%i let - Koronnaja svadba.\n", userChoice * 5);
			break;
		case Dubovaja:
			printf("%i let - Dubovaja svadba.\n", userChoice * 5);
			break;
		case Granitnaja:
			printf("%i let - Granitnaja svadba.\n", userChoice * 5);
			break;
		case Krasnaja:
			printf("%i let - Krasnaja svadba.\n", userChoice * 5);
			break;
		default:
			printf("No u nee net nazvanija.\n");
			break;
		}
	}
	else
	{
		printf("%i - Ne jubilejnaja godovshina.\n", userChoice);
	}
	return 0;
}