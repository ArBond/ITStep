#include "DynArray.h"

#include <list>

#include <iostream>

void main()
{
	DynArray<int> d = { 2, 3, 1, 6, 4, 9 };
	DynArrayIterator<int> it = d.begin();
	for (it = d.begin(); it != d.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";

	it = d.end();
	d.insert(it - 4, -100);
	for (int& i : d)
	{
		std::cout << i << " ";
	}
	std::cout << "\n";

	it = d.begin();
	d.erase(++it);
	for (int& i : d)
	{
		std::cout << i << " ";
	}
	std::cout << "\n";

	it = d.end();
	d.insert(it, 0);
	for (int& i : d)
	{
		std::cout << i << " ";
	}
	std::cout << "\n";
}