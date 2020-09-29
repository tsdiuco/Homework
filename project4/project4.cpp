#include <iostream>
#include <array>

using namespace std;

int main() {
   char transCipher[26][2];
   char letter = 'a';

   for (int i = 0; i < 26; i++) {
      transCipher[i][0] = letter;
      letter++;
      cout << transCipher[i][1] << endl;
   }
   return 0;
}