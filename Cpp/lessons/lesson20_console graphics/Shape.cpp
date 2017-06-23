#include "Shape.h"


Shape::Shape()
{
}


Shape::~Shape()
{
}




Circle::Circle(int centreX, int centreY, int radius) :
	m_centreX(centreX),
	m_centreY(centreY),
	m_radius(radius)
{
}

void Circle::Draw(Graphics* graphics)
{
	graphics->DrawEllipse(m_centreX - m_radius,
		m_centreY - m_radius, m_radius * 2, m_radius * 2);
}

void Circle::Move(int x, int y)
{
	m_centreX += x;
	m_centreY += y;
}





Smile::Smile(int centreX, int centreY, int radius) :
	Circle(centreX, centreY, radius),
	m_leftEye(m_centreX - m_radius / 2, m_centreY - m_radius / 2, m_radius / 5),
	m_rightEye(m_centreX + m_radius / 2, m_centreY - m_radius / 2, m_radius / 5)
{
}

void Smile::Draw(Graphics* graphics)
{
	Circle::Draw(graphics);
	m_leftEye.Draw(graphics);
	m_rightEye.Draw(graphics);

	graphics->DrawLine(m_centreX - m_radius / 2,
		m_centreY + m_radius / 2, m_centreX + m_radius / 2,
		m_centreY + m_radius / 2);

	graphics->SetPixel(m_centreX, m_centreY);
}

void Smile::Move(int x, int y)
{
	Circle::Move(x, y);
	m_leftEye.Move(x, y);
	m_rightEye.Move(x, y);
}







Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3):
	m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2), m_x3(x3), m_y3(y3)
{
}

void Triangle::Draw(Graphics* graphics)
{
	graphics->DrawLine(m_x1, m_y1, m_x2, m_y2);
	graphics->DrawLine(m_x2, m_y2, m_x3, m_y3);
	graphics->DrawLine(m_x3, m_y3, m_x1, m_y1);
}
void Triangle::Move(int x, int y)
{
	m_x1 += x;
	m_y1 += y;
	m_x2 += x;
	m_y2 += y;
	m_x3 += x;
	m_y3 += y;
}