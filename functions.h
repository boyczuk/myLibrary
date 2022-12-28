#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

int mainMenu();
int viewLibrary();
int viewAddBook();
int viewRemoveBook();
void addBook(std::string title, std::string author, std::string genre, std::string status, std::string date);
void displayBooks();
void removeBook(std::string title, std::string author);
static int callback(void *NotUsed, int argc, char **argv, char **azColName);

#endif