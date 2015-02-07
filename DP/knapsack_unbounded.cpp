/*
http://karmaandcoding.blogspot.in/2012/02/dynamic-programming-unbounded-knapsack.html
*/

#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int knapsack ( int *s, int *val, int n, int cap );

int main()
{	int n, cap;
	cin>>n>>cap;
	int a[n], val[n];
	for ( int i=0; i<n; i++ )
		cin>>a[i]>>val[i];
	cout<<"max value: "<<knapsack(a,val,n,cap)<<endl;
	return 0;
}

int knapsack ( int *s, int *val, int n, int cap )
{	int a[cap+1], max, max_val;
	memset(a,0,sizeof(a));
	for ( int i=1; i<=cap; i++ )
	{	max=0;
		for ( int j=0; j<n; j++ )
		{	if ( i-s[j] >= 0 )
			{	if ( a[i-s[j]]+val[j] > max )
					max=a[i-s[j]]+val[j];
			}
		}
		a[i]=max > a[i-1] ? max : a[i-1];
	}
	return a[cap];
}
