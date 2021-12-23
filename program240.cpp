#include<iostream>
#include<stdio.h>
using namespace std;

int Strlenx(char *str)
{
	int iCnt=0;
	while(*str!='\0')
	{
		iCnt++;
		str++;
	}
	return iCnt;
}

int StrlenR(char *str)
{
	static int iCnt=0;
	if(*str!='\0')
	{
		iCnt++;
		str++;
		Strlenx(str);
	}
	return iCnt;
}


int main()
{
	char Arr[20];
	int iRet = 0;
	cout<<"Enter the String\n";
	scanf("%[^'\n']s",Arr);

	iRet = StrlenR(Arr);
	cout<<"Length of String is : "<<iRet<<"\n";

	return 0;
}