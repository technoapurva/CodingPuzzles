/*  
You are given a list of n float numbers x_1, x_2, x_3, ... x_n, where x_i > 0. 
A traveler starts at point (0, 0) and moves x_1 metres to the north, then x_2 metres to the west, x_3 to the south, x_4 to the east and so on (after each move his direction changes counter-clockwise) 
Write an single-pass algorithm that uses O(1) memory to determine, if the travelers path crosses itself, or not (i.e. if it's self-intersecting) 
e.g. 
2 1 1 2 -> crosses 
1 2 3 4 -> doesn't cross
*/

#include<iostream>
using namespace std;

int isIntersect(double arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(i>=5 && arr[i-2]-arr[i-4]>0 && arr[i-1]-arr[i-3]+arr[i-5]>=0 && arr[i-1]-arr[i-3]<=0 && arr[i-2]-arr[i-4]-arr[i]<=0) 
		{
			return 1;
		}
		if(i>=3 && arr[i-1]<=arr[i-3] && arr[i]>=arr[i-2])
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	double arr[] = { 2, 2, 2, 1 }; // No cross
    //double arr[] = { 2, 2, 2, 2 }; // Cross
    //double arr[] = { 3, 2, 2, 3 }; // Cross
    //double arr[] = { 3, 3, 2, 2, 3 }; // Cross
    //double arr[] = { 2, 2, 4, 5, 1, 4 }; // No Cross
    //double arr[] = { 2, 2, 4, 5, 3, 4 }; // Cross
    //double arr[] = { 1, 2, 4, 5, 1, 4 }; // No Cross
    //double arr[] = { 0.5, 2, 2, 4, 5, 3, 4, 0.5 }; // Cross

	int n=sizeof(arr)/8;
	cout<<isIntersect(arr,n);
	return 0;
}
