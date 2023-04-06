/**********************************************************************************************
CS211
Assignment 
DLL application
Template written by Kazumi Slott
4/29/2020

Your name: Eric Lozano

Program: This code is meant to create a doubly linked linked list which is done by liking a bunch of nodes together. This link list will allow us to move foward and track back from nodes. 
****************************************************************************************************/
#include <iostream>
#include <cstdlib>
#include "DLL.h"

/***************************************************************************************
no parameters.
This function is the default constructor. Assigns all private memebers to default value

****************************************************************************************/
DLL :: DLL()
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
DLL :: ~DLL()
{
  while(!isEmpty())//if not empty
    {
      deleteFront();//call delete front over and over till its empty
    }
}
/***************************************************************************************
el is a data type of type def el_t.
This function adds a new element to the end of the link list.
****************************************************************************************/

void DLL:: addRear(el_t el)
{
  node* temp = new node;//new node
  temp -> elem = el;//node elem from stuct
  
  if(isEmpty())
    {
      front = temp;//front is pointing to only node 
      temp->prev = NULL;//set temp previous to NULL
      rear = temp;//rear is pointing to only node
      temp->next = NULL;//set rear temp tp NULL
      count++;//increment size
    }
  else
    {
      front->prev = NULL;//set front previous to NULL
      temp->prev = rear;//link temp previous to current rear.
      rear -> next = temp;//points to temp's node address.
      rear = temp;//rear is now new node temp
      temp->next = NULL;//temp is now rear so temp next is NULL.
      count++;//incremnet size
    }
}
/***************************************************************************************
no parameters.
This function is checks whether the linked list is empty or not.
****************************************************************************************/
bool DLL:: isEmpty()
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

void DLL:: displayAll()
{
  node* temp;//create node
  temp = front;//temp node must equal front to chack if there is an lement still remaining
  if(isEmpty())//if linked list is empty enter condition
    {
      cout<<"["<<"empty"<<"]";//cout message.
    }
   while(temp != NULL)//if temp doent not equal NULL then we have a node
    {
      cout<<temp->elem<<" ";//print temp element at current node
      temp = temp -> next;//temp needs to point to next node address
    }
   cout<<endl;
}
/***************************************************************************************
no parameters.
This function deletes the front node stored in linked list and returns its element. It then assigns a new frontfoubd by using next.
****************************************************************************************/
el_t DLL::deleteFront()
{
  node* temp;//declare a node of temp will hold current front.
  el_t p;// will hold previous value.
  if(isEmpty())//if linked list is empty enter condition. 
    {
      queueError("The queue is empty. Cannot delete.");//display message.
    }
  else if(count == 1)//else if count is 1 enter condition.
    {
      temp = front;//current front so we can have access to it later
      front = NULL;//it is the last node so set to NULL
      rear = NULL;//it is last node so set to NULL
      p = temp -> elem;//store current front element to prev to get access to it later.
      delete temp;//delete temporary node since it has served it purpose leave no extra memory behind.
      count --;//reduce linked list size.
    }
  else//we must have more then 1 item in linked list.
    {
      temp = front;//temp is assigned current front so we can have access to it later
      front = front -> next;//front will equal next address 
      p = temp -> elem;//temp equals current front extract element.
      front->prev = NULL;//since its a new front we have re-set prev to NULL

      delete temp;//delete temp is has surved its purpose whic was to give us access to previous front node.
      count --;//subtract 1 from linked list.
    }
  return p;//return element in previous node.
}

/***************************************************************************************
no parameters.
This function will give us access to private memeber function print all reverse.
****************************************************************************************/

void DLL::printAllReverse()
{
  printAllReverse(front);//pass front since the is the node we want access to first.
}

/***************************************************************************************
p is struct object node.
This function prints the linked list in reverse order.
****************************************************************************************/

void DLL::printAllReverse(node* p)
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
void DLL::queueError(string msg)
{
  //displays message.
  cout<<msg<<endl;
  exit(1);//exit program.
}
/********************************************************************************************************
This function adds a new node to the front of the linked list.
*********************************************************************************************************/

void DLL::addFront(el_t el)
{
  node* ptr = new node;//create new node for new front.
  ptr->elem = el;//assign element to new node.
  ptr->next = NULL;//set new node to NULL.
  if(isEmpty())//if its emoty there is nothing in the linked list.
    {
      front = ptr;//front equals new node.
      ptr->prev = NULL;//new node is front so previous should be set to null
      rear = ptr;//front equals new node.
      ptr->next = NULL;//set ptr next to NULL.
      count++;//increment linked list.
    }
  else//there is at least 1 node in the linked list
    {
      ptr->next = front;//have new node point to the address of current front.
      front->prev = ptr;//now point front to new starting front being ptr. 
      front = ptr;//front is now moved to prt.
      front->prev = NULL;//front prev is now set to NULL.
      rear->next = NULL;//rear next is now set to NULL.
      count++;//increment list.
    }
}
/*****************************************************************************
Function: This function deletes the right most node. Then re-assigns a new rear. 
It will return the element of the deleted node.
 ****************************************************************************/
