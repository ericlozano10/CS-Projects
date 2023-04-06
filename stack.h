//CS311 Yoshii 
//INSTRUCTION:
//Stack class header file template based on Notes-1
//You must complete the class function parts and then complete stack.cpp
//EMACS HINT:
//  control-S does searches
//  Tab on each line will indent perfectly for C++

// =======================================================
// HW#: HW1P1 stack
// Your name: Eric Lozano
// Compiler:  g++ 
// File type: headher file stack.h
//=======================================================

//----- Globally setting up the aliases ----------------
#ifndef STACK_H
#define STACK_H
#include<string>
#include<cstdlib>
using namespace std;

const int MAX = 10;   // The MAX number of elements for the stack
                      // MAX is unknown to the client

typedef int el_t;      // the el_t type is int for now
                      // el_t is unknown to the client
//-------------------------------------------------------


class stack
{ 
  
 private: // to be hidden from the client
  
  el_t el[MAX];       // el is  an array of el_t's
  int  top;           // top is index to the top of stack

 public:  // available to the client

  // Add exception handling classes here  
  class Overflow{}; //empty class used as an expression name only
  class Underflow{}; //empty class used as an expression name only
  
  // prototypes to be used by the client
  // Note that no parameter variables are given

  stack();   // constructor to create an object
  ~stack();  // destructor  to destroy an object
  
  // PURPOSE: if not full, enters an element at the top;
  //          otherwise throws an exception - Overflow
  // PARAMETER: pass the element to be pushed
  void push(el_t elem);
  
  // PURPOSE: if not empty, removes and gives back the top element;
  //          otherwise throws an exception - Underflow
  // PARAMETER: provide variable to receive the popped element (by ref)
  void pop(el_t& elem);
  
  // PURPOSE: if not empty, gives the top element without removing it;
  //          otherwise, throws an exception - Underflow
  // PARAMETER: provides variable to receive the top element.(by ref)
  void topElem(el_t& elem);
  
  // Must add good comments for each function - See Notes1B

  //PURPOSE: If its empty than it returns true else if its not empty returns false.
  bool isEmpty();

  //PURPOSE: returns true if stack is full else false.
  bool isFull();

  //PURPOSE: Allows us to see what is in the stack by displaying everything in the stack in a vertical manner.
  void displayAll();

  //PURPOSE: This will allow the user to empty the stack if needed be. 
  void clearIt();
  
};  //end of class function.

#endif
// Note: semicolon is needed at the end of the header file

