#pragma once

class Logger
{
private:
	static Logger* g_instance;
	Logger();

public:
	void Log(char const* msg);
	Logger(Logger const&) = delete;
	Logger& operator=(Logger&) = delete;

	static Logger* GetInstance();
};