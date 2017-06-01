#include <iostream>

#include "Stack.h"

void main()
{
	Stack st1;
	st1.Push(5);
	Stack st2(st1);
	std::cout << "St2 top: " << st2.Top() << "\n";
	st1 << 4;
	st1 << 3;
	std::cout << "Quantity st1: " << st1.GetQuantity() << "\n";
	std::cout << "St1 top: " << st1.Top() << "\n";
	st1.Pop();
	std::cout << "St1 top: " << st1.Top() << "\n";
	Stack st3 = st2;
	std::cout << "St3 top: " << st3.Top() << "\n";
	st2 = st1;
	std::cout << "St2 top: " << st2.Top() << "\n";
	int a;
	st2 >> a;
	std::cout << a << "\n";
}
