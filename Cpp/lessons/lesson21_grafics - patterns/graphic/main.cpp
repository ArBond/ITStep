#include "ConsoleGraphics.h"
#include "Shape.h"
#include "HtmlGraphics.h"

#include <list>

void DrawShapes(std::list<IShape*> const& shapes, IGraphics* g)
{
	for (IShape* shape : shapes)
	{
		shape->Draw(g);
	}
}

int main()
{
	HtmlGraphics hg("graphics.html");

	/*g.DrawEllipse(1, 1, 20, 6);
	g.DrawRectangle(5, 5, 20, 5);
	g.DrawLine(1, 1, 20, 10);*/

	Circle c1(10, 10, 5);
	Smile s1(15, 15, 10);

	s1.Draw(&hg);

	s1.Move(22, 0);

	s1.Draw(&hg);

	Triangle t1(10, 2, 2, 10, 20, 10);
	//t1.Draw(&g);
	Triangle t2(10, 10, 2, 2, 20, 2);
	t2.Move(0, 3);
	//t2.Draw(&g);

	std::list<IShape*> list;
	list.push_back(&t1);
	list.push_back(&t2);
	list.push_back(&c1);
	list.push_back(&s1);

	DrawShapes(list, &hg);

	return 0;
}

// https://pastebin.com/xsTknKmw


//		Эрик/Элизабет Фриман - паттерны
