// main.cpp
#include <cstdlib>
#include <iostream>
#include "functions.h"

int main(void)
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
			userChoice = addBook();

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
