# Makefile for main.cpp
myLibrary : main.o models.o cli.o
	g++ -o myLibrary main.o models.o cli.o

main.o : main.cpp functions.h
	g++ -c main.cpp

models.o : models.cpp functions.h
	g++ -c models.cpp

cli.o : cli.cpp functions.h
	g++ -c cli.cpp
	
clean :
	rm myLibrary *.o