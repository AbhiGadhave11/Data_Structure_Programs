#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}NODE,*PNODE,**PPNODE;

class SinglyLL
{
	private :
	PNODE first;
	int size;
	
	public :
    
    SinglyLL();
	void InsertFirst(int no);
	void InsertLast(int no);
	void InsertAtPos(int no,int iPos);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int iPos);
	void Display();
	int Count();

};


	SinglyLL :: SinglyLL()
	{
		first = NULL;
		size = 0;
	}

	void SinglyLL :: InsertFirst(int no)
	{
		PNODE newn = NULL;
		newn = new NODE; // newn = (PNODE)malloc(sizeof(NODE));

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

	void SinglyLL :: InsertLast(int no)
	{
		PNODE newn = NULL;
		newn = new NODE; // newn = (PNODE)malloc(sizeof(NODE));

		newn->data = no;
		newn->next = NULL;

		if(first==NULL)
		{
			first = newn;
		}
		else
		{
			PNODE temp = first;

			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newn;
		}
		size++;
	}

	void SinglyLL :: InsertAtPos(int no,int iPos)
	{
		PNODE temp = first;
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
			PNODE newn = NULL;
			newn = new NODE;

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

	void SinglyLL :: DeleteFirst()
	{
		PNODE temp = first;
		if(first !=NULL)
		{
			first = first->next;
			delete temp;

			size--;
		}
	}

	void SinglyLL :: DeleteLast()
	{
		PNODE temp = first;
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

	void SinglyLL :: DeleteAtPos(int iPos)
	{
		PNODE temp = first;
		PNODE targeted = NULL;
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

	void SinglyLL :: Display()
	{
		PNODE temp = first;

		while(temp!=NULL)
		{
			printf("|%d| -> ",temp->data);
			temp = temp->next;
		}
		cout<<"NULL\n";
	}

	int SinglyLL :: Count()
	{
		return size;
	} 


int main()
{
	SinglyLL obj;
  
    int iRet = 0,iPos=0,iChoice=1,iValue=0;
    while(iChoice!=0)
    {
    	printf("\n******************************************\n");
    	printf("Enter the operation that we want to perform\n");
    	printf("1 : Insert the Element at First Position\n");
    	printf("2 : Insert the Element at Second Position\n");
    	printf("3 : Insert the Element at Any Position\n");
    	printf("4 : Delete the Element at First Position\n");
    	printf("5 : Delete the Element at Last Position\n");
    	printf("6 : Delete the Element at Any Position\n");
    	printf("7 : Display the Linked List\n");
    	printf("8 : Count The number of Nodes\n");
    	printf("0 : Terminate the Application\n");
    	printf("\n******************************************\n");
    	
    	printf("Enter the Choice\n");
    	scanf("%d",&iChoice);
    	
    	switch(iChoice)
    	{
    		case 1 :
    		{
    			printf("Enter the Element\n");
    		    scanf("%d",&iValue);
    		    obj.InsertFirst(iValue);
    		    break;
    		}
    		case 2 :
    		{
    			
    			printf("Enter the Element\n");
    			scanf("%d",&iValue);
    			obj.InsertLast(iValue);
    			break;
    		}
    		case 3 :
    		{
    			
    			printf("Enter the Element\n");
    			scanf("%d",&iValue);
    			printf("Enter the Position\n");
    			scanf("%d",&iPos);
    			obj.InsertAtPos(iValue,iPos);
    			break;
    		}
    		case 4 :
    		{
    		
    			obj.DeleteFirst();
    			break;
    		}
    		case 5 :
    		{
    			
    			obj.DeleteLast();
    			break;
    		}
    		case 6 :
    		{
    			
    			printf("Enter the Position\n");
    			scanf("%d",&iPos);
    			obj.DeleteAtPos(iPos);
    			break;
    		}
    		case 7 :
    		{
    			
    			obj.Display();
    			break;
    		}
    		case 8 :
    		{
    			
    			iRet = obj.Count();
    			printf("Number of Nodes are : %d\n",iRet);
    			break;
    		}
    		case 0 :
    		{
    			printf("Thank You for using the Software\n");
    			break;
    		}
    		default :
    		{
    			printf("Enter the Valid Choice\n");
    			break;
    		}
    		
    	}
    }
    
	return 0;
}