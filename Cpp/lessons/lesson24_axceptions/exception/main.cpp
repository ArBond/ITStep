#include "stack.h"

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

typedef void(*TerminateFunc)();

void CustomTerminate()
{
	std::cout << "Custom terminate\n";
	exit(1);
}

double CalcSqrt(double value) noexcept
{
	throw "CalcSqrt exception";
	return sqrt(value);
}

void main()
{
	TerminateFunc prev = set_terminate(CustomTerminate);
	//set_terminate(prev);

	Stack stack;
	try
	{
		std::vector<int> v;
		v.push_back(1);
		std::cout << v.at(1) << "\n";
		//CalcSqrt(-1);
		stack.Push(1);
		/*stack.Push(1);
		stack.Push(1);
		stack.Push(1);
		stack.Push(1);
		stack.Push(1);*/
		int a = stack.Pop();
		a = stack.Pop();
	}
	catch(char* message)
	{
		std::cout << message << "\n";
	}
	catch (size_t count)
	{
		std::cout << count << "\n";
	}
	catch (std::exception& ex)
	{
		std::cout << "std::exception: " << ex.what() << "\n";
	}
	catch (StackIsFullException& ex)
	{
		std::cout << "Stack is full\ncount = " << ex.GetCount() << "\n";
	}
	catch (StackException& ex)
	{
		std::cout << "Stack throwed exception\ncount = " << ex.GetCount() << "\n";
	}
	catch (...)
	{
		std::cout << "Someting gone wrong\n";
	}
	std::cout << "continue work\n";
}
