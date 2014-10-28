/*
	Main client for implementing the Binary Search Tree

	DATE	: 28-October-2014
	CODER	: Arjun Krishna Babu
	
	COMPILER: G++
	OS		: Ubuntu 14.04 LTS 
*/

#include<iostream>
#include "Node.h"

#define ERR_TREE_EMPTY cerr<<"\n ERROR: Empty Tree!";

using namespace std;

class BST	{
	Node *root;
	bool isEmpty()	{
		return (root == NULL);
	}
public:
	BST()	{
		root = NULL;
	}
	
	Node* getRoot(void)	{
		return root;
	}
	
	void insert(int data);
	void trav_pre(Node *r);
	void trav_in(Node *r);
	void trav_post(Node *r);
};

int main()	{
	BST B;
	int choice;
	int num;
	
	do {
		cout<<"\n [BINARY SEARCH TREE IMPLEMENTATION]";
		cout<<"\n 1. Insertion";
		cout<<"\n 7. Pre-order traversal";
		cout<<"\n 8. In-order traversal";
		cout<<"\n 9. Post-order traversal";
		cout<<"\n 0. EXIT";
		cout<<"\n Enter Your Choice: ";
		cin>>choice;
		switch(choice)	{
			case 1: cout<<"\n Enter number to insert: ";
					cin>>num;
					B.insert(num);
					break;
			case 7: cout<<"\n Pre Order Traversal: ";
					B.trav_pre( B.getRoot() );
					break;
			case 8: cout<<"\n In Order Traversal: ";
					B.trav_in( B.getRoot() );
					break;
			case 9: cout<<"\n Post Order Traversal: ";
					B.trav_post( B.getRoot() );
					break;
			case 0: cout<<"\n Program under development";
					cout<<"\n Thank You For Using This Program!";
					break;
		   default: cerr<<"\n ERROR: Invalid Choice!";
					break;
		}				
	  cout<<endl<<endl;
	} while ( choice != 0 );
  return 0;
}
/*** MEMBER FUNCTION DEFINITIONS ***/
void BST::insert(int d)	{
	Node *temp = new Node(d);
	
	Node *loc = root;
	
	if( isEmpty() )	{
		root = temp;
	}
	else {
		loc = root;
		while(loc != NULL)	{
			if(loc->getData() > d)	{
				if( loc->getLeft() == NULL )	{
					loc->setLeft(temp);
					break;
				}
				loc = loc->getLeft();
			}
			else if( loc->getData() <= d )	{
				if( loc->getRight() == NULL )	{
					loc->setRight(temp);
					break;
				}
				loc = loc->getRight();
			}
		} //end of while()
	} //end of else
}

void BST::trav_pre(Node *R)	{
	if( R != NULL )	{
		cout<<" "<<R->getData();
		trav_pre(R->getLeft());
		trav_pre(R->getRight());
	}
}

void BST::trav_in(Node *R)	{
	if( R != NULL )	{
		trav_in( R->getLeft() );
		cout<<" "<<R->getData();
		trav_in( R->getRight() );
	}
}

void BST::trav_post(Node *R)	{
	if( R != NULL )	{
		trav_post( R->getLeft() );
		trav_post( R->getRight() );
		cout<<" "<<R->getData();
	}
}

