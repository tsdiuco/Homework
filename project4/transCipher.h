#ifndef TRANSCIPHER_H
#define TRANSCIPHER_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>

using namespace std;

void generateKey(char[]);
char transform (char, int[][2]);
void fileOpen(fstream& , char [], char);
void readKeyFile(fstream&, char[][2]);

#endif