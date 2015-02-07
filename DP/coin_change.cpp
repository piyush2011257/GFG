/*
http://karmaandcoding.blogspot.in/2012/02/dynamic-programming-unbounded-knapsack.html

http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/
Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.

To count total number solutions, we can divide all set solutions in two sets.
1) Solutions that do not contain mth coin (or Sm).
2) Solutions that contain at least one Sm.
Let count(S[], m, n) be the function to count the number of solutions, then it can be written as sum of count(S[], m-1, n) and count(S[], m, n-Sm).

f(C,n) = f(C-s[n],n-1) + f(C,n-1)

BUT-

f(C) = (sum i=1 -> n) f(C-s[i])
consider sample i/p be-
3 4
1 2 3

a[]- 1 1 2 4 7
aa[3]=4 wrong
{1,1,1}
{1,2}
{2,1}			repeat since we did not take care of the ordering
{3}
*/

#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int knapsack ( int *s, int n, int cap );

int main()
{	int n, cap;
	cin>>n>>cap;
	int a[n];
	for ( int i=0; i<n; i++ )
		cin>>a[i];
	cout<<"max value: "<<knapsack(a,n,cap)<<endl;
	return 0;
}

int knapsack ( int *s, int n, int cap )
{	int a[cap+1][n+1], sum;
	memset(a,0,sizeof(a));
	for ( int i=0; i<n; i++ )
		a[0][i]=1;
	for ( int i=1; i<=cap; i++ )		// a[0][0]=1
		a[i][0]=0;
	for ( int i=1; i<=cap; i++ )
	{	for ( int j=1; j<=n; j++ )
		{	if ( i-s[j-1] >= 0 )
				a[i][j] = a[i-s[j-1]][j] + a[i][j-1];
			else
				a[i][j] =a[i][j-1];
		}
	}
	/*
	for ( int i=0; i<=cap; i++ )
	{	for ( int j=1; j<=n; j++ )
			printf("%d ", a[i][j]);
		printf("\n");
	}
	*/
	return a[cap][n];
}
