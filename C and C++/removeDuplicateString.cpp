/* 
Given a string which only contains lowercase. You need delete the repeated letters only leave one, and try to make the lexicographical order of new string is smallest. 
i.e: 
bcabc 
You need delete 1 'b' and 1 'c', so you delete the first 'b' and first 'c', the new string will be abc which is smallest. 

ps: If you try to use greedy algorithm to solve this problem, you must sure that you could pass this case: 
cbacdcbc. answer is acdb not adcb 

I can't solve this problem well and the interviewer said that you can scan the string twice. First scan is do some preprocess, and the second is to get the answer, but I really can't come up this idea.
*/

#include<iostream>
using namespace std;
#include<ctype.h>
#include<string.h>

void createDictionary(char *str,int dictionary[26])
{
	int i=0;
	while(str[i]!='\0')
	{
		dictionary[str[i]-'a']++;
		i++;
	}
}

void printDictionary(int dictionary[26])
{
	for(int i=0;i<26;i++)
	{
		cout<<(char)('a'+i)<<" "<<dictionary[i]<<" ";
	}
	cout<<endl;
}

char* removeDuplicates(char *str,int dictionary[26])
{
	char *result=new char[strlen(str)];
	for(int k=0;str[k]!='\0';k++)
	{
		for(int i='a';i<='z';i++)
		{
			int tempDict[26]={0};
			int j=k;
			while(str[j]!=i && str[j]!='\0')
			{
				if(isalpha(str[j]))
				{
					int index=str[j]-'a';
					tempDict[index]++;
					if(dictionary[index]-tempDict[index]==0)
					{
						break;
					}
				}
				j++;				
			}
			if(str[j]==i)
			{
				if(str[j+1]=='\0' && dictionary[str[j]-'a']>1)
				{
					dictionary[str[j]-'a']--;
					str[j]=' ';
				}
				for(;k<j;k++)
				{
					dictionary[str[k]-'a']--;
					str[k]=' ';
				}
				break;
			}
		}
	}
	int j=0;
	for(int i=0;i<strlen(str);i++)
	{
		if(isalpha(str[i]))
		{
			result[j]=str[i];
			j++;
		}
	}
	result[j]='\0';
	return result;
}

int main()
{
	char str[]="cbacdcbc";
	int dictionary[26]={0};
	createDictionary(str,dictionary);
	printDictionary(dictionary);
	char *result=removeDuplicates(str,dictionary);
	cout<<result;
	return 0;
}
