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
   // if (argc != 7)
   // {
   //    cout << "Incorrect number of command line arguments... Exiting Program\n";
   //    exit(EXIT_FAILURE);
   // }
   // if (atoi(argv[4]) != 0 && atoi(argv[4]) != 1)         //Checking valid input for Mode
   // {
   //    cout << "Mode can only be 0 or 1... Exiting Program\n";
   //    exit(EXIT_FAILURE);
   // }
   // if (atoi(argv[6]) > 25 || atoi(argv[6]) < 1)          //Checking valid input for Beta
   // {
   //    cout << "Beta's input has a range of [1..25]... Exiting Program\n";
   //    exit(EXIT_FAILURE);
   // }
   checkCommandArgmuents(argc, argv);

   int mode = atoi(argv[3]);
   int shift = atoi(argv[4]);
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
         outputFile << encrypt(inputFile.get(), shift);
      }
      outputFile << endl;
   }
   else                       // Decrypt
   {
      while(inputFile.peek() != EOF)
      {
         outputFile << decrypt(inputFile.get(), shift);
      }
      outputFile << endl;
   }

   inputFile.close();
   outputFile.close();

   return 0;
}