el_t DLL:: deleteRear()//no parameters
{
  node* temp;
  el_t p;// will store element of deleted  rear.
  if(isEmpty())//if linked list is empty enter condition.
    {
      queueError("The queue is empty. Cannot delete.");//display message.
    }
  else if(count == 1)//if there is only one node in list enter if
    {
      temp = rear;//temp equals rear
      front = rear = NULL;//front and rear both point to only node
      p = temp ->elem;//prev is assinged node temps element
      delete temp;//we then delete temp
      count--;//decrement count
    }
  else
    {
      temp = rear->prev;
      p = rear->elem;// store rear element in prev
      delete rear;//delete rear node
      rear = temp;//rear now points to temp
      rear->next = NULL;//rear next is now null
      front->prev = NULL;
      count--;//decrement count
    }
  return p;//return deleted node element.
}
/*****************************************************************************************
Function: We create a copy constructor. it will copy the any linked list past to it.

 *****************************************************************************************/
/*
DLL::DLL(const LL& other)//pass linked list to be copied.
{
  this->front = this->rear = NULL;//set private front and rear to NULL
  this->count = 0;// set private count to 0. 

  node* ptr = new node;//create new node.
  ptr = other.front;//assignt ptr linked list other's front.
  
  while(ptr != NULL)//while ptr does not equal null enter loop
    {
      this->addRear(ptr->elem);//add ptr element to new linked list by using addRear 
      ptr = ptr->next;//point to next address of node.
    }

}
*/


/********************************************************************************************************************
Function: Is meant to delete a node with the given element.
*********************************************************************************************************************/
void DLL :: deleteNode(el_t e)
{
  node* del;//create node to be deleted.

  del = front;// delete equals front.
 
  if(isEmpty())//if its empty enter if
    {
      ;//do nothing
    }
  else if(del->elem == e)//if del node holds the current element enter if
    {
      deleteFront();//call delete front since its the first node in link list.
    }
  else if (rear->elem == e)//if rear elem equals element we are looking for enter if
    {
      while(del->elem != e)//while del element is not equal to the element we are looking for enter loop
	{
	  del = del->next;//del is reassigned to next node address.
	}
      if(del != NULL)//del is not null enter if
	{
	  del->prev->next = NULL;//del is rear then set del prev next to NULL.
	  rear = rear->prev;//rear is now rear prev.
	  delete del;//delete dl
	  count--;//decrement count.
	}
    }
  else// we are deleting a node in the middle.
    {
      while(del != NULL && del->elem != e)//while del is not null or del is not e enter while
	{
	  del = del->next;//del is assigned next node address.
	}
      
      if(del != NULL)// if del is not NULL element exist in list
	{
	  del->prev->next = del->next;//set del previous next node to del next.
	  del->next->prev = del->prev;//set del next previous to del previous.
	  delete del;//delete del
	  count--;//decrement count
	}
    }
}
/*********************************************************************************************************************
function: This function will add a new node into the linked list in ascending order. 

 *********************************************************************************************************************/
void DLL::addInOrderAscend(el_t e)// pass an element of e
{
  node* ptr;//create a node ptr
  node* temp = new node;//create a temp node
  
  ptr = front;//assign ptr to front.

  if(isEmpty())//if list is emmpty enter if
    {
      addFront(e);//call addfront and pass e to it.
    }
  else if(e < ptr->elem)//if element e is less than the adjacent element being ptr->elem enter if.
    {
      addFront(e);//call addfront function and pass e to it.
    }
  else//e greater than current ptr elem enter if
    {
      while(ptr->next != NULL && ptr->next->elem < e)//while ptr element is not NULL and if ptr next element is less then e enter loop  
	{
	  ptr = ptr->next;//set ptr to next node address
	}
      if(ptr == rear)//if ptr is equal to rear then they point ot same node enter if
	{
	  addRear(e);//then we call addrear function.
	}
      else//we are not at the end of the linked list.
	{
	  temp->elem = e;//new node temp is assigned element e.
	  temp->next = ptr->next;//temp points to next node.
	  temp->next->prev = temp;//next node points back to temp.
	  temp->prev = ptr;//temp previous points ptr node.
	  ptr->next = temp;//ptr next point back at temp.
	  count++;//increment count.
	}
    }
}
/***********************************************************************************************************
Function: This function is meant to search for the given element e in the linked list.

 **********************************************************************************************************/
bool DLL :: search(el_t e)//pass el_t e as a parameter.
{
  node* ptr;//create a node ptr 
  ptr = front;//set front to ptr.

  if(isEmpty())//if list is empty enter if
    {
      return false;//return false list is empty
    }

  while(ptr != NULL)//if ptr is not NULL enter if
    {
      if(ptr->elem == e)//if ptr elem successfully compares to e then enter if
	{
	  return true;//e is in current node so return true.
	}
      ptr = ptr->next;//e did not match current node element so point to new nodes address.
    }
  return false;//else e is not in the linkes list return false.
}
/*********************************************************************
This function is meant to print the Doubly lnked list in reverse order.
 ********************************************************************/
void DLL::printAllReverseDLL()
{
  node* current = rear;//we start from rear
  if(isEmpty())//if linked list is empty enter condition
    {
      cout<<"["<<"empty"<<"]";//cout message.
    }

  while(current != NULL)//while current is not null enter while
    {
      cout<<current->elem<<" ";//print current element
      current = current->prev;//assign current previous address.
    }
  cout<<endl;
}
