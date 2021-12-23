#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
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
        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            PNODE temp = first;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
            newn->prev = temp;
        }
        size++;
    }
    
    int Dequeue()   // DeleteFirst()
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
        PNODE temp=first;
       for(int i=1;i<=size;i++)
       {
          cout<<"|"<<temp->data<<"|\n";
          temp = temp->next;
       }
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
    
    cout<<"Elements of Queue\n";
    obj.Display(); 

    int iret = obj.Dequeue();   // 11
    cout<<"Removed Element from Queue : "<<iret<<"\n";                 // 11
    
    obj.Display();          // 11 21 51
    iret = obj.Count();     // 3
    
    cout<<"Size of queue is : "<<iret<<"\n"; // 3
    
    return 0;
}