#include<iostream>
using namespace std;

// You may not change my code in any manner.  0 pts if you do!!!!!!
// Simply add your code for **

//----------------------------------------
//CS311 HW2P2 Partition
//Name: Eric Lozano
//Compiler: g++
//-----------------------------------------



//Purpose:The purpose of this lab was to learn to use partition. We were meant to pick a pivot point and based off that pivot we would
//seperate them into groups of small and large sections dependent on the pivot.

//Algorithm: Here we pass into partition fucntion a pivot which will always be the first one in our case, an array of int, the start of the array being pos 0
// and the size of the array  - 1. The left variable will have pointer f which points to front of the array, right will hold a rear pointer which points
//at the end of the array and temp will hold a value for us when we swap. While the left is smaller than or equal to position right keep looping.
//This while loop will tell us if we have crossed arrows or positions if so break out. 
//In the second while loop we will continue to loop through the contents of the array until we find something larger than the pivot meaning that element belongs
//in the right side of pivot break out of loop. Update left so it moves postions in the array. The same idea applies to the third while loop except on the right side //we loop till we find something smaller than the pivot if so than it belongs the left break out of loop. Update right by decrementing to move right down.
//As for the if statement, we know if we get here than we found something on the left that belongs on the right and vice versa. So, we say so long as the position of
// left is smaller than or equal to the right position than swap otherwise dont enter if. 
//We only print the statement for actual swaps not swaps in the same position hence, if left is smaller than right position print statement. 
//Increment left position and decrement right position. 


// partitions the array a into smaller than pivot and others.
// f is the beginning of the section to be partitioned
// r is the end of the section to be partitioned
// return the first slot of the Large section
int partition(int pivot, int a[], int f, int r)
{
  int left = f; // pointer from the left
  int right = r; // pointer from the right 
  int temp; //used to hold value for swap
  while (left <= right)
    {
  // loop for finding out of place pairs and swap them
  // ** until the left and right cross
  //    if left OK, move left
      while(a[left] < pivot)//keep entering loop until we find an element that should be on the right side.
	{
	  left++;//increment left position to move foward.
	}//end of while

  //    if right OK, move right
      while(a[right] > pivot)//keep entering loop until we find an element that should be on the left side.
	{
	  right--;//decrement right position to move backward.
	}//end of while

	//    if both are bad, swap
	if(left <= right)//left side position will always be smaller or equal to right side. So, we will always be able to swap if the first two checks are bad.
	  {
	    //swap temp holds array a at left position to use later in swap process.
	    temp = a[left];//let temp equal the element in array a at position left.
	    a[left] = a[right];//let array a at left position equal array a at right position. a[left] holds right element now.
	    a[right] = temp;//array a at right position will now equal element on the left that temp was holding. array right holds array left element now.
	    
	    if(left < right)//if left is less than the right we made a successful swap positions moved.
	      {
		cout<<"swap "<<a[right]<<" and "<<a[left]<<endl;// print which elment swapped with which element.
	      }
	    left++;//increment left now that swap occured.
	    right--;//decrement left now the swap occured.

	  }//end of if statement

    }//end of while
  // return the partition point where

  return left;//return left since all elments wiil be sorted and everything behind left is smaller than pivot making left our pivot point. 

  // those smaller than pivot are before what is returned
  // ** there is a special cases and a regular case

}//end of function

int main()
{
  int x;  // number of elements
  int nums[10];
  cout << "How many elements? (must be less than 10) "; 
  cin >> x;
  cout << "Enter elements one per line.." << endl;
  for (int i = 0; i < x; i++)
    { cin >> nums[i]; }

  // the pivot is always the first element
  cout << "Ok the pivot is " << nums[0] << endl;

  int part = partition(nums[0], nums, 0, x-1);

  cout << "Results..." << endl;
  // display up to the partition without endl
  for (int i = 0; i < part; i++)
    cout << nums[i];

  cout << "|";
  // display from the partition on.. without endl
  for (int i = part; i < x; i++)
    cout << nums[i];

  cout << endl;

}
