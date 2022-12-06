#include<cstdlib>
#include<iostream>
#include "functions.h"

int mainMenu(){
	int userChoice;
	
	std::cout << "Welcome to myLibrary!\n========================\nType...\n2. View library\n1. Add book\n0. Exit\n";
	std::cin >> userChoice;
	std::cout << "\nYour choice: " << userChoice << "\n";
    
    return userChoice;
}

int viewLibrary(){
    int userChoice;
	
	std::cout << "Library\n========================\nType 0 to exit\n";
	std::cout << "Book example 1\n";
    std::cin >> userChoice;
	
    
    return userChoice;
}

int addBook(){
    int userChoice;
	
	std::cout << "Welcome to myLibrary!\n========================\nType 0 to exit\n";
	std::cout << "Space to add query\n";
    std::cin >> userChoice;
	
    
    return userChoice;
}