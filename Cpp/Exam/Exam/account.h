#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

#include "hotelException.h"

class Account
{
protected:
	bool isAdmin;
	std::string login;
	std::string password;

public:
	Account(bool isAdmin, std::string login, std::string password) :
		isAdmin(isAdmin), login(login), password(password)
	{
	}

	std::string GetLogin() const;
	bool IsAdmin() const;
	void ChangePassword();
	void SavePassword();
};




std::string Account::GetLogin() const
{
	return login;
}

bool Account::IsAdmin() const
{
	return isAdmin;
}

void Account::ChangePassword()
{
	std::string oldPassword;
	std::cout << "enter old password: ";
	std::cin >> oldPassword;
	if (oldPassword != password)
		throw HotelException("Passwords do not match!");

	std::string newPassword;
	std::string newPasswordConfirmation;
	int count = 0;
	while (count++ < 3)
	{
		std::cout << "Enter new password: ";
		std::cin >> newPassword;
		std::cout << "Confirm new password: ";
		std::cin >> newPasswordConfirmation;
		if (newPassword == newPasswordConfirmation)
		{
			password = newPassword;
			SavePassword();
			std::cout << "Completed!" << std::endl;
			return;
		}
		system("cls");
		std::cout << "Passwords do not match! Try again:";
	}
	std::cout << "3 trys failed";
}

void Account::SavePassword()
{
	std::ostringstream filePath;
	filePath << "Accounts\\" << login << ".bin";
	
	if (isAdmin)
	{
		std::ofstream ofile(filePath.str(), std::ios::binary | std::ios::trunc);
		ofile << isAdmin << " " << password << std::endl;
		ofile.close();
	}
	else
	{
		std::ifstream ifile(filePath.str(), std::ios::binary);
		std::string mail;
		std::string fullName;
		std::string buf;
		ifile >> buf >> buf >> mail >> fullName;
		ifile.close();
		std::ofstream ofile(filePath.str(), std::ios::binary | std::ios::trunc);
		ofile << isAdmin << " " << password << " " << mail << " " << fullName << std::endl;
		ofile.close();
	}
}