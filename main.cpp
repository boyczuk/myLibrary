// main.cpp
#include <cstdlib>
#include <iostream>
#include "functions.h"


int mainmen(void)
{
	int userChoice;
	
	while (true)
	{
		userChoice = mainMenu();
		if (userChoice == 2)
		{
			// View Library
			userChoice = viewLibrary();
		}
		else if (userChoice == 1)
		{
			// Add Book
			userChoice = viewAddBook();
			// Find a better way to keep menu

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
