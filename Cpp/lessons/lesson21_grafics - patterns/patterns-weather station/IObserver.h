#pragma once

class IObserver
{
private:

public:
	virtual ~IObserver() = default;

	virtual void Update(double temp, double hum) = 0;
};