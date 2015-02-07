/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-153-sde1/
Q2. Given a string, write a program to find longest length palindrome from that given string. You can swap the characters of given string.

Longest pallindromic substring
http://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
*/

#include<cstdio>
#include<cstring>
using namespace std;

int main()
{	char ip[100];
	scanf("%s",ip);
	int n=strlen(ip);
	bool a[100][100];
	// isPalindrome(i,j)
	for ( int i=0; i<n; i++ )
		a[i][i]=1;
	for ( int i=n-2; i>=0; i-- )
	{	for ( int j=n-1; j>i; j-- )
		{	bool v1=0, v2=0, v3=0;
			if ( ip[i] == ip[j] )
			{	if ( i+1 <= j-1 && i+1 < n && j-1 >= 0 )
					if ( a[i+1][j-1] == 1 )
						v1=1;
			}
			a[i][j]= v1;			// we can calculate max substring here itself j-i+1
		}
	}
	for ( int i=0; i<n; i++ )
	{	for ( int j=0; j<n; j++ )
			printf("%d ", a[i][j]);
		printf("\n");
	}
	int len[100][100];
        for ( int i=0; i<n; i++ )
                len[i][i]=1;
        for ( int i=n-2; i>=0; i-- )
        {       for ( int j=i+1; j<n; j++ )
                {       int v1=0, v2=0, v3=0;
                        if ( a[i][j] == 1 )
                               v1= j-i+1;
                        if ( i+1 <=j && i+1 < n )
				v2=len[i+1][j];
			if ( j-1 >= i && j-1 >= 0 )
				v3=len[i][j-1];
			int t= v1 > v2 ? v1 : v2;
			t = t > v3 ? t : v3;
			len[i][j]= t;
                }
        }
        for ( int i=0; i<n; i++ )
        {       for ( int j=0; j<n; j++ )
                        printf("%d ", len[i][j]);
                printf("\n");
        }
	return 0;
}
