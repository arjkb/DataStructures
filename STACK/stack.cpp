/*
	Program to implement a stack in C++
	
	DATE	: 23-October-2014
	AUTHOR	: Arjun Krishna Babu
*/

#include<iostream>

using namespace std;

const int SIZE = 100;

class Stack	{
	int A[SIZE];
	int top;
	
	bool isFull()	{
		return(top == (SIZE - 1));
	}
	
	bool isEmpty()	{
		return (top == -1);
	}

public:
	Stack()	{
		top = -1;
	}
	
	void push(int d)	{
		if( !isFull() )	
			A[++top] = d;
		else
			cerr<<"\n ERROR: Overflow!";
	}
	
	void pop()	{
		if( !isEmpty()	)	
			cout<<"\n Popped Element: "<<A[top--];
		else
			cerr<<"\n ERROR: Underflow!";
	}
	
	int peek()	{
		if( !isEmpty() )
			return A[top];
		else {
			cerr<<"\n ERROR: Underflow!";
			return -1;
		}
	}
	
	void dispAll()	{
		if( !isEmpty() )	{
			for(int i = top; i >= 0; i--)	{
				cout<<"\n "<<A[i];
			}
		} 
		else
			cerr<<"\n ERROR: Underflow!";
	}
};

int main()	{
	
	Stack S;
	
	int choice;
	int num;
	
	do {
		cout<<"\n [STACK IMPLEMENTATION]";
		cout<<"\n 1. Push";
		cout<<"\n 2. Pop";
		cout<<"\n 3. Peek";
		cout<<"\n 9. Display";
		cout<<"\n 0. EXIT";
		cout<<"\n Enter Your Choice: ";
		cin>>choice;
		switch(choice)	{
			case 1: cout<<"\n Enter an element to push: ";
					cin>>num;
					S.push(num);
					break;
			case 2: S.pop();
					break;
			case 3: cout<<"\n Top Element: "<<S.peek();
					break;
			case 9: cout<<"\n Elements of the stack are: ";
					S.dispAll();
					break;
			case 0: cout<<"\n Program under development!";
					cout<<"\n Thank You For Using This Program!";
					break;
		   default: cerr<<"\n ERROR: Invalid Choice!";
					break;
		}
	  cout<<endl<<endl;			
	} while ( choice != 0 );
  return 0;
}
