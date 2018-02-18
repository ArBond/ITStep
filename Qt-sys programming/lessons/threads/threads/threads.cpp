#include <thread>
#include <iostream>

void f()
{
	for (size_t i = 0; i < 100; i++)
		std::cout << "*";
}

void main()
{
	std::thread t(f);
	std::cout << "%";
	t.detach();
}

