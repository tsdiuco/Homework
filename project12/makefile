# Class: CPSC 122-02
# Trevor Diuco
# GU Username: tdiuco
# Submitted By: Trevor Diuco
# GU Username: tdiuco
# File Name: makefile
# Make file for priority queue program
# To build: make
# To run: ./pqueue had we but world

#to run: make
#to eliminate .o files: make clean
pqueue: queue3Tst.o queue3.o queue2.o list.o
	g++ -o pqueue queue3Tst.o queue3.o queue2.o list.o

queue3Tst.o: queue3Tst.cpp
	g++ -c queue3Tst.cpp

queue3.o: queue3.cpp
	g++ -c queue3.cpp

queue2.o: queue2.cpp
	g++ -c queue2.cpp

list.o: list.cpp
	g++ -c list.cpp

clean :
	rm *.o
