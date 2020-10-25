/*
Class: CPSC 122-02
Team Member 1: Trevor Diuco
Team Member 2: None
Submitted By: Trevor Diuco
GU Username: tdiuco
File Name: project5.cpp
Program that has the functionality to either encrypt or decrypt using a transposition cipher message. It can also generate a encryption key.
To Build: g++ project5.cpp project5Tst1.cpp -o project5
To Execute:
   Generate Key: ./project5 keyFile.txt
   Encrypt(0)/Decrypt(1): ./project5 inFile.in outFile.out keyFile.txt mode(0/1)
*/

#include <iostream>
using namespace std;

#include "project5.h"

int main(int argc, char* argv[])
{
   TransPos trevor (argv[1],argv[2],argv[3], atoi(argv[4]));
}