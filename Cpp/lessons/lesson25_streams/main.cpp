#include "Person.h"
#include "Employee.h"
#include "Student.h"

#include <iostream>
#include <fstream>

void main()
{
	/*std::ofstream file("example.txt", std::ios::out | std::ios::trunc);  //truncate

	double d = 3.14;
	int a = 100500;
	char c = 'c';
	char str[] = "Hey hoy!";

	file << d << " " << a << " " << c << " " << str;*/



	/*std::ifstream ifile("example.txt", std::ios::in);

	double d;
	int a;
	char c;
	char str[256];
	ifile >> d >> a >> c;
	ifile.read(str, 256);

	std::cout << d << ' ' << a << ' ' << c << ' ' << str;*/



	//std::ofstream file("example.txt", std::ios::out | std::ios::app);  //append

	//file << "Knowledge is pover\n";
	//file << "C++ rilez\n";

	//file.close();

	//std::ifstream ifile("example.txt", std::ios::in);

	//char buff[1024];

	//while (!ifile.eof())
	//{
	//	ifile.getline(buff, 1024);
	//	std::cout << buff << "\n";
	//}


	std::ofstream ofile("Person.txt", std::ios::out | std::ios::trunc);
	PersonList list;
	list.Add(new Student("Ivanov", 8));
	list.Add(new Employee("Johan", 10000));
	list.Add(new Person("Petrov"));
	list.SaveToStream(ofile);
	//list.SaveToStream(std:;cout);

	ofile.close();

	std::ifstream ifile("Person.txt", std::ios::in);
	list.LoadFromStream(ifile);
	list.Print();
	//savePersons();

}
