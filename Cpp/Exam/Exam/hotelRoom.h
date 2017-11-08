#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

class HotelRoom
{
private:
	int roominess;
	double price;
	bool canBeReservation;

public:
	HotelRoom(int roominess, double price, bool canBeReservation);

	int GetRoominess() const;
	void SetRoominess(int roominess, int number);
	double GetPrice() const;
	void SetPrice(double price);
	bool CanBeReservated() const;
	void SetCanBeReservation(bool canBeReservation);

	void Print() const;
};




HotelRoom::HotelRoom(int roominess, double price, bool canBeReservation = true) :
	roominess(roominess), price(price), canBeReservation(canBeReservation)
{
}

int HotelRoom::GetRoominess() const
{
	return roominess;
}

void HotelRoom::SetRoominess(int roominess, int number)
{
	this->roominess = roominess;
}

double HotelRoom::GetPrice() const
{
	return price;
}

void HotelRoom::SetPrice(double price)
{
	this->price = price;
}

bool HotelRoom::CanBeReservated() const
{
	return canBeReservation;
}

void HotelRoom::SetCanBeReservation(bool canBeReservation)
{
	this->canBeReservation = canBeReservation;
}

void HotelRoom::Print() const
{
	std::cout << "roominess - " << roominess << " person, price - " << price << "$" << std::endl;
}