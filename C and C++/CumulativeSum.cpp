/*  
You are given large numbers of logs, each one of which contains a start time (long), end time (long) and memory usage (int). The time is recorded as MMDDHH (100317 means October 3rd 5PM) Write an algorithm that returns a specific time (hour) when the memory usage is the highest. If there are multiple answers, return the first hour. 

e.g. 100207 100208 2 
 100305 100307 5 
 100207 100209 4 
 111515 121212 1 
Answer: 100207 

(Need to consider different scenarios like the time slots could be very sparse)
*/

#include<iostream>
using namespace std;

static const int MAX = 113023;

struct Input
{
	int start;
	int end;
	int load;
};

int getHighestUsage() {
	Input input[] = {{100207,100208,2},{100305,100307,5},{100207,100209,4},{111515,121212,1}};
	int n=sizeof(input)/sizeof(Input);
	int usage[MAX]={0};
	int max=0,result=0;
	for(int i=0;i<n;i++) {
		usage[input[i].start - 10101] += input[i].load;
		usage[input[i].end - 10101 + 1] -= input[i].load;
	}
	
	for (int i = 0; i < MAX; i++)
	{
		usage[i] += usage[i - 1];
		if (usage[i] > max) {
			result = i;
			max = usage[i];
		}
	}	

	return result + 10101;
}
int main()
{
	cout<<getHighestUsage();
	return 0;
}
