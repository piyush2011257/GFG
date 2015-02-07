/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-173-campus/
You are given an array of both negative and positive integers. You need to rearrange the array such that positive and negative numbers alternate. Also, the order should be same as previous array and only O(1) auxiliary space can be used and time complexity O(n).
eg. -2 3 4 5 -1 -6 7 9 1
result – 3 -2 4 -1 5 -6 7 9 1.

http://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers-publish/

The above problem can be easily solved if O(n) extra space is allowed. It becomes interesting due to the limitations that O(1) extra space and order of appearances.
The idea is to process array from left to right. While processing, find the first out of place element in the remaining unprocessed array. An element is out of place if it is negative and at odd index, or it is positive and at even index. Once we find an out of place element, we find the first element after it with opposite sign. We right rotate the subarray between these two elements (including these two).
*/

#include<cstdio>
#include<iostream>
using namespace std;

int main()
{	int n,t;
	cin>>n;	
	int a[n], ct_zero=0;
	for ( int i=0,j=0; i<n; i++ )
	{	cin>>t;
		if ( t == 0 )
			ct_zero++;
		else
			a[j++]=t;
	}
	// Assume PNPNPNPN....0000 format P-+ve N-negative
	int N=n-ct_zero;
	int low=0, top=N-1;
	while ( low <= top )
	{	while ( low < N && a[low] < 0 )
			low++;
		while ( top >=0 && a[top] > 0 )
			top--;
		if ( low < top )
		{	a[low]=a[low]^a[top];
			a[top]=a[low]^a[top];
			a[low]=a[low]^a[top];
		}
	}				// quick sort paritioning using 0 as pivot. Adding 0 at the end
	if ( ct_zero > 0 )
		for ( int i=N, j=0; j<ct_zero; j++,i++ )
			a[i]=0;
	for ( int i=0; i<n; i++ )
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
