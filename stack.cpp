//CS311 Yoshii 
//INSTRUCTION:
// Look for astriks to complete the program (do control-S)
// Update the comments using the HOW TO COMMENT file, 
// When done, compile stack.cpp to make sure there are no syntax errors.
// NOTE: functions are called instead of repeating
// the same lines of code.
  
//=========================================================
//HW#: HW1P1 stack
//Your name: Eric Lozano
//Complier:  G++
//File type: stack implementation file stack.cpp
//=========================================================

using namespace std;  
#include <iostream>
#include "stack.h"

//PURPOSE:  Constructor must initialize top to be -1 to begin with.
stack::stack()
{ 
  top = -1; // indicate an empty stack }
}//end of function

//PURPOSE:  Destructor does not have to do anything since this is a static array.
stack::~stack()
{ 
  // nothing 
}//end of function
  
//PURPOSE:  checks top and returns true if empty, false otherwise.
bool stack::isEmpty()
{ 
  if (top == -1)//if top = -1 enter if
    {
      return true; //if top = -1 than stack must be empty. Since top started at - 1.
    }
  else//stack is not empty enter else
    { 
      return false; //returns false since stack is not empty
    }
}//end of function
    
//PURPOSE: checks top and returns true if full, false otherwise.
bool stack::isFull()
{ 
  if (top == MAX-1 )//if stack has reached maxed capacity enter if.
    { 
      return true; //returns true since stack must be full. 
    }
  else//stack is not full and more can be pushed into stack.
    { 
      return false;//return false stack is not full.
    }//end of if/else
 
}//end of function
  
//PURPOSE: calls isFull and if true, throws an exception (Overflow)
//Otherwise, adds an element to el after incrementing top.
//PARAMETER: pass the element (elem) to be pushed 
void stack::push(el_t elem)
{ 
  if (isFull()) //if the stack is full enter if
    {
      throw Overflow();//if we try to push when stack is full than we have an overflow. We throw the overflow to be catched and the error can be dealt with.
    }
  else//the stack is not full yet.
    { 
      top++; //increment the stack by one since the new top variable is now elem. 
      el[top] = elem;//feed the array the new elem.
    }//end of if/else

}//end of function
 
//PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
//  Otherwise, removes an element from el and gives it back.
//PARAMETER: provide a holder (elem) for the element popped (pass by ref)
void stack::pop(el_t& elem)
{ 
  if (isEmpty())//call isEmpty if the stack is empty enter if
    {
      throw Underflow();//throw underflow since we are trying to pop a stack that is empty. The throw method will pass this on to catch in client and deal with it there.
    }
  else//the stack is not empty 
    { 
      elem = el[top]; //we assign the element at the top that is going to be removed to elem.
      top--;// we decrease the stack by 1 since we removed a variable from stack.
    }//end of if\else

}//end of function
 
//PURPOSE: calls isEmpty and if true, throws an exception (underflow)
//Otherwise, gives back the top element from el.
//PARAMETER: provide a holder (elem) for the element (pass by ref)
void stack::topElem(el_t& elem)
{ 
  if (isEmpty())//if the stack is emmpty enter if.
    {
      throw Underflow();//we are trying to peek the top element when there is nothing in stack. Throws underflow to catch to deal with error in client. 
    }
  else //the stack is not empty
    {
      elem = el[top];//elem is assigned the top element in the stack.
    }//end of if\else

}//end of function
 
//PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
// Otherwise, diplays the elements vertically.
void stack::displayAll()
{  
  cout << "STACK:---------" << endl;//border outline to be printed
  if (isEmpty())//if stack is empty enter if
     { 
       cout << "[ empty ]" << endl;//the stack is empty so prints empty.
     }
  else//stack is not empty
     { 
       for (int i = top; i>= 0; i--)//must have loop to go through the array start from top to bottome as it is a stack.
	 { 
	   cout << el[i] << endl; //prints the element at position i in the array.
	 }//end of for loop

     }//end of if\else

  cout << "--------------" << endl;//prints end of border outline.
}//end of function
 
 
//PURPOSE: pops all elements from the stack until 
// it is empty 
void stack::clearIt()
{
  el_t temp;  // comment a local variable here

  // do not do top = -1, use a loop
  while(!isEmpty())//while stack is not empty enter while and keep looping
    {
      pop(temp);//continue to pop from stack and store it in over and over in temp unitl stack is empty.
    }//end of while

}//end of function

