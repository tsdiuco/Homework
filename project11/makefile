#Class: CPSC 122-02
#Trevor Diuco
#GU Username: tdiuco
#Submitted By: Trevor Diuco
#GU Username: tdiuco
#File Name: list.cpp
#Make file for a simple linked list that adds and deletes at the head
#Traversals are done recursively
#To Build: make
#To Execute: ./list

#to run: make
#to eliminate .o file: make clean

list: listTst.o list.o
	g++ -o list listTst.o list.o

listTst.o: listTst.cpp
	g++ -c listTst.cpp

list.o: list.cpp
	g++ -c list.cpp

clean:
	rm *.o