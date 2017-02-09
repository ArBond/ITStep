#include <stdio.h>

enum Deistvie
{
	none = 0,
	zavesti,
	zaglushit,
	poehat, 
	count
};

int main()
{
	enum Deistvie userAction;
	printf("Zavesti:   %i\n", zavesti);
	printf("Zaglushit: %i\n", zaglushit);
	printf("Poehat:    %i\n", poehat);
	printf("Vvedite deistvie(1-%i): ", count-1);
	scanf("%i", &userAction);
	switch (userAction)
	{
	case zavesti:
		printf("zavesti\n");
		scanf("%i", &userAction);
		switch (userAction)
		{
		case zaglushit:
			printf("zaglushit\n");
			scanf("%i", &userAction);
			switch (userAction)
			{
			case zavesti:
				printf("zavesti\n");
				break;
			default:
				printf("Error! Mashina ze ne zavedena.\n");
				break;
			}
		case poehat:
			printf("poehat\n");
			scanf("%i", &userAction);
			switch (userAction)
			{
			case zaglushit:
				printf("zaglushit\n");
				break;
			case poehat:
				printf("poehat\n");
				break;
			default:
				printf("Error! Mashina uze zavedena.\n");
				break;
			}
		default:
			printf("Error! Mashina uze zavedena.\n");
			break;
		}
		break;
	default:
		printf("Error! Mashina ze ne zavedena.\n");
		break;
	}
	return 0;
}