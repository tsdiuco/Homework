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

#include <iostream>
using namespace std;

#include <ctime>
#include "project5.h"

TransPos::TransPos(string inp_name_in, string out_name_in, string key_name_in, int mode_in)
{
   cout << "Entered the encrypt/decrypt constructor" << endl;
   inp_name = inp_name_in;
   out_name = out_name_in;
   key_name = key_name_in;
   mode = mode_in;

   key_enc = new int[R];
   key_dec = new int[R];

   ctpt = new int*[R]; //rows
   for (int i = 0; i < R; i++)   //cols
      ctpt[i] = new int[C];

   if (mode == 0) {
      cout << "Entering Encryption Mode\n";
      // 1. Read Key File
      readKeyFile();
      // 2. Transform inFile
      // 3. Write to outFile
      fileOpen(fin,inp_name,'r');
      fileOpen(fout,out_name,'w');
      transpose(key_enc);
   }

   if (mode == 1) {
      cout << "Entering Decryption Mode\n";
      // 1. Read Key File
      readKeyFile();
      // 2. Create Dec Key
      dec_key_gen();
      // 3. Transform inFile
      // 4. Write to outFile
      fileOpen(fin,inp_name,'r');
      fileOpen(fout,out_name,'w');
      transpose(key_dec);
   }

}

TransPos::TransPos(string key_name_in)
{
   cout << "Entered the key creation constructor" << endl;
   key_name = key_name_in;
   key_enc = new int[R]; //holds encryption key
   key_dec = new int[R];

   //ctpt is a dynamically declared 2D array
   ctpt = new int*[R]; //rows
   for (int i = 0; i < R; i++)   //cols
      ctpt[i] = new int[C];
}

void TransPos::store_enc_key()
{
   enc_key_gen();
   fileOpen(fkey,key_name,'w');
   for(int i = 0; i < R; i++)
      fkey << key_enc[i] << ' ';
   fkey << endl;
   fkey.close();
}

//generate the encryption key
void TransPos::enc_key_gen()
{
   bool validate[R] = {false};

   srand(time(0));
   int pos = 0;

   while (pos < R)
   {
      while(true)
      {
         int k = rand() % R;
         if (!validate[k])
         {
            key_enc[pos] = k;
            validate[k] = true;
            pos++;
            break;
         }
      }
   }
}

void TransPos::store_dec_key()
{
   dec_key_gen();
   //append dec key to key file
   fileOpen(fkey,key_name,'a');
   //storing 0 .. 25 on the second line of the key file to demonstrate appending
   //to an existing file
   for (int i = 0; i < R; i++)
      fkey << key_dec[i] << ' ';
   fkey << endl;
   fkey.close();
}

void TransPos::dec_key_gen()
{
   //make ctpt for sorting purposes
   for (int i = 0; i < R; i++)
   {
      ctpt[i][0] = i;
      ctpt[i][1] = key_enc[i];
   }

   for (int i = 0; i < R; i++) {
      for (int j = 0; j < R; j++) {
         if (ctpt[j][1] == i) {
            key_dec[i] = ctpt[j][0];
            break;
         }
      }
   }
}

void TransPos::fileOpen(fstream& file, string name, char mode)
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
   if (mode == 'a')
      file.open(name, ios::app);  //available through fstream;

   if (file.fail()) //error condition
   {
      cout << "Error opening " << fileType << " file" << endl;
      exit(EXIT_FAILURE);
   }
}

void TransPos::readKeyFile()
{
   fileOpen(fkey,key_name,'r');
   int count = 0;
   while (fkey.peek() != EOF)
      fkey >> key_enc[count++];       // One single int is read and placed in array, count is incremented
}

void TransPos::transpose(int* cipher) {
   char ch = 'A';
   while(fin.peek() != EOF)
   {
      ch = toupper(fin.get());
      fout << transform(ch, cipher);
   }
}

char TransPos::transform (char ch, int* cipher)
{
   if (isalpha(ch))
      return cipher[ch - 65] + 65;
   return ch;
}