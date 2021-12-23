#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE;

class Queue     // Singly Linear Linked List
{
    private:
    PNODE first;
    int size;
    
    public:
    Queue()
    {
        first = NULL;
        size = 0;
    }
    
    void Enqueue(int no)   // InsertLast()
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
               last->next = newn;
               newn->prev = last;
               last = newn;
            }
        last->next = first;
        first->prev = last;
        size++;
    }
    
    int Dequeue()   // DeleteFirst()
    {
        // Logic
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
    Queue obj;
    
    obj.Enqueue(11);
    obj.Enqueue(21);
    obj.Enqueue(51);
    obj.Enqueue(101);
    
    int iret = obj.Dequeue();   // 11
    cout<<iret;                 // 11
    
    obj.Display();          // 11 21 51
    iret = obj.Count();     // 3
    
    cout<<"Size of queue is : "<<iret<<"\n"; // 3
    
    return 0;
}
