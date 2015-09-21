/*  
Given an array consisting of N Numbers. 
Divide it into two Equal(it is important) partitions (in size both contains N/2 elements) such that difference between sum of both partitions is minimum. 

If number of elements are odd difference in partition size can be at most 1.
*/

#include<iostream>
using namespace std;

void getSubset(int arr[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
	}
	int dp[n+1][sum/2+1][(n+1)/2+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=sum/2;j++)
		{
			for(int k=0;k<=(n+1)/2;k++)
			{
				if(j==0 && k==0)
				{
					dp[i][j][k]=1;
				}
				else
				{
					dp[i][j][k]=0;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum/2;j++)
		{
			for(int k=1;k<=(n+1)/2;k++)
			{
				if(j-arr[i]>=0)
				{
					dp[i][j][k]=dp[i-1][j-arr[i]][k-1] || dp[i-1][j][k];
				}
				else
				{
					dp[i][j][k]=dp[i-1][j][k];
				}
			}
		}
	}
	int j;
	for(j=sum/2;j>=0;j--)
	{
		if(dp[n][j][(n+1)/2])
		{
			break;
		}
	}
	cout<<"Sum: "<<j<<endl;
	int k=(n+1)/2,i=n;
	while(i>0 && dp[i][j][k])
	{
		if(j-arr[i]>=0)
		{
			if(dp[i-1][j-arr[i]][k-1])
			{
				cout<<arr[i]<<" ";
				k--;
				j=j-arr[i];
			}
		}
		i--;
	}
	cout<<endl;
}
int main()
{
	int arr[]={7,1,6,10,1};
	int n=sizeof(arr)/4;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	getSubset(arr,n);
	return 0;
}
