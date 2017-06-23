#pragma once

#include "Graphics.h"

class Shape
{
public:
	Shape();
	virtual ~Shape();

	virtual void Draw(Graphics* graphics) = 0;
	virtual void Move(int x, int y) = 0;
};

class Circle : public Shape
{
protected:
	int m_centreX = 0;
	int m_centreY = 0;
	int m_radius = 0;

public:
	Circle(int centreX, int centreY, int radius);

	void Draw(Graphics* graphics) override;
	void Move(int x, int y) override;
};

class Smile : public Circle
{
private:
	Circle m_leftEye;
	Circle m_rightEye;

public:
	Smile(int centreX, int centreY, int radius);

	void Draw(Graphics* graphics) override;
	void Move(int x, int y) override;
};

class Triangle : public Shape
{
private:
	int m_x1, m_y1, m_x2, m_y2, m_x3, m_y3;

public:
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3);

	void Draw(Graphics* graphics) override;
	void Move(int x, int y) override;
};