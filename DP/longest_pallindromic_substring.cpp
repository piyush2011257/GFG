/*
http://www.geeksforgeeks.org/longest-palindrome-substring-set-1/

Similar to Matrix Chain Multiplication
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

int lps ( string s );

int main()
{	string str;
	cin>>str;
	cout<<"lps: "<<lps(str)<<endl;
	return 0;
}

int lps ( string str )
{	int n=str.length(), max=0;
	bool a[n][n];
	memset(a,0,sizeof(a));
	for ( int i=0; i<n; i++ )
		a[i][i]=1;
	for ( int i=n-1; i>=0; i-- )
	{	for ( int j=i; j<n; j++ )
		{	if ( str[i] == str[j] )
			{	if ( i+1 < n && j-1 >= i && i+1 <= j-1)
					a[i][j] = a[i+1][j-1];
				else
					a[i][j]=1;
			}
			else
				a[i][j]=0;
			if ( a[i][j] == 1 && j-i+1 > max )
				max=j-i+1;
		}
	}
	return max;
}

/*
Alternate way is-
f(i,j) = j-i+1 if i,j is pallindrome
	 else max { f(i+1,j) , f(i,j-1)}
*/
