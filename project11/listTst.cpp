/*
Class: CPSC 122-02
Trevor Diuco
GU Username: tdiuco
Submitted By: Trevor Diuco
GU Username: tdiuco
File Name: listTst.cpp
Test file for a simple linked list that adds and deletes at the head
Traversals are done recursively
To Build: make
To Execute: ./list
*/

#include <iostream>
using namespace std;

#include "list.h"


int main()
{
   List* lst1 = new List;
   for (int i = 0; i < 5; i++)
   lst1->PutItemH(i);
   lst1->Print();
   lst1->PrintR();

   cout << "Length: " << lst1->GetLength() << endl;

   delete lst1;
   return 0;
}
