#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

int mainMenu();
int viewLibrary();
int viewAddBook();
void addBook(std::string title, std::string author, std::string genre, std::string description, std::string date);
static int callback(void *NotUsed, int argc, char **argv, char **azColName);

#endif