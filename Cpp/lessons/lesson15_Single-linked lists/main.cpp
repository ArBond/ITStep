#include "list.h"

#include <iostream>

void main()
{
	List list = { -1, -4 };
	list.insert(4, list.end());
	list.insert(5, list.end());
	list.insert(2, list.begin());
	list.insert(10, list.begin(-9));
	list.insert(10, list.begin(100));

	for (Iterator it = list.begin();
		it != list.end(); ++it)
	{
		std::cout << *it << " ";
	}

}
