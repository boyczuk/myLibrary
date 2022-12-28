#include <cstdlib>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "functions.h"

using namespace std;

int viewLibrary()
{
	cout << "View Library Page" << endl;
	displayBooks();
	return 0;
}

int viewAddBook()
{
	string title;
	string author;
	string genre;
	string status;
	string date;

	cout << "Add Book Page" << endl;
	cout << "Title: ";
	cin.ignore();
	getline(cin, title);
	
	cout << "Author: ";
	getline(cin, author);

	cout << "Genre: ";
	getline(cin, genre);

	cout << "Status: ";
	getline(cin, status);

	cout << "Date: ";
	getline(cin, date);

	addBook(title, author, genre, status, date);

	return 0;
}

int viewRemoveBook()
{
	string title;
	string author = "";

	cout << "View removeBook Page" << endl;
	
	cout << "Enter Title to Remove:" << endl;
	cin.ignore();
	getline(cin, title);

	removeBook(title, author);
	return 0;
}