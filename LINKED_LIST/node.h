/*
	Nodes for linked list.
	* Linkled List Node
	* Circular Linked List Node
	* Doubly Linked List Node
	
	DATE 	: 24 - October - 2014
	AUTHOR	: Arjun Krishna Babu
*/

#ifndef NODE_H
	#define NODE_H
	
	class Node	{
		int data;
		Node *next;
	public:
		void setData(ind d)	{
			data = d;
		}
		int getData()	{
			return data;
		}
		
		void setNext(Node *N)	{
			next = N;
		}
		Node* getNext()	{
			return next;
		}
	};
		
#endif
