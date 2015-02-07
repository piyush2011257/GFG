/*
http://www.geeksforgeeks.org/dynamic-programming-set-3-longest-increasing-subsequence/
The longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order

http://www.codechef.com/wiki/tutorial-dynamic-programming#Problem_:_Longest_Increasing_subsequence
*/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int lis ( int *a, int n );

int main()
{	int n;
	cin>>n;
	int a[n];
	for ( int i=0; i<n; i++ )
		cin>>a[i];
	cout<<lis(a,n)<<endl;
	return 0;
}

int lis ( int *a, int n )
{	int max[n];
	memset(max,0,sizeof max);
	max[0]=1;
	for ( int i=1; i<n; i++ )
	{	for ( int j=i-1; j>=0; j-- )
			if ( a[i] > a[j] )
			{	if ( max[j]+1 > max[i] )
					max[i]=max[j]+1;
			}
	}
	int mx=0;
	for (int i=0; i<n; i++ )
		if ( max[i] > mx )
			mx=max[i];
	return mx;
}
		
