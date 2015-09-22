/*
Given n light bulbs, write two methods. 

isOn(i) to determine if a light bulb is on 
toggle(start, end) to toggle all the light bulbs in the range 

One caveat, write toggle so that it is less than O(n) complexity
*/

#include<iostream>
using namespace std;
#include<string.h>

const int n=30;
char str[n/8 + 2]="";

void printBoolean(char ch)
{
	char ans[9];
	for(int i=0;i<8;i++)
	{
		ans[i]=(ch&1)+'0';
		ch=ch>>1;
	}
	ans[8]='\0';
	cout<<strrev(ans);
}
void onBulb(int i)
{
	if(i>=0 && i<n)
	{
		str[i/8]=str[i/8]|(1<<(i%8));
	}
}

int isOn(int i)
{
	if(i>=0 && i<n)
	{
		return (str[i/8]&1<<(i%8))!=0;
	}
	return 0;
}

void toggle(int start, int end)
{
	int startIndex=start/8,endIndex=end/8;
	if(startIndex!=endIndex)
	{
		char temp=(~(str[endIndex]<<(7-(end%8))))>>(7-(end%8));
		str[endIndex]=((str[endIndex]>>((end%8)+1))<<((end%8)+1)) | temp;
		temp=(~(str[startIndex]>>(start%8)))<<(start%8);
		str[startIndex]=((str[startIndex]<<(7-(start%8))))>>(7-(start%8)) | temp;
		for(int i=startIndex+1;i<endIndex;i++)
		{
			str[i]=255;
		}
	}
	else
	{
		char temp1=~(((((~str[startIndex])<<(7-(end%8)))>>(7-(end%8)))>>(start%8))<<(start%8));
		char temp2=((str[endIndex]>>((end%8)+1))<<((end%8)+1));
		char temp3=((str[startIndex]<<(7-(start%8))))>>(7-(start%8)) ;
		str[startIndex]=temp1|temp2|temp3;
	}
}

int main()
{
	for(int i=0;i<n/8 + 1;i++)
	{
		str[i]=0;
	}
	str[n/30 + 1]='\0';
	toggle(1,16);
	cout<<isOn(0);
	return 0;
}
