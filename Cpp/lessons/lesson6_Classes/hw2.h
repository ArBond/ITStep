#pragma once

class Set
{

private:
	int* m_elements;
	size_t m_capacity;
	size_t m_count;

	void ExpandMemory();

public:
	Set();
	Set(int number);
	Set(Set const& set);

	bool Contains(int element) const;
	size_t GetCount() const;
	void AddElement(int element);
	void DeleteElement(int element);
};