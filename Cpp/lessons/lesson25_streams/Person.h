#pragma once

#include <list>
#include <string>
#include <iosfwd>
#include <exception>

class Person
{
protected:
	std::string m_name;

	virtual void SaveToStream(std::ostream& stream) const;
	virtual std::string GetType() const;

public:
	Person() = default;
	Person(std::string const& name);
	virtual ~Person() = default;

	void SetName(std::string const& name);
	std::string const& GetName() const;

	virtual void Print() const;

	friend std::ostream& operator<<(std::ostream& stream, Person const& person);
};

std::ostream& operator<<(std::ostream& stream, Person const& person);

class PersonList
{
	std::list<Person*> m_data;

public:
	~PersonList();
	void Add(Person* person);
	void Print() const;
	void SaveToStream(std::ostream& stream);
	void LoadFromStream(std::istream& stream);
};