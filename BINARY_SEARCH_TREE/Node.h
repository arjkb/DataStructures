/*
	Node for a binary search tree

	DATE	: 28 - October - 2014
	AUTHOR	: Arjun Krishna Babu
*/

#ifndef NODE_H
	#define NODE_H
		
		class Node	{
			int data;
			Node *left;
			Node *right;
		public:
			Node()	{
				data = 0;
				left = right = NULL;
			}
			
			Node(int d)	{
				data = d;
				left = right = NULL;
			}
			
			void setData(int d)	{ data = d; 	}
			int  getData()		{ return data; 	}
			
			void setLeft(Node *L)	{ left = L;		}
			Node* getLeft()			{ return left;	}

			void setRight(Node *R)	{ right = R;	}
			Node* getRight()			{ return right;	}
		};
#endif
