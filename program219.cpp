#include<iostream>
using namespace std;


void Swap(int *p,int *q)
{
	int temp = 0;
	temp = *p;
	*p = *q;
	*q = temp; 
}
int main()
{
    int x=0,y=0;

    cout<<"Enter first Number\n";
    cin>>x;

    cout<<"Enter second Number\n";
    cin>>y;
 

    cout<<"Value of x becomes : "<<x<<"\n";
    cout<<"Value of y becomes : "<<y<<"\n";
   
    Swap(&x,&y);

    cout<<"Value of x becomes : "<<x<<"\n";
    cout<<"Value of y becomes : "<<y<<"\n";

	return 0;
}