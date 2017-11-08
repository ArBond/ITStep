#pragma once

#include "hotel.h"

#include <iostream>

enum GlobalMenuItem
{
	Exit,
	SignIn,
	Checkin
};

enum AdminMenuItem
{
	AdminSignOut,
	AddHotelRoom,
	DeleteHotelRoom,
	SetRoomReservationPossibility,
	ViewReservations,
	ViewFreeHotelRoom,
	ShowUserInforvaton,
	ShowHotelRoomInformation,
	AdminChangePassword

};

enum UserMenuItem
{
	UserSignOut,
	ReserveRoom,
	CancelRoomReservation,
	ShowMyReservations,
	UserChangePassword
};

class Menu
{
private:
	std::unique_ptr<Hotel> hotel;

public:
	Menu(Hotel hotel);
	void MainMenuStart();
	void UserMenuStart();
	void AdminMenuStart();
};






Menu::Menu(Hotel hotel):
	hotel(std::make_unique<Hotel>(hotel))
{
}

void Menu::MainMenuStart()
{
	bool exit = false;
	int choice;
	while (!exit)
	{
		std::cout << SignIn << " - sign in\n" << Checkin << " - check in\n" << Exit << " - exit" << std::endl;
		std::cin >> choice;
		system("cls");

		try
		{
			switch (choice)
			{
			case SignIn:
				hotel->SignIn();
				if (hotel->GetCurrentAccount()->IsAdmin())
					AdminMenuStart();
				else
					UserMenuStart();
				break;
			case Checkin:
				hotel->CheckIn();
				break;
			case Exit:
				hotel->SaveData();
				exit = true;
				break;
			default:
				std::cout << "error input!";
				break;
			}
		}
		catch (HotelException ex)
		{
			system("cls");
			std::cout << ex.what() << std::endl;
		}
		system("pause");
		system("cls");
	}
}

void Menu::UserMenuStart()
{
	int choice;
	while(true)
	{
		std::cout << ReserveRoom << " - reserve room\n" << CancelRoomReservation << " - cancel room reservation\n" << ShowMyReservations << " - show my reservations\n" 
			<< UserChangePassword << " - change password\n" << UserSignOut << " - sign out" << std::endl;
		std::cin >> choice;
		system("cls");

		try
		{
			switch (choice)
			{
			case ReserveRoom:
				hotel->ReserveRoom();
				break;
			case CancelRoomReservation:
				hotel->CancelRoomReservation();
				break;
			case ShowMyReservations:
				hotel->ShowUserReservedRooms();
				break;
			case UserChangePassword:
				hotel->GetCurrentAccount()->ChangePassword();
				break;
			case UserSignOut:
				hotel->SignOut();
				return;
			default:
				std::cout << "error input!";
				break;
			}
		}
		catch (HotelException ex)
		{
			system("cls");
			std::cout << ex.what() << std::endl;
		}
		system("pause");
		system("cls");
	}
}

void Menu::AdminMenuStart()
{
	int choice;
	while(true)
	{
		std::cout << AddHotelRoom << " - add hotel room\n" << DeleteHotelRoom << " - delete hotel room\n" << SetRoomReservationPossibility << " - set room reservation possibility\n"
			<< ViewReservations << " - view reservations\n" << ViewFreeHotelRoom << " - view free hotel room\n" << ShowUserInforvaton << " - show user inforvaton\n"
			<< ShowHotelRoomInformation << " - show hotel room information\n" << AdminChangePassword << " - change password\n" << AdminSignOut << " - sign out" << std::endl;
		std::cin >> choice;
		system("cls");

		try
		{
			switch (choice)
			{
			case AddHotelRoom:
				hotel->AddRoom();
				break;
			case DeleteHotelRoom:
				hotel->DeleteRoom();
				break;
			case SetRoomReservationPossibility:
				hotel->SetRoomReservationPossibility();
				break;
			case ViewReservations:
				hotel->ShowReservations();
				break;
			case ViewFreeHotelRoom:
				hotel->ShowAvailableRooms();
				break;
			case ShowUserInforvaton:
				hotel->ShowUserInformation();
				break;
			case ShowHotelRoomInformation:
				hotel->ShowHotelRoomInformation();
				break;
			case AdminChangePassword:
				hotel->GetCurrentAccount()->ChangePassword();
				break;
			case AdminSignOut:
				hotel->SignOut();
				return;
			default:
				std::cout << "error input!";
				break;
			}
		}
		catch (HotelException ex)
		{
			system("cls");
			std::cout << ex.what() << std::endl;
		}
		system("pause");
		system("cls");
	}
}