#pragma once

#include "hotelRoom.h"
#include "reservation.h"
#include "account.h"
#include "hotelException.h"

#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <fstream>
#include <memory>

char accountsFilePath[] = "Accounts\\";
char reservationsFilePath[] = "Reservations\\";
char roomsFilePath[] = "Rooms\\";

class Hotel
{
private:
	std::shared_ptr<Account> currentAccount;
	std::map<int, std::shared_ptr<HotelRoom>> hotelRooms;
	std::map<int, std::vector<std::shared_ptr<Reservation>>> reservations;

	void LoadHotelRoomsData();
	void LoadRoomsReservationData();
	void WriteToFileHotelRoomsData();
	void WriteToFilesRoomsReservationData();

public:

	Hotel();

	std::shared_ptr<Account> GetCurrentAccount() const;
	void SaveData();
	void CheckIn();
	void SignIn();
	void SignOut();
	void AddRoom();
	void DeleteRoom();
	void SetRoomReservationPossibility();
	void ShowReservations() const;
	std::map<int, std::shared_ptr<HotelRoom>> FindAvailableRooms(Date occupancy, Date eviction, int persons);
	void ShowAvailableRooms();
	Date AskDate();
	void ReserveRoom();
	std::vector<std::pair<int, std::shared_ptr<Reservation>>> FindUserReservedRooms(std::string login);
	void ShowUserReservedRooms();
	void PrintUserReservations(std::vector<std::pair<int, std::shared_ptr<Reservation>>> userReservation);
	bool CanToCancelRoomReservation(std::shared_ptr<Reservation> const& reservation);
	void DeleteReservation(std::pair<int, std::shared_ptr<Reservation>> deleterReservation);
	void CancelRoomReservation();
	void ShowUserInformation();
	void ShowHotelRoomInformation();
};





void Hotel::LoadHotelRoomsData()
{
	std::ostringstream filePath;
	filePath << roomsFilePath << "hotelRooms.bin";
	std::ifstream ifile(filePath.str(), std::ios::binary);

	int number;
	int roominess;
	double price;
	bool reservationByAnybody;
	while (true)
	{
		ifile >> number >> roominess >> price >> reservationByAnybody;
		if (ifile.eof())
			break;
		hotelRooms.insert(std::pair<int, std::shared_ptr<HotelRoom>>(number, std::make_shared<HotelRoom>(roominess, price, reservationByAnybody)));
	}
	ifile.close();
}

void Hotel::LoadRoomsReservationData()
{
	Date occupancy;
	Date eviction;
	std::string login;

	for (auto room : hotelRooms)
	{
		std::ostringstream fileName;
		fileName << reservationsFilePath << room.first << ".bin";
		std::ifstream ifile(fileName.str(), std::ios::binary);
		if (ifile.is_open())
		{
			ifile.seekg(0, std::ios::end);
			if ((int)ifile.tellg() == 0)
			{
				ifile.close();
				remove(fileName.str().c_str());
				continue;
			}
			ifile.seekg(0, std::ios::beg);
			std::vector<std::shared_ptr<Reservation>> roomReservations;
			while (true)
			{
				ifile >> login;
				ifile >> occupancy.day >> occupancy.month >> occupancy.year;
				ifile >> eviction.day >> eviction.month >> eviction.year;
				if (ifile.eof())
					break;
				if (eviction < Date::Now())
					continue;
				roomReservations.push_back(std::make_shared<Reservation>(login, occupancy, eviction));
			}
			ifile.close();
			if (!roomReservations.empty())
				reservations.insert(std::pair<int, std::vector<std::shared_ptr<Reservation>>>(room.first, roomReservations));
		}
	}
}

void Hotel::WriteToFileHotelRoomsData()
{
	std::ostringstream filePath;
	filePath << roomsFilePath << "hotelRooms.bin";
	std::ofstream ofile(filePath.str(), std::ios::binary | std::ios::trunc);

	for (auto room : hotelRooms)
		ofile << room.first << " " << room.second->GetRoominess() << " " << room.second->GetPrice() << " " << room.second->CanBeReservated() << std::endl;
	ofile.close();
}

void Hotel::WriteToFilesRoomsReservationData()
{
	for (auto roomReservatoins : reservations)
	{
		std::ostringstream filePath;
		filePath << reservationsFilePath << roomReservatoins.first << ".bin";
		std::ofstream ofile(filePath.str(), std::ios::binary | std::ios::trunc);

		for (auto reservation : roomReservatoins.second)
			ofile << reservation->GetLogin() << " " << reservation->GetOccupancyDate().ToStringWithSpace() << " " << reservation->GetEvictionDate().ToStringWithSpace() << std::endl;
	}
}

