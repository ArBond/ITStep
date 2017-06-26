#include "WeatherStation.h"


WeatherStation::WeatherStation()
{
}

WeatherStation::~WeatherStation()
{
}

void WeatherStation::Set(double temp, double hum)
{
	if (m_hum != hum || m_temp != temp)
	{
		m_temp = temp;
		m_hum = hum;
		NotifyObservers();
	}
}

double WeatherStation::GetTemp() const
{
	return m_temp;
}

double WeatherStation::GetHum() const
{
	return m_hum;
}

void WeatherStation::AddObserver(IObserver* observer)
{
	m_observers.push_back(observer);
}

void WeatherStation::RemoveObserver(IObserver* observer)
{
	for(std::vector<IObserver*>::iterator it = m_observers.begin(); it != m_observers.end(); it++)
	{
		if (*it == observer)
		{
			m_observers.erase(it);
			return;
		}
	}
}

void WeatherStation::NotifyObservers()
{
	for (size_t i = 0; i < m_observers.size(); i++)
	{
		m_observers[i]->Update(m_temp, m_hum);
	}
}