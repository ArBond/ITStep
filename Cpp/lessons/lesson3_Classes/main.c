#include "student.h"
#include <iostream>

void PrintMaxRaiting(Student s1, Student s2)
{
	std::cout << (s1.GetRating() < s2.GetRating() ? s2.GetRating() : s1.GetRating()) << "\n";
}

Student Create(Group& g, char const* name)
{
	/*int count;
	std::cin >> count;
	Student** students = new Student*[count];
	for (int i = 0; i < count; ++i)
	{
		Student* st = new Student(g);
		students[i] = st;
	}*/

	Student s(g, name, 0);
	return s;
}

void main()
{

	//Group g;
	//Student s1(g, "Petrov", 6);
	//Student s2 = s1;
	//Student s3(s1);
	//s2.SetName("Ivanov");
	//s2.SetRating(5);
	//s1.Print();
	//s2.Print();

	//PrintMaxRaiting(s1, s2);

	//Create(g, "Sidorov").Print();

	Group g;
	Student s1(g, "Petrov", 6);
	Student s2(g);
	s2 = s1;
	s1.Print();
	s2.Print();
}
