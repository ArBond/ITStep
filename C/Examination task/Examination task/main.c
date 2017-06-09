#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <string.h>
#include <time.h>

#define NAME_SIZE 101
#define RECIPE_TEXT_SIZE 10001
#define DATE_SIZE 12

enum Menu
{
	Exit,
	Look,
	Add,
	Edit,
	Delete,
	MenuEnd
};

struct Recipe
{
	char* Name;
	char* Date;
	int Rating;
};

void clearChar()
{
	char ch;
	do
	{
		ch = getchar();
	} while (ch != '\n' && ch != EOF);
}

void clearEnterSymbol(char* string)
{
	while (*string != 0)
	{
		if (*string == '\n')
		{
			*string = 0;
			return;
		}
		string++;
	}
}

enum Menu printMenuAndChooseAction()
{
	system("cls");
	printf("\nMenu:\n");
	printf(" %i - look a recipe\n %i - add a recipe\n %i - edit a recipe\n %i - delete a recipe\n %i - exit\n", Look, Add, Edit, Delete, Exit);
	enum Menu selection;
	scanf("%i", &selection);
	while (selection < Exit || selection >= MenuEnd)
	{
		printf("No such item!\n");
		scanf("%i", &selection);
	}
	return selection;
}

void printfRecipes(struct Recipe* Recipes, int recipesQuantity)
{
	printf("\t\t\t=== Recipes list===\nName:\t\tRating:\t\tDate:\n");
	for (int i = 0; i < recipesQuantity; i++)
	{
		printf("%s\t\t%i\t\t%s\n", (*(Recipes + i)).Name, Recipes[i].Rating == 0 ? Recipes[i].Rating + 10 : Recipes[i].Rating, Recipes[i].Date);
	}
}

char* getRecipeName()
{
	char* recipeName = malloc(NAME_SIZE + 8);
	clearChar();
	fgets(recipeName, NAME_SIZE, stdin);
	clearEnterSymbol(recipeName);
	return recipeName;
}

void lookRecipe(struct Recipe* Recipes, int recipesQuantity)
{
	printf("\nEnter the name of recipe which you want to look: ");
	char* recipeName = getRecipeName();
	int i;
	for (i = 0; i < recipesQuantity; i++)
	{
		if (strcmp(Recipes[i].Name, recipeName) == 0)
		{
			system("cls");
			printf("\t\t\t\t%s\n\n Text: ", recipeName);
			sprintf(recipeName, "%s%i.recipe", recipeName, Recipes[i].Rating);
			FILE* seeFile = fopen(recipeName, "rb");

			char* strBuff = malloc(256);
			fread(strBuff, 256, 1, seeFile);
			do
			{
				printf("%s", strBuff);
			} while (fread(strBuff, 256, 1, seeFile));
			fclose(seeFile);
			printf("\n Rating: %i/10\n", Recipes[i].Rating);
			printf(" Creation date: %s\n", Recipes[i].Date);
			free(strBuff);
			break;
		}
	}
	printf(i == recipesQuantity ? "Recipe not found\n" : "");
	free(recipeName);
	printf("\n Press enter to continue...");
	clearChar();
}

