#include<iostream>
#include<stdio.h>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}NODE,*PNODE,**PPNODE;

void InsertFirst(PPNODE Head,int no)
{
	PNODE newn = NULL;
	newn = new NODE;
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

void Display(PNODE Head)
	{
         while(Head!=NULL)
         {
         	cout<<"|"<<Head->data<<"|-> ";
         	Head = Head->next;
         }
         cout<<"NULL\n";
	}

int Count(PNODE Head)
	{
		int iCnt = 0;
         while(Head!=NULL)
         {
         	iCnt++;
         	Head = Head->next;
         }
         return iCnt ;
	}	
int main()
{
	PNODE First = NULL;

    InsertFirst(&First,101);
    InsertFirst(&First,51);
    InsertFirst(&First,21);
    InsertFirst(&First,11);

    Display(First);
    int iRet = Count(First);
    cout<<"Number of nodes are : "<<iRet<<"\n";




	return 0;
}