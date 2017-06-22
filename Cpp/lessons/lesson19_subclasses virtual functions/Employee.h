#pragma once

#include "Person.h"
#include "String.h"

class Employee : public Person
{
private:
	int m_salary;
public:
	Employee();
	Employee(String const& name, int salary);
	~Employee();

	int GetSalary() const;
	void SetSalary(int salary);
	void Print() const override;
};