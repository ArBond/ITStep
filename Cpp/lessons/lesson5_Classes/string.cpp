#include "string.h"
#include <cstring>
#include <iostream>

String::String()
{
	m_str = new char[1];
	m_str[0] = '\0';
}

String::String(char const* str)
{
	size_t length = strlen(str);
	m_str = new char[length + 1];
	//strcpy(m_str, str);
	memcpy(m_str, str, length + 1);
}

String::String(String const& string)
{
	size_t length = strlen(string.m_str);
	m_str = new char[length + 1];
	memcpy(m_str, string.m_str, length + 1);
}

String::~String()
{
	delete[] m_str;
}

char const* String::GetString() const
{
	return m_str;
}

size_t String::GetLength() const
{
	return strlen(m_str);
}

String String::operator+(String const& rhs)
{
	size_t length1 = GetLength();
	size_t length2 = rhs.GetLength();
	String newStr;
	delete[] newStr.m_str;
	newStr.m_str = new char[length1 + length2 + 1];
	memcpy(newStr.m_str, m_str, length1);
	memcpy(newStr.m_str + length1, rhs.m_str, length2 + 1);
	return newStr;
}

bool String::operator==(String const& rhs) const
{
	return strcmp(rhs.m_str, m_str) == 0;
}

bool String::operator!=(String const& rhs) const
{
	return strcmp(rhs.m_str, m_str) != 0;
}

bool String::operator<(String const& rhs) const
{
	return strcmp(rhs.m_str, m_str) <= 0;
}

bool String::operator>(String const& rhs) const
{
	return strcmp(rhs.m_str, m_str) >= 0;
}

std::ostream& operator<<(std::ostream& stream, String const& string)
{
	stream << string.GetString();
	return stream;
}

std::istream& operator>>(std::istream& stream, String& string)
{
	char buffer[1024];
	stream.getline(buffer, 1024);
	size_t length = strlen(buffer);
	delete[] string.m_str;
	string.m_str = new char[length + 1];
	strcpy(string.m_str, buffer);

	return stream;
}