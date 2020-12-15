/*
Class: CPSC 122-02
Trevor Diuco
GU Username: tdiuco
Submitted By: Trevor Diuco
GU Username: tdiuco
File Name: queue2.cpp
Header file for a linked list with:
1) The capacity to manipulate the tail
2) The capacity to manipulate the head
3) The capacity to make a copy of a list with a the copy constructor
*/

//Queue using List and composition
#include <iostream>
using namespace std;
#include "queue2.h"

template <typename T>
Queue<T>::Queue() : List<T>()
{
 //constructor inherited queue
}

template <typename T>
void Queue<T>::Enqueue(T newItem)
{
 cout << "Queue" << endl;
 this->PutItemT(newItem);
}

template <typename T>
void Queue<T>::Dequeue()
{
 this->DeleteItemH();
}

template <typename T>
T Queue<T>::Peek()
{
 return this->GetItemH();
}
