//We know a string is Palindrome if it is the same reading from both sides. Now we define the following string also Palindrome:
//A man, a plan, a canal, Panama! 
#include<iostream>
using namespace std;
#include<string.h>
#include<ctype.h>

int isPalindrome(char *str)
{
	int len=strlen(str);
	int s=0,e=len-1;
	while(s<e)
	{
		while(!isalpha(str[s])&&!isdigit(str[s]))
		{
			s++;
		}
		while(!isalpha(str[e])&&!isdigit(str[e]))
		{
			e--;
		}
		char l=isalpha(str[s])?toupper(str[s]):str[s];
		char r=isalpha(str[e])?toupper(str[e]):str[e];
		if(l==r)
		{
			s++;
			e--;
		}
		else
		{
			break;
		}
	}
	if(s<e)
		return 0;
	return 1;
}
int main()
{
	char *str="A man, a plan, a canal, Panama!!";
	cout<<isPalindrome(str);
	return 0;
}


