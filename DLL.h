/**********************************************************************************************
CS211
Assignment 
LL application
Template written by Kazumi Slott
4/23/2020

Your name: Eric Lozano

Program: This code is meant to creates a doubly linked lsit object. This program also creates a node struct object that will allow us to access certain addresses of nodes through the use pointers.
****************************************************************************************************/
#ifndef DLL_H
#define DLL_H
#include<string>
using namespace std;
typedef int el_t;

struct node//struct object node
{
  el_t elem;//holds a char
  node* next;//gives us address of next node.
  node* prev;
};

class DLL
{
 private:
  int count;//the number of elements the queue contains.
  node* front;//where the front elment of the queue is.
  node* rear;//where the rear is.
  void printAllReverse(node* p);//prints nodes from top to bottom hence reverse order through recursion.
  void queueError(string msg);//displays messgae and terminates code using  exit(1)
 public:
  DLL();//default constructor
  //  DLL(const LL& l);//copy constructor.
  ~DLL();//deconstructor
  void addRear(el_t el);//adds an item or value to linked list of data type el_t.
  el_t deleteFront();//deletes current front and returns it. 
  bool isEmpty();//shows whether linked list is empty or not.
  void displayAll();//displays everything in linked list.
  void printAllReverse();//print linked list in reverse order. this is just the accessor.
  void addFront(el_t el);//adds el_t e to front of linked list
  el_t deleteRear();//adds el_t e to back of linked list
  void deleteNode(el_t e);//deletes a node from the linked list
  void addInOrderAscend(el_t e);//adds to linked list in ascending order.
  bool search(el_t e);//searches for el_t e in list returns true or false. 
  void printAllReverseDLL();//will print doubly linked list in reverse order.

};
#endif
