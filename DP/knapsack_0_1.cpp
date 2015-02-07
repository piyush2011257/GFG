/*
http://www.geeksforgeeks.org/dynamic-programming-set-10-0-1-knapsack-problem/
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
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
{	int a[cap+1][n+1], max, max_val, v1, v2;
	memset(a,0,sizeof(a));
	for ( int i=0; i<=cap; i++ )
	{	for ( int j=1; j<=n; j++ )
		{	v1=v2=0;
			if ( j-1 > 0 )
				v1=a[i][j-1];
			if ( i - s[j-1] >= 0 )
				v2=a[i-s[j-1]][j-1]+val[j-1];
			a[i][j]= v1 > v2 ? v1 : v2;
		}
	}
	/*
	for ( int i=0; i<=cap; i++ )
	{	for ( int j=1; j<=n; j++ )
			printf("%d ", a[i][j]);
		printf("\n");
	}
	*/
	max=0;
	for ( int i=1; i<=cap; i++ )
		if ( a[i][n] > max )
			max=a[i][n];
	return max;
}
