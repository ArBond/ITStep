#pragma once

#include "Person.h"

class Student : public Person
{
protected:
	int m_rating;

	void SaveToStream(std::ostream& stream) const override;
	std::string GetType() const override;

public:
	Student();
	Student(std::string const& name, int rating);
	Student(Student const& student);
	Student(Student&& student);
	~Student();

	int GetRating() const;
	void SetRating(int rating);

	void Read();
	void Print() const override;

	Student& operator=(Student const& student);
	Student& operator=(Student&& student);
};