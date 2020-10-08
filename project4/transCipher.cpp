#include "transCipher.h"

void generateKey(char key[], char cipherArray[26][2]) {
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
   for(int i = 0; i < 26; i++)
      cipherArray[i][1] = static_cast<char>(key[i]);
}