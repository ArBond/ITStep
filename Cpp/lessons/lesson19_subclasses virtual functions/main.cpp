#include "Student.h"
#include "String.h"
#include "Employee.h"
#include "animals.h"

#include <iostream>

#define _CRT_SECURE_NO_WARNINGS


void PrintPerson(Person const& person)
{
	person.Print();
}

void PrintType(Pet* pet)
{
	Cat* cat = dynamic_cast<Cat*>(pet);
	if(cat)
	{
		std::cout << "This is a cat\n";
		return;
	}
	Dog* dog = dynamic_cast<Dog*>(pet);
	if (dog)
	{
		std::cout << "This is a dog\n";
		return;
	}
	std::cout << "Uncnown animal!\n";
}

void main()
{
	/*Student st1("Ivanov", 5);
	Employee emp1("Petrov", 1000);

	std::cout << "\n";
	st1.Print();
	emp1.Print();
	std::cout << "\n";
	PrintPerson(st1);
	PrintPerson(emp1);
	std::cout << "\n";*/

	/*Employee emp1("Ivanov", 400);
	Employee emp2("Sidorov", 500);
	emp1 = emp2;*/


	/*Cat cat;
	StrokeTheCat(cat);
	Dog dog;
	KickTheDog(dog);

	CatDog catdog;
	StrokeTheCat(catdog);
	KickTheDog(catdog);

	PrintType(&dog);*/


	Person* person = new Student();
	delete person;
}