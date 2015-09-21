// paint a list of N houses and M colors, each combination has cost, minimize the total cost without color in row.

#include<iostream>
using namespace std;

int getMin(int dp[][4],int rowIndex,int columnIndex)
{
	int min=-1;
	for(int i=0;i<4;i++)
	{
		if(i!=columnIndex)
		{
			if(min==-1 || dp[rowIndex][min]>dp[rowIndex][i])
			{
				min=i;
			}
		}
	}
	return dp[rowIndex][min];
}
void getBestCost(int costMat[][4],int row)
{
	int dp[row][4];
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<4;j++)
		{
			dp[i][j]=0;
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=0;i<4;i++)
	{
		dp[0][i]=costMat[0][i];
		cout<<dp[0][i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<row;i++)
	{
		for(int j=0;j<4;j++)
		{
			dp[i][j]=getMin(dp,i-1,j)+costMat[i][j];
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}	
}
int main()
{
	int costMat[][4]={{10,2,1,6},{9,3,1,2},{7,5,8,9},{3,2,1,3}};
	getBestCost(costMat,4);
	return 0;
}
