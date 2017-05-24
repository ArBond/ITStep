#pragma once

class Group
{
};

class Student
{
private:
	char* m_name = 0;
	int m_rating;
	Group& m_group;

public:
	Student(Group& group);
	Student(Group& group, char const* name, int rating);
	Student(Student const& student);

	~Student();

	char const* GetName() const;
	int GetRating() const;

	void SetName(char const* name);
	void SetRating(int rating);

	void Read();
	void Print() const;

	Student& operator=(Student& student);
};