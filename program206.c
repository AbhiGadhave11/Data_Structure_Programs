#include <stdio.h>
#include<stdlib.h>

struct node
{
	int Data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE Head,int no)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(PNODE));
	newn->Data = no;
	newn->next = NULL;
	if(*Head==NULL)
	{
		*Head = newn;
	}
	else
	{
		newn->next = *Head;
		*Head = newn;
	}

}

void InsertLast(PPNODE Head,int no)
{
	
	PNODE newn = NULL;
	PNODE temp = *Head;
	newn = (PNODE)malloc(sizeof(PNODE));
	newn->Data = no;
	newn->next = NULL;
	if(*Head==NULL)
	{
		*Head = newn;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
	}
}

void Display(PNODE Head)
{
	while(Head!=NULL)
	{
		printf("%d\t",Head->Data);
		//printf("%u\n",Head->next);
		Head = Head->next;
	}
}

int Count(PNODE Head)
{
	int iCnt=0;
	while(Head!=NULL)
	{
		iCnt++;
		Head = Head->next;
	}
	return iCnt;
}

void DeleteFirst(PPNODE Head)
{
	if(*Head == NULL)
	{
		return;
	}
	else
	{
		PNODE temp = *Head;
		*Head = (*Head)->next;
		free(temp);
	}
}

void DeleteLast(PPNODE Head) // LL is empty
{
	PNODE temp = *Head;
	if(*Head==NULL)
	{
		return;
	}
	else if(((*Head)->next)==NULL)
	{
		free(*Head);
		*Head = NULL;
	}
	else
	{
		while(temp->next->next!=NULL)
		{
			temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;
	}
}

int main()
{
    PNODE first = NULL;
    int iRet = 0;
    
    InsertFirst(&first,101);
    InsertFirst(&first,51);  //InsertFirst(50,51);
    InsertFirst(&first,21);  //InsertFirst(50,51);
    InsertFirst(&first,11);  //InsertFirst(50,51);
    printf("\nInserted elements are\n");
    Display(first);
    printf("\n");
    iRet = Count(first);
    printf("Count of node is : %d\n",iRet);

    InsertLast(&first,111);
    printf("\nLast Inserted element is: \n");
    Display(first);
    printf("\n");
    iRet = Count(first);
    printf("Count of node is : %d\n",iRet);

    DeleteFirst(&first);
    printf("\nDeleteFirst element : \n");
    Display(first);
    printf("\n");
    iRet = Count(first);
    printf("Count of node is : %d\n",iRet);

    DeleteLast(&first);
    printf("\nDeleteLast element : \n");
    Display(first);
    printf("\n");
    iRet = Count(first);
    printf("Count of node is : %d\n",iRet);
    printf("\n");

    return 0;
}

/*
  void InsertFirst(PPNODE Head,int no)
  void InsertLast(PPNODE Head,int no)
  void InsertAtPos(PPNODE Head,int no,int pos)
  
  void DeleteFirst(PPNODE Head)
  void DeleteLast(PPNODE Head)
  void DeleteAtPos(PPNODE Head,int pos)
 
  
  void Display(PNODE Head)
  int Count(PNODE Head)
*/
