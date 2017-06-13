#include "dinArray.h"

#include <iostream>

void main()
{
	DynArray<int> d = { 200, 300, 100 };
	DynArray<int> d1 = (std::move(d));
	int arr[] = { 5, 6, 7, 8 };
	/*for (int el : arr)
	{
		std::cout << el << " ";
	}*/
	d = d1 * 10;
	std::cout << d << "\n";

	DynArray<int> const d2(d1);
	std::cout << d2[0] << "\n";
	d1[0] = -5;
	std::cout << d1[0] << "\n";

}
