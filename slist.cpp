// CS311 Yoshii Complete all functions with their comments

// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: Eric Lozano
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h" 

// ** Make sure llist constructor and destructors have couts in them
// do not change this one

//Purpose: Everytime we create an object we should create a constructor. Slist alreayd inherited 
//the constructor from llist so make this one do nothing.
//Parameters: none.
slist::slist()
{ cout << "slist constructor:" << endl;}


// positions always start at 1
//Purpose: The purpose of this function is to serach for a given element in the list.
//Parameters: We have el_t type of key and key is the element we are looking for in the list.
//Return: return the position of the found element or return 0 for not found.
int slist::search(el_t key)
{
  Node* ptr;//create a node ptr
  ptr = Front;//set front to ptr.
  int pos = 1;//position must start at 1.
  if(isEmpty())//if list is empty enter if
    {
      return 0;//return 0 if list is empty
    }//end of if

  while(ptr != NULL)//if ptr is not NULL enter if
    {
      if(ptr->Elem == key)//if ptr elem successfully compares to key then enter if
        {
          return pos;//key is in the current node so return position.
        }//end of if
      ptr = ptr->Next;//key did not match current node element so point to new nodes address.
      pos++;//increment position by 1.
    }//end of while
  return 0;//else key is not in the link list return 0.
}//end of function

// don't forget to throw OutOfRange for bad pos 
//Purpose: The purpose of this function is to replace the found element from search function.
//Parameters: el_t type element which is the element we are trying to insert after we delete the element found using search.
//int pos is the pos of the element found in search which is the element we want to replace.
void slist::replace(el_t element, int pos)
{
  Node*t;//create local pointer
  t = Front;// set pointer to front of list
  if(isEmpty())//if slist is empty enter if
    {
      throw OutOfRange();//slist is empty so element must no be in list throw OutOfRange exception.
    }//end of if
  
  if(pos <= Count)//if position is less than or equal to our count size we are in range enter if.
    {
      if(pos >= 1)//if pos is not 1 or greater than its a bad position enter if.
	{
	  moveTo(pos + 1, t);//since my move to is J - 2 I had to add 1 to make it j - 1 position. transverse j to moveTo j - 1
	  t->Elem = element;//we have move to desired position so replave t->Elem with the passed element.
	}
      else //position was bad
	{
	  throw OutOfRange();//throw out of range exception.
	}//end of if/else
    }
  else// we position must be greater than count enter else
    {
      throw OutOfRange();//throw out of range exception.
    }
}//end of function

//Purpose: The purpose of this funciton is to teach the compiler how to compare to objects of slist.
//Parameters: we pass operator as the this object and the other one as the object we are comaring with.
// we pass OtherOne as by refrence so we do not copy the object size and we have it const to not alter the object.
//Return: True or false for the comparisons. 
bool slist::operator==(const slist& OtherOne)
{
  // if not the same length, return false
  // if the same lengths,
  //check each node to see if the elements are the same
  Node* p ;// declare local pointer p to hold OtherOne's front
  Node* f;//declare pointer f to hold this's front.
  f = this->Front;//f holds this->front of list
  p = OtherOne.Front;//p holds OtherOne's front.
  
  if(this->Count != OtherOne.Count)//if count sizes are not the same enter if
    {
      return false;//count size's are different so they cannot have the same elements.
    }//end of if

  while(p != NULL && f != NULL)//while p is not null and f is not null we have not reached end of lists enter if
	{
	  if(f->Elem != p->Elem)//if f's element is not equal to p's element enter if.
	    {
	      return false;//element's are different so return false. lists are not the same.
	    }//end of if

	  f = f->Next;//make f point to next node address of this's list
	  p = p->Next;//make p point to next node address of OtherOne's list.
	}//end of while

  return true;//list must be the same after all the checks.
}//end of function
