/* Задание 2
   Написать программу подсчета стоимости разговора для разных мобильных операторов.
   Пользователь вводит стоимость разговора и выбирает с какого на какой оператор он
   звонит.Вывести стоимость на экран. */



#include <stdio.h>

enum Operator
{
	MTS = 1,
	Velcom,
	Life
};

int main()
{
	enum Operator userChoice;
	int minutes;
	printf("Skolko celyh minut vy razgovarivali?\n");
	scanf("%i", &minutes);
	if (minutes < 0)
	{
		printf("Error!\nNevozmoznoe kolichestvo minut.\n");
		return 1;
	}
	printf("MTS -    %i\nVelcom - %i\nLife -   %i\n", MTS, Velcom, Life);
	printf("S kakogo operatora vy zvonire?\n");
	scanf("%i", &userChoice);
	float costOfCall;
	switch (userChoice)
	{
	case MTS:
		printf("Na kakoi?\n");
		scanf("%i", &userChoice);
		float costOfMinuteInMts = 0.05;
		float costOfMinuteOutMts = 0.14;
		switch (userChoice)
		{
		case MTS:
			costOfCall = (minutes + 1) * costOfMinuteInMts;
			printf("Stoimost' minutu - %.2f\nStoimost' razgovora = %.2f rub\n", costOfMinuteInMts, costOfCall);
			break;
		case Velcom:
			costOfCall = (minutes + 1) * costOfMinuteOutMts;
			printf("Stoimost' minutu - %.2f\nStoimost' razgovora = %.2f rub\n", costOfMinuteOutMts, costOfCall);
			break;
		case Life:
			costOfCall = (minutes + 1) * costOfMinuteOutMts;
			printf("Stoimost' minutu - %.2f\nStoimost' razgovora = %.2f rub\n", costOfMinuteOutMts, costOfCall);
			break;
		default:
			printf("Error!\nVvedeno nepravilnoe chislo.\n");
			break;
		}
		break;
	case Velcom:
		printf("Na kakoi?\n");
		scanf("%i", &userChoice);
		float costOfMinuteInVelcom = 0.07;
		float costOfMinuteOutVelcom = 0.16;
		switch (userChoice)
		{
		case MTS:
			costOfCall = (minutes + 1) * costOfMinuteOutVelcom;
			printf("Stoimost' minutu - %.2f\nStoimost' razgovora = %.2f rub\n", costOfMinuteOutVelcom, costOfCall);
			break;
		case Velcom:
			costOfCall = (minutes + 1) * costOfMinuteInVelcom;
			printf("Stoimost' minutu - %.2f\nStoimost' razgovora = %.2f rub\n", costOfMinuteInVelcom, costOfCall);
			break;
		case Life:
			costOfCall = (minutes + 1) * costOfMinuteOutVelcom;
			printf("Stoimost' minutu - %.2f\nStoimost' razgovora = %.2f rub\n", costOfMinuteOutVelcom, costOfCall);
			break;
		default:
			printf("Error!\nVvedeno nepravilnoe chislo.\n");
			break;
		}
		break;
	case Life:
		printf("Na kakoi?\n");
		scanf("%i", &userChoice);
		float costOfMinuteInLife = 0.04;
		float costOfMinuteOutLife = 0.11;
		switch (userChoice)
		{
		case MTS:
			costOfCall = (minutes + 1) * costOfMinuteOutLife;
			printf("Stoimost' minutu - %.2f\nStoimost' razgovora = %.2f rub\n", costOfMinuteOutLife, costOfCall);
			break;
		case Velcom:
			costOfCall = (minutes + 1) * costOfMinuteOutLife;
			printf("Stoimost' minutu - %.2f\nStoimost' razgovora = %.2f rub\n", costOfMinuteOutLife, costOfCall);
			break;
		case Life:
			costOfCall = (minutes + 1) * costOfMinuteInLife;
			printf("Stoimost' minutu - %.2f\nStoimost' razgovora = %.2f rub\n", costOfMinuteInLife, costOfCall);
			break;
		default:
			printf("Error!\nVvedeno nepravilnoe chislo.\n");
			break;
		}
		break;
	default:
		printf("Error!\nVvedeno nepravilnoe chislo.\n");
		break;
	}
	return 0;
}