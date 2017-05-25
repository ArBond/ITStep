#include "Distance.h"

#include <iostream>

Distance::Distance()
{
	m_feet = 0;
	m_inches = 0;
}

Distance::Distance(int feet, float inches)
{
	m_feet = feet;
	m_inches = inches;
	// SetData(feet, inches);
}

Distance::Distance(int feet)
{
	m_feet = feet;
	m_inches = 0;
}

int Distance::GetFeet() const
{
	return m_feet;
}

float Distance::GetInches() const
{
	return m_inches;
}

void Distance::SetData(int feet, float inches)
{
	m_feet = feet;
	m_inches = inches;
}

void Distance::Read()
{
	std::cin >> m_feet >> m_inches;
}

void Distance::Print()
{
	std::cout << m_feet << "\'" << m_inches << "\"" << std::endl;
}

Distance Distance::operator+(Distance const& rhs)
{
	Distance result(*this);
	result += rhs;
	return result;
}

void Distance::operator+=(Distance const& rhs)
{
	m_feet += rhs.m_feet;
	m_inches += rhs.m_inches;
	if (m_inches >= 12.0f)
	{
		m_inches -= 12.0f;
		m_feet += 1;
	}
}

Distance Distance::operator-(Distance const& rhs)
{
	Distance result(*this);
	result -= rhs;
	return result;
}

void Distance::operator-=(Distance const& rhs)
{
	m_feet -= rhs.m_feet;
	m_inches -= rhs.m_inches;
	if (m_inches < 0)
	{
		m_inches += 12.0f;
		m_feet -= 1;
	}
}

Distance& Distance::operator++()
{
	m_feet++;
	return *this;
}

Distance Distance::operator++(int)
{
	Distance result(*this);
	m_feet++;
	return result;
}

float operator/(Distance const& lhs, Distance const& rhs)
{
	float inches1 = lhs.GetFeet()*12.0f + lhs.GetFeet();
	float inches2 = rhs.GetFeet()*12.0f + rhs.GetFeet();
	return inches1 / inches2;
}