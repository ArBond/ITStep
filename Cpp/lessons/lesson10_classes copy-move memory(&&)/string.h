#pragma once

#include <iosfwd>

class String
{
private:
	char* m_str = nullptr;

public:
	String();
	String(char const* str);
	String(String const& string);
	String(String&& string);
	~String();

	char const* GetCString() const;
	size_t GetLength() const;
	String operator+(String const& rhs);

	bool operator==(String const& rhs) const;
	bool operator!=(String const& rhs) const;
	bool operator<(String const& rhs) const;
	bool operator>(String const& rhs) const;

	String& operator=(String const& rhs);
	String& operator=(String&& rhs);
	char operator[](int idx) const;
	char& operator[](int idx);

	operator char*();

	friend std::istream& operator >> (std::istream& stream, String& string);
};

std::ostream& operator<<(std::ostream& stream, String const& string);
std::istream& operator >> (std::istream& stream, String& string);