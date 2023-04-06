#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

//--------------------------------------
// CS311 File mat.cpp for HW2EC Matrix 
// Your name: **
//--------------------------------------

// the following can be changed and the rest of the code should work
int const R = 3;  // number of rows
int const C = 4;  // number of columns
int const VM = 3; // table entry length

vector<char>  T[R][C];  // 3 rows and 4 columns table for now 

// ------------------ Functions --------------------------------

int convert(char x)
{ 
  ** do a formula to convert a to 0, b to 1, c to 2 etc.
} 

int readTable()
{  int row, col;
   char col_c; 
   ifstream fin ("lines.txt", ios::in);
   // Read in the file into T
   while (fin >> row)
     {
       fin >> col_c; col = convert(col_c);  // to a slot number
       vector<char> v;  // a vector to fill
       char c; // one char from the file

       // ** Fill v with chars from the file (a loop)
       // ** Put  v in T[row][col]
     }//end of while
}

void showVector(vector<char> v)
{ if (v.size() == 0)  // empty entry
    for (int i = 1; i <= VM; i++) cout << "- ";
  else
    // show the content of v separated by blanks
}


void displayTable()
{
  // ** display T nicely labeled with row numbers
  //    by calling showVector
}


int main()
{
  readTable(); 
  displayTable();  
}//the end
