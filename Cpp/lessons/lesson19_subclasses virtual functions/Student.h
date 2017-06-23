#pragma once

#include "Person.h"
#include "String.h"

class StudentInfo
{
public:
	~StudentInfo();
};

class Student : public Person
{
private:
	int m_rating;
	StudentInfo m_info;

public:
	void Init() override;

	Student();
	Student(String const& name, int rating);
	Student(Student const& student);
	Student(Student&& student);
	//~Student();

	int GetRating() const;
	void SetRating(int rating);

	void Read();
	void Print() const override;

	Student& operator=(Student const& student);
	Student& operator=(Student&& student);
};