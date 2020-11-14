/*
Class: CPSC 122-02
Trevor Diuco
GU Username: tdiuco
Submitted By: Trevor Diuco
File Name: project8.h
Test file for a doubly linked list with dummy notes at head and
tail to make insertion and deletion easier
To Build: g++ project8Tst.cpp project8.cpp
To Execute: ./a.out
*/
#include "project8.cpp"


int main()
{
   List2<int>* lst = new List2<int>;

   srand(time(0));

   for (int i = 1; i <= 10; i++)
      lst->Insert(rand() % 100,i);

   lst->PrintForward();
   lst->Sort();

   cout << endl;
   List2<int>* lst1 = new List2<int>(lst);

   lst->PrintForward();

   return 0;
}