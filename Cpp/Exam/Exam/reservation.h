#pragma once

#include <string>
#include "date.h"

class Reservation
{
private:
	std::string login;
	Date occupancy;
	Date eviction;

public:
	Reservation(std::string login, Date occupancy, Date eviction);

	std::string GetLogin() const;
	Date GetOccupancyDate() const;
	Date GetEvictionDate() const;

	void Print() const;
};




Reservation::Reservation(std::string login, Date occupancy, Date eviction) :
	login(login), occupancy(occupancy), eviction(eviction)
{
}

std::string Reservation::GetLogin() const
{
	return login;
}

Date Reservation::GetOccupancyDate() const
{
	return occupancy;
}

Date Reservation::GetEvictionDate() const
{
	return eviction;
}

void Reservation::Print() const
{
	std::cout << "User " << login << ": occupancy date - " << occupancy << " eviction date - " << eviction << std::endl;
}