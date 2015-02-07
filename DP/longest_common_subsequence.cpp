/*
http://www.geeksforgeeks.org/dynamic-programming-set-4-longest-common-subsequence/
iven two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”. So a string of length n has 2^n different possible subsequences.

http://www.geeksforgeeks.org/printing-longest-common-subsequence/
*/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int lcs ( string s1, string s2 );

int main()
{	string s1,s2;
	cin>>s1>>s2;
	cout<<lcs(s1,s2)<<endl;
	return 0;
}

int lcs ( string s1, string s2 )
{	int n=s1.length();
	int m=s2.length();
	int a[n+1][m+1];
	memset(a,0,sizeof(a));
	/*
	for ( int i=0; i<n; i++ )
	{	for ( int j=0; j<m; j++ )
			printf("%d ",a[i][j]);
		printf("\n");
	}
	*/
	for ( int i=n-1; i>=0; i-- )
	{	for ( int j=m-1; j>=0; j-- )
		{	//printf("%d %d ",i,j);
			//cout<<s1[i]<<" "<<s2[j]<<" "<<a[i+1][j+1]<<endl;
			if ( s1[i] == s2[j] )
			{	//printf("equal\n");
				a[i][j] = 1 + a[i+1][j+1];
			}
			else
			{	//printf("not equal\n");
				a[i][j]=a[i][j+1] > a[i+1][j] ? a[i][j+1] : a[i+1][j];
			}
		}
	}
	/*
	for ( int i=0; i<n; i++ )
	{	for ( int j=0; j<m; j++ )
			printf("%d ",a[i][j]);
		printf("\n");
	}
	*/
	// print the lcs
	{	cout<<"lcs: ";
		int i=0, j=0;
		while ( i != n && j != m )
		{	if ( s1[i] == s2[j] )
			{	cout<<s1[i];
				i++;
				j++;
			}
			else
			{	if ( a[i+1][j] > a[i][j+1] )
					i++;
				else
					j++;
			}
		}
		cout<<endl;
	}
	return a[0][0];
}	