void addRecipe(struct Recipe* Recipes, int* recipesCounter, int* changingRecipesQuantity)
{
	if (*changingRecipesQuantity == 10)
	{
		struct Recipe* buffPointer = realloc(recipesCounter + 10, sizeof(struct Recipe));
		if (buffPointer != NULL)
		{
			Recipes = buffPointer;
			changingRecipesQuantity = 0;
			free(buffPointer);
		}
		else
		{
			return;
		}
	}
	int recipeRating;
	char* recipeName = malloc(NAME_SIZE);
	char* fileStr = malloc(NAME_SIZE + 8);
	char* recipeText = malloc(RECIPE_TEXT_SIZE);
	char* recipeDate = malloc(DATE_SIZE);
	if (recipeName == NULL || fileStr == NULL || recipeText == NULL || recipeDate == NULL)
	{
		return;
	}
	bool toContinue;
	do
	{
		toContinue = true;
		printf("Enter recipe name(%i symbols): ", NAME_SIZE - 1);
		do
		{
			fgets(recipeName, NAME_SIZE, stdin);
		} while (*recipeName == '\n');
		clearEnterSymbol(recipeName);
		for (int i = 0; i < *recipesCounter; i++)
		{
			if (strcmp(Recipes[i].Name, recipeName) == 0)
			{
				printf("File with this name already exists\n");
				toContinue = false;
				break;
			}
		}
	} while (!toContinue);
	printf("Enter the text of recipe(%i symbols): ", RECIPE_TEXT_SIZE - 1);
	do
	{
		fgets(recipeText, RECIPE_TEXT_SIZE, stdin);
	} while (*recipeText == '\n');
	printf("Enter his rating(1 - 10): ");
	scanf("%i", &recipeRating);
	while (recipeRating < 1 || recipeRating > 10)
	{
		printf("please enter rating(1 - 10)!\n");
		scanf("%i", &recipeRating);
	}
	sprintf(fileStr, "%s%i.recipe", recipeName, recipeRating == 10? recipeRating - 10 : recipeRating);
	FILE* newRecipe = fopen(fileStr, "wb");
	char* pointerOnRecipeText = recipeText;
	do
	{
		fwrite(recipeText, 256, 1, newRecipe);
		recipeText += 256;
	} while (*recipeText != -51 && recipeText - pointerOnRecipeText < RECIPE_TEXT_SIZE - 256);
	free(fileStr);
	free(pointerOnRecipeText);
	fclose(newRecipe);
	Recipes[*recipesCounter].Rating = recipeRating;
	Recipes[*recipesCounter].Name = recipeName;
	SYSTEMTIME time;
	GetSystemTime(&time);
	sprintf(recipeDate, "%02d:%02d:%d", time.wDay, time.wMonth, time.wYear);
	Recipes[*recipesCounter].Date = recipeDate;
	(*recipesCounter)++;
	clearChar();
	printf("\nRecipe edded.\n\nPress enter to continue...");
	clearChar();
}

void editRecipe(struct Recipe* Recipes, int recipesCounter)
{
	printf("\nEnter the name of recipe which you want to edit: ");
	char* recipeName = getRecipeName();
	int i;
	for (i = 0; i < recipesCounter; i++)
	{
		if (strcmp(Recipes[i].Name, recipeName) == 0)
		{
			printf("Enter new recipe text(%i symbols): ", RECIPE_TEXT_SIZE - 1);
			char* newRecipeText = malloc(RECIPE_TEXT_SIZE);
			fgets(newRecipeText, RECIPE_TEXT_SIZE, stdin);

			printf("Save changes?\n 1 - yes\t 0 - no\n");
			int choice;
			scanf("%i", &choice);
			while (choice < 0 || choice > 1)
			{
				printf("There is no such item!\n");
				scanf("%i", &choice);
			}
			if (choice == 0)
			{
				return;
			}
			sprintf(recipeName, "%s%i.recipe", Recipes[i].Name, Recipes[i].Rating);
			FILE* newRecipe = fopen(recipeName, "wb");
			char* pointerOnRecipeText = newRecipeText;
			do
			{
				fwrite(newRecipeText, 256, 1, newRecipe);
				newRecipeText += 256;
			} while (*newRecipeText != -51 && newRecipeText - pointerOnRecipeText < RECIPE_TEXT_SIZE - 256);
			free(pointerOnRecipeText);
			fclose(newRecipe);
			break;
		}
	}
	printf(i == recipesCounter? "Recipe not found\n" : "Recipe changed\n\n");
	printf("Press enter to continue...");
	clearChar();
	free(recipeName);
}

