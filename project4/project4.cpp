#include "transCipher.h"

int main(int argc, char* argv[]) {

   if (argc == 2) {
      fstream keyFile;
      fileOpen(keyFile, argv[1], 'w');

      char key[26];
      generateKey(key);
      for (int i = 0; i < 26; i++)
         keyFile << key[i] << endl;
   }

   if (argc == 5) {
      fstream inFile, outFile, keyFile;
      fileOpen(inFile, argv[1], 'r');
      fileOpen(outFile, argv[2], 'w');
      fileOpen(keyFile, argv[3], 'r');

      char pt_ct[26][2];
      char ct_pt[26][2];
      char letter = 'A';
      for (int i = 0; i < 26; i++) {
         pt_ct[i][0] = letter;
         ct_pt[i][0] = letter++;
      }
      readKeyFile(keyFile, pt_ct);
      

      for(int i = 0; i < 2; i++) {
         for (int j = 0; j < 26; j++)
            cout << pt_ct[j][i] << " ";
      cout << endl;
      }
   }
   return 0;
}