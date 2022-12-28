// main.cpp
#include <cstdlib>
#include <iostream>
#include "functions.h"

int main(void)
{
	int userChoice;

	while (true)
	{
		std::cout << "\nWelcome to myLibrary!\n========================\nType...\n3. View library\n2. Add book\n1. Remove book\n0. Exit\n";
		std::cin >> userChoice;

		if (userChoice == 3)
		{
			viewLibrary();
		}
		else if (userChoice == 2)
		{
			viewAddBook();
		}
		else if (userChoice == 1)
		{
			viewRemoveBook();
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
