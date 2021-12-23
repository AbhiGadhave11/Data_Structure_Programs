
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;

}NODE,*PNODE,**PPNODE;

void InsertFirst(PPNODE Head,int no)
{
	PNODE newn = NULL;

	newn = (PNODE)malloc(sizeof(NODE));
	
	newn->data = no;
	newn->next = NULL;
	
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
        newn->next = *Head;
        *Head = newn;
	}
}

void Ascending_Sort(PNODE Head)
{
	PNODE temp = Head;
    int a=0,n1=0;
    PNODE targeted = NULL;
	
	while(temp!=NULL)
	{
		n1 = temp->data;
		targeted = temp->next;
		while(targeted!=NULL)
		{
			if((targeted->data) < n1)
			{
				a = n1;
				n1 = targeted->data;
				targeted->data = a;
				
				temp->data = n1;
			}
			targeted = targeted->next;
		}
		
		temp = temp->next;
	}

}

void Descending_Sort(PNODE Head)
{
	PNODE temp = Head;
    int a=0,n1=0;
    PNODE targeted = NULL;
	
	while(temp!=NULL)
	{
		n1 = temp->data;
		targeted = temp->next;
		while(targeted!=NULL)
		{
			if((targeted->data) > n1)
			{
				a = n1;
				n1 = targeted->data;
				targeted->data = a;
				
				temp->data = n1;
			}
			targeted = targeted->next;
		}
		
		temp = temp->next;
	}

}


void Display(PNODE Head)
{
    while(Head!=NULL)
    {
    	printf("|%d| -> ",Head->data);
    	Head = Head -> next;
    }
    printf("NULL\n");
}


int main()
{
	PNODE first = NULL;
	InsertFirst(&first,21);
	InsertFirst(&first,101);
	InsertFirst(&first,11);
	InsertFirst(&first,51);
	InsertFirst(&first,71);
	Display(first);
    
    printf("Ascending order ->\n");
	Ascending_Sort(first);
	Display(first);
  
    printf("Descending order ->\n");
	Descending_Sort(first);
	Display(first);


	return 0;
}