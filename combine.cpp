#include <iostream>
#include <vector>
using namespace std;

// Must use the algorithm that is in the notes! 

//--------------------------------------------
//CS311 HW2P2 Combine 
//Name: Eric Lozano
//Compiler: g++
//--------------------------------------------


//Purpose: The purpose of this program is to understand mergesort. We are meant to sort as we go. 


//Algorithm: In the combine function we pass 3 vectors A, B and R. R is the only one passed by refrence. We declare 3 seprate counters for each vector.
//We than declare two more variables to store the sizes of Vector A and B. While counter ia is smaller than vector A size and if ib is also less than 
//vector Bsize enter loop. Once larger we know we can't sort the rest since they are all already sorted so they could fall in place. 
//If vector A element at position ia is less than vector B element at position ib then enter if. This means A[ia] elements are smaller so they get pushed into
// R vector first. Then we update ia by 1. On the other hand, if vector B elements are less than vector A elements  enter else. This than means vector B elements
//must get pushed first since they hold the smallest values. Then increment ib by 1. Now, update vector R counter ir by 1 than display message.
//If there are still contents in Vector A or B it means they are already in sorted order so they can just get pushed back into R vector.  

// combine two sorted lists A and B into R
// displays comparison every time it is done
void combine( vector<int> A, vector<int> B, vector<int> &R )
{
  int ia = 0;//counter for vector A
  int ib = 0;//counter for vector B
  int ir = 0;//counter for vector R
  
  int Asize = A.size();//holds size of vector A
  int Bsize = B.size();// holds size of vector B

  while(ia < Asize && ib < Bsize)//this while loop will continue to loop until ia and ib are larger than there coressponding vectors. Once larger we break out. 
    {
      if(A[ia] < B[ib])//if elements in vector A are less than elements in Vector B push them first into R vector. This will help us sort.
	{
	  R.push_back(A[ia]);//we push back vector A at position ia into vector R.
	  ia = ia + 1;//we increment ia to update counter/position by 1 for vector A.
	}
      else//B vector contents are smaller than A vector enter else.
	{
	  R.push_back(B[ib]);//push B vector element at position ib into R vector.
	  ib = ib + 1;//update vector B's counter/position by 1.
	}//end of if/else statement

      ir = ir + 1;//now update counter/position for vector R.
      cout << "comparison" << endl;//display comparison after every check.
    }//end of while

  //  if you still have A elements left, copy them into R
  //else copy the remaining B elements into R.

  //checks if any elements remain in vector A.
  while(ia < Asize)//This while will check if we have reached mas size if not there are remaning elements in vector A enter loop. 
    {
      R.push_back(A[ia++]);//push contents in A vector into R vector than increment A vector position by 1. 
      if(ia == Asize)//if position ia is equal to the size of vector A enter if. Since, we want to display the statement once only at the end.
	{
	  cout<<"The rest of the first one goes down."<<endl;//print statement.
	}
      ir = ir + 1;//increment ir since we pushed into R vector.
    }//end of while

  //checks if any remaning elements are in vector B.
  while(ib < Bsize)//while current position ib is less than the size of vector B continue loop. once large we break out no further contents in vector B.
    {
      R.push_back(B[ib++]);//push back the contents of vector B into vector R than increment positon/counter ib.
      if(ib == Bsize)//we want to print message once so only enter if, once pos ib equal vector B size.
	{
	  cout<<"The rest of the second one goes down."<<endl;//display message.
	}//end of if
      ir = ir + 1;//increment into ir since we pushed into R vector.
    }//end of while.
  // be careful -- R comes in as an empty vector with no slots so you have to use push_back
}//end of function


int main()
{  
  vector<int> L1;
  vector<int> L2;
  vector<int> L3;
  int N;  // how many elements in each of L1 and L2
  int e;  // for each element

  cout << "How many elements in each list?" << endl;
  cin >> N;

  cout << "List1"  << endl;
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L1.push_back(e);} 

  cout << "List2"  << endl; 
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L2.push_back(e);} 
  

  // call combine here to combine L1 and L2 into L3
  //**
  combine(L1, L2, L3);
  cout << "The result is: ";
  for (int i = 0; i < N*2; i++)
    { cout << L3[i]; } cout << endl;

}// end of main
