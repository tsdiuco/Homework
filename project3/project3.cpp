/*
Class: CPSC 122-02
Team Member 1: Trevor Diuco
Team Member 2: None
Submitted By: Trevor Diuco
GU Username: tdiuco
File Name: project2.cpp
Program that has the functionality to either encrypt or decrypt a caeser cipher message
To Build: g++ project2.cpp -o project2
To Execute: ./project2 inFile.in outFile.out mode(0/1) shift (1-25)
*/

#include <iostream>
#include <fstream>
#include <cstdlib>


using namespace std;

char encrypt(char, int);
char decrypt(char, int);

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

int main(int argc, char* argv[])
{
   if (argc != 5)
   {
      cout << "Incorrect number of command line arguments... Exiting Program\n";
      exit(EXIT_FAILURE);
   }

   int mode = atoi(argv[3]);
   int shift = atoi(argv[4]);

   ifstream inputFile;
   ofstream outputFile;

   inputFile.open(argv[1]);
   outputFile.open(argv[2]);

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