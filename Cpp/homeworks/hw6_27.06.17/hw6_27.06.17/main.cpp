#include "calculator.h"

void main()
{
	std::cout << "Welcome to Calculator!" << std::endl;
	Calculator calc;
	std::vector<Operation*>::iterator it;
	int choice;
	while (true)
	{
		it = calc.Begin();
		calc.ShowMenu();
		std::cin >> choice;
		if (choice > 0 && choice <= calc.GetOperationCuantity())
		{
			it += choice - 1;
			calc.ExecuteOperation(*it);
			continue;
		}
		else if (choice == 0)
		{
			break;
		}
		std::cout << "There is no such item!" << std::endl;
		
	}
	std::cout << "Good luck!" << std::endl;
}