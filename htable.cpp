// CS311 Yoshii - Hash Table - complete all ** parts.
// Note: this class does not know the parts of element except for key
// so that it would work even if each element in the hash table changed
//-----------------------------------------------------

// ============================================
// HW#: HW8 Hash Table
// Name: Eric Lozano
// File Type: implementation htable.cpp
// =============================================


#include <iostream>
#include "htable.h"
#include "elem.h"

using namespace std;


//Purpose: to set private values to default. In this case does nothing.
htable::htable()
{
  //do nothing
}//end of constructot


//Purpose: to destroy hash table.
htable::~htable()
{
  //do nothing
}//end of destructor

// Purpose: a simple hash function that uses % TSIZE simply.
//Param: int ket will hold the key valuse passed in client.
//Returns: slot number
int htable::hash(int key)
{
  return key % TSIZE;//turns key into a slot number in range of tsize and returns that slot number.
}//end function

// Purpose: adds the element to the table and returns slots
//Param: el_t object element. 
//returns: slot number
int htable::add(el_t element )
{
  int slot = hash(element.getkey());  // hash with the key part. holds slot for table array.
  // ** Note that this means adding the element to a slist in the slot (addRear)
  table[slot].addRear(element);//add element object to slist table in that slot position.

  return slot;//we should return slot position of where we added the element in.
}//end of function

// Purpose: finds element using the skey and returns the found element itself
// or a blank element  -- there is no cout in here
//Param: integer skey. Skey is slist's key.
//returns: element found or blank element object.

el_t htable::find(int skey)
{ 
  el_t elem;//create el_t elem object
  int slot = hash(skey); // hash with skey
  el_t selement;  // this is the element to look for in slist
  // initialize selement with just the skey
  selement.setkey(skey);//call setkey object and pass skey to it.
  // call slist's search2 with selement which returns the found element 
  elem = table[slot].search2(selement);//search 2 should return the found element. Stores it into el_t elem object
  // return the found element from here (it could be blank)
  return elem;//return object.
}//end of function

// Purpose: displays the entire table with slot#s too.
//Param: nothing.
//return: nothing.
void htable::displayTable()
{
  for (int i = 0; i < 37; i++)//loops 37 times
    { cout << i << ":" ;   //cout i
      table[i].displayAll();// call slist's displayAll contents in table[i[
    }//end of for
}//end of functiion.
