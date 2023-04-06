// CS311 : This is the BST implementation file template by Rika Yoshii

// Each node has an Up link to make it easy to go up the tree.  It must be set as nodes are inserted.  Some deletion
// cases require Up link to be updated.  Couts are there to test to make sure
// you set the Up links correctly!!!! (Fall 19)
//
// INSTRUCTIONS:
// Look for ** comments to complete this file for HW4
// Try not to delete the ** comments, but add the code next to them
// Make sure all { } match. Doing Tab on each line helps.
// Draw pictures as you complete each **

// =========================================================
//HW#: HW4 BST
//Your name: Eric Lozano
//Complier:  g++
//File type: implementation file binstree.cpp
//================================================================

using namespace std;
#include <iostream>
#include "binstree.h"

// constructor  initializes Root
BST::BST()
{
  Root = NULL;   // This is an empty tree
}//end of constructor

// destructor must completely destroy the tree
BST::~BST()
{
  dtraverse(Root); // traverse to delete all vertices in post order
  Root = NULL;    //set root to null
}//end of destructor

// PURPOSE: Does Post Order traversal of the tree and deletes each vertex
// PARAM:   V is a pointer to the vertex to be deleted
void BST::dtraverse(Vertex *V)  // recursive post order traversal
{   
  if (V != NULL) //if V is not Null we have nodes left to go through enter if
    {
      dtraverse(V->Left);         // destroy left sub tree of V
      dtraverse(V->Right);       //  destroy right sub tree of V
      delete V;                  //  delete V
    }//end of if
}//end of function

// PURPOSE: Show vertices in IN order traversal from the Root
void BST::Display()
{
  cout << "Elements in the IN order: " << endl;
  INorderTraversal(Root);  // start in-order traversal from the root
}//end of function

// PURPOSE: Does IN order traversal from V recursively
// PARAM: V is te pointer to the vertex to visit right now
// For non EC, the height and balance will always be 0 
void BST::INorderTraversal(Vertex *V)
{
  if (V != NULL)//if V is not null there are still some remaining nodes to go through in the tree.
    {
      INorderTraversal(V->Left);   // ** traverse left sub-tree of V recursively
      cout<<"Elem: "<<V->Elem<<" Height: "<<V->Height<<" Balance: "<<V->Balance<<endl;// ** display V's element, height and balance and do endl;
      INorderTraversal(V->Right);   // ** traverse right sub-tree of V recursively
    }//end of if
}//end of function

// PURPOSE: Searches for an element in PRE-order traversal
// This is the same as Depth First Traversal
bool BST::Search(el_t K)
{
  PREorderSearch(Root, K);  // start pre-order traversal from the root
}
// PURPOSE: Does PRE order search from V recursively
// PARAM: V is the pointer to the vertex to be visited now
//        K is what we are looking for
bool BST::PREorderSearch(Vertex *V, el_t K)
{
  if (V != NULL)//if V is not null there are still some remaining nodes to go through in the tree.
      {
        if (K == V->Elem) return true; // found the element in V
        else if (K < Root->Elem ) //if root element is greter than what we are looking for traverse left.
	  //** traverse left sub-tree of V recursively
	  PREorderSearch(V->Left, K);//update V to go left and pass what we are looking for K
	else 
	  //** traverse right sub-tree of V recursively
	  PREorderSearch(V->Right, K);//update V to go right and pass what we are looking for K
      }
  else return false;//other wise return false did not find K
}

// ------ The following are for adding and deleting vertices -----


