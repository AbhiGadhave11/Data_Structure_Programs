#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;

}NODE,*PNODE,**PPNODE;

void InsertFirst(PPNODE Head,PPNODE Tail,int no)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));

	newn->data = no;
	newn->next = NULL;
	

	if((*Head==NULL) && (*Tail==NULL))
	{
        *Head = newn;
        *Tail = newn;
	}
	else
	{
		newn->next = *Head;
		*Head = newn;
	}
	(*Tail) -> next = *Head; // To maintain circular nature
}

void InsertLast(PPNODE Head,PPNODE Tail,int no)
{

	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));

	newn->data = no;
	newn->next = NULL;
	

	if((*Head==NULL) && (*Tail==NULL))
	{
        *Head = newn;
        *Tail = newn;
	}
	else
	{
		(*Tail) -> next = newn;
		*Tail = newn;
	}
	
	(*Tail) -> next = *Head; 
}

int Count(PNODE Head,PNODE Tail)
{
	int iCnt = 0;
	if((Head==NULL)&&(Tail==NULL))
	{
		return 0;
	}
	do
	{
		iCnt++;
		Head = Head->next;
	
	}while(Head!=Tail->next);
	return iCnt;
}

void InsertAtPos(PPNODE Head,PPNODE Tail,int no,int iPos)
{
	int size = 0;
	size = Count(*Head,*Tail);
	PNODE temp = *Head;
	if((iPos<1)&&(iPos>size + 1))
	{
		return;
	}
	if(iPos==1)
	{
		InsertFirst(Head,Tail,no);
	}
	else if(iPos==size+1)
	{
		InsertLast(Head,Tail,no);
	}
	else
	{
		PNODE newn = NULL;
		newn = (PNODE)malloc(sizeof(NODE));


		newn->data = no;
		newn->next = NULL;
		
		for(int i=1;i<(iPos-1);i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;
	}
}

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
	if((*Head == NULL)&&(*Tail == NULL))
	{
		return;
	}
	else if(*Head == *Tail)
	{
		free(*Head);
		*Head = NULL;
		*Tail = NULL;
	}
	else
	{
		*Head = (*Head) -> next;
		free((*Tail)-> next);
		(*Tail)-> next = *Head;
	}
}

void DeleteLast(PPNODE Head,PPNODE Tail)
{
	PNODE temp = *Head;
	if((*Head == NULL)&&(*Tail == NULL))
	{
		return;
	}
	else if(*Head == *Tail)
	{
		free(*Head);
		*Head = NULL;
		*Tail = NULL;
	}
	else
	{
		while(temp->next != *Tail)
		{
			temp = temp->next;
		}
		free(*Tail);
		*Tail = temp;
		(*Tail) -> next = *Head;
	}
}

void DeleteAtPos(PPNODE Head,PPNODE Tail,int iPos)
{
	PNODE temp = *Head;
	PNODE targeted = NULL;
	int size = 0;
	size = Count(*Head,*Tail);
	if((iPos<1)&&(iPos>size + 1))
	{
		return;
	}
	if(iPos==1)
	{
		DeleteFirst(Head,Tail);
	}
	else if(iPos==size+1)
	{
		DeleteLast(Head,Tail);
	}
	else
	{
		for(int i=1;i<(iPos-1);i++)
		{
			temp = temp->next;
		}
		targeted = temp->next;
		temp->next = targeted->next;
		free(targeted);
	}
}

void Display(PNODE Head,PNODE Tail)
{
	if((Head==NULL)&&(Tail==NULL))
	{
		return;
	}
	do
	{
		printf("|%d| -> ",Head->data);
		Head = Head->next;
	
	}while(Head!=Tail->next);
	printf("NULL\n");
}



int main()
{
	PNODE first = NULL;
    PNODE last = NULL;
    int iChoice = 1,Value=0;
    int iRet = 0,pos = 0;

    while(iChoice!=0)
    {
    	printf("****************************************************\n");
    	printf("Enter the Desired operation that you want to perform on LinkedList\n");
        printf("1 : Insert the node at first position\n");
        printf("2 : Insert the node at Last position \n");
        printf("3 : Insert the node at Desired position\n");
        printf("4 : Delete the first node\n");
        printf("5 : Delete the last node\n");
        printf("6 : Delete the node at desired position\n");
        printf("7 : Display the content of LinkedList\n");
        printf("8 : Count the number of nodes from LinkedList\n");
        printf("0 : Terminate the Application\n");
        printf("*****************************************************\n");    
        
        scanf("%d",&iChoice);
        switch(iChoice)
        {
        	case 1 :
        	{
        	printf("Enter the data to insert\n");
        	scanf("%d",&Value);
        	InsertFirst(&first,&last,Value);
        	break;
            }

        	case 2 :
        	{
        	printf("Enter the data to insert\n");
        	scanf("%d",&Value);
        	InsertLast(&first,&last,Value);
        	break;
            }
        	case 3 :
        	{
        	printf("Enter the data to insert\n");
        	scanf("%d",&Value);
        	printf("Enter the position\n");
        	scanf("%d",&pos);
        	InsertAtPos(&first,&last,Value,pos);
        	break;
             }

        	case 4 :
        	{
        	DeleteFirst(&first,&last);
        	break;
            }

        	case 5 :
        	{
        	DeleteLast(&first,&last);
        	break;
            }

        	case 6 :
        	{
        	printf("Enter the position\n");
        	scanf("%d",&pos);
            DeleteAtPos(&first,&last,pos);
        	break;
            }

        	case 7 :
        	{
        	printf("Elements in LinkedList are:\n");
        	Display(first,last);
        	break;
            }

        	case 8 :
        	{
        	iRet = Count(first,last);
        	printf("Number of Elements are : %d\n",iRet);
        	break;
            }

            case 0:
                printf("Thank for using Marvellous Linked List\n");
                break;

        	default :
        	{
        	   printf("Please Enter Proper Choice\n");
        	   break;
        	}
    
        } 
    }
	
  return 0;
}