#include "interval.h"
#include <iostream>


Interval::Interval() :
	m_begin(0),
	m_end(0)
{
}

Interval::Interval(float begin, float end)
{
	if (begin < end)
	{
		m_begin = begin;
		m_end = end;
	}
	else
	{
		m_begin = end;
		m_end = begin;
	}
}

Interval::Interval(Interval const& interval)
{
	m_begin = interval.m_begin;
	m_end = interval.m_end;
}


float Interval::GetLength()
{
	return m_end - m_begin;
}

Interval Interval::GetInterval()
{
	return *this;
}

void Interval::Move(float distance)
{
	m_begin += distance;
	m_end += distance;
}

void Interval::Expand(float scale)
{
	m_end = GetLength() * scale + m_begin;
}

float Interval::Middle()
{
	return (m_begin + m_end) / 2;
}

bool Interval::IsEmpty()
{
	return m_begin == m_end;
}

float max(float number1, float number2)
{
	return number1 > number2 ? number1 : number2;
}

float min(float number1, float number2)
{
	return number1 < number2 ? number1 : number2;
}

Interval Interval::operator&(Interval const& rhs) const
{
	Interval interval;
	float begin = max(m_begin, rhs.m_begin);
	float end = min(m_end, rhs.m_end);
	if (begin < end)
	{
		interval.m_begin = begin;
		interval.m_end = end;
	}
	return interval;
}

Interval Interval::operator|(Interval const& rhs) const
{
	Interval interval;
	float begin = min(m_begin, rhs.m_begin);
	float end = max(m_end, rhs.m_end);
	if (!(m_begin > rhs.m_end || m_end < rhs.m_begin))
	{
		interval.m_begin = begin;
		interval.m_end = end;
	}
	return interval;

}

void Interval::operator+=(float distance)
{
	Move(distance);
}

void Interval::operator*=(float scale)
{
	Expand(scale);
}


std::ostream& operator << (std::ostream& stream, Interval const& interval)
{
	stream << interval.m_begin << " " << interval.m_end;
	return stream;
}

std::istream& operator >> (std::istream& stream, Interval& interval)
{
	char buffer[21];
	stream.getline(buffer, 20);
	sscanf(buffer, "%f %f", &interval.m_begin, &interval.m_end);
	return stream;
}