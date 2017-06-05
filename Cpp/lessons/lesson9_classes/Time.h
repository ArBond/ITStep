#pragma once

class Time
{
private:
	int hour;
	int minute;
	int second;
	void Check();

public:
	Time();
	Time(int hour, int minute, int second);
	Time(const char* timeString);
	Time(Time const& time);
	~Time();

	void Set(int hour, int minute, int second);
	int GetHour() const;
	int GetMinute() const;
	int GetSecond() const;

	void AddSec(int value);
	void AddMin(int value);
	void AddHour(int value);

	void Print() const;

	bool IsAm() const;

	int TimeToSec() const;

	Time& operator=(Time const& time);

	Time& operator+(Time const& time);

	Time& operator++();
	Time operator++(int);

	bool operator < (Time const& time) const;
	bool operator >= (Time const& time) const;

};

Time operator + (Time const& time1, Time const& time2);