// PURPOSE: Adds a vertex to the binary search tree for a new element 
// PARAM: the new element E
// ALGORITHM: We will do this iteratively (not recursively)
// to demonstrate the algorithm that is in the notes
//    - smaller than the current -> go to the left
//    - bigger than the current  -> go to the right
//    - cannot go any further    -> add it there
void BST::InsertVertex(el_t E)
{
  // Set up a new vertex first
   Vertex *N;         // N will point to the new vertex to be inserted
   N = new Vertex;    // a new vertex is created
   N->Left  = NULL;   // make sure it does not
   N->Right = NULL;   // point to anything
   N->Elem  = E;      // put element E in it
   N->Height = 0;
   N->Balance = 0;
   N->Up = NULL;      // no parent for now
   cout << "Trying to insert " << E << endl;
   if (Root == NULL)  // Special case: we have a brand new empty tree
     {
       Root = N;      // the new vertex is added as the root
       cout << "...adding " << E << " as the root" << endl; 
     }// end of the special case
   else  // the tree is not empty
     {
       Vertex *V;       // V will point to the current vertex
       Vertex *Parent;  // Parent will always point to V's parent

       V = Root;        // start with the root as V
       Parent = NULL;   // above V so it does not point to anything  
       
       // go down the tree until you cannot go any further        
       while (V != NULL)//While V is not Null we can still go down the tree.
	 {
	   if (N->Elem == V->Elem) // the element already exists
	     {	 cout << "...error: the element already exists" << endl;
	       return;  }
	   else
	     if (N->Elem < V->Elem)  // what I have is smaller than V
	       {  cout << "...going to the left" << endl; 
		 // ** change Parent to be V to go down 
		 Parent = V;//parent goes to where V is.
		 // ** change V to be V's Left 
		 V = V->Left;// V goes down to Parent's left child
	       }
	     else // what I have is bigger than V
	       {  cout << "...going to the right" << endl;
		  // ** change Parent to be V to go down
		 Parent = V;//Parent moves to V
		 // ** change V to be V's Right
		 V = V->Right;//V goes down to Parent's right child.
	       }//end of if else
	 }//end of while
       
       // reached NULL -- Must add N as the Parent's child
       if (N->Elem < Parent->Elem)  //if what I have is less than Parent go left enter if
	 {  
	   // ** Parent's Left should point to the same place as N
	   cout << "...adding " << E << " as the left child of " 
		<< Parent->Elem << endl;
	   Parent->Left = N;//so Parent's Left pointer hand should point to New vertex N.
	   // ** N must point UP to the Parent 
	   N->Up = Parent;//parents child should point up to parent.
	   cout << N->Elem  << " now points UP to " << N->Up->Elem << endl;   
	   // *** EC call here to adjust height and BF	}
	 }
       else //else what iva is greater than what parent has
	  {
	    // ** Parent's Right should point to the same place as N 
	    cout << "...adding " << E << " as the right child of " 
                  << Parent->Elem << endl;
	    Parent->Right = N;//Parent;s right hand should point ot New node/vertex N.
	    // ** N must point UP to the Parent 
	    N->Up = Parent;//N should point up to parent.
	    cout << N->Elem << " now points UP to " << N->Up->Elem << endl;   
	    // *** EC call here to adjust height and BF
	  }//end of if else
       
     }// end of normal case
   
}// end of InsertVertex


