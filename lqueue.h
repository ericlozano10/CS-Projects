/**********************************************************************************************
CS211
Assignment 9
LQueue application
Template written by Kazumi Slott
4/6/2020

Your name: Eric Lozano

Program: This code is meant to creates a linked queue object which is done by liking a bunch of nodes together. This program also creates
a node struct object/
****************************************************************************************************/
#ifndef LQUEUE_H
#define LQUEUE_H
#include <iostream>
#include <cstdlib>
using namespace std;
typedef int el_t;


struct node//struct object node
{
  int elem;//holds and integer
  node* next;//gives us address of next node.
};

class LQueue
{
 private:
  int count;//the number of elements the queue contains.
  node* front;//where the front elment of the queue is.
  node* rear;//where the rear is.
  void printAllReverse(node* p);//prints nodes from top to bottom hence reverse order through recursion.
  void queueError(string msg);//displays messgae and terminates code using  exit(1)
 public:
  LQueue();//default constructor
  ~LQueue();//deconstruuctor
  void addRear(el_t el);//adds an item or value to linked list of data type el_t.
  el_t deleteFront();//deletes current front and returns it. 
  bool isEmpty();//shows whether linked list is empty or not.
  void displayAll();//displays everything in linked list.
  void printAllReverse();//print linked list in reverse order. this is just the accessor.
  };
#endif