Hotel::Hotel()
{
	LoadHotelRoomsData();
	LoadRoomsReservationData();
}

std::shared_ptr<Account> Hotel::GetCurrentAccount() const
{
	return currentAccount;
}

void Hotel::SaveData()
{
	WriteToFileHotelRoomsData();
	WriteToFilesRoomsReservationData();
}

void Hotel::CheckIn()
{
	std::string fullName;
	std::cout << "Enter fullName: ";
	std::cin >> fullName;

	std::string mail;
	std::cout << "Enter mail: ";
	std::cin >> mail;

	std::string login;
	std::cout << "Enter login: ";
	std::cin >> login;

	std::ostringstream filePath;
	filePath << accountsFilePath << login << ".bin";
	std::ifstream ifile(filePath.str(), std::ios::binary);
	while (ifile.is_open())
	{
		system("cls");
		std::cout << "Account whith this login already exist. Please enter enother: ";
		ifile.close();
		std::cin >> login;
		filePath.str("");
		filePath << accountsFilePath << login << ".bin";
		ifile = std::ifstream(filePath.str(), std::ios::binary);
	}

	std::string password;
	std::string password—onfirmation;
	int count = 0;
	while (true)
	{
		if (count++ == 3)
			throw HotelException("exceeded the attempts limit!");
		std::cout << "Enter password: ";
		std::cin >> password;
		std::cout << "Confirm password: ";
		std::cin >> password—onfirmation;
		if (password == password—onfirmation)
		{
			std::cout << "Completed!" << std::endl;
			system("pause");
			system("cls");
			break;
		}

		system("cls");
		std::cout << "Passwords do not match! Try again:";
	}

	std::ofstream ofile(filePath.str(), std::ios::binary);
	ofile << false << " " << password << " " << mail << " " << fullName << std::endl;
	ofile.close();
}

void Hotel::SignIn()
{
	std::string login;
	std::cout << "Enter login: ";
	std::cin >> login;
	int count = 0;

	std::ostringstream filePath;
	filePath << accountsFilePath << login << ".bin";
	std::ifstream ifile(filePath.str(), std::ios::binary);
	while (!ifile.is_open())
	{
		if (count++ == 3)
			throw HotelException("exceeded the attempts limit!");
		system("cls");
		std::cout << "Account whith this login does not exisÂ. Please try again: ";
		ifile.close();
		std::cin >> login;
		filePath.str("");
		filePath << accountsFilePath << login << ".bin";
		ifile = std::ifstream(filePath.str(), std::ios::binary);
	}

	bool isAdmin;
	std::string truePassword;
	std::string mail;
	std::string fullName;
	ifile >> isAdmin >> truePassword >> mail >> fullName;
	ifile.close();

	std::string password;
	count = 0;
	while (true)
	{
		if (count++ == 3)
			throw HotelException("exceeded the attempts limit!");

		std::cout << "Enter password: ";
		std::cin >> password;
		if (password == truePassword)
		{
			std::cout << "We glad to see you!" << std::endl ;
			system("pause");
			system("cls");
			break;
		}

		system("cls");
		std::cout << "Passwords do not match! Try again: ";
	}
	currentAccount = std::make_shared<Account>(isAdmin, login, password);
}

void Hotel::SignOut()
{
	currentAccount = nullptr;
}


void Hotel::SetRoomReservationPossibility()
{
	int number;
	std::cout << "Enter hotel room number: ";
	std::cin >> number;

	if (hotelRooms.find(number) == hotelRooms.end())
		throw HotelException("room not found.");

	bool canBeReservation;
	std::cout << "Can be reservation: 1 - yes 0 - no." << std::endl;
	std::cin >> canBeReservation;

	hotelRooms.find(number)->second->SetCanBeReservation(canBeReservation);
}

void Hotel::AddRoom()
{
	std::cout << "Enter hotel room number: ";
	int number;
	std::cin >> number;
	if (hotelRooms.find(number) != hotelRooms.end())
		throw HotelException("Hotel room whith this number already exist.");

	std::cout << "Roominess(1 - 4): ";
	int roominess;
	do
		std::cin >> roominess;
	while (roominess < 1 || roominess > 4);

	std::cout << "Price: ";
	double price;
	std::cin >> price;

	hotelRooms.insert(std::pair<int, std::shared_ptr<HotelRoom>>(number, std::make_shared<HotelRoom>(roominess, price)));
}

void Hotel::DeleteRoom()
{
	std::cout << "Enter hotel room number: ";
	int number;
	std::cin >> number;
	auto it = hotelRooms.find(number);
	if (it == hotelRooms.end())
		throw HotelException("Hotel room not found.");

	std::ostringstream filePath;
	filePath << reservationsFilePath << number << ".bin";
	std::ifstream ifile(filePath.str(), std::ios::binary);
	if (ifile.is_open())
		throw HotelException("Hotel room reserved. You can to prohibit a reservation.");
	hotelRooms.erase(it);
	std::cout << "Completed." << std::endl;
}

