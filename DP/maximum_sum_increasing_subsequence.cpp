/*
http://www.geeksforgeeks.org/dynamic-programming-set-3-longest-increasing-subsequence/

http://www.geeksforgeeks.org/dynamic-programming-set-14-maximum-sum-increasing-subsequence/\
Given an array of n positive integers. Write a program to find the sum of maximum sum subsequence of the given array such that the intgers in the subsequence are sorted in increasing order. For example, if input is {1, 101, 2, 3, 100, 4, 5}, then output should be 106 (1 + 2 + 3 + 100), if the input array is {3, 4, 5, 10}, then output should be 22 (3 + 4 + 5 + 10) and if the input array is {10, 5, 4, 3}, then output should be 10 

*/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int msis ( int *a, int n );

int main()
{	int n;
	cin>>n;
	int a[n];
	for ( int i=0; i<n; i++ )
		cin>>a[i];
	cout<<msis(a,n)<<endl;
	return 0;
}

int msis ( int *a, int n )
{	int max[n];
	memset(max,0,sizeof max);
	max[0]=a[0];
	for ( int i=1; i<n; i++ )
	{	for ( int j=i-1; j>=0; j-- )
			if ( a[i] > a[j] )
			{	if ( max[j]+a[i] > max[i] )
					max[i]=max[j]+a[i];
			}
	}
	int mx=0;
	for (int i=0; i<n; i++ )
		if ( max[i] > mx )
			mx=max[i];
	return mx;
}
