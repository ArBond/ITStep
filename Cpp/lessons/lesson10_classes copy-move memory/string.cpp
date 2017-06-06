#include "String.h"

#include <cstring>
#include <iostream>

String::String()
{
	m_str = new char[1];
	m_str[0] = '\0';
	std::cout << "String default constructor\n";
}

String::String(char const* str)
{
	size_t length = strlen(str);
	m_str = new char[length + 1];
	strcpy(m_str, str);
	std::cout << "String constructor with char*\n";
	// memcpy(m_str, str, length + 1);
}

String::String(String const& string)
{
	size_t length = string.GetLength();
	m_str = new char[length + 1];
	strcpy(m_str, string.m_str);
	std::cout << "String copy constructor\n";
	// memcpy(m_str, string.m_str, length + 1);
}

String::String(String&& string)
{
	m_str = string.m_str;
	string.m_str = nullptr;
	std::cout << "String move constructor\n";
}

String::~String()
{
	delete[] m_str;
	std::cout << "String destructor\n";
}

size_t String::GetLength() const
{
	return strlen(m_str);
}

char const* String::GetCString() const
{
	return m_str;
}

String String::operator+(String const& rhs)
{
	size_t length1 = GetLength();
	size_t length2 = rhs.GetLength();
	String newStr;
	delete[] newStr.m_str;
	newStr.m_str = new char[length1 + length2 + 1];
	/*strcat(newCStr, m_str);
	strcat(newCStr, rhs.m_str);
	newStr.m_str = newCStr; */
	memcpy(newStr.m_str, m_str, length1);
	memcpy(newStr.m_str + length1, rhs.m_str, length2 + 1);

	return newStr;
}

bool String::operator==(String const& rhs) const
{
	return strcmp(m_str, rhs.m_str) == 0;
}

bool String::operator!=(String const& rhs) const
{
	// return !(*this == rhs);
	return strcmp(m_str, rhs.m_str) != 0;
}

bool String::operator<(String const& rhs) const
{
	return strcmp(m_str, rhs.m_str) < 0;
}

bool String::operator>(String const& rhs) const
{
	return strcmp(m_str, rhs.m_str) > 0;
}

std::ostream& operator<<(std::ostream& stream, String const& string)
{
	stream << string.GetCString();
	return stream;
}
std::istream& operator >> (std::istream& stream, String& string)
{
	char buffer[1024];
	stream.getline(buffer, 1024);
	size_t length = strlen(buffer);
	delete[] string.m_str;
	string.m_str = new char[length + 1];
	strcpy(string.m_str, buffer);

	return stream;
}

String& String::operator=(String const& rhs)
{
	std::cout << "String copy operator=\n";
	if (&rhs != this)
	{
		delete[] m_str;
		size_t length = rhs.GetLength();
		m_str = new char[length + 1];
		strcpy(m_str, rhs.m_str);
	}
	return *this;
}

String& String::operator=(String&& rhs)
{
	std::cout << "String move operator=\n";
	if (&rhs != this)
	{
		delete[] m_str;
		m_str = rhs.m_str;
		rhs.m_str = nullptr;
	}
	return *this;
}

char String::operator[](int idx) const
{
	String* nonConstThis = const_cast<String*>(this);
	return (*nonConstThis)[idx];
}

char& String::operator[](int idx)
{
	if (idx < 0 || idx >= GetLength())
	{
		std::cout << "Invalid index\n";
		exit(-1);
	}
	return m_str[idx];
}

String::operator char*()
{
	return m_str;
}