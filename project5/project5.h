/*
Class: CPSC 122-02
Team Member 1: Trevor Diuco
Team Member 2: None
Submitted By: Trevor Diuco
GU Username: tdiuco
File Name: project5.cpp
Program that has the functionality to either encrypt or decrypt using a transposition cipher message. It can also generate a encryption key.
To Build: g++ project5.cpp (project5Tst0.cpp or project5Tst1.cpp) -o project5
To Execute:
   Generate Key: ./project5 keyFile.txt
   Encrypt(0)/Decrypt(1): ./project5 inFile.in outFile.out keyFile.txt mode(0/1)
*/

#ifndef TRANS_H
#define TRANS_H
#include <fstream>
using namespace std;

class TransPos
{
public:
   TransPos(string inp_name_in, string out_name_in, string key_name_in, int mode);
   TransPos(string key_name_in);
   void store_enc_key();
   void store_dec_key();
   void transpose(int*);
   char transform(char, int*);
   //void readKeyFile();
private:
   void enc_key_gen();
   void dec_key_gen();
   void fileOpen(fstream& keyF, string name,  char mode);
   void readKeyFile();

   string key_name;
   string inp_name;
   string out_name;
   fstream fkey;
   fstream fin;
   fstream fout;
   int* key_enc;
   int* key_dec;
   int** ctpt;  //pointer to a 2D array
   int mode;
   static const int R = 26;
   static const int C = 2;
};
#endif