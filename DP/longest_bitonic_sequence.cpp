/*
http://www.geeksforgeeks.org/dynamic-programming-set-15-longest-bitonic-subsequence/
Given an array arr[0 … n-1] containing n positive integers, a subsequence of arr[] is called Bitonic if it is first increasing, then decreasing. Write a function that takes an array as argument and returns the length of the longest bitonic subsequence.
A sequence, sorted in increasing order is considered Bitonic with the decreasing part as empty. Similarly, decreasing order sequence is considered Bitonic with the increasing part as empty.

Strictly increasing and decreasing

My logic
Similar to Longest Pallindromic Subsequence
isbitonic(i,j)

isbotinic(i,i)=1 	for all i belongs to N
isbitonic(i,i+1)=1	a[i] > a[i+1] || a[i] < a[i+1]		strictly increasing or decreasing is also bitonic
The above logic fails further
since
for
isbitonic(i,j) we do not know if i+1,j-1 is strictly increasing / decreasing or increasing then decreasing
Hence this logic cannot be used
*/

#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int lbs ( int *a, int n );

int main()
{	int n;
	cin>>n;
	int a[n];
	for ( int i=0; i<n; i++ )
		cin>>a[i];
	cout<<"longest bitonic subsequence: "<<lbs(a,n)<<endl;
	return 0;
}

int lbs ( int *a, int n )
{	int lis_left[n], lis_right[n], max;
	memset(lis_left,0,sizeof(lis_left));
	memset(lis_right,0,sizeof(lis_right));
	lis_left[0]=1;
	for ( int i=1; i<n; i++ )
	{	max=0;
		for ( int j=i-1; j>=0; j-- )
		{	if ( a[j] < a[i] && lis_left[j] > max )
				max=lis_left[j];
		}
		lis_left[i]=max+1;
	}
	lis_right[n-1]=1;
	for ( int i=n-2; i>=0; i-- )
        {       max=0;
                for ( int j=i+1; j<n; j++ )
                {       if ( a[j] < a[i] && lis_right[j] > max )
                                max=lis_right[j];
                }
                lis_right[i]=max+1;
        }
	/*
	for ( int i=0; i<n; i++ )
		cout<<lis_left[i]<<" ";
	cout<<endl;
        for ( int i=0; i<n; i++ )
                cout<<lis_right[i]<<" ";
        cout<<endl;
	*/
	max=0;
	for ( int i=0; i<n; i++ )
		if ( lis_left[i] + lis_right[i]-1 > max )
			max= lis_left[i] + lis_right[i] -1;
	return max;
}
