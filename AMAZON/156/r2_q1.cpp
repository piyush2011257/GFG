/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-156-campus/
http://www.geeksforgeeks.org/dynamic-programming-set-32-word-break-problem/

http://www.geeksforgeeks.org/dynamic-programming-set-32-word-break-problem/
Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated sequence of dictionary words. 
http://www.programcreek.com/2012/12/leetcode-solution-word-break/
*/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

bool func ( string ip_str, int index, int len, string str[] );

int main()
{	int d;
	scanf("%d",&d);
	string str[d];
	for ( int i=0; i<d; i++ )
		cin>>str[i];
	string ip_str;
	cin>>ip_str;
	cout<<func(ip_str, 0, d, str )<<endl;
	return 0;
}

/* Without memoization */
bool func ( string ip_str, int index, int len, string str[] )
{	int n=ip_str.length();
	if ( index >= n )
                return 1;
        for ( int i=0; i<len; i++ )
	{	int temp_index=index;
		if ( temp_index + str[i].length() <= n )
		{	string c=ip_str.substr(temp_index, str[i].length());
			if ( str[i].compare(c) == 0 )
			{	temp_index+=str[i].length();
				if ( func(ip_str,temp_index,len,str) == 1 )
				{	cout<<c<<endl;
					return 1;
				}
			}
		}
	}
	return 0;
}
