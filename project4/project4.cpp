#include "transCipher.h"

int main(int argc, char* argv[]) {

   char cipherArray[26][2];
   char key[26];
   char letter = 'A';

   for (int i = 0; i < 26; i++)
      cipherArray[i][0] = letter++;
   generateKey(key, cipherArray);

   for(int i = 0; i < 2; i++) {
      for (int j = 0; j < 26; j++) {
         cout << cipherArray[j][i] << " ";
      }
      cout << endl;
   }
   return 0;
}