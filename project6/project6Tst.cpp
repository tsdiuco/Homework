/*
Class: CPSC 122-02
Trevor Diuco
GU Username: tdiuco
Submitted By: Trevor Diuco
GU Username: Trevor Diuco
File Name: project6Tst.cpp
Description:
To Build: g++ project6Tst.cpp project6.cpp
To Execute: ./a.out
*/

#include <iostream>
using namespace std;

#include "project6.h"


int main()
{
   //Use of a static list
   List lst;
   for (int i = 0; i < 5; i++)
      lst.PutItemH(i);
   lst.Print();

   //Use of a dynamic list
   List* lst1 = new List;
   for (int i = 0; i < 5; i++)
      lst1->PutItemH(10*i);
   lst1->Print();

   delete lst1; //necessary to invoke destructor on dynamic list
   return 0;
}