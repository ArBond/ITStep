#include <iostream>
#include "Distance.h"
#include "geometry.h"

void main()
{
	//Distance d1;
	//d1.Read();
	//Distance d2;
	//d2.Read();
	//d1.Add(d2);
	//d1.Print();

	//Distance* d3 = new Distance();
	//d3->SetData(4, 4.3);
	//d3->Print();
	//delete d3;



	//Distance* array = new Distance[5];
	//for (int i = 0; i < 5; i++)
	//{
	//	array[i].Read();
	//}
	//Distance result;
	//result.SetData(0, 0);
	//for (int i = 0; i < 5; i++)
	//{
	//	result.Add(array[i]);
	//}
	//result.Print();
	//delete[] array;



	/*Rectangle r;
	r.Init(0, 0, 100, 50);
	Point p;
	p.Init(60, 20);
	if (r.Contains(p))
	{
		std::cout << "r contains p\n";
	}
	else
	{
		std::cout << "r doesnt contains p\n";
	}*/



	/*Size size;
	size.Init(100, 50);
	Rectangle r1;
	r1.Init(p, size);
	Rectangle r2 = r.IntersectWith(r1);
	r2.Print();*/


	Distance d;
	d.Print();
}
