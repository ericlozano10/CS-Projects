// CS311 Yoshii - HW5 Priority Queue Implementation File
// Complete all ** parts and give good comments
// ** Do not delete my comments.

// =================================================
// HW5 Priority Printer Queue 
// YOUR NAME: Eric Lozano
// File Type: implementation pqueue.cpp
// =================================================

#include "pqueue.h"

// constructor
pqueue::pqueue()
{  
  count = 0;  // no jobs yet
}

// destructor does nothing
pqueue::~pqueue() {}

// Purpose: to add a job to a right place in the Pqueue
// Argument: j is the job priority number
// Remember that the current last job is in slot count-1.
void pqueue::insertjob(int j)
{
  cout << "Adding: " << j << endl;
  // ** add the job j at the rear (and update count)

  if(count >= 0 && count < MAX)//if count is greater than or equal to zero and less than max enter if.
    {
      count++;//we have to incrememnt countt by 1 to enter the 1st job.
      Q[count - 1] = j;//insert new job at the end of array.
    }
  else//else out of range.
    {
      // **   if possible else display error message. 
      cerr<<"..cannot add..Full!"<<endl;//error message
    }
  trickleup(); // moves the job to the right place
}//end of function

// Purpose: to print a job and reheapify the Pqueue
void pqueue::printjob()
{
  cout << "Printing: " << Q[0] <<endl;//prints root
  reheapify();//calls reheapify
}//end of function

// Purpose: to display all jobs
void pqueue::displayAll()
{
  cout << "Jobs: " ;
 
  if(count >= 0 && count <= MAX)//if count is greater than or eqaul to count and less than or equal to Max enter if.
    {
      // ** loop to display jobs from slot 0 to slot count-1 horizontally. No need to show a tree format.
      for(int i = 0; i <= count - 1; i++)//keep looping until i is count - 1
	{
	  cout<<Q[i]<<" ";//display evey index value in Queue
	}//end of loop
    }//end of if
  cout<<endl;

} //end of function


// Utility functions follow: ------------------
//Purpose: The purpose of this funciton is to swap the values between the two given locations when called.
//Parameters: loc1 holds position of the 1st passed value and loc2 holds the position on the 2nd passed value.
void pqueue::swap(int loc1, int loc2)
{
  int temp;//temp holds loc1/positon for swapping process
  // ** swap the values in these locations in Q
  if(count >= 0 && count < MAX)//if count is greater then or equal to zero and count is less than MAX. enter if
    {
      temp = Q[loc1];//temp holds value of loc1 in array Q.
      Q[loc1] = Q[loc2];//Array Q at index loc1 is now holding Array Q loc2's value.
      Q[loc2] = temp;//Array Q at index loc2 is now holding temp's value.
    }//end of if
}//end of function

// Purpose: to make the very last job trickle up to the right location. Never do X--. 
void pqueue::trickleup()
{ 
  int x = count-1;  // the very last job's location
  // ** While x is > 0   

  while(x > 0)//Continue to loop so long as x is larger then zero. meaning we still have values in the tree. 
    {
  //    compare Q[x] with the parent (*)
      int P = getParent(x); // (*) Call getParent to get the location of the parent
  // based on the child's location.

      if(Q[x] < Q[P])//if the last job's value being Q[x] is less than the value of the parent being in Q[P] enter if.
	{

  //    and if the parent is bigger swap & update x 
  //    to be the parent . Otherwise stop the loop.
	  swap(P, x);//value of x the last job in array is smaller than parent swap values.
	  x = P;//since x's original value moved to parents old position must update to x's new positon 
	}
      else//the Parent is smaller than child so stop the loop.
	{
	  x = -1; //stop the loop
	}//end of if/else
    }//end of while
}//end of function

// Purpose: find the location of the parent 
// The child location is given.  Need to call even.
//Param: childs location.
//Returns: parents position in the array.
int pqueue::getParent(int childloc)
{  // ** return the parent location based on the child loc
  int par;// par will be the resulted value of the equation.

  if(even(childloc) == true)//if child location/position is an even number enter if 
    {
      par = (childloc - 2)/ 2;//By using this formula we get the parents position. If you think about it in a pre-order fashion. right child will always be 2 away.
    }
  else//else odd location number
    {
      par = (childloc - 1)/ 2;//By using this formula we get the parents position. If you think about it in a pre-order fashion. left child will always be 1 away.
    }
  return par;//return the parents position.
}//end of function

// Purpose: is location i even? (0 is even and 1 is odd)
//Important in finding its parent location
//This funtion checks whether the passed integer is even or odd.
//Returns: True if even and false if odd.
bool pqueue::even(int i)
{
  if ((i % 2) ==  0) return true; else return false; //if i has remainder of zero than even. else false
}//end of funciton


// Purpose: to reheapify the Pqueue after printing
//  This trickles down.  Never do X++.
void pqueue::reheapify()
{ int X;   // the current location
  Q[0] = Q[count-1];  // move the last job to the front
  count--;//decrement count since we will be shuffling elements around and we are moving last job/right most leaf to replace current root.
  // ** Start X at 0 (the root)
  X = 0;//root
  //    while X is within the array:
  while(X <= count - 1)//while X position is less than or equal to count - 1 our array size enter if.
    {
  //       Find the location of the smaller child
      int s = getSmallerchild(X);// s is the position of smallest child
      //         (if the location of both children are off the tree, stop the loop).
      //       If the smaller child is smaller than the parent,
      //          swap and X becomes the smaller child's location.
      if(s < count )//if location of the smaller child is off the tree than its safe to assume the larger one is off too.
	{
	  if(Q[X] > Q[s])//Q[X] our root value is gretaer than the child's values Q[s] enter if.
	    {
	      swap(X, s);//Swap values of the root and child.
	      X = s;//position of X is now s's is position in the array. As their values were swapped so X must point/follow to original value. 
	    }
	  else//roots value was smaller than its smallest child.
	    {
	      X = count + 1;//update count to 1 more then max array size. This will stop the loop.
	    }//end of if/else
	}
      //       else no swaps so stop to loop.
      else
	{
	  X = count + 1;//stops loop
	}//end of if/else
    }//end of while
}//end of function.

// Purpose: to find the location of the smaller child
// where children are at locations 2*i+1 and 2*i+2
//Parameters: integer i holds a position in the array.
//Returns: The location of the smallest child.
int pqueue::getSmallerchild(int i)
{
  int leftchild = (2 * i) + 1;//finds the laft child
  int rightchild = (2 * i) + 2;//finds right child.

// ** return the location of the smaller child 
//    Be careful because one or both of them may be
//    beyond count-1.  Check boundaries before you 
//    compare Q contents!!!!
  if(leftchild <= count - 1 && rightchild <= count - 1)//if we have thwo childrend check if they are within bounds if so enter if.
    {
      if(Q[leftchild] < Q[rightchild])//compare values of both left nd right child. If left child is smaller enter if.
	{
	  return leftchild;//return position of left child.
	}
      else//else right child was smaller.
	{
	  return rightchild;//reutnr position of right child.
	}//end of if/else
    }
  else if (leftchild <= count - 1 && rightchild > count - 1)//else if left child is wthing boundaries and not the right child enter if.
    {
      return leftchild;//return left child thats the only one in bound forget about right child.
    }
  else//else right child must be in bounds and left child is out of bounds.
    {
      return rightchild;//return position of right child.
    }//end if/elseif/else
}//end of fucntion


