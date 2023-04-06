#include <iostream>
using namespace std;


//--------------------------------------------
// CS311 HW2P1 Binary Search
// Name: Eric Lozano
// Compiler: g++
// --------------------------------------------


//Purpose: This program is meant to do a binary search through the use of recursion.

/*Algorithm: We first start by creating a function call binary Search which accepts the L array with a fixed size of 10.
This function also passes an int variable x which acts as our key it is what we are searching for, first is our 0 position and last is our last slot the 9th position.
The middle variable will act as our checking point. 
We use the middle variable to update our first/last position which is dependent on our key X, is X larger(right side)/smaller(left side)than our middle.
There is a possibility that we might find our x value straight away so if x equals L[middle] return middle position not the value.
On the other hand, we might not find it straight away and need to search a little more. We may need to search the left side of our array while not recheking middle.
So, if x value is less than L[middle] than update our last to middle - 1. 
There is no need to check the right side of array since it greater than middle and middle is greater than the x value so focus on the left side.
The same idea is applied for the next check. We might have to search the right side of our array since the x value might be larger than our middle.
If thats the case update first to middle + 1 no need to check the middle and left side since there values are less than the x value.
Lastly, the x value might be in the very last slot of the array so if first and last are both equal meaning they are pointing to the same slot.
Than, x must either be in that last slot so return that position of the slot or x is not in the array at all.
*/

// x is what we are looking for in L; first and last are slot numbers 
//This returns the slot number in which x was found
//or -1
int binarySearch(int L[], int x, int first, int last) 
{
  int middle;//will hold the middle position 
  int temp;//will hold the the resulting position in the array.
  //** be sure to check for first == last to
  //   end the recursion 

  middle = (first + last) / 2;//middle will always be our checking point using middle we know to either go left or right of the array.
  cout << "comparing against an element in slot " << middle << endl; //will print the current middle we are comparing our key with at the moment. 

  if(x == L[middle])//if our key being x is equal to what is in array L in position middle than we found our x in 1 comparison enter if.
    {
      return middle;//return middle since we ant to return the position.
    }//if ends
  else if(x < L[middle])//if the key we are looking for being x is less than what is in array L[middle] enter if
    {
      last = middle - 1;//there is no need to check anything from middle and to the right of our array 
      //since we know our key is less than those values so update last to middle - 1   
    }//else if ends
  else if(x > L[middle])//if our key x is greater than what is currently in L[middle] enter if
    {
      first = middle + 1;//there is no need to check anything from middle and to the left of our array
      //since we know our key is greater than those values so update last to middle + 1
    }//else/if ends
  
  if(first == last)//if we still have not found our x position it means we have 1 slot left both first and last both point at it. So, enter if.
    {
      if(L[first] == x)//if L[first] is holding the smae value as our key enter if.
	{
	  return first;//they are equal so return the position at first.
	}
      else//the key x must not exist so enter else.
	{
	  return -1;//return -1 means we did not find x in the array,
	}//if/else ends
    }//if closes

  temp = binarySearch(L, x, first, last);//temp holds the position of the array which binary Search gets when x is found. 
  return temp;//return that position.
}//binary search function ends


int main()
{ int A[10];
  int e;  // to look for this

  // fixed elements for A
  A[0] = 1; A[1]= 3; A[2]=5; A[3]= 7; A[4]=9; A[5]=11; A[6]=13;
  A[7] =15; A[8]= 17; A[9]= 19;

  cout << "What do you want to look for? ";
  cin >> e;

  // Call binarySearch here to look for e in A
  int respos = binarySearch(A,e,0,9);

  if (respos == -1) cout << "Element not found" << endl; 
  else cout << "Found it in position " << respos+1 << endl;

}//main ends
