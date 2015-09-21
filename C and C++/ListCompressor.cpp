/*
Number list compressing. 
Given an sorted array. Input: sorted number list 
 1, 2, 3,10, 25, 26, 30, 31, 32, 33 

 Output: find consecutive segments 
 print: 1-3, 10, 25-26, 30-33
*/

#include<iostream>
using namespace std;
int getIndex(int a[],int n,int s)
{
	int i=s;
	while(i<n && a[i]==i-s+a[s])
	{
		i++;
	}
	return (i==s)?i:i-1;
}
int main()
{
	int a[]={1, 2, 3,10, 25, 26, 30, 31, 32, 33 };
	int n=sizeof(a)/sizeof(int);
	for(int i=0;i<n;i++)
	{
		int index=getIndex(a,n,i);
		cout<<a[i];
		if(index!=i)
		{
			cout<<'-'<<a[index];
			i=index;
		}
		cout<<";";
		
	}
	return 0;
}

