#include "transCipher.h"

int main(int argc, char* argv[]) {

   if (argc == 2) {
      fstream keyFile;
      fileOpen(keyFile, argv[1], 'w');
      char key[26];
      generateKey(key);
      for (int i = 0; i < 26; i++) {
         keyFile << key[i] << endl;
      }
   }
   if (argc == 5) {
      fstream inFile, outFile, keyFile;

      fileOpen(inFile, argv[1], 'r');
      fileOpen(outFile, argv[2], 'w');
      fileOpen(keyFile, argv[3], 'r');

      char cipherArray[26][2];
      char letter = 'A';
      for (int i = 0; i < 26; i++)
         cipherArray[i][0] = letter++;

      readKeyFile(keyFile, cipherArray);

      for(int i = 0; i < 2; i++) {
         for (int j = 0; j < 26; j++)
            cout << cipherArray[j][i] << " ";
      cout << endl;
      }
   }

   // for(int i = 0; i < 2; i++) {
   //    for (int j = 0; j < 26; j++)
   //       cout << cipherArray[j][i] << " ";
   //    cout << endl;
   // }
   return 0;
}