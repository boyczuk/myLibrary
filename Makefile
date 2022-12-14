# Makefile for main.cpp
myLibrary : main.o models.o cli.o
	g++ -o myLibrary main.o models.o cli.o -lsqlite3

main.o : main.cpp functions.h
	g++ -c main.cpp -l sqlite3

models.o : models.cpp functions.h
	g++ -c models.cpp

cli.o : cli.cpp functions.h
	g++ -c cli.cpp