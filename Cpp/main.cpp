#include <iostream>

//int main()
//{
//	std::cout << "What is your name?\n";
//	char name1[20];
//	char name2[20];
//	std::cin >> name1 >> name2;
//	std::cout << "hello, " << name1 << " and " << name2 << "!\n";
//	return 0;
//}






//struct Point
//{
//	int x;
//	int y;
//};
//
//void main()
//{
//	int a = 100;
//	double b = 20.5;
//
//	int& refa = a;
//	double& refb = b;
//
//	Point p = { 3, 5 };
//	Point& refp = p;
//
//	std::cout << a << "\t" << refa << "\n";
//	refa = 200;
//	std::cout << a << "\t" << refa << "\n";
//}




//void main()
//{
//
//	int* count = new int[10];
//	for (int i = 0; i < 10; i++)
//	{
//		count[i] = i;
//		
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		std::cout << count[i] << "\t";
//
//	}
//	delete[]count;
//
//
//	char* name = new char[10];
//	delete[]name;
//}

#include "distance.h"

void main()
{
	Distance d1 = Read();
	Distance d2 = Read();
	Distance d3 = Summ(d1, d2);
	Print(d3);

	d1 = Read();
	d2 = Read();
	d3 = Diff(d1, d2);
	Print(d3);
}