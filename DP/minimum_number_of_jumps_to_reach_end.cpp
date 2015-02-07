/*
http://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/
Given an array of integers where each element represents the max number of steps that can be made forward from that element. Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.
*/
#include<cstdio>
#include<iostream>
#include<climits>
using namespace std;

int min_jump ( int *a, int n );

int main()
{	int n;
	cin>>n;
	int a[n];
	for ( int i=0; i<n; i++ )
		scanf("%d",a+i);
	cout<<"minimum jump: "<<min_jump(a,n)<<endl;
	return 0;
}

int min_jump ( int *a, int n )
{	int val[n], pos[n], lt, min, ps;
	val[n-1]=0;
	pos[n-1]=0;
	for ( int j=n-2; j>=0; j-- )
	{	val[j]=INT_MAX;
		pos[j]=-1;
		lt=a[j] < n-1-j ? a[j] : n-1-j;
		min=INT_MAX;
		ps=-1;
		for ( int i=1; i<=lt; i++ )
		{	if ( val[j+i] < min )
			{	min=val[j+i];
				ps=i;
			}
		}
		if ( ps != -1 )
		{	val[j]=min+1;
			pos[j]=ps;
		}
	}
	if ( val[0] != INT_MAX )
	{	ps=0;
		while ( ps != n-1 )
		{	printf("%d ", a[ps],ps);
			ps += pos[ps];
		}
		printf("%d\n", a[n-1]);
	}
	return val[0];
}
