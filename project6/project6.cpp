/*
Class: CPSC 122-02
Trevor Diuco
GU Username: tdiuco
Submitted By: Trevor Diuco
GU Username: Trevor Diuco
File Name: project6.cpp
Description:
To Build: g++ project6Tst.cpp project6.cpp
To Execute: ./a.out
*/

#include <iostream>
using namespace std;

#include "project6.h"

List::List()
{
   length = 0;
}

List::~List()
{
   while (!IsEmpty())
      DeleteItemH();
}

bool List::IsEmpty() const
{
   return GetLength() == 0;
}

int List::GetLength() const
{
   return length;
}

void List::PutItemH(const itemType newItem)
{
   node* tmp = new node;
   if (IsEmpty())
      tmp->next = NULL;
   else
      tmp->next = head;
   tmp->item = newItem;
   head = tmp;
   length++;
}

itemType List::GetItemH() const
{
   if (!IsEmpty())
      return head->item;
   return 1;
}

void List::DeleteItemH()
{
   if (!IsEmpty())
   {
      node* tmp = head;
      if (length > 1)
         head = head->next;
      delete tmp;
      if (length == 1)
         head = NULL;
      length--;
   }
}

void List::Print() const
{
   node* tmp = head;
   while (tmp != NULL)
   {
      cout << tmp->item << endl;
      tmp = tmp->next;
   }
   delete tmp;
}

int List::Find(const itemType item) const
{
   int count = 0;
   node* tmp = head;
   while (count < length) {
      if (tmp->item == item)
         return count;
      tmp = tmp->next;
      count++;
   }
   delete tmp;
   return -1;
}

void List::DeleteItem(const int pos)
{
   if (pos == 0)
      DeleteItemH();
   if (pos <= length && pos > 0) {
      node* tmp = head;
      for (int i = 0; i < pos - 1; i++)
         tmp = tmp->next;
      tmp->next = tmp->next->next;
      delete tmp;
      if (pos == length -1)
         tmp->next = NULL;
   }
   length--;
}
