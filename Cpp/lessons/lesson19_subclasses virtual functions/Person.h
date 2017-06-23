#pragma once

#include "String.h"

class Person
{
protected:
	String m_name;
public:
	virtual void Init();

	Person();
	Person(String const& name);
	virtual ~Person();

	String const& GetName() const;
	void SetName(String const& name);

	Person& operator=(Person const& rhs);

	virtual void Print() const;
};