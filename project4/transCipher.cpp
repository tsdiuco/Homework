#include "transCipher.h"

void key_gen(int key[26])
{
   bool validate[26] = {false};
   int k = 0;
   srand(time(0));

   for (int i = 0; i < 26; i++)
   {
      k = rand() % 26;
      while (validate[k])
         k = rand() % 26;
      validate[k] = 1;
      key[i] = k;
   }
}

char transform (char ch, int arr[26][2])
{
   if (isalpha(ch))
      return arr[ch - 65][1] + 65;
   return ch;
}

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

   if (file.fail())
   {
      cout << "Error opening " << fileType << " file" << endl;
      exit(EXIT_FAILURE);
   }
}

void readKeyFile(fstream& keyFile, int pt_ct[26][2])
{
   int count = 0;
   while (keyFile.peek() != EOF)
      keyFile >> pt_ct[count++][1];
}

void selection_sort(int arr[26][2])
{
   int minLocation = 0;
   for (int i = 0; i < 25; i++)
   {
      minLocation = i;
      for (int j = i + 1; j < 26; j++)
         if (arr[j][0] < arr[minLocation][0])
            minLocation = j;
      swap(i, minLocation, arr);
   }
}

void swap(int begin, int minLocation, int arr[26][2])
{
   int temp = arr[begin][0];
   int temp2 = arr[begin][1];
   arr[begin][0] = arr[minLocation][0];
   arr[begin][1] = arr[minLocation][1];
   arr[minLocation][0] = temp;
   arr[minLocation][1] = temp2;
}