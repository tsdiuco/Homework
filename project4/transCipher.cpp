#include "transCipher.h"

void generateKey(ofstream& keyFile) {

   char key[26];
   bool validate[26] = {false};
   int value = 0;
   srand(time(0));

   for (int i = 0; i < 25; i++) {
      value = rand() % 26 + 65;
      while(validate[value] == true) {
         value = rand() % 26 + 65;
      }
      validate[value] = false;
      key[i] = value;
   }

   for (int val : key) {
      cout << val << endl;
   }

   keyFile.close();
   exit(EXIT_SUCCESS);
}