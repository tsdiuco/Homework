/*
Class: CPSC 122-01
Trevor Diuco
GU Username: tdiuco
Submitted By: Trevor Diuco
GU Username: tdiuco
File Name: projet7Tst.cpp
Header file for a linked list with head and tail pointers
To Build: g++ project7Tst.cpp project7.cpp
To Execute: ./a.out
*/

#include "project7.h"

int main() {

   List1 lst;

   for (int i = 0; i < 5; i++)
      lst.PutItemH(i);
   lst.PutItemH(6);
   lst.PutItemH(6);
   lst.Print();
   cout << endl;
   lst.DeleteItem(2);
   lst.DeleteItem(6);
   lst.Print();

   return 0;
}