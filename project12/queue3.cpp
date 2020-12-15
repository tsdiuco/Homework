/*
Class: CPSC 122-02
Trevor Diuco
GU Username: tdiuco
Submitted By: Trevor Diuco
GU Username: tdiuco
File Name: queue3.cpp
Implementation file for priority queue program
To build: make
To run: ./pqueue had we but world
*/

//Queue using List and composition
#include <iostream>
using namespace std;
#include "queue3.h"

template <typename T>
PQueue<T>::PQueue() : Queue<T>()
{
}

template <typename T>
void PQueue<T>::Enqueue(int pty, T newItem)
{
   if(this->IsEmpty() || (pty < this->head->pty))
   {
      this->PutItemH(newItem);
      this->head->pty = pty;
   }
   else if (pty > this->tail->pty)
   {
      this->PutItemT(newItem);
      this->tail->pty = pty;
   }
   else
   {
      node<T>* nodePre = PtrTo(pty);
      node<T>* newNode = new node<T>;

      newNode->next = nodePre->next;
      nodePre->next = newNode;
      newNode->item = newItem;
      newNode->pty = pty;
   }

}

template <typename T>
void PQueue<T>::Print() const
{
   node<T>* curr = this->head;
   while (curr != NULL) {
      cout << curr->pty;
      cout << " " << curr->item << endl;
      curr = curr->next;
   }
}

template <typename T>
node<T>* PQueue<T>::PtrTo(int pty)
{
   node<T>* curr = this->head;
   while (curr->next != NULL) {
      if (curr->pty == pty)
         return curr;
      if ((curr->pty < pty) && (curr->next->pty > pty))
         return curr;
      curr = curr->next;
   }
   return this->head;
}