// PURPOSE: Deletes a vertex that has E as its element.
// PARAM: element E to be removed
// ALGORITHM: First we must find the vertex then call Remove 
void BST::DeleteVertex(el_t E)
{
  cout << "Trying to delete " << E << endl;
  
  Vertex *V;       // the current vertex
  Vertex *Parent;  // Parent will always point to V's parent

  // case 1: Lonely Root  --------------------
  if ((E == Root->Elem) && (Root->Left == NULL) && (Root->Right == NULL))//if root's left hand and right hand are holding nothing we have only the roo
      { cout << "...deleting the lonely root" << endl;
	delete Root; //delete root
	Root = NULL;//set root to null
	cout<<"Root only."<<endl;
	return; }  // only the Root was there and deleted it    
    // case 2:  One Substree Root ----------------
    // ** if what you want to delete is the root
    // ** and it has only the left subtree
  if((E == Root->Elem) && (Root->Right == NULL) && (Root->Left != NULL))//if Root's left hand is holding something and its right hand is not.      
      { 
	cout << "... deleting the root with just one child" << endl;
	//** change the root to the left child and return
	//   making sure the old root has been deleted and the new root's UP is NULL 
	Root = Root->Left;//new root
	delete Root->Up;//delete old root vertex
	Root->Up = NULL;//make root up NULL
	return;
      }
  else if((E == Root->Elem) && (Root->Right != NULL) && (Root->Left == NULL)) //else if root's right hand is holding something and root's left hand is not.
      {
        cout << "... deleting the root with just one child" << endl;
	// ** and it has only the right subtree
	// ** change the root to the right child and return
	//    making sure the old root has been deleted and the new root's UP is NULL 
	Root = Root->Right;//update to new root right
	delete Root->Up;//delete old root
	Root->Up = NULL;//old root is set to null
	return;
      }// end of deleting the root with one subtree
  else if((E == Root->Elem) && (Root->Right != NULL) &&(Root ->Left != NULL))//else if root's right hand and left hand hold something. 2 childrend
     {
       el_t e = findMax(Root);//replace element of current root with a leaf element. Find max finds the smallest/largest leaf element for us
       Root->Elem = e;//root elem is overwritten with e.
       delete Root->Left;//delete old root left being the leaf
       Root->Left = NULL;//set leaf to NULL
       return;
     }
   // ---- Otherwise deleting something else  --------------
   V = Root;  // start with the root to look for E
   Parent = NULL;  // above the V so does not point to anything yet
   // going down the tree looking for E
   while (V != NULL)//while v is not null we can still go down the tree.
     { 
       if (E == V->Elem)   // found it
	 {  cout << "...removing " << V->Elem << endl;
	   // ** call remove here to remove V
	   remove(V, Parent);//call remove and pass vertex v which holds the root and Parent.
	   return; 
	 }
       else//we need to continues to search for E.
	 {
	   if (E < V->Elem)//if E is less than V element go down to the left of the tree.
	     {  cout << "...going to the left" << endl;
	       // ** update Parent and V here to go down
	       Parent = V;//P will go to where V is.
	       V = V->Left;//V will now go down the tree as well going to parent's child.
	     }
	   else//else E is greater than V element so go right.
	     {  cout << "...going to the right" << endl;
	       // ** update Parent and V here to go down
	       Parent = V;//parent moves to where V is. A root or a subtree's root.
	       V = V->Right;//move to Parent's right child or v goes down to the right side of the root.
	     }//end of if/else
	 }//end if/else
     }// end of while
   
   // reached NULL  -- did not find it
   cout << "Did not find the key in the tree." << endl;
}// end of DeleteVertex


