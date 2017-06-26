#pragma once

#include "IObserver.h"

#include <iostream>

class GeneralWidget : public IObserver
{
public:
	void Update(double temp, double hum)
	{
		Dispay(temp, hum);
	}
	void Dispay(double temp, double hum)
	{
		std::cout << "Temp: " << temp << "(C)\nHum: " << hum << "(%)\n\n\n";
	}

};