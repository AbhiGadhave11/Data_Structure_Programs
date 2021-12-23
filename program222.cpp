#include<iostream>
using namespace std;


//specific Function        
void Swap(char *p,char *q)
{
	char temp = '\0';
	
	temp = *p;
	*p = *q;
	*q = temp; 
}

// Generic Function
template<class T>
void SwapX(T *p,T *q)
{
    T temp = '\0';
    
    temp = *p;
    *p = *q;
    *q = temp; 
}


int main()
{
    char x='\0',y='\0';

    cout<<"Enter first Number\n";
    cin>>x;

    cout<<"Enter second Number\n";
    cin>>y;
 

    cout<<"Value of x becomes : "<<x<<"\n";
    cout<<"Value of y becomes : "<<y<<"\n";
   
    cout<<"*********************************\n";
    SwapX(&x,&y);

    cout<<"Value of x becomes : "<<x<<"\n";
    cout<<"Value of y becomes : "<<y<<"\n";

	return 0;
}