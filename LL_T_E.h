/**********************************************************************************************
CS211
Assignment 
LL application
Template written by Kazumi Slott
4/23/2020

Your name: Eric Lozano

Program: This code is meant to create a linked queue object which is done by liking a bunch of nodes together.
****************************************************************************************************/
#ifndef LL_H
#define LL_H

#include "Node.h"
#include<string>
using namespace std;

template<class T>
struct node//struct object node
{
  T elem;//holds a char
  node<T>* next;//gives us address of next node.
};

template <class T>
class LL
{
 private:
  int count;//the number of elements the queue contains.
  node<T>* front;//where the front elment of the queue is.
  node<T>* rear;//where the rear is.
  void printAllReverse(node<T>* p);//prints nodes from top to bottom hence reverse order through recursion.
  //  void queueError(string msg);//displays messgae and terminates code using  exit(1)
  void preintAllReverseDLL();
 public:
  LL();//default constructor
  LL(const LL& l);//copy constructor.
  ~LL();//deconstructor
  void addRear(T el);//adds an item or value to linked list of data type el_t.
  T deleteFront();//deletes current front and returns it.
  bool isEmpty();//shows whether linked list is empty or not.
  void displayAll();//displays everything in linked list.
  void printAllReverse();//print linked list in reverse order. this is just the accessor.
  void addFront(T el);//adds el_t e to front of linked list
  T deleteRear();//adds el_t e to back of linked list
  void deleteNode(T e);//deletes a node from the linked list
  void addInOrderAscend(T e);//adds to linked list in ascending order.
  bool search(T e);//searches for el_t e in list returns true or false.
  class Underflow{};
};

/***************************************************************************************
no parameters.
This function is the default constructor. Assigns all private memebers to default value

****************************************************************************************/
template<class T>
LL<T> :: LL()
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
template <class T>
LL<T> :: ~LL()
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
template <class T>
void LL<T>:: addRear(T el)
{
  node<T>* temp = new node<T>;//new node
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
template<class T>
bool LL<T>:: isEmpty()
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
template<class T>
void LL<T>:: displayAll()
{
  node<T>* temp;//create node
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
This function is deletes the front value stored in linked list and returns its element.
****************************************************************************************/
template <class T>
T LL<T>::deleteFront()
{
  node<T>* temp;//declare a node of temp will hold current front.
  T prev;// will hold previous value.
  if(isEmpty())//if linked list is empty enter condition. 
    {
      throw Underflow();

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

template <class T>
void LL<T>::printAllReverse()
{
  printAllReverse(front);//pass front since the is the node we want access to first.
}

/***************************************************************************************
p is struct object node.
This function prints are linked list in reverse order.
****************************************************************************************/
template <class T>
void LL<T>::printAllReverse(node<T>* p)
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
/*
template<class T>
void LL<T>::queueError(string msg)
{
  //displays message.
  cout<<msg<<endl;
  exit(1);//exit program.
}
*/
/************************************************************
This funciton adds a node to the front of Linked list.
************************************************************/
template<class T>
void LL<T>::addFront(T el)
{
  node<T>* ptr = new node<T>;//create new node for new front.
  ptr->elem = el;//assign element to new node.
  ptr->next = NULL;
  if(isEmpty())
    {
      front = ptr;//front equals new node.
      rear = ptr;//front equals new node.
      count++;//increment linked list.
    }
  else
    {
      ptr->next = front;//have new node point to the address of current front.
      front = ptr;//now point front to new starting front being ptr. 
      count++;//increment list.
    }
}
/*****************************************************************************
Function: This function deletes the right most node. The reassigns a new rear. 
It will return the element of the deleted node.
 ****************************************************************************/
template <class T>
T LL<T>:: deleteRear()//no parameters
{
  node<T>* temp;//declare a node of temp will hold current front.
  T prev;// will store element of deleted  rear.
  if(isEmpty())//if linked list is empty enter condition.
    {
      throw Underflow();
    }
  else if(count == 1)//if there is only one node in list enter if
    {
      temp = rear;//temp equals rear
      front = rear = NULL;//front and rear both point to only node
      prev = temp ->elem;//prev is assinged node temps element
      delete temp;//we then delete temp
      count--;//decrement count
    }
  else
    {
      for(temp = front;temp->next != rear; temp = temp->next)//we transverse to reach the 2nd right most node store it into temp.
	{
	  ;
	}
      prev = rear->elem;// store rear element in prev
      delete rear;//delete rear node
      rear = temp;//rear now points to temp
      rear->next = NULL;//rear next is now null
      count--;//decrement count
    }
  return prev;//return prev
}
/*****************************************************************************************
Function: We create a copy constructor. it will copy the any linked list past to it.

 *****************************************************************************************/
/*LL::LL(const LL& other)//pass linked list to be copied.
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

    }*/
/********************************************************************************************************************
Function: Is meant to delete a node with the given element.
*********************************************************************************************************************/
template <class T>
void LL<T> :: deleteNode(T e)
{
  node<T>* prev;//create a  node to store previous node.
  node<T>* del;//create node to be deleted.

  del = front;// delete equals front.
  
  if(isEmpty())//if its empty enter if
    {
      ;//do nothing
    }
  else if(del->elem == e)//if del node holds the current element enter if
    {
      deleteFront();//call delete front since its the first node in link list.
      rear = NULL;//set rear to NULL now there no longer exist node.
    }
  else// we are deleting a node in the middle.
    {
      for(prev = front, del = front->next; del != NULL && del->elem != e; prev = del, del = del->next)//if del node is NULL element does not exist. If del equals e node does exist either case break out of loop.
	{
	  ;//del is updated to address of desired node with the desired element.
	}
      
      if(del != NULL)// if del is not NULL element exist in list
	{
	  prev->next = del->next;//prev->next is now assigned del's next
	  delete del;//delete del
	  count--;//decrement count
	}
  }
}
/*********************************************************************************************************************
function: This function will add a new node into the linked list. Adding node in ascending order. 

 *********************************************************************************************************************/
template<class T>
void LL<T>::addInOrderAscend(T e)// pass an element of e
{
  node<T>* ptr;//create a node ptr
  node<T>* temp = new node<T>;//create a temp node
  
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
      temp->elem = e;//set e to temp->elem
      temp->next = ptr->next;//point temp address to ptr address.
      ptr->next = temp;//set ptr to pointing to temp.
      count++;//increment count.
    }
}
/***********************************************************************************************************
Function: This function is meant to search element e in the linked list.

 **********************************************************************************************************/
template<class T>
bool LL<T> :: search(T e)//pass el_t e as a parameter.
{
  node<T>* ptr;//create a node ptr 
  ptr = front;//set front to ptr.

  if(isEmpty())//if list is empty enter if
    {
      return false;//return false list is empty
    }

  while(ptr != NULL)//if ptr is not NULL enter if
    {
      if(ptr->elem == e)//if ptr elem successfully compares to e then enter if
	{
	  cout<<count<<" nodes checked."<<endl;
	  return true;//e is in current node so return true.
	}
      ptr = ptr->next;//e did not match current node element so point to new nodes address.
    }
  cout<<count<<" nodes checked."<<endl;
  return false;//else e is not in the linkes list return false.
}

#endif
