/*
http://www.geeksforgeeks.org/dynamic-programming-set-12-longest-palindromic-subsequence/

Given a sequence, find the length of the longest palindromic subsequence in it. For example, if the given sequence is “BBABCBCAB”, then the output should be 7 as “BABCBAB” is the longest palindromic subseuqnce in it. “BBBBB” and “BBCBB” are also palindromic subsequences of the given sequence, but not the longest ones.
*/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int lps ( string s );

int main()
{	string s;
	cin>>s;
	cout<<"lps: "<<lps(s)<<endl;
	return 0;
}

int lps ( string s )
{	int n=s.length();
	int a[n+2][n+2];
	memset(a,0,sizeof(a));
	for ( int i=1; i<=n; i++ )
		a[i][i]=1;
	for ( int i=n; i>0; i-- )
	{	for ( int j=i+1; j<=n; j++ )
		{	if ( s[i-1] == s[j-1] )
				a[i][j] = 2  + a[i+1][j-1];
			else
				a[i][j] = a[i+1][j] > a[i][j-1] ?  a[i+1][j] :  a[i][j-1];
		}
	}
	/*
	for ( int i=1; i<=n; i++ )
	{	for ( int j=1; j<=n; j++ )
			printf("%d ", a[i][j]);
		printf("\n");
	}
	*/
	return a[1][n];
}
