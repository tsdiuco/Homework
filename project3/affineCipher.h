/*
Class: CPSC 122-02
Team Member 1: Trevor Diuco
Team Member 2: None
Submitted By: Trevor Diuco
GU Username: tdiuco
File Name: project3.cpp
Program that has the functionality to either encrypt or decrypt a Affine cipher message
To Build: g++ project3.cpp -o project3
To Execute: ./project2 inFile.in outFile.out MIfile mode(0/1) alpha beta
*/

#ifndef AFFINECIPHER_H
#define AFFINECIPHER_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <array>

using namespace std;

char encrypt(char, int);
char decrypt(char, int);
void fillHash(int[], ifstream&);
void checkCommandArgmuents(int, char*[]);

#endif