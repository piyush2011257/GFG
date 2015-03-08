/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-176-sde-1/

http://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
Search in a sorted, pivot array

*/
#include<cstdio>
#include<iostream>
using namespace std;

int func ( int *a, int n, int ele );

int main()
{	int n, ele;
	cin>>n;
	int a[n];
	for ( int i=0; i<n; i++ )
		cin>>a[i];
	cin>>ele;
	cout<<"idx: "<<func(a,n,ele)<<endl;
	return 0;
}

int func ( int *a, int n, int ele )
{	int m,s=0,e=n-1;
	while ( s <= e )
	{	m=(s+e)/2;
		if ( a[m] == ele )
			return m;
		if ( a[s] <= a[m] )
		{	if  ( ele >= a[s] && ele < a[m] )
				e=m-1;
			else
				s=m+1;
		}
		else
		{	if ( ele <= a[e] && ele > a[m] )
				s=m+1;
			else
				e=m-1;
		}
	}
	return -1;
}

/* 
sorted and pivot
3 4 5 1 2
for for mid
any one side of the mid ( either left or right ) WILL be SORTED ALWAYS 
Based on sorted side and if the ele to be searched present in the sorted side range we make decision. Since all elements are sorted and then pivot we always find element if present
*/
