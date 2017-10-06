#include <iostream>
#include <vector>
#include <list>
#include "Functors.h"

void main()
{
	std::vector<int> vector = { 1, 5, 2, 34, 2, -5, 0, -13 };
	SortFunctor<std::vector<int>> f1(vector.begin(), vector.end());
	//f1();

	ReduceByFunctor<std::vector<int>> f2(vector.begin(), vector.end());
	//f2(5);

	DeleterFunctor<std::vector<int>> f3(vector.begin(), vector.end());
	/*f3(2);
	for each (auto it in vector)
		std::cout << it << std::endl;*/

	std::list<int> list = { 1, 5, 2, 34, 2, -5, 0, -13 };
	SortFunctor<std::list<int>> f4(list.begin(), list.end());
	f4();
	for each (auto it in list)
		std::cout << it << std::endl;
}
