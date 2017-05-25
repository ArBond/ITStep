#pragma once

class Distance
{
public:
	Distance();
	Distance(int feet, float inches);
	Distance(int feet);

	int GetFeet() const;
	float GetInches() const;
	void SetData(int feet, float inches);
	void Read();
	void Print();

	Distance operator+(Distance const& rhs);
	void operator+=(Distance const& rhs);
	Distance operator-(Distance const& rhs);
	void operator-=(Distance const& rhs);
	Distance& operator++();
	Distance operator++(int);

private:
	int m_feet = 0;
	float m_inches = 0;
};

float operator/(Distance const& lhs, Distance const& rhs);