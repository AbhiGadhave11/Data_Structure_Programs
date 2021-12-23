#include<iostream>
#include<stdio.h>
using namespace std;

int CountChar(char *str)
{
	int iCnt = 0;
	while(*str!='\0')
	{
		if(*str>='A'&&*str<='Z')
		{
			iCnt++;
		}
		str++;
	}
	return iCnt;
}
int main()
{
	char Arr[20];
	int iRet = 0;
	cout<<"Enter the String\n";
	scanf("%[^'\n']s",Arr);

	iRet = CountChar(Arr);
	cout<<"Capital letters are : "<<iRet<<"\n";

	return 0;
}