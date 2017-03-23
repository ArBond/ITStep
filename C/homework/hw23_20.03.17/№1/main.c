/*	Задание 1:
	Разработать программу для управления библиотекой книг(имя, автор, жанр, год) со
	следующими возможностями :
	• Добавление книг
	• Вывод списка книг
	• Сортировка по заданному критерию(имя, автор, жанр, год) с указанием
	направления сортировки */



#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BOOKS_LIMIT 50
#define NAME_SIZE 20
#define AUTOR_SIZE 20
#define GENRE_SIZE 20

void printStruct(struct Book* books, int positionForRecording);
void addBook(struct Book* books, int positionForRecording);
void deleteBook(struct Book* books, int positionForRecording);
void sortStruct(struct Book* books, int positionForRecording);

void clearEnterSymbol(char* books);

enum Menu
{
	Exit,
	PrintStruct,
	AddBook,
	DeleteBook,
	Sort,
	EndMenu
};

enum SortBy
{
	BeginSortBy,
	ByName,
	ByAuthor,
	ByGenre,
	ByYear,
	EndSortBy
};

struct Book
{
	int bookCount;
	char name[NAME_SIZE];
	char author[AUTOR_SIZE];
	char genre[GENRE_SIZE];
	int year;
};

void main()
{
	struct Book books[BOOKS_LIMIT];
	int positionForRecording = 0;
	while (true)
	{
		printf(" %i - print books\n %i - add book\n %i - delete book\n %i - sort books\n %i - exit\n", PrintStruct, AddBook, DeleteBook, Sort, Exit);
		int selection;
		scanf("%i", &selection);
		while (selection < Exit || selection >= EndMenu)
		{
			printf("There is no such punkt!\n");
			scanf("%i", &selection);
		}
		switch (selection)
		{
		case PrintStruct:
			if (positionForRecording > 0)
			{
				printStruct(books, positionForRecording);
			}
			else
			{
				printf("No books in the library.\n");
			}
			break;
		case AddBook:
			if (positionForRecording < BOOKS_LIMIT)
			{
				addBook(books, positionForRecording);
				printf("Book added.\n");
				positionForRecording++;
			}
			else
			{
				printf("Library is full.\n");
			}
			break;
		case DeleteBook:
			if (positionForRecording > 0)
			{
				deleteBook(books, positionForRecording);
				printf("Book deleted.\n");
				positionForRecording--;
			}
			else
			{
				printf("No books in the library.\n");
			}
			break;
		case Sort:
			sortStruct(books, positionForRecording);
			printf("Books sorted.\n");
			break;
		default:
			return;
		}
	}
}

void printStruct(struct Book* books, int positionForRecording)
{
	printf("#:\tname\tauthor\tganre\tyear\n");
	for (int i = 0; i < positionForRecording; i++)
	{
		printf("Book %i:\t%s\t%s\t%s\t%i\n", books[i].bookCount, books[i].name, books[i].author, books[i].genre, books[i].year);
	}
}

void addBook(struct Book* books, int positionForRecording)
{
	books[positionForRecording].bookCount = positionForRecording + 1;
	printf("\nBook %i:\n", positionForRecording + 1);
	printf("Name: ");
	do
	{
		fgets(books[positionForRecording].name, NAME_SIZE, stdin);
	} while (books[positionForRecording].name[0] == '\n');
	clearEnterSymbol(&books[positionForRecording].name[0]);

	printf("Author: ");
	do
	{
		fgets(books[positionForRecording].author, AUTOR_SIZE, stdin);
	} while (books[positionForRecording].author[0] == '\n');
	clearEnterSymbol(&books[positionForRecording].author[0]);

	printf("Genre: ");
	do
	{
		fgets(books[positionForRecording].genre, GENRE_SIZE, stdin);
	} while (books[positionForRecording].genre[0] == '\n');
	clearEnterSymbol(&books[positionForRecording].genre[0]);

	printf("Year: ");
	scanf("%i", &books[positionForRecording].year);
}

void deleteBook(struct Book* books, int positionForRecording)
{
	printf("Which book do you want to delete(1 - %i): ", positionForRecording);
	int numberForDelete;
	scanf("%i", &numberForDelete);
	while (numberForDelete > positionForRecording || numberForDelete < 1)
	{
		printf("There is no such book number.\n");
		scanf("%i", &numberForDelete);
	}
	numberForDelete--;
	while (numberForDelete < positionForRecording)
	{
		strcpy(books[numberForDelete].name, books[numberForDelete + 1].name);
		strcpy(books[numberForDelete].author, books[numberForDelete + 1].author);
		strcpy(books[numberForDelete].genre, books[numberForDelete + 1].genre);
		books[numberForDelete].year = books[numberForDelete + 1].year;
		numberForDelete++;
	}
}

void sortStruct(struct Book* books, int positionForRecording)
{
	printf("Sort by:\n %i - name\n %i - author\n %i - genre\n %i - year\n", ByName, ByAuthor, ByGenre, ByYear);
	int selection;
	scanf("%i", &selection);
	while (selection <= BeginSortBy || selection >= EndSortBy)
	{
		printf("There is no such punkt!\n");
		scanf("%i", &selection);
	}
	char strBuffer[NAME_SIZE];
	for (int i = 0; i < positionForRecording; i++)
	{
		for (int j = 0; j < positionForRecording - i; j++)
		{
			int rezult = 0;
			switch (selection)
			{
			case ByName:
				rezult = strcmp(books[j].name, books[j + 1].name);
				break;
			case ByAuthor:
				rezult = strcmp(books[j].author, books[j + 1].author);
				break;
			case ByGenre:
				rezult = strcmp(books[j].genre, books[j + 1].genre);
				break;
			default:
				if (books[j].year > books[j + 1].year)
				{
					rezult = 1;
				}
			}
			if (rezult > 0)
			{
				strcpy(strBuffer, books[j].name);
				strcpy(books[j].name, books[j + 1].name);
				strcpy(books[j + 1].name, strBuffer);
				strcpy(strBuffer, books[j].author);
				strcpy(books[j].author, books[j + 1].author);
				strcpy(books[j + 1].author, strBuffer);
				strcpy(strBuffer, books[j].genre);
				strcpy(books[j].genre, books[j + 1].genre);
				strcpy(books[j + 1].genre, strBuffer);
				int buffer = books[j].year;
				books[j].year = books[j + 1].year;
				books[j + 1].year = buffer;
			}
		}
	}
}

void clearEnterSymbol(char* books)
{
	while (*(books) != '\n')
	{
		books++;
	}
	*(books) = 0;
}