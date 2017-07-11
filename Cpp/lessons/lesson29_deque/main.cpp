#include "student.h"

#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>
#include <deque>

void Print(std::vector<std::string> v)
{
	std::copy(v.begin(), v.end(),
		std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;
}

int Summ(int a, int b, int c)
{
	return a + b + c;
}

bool less(int a, int b)
{
	return a < b;
}

void main()
{
	//std::vector<std::string> words;

	//std::ifstream is("song.txt", std::ios::in);

	///*while (!is.eof())
	//{
	//	std::string buffer;
	//	is >> buffer;
	//	words.push_back(buffer);
	//}*/

	//std::function<bool(std::string const&)> lambda = [](std::string const& st)
	//{
	//	char symbol = st[0];
	//	return symbol == 'a' || symbol == 'o' || symbol == 'y' || symbol == 'i' || symbol == 'e' || symbol == 'u';
	//};

	///*std::copy(std::istream_iterator<std::string>(is), std::istream_iterator<std::string>(), std::back_inserter(words));
	//auto it = std::remove_if(words.begin(), words.end(), std::not1(lambda));
	//words.erase(it, words.end());*/

	//std::copy_if(std::istream_iterator<std::string>(is), std::istream_iterator<std::string>(), std::back_inserter(words), lambda);

	//auto it = std::unique(words.begin(), words.end());
	//words.erase(it, words.end());

	//std::function<bool(std::string const&, std::string const&)> compareBySize = [](std::string const& w1, std::string const& w2)
	//{
	//	return size(w1) < size(w2);		// or  w1.size() < w2.size()
	//};

	//std::sort(words.begin(), words.end(), compareBySize);

	//Print(words);



	//		 DEQUE

	std::deque<Student> d;
	d.push_front(Student("Ivanov", 7));
	d.push_front(Student("Anisimov", 3));
	d.push_front(Student("Petrov", 5));

	auto printStudent = [](Student const& st)
	{
		st.Print();
	};

	//std::for_each(d.begin(), d.end(), printStudent);

	std::for_each(d.begin(), d.end(), std::bind(&Student::Print, std::placeholders::_1));
	std::cout << std::endl;



	/*std::function<int(int, int, int)> summ3 = Summ;
	int a = summ3(1, 2, 3);
	std::function<int(int, int)> summ2 = std::bind(summ3, std::placeholders::_1, std::placeholders::_2, 0);
	a = summ2(1, 2);

	std::function<bool(int, int)> greater = std::bind(less, std::placeholders::_2, std::placeholders::_1);*/

	std::sort(d.begin(), d.end());
	std::for_each(d.begin(), d.end(), std::bind(&Student::Print, std::placeholders::_1));
	std::cout << std::endl;

	std::sort(d.begin(), d.end(), std::bind(std::less<Student>(), std::placeholders::_2, std::placeholders::_1));
	std::for_each(d.begin(), d.end(), std::bind(&Student::Print, std::placeholders::_1));
	std::cout << std::endl;

	/*std::vector<int> v = { 1, 11, 15, 19, 21, 3 };

	std::copy_if(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "), std::bind(std::logical_and<bool>(),
			std::bind(std::greater<int>(), std::placeholders::_1, 10), std::bind(std::less<int>(), std::placeholders::_1, 20)));*/


	std::deque<std::string> names = { "Kozlov", "Eroshenkov", "Shukherman" };
	std::vector<Student> students;

	int rating = 6;
	std::function<Student(std::string const&)> createStudent = [&rating](std::string const& name)
	{
		return Student(name, rating);
	};

	std::transform(names.begin(), names.end(), std::back_inserter(students), createStudent);

	std::for_each(students.begin(), students.end(), std::bind(&Student::Print, std::placeholders::_1));
}
