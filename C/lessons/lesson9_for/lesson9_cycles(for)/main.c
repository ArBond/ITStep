/*
do
{
	printf("...");
	scanf("...");
} while (x < y || x > z);



//     иниц.  условие  приращ.
for (int i = 0; i < 10; i++)
{
	prinf("%i", i)
}
*/








#include <stdio.h>

int main()
{
	int height;
	int width;
	printf("Vvedite vysotu pramougolnika: ");
	scanf("%i", &height);
	printf("Vvedite shirinu pramougolnika: ");
	scanf("%i", &width);
	int numberInWidth;
	int nubberInHeight;
	printf("skolko nuzno kolichestva v shirinu: ");
	scanf("%i", &numberInWidth);
	printf("skolko nuzno kolichestva v vysotu: ");
	scanf("%i", &nubberInHeight);
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == 0 || i == height - 1)
			{
				printf("*");
			}
			else
			{
				if (j == 0 || j == width - 1)
				{
					printf("*");
				}
				else
				{
					printf(" ");
				}
			}

		}
		printf("\n");
	}
	return 0;
}