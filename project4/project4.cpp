#include "transCipher.h"

int main(int argc, char* argv[]) {

   if (argc != 2 && argc != 5){
      cout << "Incorrect number of command line arguments...Exiting Program\n";
      exit(EXIT_FAILURE);
   }
   if (argc == 2) {
      ofstream keyFile;
      keyFile.open(argv[1]);

      if (!keyFile.is_open()) {
         cout << "keyFile Failed to Open...Exiting Program\n";
         exit(EXIT_FAILURE);
      }
      generateKey(keyFile);
   }

   char cipherArray[26][2];
   char letter = 'A';

   for (int i = 0; i < 26; i++) {
      cipherArray[i][0] = letter;
      letter++;
      cout <<  cipherArray[i][0] << endl;
   }
   return 0;
}