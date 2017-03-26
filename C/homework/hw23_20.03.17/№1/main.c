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

int punktSelection(int beginList, int endList);
void printBooks(struct Book* books, int positionForRecording);
void addBook(struct Book* books, int positionForRecording);
void deleteBook(struct Book* books, int positionForRecording);
void sortBooks(struct Book* books, int positionForRecording);

enum Menu
{
	BeginMenu = -1,
	Exit,
	PrintBooks,
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

enum SortDirection
{
	BeginSortDirection,
	Ascending,
	Descending,
	EndSortDirection
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
		printf("\n %i - print books\n %i - add book\n %i - delete book\n %i - sort books\n %i - exit\n", PrintBooks, AddBook, DeleteBook, Sort, Exit);
		enum Menu selection = punktSelection(BeginMenu, EndMenu);
		switch (selection)
		{
		case PrintBooks:
			if (positionForRecording > 0)
			{
				printBooks(books, positionForRecording);
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
			sortBooks(books, positionForRecording);
			printf("Books is sorted.\n");
			break;
		default:
			return;
		}
	}
}

void printBooks(struct Book* books, int positionForRecording)
{
	printf(" \tname:\tauthor:\tganre:\tyear:\n");
	for (int i = 0; i < positionForRecording; i++)
	{
		printf("book %i:\t%s\t%s\t%s\t%i\n", books[i].bookCount, books[i].name, books[i].author, books[i].genre, books[i].year);
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

void enteringBookInfo(char* title, char* bookCategory)
{
	printf("%s: ", title);
	do
	{
	fgets(bookCategory, NAME_SIZE, stdin);
	} while (*(bookCategory) == '\n');
	clearEnterSymbol(bookCategory);
}

void addBook(struct Book* books, int positionForRecording)
{
	books[positionForRecording].bookCount = positionForRecording + 1;
	printf("\nBook %i:\n", positionForRecording + 1);
	enteringBookInfo("Name", books[positionForRecording].name);
	enteringBookInfo("Author", books[positionForRecording].author);
	enteringBookInfo("Genre", books[positionForRecording].genre);
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

void swap(char* firstElement, char* secondElement)
{
	char strBuffer[NAME_SIZE];
	strcpy(strBuffer, firstElement);
	strcpy(firstElement, secondElement);
	strcpy(secondElement, strBuffer);
}

void sortBooks(struct Book* books, int positionForRecording)
{
	printf("Sort by:\n %i - name\n %i - author\n %i - genre\n %i - year\n", ByName, ByAuthor, ByGenre, ByYear);
	enum SortBy category = punktSelection(BeginSortBy, EndSortBy);
	printf("Sorting direction:\n %i - ascending\n %i - descending\n", Ascending, Descending);
	enum SortDirection sortingDirection = punktSelection(BeginSortDirection, EndSortDirection);
	int comparisonResult;
	for (int i = 0; i < positionForRecording - 1; i++)
	{
		for (int j = 0; j < positionForRecording - 1 - i; j++)
		{
			switch (category)
			{
			case ByName:
				comparisonResult = strcmp(books[j].name, books[j + 1].name);
				break;
			case ByAuthor:
				comparisonResult = strcmp(books[j].author, books[j + 1].author);
				break;
			case ByGenre:
				comparisonResult = strcmp(books[j].genre, books[j + 1].genre);
				break;
			default:
				if (books[j].year > books[j + 1].year)
				{
					comparisonResult = 1;
				}
				else if (books[j].year < books[j + 1].year)
				{
					comparisonResult = -1;
				}
			}
			if (comparisonResult > 0 && sortingDirection == Ascending || comparisonResult < 0 && sortingDirection == Descending)
			{
				swap(books[j].name, books[j + 1].name);
				swap(books[j].author, books[j + 1].author);
				swap(books[j].genre, books[j + 1].genre);
				int buffer = books[j].year;
				books[j].year = books[j + 1].year;
				books[j + 1].year = buffer;
			}
		}
	}
}

int punktSelection(int beginList, int endList)
{
	int selection;
	scanf("%i", &selection);
	while (selection <= beginList || selection >= endList)
	{
		printf("There is no such punkt!\n");
		scanf("%i", &selection);
	}
	return selection;
}