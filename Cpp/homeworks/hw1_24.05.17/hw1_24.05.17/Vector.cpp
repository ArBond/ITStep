#include "Vector.h"

#include <iostream>

Vector::Vector():
	m_x(0), m_y(0), m_z(0)
{
}

Vector::Vector(float x, float y, float z):
	m_x(x), m_y(y), m_z(z)
{
}

float Vector::GetX() const
{
	return m_x;
}

float Vector::GetY() const
{
	return m_y;
}

float Vector::GetZ() const
{
	return m_z;
}

void Vector::SetValues(float x, float y, float z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

void Vector::Read()
{
	std::cout << "x: ";
	std::cin >> m_x;
	std::cout << "y: ";
	std::cin >> m_y;
	std::cout << "z: ";
	std::cin >> m_z;
}

void Vector::Print() const
{
	std::cout << " x: " << m_x << "  y: " << m_y << "  z: " << m_z << "\n";
}

void Vector::Add(Vector const& rhs)
{
	m_x += rhs.m_x;
	m_y += rhs.m_y;
	m_z += rhs.m_z;
}

float Vector::CalculateLength() const
{
	return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

float Vector::ScalarMult(Vector const& rhs) const
{
	return m_x * rhs.m_x + m_y * rhs.m_y + m_z * rhs.m_z;
}

float Vector::CalculateCos(Vector const& rhs) const
{
	return (*this).ScalarMult(rhs) / (*this).CalculateLength() * rhs.CalculateLength();
}

Vector Vector::VectorMult(Vector const& rhs) const
{
	Vector result;
	result.m_x = m_y * rhs.m_z - m_z * rhs.m_y;
	result.m_y = m_z * rhs.m_x - m_x * rhs.m_z;
	result.m_z = m_x * rhs.m_y - m_y * rhs.m_x;
	return result;
}