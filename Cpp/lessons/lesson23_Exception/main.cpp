#include "stack.h"

#include <iostream>
#include <string>

struct  a
{
	int a;
};

struct  b: a
{
	b = a
};

void main()
{
	Stack stack;
	try
	{
		stack.Push(1);
		stack.Push(1);
		stack.Push(1);
		stack.Push(1);
		stack.Push(1);
		stack.Push(1);
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
