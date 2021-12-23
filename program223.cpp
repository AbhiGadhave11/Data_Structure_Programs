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
    T temp;
    
    temp = *p;
    *p = *q;
    *q = temp; 
}


int main()
{
    char x='A',y='B';
    cout<<"Value of x becomes : "<<x<<"\n";
    cout<<"Value of y becomes : "<<y<<"\n";
    cout<<"**********************\n";
    SwapX(&x,&y);
    cout<<"Value of x becomes : "<<x<<"\n";
    cout<<"Value of y becomes : "<<y<<"\n\n";

    int i=11,j=21;
    cout<<"Value of i becomes : "<<i<<"\n";
    cout<<"Value of j becomes : "<<j<<"\n";
    cout<<"***********************\n";
    SwapX(&i,&j);
    cout<<"Value of i becomes : "<<i<<"\n";
    cout<<"Value of j becomes : "<<j<<"\n";

	return 0;
}