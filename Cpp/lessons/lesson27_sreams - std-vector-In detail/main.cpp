#include <sstream>
#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>

class CalcExeption : public std::exception
{
public:
	char const* what() const override
	{
		return "Invalid argument";
	}
};

double CalcSqrt(double value)
{
	if (value < 0)
	{
		throw CalcExeption();
	}
	return sqrt(value);
}

void Sort(int* arr, int count)
{

}

void Print(std::vector<int> v)
{
	std::copy(v.begin(), v.end(),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}

void main()
{
	/*std::string str = "type:student name:Ivanov rating:8";
	std::istringstream is(str);
	std::string buf;
	while (!is.eof())
	{
	is >> buf;
	std::istringstream is2(buf);
	char part[1024];
	is2.getline(part, 1024, ':');
	std::cout << "key=" << part;
	is2.getline(part, 1024, ':');
	std::cout << ", value=" << part << std::endl;
	}

	double val = -6;
	try
	{
	double res = CalcSqrt(val);
	std::cout << res << std::endl;
	}
	catch (std::exception& ex)
	{
	std::ostringstream os;
	os << "Error in function CalcSqrt()" <<
	", argument: " << val << ", :" <<
	ex.what();
	std::cout << os.str() << std::endl;
	}

	std::ostringstream os1;
	os1 << 5 << " + " << 6 << " = " << (5 + 6);
	std::cout << os1.str() << std::endl;

	std::istringstream is1("123");
	int a;
	is1 >> a;
	std::cout << a + 1 << std::endl; */

	std::vector<int> v;
	for (int i = 1; i < 10; ++i)
	{
		v.push_back(i);
	}

	//std::copy(v.begin(), v.end(),
	//  std::ostream_iterator<int>(std::cout, " "));

	std::vector<int> v1 = { 1, 19, 20 };
	std::vector<int> v2(std::move(v1));
	Print(v2);

	std::vector<int> v3(v.begin(), v.begin() + 5);
	Print(v3);

	std::cout << v3.front() << " " << v3.back() << std::endl;

	std::cout << v3.size() << " " << v3.capacity() << std::endl;
	v3.push_back(0);
	std::cout << v3.size() << " " << v3.capacity() << std::endl;

	v3.reserve(20);
	v3.resize(15);
	std::copy(v3.begin(), v3.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	std::cout << v3.size() << " " << v3.capacity() << std::endl;
	std::cout << std::endl;

	std::vector<int>::reverse_iterator it = v3.rbegin();
	for (; it != v3.rend(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	Print(v3);

	int* array = &v3[0];
	int* array1 = &v3.front();
	int* array2 = v3.data();
	Sort(v3.data(), v3.size());

	v3.insert(v3.begin() + 1, 100);
	Print(v3);

	std::vector<int>::iterator it1 = v3.insert(v3.begin() + 5, 5, 500);
	Print(v3);

	std::cout << std::distance(v3.begin(), it1)
		<< std::endl;

	it1 = v3.erase(it1);
	Print(v3);

	v3.erase(it1, it1 + 5);
	Print(v3);

	for (std::vector<int>::iterator i = v3.begin(); i != v3.end();)
	{
		if (*i % 2 == 0)
		{
			i = v3.erase(i);
		}
		else
		{
			i++;
		}
	}
	Print(v3);

	v3.insert(v3.begin(), 0);
	v3.insert(v3.begin() + 2, 0);
	v3.resize(10);
	v3.insert(v3.end(), 5, 100);
	Print(v3);

	auto it4 = std::remove(v3.begin(), v3.end(), 0);
	Print(v3);

	std::cout << std::distance(v3.begin(), it4) << std::endl;

	v3.erase(it4, v3.end());
	Print(v3);

	std::vector<int> v4;
	v4.reserve(100);
	v4.insert(v4.begin(), { 1, 3, 4, 5 });
	std::cout << v4.size() << " " << v4.capacity() << std::endl;
	v4.shrink_to_fit();
	std::cout << v4.size() << " " << v4.capacity() << std::endl;


	std::vector<int> v5 = { 1, 2, 7, 34, 7, 3, 40 };
	std::copy(v5.begin(), v5.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	
	int num = 2;
	std::function<bool(int&)> lambda = [&num](int& el)
	{
		return (el % num) == 0;
	};

	auto it5 = std::remove_if(v5.begin(), v5.end(), lambda);
	v5.erase(it5, v5.end());
	std::copy(v5.begin(), v5.end(), std::ostream_iterator<int>(std::cout, " "));
}
