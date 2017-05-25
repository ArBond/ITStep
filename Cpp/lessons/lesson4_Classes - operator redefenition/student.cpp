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

Student::Student(Group& group) :
	m_group(group),
	m_rating(0)
{
	IncreaseCounter();
	m_name = new char[1];
	m_name[0] = '\0';
}

Student::Student(Group& group, char const* name, int rating) :
	m_name(NULL),
	m_group(group),
	m_rating(rating)
{
	IncreaseCounter();
	SetName(name);
}

Student::Student(Student const& student) :
	m_group(student.m_group),
	m_rating(student.m_rating)
{
	IncreaseCounter();
	std::cout << "Copy\n";
	SetName(student.GetName());
}

Student::~Student()
{
	DecreaseCounter();
	delete[] m_name;
}

char const* Student::GetName() const
{
	return m_name;
}

int Student::GetRating() const
{
	return m_rating;
}

void Student::SetName(char const* name)
{
	delete[] m_name;
	size_t length = strlen(name);
	m_name = new char[length + 1];
	strcpy(m_name, name);
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
	IncreaseCounter();
	this->SetName(student.GetName());
	this->m_rating = student.GetRating();
	return *this;
}