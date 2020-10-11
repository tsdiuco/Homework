#ifndef TRANSCIPHER_H
#define TRANSCIPHER_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>

using namespace std;

void key_gen(int[]);
char transform (char, int[][2]);
void fileOpen(fstream& , char[], char);
void readKeyFile(fstream&, int[][2]);
void selection_sort(int[][2]);
void swap(int, int, int[][2]);

#endif