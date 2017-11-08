#include "Menu.h"

#include <iostream>

void main()
{	
	std::cout << "Welcome to Plaza Hotel!" << std::endl;
	Hotel hotel;
	Menu menu(hotel);
	menu.MainMenuStart();
	std::cout << "Have a nice day!" << std::endl;
}