/*  
Given unsigned integer 'x', write an algorithm thet returns unsigned integer 'y' such that it has the same number of bits set as 'x' and is not equal to 'x' and the distance |x-y| is minimized. 

Example: 
x: 01 
y: 10 

Note that one bit is set and 'x' is not equal 'y'. You may assume that x is positive integer between zero and 2^32-2;
*/

#include<iostream>
using namespace std;

void getBinary(int a)
{
	int i=31;
	char ch[33]="00000000000000000000000000000000";
	while(a!=0)
	{
		ch[i--]=(char)((a&1)+'0');
		a=a>>1;
	}
	cout<<ch<<endl;
}

int getNearestNumber(int a)
{
	int leastBit=a&1,i=0;
	for(int b=a;b&1==leastBit && i<32;b=b>>1,i++);
	if(i<32)
	{
		if(leastBit==0)
		{
			a=a&~(1<<i);
			a=a|(1<<(i-1));
		}
		else
		{
			a=a&~(1<<i-1);
			a=a|(1<<(i));
		}
	}
	return a;
}

int main()
{
	int a=81;
	getBinary(a);
	int ans=getNearestNumber(a);
	getBinary(ans);
	return 0;
}
