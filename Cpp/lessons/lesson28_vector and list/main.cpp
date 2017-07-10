#include "student.h"

#include <sstream>
#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <list>

void Print(std::vector<int> v)
{
	std::copy(v.begin(), v.end(),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}

void Print(std::list<int> l)
{
	std::copy(l.begin(), l.end(),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}

void main()
{	
	/*std::vector<int> v = { 16, 4, 8, 13, 4, 8, 1, 0, 15, 12, 7 };
	Print(v);

	int min = 10;
	int max = 15;
	std::function<bool(int&)> lambda = [&min, &max](int& el)
	{
		return el >= min && el <= max;
	};

	auto it = std::remove_if(v.begin(), v.end(), lambda);
	v.erase(it, v.end());
	Print(v);

	it = std::remove(v.begin(), v.end(), 4);
	v.erase(it, v.end());
	Print(v);

	min = 2;
	max = 8;

	std::copy_if(v.begin(), v.end(),
		std::ostream_iterator<int>(std::cout, " "), lambda);
	std::cout << std::endl;



	std::vector<Student> students = {Student("Ivanov", 5), Student("Azarenko", 3),
				Student("Kozlov", 6), Student("Belkin", 8), Student("Popov", 2) };

	std::sort(students.begin(), students.end());
	for (auto it = students.begin(); it != students.end(); it++)
	{
		it->Print();
	}
	std::cout << std::endl;

	std::function<bool(Student const&, Student const&)> compareByRating = [](Student const& st1, Student const& st2)
	{
		return st1.GetRating() < st2.GetRating();
	};

	std::sort(students.begin(), students.end(), compareByRating);
	for (auto it = students.begin(); it != students.end(); it++)
	{
		it->Print();
	}
	std::cout << std::endl;

	std::sort(students.begin(), students.end(), std::greater<Student>());
	for (auto it = students.begin(); it != students.end(); it++)
	{
		it->Print();
	}*/




	//		LIST

	std::list<int> list = { 2, 8, 24, 17, 9, 8, 0, 23, 1, 17 };

	std::list<int>::iterator startIt = list.begin();
	std::advance(startIt, 4);

	std::list<int>::iterator it1 = std::find(startIt, list.end(), 8);

	if (it1 != list.end())
	{
		std::cout << std::distance(list.begin(), it1) << std::endl;
		std::cout << *it1 << std::endl;
	}
	else
	{
		std::cout << "Not found\n";
	}
	list.push_front(0);
	list.push_back(0);
	Print(list);

	auto listLambda = [](int const& el)
	{
		return el >= 10;
	};

	list.remove_if(listLambda);
	Print(list);

	list.sort(); // алгоритм сортировки нельзя использовать для листа, у него есть метод
	Print(list);

	auto reversSortLambda = [](int& el1, int& el2)
	{
		return el1 > el2;
	};
	list.sort(reversSortLambda);
	Print(list);

	list.unique();
	Print(list);

	/*auto remainerEquals = [](int& el1, int& el2)
	{
		return el1 % 3 == el2 % 3;
	};
	list.unique(remainerEquals);
	Print(list);*/

	std::istringstream is("10 23 5 7 8 4");
	std::vector<int> v3;
	//v3.resize(10);
	std::copy(std::istream_iterator<int>(is),	//sourse begin
		std::istream_iterator<int>(),		//sourse end
		std::back_inserter(v3));		//dest begin

	Print(v3);
}


//Вандервуд Джoсатис