Date Hotel::AskDate()
{
	Date date;
	std::cout << "Year: ";
	std::cin >> date.year;
	std::cout << "Month: ";
	std::cin >> date.month;
	while (date.month < 1 || date.month > 12)
	{
		std::cout << "Range of months: 1 - 12" << std::endl;
		std::cin >> date.month;
	}
	std::cout << "Day: ";
	std::cin >> date.day;
	while (date.day > date.GetDaysInMonth())
	{
		std::cout << "Range of days in this month: 1 - " << date.GetDaysInMonth();
		std::cin >> date.day;
	}
	return date;
}

std::map<int, std::shared_ptr<HotelRoom>> Hotel::FindAvailableRooms(Date occupancy, Date eviction, int persons = 0)
{
	std::map<int, std::shared_ptr<HotelRoom>> availableRooms;
	for (auto room : hotelRooms)
	{
		if (persons == 0 || room.second->GetRoominess() == persons && room.second->CanBeReservated())
		{
			auto it = reservations.find(room.first);
			if (it != reservations.end())
			{
				bool isAvailable = true;
				for (auto reservation: it->second)
				{
					if (!(occupancy < reservation->GetOccupancyDate() && eviction < reservation->GetOccupancyDate() || occupancy > reservation->GetEvictionDate()))
					{
						isAvailable = false;
						break;
					}
				}
				if(isAvailable)
					availableRooms.insert(std::pair<int, std::shared_ptr<HotelRoom>>(room.first, room.second));
			}
			else
				availableRooms.insert(std::pair<int, std::shared_ptr<HotelRoom>>(room.first, room.second));
		}
	}
	return availableRooms;
}

void Hotel::ShowAvailableRooms()
{
	std::cout << "Occupancy date" << std::endl;
	Date occupancy = AskDate();
	std::cout << "Eviction date" << std::endl;
	Date eviction = AskDate();
	while (occupancy - eviction >= 0 || Date::Now() - occupancy >= 0)
	{
		if (occupancy - eviction >= 0)
			std::cout << "Occupancy date shoud be earlier eviction date." << std::endl;
		else
			std::cout << "Can not to reserve on a past date." << std::endl;
		std::cout << "Occupancy date:";
		occupancy = AskDate();
		std::cout << "Eviction date:";
		eviction = AskDate();
	}
	auto availableRooms = FindAvailableRooms(occupancy, eviction);
	if (availableRooms.empty())
	{
		std::cout << "Sorry, no free rooms." << std::endl;
		return;
	}

	for (auto room : availableRooms)
	{
		std::cout << "room " << room.first << ": ";
		room.second->Print();
	}
}

void Hotel::ShowReservations() const
{
	for (auto roomReservations : reservations)
	{
		std::cout << "room " << roomReservations.first << ": ";
		hotelRooms.find(roomReservations.first)->second->Print();
		for (auto reservation : roomReservations.second)
		{
			std::cout << "\t";
			reservation->Print();
		}
	}
}

void Hotel::ReserveRoom()
{
	std::cout << "Occupancy date" << std::endl;
	Date occupancy = AskDate();
	std::cout << "Eviction date" << std::endl;
	Date eviction = AskDate();
	while (occupancy - eviction >= 0 || Date::Now() - occupancy >= 0)
	{
		if (occupancy - eviction >= 0)
			std::cout << "Occupancy date shoud be earlier eviction date." << std::endl;
		else
			std::cout << "Can not to reserve on a past date." << std::endl;
		std::cout << "Occupancy date:";
		occupancy = AskDate();
		std::cout << "Eviction date:";
		eviction = AskDate();
	}
	int persons;
	std::cout << "number of persons(1 - 4): ";
	std::cin >> persons;
	while (persons < 1 || persons > 4)
	{
		std::cout << "Range of person: 1 - 4. Yor can to reserv another room after if you need more seats." << std::endl;
		std::cin >> persons;
	}

	auto availableRooms = FindAvailableRooms(occupancy, eviction, persons);
	if (availableRooms.empty())
	{
		std::cout << "Sorry, no free rooms." << std::endl;
		return;
	}
	for (auto room : availableRooms)
	{
		std::cout << "room " << room.first << ": ";
		room.second->Print();
	}
	std::cout << "What room you want to reserve? Enter number: ";
	int number;
	std::cin >> number;
	while (availableRooms.find(number) == availableRooms.end())
	{
		std::cout << "In this list no such room. Try again: ";
		std::cin >> number;
	}
	
	auto it = reservations.find(number);
	if (it == reservations.end())
	{
		std::vector<std::shared_ptr<Reservation>> reservation;
		reservation.push_back(std::make_shared<Reservation>(currentAccount->GetLogin(), occupancy, eviction));
		reservations.insert(std::pair<int, std::vector<std::shared_ptr<Reservation>>>(number, reservation));
	}
	else
	{
		it->second.push_back(std::make_shared<Reservation>(currentAccount->GetLogin(), occupancy, eviction));
	}
	std::cout << "Completed." << std::endl;
}

