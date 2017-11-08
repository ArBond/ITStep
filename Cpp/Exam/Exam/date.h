#pragma once

#include <sstream>
#include <string>
#include <iomanip>
#include <chrono>
#include <ctime>

typedef std::chrono::system_clock::time_point TimePoint;

struct Date
{
	int day = 0;
	int month = 0;
	int year = 0;

	Date() = default;
	Date(int day, int month, int year);
	Date(TimePoint const& tp);

	static Date Now();
	int GetDaysInMonth() const;
	bool IsLeapYear() const;
	std::string ToStringWithSpace() const;

	bool operator<(Date const& date) const;
	bool operator>(Date const& date) const;
	bool operator==(Date const& date) const;
};

long operator-(Date const& date1, Date const& date2);
std::ostream& operator<<(std::ostream& stream, Date const& date);




Date::Date(int day, int month, int year):
	day(day), month(month), year(year)
{
}

Date::Date(TimePoint const& tp)
{
	std::time_t t = std::chrono::system_clock::to_time_t(tp);
	tm* _tm = std::localtime(&t);
	day = _tm->tm_mday;
	month = _tm->tm_mon + 1;
	year = _tm->tm_year + 1900;
}

Date Date::Now()
{
	return Date(std::chrono::system_clock::now());
}

int Date::GetDaysInMonth() const
{
	if (month == 2)
		if (IsLeapYear())
			return 29;
		else
			return 28;
	else
		return 31 - month % 2;
}

bool Date::IsLeapYear() const
{
	return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

std::string Date::ToStringWithSpace() const
{
	std::ostringstream str;
	str << day << " " << month << " " << year;
	return str.str();
}

bool Date::operator<(Date const& date) const
{
	if (year < date.year)
		return true;
	if (year > date.year)
		return false;
	if (month < date.month)
		return true;
	if (month > date.month)
		return false;
	if (day < date.day)
		return true;
	return false;
}

bool Date::operator>(Date const& date) const
{
	return (date < *this);
}

bool Date::operator==(Date const& date) const
{
	return year == date.year && month == date.month && day == date.day;
}

int DateToDays(Date const& date)
{
	const int mDays[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
	int days = 365 * date.year + date.year / 4 - date.year / 100 + date.year / 400 + mDays[date.month - 1] + date.day;
	if (date.month > 2 && (date.year % 4 == 0 && (date.year % 100 != 0 || date.year % 400 == 0)))
		days++;
	return days;
}

long operator-(Date const& date1, Date const& date2)
{
	return DateToDays(date1) - DateToDays(date2);
}

std::ostream& operator<<(std::ostream& stream, Date const& date)
{
	stream << std::setfill('0') << std::setw(2) << date.day << "." << std::setfill('0') << std::setw(2) << date.month << "." << (int)date.year;
	return stream;
}