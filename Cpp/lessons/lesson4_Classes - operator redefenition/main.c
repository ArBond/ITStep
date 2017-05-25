#include "student.h"
#include "example.h"
#include "distance.h"
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
	Group g;
	Student s1(g, "Ivanov", 6);
	Student s2 = s1;
	Student s3(s1);

	std::cout << "count = " << Student::GetStudentCount() << "\n";

	s2.SetName("Petrov");
	s2.SetRating(5);
	s1.Print();
	s2.Print();

	PrintMaxRaiting(s1, s2);
	Student* s5;
	{
		s5 = new Student(g);
		Student s4 = Create(g, "Sidorov");
		s4.Print();
		std::cout << "count = " << Student::GetStudentCount() << "\n";
	}
	std::cout << "count = " << Student::GetStudentCount() << "\n";
	delete s5;
	std::cout << "count = " << Student::GetStudentCount() << "\n";

	Logger::GetInstance()->Log("hello");
	Logger::GetInstance()->Log("world");

	Distance d1(1, 2);
	Distance d2(3, 4);
	Distance d3 = d1 + d2;
	d3.Print();
}
