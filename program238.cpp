#include<iostream>
using namespace std;

int SumArrayI(int Arr[],int iSize)
{
	int iSum=0;
	
    int i=0;
    while(i<iSize)
    {
        iSum = iSum + Arr[i];
        i++;
       
    }
	return iSum;
}

int SumArrayR(int Arr[],int iSize)
{
    static int iSum=0;
    int i=0;
    if(i<iSize)
    {
        iSum = iSum + Arr[i];
        i++;
        SumArrayR(Arr,iSize);
       
    }
    return iSum;
}

int main()
{
    int *ptr = NULL,iLength=0;
    int i=0;
    cout<<"Enter the size of array\n";
    cin>>iLength;
    
    ptr = new int[iLength];
    
    cout<<"Enter the Elements\n";
    for(i=0;i<iLength;i++)
    {
    	cin>>ptr[i];
    }

    int iRet = SumArrayI(ptr,iLength);
    cout<<"Sum of array Elements is : "<<iRet<<"\n";
    
    delete []ptr;

	return 0;
}