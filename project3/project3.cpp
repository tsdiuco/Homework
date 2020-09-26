/*
Class: CPSC 122-02
Team Member 1: Trevor Diuco
Team Member 2: None
Submitted By: Trevor Diuco
GU Username: tdiuco
File Name: project3.cpp
Program that has the functionality to either encrypt or decrypt a Affine cipher message
To Build: g++ project3.cpp -o project3
To Execute: ./project3 inFile.in outFile.out MIfile mode(0/1) alpha beta
*/

#include "affineCipher.h"

int main(int argc, char* argv[])
{
   checkCommandArgmuents(argc, argv);

   int mode = atoi(argv[4]);
   int alpha = atoi(argv[5]);
   int beta = atoi(argv[6]);
   int MIarray[26];

   ifstream inputFile;
   ifstream MIfile;
   ofstream outputFile;

   inputFile.open(argv[1]);
   outputFile.open(argv[2]);
   MIfile.open(argv[3]);

   fillHash(MIarray, MIfile);

   if (mode == 0)             // Encrypt
   {
      while (inputFile.peek() != EOF)
      {
         outputFile << encrypt(inputFile.get(), alpha, beta);
      }
      outputFile << endl;
   }
   else                       // Decrypt
   {
      while(inputFile.peek() != EOF)
      {
         outputFile << decrypt(inputFile.get(), MIarray, alpha, beta);
      }
      outputFile << endl;
   }

   inputFile.close();
   outputFile.close();

   return 0;
}