#include "transCipher.h"

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
         pt_ct[i][0] = i;
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