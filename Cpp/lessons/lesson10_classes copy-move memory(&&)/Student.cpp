#include "Student.h"

#include <cstring>
#include <iostream>

Student::Student() :
	m_rating(0)
{
}

Student::Student(String const& name, int rating) :
	m_name(name),
	m_rating(rating)
{
	std::cout << "Student constructor with param\n";
}

Student::Student(Student const& student) :
	m_rating(student.m_rating)
{
	std::cout << "Student copy constructor\n";
	m_name = student.m_name;
}

Student::Student(Student&& student) :
	m_name(std::move(student.m_name)),
	m_rating(student.m_rating)
{
	std::cout << "Student move constructor\n";
}

Student::~Student()
{
	std::cout << "Student destructor\n";
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
	std::cout << "Student copy operator=\n";
	if (this == &student)
	{
		return *this;
	}
	this->m_name = student.m_name;
	this->m_rating = student.GetRating();
	return *this;
}