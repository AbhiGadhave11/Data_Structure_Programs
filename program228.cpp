#include<iostream>
using namespace std;

template<typename T>
struct node
{
	T data;
    struct node *next;
};

template<class T>
class SinglyLL
{
	private :
    node<T> *first;
	int size;
	
	public :
    
    SinglyLL();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int iPos);
	void Display();
	int Count();

};

    template<class T>
	SinglyLL<T> :: SinglyLL()
	{
		first = NULL;
		size = 0;
	}
   
    template<class T>
	void SinglyLL<T> :: InsertFirst(T no)
	{
		 node<T> * newn = NULL;
		newn = new node<T>; // newn = (PNODE)malloc(sizeof(NODE));

		newn->data = no;
		newn->next = NULL;

		if(first==NULL)
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

    template<class T>
	void SinglyLL<T> :: InsertLast(T no)
	{
		node<T> * newn = NULL;
		newn = new node<T>; // newn = (PNODE)malloc(sizeof(NODE));

		newn->data = no;
		newn->next = NULL;

		if(first==NULL)
		{
			first = newn;
		}
		else
		{
			 node<T> * temp = first;

			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newn;
		}
		size++;
	}

    template<class T>
	void SinglyLL<T> :: InsertAtPos(T no,int iPos)
	{
		 node<T> * temp = first;
		int i=0;
		if((iPos<1)||(iPos>size+1))
		{
			return;
		}
		if(iPos==1)
		{
			InsertFirst(no);
		}
		else if(iPos==size + 1)
		{
			InsertLast(no);
		}
		else
		{
			 node<T> * newn = NULL;
			newn = new node<T>;

			newn->data = no;
			newn->next = NULL;

			for(i=1;i<(iPos-1);i++)
		     {
			    temp = temp->next;
		     }
		    newn->next = temp->next;
		    temp->next = newn;
		    size++;
		}
		
	}

    template<class T>
	void SinglyLL<T> :: DeleteFirst()
	{
		 node<T> * temp = first;
		if(first !=NULL)
		{
			first = first->next;
			delete temp;

			size--;
		}
	}

    template<class T>
	void SinglyLL<T> :: DeleteLast()
	{
		node<T> * temp = first;
		if(first==NULL)
		{
			return;
		}
		else if(first->next==NULL)
		{
			delete first;
			first = NULL;
			size--;
		}
		else
		{
			while(temp->next->next != NULL)
			{
				temp = temp->next;
			}
			delete(temp->next);
			temp->next = NULL;
			size--;
		}
	}

    template<class T>
	void SinglyLL<T> :: DeleteAtPos(int iPos)
	{
		 node<T> * temp = first;
		 node<T> * targeted = NULL;
		if((iPos<1)||(iPos>size+1))
		{
			return;
		}
		if(iPos==1)
		{
			DeleteFirst();
		}
		else if(iPos==size+1)
		{
			DeleteLast();
		}
		else
		{
			int i=0;
			for(i=1;i<(iPos-1);i++)
			{
				temp = temp->next;
			}
			targeted = temp->next;
			temp->next = targeted->next;

		}
		size--;
	}
    
    template<class T>
	void SinglyLL<T> :: Display()
	{
		 node<T> * temp = first;

		while(temp!=NULL)
		{
			cout<<"|"<<temp->data<<"|-> ";
			temp = temp->next;
		}
		cout<<"NULL\n";
	}

    template<class T>
	int SinglyLL<T> :: Count()
	{
		return size;
	} 

////////////////////////////////

int main()
{
	int iRet = 0;

    SinglyLL <char>obj;
  
    obj.InsertFirst('C');
    obj.InsertFirst('B');
    obj.InsertFirst('A');
    
    obj.InsertLast('D');
    obj.InsertLast('E');
    
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";


	SinglyLL <int>iobj;
  
    iobj.InsertFirst(51);
    iobj.InsertFirst(21);
    iobj.InsertFirst(11);
    
    iobj.InsertLast(101);
    iobj.InsertLast(111);
    
    iobj.Display();

    iRet = iobj.Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";
    
	return 0;
}