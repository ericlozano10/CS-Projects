//CS311 Yoshii dgraph.cpp 
// INSTRUCTION:
//  Complete all the functions you listed in dgraph.h
//  Comment the file completely using How to Comment file.
//  Use HW6-help.docx to finish the functions.
//-------------------------------------------------------

//======================================================
// HW#: HW6 dgraph
// Name: Eric Lozano
// File Type: dgraph.cpp
//========================================================

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "dgraph.h"
#include <iomanip>

//Purpose: constructor baically sets struct and private values to default values.
dgraph::dgraph() // initialize vertexName (blank) and visit numbers (0)    // initialize countUsed to be 0
{
  for (int i = 0; i < SIZE; i++)//loop max time array size lets you.
    {
      Gtable[i].vertexName = ' ';//set every Gtable (object) vertex name to blank
      Gtable[i].visit = 0;//set every Gtable (object) visit to 0.
    }
  countUsed = 0;//countUsed has no jobs yet.
}

//Purpose: to do nothing. list takes care of the destruction. 
dgraph::~dgraph()   // do we have to delete all nodes of slists in table??
// Question: If we do not do this, will the llist destructor be called automatically??? Try it.
{
  //do nothing should inherit destructor from slist.
}//end of destructor

//Purpose: To read in from a file and store there values according to there row/slots.
//Out degree will have to run out degree times. Since a vertex can have multiple edges coming out.
//Than after reading an edge store it in Gtable slot under asjacent ones using a slist format and add to rear of slist.Increment countUsed.

void dgraph::fillTable()  // be sure to read from a specified file
{
  string fname;//declare a string name fname
  cout << "Enter a file name: ";
  cin >> fname;//ask for file from user
  ifstream fin (fname.c_str(), ios::in); // declare and open fname

  // the rest is in HW6-help
  char x;//reads a charecter from file
  while (fin >> Gtable[countUsed].vertexName)  // IF I CAN READ THE NAME
    { fin >> Gtable[countUsed].outDegree;//read in the amount of outDegree/edges coming out
      //Then for the OutDegree times (for-loop):
      for(int i = 0; i < Gtable[countUsed].outDegree;i++)//loop amount degree times. Since out degree returns an int edges from file
	{
	  fin>>x;//read in char
	  (Gtable[countUsed].adjacentOnes).addRear(x);   // this is a slist function from HW3. If there exist an edge there is vertex across it add to rear.
	}
      countUsed++;//update counter    
    }//end of while loop
  fin.close();//close file


}//end of function.

//Purpose: The purpose of this function is to display the graph in a table chart manner.

void dgraph::displayGraph() // be sure to display
{// in a really nice table format -- all columns but no unused rows and include the number of edges at the top 

  int degree = 0;//stores total edges
  for(int i = 0; i < countUsed;i++)//loop countUsed times
    {
      degree = Gtable[i].outDegree + degree;//Gtable[i].outDegree gives an integer being a degree add that integer to degree nad display the sum.
    }  
  cout<<"total number of edges: "<<degree<<endl;//displays total degree
  
  cout<<"====================================================================="<<endl;//border 1
  for(int i = 0; i < countUsed; i++)//loop count Used times. SInce that is the number of slots used.
    {
      //alignment of chart.
      cout<<"Vname: "<<left<<setw(5)<<Gtable[i].vertexName<<"Degree: "<<right<<Gtable[i].outDegree<<setw(15)<<right<<"Visited: "<<Gtable[i].visit<<right<<setw(10);
      if(!(Gtable[i].adjacentOnes).isEmpty())//Since the adjacent part of Gtable object is an slist we can check if its empty if not enter if.
	{
	  cout<<setw(15)<<"adjacent: "<<setw(5)<<right;//alignment
	  (Gtable[i].adjacentOnes).displayAll();//since Gtable part of adjacent is an slist we can display it directly.
	}
      else//else gtable must be empty no adjacent values.
	{
	  cout<<setw(15)<<"adjacent: "<<right<<setw(11)<<"[Empty]"<<endl;//print empty
	}//end of if and else
      cout<<endl;
      
    }//end of loop
  cout<<"====================================================================="<<endl;//border 2

}//end of funciton.

//Purpose: To find out the number of degree. To do that we have to map characters to their approriate slots.
//In other words, turn characters to integers.
//Param: Is char V which holds the vertex passsed.
//return: we return the gtable row ith from the degree section of the file.
int dgraph::findOutDegree(char V)// throws exception
{// does not use a loop
  int i;//index
  i = V - 'A';// converts char to an into by subtratinc value of 65 which 'A' holds. This basically maps A = 0, B = 1 etc..

  if(i < countUsed && i >= 0)//if the vertex is integer value is less than our number o slots and if int i is greater than or equal to zero enter if means we have 1 job at least.
    {
      return Gtable[i].outDegree;//we must have at least 1 jobe meaning 1 edge exist. Edges tells us the amount of degrees a vertex has. So, return the section in degree' from file.
    }
  else
    {
      throw BadVertex();//otherwise bad vertex throw Bed vertex function.
    }//end of if/else
}//end of funciton

//Purpose: To find the adjacent values of the given vertex. 
//Param: Char v is the vertex passed. Must map char's to slot value of file. We covert them from char to int and use them as an index.
//return: we return the gtable row ith from the adjacent section of the file.
slist dgraph::findAdjacency(char V)// throws exception
{// does not use a loop
  
  int i;//index

  i = V - 'A';// converts char to an into by subtratinc value of 65 which 'A' holds. This basically maps A = 0, B = 1 etc..

  if(i < countUsed && i >= 0)//if the vertex is integer value is less than our number o slots and if int i is greater than or equal to zero enter if means we have 1 job at least.

    {
      return Gtable[i].adjacentOnes;//we must have at least 1 jobe meaning 1 edge exist. Edges tel;s us the amount of degrees a vertex has. So, return adjacent's section.
    }
  else//bad vertex 
    {
      throw BadVertex();//throw exception handeling Bad vertex
    }//end of if/else
}//end of function
