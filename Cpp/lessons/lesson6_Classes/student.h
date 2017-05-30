#pragma once

#include "String.h"

class Student
{
private:
	String m_name;
	int m_rating;

	static int g_count;

public:
	Student();
	Student(String const& name, int rating);
	// copy constructor
	Student(Student const& student);

	~Student();

	String const& GetName() const;
	int GetRating() const;

	void SetName(String const& name);
	void SetRating(int rating);

	void Read();
	void Print() const;

	Student& operator=(Student& student);

	static void IncreaseCounter();
	static void DecreaseCounter();
	static int GetStudentCount();
};