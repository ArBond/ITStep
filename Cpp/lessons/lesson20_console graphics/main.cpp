#include "Graphics.h"
#include "Shape.h"

#include <list>

void DrawShapes(std::list<Shape*> const& shapes, Graphics* g)
{
	for (Shape* shape : shapes)
	{
		shape->Draw(g);
	}
}

void main()
{
	Graphics g(80, 50);

	Circle c1(60, 10, 10);
	Smile s1(40, 40, 10);
	Triangle t1(10, 10, 30, 10, 20, 20);
	Triangle t2(10, 17, 30, 17, 20, 7);

	std::list<Shape*> list;
	list.push_back(&t1);
	list.push_back(&t2);
	list.push_back(&c1);
	list.push_back(&s1);

	DrawShapes(list, &g);
}
