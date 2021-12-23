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
    PNODE last;

    int size;
    
    public:
    Stack()
    {
        first = NULL;
        last = NULL;
        size = 0;
    }
    
    void push(int no)   // InsertFirst()
    {
        PNODE newn = NULL;
        newn = new NODE;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        if((first==NULL)&&(last==NULL))
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn->next = first;
            first->prev = newn;
            first = newn;
        }
        last->next = first;
        first->prev = last;
        size++;
    }
    
    int pop()   // DeleteFirst()
    {
        int no = 0;
        if((first==NULL)&&(last==NULL))
        {
            return -1;
        }
        if(first == last)
        {
            no = first->data;
            delete first;
            first = NULL;
            last = NULL;
        }
        else
        {
            no = first->data;
            first = first->next;
            delete last->next;
        }
        last -> next = first;
        first -> prev = last;
        size--;
        return no;
    }
    
    void Display()
    {
         PNODE temp = first;
         if((first==NULL)&&(last==NULL))
         {
            return;
         }
        do
        {
            cout<<"|"<<temp->data<<"|-> ";
            temp = temp->next;
        }while(temp!=last->next);
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
    
    cout<<"Size of stack is : "<<iret<<"\n";// 3
    
    return 0;
}
