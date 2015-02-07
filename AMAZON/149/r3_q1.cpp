/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-149-campus-internship/
Given a string, find the longest substring without repeating characters. For example, the longest substrings without repeating characters for “ABDEFGABEF” are “BDEFGA” and “DEFGAB”.

http://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/
Given a string, find the length of the longest substring without repeating characters. For example, the longest substrings without repeating characters for “ABDEFGABEF” are “BDEFGA” and “DEFGAB”, with length 6. For “BBBB” the longest substring is “B”, with length 1. For “GEEKSFORGEEKS”, there are two longest substrings shown in the below diagrams, with length 7. 
*/

#include<cstdio>
using namespace std;

int main()
{	char str[]="aaaaaaabbbbb";
	int pos[26];
	for ( int i=0; i<26; i++ )
		pos[i]=-1;
	int start, end, mx=1, start_mx, end_mx;
	start=end=start_mx=end_mx=0;
	pos[str[0]-'a']=0;					// Corner Case. This initialization. For strings like "aa"
	for ( int i=1; str[i] != '\0'; i++ )
	{	printf("%d %d %d %c\n", start,end, pos[str[i]-'a'], str[i]);
		if ( pos[str[i]-'a'] >= start )
		{	printf("Call\n");
			if ( end-start > mx )
			{	printf("called\n");
				mx=end-start;
				start_mx=start;
				end_mx=end-1;			// mis-match at i !!
			}
			start=pos[str[i]-'a']+1;
		}
		pos[str[i]-'a']=i;
		end=i;
	}
	if ( end-start+1 > mx )					// Corner Case here -> +1
	{	mx=end-start+1;
		start_mx=start;
		end_mx=end;
	}
	printf("%d %d %d\n", mx, start_mx, end_mx);
	return 0;
}

