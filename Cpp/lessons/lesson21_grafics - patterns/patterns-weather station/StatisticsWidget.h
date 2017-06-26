#pragma once

#include "IObserver.h"

#include <iostream>

class StatisticsWidget : public IObserver
{
private:
	double m_averageTemp = 0;
	double m_averageHum = 0;
	double m_minHum = 0;
	double m_maxHum = 0;
	double m_minTemp = 0;
	double m_maxTemp = 0;

	int m_count = 0;

public:
	void Update(double temp, double hum)
	{
		m_averageTemp = (m_averageTemp * m_count + temp) / (m_count + 1);
		m_averageHum = (m_averageHum * m_count + hum) / (m_count + 1);

		if (m_count == 0)
		{
			m_maxHum = m_minHum = hum;
			m_maxTemp = m_minTemp = temp;
		}
		else
		{
			if (temp < m_minTemp)
			{
				m_minTemp = temp;
			}
			else if (temp > m_maxTemp)
			{
				m_maxTemp = temp;
			}

			if (hum < m_minHum)
			{
				m_minHum = hum;
			}
			else if (hum > m_maxHum)
			{
				m_maxHum = hum;
			}
		}
		m_count++;
		Dispay();
	}

	void Dispay()
	{
		std::cout << "Average temp: " << m_averageTemp << "(C)\nAverage Hum: " << m_averageHum << "(%)\n";
		std::cout << "Min temp: " << m_minTemp << "(C)\nMin Hum: " << m_minHum << "(%)\n";
		std::cout << "Max temp: " << m_maxTemp << "(C)\nMax Hum: " << m_maxHum << "(%)\n\n";
	}
};