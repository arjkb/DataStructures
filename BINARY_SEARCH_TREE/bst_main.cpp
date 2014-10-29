/*
	Main client for implementing the Binary Search Tree
	* Insertion
	* Search
	* Find height
	* Traversal

	DATE	: 28-October-2014
	CODER	: Arjun Krishna Babu
	
	COMPILER: G++
	OS		: Ubuntu 14.04 LTS 
*/

#include<iostream>
#include "Node.h"

#define ERR_TREE_EMPTY cerr<<"\n ERROR: Empty Tree!";

using namespace std;
/*
enum MODE	{
	PREORDER, 
	INORDER, 
	POSTORDER
}M;
*/

int max(int a, int b)	{
	return (a >=  b)? a : b;
}

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
	bool search(int key);
	int getHeight(Node *);

//	void traverse(MODE, Node *);
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
		cout<<"\n 2. Search";
		cout<<"\n 3. Height";
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
					
			case 2: cout<<"\n Enter number to search: ";
					cin>>num;
					if( B.search(num) )
						cout<<"\n "<<num<<" FOUND!";
					else
						cout<<"\n "<<num<<" NOT FOUND!";
					break;
					
			case 3: cout<<"\n Height of tree: "<<B.getHeight( B.getRoot() );
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
					
			case 0: cout<<"\n Program under development at https://github.com/arjunkbabu";
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

bool BST::search(int key)	{
	
	Node *loc = root;
		
	while( loc != NULL )	{
		if( loc->getData() == key )
			return true;
		else if( loc->getData() < key )
			loc = loc->getRight();
		else if( loc->getData() > key )
			loc = loc->getLeft();
	}		
	return false;
}	

int BST::getHeight(Node *r)	{
	if( r == NULL )	
		return -1;
	else
		return ( max( getHeight( r->getLeft()), getHeight( r->getRight() ) ) + 1 );
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

/*	WORK IN PROGRESS
void traverse(int E, Node *R)	{
	if( R != NULL )	{
		switch(E)	{
			case PREORDER: 	cout<<" "<<R->getData();
							traverse(PREORDER, R->getLeft());
							traverse(PREORDER, R->getRight());
							break;
							
			case INORDER:	traverse(INORDER, R->getLeft() );
							cout<<" "<<R->getData();
							traverse(INORDER, R->getRight() );	
							break;
							
			case POSTORDER:	traverse(POSTORDER, R->getLeft() );
							traverse(POSTORDER, R->getRight() );
							cout<<" "<<R->getData();
							break;							
		}
	}
}
*/
