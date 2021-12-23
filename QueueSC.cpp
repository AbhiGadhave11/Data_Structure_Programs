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
    PNODE last;
    int size;
    
    public:
    Queue()
    {
        first = NULL;
        last = NULL;
        size = 0;
    }
    
    void Enqueue(int no)   // InsertLast()
    {
       PNODE newn = NULL;
       newn = new NODE;
       newn->data = no;
       newn->next = NULL;
       if((first == NULL)&&(last==NULL))
       {
          first = newn;
          last = newn;
       }
       else
       {
          last->next = newn;
          last = last->next;
       }
       last->next = first;
       size++;
    }
    
    int Dequeue()   // DeleteFirst()
    {
       int no = 0;
       if((first == NULL)&&(last==NULL))
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
          PNODE temp = first;
          no = first->data;
          first = first->next;
          delete temp;
       }
       last -> next = first; 
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