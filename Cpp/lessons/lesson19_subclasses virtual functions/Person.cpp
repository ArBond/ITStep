#include "Person.h"

#include <iostream>

Person::Person()
{
	//std::cout << "Person constructor\n";
}

Person::Person(String const& name) :
	m_name(name)
{
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
	std::cout << "name: " << m_name << "\n";
}

Person& Person::operator=(Person const& rhs)
{
	if (this != &rhs)
	{
		m_name = rhs.m_name;
	}
	return *this;
}
void Person::Init()
{
	std::cout << "Person::Init()\n";
}