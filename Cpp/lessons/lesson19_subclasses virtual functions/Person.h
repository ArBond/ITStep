#pragma once

#include "String.h"

class Person
{
protected:
	String m_name;
public:
	Person();
	Person(String const& name);
	~Person();

	String const& GetName() const;
	void SetName(String const& name);
	virtual void Print() const;
};