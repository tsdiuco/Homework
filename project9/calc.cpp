/*
Class: CPSC 122-02
Trevor Diuco
GU Username: tdiuco
Submitted By: Trevor Diuco
GU Username: tdiuco
File Name: calc.h
To Execute: ./calc "(A+B)" 27 32
*/

#include <iostream>
using namespace std;

#include "calc.h"
#include <cstring>

Calc::Calc(int argcIn, char* argvIn[])
{
   inFix = new char[strlen(argvIn[1]) + 1];
   strcpy(inFix,argvIn[1]);

   if (!CheckTokens())
   {
      cout << "Failed at CheckTokens()... Exiting\n";
      exit(EXIT_FAILURE);
   }

   values = new int[argcIn-2];
   for (int i = 2; i < argcIn; i++)
      values[i-2] = atoi(argvIn[i]);

   stk = new Stack;

   if (!CheckParens())
   {
      cout << "Failed at CheckParens()... Exiting\n";
      exit(EXIT_FAILURE);
   }
}

Calc::~Calc()
{}

void Calc::DisplayInFix()
{
   cout << inFix << endl;
}

bool Calc::CheckParens()
{
   int pos = 0;
   while (inFix[pos] != '\0')
   {
      if (inFix[pos] == '(')
         stk->Push(inFix[pos]);
      if (inFix[pos] == ')')
      {
         if (stk->IsEmpty())
            return false;
         stk->Pop();
      }
      pos++;
   }
   if (stk->IsEmpty())
      return true;
   return false;
}

bool Calc::CheckTokens()
{
   string str = "()*/+-";
   int count = 0;
   while (inFix[count] != '\0')
   {
      if (isalpha(inFix[count]))
      {
         count++;
         continue;
      }
      for (int i = 0; i < str.length(); i++)
      {
         if (inFix[count] == str.at(i))
            break;
         if (i == (str.length() - 1))
            return false;
      }
      count++;
   }
   return true;
}
