/*
	Basic queue implementation in C++ using arrays
	
	DATE	: 23 - October - 2014
	AUTHOR	: Arjun Krishna Babu
*/

#include<iostream>

using namespace std;

const int SIZE = 5;
class Queue	{
	int A[SIZE];
	int front;
	int rear;
	
	bool isEmpty()	{
		return ( (front == -1) && (rear == -1) );
	}
	
	bool isFull()	{
		return ( (front == 0 && rear == (SIZE - 1)) || ( rear == (front - 1)) );
	}
	
public:
	Queue()	{
		front = -1;
		rear  = -1;
		//a value of -1 for front AND rear indicates queue is empty
	}
	
	void enqueue(int);
	int dequeue();
	void dispAll();
};

int main()	{
	Queue Q;
	
	int choice;
	int num;
	
	do {
		
		cout<<"\n [CIRCULAR QUEUE IMPLEMENTATION]";
		cout<<"\n 1. Enqueue";
		cout<<"\n 2. Dequeue";
		cout<<"\n 9. Display";
		cout<<"\n 0. EXIT";
		cout<<"\n Enter Your Choice: ";
		cin>>choice;
		
		switch(choice)	{
			case 1: cout<<"\n Enter element to enqueue: ";
					cin>>num;
					Q.enqueue(num);
					break;
			case 2: cout<<"\n Dequeued Element: "<<Q.dequeue();
					break;
			case 9: Q.dispAll();
					break;
			case 0: cout<<"\n Program under development!";
					cout<<"\n Thank You For Using This Program!";
					break;
		   default: cerr<<"\n ERROR: Invalid Choice!";
					break;
		}
		
	  cout<<endl<<endl;
	}while( choice != 0 );
  return 0;
}
/***** MEMBER FUNCTION DEFINITIONS *****/
void Queue::enqueue(int d)	{
	if( isFull() )
		cerr<<"\n ERROR: Overflow!";
	else {	//if there is space in queue	
		if( isEmpty() )	{
			front = rear = 0;
			A[rear] = d;
		}
		else if( rear == SIZE - 1 )  {
			rear = 0;
			A[rear] = d;
		}
		else 
			A[++rear] = d;
	}
}

int Queue::dequeue()	{
	int temp = -1;
	
	if( isEmpty() )	{
		cerr<<"\n ERROR: Underflow!";
		return -1;
	}
	else {
		if( front == rear )	{
			temp = A[front];
			front = rear = -1;
		}
		else if( front == (SIZE - 1) )	{
			temp = A[front];
			front = 0;
		}
		else
			temp = A[front++];
		
		return temp;		
	}
}

void Queue::dispAll()	{
	int i;
	if( isEmpty() )	
		cerr<<"\n ERROR: Underflow!";
	else {
		
		if( front <= rear )	
			for( i = front; i <= rear; i++ )
				cout<<" "<<A[i];
		else if( rear < front )	{
			for( i = front; i <= SIZE - 1; i++)	
				cout<<" "<<A[i];
			
			for( i = 0; i <= rear; i++ )
				cout<<" "<<A[i];
		}
	}
}
