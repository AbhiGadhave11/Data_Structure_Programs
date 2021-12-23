#include<iostream>
using namespace std;

int SumI(int iNo)
{
	int iDigit=0,iSum=0;
	while(iNo>0)
	{
		iDigit = iNo % 10;
		iSum = iSum + iDigit;
		iNo = iNo / 10;
	}
	return iSum;
}

int SumR(int iNo)
{

	static int iSum = 0;
	if(iNo>0)
	{
		iSum = iSum + (iNo%10);
		iNo = iNo/10;
		 SumR(iNo);
	}
	return iSum;
}
int main()
{
	int iValue = 0,iRet = 0;
	cout<<"Enter Number\n";
	cin>>iValue;
	iRet = SumR(iValue);
	cout<<"Summation of Digits : "<<iRet<<"\n";

	return 0;
}