//INSTRUCTION:
//Look for ** using control-S
//Then, fill in the function body
//When done, compile queue.cpp to make sure it has no syntax errors

//=========================================================
//HW#: HW1P2 queue
//Your name: Eric Lozano
//Complier:  g++
//File type:  Queue Implementation queue.cpp
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"  

// constructor 
//Purpose: Constructor must initialize count to zero for size.
//front to zero and rear to -1 to begin with.
queue::queue()
{  // initialize data members as in the notes 
  count = 0;//count is our size of queue its currently zero.
  front = 0;//front nothing is in front at the moment so front is at zero.
  rear = -1;//rear must start at -1 so once we enter an element rear will be at zero.
}//end of function

//destructor 
//Purpose: Destructor does nothing since the array is static.
queue::~queue()
{ 
  // nothing
}//end of function

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
  if(count == 0)//count is zero queue is empty
    {
      return true;//return true for empty
    }
  else// queue is not empty
    {
      return false;//return false for queue is not empty
    }// end of if/else
}//end of function

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{
  if(count == MAX_SIZE)//if count being are size is equal to our max size queue is full
    {
      return true;//return true for queue full
    }
  else//queue is not full since the count is not equal to max size
    {
      return false;//return false queue is not full.
    }//end of if/else
}//end of function

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
{
  if(isFull())//if queue is full enter if
    {
      throw Overflow();//if we try to add when queue is full throw overflow to be caught in client2 and dealt with.
    }
  else//queue is not full enter else
    {
      rear = (rear + 1)% MAX_SIZE;//when we add a new elment we must move rear to rear plus 1 and in case rear reaches the front wrap around by mod our max size.
      el[rear]= newElem;//EL is our array at position rear insert our new element.
      count++;//we entered a new elem increment size by 1.
    }//end of if/else
}//end of function

// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem)
{
  if(isEmpty())//if queue is empty.
    {
      throw Underflow();//if we try to remove while queue is emoty throw underflow to be caught and dealt with at client2.
    }
  else//queue is not empty enter else
    {
      removedElem = el[front];//removed elem is not holding the front value of the queue. Its passed by refrence so function holds removed elem when called.
      front = (front + 1) % MAX_SIZE;//front must move to a new front so increment by 1 to stay withing the array wrap around by mod and our queue max size.
      count--;//decrement queue size since we removed an elem.
    }//end of if/else
}//end of function

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{
  if(!isEmpty())//if the queue is not empty enter if
    {
      theElem = el[front];//theElem now holds the front element in queue since its pass by ref once function is called it holds the front elem.
    }
  else//queue is empty
    {
      throw Underflow();//queue is empty and we tried to get the front elem throw underflow to be caught in clients and dealt with.
    }//end of if/else
}//end of function

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{
  return count;//returns the size of queue.
}//end of funtion

// PURPOSE: display everything in the queue horizontally
// from front to rear enclosed in [   ]
// if empty, displays [ empty ]
void queue::displayAll()
{  
  int temp = front;// temp variable to not affect original front
  if (isEmpty()) //if queus is empty enter if.
    { 
      cout << "[ empty ]" << endl;//print empty
    }
  else//queue is not empty
    {
      cout << "[";//print bracket
      
      for (int i = 0; i < count; i++)// so long as i is less than our queue size continue to loop.
	{ 
	  cout<<el[temp];//print all the values in queue.
	  temp = (temp + 1) % MAX_SIZE;//everytime temp reahes the maz size to display we wrap around.
	}//end of for loop.

      cout << "]" << endl;// print end of bracket.
    }  //end of if/else
}//end of function

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//calling remove followed by add.
void queue::goToBack()
{          
  el_t temp;// ** comment a local variable
  if(isEmpty())//if queue is empty enter if.
    {
      throw Underflow();//throw underflow if we try to send to back when queue is empty. Client2 will deal with error.
    }
  else if(front == rear)//else if front an rear point to same element we have only one element
    {
      ;//so do nothing since the front is alse the back.
    }
  else//we are not empty and have mre than 1 element in queue enter else
    {
      remove(temp);//call remove it will remove the front now temp holds that element.
      add(temp);//add back to the queue will be added to the rear of queue.
    }//end of if/else
}//end of function.

