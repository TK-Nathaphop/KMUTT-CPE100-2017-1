# This makefile is intended to build the two test programs for
# CPE100 Lab Lab. It also shows how to create and use a simple 
# makefile
#
# Note that this makefile assumes a Linux environment. The executables
# have no extension.
#
#  Updated 21 October 2014 by Sally Goldin
#  Updated 23 October 2017 by Nathaphop Sundarabhogin ID 3420
#

EXECUTABLES=checkFuture

all : $(EXECUTABLES)

dateFunctions.o : dateFunctions.c dateFunctions.h
	gcc -c dateFunctions.c

checkFuture.o : checkFuture.c dateFunctions.h
	gcc -c checkFuture.c

checkFuture : checkFuture.o dateFunctions.o
	gcc -o checkFuture checkFuture.o dateFunctions.o

EXECUTABLES=datecalc

all : $(EXECUTABLES)

datecalc : datecalc.o dateFunctions.o
	gcc -o datecalc datecalc.o dateFunctions.o

clean : 
	-rm *.o
	-rm datecalc
	-rm checkFuture