#include <cstdlib>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "functions.h"

using namespace std;

int viewLibrary()
{
	cout << "View Library Page" << endl;

	return 0;
}

int viewAddBook()
{
	string title;
	string author;
	string genre;
	string description;
	string date;

	cout << "Add Book Page" << endl;
	cout << "Title: ";
	cin.ignore();
	getline(cin, title);
	
	cout << "Author: ";
	getline(cin, author);

	cout << "Genre: ";
	getline(cin, genre);

	cout << "Description: ";
	getline(cin, description);

	cout << "Date: ";
	getline(cin, date);

	addBook(title, author, genre, description, date);

	return 0;
}