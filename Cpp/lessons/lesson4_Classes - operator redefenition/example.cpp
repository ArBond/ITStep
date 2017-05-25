#include "example.h"
#include <iostream>

Logger* Logger::g_instance = 0;

Logger::Logger()
{
	std::cout << "Logger created\n";
}

Logger* Logger::GetInstance()
{
	if (!g_instance)
	{
		g_instance = new Logger();
	}
	return g_instance;
}

void Logger::Log(char const* msg)
{
	std::cout << msg << "\n";
}