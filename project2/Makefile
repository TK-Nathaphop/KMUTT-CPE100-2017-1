#    This 'Makefile' is intended to build program Ghost Buster database.
#
#    Created by Nathaphop Sundarabhogin(KLA) ID : 3420
#        7 DECEMBER 2017
#

EXECUTABLES=ghostBuster

all : $(EXECUTABLES)

ghostBuster.o : ghostBuster.c ghostBuster.h
	gcc -c ghostBuster.c

manageData.o : manageData.c ghostBuster.h
	gcc -c manageData.c

database.o : database.c ghostBuster.h
	gcc -c database.c

validateEvent.o : validateEvent.c ghostBuster.h
	gcc -c validateEvent.c

askEvent.o : askEvent.c ghostBuster.h
	gcc -c askEvent.c

ghostBuster : ghostBuster.o database.o manageData.o validateEvent.o askEvent.o
	gcc -o ghostBuster ghostBuster.o database.o manageData.o validateEvent.o askEvent.o

clean : 
	-rm *.o
	-rm ghostBuster