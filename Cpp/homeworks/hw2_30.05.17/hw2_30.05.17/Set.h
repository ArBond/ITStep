#pragma once

#include <iosfwd>

class Set
{

private:
	int* m_elements;
	size_t m_capacity;
	size_t m_count;

	void ReAllocateMemory(size_t newCapacity);

public:
	Set();
	Set(int number);
	Set(Set const& rhs);

	~Set();

	size_t GetCount() const;
	bool Contains(int element) const;

	Set& operator=(Set const& rhs);

	void operator+=(int element);
	void operator-=(int element);

	bool operator==(Set const& rhs) const;
	bool operator!=(Set const& rhs) const;

	friend Set operator&(Set const& set1, Set const& set2);
	friend Set operator|(Set const& set1, Set const& set2);
	friend Set operator^(Set const& set1, Set const& set2);

	friend std::ostream& operator<<(std::ostream& stream, Set const& set);
	friend std::istream& operator>>(std::istream& stream, Set& set);

	operator bool() const;
	
};