#include "Person.h"

#include <iostream>


Person::Person()
{
	std::cout << "Person default constructor\n";
}

Person::Person(String const& name) : m_name(name)
{
	std::cout << "Person constructor\n";
}

Person::~Person()
{
	std::cout << "Person destructor\n";
}

String const& Person::GetName() const
{
	return m_name;
}

void Person::SetName(String const& name)
{
	m_name = name;
}

void Person::Print() const
{
	std::cout << "Name: " << m_name << "\n";
}