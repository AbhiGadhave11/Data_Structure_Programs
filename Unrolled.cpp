#include <iostream>
using namespace std;

#define maxElements 4

// Unrolled Linked List Node
typedef struct Node
{
	public:
	int numElements;
	int array[maxElements];
	Node *next;

}NODE,*PNODE;

/* Function to traverse am unrolled linked list
and print all the elements*/
class Unrolled
{
	PNODE first;
	int size;

	Unrolled()
	{
		first = NULL;
		size = 0;
	}

	void printUnrolledList()
    {
    	PNODE temp = first;
	   while (temp!= NULL)
	   {
		
		   for (int i=0; i<(temp->numElements); i++)
		   {
			   cout<<temp->array[i]<<" ";
		   }

		   temp = temp->next;
	    }
    }
};


// Program to create an unrolled linked list
// with 3 Nodes
int main()
{
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;

	// allocate 3 Nodes
	head = new Node();
	second = new Node();
	third = new Node();

	// Let us put some values in second node (Number
	// of values must be less than or equal to
	// maxElement)
	head->numElements = 3;
	head->array[0] = 1;
	head->array[1] = 2;
	head->array[2] = 3;

	// Link first Node with the second Node
	head->next = second;

	// Let us put some values in second node (Number
	// of values must be less than or equal to
	// maxElement)
	second->numElements = 3;
	second->array[0] = 4;
	second->array[1] = 5;
	second->array[2] = 6;

	// Link second Node with the third Node
	second->next = third;

	// Let us put some values in third node (Number
	// of values must be less than or equal to
	// maxElement)
	third->numElements = 3;
	third->array[0] = 7;
	third->array[1] = 8;
	third->array[2] = 9;
	third->next = NULL;

	printUnrolledList(head);

	return 0;
}

// This is code is contributed by rathbhupendra
