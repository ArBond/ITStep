#include <iostream>
#include <ctime>
#include <chrono>

int const SecondsPerHour = 60 * 60;
int const SecondsPerDay = 24 * SecondsPerHour;

using namespace std::chrono;

void main()
{
	std::time_t current = std::time(nullptr);
	std::cout << "time since epoch: " << current << std::endl;
	tm* _tm = gmtime(&current);
	std::cout << "Absolute time: " << asctime(_tm);
	_tm = localtime(&current);
	std::cout << "Local time: " << asctime(_tm)
		<< _tm->tm_hour << ":" << _tm->tm_min << ":" << _tm->tm_sec << std::endl;

	/*std::time_t currentPlusWeek = current + 7 * SecondsPerDay;
	std::cout << "local time: " << ctime(&currentPlusWeek);*/

	system_clock::time_point tp = system_clock::now();
	time_t t = system_clock::to_time_t(tp);
	std::cout << "Local time: " << ctime(&t);

	system_clock::time_point tp1;
	t = system_clock::to_time_t(tp1);
	std::cout << "Epoch time: " << ctime(&t);

	duration<long, std::ratio<1, 2>> halfSeconds(10);
	tp1 += halfSeconds;
	t = system_clock::to_time_t(tp1);
	std::cout << ctime(&t) << std::endl;

	duration<long, std::ratio<60* 60>> h(3);
	tp1 += h;
	t = system_clock::to_time_t(tp1);
	std::cout << ctime(&t) << std::endl;

	//typedef duration<long, std::ratio<60>> minutes;
	tp1 += minutes(20);
	t = system_clock::to_time_t(tp1);
	std::cout << ctime(&t) << std::endl;

	std::cout << (seconds(59) < minutes(1)) << std::endl;

	system_clock::time_point tpEnd = system_clock::now() + hours(24 + 7);
	t = system_clock::to_time_t(tpEnd);
	std::cout << "1 day from now: " << ctime(&t) << std::endl;

	typedef duration<long, std::ratio<60 * 60 * 24>> days;

	tpEnd += days(7);
	t = system_clock::to_time_t(tpEnd);
	std::cout << "2 Week from now: " << ctime(&t) << std::endl;

	seconds sec(5000);
	int _h = sec / hours(1);
	sec -= hours(1);
	minutes min = duration_cast<minutes>(sec);
	int _m = min.count();
	sec -= _m * minutes(1);

	std::cout << "5000 sec: " << _h << "h " << _m << "min " << sec.count() << "sec" << std::endl;

}
