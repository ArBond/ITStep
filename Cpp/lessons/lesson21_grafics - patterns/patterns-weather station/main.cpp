#include "WeatherStation.h"
#include "StatisticsWidget.h"
#include "GeneralWidget.h"

void main()
{
	WeatherStation station;

	StatisticsWidget statistic;
	GeneralWidget general;

	station.AddObserver(&statistic);
	station.AddObserver(&general);

	station.Set(20, 55);
	station.Set(18, 70);
	station.RemoveObserver(&statistic);
	station.Set(10, 90);
	station.Set(12, 85);
}
