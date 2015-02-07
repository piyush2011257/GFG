/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-152-kindle-team-sde-1/
Create Regular expression and String Matching program for ? and *, where. * means any null or character may appear instead *. and ? means one or more previous character may appear in string.
example
input :
AM*AZO?N*, AMAZON
AM*AZO?N*, ABAZOO
Both are matching as per rules of ? and *.

http://leetcode.com/2011/09/regular-expression-matching.html
*/

#include<cstdio>
using namespace std;

bool func ( char *str, char *pat, int s, int p );

int main()
{	char str[]="AMAZOOON";
	char pat[]="AM*AZO?N";
	printf("%d\n", func(str,pat,0,0));
	return 0;
}

bool func ( char *str, char *pat, int s, int p )
{	printf("s: %d p: %d\n",s,p);
	if ( str[s] == '\0' || pat[p] == '\0' )
	{	//printf("call1 %s %s %d %d %c %c\n", str, pat, s, p, str[s], pat[p]);
		if ( str[s] == '\0' && pat[p] == '\0' )
			return 1;
		return 0;
	}
	if ( pat[p] == '*' )
	{	//printf("call2\n");
		return ( func(str,pat,s,p+1) || func(str,pat,s+1,p+1) );
	}
	if ( pat[p+1] == '?' )
	{	printf("call2\n");
		char tmp=str[s];
		bool v1=0;
		while ( str[s] == tmp )
		{	v1 = v1 || ( func(str,pat,s+1,p+2) );
			if ( v1 == 1 )				// As soon we have a match stop
				return 1;
			s++;
		}		
	}
	else
	{	//printf("call3\n");
		if ( str[s] != pat[p] )
			return 0;
		return func ( str,pat,s+1,p+1);
	}
	return func(str,pat,s,p+2);
}

/* DP
func(s,j) = if string from str[s->len1-1] matched pattern[j->len2-1]
 We can further optimize by using memoization
*/
