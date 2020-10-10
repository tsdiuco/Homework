#include "transCipher.h"

void generateKey(char key[]) {
   bool validate[26] = {false};
   int k = 0;
   srand(time(0));

   for (int i = 0; i < 26; i++) {
      k = rand() % 26;
      while (validate[k])
         k = rand() % 26;
      validate[k] = 1;
      key[i] = k + 65;
   }

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

 if (file.fail()) //error condition
 {
  cout << "Error opening " << fileType << " file" << endl;
  exit(EXIT_FAILURE);
 }
}

void readKeyFile(fstream& keyFile, char cipherArray[26][2]) {
   int count = 0;
   char keyChar = 'A';
   while (keyFile.peek() != EOF) {
      keyChar = keyFile.get();
      if (isalpha(keyChar)) {
         cipherArray[count][1] = keyChar;
         count++;
      }
   }
}