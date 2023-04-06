/**********************************************************************************************
CS211
Assignment 9
LQueue application
Template written by Kazumi Slott
4/6/2020

Your name: Eric Lozano

Program: This code is meant to create a linked queue object which is done by liking a bunch of nodes together.
****************************************************************************************************/

#include "lqueue.h"
#include <iostream>
#include <cstdlib>
/***************************************************************************************
no parameters.
This function is the default constructor. Assigns all private memebers to default value

****************************************************************************************/
LQueue :: LQueue()
{
  rear = NULL;//default value
  front = NULL;//default value
  count = 0;//default value.
}

/***************************************************************************************
no parameters.
This function is the deconstructor. If LQueue is not empty it deletes the front value
of the Link list since it is a FIFO system.
****************************************************************************************/
LQueue :: ~LQueue()
{
  while(!isEmpty())//if not empty
    {
      deleteFront();//call delete front over and over till its empty
    }
}
/***************************************************************************************
el is a data type of type def el_t.
This function adds a new el_t data type in this case its an int to Link list.
****************************************************************************************/

void LQueue:: addRear(el_t el)
{
  node* temp = new node;//new node
  temp -> elem = el;//node elem from stuct
  temp -> next = NULL;//node next NULL from struct.
  if(isEmpty())
    {
      front = temp;//front is pointing to only node 
      rear = temp;//rear is pointing to only node
      count++;//increment size
    }
  else
    {
      rear -> next = temp;//points to next node address.
      rear = temp;//since its last node points to NULL
      count++;//incremnet size
    }
}
/***************************************************************************************
no parameters.
This function is checks whether the linked list is empty or not.
****************************************************************************************/
bool LQueue:: isEmpty()
{
  if(front == NULL && rear == NULL)//if front and rear both equal NULL enter if
    {
      return true;//then linkend list must be empty so true.
    }
  return false;//else it is not empty.
}

/***************************************************************************************
no parameters.
This function is displays everything in the linked list.
****************************************************************************************/

void LQueue:: displayAll()
{
  node* temp;//create node
  temp = front;//temp node must equal front to chack if there is an lement still remaining
  if(isEmpty())//if linked list is empty enter condition
    {
      queueError("[empty]");//cout message.
    }
   while(temp != NULL)//if temp doent not equal NULL then we have a node
    {
      cout<<temp->elem;//print temp element at current node
      temp = temp -> next;//temp needs to point to next node address
    }
   //cout<<endl;
}
/***************************************************************************************
no parameters.
This function is deletes the front value stored in linked list and returns its element.
****************************************************************************************/
el_t LQueue::deleteFront()
{
  node* temp;//declare a node of temp will hold current front.
  el_t prev;// will hold previous value.
  if(isEmpty())//if linked list is empty enter condition. 
    {
      queueError("The queue is empty. Cannot delete.");//display message.
    }
  else if(count == 1)//else if count is 1 enter condition.
    {
      temp = front;//current front so we can have access to it later
      front = NULL;//it is the last node so set to NULL
      rear = NULL;//it is last node so set to NULL
      prev  = temp -> elem;//store current front element to prev to get access to it later.
      delete temp;//delete temporary node since it has served it purpose leave no extra memory behind.
      count --;//reduce linked list size.
    }
  else//we must have more then 1 item in linked list.
    {
      temp = front;//current front so we can have access to it later
      front = front -> next;//front will equal next address 
      prev = temp -> elem;//temp equals current front.
      delete temp;//delete temp is has surved its purpose whic was to give us access to previous front node.
      count --;//subtract 1 from linked list.
    }
  return prev;//return element in previous node.
}

/***************************************************************************************
no parameters.
This function will give us access to private memeber function.
****************************************************************************************/

void LQueue::printAllReverse()
{
  printAllReverse(front);//pass front since the is the node we want access to first.
}

/***************************************************************************************
p is struct object node.
This function prints are linked list in reverse order.
****************************************************************************************/

void LQueue::printAllReverse(node* p)
{
  if(p == NULL)//if node p is null enter condition
    {
      return;//there is no element to print

    }
  else//else there exist an element in node p
    {
      printAllReverse(p->next);//get access to the address of next node. once we reach enod nodes.
      cout<<p->elem;//print the elements in the nodes from top to bottom.
    }
}

/***************************************************************************************
msg is a string holds a message.
This function displays a message when called and terminates program with exit 1.
****************************************************************************************/
void LQueue::queueError(string msg)
{
  //displays message.
  cout<<msg<<endl;
  exit(1);//exit program.
}
