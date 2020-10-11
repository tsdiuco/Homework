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

/*
Pre: key is a 26 position integer array
Post: key is filled with integers in the range [0..25] with no duplicates
*/
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

/*
Pre: ch is the character to be transformed, arr is a 2D transformation array
Post: Looks up the positional value of ch in the 0th col of arr, and returns the 1st col of arr
*/
char transform (char ch, int arr[26][2])
{
   if (isalpha(ch))
      return arr[ch - 65][1] + 65;
   return ch;
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

   if (file.fail())
   {
      cout << "Error opening " << fileType << " file" << endl;
      exit(EXIT_FAILURE);
   }
}

/*
Pre: keyFile is the file that contains the cipher key, pt_ct is a 2D transformation array
Post: pt_ct column 1 is filled with the cipher key from keyFile
*/
void readKeyFile(fstream& keyFile, int pt_ct[26][2])
{
   int count = 0;
   while (keyFile.peek() != EOF)
      keyFile >> pt_ct[count++][1];       // One single int is read and placed in array, count is incremented
}

/*
Pre: arr is an unsorted 2D transformation array
Post: arr column 0 is sorted smallest to greatest can colum 1 values follow with the sort
*/
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

/*
Pre: begin is the first position in arr that is being sorted, minLocation is the index of the smallest value
      arr is a 2D Transformation Array
Post: values at index minLocation and begin are swapped and updated arr is edited.
*/
void swap(int begin, int minLocation, int arr[26][2])
{
   int temp = arr[begin][0];
   int temp2 = arr[begin][1];
   arr[begin][0] = arr[minLocation][0];
   arr[begin][1] = arr[minLocation][1];
   arr[minLocation][0] = temp;
   arr[minLocation][1] = temp2;
}

int main(int argc, char* argv[])
{

   if (argc == 2)
   {
      fstream keyFile;
      fileOpen(keyFile, argv[1], 'w');

      int key[26];
      key_gen(key);
      for (int i = 0; i < 26; i++)
         keyFile << key[i] << " ";
   }
   else if (argc == 5)
   {
      fstream inFile, outFile, keyFile;
      fileOpen(inFile, argv[1], 'r');
      fileOpen(outFile, argv[2], 'w');
      fileOpen(keyFile, argv[3], 'r');

      int pt_ct[26][2], ct_pt[26][2];

      for (int i = 0; i < 26; i++)
         pt_ct[i][0] = i;                 // pt_ct col 0 is initialized with [0..25]
      readKeyFile(keyFile, pt_ct);

      for (int i = 0; i < 26; i++)
      {
         ct_pt[i][0] = pt_ct[i][1];       // Swapping Col 0 and Col 1 from pt_ct to ct_pt
         ct_pt[i][1] = pt_ct[i][0];
      }

      selection_sort(ct_pt);

      if (atoi(argv[4]) == 0)
      {
         char ch = 'A';
         while(inFile.peek() != EOF) {
            ch = toupper(inFile.get());
            outFile << transform(ch, pt_ct);
         }
      }
      else if (atoi(argv[4]) == 1)
      {
         char ch = 'A';
         while(inFile.peek() != EOF)
         {
            ch = toupper(inFile.get());
            outFile << transform(ch, ct_pt);
         }
      }
      else
      {
         cout << "Incorrect mode input... Exiting File\n";
         exit(EXIT_FAILURE);
      }
   }
   else
   {
      cout << "Incorrect number of command line arguments... Exiting Program\n";
      exit(EXIT_FAILURE);
   }
   return 0;
}