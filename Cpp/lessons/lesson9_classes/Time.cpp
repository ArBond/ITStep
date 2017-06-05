#include "Time.h"
#include <cstdio>
#include <iostream>
#include <iomanip>


Time::Time()
{
	hour = 0;
	minute = 0;
	second = 0;
}

Time::Time(int hour, int minute, int second)
{
	this->hour = hour;
	this->minute = minute;
	this->second = second;
	Check();
}

Time::Time(const char* timeString)
{
	if (sscanf(timeString, "%02i:%02i:%02i", &hour, &minute, &second) != 3)
	{
		hour = 0;
		minute = 0;
		second = 0;
		std::cout << "The wrong input!\n";
	}
}

Time::Time(Time const& time) : 
	hour(time.hour), minute(time.minute), second(time.second)
{
}

Time::~Time()
{
}


void Time::Set(int hour, int minute, int second)
{
	this->hour = hour;
	this->minute = minute;
	this->second = second;
}

int Time::GetHour() const
{
	return hour;
}

int Time::GetMinute() const
{
	return minute;
}

int Time::GetSecond() const
{
	return second;
}


void Time::Check()
{
	while (second >= 60)
	{
		minute++;
		second -= 60;
	}
	while (minute >= 60)
	{
		hour++;
		minute -= 60;
	}
	while (hour >= 24)
	{
		hour -= 24;
	}
}

void Time::AddSec(int value)
{
	second += value;
	Check();
}

void Time::AddMin(int value)
{
	minute += value;
	Check();
}

void Time::AddHour(int value)
{
	hour += value;
	Check();
}


void Time::Print() const
{
	std::cout << std::setw(2) << std::setfill('0') << hour << ":" << std::setw(2) << std::setfill('0') << minute << ":" << std::setw(2) << std::setfill('0') << second << "\n";
}

bool Time::IsAm() const
{
	return hour < 12;
}

int Time::TimeToSec() const
{
	return hour * 3600 + minute * 60 + second;
}


Time& Time::operator = (Time const& time)
{
	if (this != &time)
	{
		hour = time.hour;
		minute = time.minute;
		second = time.second;
	}
	return *this;
}

Time& Time::operator++()
{
	++second;
	Check();
	return *this;
}

Time Time::operator++(int)
{
	Time result = *this;
	second++;
	Check();
	return result;
}

bool Time::operator < (Time const& time) const
{
	return TimeToSec() < time.TimeToSec();
}

bool Time::operator >= (Time const& time) const
{
	return !(*this < time);
}

Time operator + (Time const& time1, Time const& time2)
{
	Time newTime(time1.GetHour() + time2.GetHour(),
		time1.GetMinute() + time2.GetMinute(),
		time1.GetSecond() + time2.GetSecond());
	return newTime;
}