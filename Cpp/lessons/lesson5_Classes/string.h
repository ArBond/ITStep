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
	~String();

	char const* GetString() const;
	size_t GetLength() const;
	String operator+(String const& rhs);

	friend std::istream& operator >> (std::istream& stream, String& string);

	bool operator==(String const& rhs) const;
	bool operator!=(String const& rhs) const;
	bool operator<(String const& rhs) const;
	bool operator>(String const& rhs) const;

	String& operator=(String& rhs);
	char operator[](int idx) const;
	char& operator[](int idx);
};

std::ostream& operator<<(std::ostream& stream, String const& string);