std::vector<std::pair<int, std::shared_ptr<Reservation>>> Hotel::FindUserReservedRooms(std::string login)
{
	std::vector<std::pair<int, std::shared_ptr<Reservation>>> userReservations;
	for (auto roomReservations : reservations)
	{
		for (auto reservation : roomReservations.second)
		{
			if (reservation->GetLogin() == login)
				userReservations.push_back(std::pair<int, std::shared_ptr<Reservation>>(roomReservations.first, reservation));
		}
	}
	return userReservations;
}

void Hotel::ShowUserReservedRooms()
{
	std::vector<std::pair<int, std::shared_ptr<Reservation>>> userReservations;
	if (currentAccount->IsAdmin())
	{
		std::string login;
		std::cin >> login; 
		userReservations = FindUserReservedRooms(login);
	}
	else
	{
		userReservations = FindUserReservedRooms(currentAccount->GetLogin());
	}
	if (userReservations.size() == 0)
	{
		std::cout << "You have not reservations" << std::endl;
		return;
	}
	PrintUserReservations(userReservations);
}

bool Hotel::CanToCancelRoomReservation(std::shared_ptr<Reservation> const& reservation)
{
	if (reservation->GetOccupancyDate() - Date::Now() < 7)
		return false;
	return true;
}

void Hotel::DeleteReservation(std::pair<int, std::shared_ptr<Reservation>> deleterReservation)
{
	auto it = reservations.find(deleterReservation.first);
	it->second.erase(std::find(it->second.begin(), it->second.end(), deleterReservation.second));
}

void Hotel::PrintUserReservations(std::vector<std::pair<int, std::shared_ptr<Reservation>>> userReservation)
{
	for (size_t i = 0; i < userReservation.size(); i++)
	{
		std::cout << "#" << (i + 1) << ": room " << userReservation[i].first << ": ";
		hotelRooms.find(userReservation[i].first)->second->Print();
		std::cout << " occupancy date - " << userReservation[i].second->GetOccupancyDate() <<
			" eviction date - " << userReservation[i].second->GetEvictionDate() << std::endl;
	}
}

void Hotel::CancelRoomReservation()
{
	auto userReservation = FindUserReservedRooms(currentAccount->GetLogin());
	if (userReservation.size() == 0)
	{
		std::cout << "You have not reservations" << std::endl;
		return;
	}
	PrintUserReservations(userReservation);
	size_t choice;
	std::cout << "What kind of reservation do you want to cancel? Enter number: ";
	std::cin >> choice;
	while (choice < 1 || choice > userReservation.size())
	{
		std::cout << "There is no such reservation. Try again: ";
		std::cin >> choice;
	}
	if (CanToCancelRoomReservation(userReservation[choice - 1].second))
	{
		DeleteReservation(userReservation[choice - 1]);
		std::cout << "Completed." << std::endl;
	}
	else
	{
		std::cout << "Sorry You can not to cancel reservation in less than 7 days." << std::endl;
	}
}

void Hotel::ShowUserInformation()
{
	std::string login;
	std::cout << "Enter user login: ";
	std::cin >> login;
	if (login == currentAccount->GetLogin())
	{
		std::cout << "It is your account." << std::endl;
		return;
	}
	std::ostringstream filePath;
	filePath << accountsFilePath << login << ".bin";
	std::ifstream ifile(filePath.str(), std::ios::binary);
	if (!ifile.is_open())
		throw HotelException("Account with this login not found.");
	std::string password;
	std::string mail;
	std::string fullName;
	ifile >> password >> password >> mail >> fullName;
	std::cout << "password: " << password << "\nmail: " << mail << "\nfullName: " << fullName << std::endl;
	getchar();
}

void Hotel::ShowHotelRoomInformation()
{
	int number;
	std::cout << "Enter hotel room number: ";
	std::cin >> number;
	auto it = hotelRooms.find(number);
	if (it == hotelRooms.end())
		throw HotelException("Room with this number not found");
	it->second->Print();
	if (it->second->CanBeReservated())
		std::cout << "Can be reservated." << std::endl;
	else
		std::cout << "Can not be reservated." << std::endl;
}