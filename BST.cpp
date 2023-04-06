#include "ll.h"
#include "Node.h"
#include <iostream>
#include <cstdlib> //for rand()

using namespace std;

typedef int el_t2;

class BST
{
private:
  Node* root;
  void insertNode(Node*&, el_t2);
public:
  BST();
  void insertNode(el_t2);
  bool search(el_t2 e);
  void breadthFirstPrint();
  void depthFirstPrint();
  int getMaxLength();
  int getMaxLength(Node* p);
};

BST::BST()
{
  root = NULL;
}

void BST::insertNode(el_t2 e)
{
  insertNode(root, e);
}

void BST::insertNode(Node*& p, el_t2 e)
{
  if(p == NULL)
    p = new Node(e);
  else if(e < p->elem)
    insertNode(p->left, e);
  else
    insertNode(p->right, e);
}
 
bool BST::search(el_t2 e)
{
  Node* temp;
  temp = root;
  int count = 0;
  while(temp != NULL )
    {
      if(e < temp->elem)
        {
          temp = temp->left;
        }
      else if(e > temp->elem)
        {
          temp = temp->right;
        }
      else
        {
	  cout<<count<<" nodes checked."<<endl;
	  return true;
        }
      count++;
    }
  cout<<count<<" nodes checked."<<endl;
  return false;

}

void BST::breadthFirstPrint()
{
  if(root != NULL)
    {
      LL q;
      Node* p;
      q.addRear(root);
      while(!q.isEmpty())
	{
	  p = q.deleteFront();
	  cout<<p->elem<<"->";
	  if(p->left != NULL)
	    {
	      q.addRear(p->left);
	    }
	  if(p->right != NULL)
	    {
	      q.addRear(p->right);
	    }
	}
    }
}

void BST::depthFirstPrint()
{
  LL s;
  Node* p;
  

  if(root != NULL)
    {
      s.addRear(root);
      while(!s.isEmpty())
	{
	  p = s.deleteRear();
	  cout<<p->elem<<"->";
	  
	  if(p->right != NULL)
	    {
	      s.addRear(p->right);
	    }
	  if(p->left != NULL)
	    {
	      s.addRear(p->left);
	    }
	}
    }
}

int BST::getMaxLength()
{
  return getMaxLength(root);
}

int BST::getMaxLength(Node* p)
{

  if(p == NULL)
    {
      return 0;
    }
  else 
    {
      int l1 = getMaxLength(p->left);
      int l2 = getMaxLength(p->right);
      
      if(l1 > l2)
	{
	  return l1 + 1;
	}
      else
	{
	  return l2 + 1;
	}
    }
}

int main()
{
  BST b;
  b.insertNode(5);
  b.insertNode(3);
  b.insertNode(8);
  b.insertNode(2);
  b.insertNode(4);
  b.insertNode(10);
  b.insertNode(1);

  /*b.insertNode(5);
  b.insertNode(8);
  b.insertNode(3);
  b.insertNode(9);
  b.insertNode(6);
  b.insertNode(1);
  b.insertNode(0);
  b.insertNode(4);
  b.insertNode(7);
  b.insertNode(20);
  */
  b.breadthFirstPrint();
  cout<<endl;
  cout <<"depthFirst below: "<<endl;
  b.depthFirstPrint();
  
  cout << endl;
  
  cout<<b.getMaxLength()<<endl;
  return 0;
}


/*
int main()
{
  srand(time(0)); //you need to include cstdlib

  BST b1;
  LL l1;
  int ran, count;

  for (int i = 0; i < 10000;i++ ) 
    {
      ran = (rand()% 10000 + 1);
      b1.insertNode(ran);
      l1.addRear(ran);
    } 
    
  int key;
  cout << "What number do you want to search for? ";
  cin >> key;


  cout << "BST *************************" << endl;
  if(b1.search(key) == false)
    {
      cout<<key<<" was not found."<<endl;
    }
  else
    {
      cout<<key<<" was found."<<endl;
    }
  
  

  cout << "LL************************" << endl;
  
  if(!l1.search(key))
    {
      cout<<key<<" was not found."<<endl;
    }
  else
    {
      cout<<key<<" was found."<<endl;
    }

  return 0;
}
*/
