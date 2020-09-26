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

#include "affineCipher.h"

/*
Pre: ch is the character to be encoded. shift is an integer in the range [1..25]
Post: returns an encrypted character, i.e., shifted right shift positions, alphabet-wrap accounted for.
*/

char encrypt(char ch, int shift)
{
   ch = toupper(ch);
   if (isalpha(ch))
      return (ch + shift - 65) % 26 + 65;    // 65 represents the first capital letter in the ascii table
   return ch;
}

/*
Pre: ch is the character to be decoded. shift is an integer in the range [1..25]
Post: returns a decrypted character, i.e., shifted left shift positions, negative numbers accounted for.
*/

char decrypt(char ch, int shift)
{
   ch = toupper(ch);
   if (isalpha(ch))
      return (ch - shift + 65) % 26 + 65;    // 65 represents the first capital letter in the ascii table
   return ch;
}

void fillHash(int MIarray[], ifstream& MIfile)
{
   int n = 0;
   int index = 0;
   int multiInverse;

   while (MIfile.peek() != EOF)
   {
      MIfile >> n;
      while (index != n)
      {
         MIarray[index] = -1;
         index++;
      }
      MIfile >> multiInverse;
      MIarray[index] = multiInverse;
      index++;
   }
   MIfile.close();
}

void checkCommandArgmuents(int argc, char* argv[]) {
      if (argc != 7)
   {
      cout << "Incorrect number of command line arguments... Exiting Program\n";
      exit(EXIT_FAILURE);
   }
   if (atoi(argv[4]) != 0 && atoi(argv[4]) != 1)         //Checking valid input for Mode
   {
      cout << "Mode can only be 0 or 1... Exiting Program\n";
      exit(EXIT_FAILURE);
   }
   if (atoi(argv[6]) > 25 || atoi(argv[6]) < 1)          //Checking valid input for Beta
   {
      cout << "Beta's input has a range of [1..25]... Exiting Program\n";
      exit(EXIT_FAILURE);
   }
}