/*
http://www.geeksforgeeks.org/dynamic-programming-set-10-0-1-knapsack-problem/
http://www.geeksforgeeks.org/dynamic-programming-subset-sum-problem/
Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
*/

#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int subset_sum ( int *s, int n, int cap );

int main()
{	int n, cap;
	cin>>n>>cap;
	int a[n];
	for ( int i=0; i<n; i++ )
		cin>>a[i];
	cout<<"subset_sum: "<<subset_sum(a,n,cap)<<endl;
	return 0;
}

int subset_sum ( int *s, int n, int cap )
{       bool a[cap+1][n+1], v1, v2;
        memset(a,0,sizeof(a));
	for ( int i=0; i<n; i++ )
		a[0][i]=1;			// capacity=0 and stil left
	for ( int i=1; i<=cap; i++ )
		a[i][0]=0;			// capacity != 0 and none left
        for ( int i=0; i<=cap; i++ )
        {       for ( int j=1; j<=n; j++ )
                {       v2=0;
                        v1=a[i][j-1];
                        if ( i - s[j-1] >= 0 )
                                v2=a[i-s[j-1]][j-1];
                        a[i][j]= v1 ||  v2;
                }
        }
        /*
        for ( int i=0; i<=cap; i++ )
        {       for ( int j=1; j<=n; j++ )
                        printf("%d ", a[i][j]);
                printf("\n");
        }
        */
        return a[cap][n];
}
