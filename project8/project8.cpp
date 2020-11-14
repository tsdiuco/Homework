/*
Class: CPSC 122-02
Trevor Diuco
GU Username: tdiuco
Submitted By: Trevor Diuco
File Name: project8.h
Implementation file for a doubly linked list with dummy notes at head and
tail to make insertion and deletion easier
To Build: g++ project8Tst.cpp project8.cpp
To Execute: ./a.out
*/
#include "project8.h"

template <typename T>
List2<T>::List2()
{
   length = 0;

   //create dummy nodes;
   head = new doubleNode<T>;
   tail = new doubleNode<T>;

   //set values for head dummy node;
   head->prev = NULL;
   head->item = INT_MIN;
   head->next = tail;

   //set values for tail dummy node;
   tail->prev = head;
   tail->item = INT_MAX;
   tail->next = NULL;
}

template <typename T>
List2<T>::List2(List2<T>* lst)
{
   length = 0;

   //create dummy nodes;
   head = new doubleNode<T>;
   tail = new doubleNode<T>;

   //set values for head dummy node;
   head->prev = NULL;
   head->item = INT_MIN;
   head->next = tail;

   //set values for tail dummy node;
   tail->prev = head;
   tail->item = INT_MAX;
   tail->next = NULL;

   int pos = 1;
   doubleNode<T>* start = lst->FindPosition(pos);

   while (pos < lst->length)
   {
      Insert(start->item,pos);
      start = start->next;
      pos++;
   }
}

template <typename T>
List2<T>::~List2()
{
}

template <typename T>
doubleNode<T>* List2<T>::FindPosition(int pos)
{
   doubleNode<T>* cur = head;
   int i = 0;
   while (i < pos - 1)
   {
      cur = cur->next;
      i++;
   }
   return cur;
}

template <typename T>
void List2<T>::Insert(T item, int pos)
{
   //new node goes between these two nodes
   doubleNode<T>* insertPtA = FindPosition(pos);
   doubleNode<T>* insertPtB = insertPtA->next;

   //create new node and set its values
   doubleNode<T>* tmp = new doubleNode<T>;
   tmp->prev = insertPtA;
   tmp->item = item;
   tmp->next = insertPtB;

   //set pointers for the previous and next nodes
   insertPtA->next = tmp;
   insertPtB->prev = tmp;

   length++;
}

template <typename T>
void List2<T>::Delete(int pos)
{
   pos++;
   doubleNode<T>* tmp = head;
   for (int i = 0; i < pos - 1; i++)
      tmp = tmp->next;
   tmp->prev->next = tmp->next;
   tmp->next->prev = tmp->prev;
   length--;
   delete tmp;
}

template <typename T>
int List2<T>::DeleteAll(T item)
{
   int count = 0;
   int location = 0;
   vector<int> locations;

   doubleNode<T>* tmp = head;
   while (location < length-1) {
      if (tmp->item == item)
         locations.push_back(location);
      location++;
      tmp = tmp->next;
   }

   for (int i = 0; i < locations.size(); i++) {
      Delete(locations.at(i) - i);
      count++;
   }

   return count;
}

template <typename T>
void List2<T>::PrintForward()
{
   doubleNode<T>*  cur = head->next;

   int i = 0;
   while (i < length)
   {
      cout << cur->item << endl;
      cur = cur->next;
      i++;
   }
}

template <typename T>
void List2<T>::PrintBackwards()
{
   doubleNode<T>*  cur = tail->prev;

   int i = 0;
   while (i < length)
   {
      cout << cur->item << endl;
      cur = cur->prev;
      i++;
   }
}

template <typename T>
void List2<T>::Sort()
{
   for (int i = 0; i < length; i++) {
      int minLoc = findMinLocation(i);
      int delLoc = minLoc + 1;
      T item = findMinLocItem(minLoc);
      Insert(item, i+1);
      Delete(delLoc);
   }

}

template <typename T>
int List2<T>::findMinLocation(int beg) {
   int cur = beg;
   int minLoc = beg;
   doubleNode<T>* tmp = head->next;
   for (int i = 0; i < cur; i++)
      tmp = tmp->next;
   T min = tmp->item;
   while (cur < length) {
      if (tmp->item < min) {
         min = tmp->item;
         minLoc = cur + 1;
      }
      tmp = tmp->next;
      cur++;
   }

   //delete tmp;
   return minLoc;
}

template <typename T>
T List2<T>::findMinLocItem(int loc) {
   int curr = 0;
   doubleNode<T>* tmp = head;
   while (curr < loc) {
      tmp = tmp->next;
      curr++;
   }
   return tmp->item;
}