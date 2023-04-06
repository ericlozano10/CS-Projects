//CS311 Yoshii Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes

//EMACS HINT:
//  You can copy from a Word document to emacs (contrl-right click)
//  cntr-K cuts and cntr-Y pastes
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Eric Lozano
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

#include<iostream>
#include"llist.h" 
using namespace std;

//Purpose: The purpose of the contructor is to set are starting values to default.
//Parameters: None.
llist::llist()
{
 cout << "... in llist constructor..." << endl; 
 Front = NULL;//Front should point to NULL
 Rear = NULL;//Rear should point to NULL
 Count = 0;//Count should be 0 since nothing is the constructor yet
}//end of constructor

//Purpose: The purpose of the destructor is to release any data the nodes in the link list may have obtaine through the process.
//Parameters:none
llist::~llist()
{
 cout << ".... in llist destructor..." << endl; 
 while(!isEmpty())//while the list is not empty enter statement
   {
     deleteFront(Front->Elem);//deleteFront node and its data/Element  
   }//end of while

}//end of destructor

//PURPOSE: The purpose of this function is to check if the list is empty.
//PARAMETER: none
bool llist::isEmpty() 
{ 
  if(Front == NULL && Rear == NULL && Count == 0)//we must check Front, Rear and Count make sure they are equal to default values if so enter if
    {
      return true;// we entered if so we must be empty return true
    }//end of if statement
  return false;//skipped if we must not be empty return false.
  
} //end of function
// be sure to check all 3 data members


//PURPOSE: This function is meant to display all of the contents in the list.
//PARAMETER: none.
void llist::displayAll() 
{ 
  Node* temp;//create node
  temp = Front;//temp node must equal front our starting point
  if(isEmpty())//if linked list is empty enter condition
    {
      cout<<"["<<"empty"<<"]";//cout empty message.
    }//end of if statement
  while(temp != NULL)//if temp does not equal NULL then we have at least one node
    {
      cout<<"["<<temp->Elem<<"]"<<" ";//print temp element at current node
      temp = temp -> Next;//temp needs to point to next node address
    }//end of while statement

  cout<<endl;//new line

}//end of function
// be sure to display horizontally in [  ] with
// blanks between elements
  
//PURPOSE: The purpose of this function is to add to the rear of the list.
//PARAMETER: el_t data type in out case its of type int.
void llist::addRear(el_t NewNum) 
{ 
  if(isEmpty())// the list is empty to begin with enter if
    {
      Front = new Node;// list is empty must create a new node have front point to new node.
      Rear = Front;//have rear point to front since front point to new node
      Front->Elem = NewNum;//have the front->element assigned NewNum 
      Rear->Next = NULL;//Rear next should be equal to NULL
      Count++;//increment size
    }
  else//else there exist a node already
    {
      Rear->Next = new Node;//have current rear point to new node
      Rear = Rear->Next;//now have rear node point to new node since it will become new rear.
      Rear->Elem = NewNum;//assign element to new rear elem now
      Rear->Next = NULL;//rear next must be set to null
      Count++;//incremnet size
    }//enf of if/else statement

}//end of function
 // comment the 2 cases

//PURPOSE: The purpose of this function is to add to the front o the list.
//PARAMETER: is of el_t type in out case its defined as a data type of int. 
void llist::addFront(el_t NewNum) 
{ 
  if(isEmpty())//if list is empty enter if
    {
      Front = new Node;//list is empty so we have to create a new node and have front point to it.
      Rear = Front;//Rear can point to front since front points to new node.
      Front->Elem = NewNum;//front-> is assigned New Num data passed as param.
      Rear->Next = NULL;//rear next is now set to NULL.
      Count++;//increment linked list.
    }
  else//else there already exist a front node
    {
      Node* newFront = new Node;//create a new node to be new front
      newFront -> Elem = NewNum;//assign the newFront element information
      newFront -> Next = Front;//have new front point to current front do this to not lose access ot rest of list
      Front = newFront;//now since we appended both our nodes we can make newFront front.
      Rear->Next = NULL;//rear must be set to next as it is the end of the list.
      Count++;//increment list.
    }//end of if/else statement

} // comment the 2 cases

