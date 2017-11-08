#pragma once

#include <exception>
#include <string>

class HotelException : public std::exception
{
private:
	std::string message;

public:
	HotelException(std::string message) :
		message(message)
	{
	}

	char const* what() const override
	{
		return message.c_str();
	}
};