#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
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
        
        newn = new NODE;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            newn->next = first;
            first->prev = newn;
            first = newn; 
        }
        size++;

    }
    
    int pop()   // DeleteFirst()
    {
        int no = 0;
       if(first == NULL)
       {
         cout<<"No elements in linked list\n";
         return 0;
       }
       if(first->next == NULL)
       {
          delete first;
          no = first->data;
          first = NULL;
       }
       else
       {
         // no = first->data;
          first = first->next;
          no = first->prev->data;
          delete first->prev;
          first->prev = NULL;
       }
       size--;
       return no;
    }
    
    void Display()
    {
         PNODE temp = first;
        while(temp!=NULL)
        {
            cout<<"|"<<temp->data<<"|-> ";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
    
    int Count()
    {
        return size;
    }
};

int main()
{
    Stack obj;
    
    obj.push(101);
    obj.push(51);
    obj.push(21);
    obj.push(11);
    
    cout<<"Element of stack\n";
    obj.Display();

    
    int iret = obj.pop();       // 101
    cout<<"Popped element is : "<<iret<<"\n";                     // 101
    
    cout<<"Element of stack\n";
    obj.Display();          // 51       21      11
    iret = obj.Count();
    
    cout<<"Size of stack is : "<<iret<<"\n";        // 3
    
    return 0;
}