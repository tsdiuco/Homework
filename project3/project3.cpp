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

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <array>

using namespace std;

char encrypt(char, int, int);
char decrypt(char, int[], int, int);
bool validAlpha (int, int[]);
void fillHash(int[], fstream&);
void checkCommandArgmuents(int, char*[]);
void fileOpen(fstream&, char[], char);

/*
Pre: ch is the character to be encoded. Alpa and Beta is an integer in the range [0..25]
Post: returns an encrypted character using the Affine cipher method where even alphabet-wrap accounted for.
*/

char encrypt(char ch, int alpha, int beta)
{
   ch = toupper(ch);
   if (isalpha(ch))
      return ((ch * alpha) + beta - 65) % 26 + 65;    // 65 represents the first capital letter in the ascii table
   return ch;
}

/*
Pre: ch is the character to be decoded. Alpa and Beta is an integer in the range [0..25]
Post: returns a decrypted character using the Affine cipher method where even alphabet-wrap accounted for.
*/

char decrypt(char ch, int MIarray[], int alpha, int beta)
{
   ch = toupper(ch);
   if (isalpha(ch))
      return ((MIarray[alpha] * ch) - (MIarray[alpha] * beta) + 65) % 26 + 65;    // 65 represents the first capital letter in the ascii table
   return ch;
}

/*
Pre: MIarray is an empty array of size 26 that will act as the hash table. MIfile contains %26 multiplicative inverses.
Post: The result is an updated array of size 26 with that maps the idices to the multiplicative inverses. -1 if no inverse exists.
*/

void fillHash(int MIarray[], fstream& MIfile)
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

/*
Pre: argv[] contains the command line arguments.
Post: Checks proper notion of each command line argument as well as the proper amount of total arguments
*/

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
   if (atoi(argv[5]) > 25 || atoi(argv[6]) < 1)          // Checking valid input of alpha
   {
      cout << "Alpha's input has a range of [1..25]... Exiting Program\n";
      exit(EXIT_FAILURE);
   }
   if (atoi(argv[6]) > 25 || atoi(argv[6]) < 1)          //Checking valid input for Beta
   {
      cout << "Beta's input has a range of [1..25]... Exiting Program\n";
      exit(EXIT_FAILURE);
   }
}

/*
Pre: Checks if the alpha stated has a multiplicative inverse and therefore can be encypted/decrypted
Post: Returns a bool value weither or not the alpha is valid
*/

bool validAlpha (int alpha, int MIarray[])
{
   if (MIarray[alpha] == -1) {
      return false;
   }
   return true;
}

/*
Pre: Takes in a fstream variable the arg value and a char to distinguish the type of file
Post: Files are checked if they opened successfully and labled what type of file
*/

void fileOpen(fstream& file, char name[], char mode)
{
 string fileType;

 if (mode == 'r')
  fileType = "input";
 if (mode == 'w')
  fileType = "output";

 if (mode == 'r')
  file.open(name, ios::in);  //available thorugh fstream
 if (mode == 'w')
  file.open(name, ios::out);  //available through fstream;

 if (file.fail()) //error condition
 {
  cout << "Error opening " << fileType << " file" << endl;
  exit(EXIT_FAILURE);
 }
}

int main(int argc, char* argv[])
{
   checkCommandArgmuents(argc, argv);

   // ifstream inputFile;
   // ifstream MIfile;
   // ofstream outputFile;

   // inputFile.open(argv[1]);
   // outputFile.open(argv[2]);
   // MIfile.open(argv[3]);

   fstream inputFile;
   fstream outputFile;
   fstream MIfile;

   fileOpen(inputFile, argv[1], 'r');
   fileOpen(outputFile, argv[2], 'w');
   fileOpen(MIfile, argv[3], 'w');

   int mode = atoi(argv[4]);
   int alpha = atoi(argv[5]);
   int beta = atoi(argv[6]);
   int MIarray[26];

   fillHash(MIarray, MIfile);

   if (!validAlpha(alpha, MIarray))
   {
      cout << "Alpha does not have a multiplicative inverse because Alpha is not a prime with 26...Exiting program\n";
      exit(EXIT_FAILURE);
   }

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
   //MIfile is closed in fillHash()

   return 0;
}