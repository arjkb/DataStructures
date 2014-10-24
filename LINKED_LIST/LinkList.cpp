/*
	Program to implement a linked list with the following functionalities
	- Insertion to head
	- Insertion to tail
	- Insertion after a particular element
	- Deletion from head
	- Deletion from tail
	- Deletion of a particular element
	- Search a particular element
	- Traversal (in order)
	
	DATE	: 24 - October - 2014
	AUTHOR	: Arjun Krishna Babu
*/

#include <iostream>
#include "node.h"

#define PRT_LIST_EMPTY cerr<<"\n ERROR: Empty Linked List!";

using namespace std;

class LinkList	{
	Node *head;
	
	bool isEmpty()	{
		return (head == NULL);
	}
public:
	LinkList()	{
		head = NULL;
	}
	
	void insHead(int d)	{
		Node *temp = new Node(d);	//invoked constructor 2
		
		if( isEmpty() )	{
			head = temp;
		}
		else {
			temp->setNext(head);
			head = temp;
		}
	}
	
	void insTail(int d)	{
		Node *temp = new Node(d);
		Node *loc;
		
		if( isEmpty() )	{
			head = temp;
		}
		else {
			loc = head;
			while( loc->getNext() != NULL ) { //traverse to last node
				loc = loc->getNext();			
			}
			loc->setNext(temp);
		}
	}
	
	void delHead()	{
		Node *temp = head;
		
		if( isEmpty() )	{
			PRT_LIST_EMPTY;
		}
		else {
			head = head->getNext();
			cout<<"\n Deleting Element: "<<temp->getData();
			delete temp;
		}
	}
	
	void dispAll()	{
		Node *temp = head;
		
		if( isEmpty() )	{
			PRT_LIST_EMPTY;
		}
		else {
			while( temp != NULL )	{
				cout<<" --> "<<temp->getData();
				temp = temp->getNext();
			}
		}
	}		
};
	
int main()	{
	
	LinkList L;
	int choice;
	int num;
	
	do {
		
		cout<<"\n [LINKED LIST IMPLEMENTATION]";
		cout<<"\n 1. Insert to head";
		cout<<"\n 2. Insert to tail";
		cout<<"\n 4. Delete from head";
		cout<<"\n 9. Display";
		cout<<"\n 0. EXIT";
		cout<<"\n Enter Your Choice: ";
			cin>>choice;
		
		switch(choice)	{
			case 1: cout<<"\n Enter element to insert to head: ";
					cin>>num;
					L.insHead(num);
					break;
			case 2: cout<<"\n Enter element to insert to tail: ";
					cin>>num;
					L.insTail(num);
					break;
			case 4: L.delHead();
					break;
			case 9: cout<<"\n Elements of Linked List: ";
					L.dispAll();
					break;
			case 0: cout<<"\n Program Under Development!";
					cout<<"\n Thank You For using This Program!";
					break;
		   default: cerr<<"\n ERROR: Invalid Choice!";
					break;
		}
	  cout<<endl<<endl;		
	}while(choice != 0);
  return 0;
 }