void deleteRecipe(struct Recipe* Recipes, int* recipesCounter, int* changingRecipesQuantity)
{
	printf("\nEnter the name of recipe which you want to delete: ");
	char* recipeName = getRecipeName();

	int i;
	for (i = 0; i < *recipesCounter; i++)
	{
		if (strcmp(Recipes[i].Name, recipeName) == 0)
		{
			printf("You sure?\n 1 - yes\t 0 - no\n");
			int choice;
			scanf("%i", &choice);
			while (choice < 0 || choice > 1)
			{
				printf("There is no such item!\n");
				scanf("%i", &choice);
			}
			if (choice == 0)
			{
				return;
			}
			sprintf(recipeName, "%s%i.recipe", Recipes[i].Name, Recipes[i].Rating);
			remove(recipeName);
			for (int j = i; j < *recipesCounter; j++)
			{
				Recipes[j].Name = Recipes[j + 1].Name;
				Recipes[j].Rating = Recipes[j + 1].Rating;
				Recipes[j].Date = Recipes[j + 1].Date;
			}
			free(Recipes[*recipesCounter].Name);
			free(Recipes[*recipesCounter].Date);
			(*recipesCounter)--;
			(*changingRecipesQuantity)--;
			break;
		}
	}
	free(recipeName);
	printf(i == *recipesCounter ? "Recipe not found.\n": "Recipe deleted.\n");
	printf("\n Press enter to continue...");
	clearChar();
}

struct Recipe* getRecipesWithMemoryAllocation(int* recipesCounter)
{
	struct Recipe* Recipes;
	WIN32_FIND_DATAA foundFile;
	HANDLE result = FindFirstFileA("*.recipe", &foundFile);
	if (result != INVALID_HANDLE_VALUE)
	{
		do
		{
			(*recipesCounter)++;
		} while (FindNextFileA(result, &foundFile) != 0);

		Recipes = calloc(*recipesCounter + 10, sizeof(struct Recipe));
		if (Recipes == NULL)
		{
			return NULL;
		}
		result = FindFirstFileA("*.recipe", &foundFile);
		*recipesCounter = 0;
		do
		{
			char* rating = strstr(foundFile.cFileName, ".recipe");
			rating--;
			Recipes[*recipesCounter].Rating = *rating - 48;
			*rating = 0;

			Recipes[*recipesCounter].Name = malloc(NAME_SIZE);
			strcpy((Recipes + *recipesCounter)->Name, foundFile.cFileName);

			SYSTEMTIME time;
			FileTimeToSystemTime(&foundFile.ftCreationTime, &time);
			Recipes[*recipesCounter].Date = malloc(DATE_SIZE);

			sprintf((Recipes + *recipesCounter)->Date, "%02d:%02d:%d", time.wDay, time.wMonth, time.wYear);

			(*recipesCounter)++;

		} while (FindNextFileA(result, &foundFile) != 0);
		FindClose(result);
	}
	else
	{
		Recipes = calloc(10, sizeof(struct Recipe));
	}
	return Recipes;
}

int main()
{
	printf("Welcom to 'My recipe store'!\n");
	Sleep(2000);
	int recipesQuantity = 0;
	int changingRecipesQuantity = 0;
	struct Recipe* Recipes = getRecipesWithMemoryAllocation(&recipesQuantity);
	if (recipesQuantity == 0)
	{
		printf("You dont have any recipes. Lets to create him!\n\nPress enter to continue...");
		clearChar();
		system("cls");
		addRecipe(Recipes, &recipesQuantity, &changingRecipesQuantity);
	}
	while (true)
	{
		switch (printMenuAndChooseAction())
		{
		case Look:
			system("cls");
			printfRecipes(Recipes, recipesQuantity);
			lookRecipe(Recipes, recipesQuantity);
			break;
		case Add:
			system("cls");
			addRecipe(Recipes, &recipesQuantity, &changingRecipesQuantity);
			break;
		case Edit:
			system("cls");
			printfRecipes(Recipes, recipesQuantity);
			editRecipe(Recipes, recipesQuantity);
			break;
		case Delete:
			system("cls");
			printfRecipes(Recipes, recipesQuantity);
			deleteRecipe(Recipes, &recipesQuantity, &changingRecipesQuantity);
			break;
		default:
			system("cls");
			printf("\n\t\t\t\tGood Luck!\n\n");
			return 0;
		}
	}
}