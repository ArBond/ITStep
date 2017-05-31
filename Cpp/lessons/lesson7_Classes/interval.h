#pragma once

#include <iosfwd>

class Interval
{
private:
	float m_begin;
	float m_end;

public:
	Interval();
	Interval(float begin, float end);
	Interval(Interval const& interval);

	float GetLength();
	Interval GetInterval();
	void Move(float distance);
	void Expand(float scale);
	float Middle();
	bool IsEmpty();

	Interval operator&(Interval const& rhs) const;
	Interval operator|(Interval const& rhs) const;
	void operator+=(float distance);
	void operator*=(float scale);

	friend std::ostream& operator << (std::ostream& stream, Interval const& interval);
	friend std::istream& operator >> (std::istream& stream, Interval& interval);
};