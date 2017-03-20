#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BOOKS 3
#define NAMESIZE 20
#define AUTORSIZE 20
#define GENRESIZE 20

void sortStruct(struct Book* books);
void fillStruct(struct Book* books);
void printStruct(struct Book* books);
void clearEnterSymbol(char* books);

struct Book
{
	char name[NAMESIZE];
	char author[AUTORSIZE];
	char genre[GENRESIZE];
	int year;
};

void main()
{
	struct Book books[BOOKS];
	printf("Please, fill struct\n");
	fillStruct(books);
	printf("\n\nYour struct\n");
	printStruct(books);
	while (true)
	{
		printf("1 - sort struct\t0 - exit\n");
		int selection;
		do
		{
			scnaf("%i", &selection);
		} while (selection > 1 || selection < 0);
		if (selection == 0)
		{
			break;
		}
		else
		{
			sortStruct(books);
		}
	}
}

void fillStruct(struct Book* books)
{
	for (int i = 0; i < BOOKS; i++)
	{
		printf("\nBook %i:\n", i + 1);
		printf("Name: ");
		do
		{
			fgets(books[i].name, NAMESIZE, stdin);
		} while (books[i].name[0] == '\n');
		clearEnterSymbol(&books[i].name[0]);

		printf("Author: ");
		do
		{
			fgets(books[i].author, AUTORSIZE, stdin);
		} while (books[i].author[0] == '\n');
		clearEnterSymbol(&books[i].author[0]);

		printf("Genre: ");
		do
		{
			fgets(books[i].genre, GENRESIZE, stdin);
		} while (books[i].genre[0] == '\n');
		clearEnterSymbol(&books[i].genre[0]);

		printf("Year: ");
		scanf("%i", &books[i].year);
	}
}

void printStruct(struct Book* books)
{
	for (int j = 0; j < BOOKS; j++)
	{
		printf("Book %i:\t\t", j + 1);
	}
	printf("\n");
	for (int j = 0; j < BOOKS; j++)
	{
		printf("Name = %s\t", books[j].name);
	}
	printf("\n");
	for (int j = 0; j < BOOKS; j++)
	{
		printf("Author = %s\t", books[j].author);
	}
	printf("\n");
	for (int j = 0; j < BOOKS; j++)
	{
		printf("Genre = %s\t", books[j].genre);
	}
	printf("\n");
	for (int j = 0; j < BOOKS; j++)
	{
		printf("Year = %i\t", books[j].year);
	}
	printf("\n");
}

void clearEnterSymbol(char* books)
{
	while (*(books) != '\n')
	{
		books++;
	}
	*(books) = 0;
}

void sortStruct(struct Book* books)
{
	printf("Sort by:\n1 - name\t2 - author\n3 - gener\n4 - year\n");
	int selection;
	do
	{
		scnaf("%i", &selection);
	} while (selection > 4 || selection < 1);
	switch (selection)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}
}
