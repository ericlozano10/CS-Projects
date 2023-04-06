// Project Client using a generic hash table
// Loading the data file has to happen here because
// generic htable should not know about the file
// format.
// Change everywhere it says **
// Must write / change @@ functions in htable.
// Must improve the user interface!


#include <string>
#include <iostream>
#include <fstream>
#include "htable.h"
#include "elem.h"

using namespace std;

// ** Purpose of your program here
//Purpose: The Purpose of the program was to 1st create an htable and than be able to implement that same htable. In my case I implemented soccer tema line up.

/*Algorithm: We first create an htable object in our case we called it T. We than locally declare all the elements object T will use.
We than create a string called fname which will accept the fi;e name typed by the user. We open that file if it exist. We than declare the
output file called newout.txt all are infor from out input file and updated input file will be displayed in newout.txt. we than delcare an int called
ans so long as ans does not equal 7 the exit command we will enter the while loop. We create the menu for the user and display it to the terminal.
The switch statement will go to whatever number ans is holding for example ans = 1 we go to case 1. We break out of switch once ans is a valid input. 
In case 1, when we load in the file information we loop through the inputfile so long as there is something to read. After every iteration the el_t constructor is being set with the info needed. We than add it to the htable T object. in case 2 we just display file input to terminal by calling T.displayTable(cout); 
In case 3 we ask the user for the key and name we are looking for we call find to look for the specific object in list. 
If not found say so , if found display the object. In case 4, we are adding a new object of el_t type so ask for all the info el_t constructor uses. 
Once filled we add the el_t object into the htable T object. and display to slot were it got added for the user. In case 5, we are deleting the object we are looking 
for. We need to ask the user the key/kit number of the player and the players name that we want to delete(I think its because we did our hash function this way).
We than pass the el_t object with that info into the htabble deleteIt function. We than delete it if found if now an exception is thrown form llist file and
aborts the program. In case 6, we save the file info into newout.txt and we display the info to the terminal so the user can see what they just saved without exiting
the menu. In case 7, we just display no action adn break out of switch and loop. We finally close the input file and the output file.

 */

int main()
{
  htable T;  // generic hash table

  // All declarations happen outside switch
  int kit;    // ** change
  string name;// ** change and add more
  string position;
  double paid;
  int age;
  el_t E;     // blank element
  
  // File info declared outside switch
  string fname;
  cout << "What is the input file?";
  cin >> fname;
  ifstream fin (fname.c_str(), ios::in);
  ofstream fout ("newout.txt", ios::out);


  int ans = 0;
  while (ans != 7)
    {
      // *** change menu items to be descriptive
      cout << "MENU------------------ :"<<endl;
      cout << "1. Load data from a file" << endl;
      cout << "2. Display the table" << endl;
      cout << "3. Search using a key" << endl;
      cout << "4. Add a new entry" << endl;
      cout << "5. Delete an entry" << endl;
      cout << "6. Save data to a file" << endl;
      cout << "7. Exit" << endl;
      cout << "==>";
      cin >> ans;

      switch (ans)
	{

	case 1: // ** change element parts to yours
	  while(fin >> kit)
	    { 
	      fin >> name;
	      fin>> position;
	      fin>>age;
	      fin>>paid;
	      T.add(el_t (kit, name, position, age, paid));
	 
	    } 
	  cout << "loaded data..." << endl; 
	  break;

	case 2:
	  T.displayTable(cout); //@@
          break;
	  
	case 3: // ** change key to yours
	  cout << "Enter key to look for: ";
	  cin >> kit; 
	  cout<<"Enter a name to look for: ";
	  cin>>name;
	  
	  E = T.find(kit, name);
	  if (E == el_t()) /// blank
	    cout << "Not found" << endl;
          else cout << "Found " << E << endl;
	  break;

	case 4: // ** change element parts to yours
          cout << "Enter a key: "; cin >> kit;
	  cout << "Enter a name: "; cin >> name;
	  cout << "Enter a position: "; cin>> position; 
	  cout << "Enter  age: "; cin>> age;
	  cout << "Enter payment: "; cin>> paid;

	  cout << "In Slot: " << T.add(el_t(kit, name, position, age, paid));
          cout << "  added." << endl;
	  break;
       
	case 5: // ** change key to yours
          cout << "Enter a key: "; cin >> kit;
	  cout << "Enter a name: "; cin >> name;

	  cout << "In Slot: " << T.deleteIt(el_t(kit,name, position, age, paid)); //@@
          cout << "  deleted." << endl;
          // ** what happens if the item was not found?//it throws an out of range exception. then stops the program
	  break;
        
	case 6:
	  T.displayTable(cout);
	  T.displayTable(fout);
	  cout << "Sent data to newout" << endl; 
	  break;

        default:
	  cout << "No action" << endl;
	  break;
	}
    }// end of loop
  fin.close();
  fout.close();
}

