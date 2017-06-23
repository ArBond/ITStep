#include "Employee.h"

#include <iostream>


Employee::Employee()
{
	std::cout << "Employee constructor default\n";
}

Employee::Employee(String const& name, int salary):
	Person(name),
	m_salary(salary)
{
	std::cout << "Employee constructor\n";
}

Employee::~Employee()
{
	std::cout << "Employee destructor\n";
}

int Employee::GetSalary() const
{
	return m_salary;
}

void Employee::SetSalary(int salary)
{
	m_salary = salary;
}

void Employee::Print() const
{
	Person::Print();
	std::cout << "Salary: " << m_salary << "\n";
}

Employee& Employee::operator=(Employee const& employee)
{
	if (this != &employee)
	{
		this->Person::operator=(employee);
		m_salary = employee.m_salary;
	}
	return *this;
}