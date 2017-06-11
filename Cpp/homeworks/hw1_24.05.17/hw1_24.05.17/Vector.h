#pragma once
class Vector
{
private:
	float m_x;
	float m_y;
	float m_z;

public:
	Vector();
	Vector(float x, float y, float z);

	float GetX() const;
	float GetY() const;
	float GetZ() const;
	void SetValues(float x, float y, float z);
	void Read();
	void Print() const;
	void Add(Vector const& rhs);
	float CalculateLength() const;
	float ScalarMult(Vector const& rhs) const;
	float CalculateCos(Vector const& rhs) const;
	Vector VectorMult(Vector const& rhs) const;

};