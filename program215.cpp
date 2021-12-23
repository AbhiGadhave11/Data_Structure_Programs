#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE;

class Stack     // Singly Linear Linked List
{
private:
    PNODE first;
    int size;
    
public:
    Stack()
    {
        first = NULL;
        size = 0;
    }
    
    void push(int no)   // InsertFirst()
    {
       PNODE newn = NULL;

	   newn = (PNODE)malloc(sizeof(NODE));
	
	   newn->data = no;
	   newn->next = NULL;
	
	   if(first == NULL)
	     {
		    first = newn;
	     }
	   else
	    {
            newn->next = first;
            first = newn;
	    }
	    size++;
    }
    
    int pop()   // DeleteFirst()
    {
        return 0;
    }
    
    void Display()
    {
    	 PNODE temp = first;
        for(int i=1;i<=size;i++)
        {
            cout<<"|"<<temp->data<<"|-> ";
            temp = temp->next;
        }
        cout<<"\n";
    }
    
    int Count()
    {
        return size;
    }
};

int main()
{
    Stack obj;
    
    obj.push(11);
    obj.push(21);
    obj.push(51);
    obj.push(101);
    
    obj.Display();

    int iret = obj.pop();       // 101
    cout<<iret<<"\n";                     // 101
    
    obj.Display();          // 51       21      11
    iret = obj.Count();
    
    cout<<"Size of stack is : "<<iret<<"\n";        // 3
    
    return 0;
}
