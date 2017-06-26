#pragma once

#include "IObserver.h"

#include <vector>

class WeatherStation
{
private:
	double m_temp;
	double m_hum;
	std::vector<IObserver*> m_observers;

public:
	WeatherStation();
	~WeatherStation();

	void Set(double temp, double hum);
	double GetTemp() const;
	double GetHum() const;

	void AddObserver(IObserver* observer);
	void RemoveObserver(IObserver* observer);
	void NotifyObservers();
};