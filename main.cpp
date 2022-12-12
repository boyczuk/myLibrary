// main.cpp
#include <cstdlib>
#include <iostream>
#include "functions.h"

int main(void)
{
	int userChoice;

	while (true)
	{
		std::cout << "\nWelcome to myLibrary!\n========================\nType...\n2. View library\n1. Add book\n0. Exit\n";
		std::cin >> userChoice;

		if (userChoice == 2)
		{
			viewLibrary();
		}
		else if (userChoice == 1)
		{
			viewAddBook();
		}
		else if (userChoice == 0)
		{
			break;
		}
		else
		{
			std::cout << "Invalid selection\n";
		}
	}

	return 0;
}
