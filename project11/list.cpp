/*
Class: CPSC 122-02
Trevor Diuco
GU Username: tdiuco
Submitted By: Trevor Diuco
GU Username: tdiuco
File Name: list.cpp
Implementation file for a simple linked list that adds and deletes at the head
Traversals are done recursively
To Build: make
To Execute: ./list
*/

#include <iostream>
using namespace std;

#include "list.h"


//Non-recursive functions. I have written them for you.
List::List()
{
   head = NULL;
}

void List::PutItemH(itemType item)
{
   node* tmp = new node;
   tmp->item = item;
   tmp->next = head;
   head = tmp;
   tmp = NULL;
}

itemType List::GetItemH()
{
   return head->item;
}

void List::DeleteItemH()
{
   node* cur = head;
   head = head->next;
   delete cur;
   cur = NULL;
}


//Write the following functions recursively or in such a way that they use
//recursive functions


int List::GetLength()
{
   int count = 0;
   node* current = head;
   count = GetLength(current, count);
   return count;
}

int List::GetLength(node* cur, int& ct)
{
   if (cur == NULL)
      return 0;
   else
      return 1 + GetLength(cur->next, ct);
}

bool List::IsEmpty()
{
   return GetLength() == 0;
}

void List::Print( )
{
   node* current = head;
   Print(current);
   cout << endl;
}

void List::Print(node* cur)
{
   if (cur == NULL)
      return;
   cout << cur->item << " ";
   Print(cur->next);
}

void List::PrintR( )
{
   node* current = head;
   PrintR(current);
   cout << endl;
}

void List::PrintR(node* cur)
{
   if (cur == NULL)
      return;
   PrintR(cur->next);
   cout << cur->item << " ";
}

void List:: deleteList(node* curr) {
   if (curr == NULL)
      return;
   deleteList(curr->next);
   free(curr);
}

List::~List()
{
   deleteList(head);
}
