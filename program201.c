#include<stdio.h>
#include<stdlib.h>

struct node
{
	int Data;
	struct node *next;
};
int main()
{
       printf("%d\n",sizeof(struct node));
	return 0;
}