// PURPOSE: Removes vertex pointed to by V
// PARAM: V and its parent  pointer P
// Case 1: it is a leaf, delete it
// Case 2: it has just one child, bypass it
// Case 3: it has two children, replace it with the max of the left subtree
void BST::remove(Vertex *V, Vertex *P)
{
  // ** if V is a leaf (case 1)
  if((V->Right == NULL) && (V->Left == NULL))//If V right is holding nothing and V'left holds nothing we must be a leaf.
    {
      cout << "removing a leaf" << endl;
      // ** if V is a left child of P
      if(V->Elem < P->Elem )//if V elem is less than P elem go enter if we are deleteing parent's left leaf.
	{
	  // ** delete V and also make Parent's left NULL 
          // *** EC call here from P to adjust height and BF
	  delete V;//delete V 
	  P->Left = NULL;// P left is now NULL
	}
      else // V is a right child of the Parent delte parent's right leaf
	{ 
          // ** delete V and also make Parent's right NULL 
          // *** EC call from P to adjust height and BF
	  delete V;//delete V
	  P->Right = NULL;//P right is now null
	}
    }//end of leaf case   
  else if((V->Right == NULL) && (V->Left != NULL))// ** if V has just the left child so bypass V (case 2)
    { Vertex* C = V->Left; // the left child
      cout << "removing a vertex with just the left child" << endl;
      // ** You need if then else to determine Parent's left or right
      if(V->Elem < P->Elem)//V elem is less than P elem go left
	{
	  //    should point to V's left child
	  P->Left = C;//Parent should point to V's left child which C points too.
	  // ** Make V's left child point UP to the parent;
	  C->Up = P;//V's left child should point up to parent.
	  cout << C->Elem << " points up to " << C->Up->Elem << endl;
	  // ** Be sure to delete V
	  // *** EC call from P to adjust height and BF
	  delete V;//delete V we have no use for it anymore.
	}
      else//V must just have the right child so bypass V.
	{
	  //    should point to V's left child
	  P->Right = C;//P'right hand should point to V's left child.
	  // ** Make V's left child point UP to the parent;
	  C->Up = P;// V's left child should point up to Parent.
	  cout << C->Elem << " points up to " << C->Up->Elem << endl;
	  // ** Be sure to delete V
	  // *** EC call from P to adjust height and BF
	  delete V;//delete V no use for it anymore.
	}
    }// end of V with left child       
  else if((V->Left == NULL) && (V->Right != NULL))// ** if V has just the right child so bypass V (case 2)
    { Vertex* C = V->Right;  // the right child
      cout << "removing a vertex with just the right child" << endl;
      // ** You need if then else to determine Parent's left or right
      if(V->Elem > P->Elem)//If what we have is greater than what parent has go right.
	{
	  //  should point to V's right child; 
	  P->Right = C;//parent should point V's right child and C points to it.
	  // ** Make V's right child point UP to the parent;
	  C->Up = P;//V's right child should point up to Parent.
	  cout << C->Elem << " points up to " << C->Up->Elem << endl;
	  // ** Be sure to delete V
	  delete V;//delete V no use for it
	  // *** EC call from P to adjust height and BF
	}
      else//else what we have is less than what parent has.
         {
	   //    should point to V's left child
           P->Left = C;// Parent's left hand should point to V;s left child which C points to.
	   // ** Make V's left child point UP to the parent;

	   C->Up = P;// V's left child should point up to parent.
           cout << C->Elem << " points up to " << C->Up->Elem << endl;
           // ** Be sure to delete V
           // *** EC call from P to adjust height and BF
           delete V;//delete V no use for it anymore.
	 }      
      
    }//end of V with right child
  else // V has two children (case 3)
    { cout << "removing an internal vertex with children" << endl;
      cout << "..find the MAX of its left sub-tree" << endl;
      el_t Melem;// el_t type Melem
      // find MAX element in the left sub-tree of V
      Melem = findMax(V); //call find max
      cout << "..replacing " << V->Elem << " with " << Melem << endl;
          // ** Replace V's element with Melem here
      V->Elem = Melem;// V->Elem now holds Melem's value.
    }//end of V with two children      
}// end of remove

// PURPOSE: Finds the Maximum element in the left sub-tree of V
// and also deletes that vertex
el_t BST::findMax(Vertex *V)
{
  Vertex *Parent = V;//Parent points to V or top of tree/ root.
  V = V->Left;          // start with the left child of V
  
  
  // ** while the right child of V is still available
  while(V->Right != NULL)//while V right is not NULL we can continue down the tree.
    {
      // ** update Parent and V to go to the right
      Parent = V;//parent should point to where V is after every iteration
      V = V->Right;//V should update down the tree.
    }//end of while.
        
  // reached NULL Right  -- V now has the MAX element
  el_t X = V->Elem;//X holds V elem's value.
  cout << "...Max is " << X << endl;
  remove(V, Parent);    // remove the MAX vertex 
  return X;             // return the MAX element
  
}// end of FindMax

