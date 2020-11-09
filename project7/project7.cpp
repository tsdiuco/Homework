/*
Class: CPSC 122-01
Trevor Diuco
GU Username: tdiuco
Submitted By: Trevor Diuco
GU Username: tdiuco
File Name: projet7.cpp
Header file for a linked list with head and tail pointers
To Build: g++ project7Tst.cpp project7.cpp
To Execute: ./a.out
*/

#include "project7.h"

List1::List1() {
   length = 0;
   tail = NULL;
   head = NULL;
}

List1::~List1() {
   delete head;
   delete tail;
}

bool List1::IsEmpty() const {
   return GetLength() == 0;
}

int List1::GetLength() const {
   return length;
}

void List1::PutItemH(const itemType newItem) {
   node* tmp = new node;
   if (IsEmpty()) {
      tmp->next = NULL;
      tail = tmp;
   }
   else
      tmp->next = head;
   tmp->item = newItem;
   head = tmp;
   length++;
}

itemType List1::GetItemH() const {
   if (!IsEmpty())
      return head->item;
   return 1;
}

void List1::DeleteItemH() {
   if (!IsEmpty())
   {
      node* tmp = head;
      if (length > 1)
         head = head->next;
      if (length == 1) {
         head = NULL;
         tail = NULL;
      }
      delete tmp;
      length--;
   }
}

void List1::PutItemT(const itemType newItem) {
   if (IsEmpty()) {
      PutItemH(newItem);
   }
   else {
      node* tmp = new node;
      tmp->item = newItem;
      tmp->next = NULL;
      tail->next = tmp;
      tail = tmp;
      length++;
   }
}

itemType List1::GetItemT() const {
   return tail->item;
}

void List1::DeleteItemT() {
   if (!IsEmpty()) {
      node* tmp = tail;
      tail = PtrTo();
      PtrTo()->next = NULL;
      delete tmp;
   }
}

void List1::Print() const {
   node* tmp = head;
   while (tmp != NULL)
   {
      cout << tmp->item << endl;
      tmp = tmp->next;
   }
   delete tmp;
}

int List1::FindItem(const itemType target) const {
   int count = 0;
   node* tmp = head;
   while (tmp != NULL) {
      if (tmp->item == target)
         count++;
      tmp = tmp->next;
   }
   delete tmp;
   return count;
}

int List1::DeleteItem(const itemType target) {     //To Do
   int deletes = FindItem(target);
   while (deletes != 0) {
      if (target == tail->item) {
         DeleteItemT();
         deletes--;
      }
      else if (target == head->item) {
         DeleteItemH();
         deletes--;
      }
      else {
         node* tmp = head;
         while (tmp->next->item != target)
            tmp = tmp->next;
         tmp->next = tmp->next->next;
         tmp = tmp->next;
         delete tmp;

         deletes--;
      }
   }

   return 0;
}

node* List1::PtrTo() {
   node* tmp = head;
   while (tmp->next->next != NULL) {
      tmp = tmp->next;
   }
   return tmp;
}