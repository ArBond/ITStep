#include "Student.h"

#include <cstring>
#include <iostream>


int Student::g_count = 0;

void Student::IncreaseCounter()
{
	++g_count;
}
void Student::DecreaseCounter()
{
	--g_count;
}

int Student::GetStudentCount()
{
	return g_count;
}

Student::Student() :
	m_rating(0)
{
	IncreaseCounter();
}

Student::Student(String const& name, int rating) :
	m_name(name),
	m_rating(rating)
{
	IncreaseCounter();
}

Student::Student(Student const& student) :
	m_rating(student.m_rating)
{
	IncreaseCounter();
	std::cout << "copy ctor\n";
	m_name = student.m_name;
}

Student::~Student()
{
	DecreaseCounter();
}

String const& Student::GetName() const
{
	return m_name;
}

int Student::GetRating() const
{
	return m_rating;
}

void Student::SetName(String const& name)
{
	m_name = name;
}

void Student::SetRating(int rating)
{
	m_rating = rating;
}

void Student::Read()
{
	std::cout << "Enter name: ";
	char buffer[21];
	std::cin.getline(buffer, 20);
	SetName(buffer);
	std::cout << "Enter rating: ";
	std::cin >> m_rating;
}

void Student::Print() const
{
	std::cout << m_name << ": " << m_rating << "\n";
}

Student& Student::operator=(Student& student)
{
	if (this == &student)
	{
		return *this;
	}
	this->m_name = student.m_name;
	this->m_rating = student.GetRating();
	return *this;
}