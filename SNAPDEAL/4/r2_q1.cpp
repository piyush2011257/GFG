/*
www.geeksforgeeks.org/largest-sum-contiguous-subarray/
find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum.
*/
// Also called Kadane's Algorithm

#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int lcs ( int *a, int n );

int main()
{	int n;
	scanf("%d",&n);
	int a[n];
	for ( int i=0; i<n; i++ )
		cin>>a[i];
	//memset(a,0,sizeof a);
	cout<<"Largest consecutive / contigouos sum: "<<lcs(a,n)<<endl;
	return 0;
}

int lcs ( int *a, int n )
{	int old_sum=a[0], max_sum=a[0];
	for ( int i=1; i<n; i++ )
	{	if ( old_sum + a[i] >= 0 )
		{	old_sum=old_sum+a[i];
			if ( old_sum > max_sum )
				max_sum=old_sum;
		}
		else
		{	old_sum=0;
			if ( a[i] > max_sum )
				max_sum=a[i];
		}
	}
	return max_sum;
}
