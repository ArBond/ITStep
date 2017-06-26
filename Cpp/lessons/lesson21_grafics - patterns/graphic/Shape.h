#pragma once
#include "IGraphics.h"

class IShape
{
public:
	virtual ~IShape() = default;

	virtual void Draw(IGraphics* graphics) = 0;
	virtual void Move(int x, int y) = 0;
};

class Triangle : public IShape
{
private:
	int m_x1;
	int m_y1;
	int m_x2;
	int m_y2;
	int m_x3;
	int m_y3;
public:
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3);

	void Draw(IGraphics* graphics) override;
	void Move(int x, int y) override;
};

class Circle : public IShape
{
protected:
	int m_centreX = 0;
	int m_centreY = 0;
	int m_radius = 0;
public:
	Circle(int centreX, int centreY, int radius);

	void Draw(IGraphics* graphics) override;
	void Move(int x, int y) override;
};

class Smile : public Circle
{
private:
	Circle m_leftEye;
	Circle m_rightEye;
public:
	Smile(int centreX, int centreY, int radius);
	void Draw(IGraphics* graphics) override;
	void Move(int x, int y) override;
};