//PURPOSE: The purpose of this function is to delete the front node of the list.
//PARAMETER: oldNum passed by refenced of el_t type in our case type int.
//Used to store element od deleted node.
void llist::deleteFront(el_t& OldNum) 
{ 
  if(isEmpty())//if linked list is empty enter condition.
    {
      throw Underflow();//throw Underflow exception
    }
  else if(Count == 1)//else if count is 1 enter condition.
    {
      OldNum  = Front -> Elem;//store current front element to OldNum to store for later use.
      Front = NULL;//deleteing only node in list so set to NULL
      Rear = NULL;//deleting only node in list so set to NULL
      delete Front;//delete front now that the lement has been stored away.
      Count --;//reduce linked list size.
    }
  else//we must have more then 1 item in linked list.
    {
      Node* temp;//create a node
      temp = Front;//have temp point to front
      Front = Front -> Next;//front will equal next address. Points to second node/ new front.
      OldNum = temp -> Elem;//temp element value is set to OldNum.
      delete temp;//delete temp as it point to front.
      Count --;//subtract 1 from linked list.
    }//end of if/elseif/else statement

} // comment the 3 cases

//PURPOSE: The purpose of this function is to delete from the rear of the list.
//PARAMETER: OldNum passed by refrence is used to store the element of delted node.
void llist::deleteRear(el_t& OldNum)
{
  if(isEmpty())//if linked list is empty enter condition.
    {
      throw Underflow();//throw Underflow exception
    }
  else if(Count == 1)//if there is only one node in list enter if
    {
      OldNum = Rear->Elem;//OldNum is assigned element of rear before deletion
      delete Rear;//delete rear
      Front = Rear = NULL;//front and rear must both point to null as no node is left in list.
      Count--;//decrement count
    }
  else//there exist more than one node.
    {
      Node* temp;//creat a node temp
      temp = Front;//temp points to front.

      while(temp->Next != Rear)//while temp->next does not equal Rear enter while
	{
	  temp = temp->Next;//update temp to the next node address
	}//end of while

      OldNum = Rear->Elem;// store rear element in OldNum
      delete Rear;//delete rear node
      Rear = temp;//rear node points to temp since temp is our new Rear
      Rear->Next = NULL;//rear next is now null
      Count--;//decrement count
    }//end of if/elseif/else statement
} // comment the 3 cases


/* harder ones follow */

// Utility Function to move a local pointer to the Jth node

//Purpose: The purpose of this function is to tranverse to 2 position less than the passed position.
//Parameters: int J is the position we are given and Node*& temp is used to tranverse to the position and store it.  
void llist::moveTo(int J, Node*& temp)
{ // moves temp J-2 times to go to the Jth node
  temp = Front;//temp must point for front to as we wan to transverse through whole loop.

  //j-1 because we start at 1 not 0 
  for ( int K = 1; K < J - 1; K++)//continue to loop until K is no longer less than J - 2 
    {
      temp = temp->Next;//temp should point to the address of next node.
    }//end of loop
}//end of funciton


//PURPOSE: The purpose of this function is to delete an element at the passed position.
//PARAMETER: int I is the passed position in the list.
//Passed by refrence OldNum is used to store the element of the deleted position.
void llist::deleteIth(int I, el_t& OldNum) 
{ 
  Node* del;//create node to be deleted.
  Node* second; //holds second node
  
  if(I > Count || I < 1)//if I posiiton is greater than Count or If I position is less than count we are out of range of list enter if.
    {
      throw OutOfRange();//throw Out of range error.
    }
  else if(I == 1)// I must be at the front since list starts at 1
    {
      deleteFront(OldNum);//call delete front since its the first node in link list.
    }
  else if(I == Count)//Else if count and I are the same than we are at the end of the list since count is the size of the whole list.
    {
      deleteRear(OldNum);//call delete rear and pass oldnum to hold value of elemen deleted.
    }
  else// we are deleting a node in the middle.
    {
      moveTo(I, second);//call move to and pass position and prev node to transverse through list.
      if(second != NULL)// if second is not NULL than an element exist in list
        {
	  del = second->Next;//set del to point second next/ the node to be deleted
          second->Next = del->Next;//since we are about to delete a middle node have second next point to del's next. Attach both ends
	  OldNum = del->Elem;//OldNum is assigned element of del
          delete del;//delete del
          Count--;//decrement count
        }//end of if
    }//end of if/else if/else

}//end of function
 // use moveTo to move local pointers. Be sure to comment to which node you are moving them. Do not forget to set OldNum.  

//PURPOSE: The Purpoe of this function is to insert at the passed position.
//PARAMETER: int I is the given position
//el_t newNUm is the number we are trying to store into the new added node.
void llist::insertIth(int I, el_t newNum) 
{ 
  Node* temp = new Node;//create a new node
  Node* second;//create an local second node
  if(I > Count + 1 || I < 1)//if I position in greater than Count || if I less than 1 we are out of range
    {
      throw OutOfRange();//throw out of range error
    }
  else if(I == 1)//else if I is position 1 enter if
    {
      addFront(newNum);//since I is position 1 call addFront pass newNum into function call to store element.
      Count++;//increment size of list by 1
    }
  else if(I == Count + 1)//if I is equal to Count + 1 than enter if 
    {
      addRear(newNum);//call addRear we want to add to the ned of the list pass new num in call function to pass element.
    }
  else//we are adding a new node somewhere in the middle
    {
      moveTo(I, second);//call moveTO function. If pass position I and node second used to transverse and sore that postion.
      if(second != NULL)//if second does not equal NULL
	{
	  temp->Next = second->Next;//set temp->next to point to the next addres second is pointing to.
	  second->Next = temp;//second->next can now point to temp since temp is now connected to the rest of link list.
	  temp->Elem = newNum;//assing new node temp its element data.
	}//end of if
    }//end if/elseif/else stateament.
} //end of function
// use moveTo to move local pointers. Be sure to comment to which node you are moving them.

//PURPOSE: The purpose of this function is to copy the contents of an existing link list to another link list.
//PARAMETER: We passed a constant llist Original and refenced it because we dont want to copy/pass by value  this object but we dont want to alter it.
// We just need access to it.
llist::llist(const llist& Original) 
{ 
  //  this->'s data members need to be initialized here first
  this->Front = NULL; this->Rear = NULL; this->Count = 0;
  // this-> object has to be built up by allocating new cells with OtherOne elements (**)
  Node* P;  // local pointer for Original
  P = Original.Front; //have P point to the front of the list we are trying to copy from.
  while (P != NULL)  // a loop which repeats until you reach the end of Original. 
    {
      this->addRear(P->Elem);    //P’s element is added to this->
      P = P->Next;   // Go to the next node in Original   
    } //end of while

}//end of funciton
//  Nothing to return because this is a constructor.
// use my code

//PURPOSE: The purpose of this function is to teach the program how to assign the values of one link list to another.
//PARAMETER: We pass a constant link list object called otherOne passed by refrence we dont wan to copy the whole object
//by passing it by value so refrence and we dont want to alter it so const. We also pass a this->object.
llist& llist::operator=(const llist& OtherOne) 
{ 
  el_t x;
  // First make sure this-> and OtherOne are not the same object.
  // To do this, compare the pointers to the objects .
  if (&OtherOne != this)  // if not the same
    {
      // this-> object has to be emptied first.
      while (! this->isEmpty() )//while this object is not empty loop
	this->deleteRear(x);  //delete from rear from this object.

      // this-> object has to be built up by allocating new cells with OtherOne elements (**)
      Node* P;  // local pointer for OtherOne
      P = OtherOne.Front;// P points to the otherOne's front 
      while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
        {
	  this->addRear(P->Elem);    //P’s element is added to this->
	  P = P->Next;                         // Go to the next node in OtherOne   
	} 
    }// end of if              
  return *this;    // return the result unconditionally.  Note that the result is returned by reference.

} // use my code
//end of function

