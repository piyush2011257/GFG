/*
http://www.geeksforgeeks.org/dynamic-programming-set-8-matrix-chain-multiplication/
Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.
*/

#include<cstdio>
#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

int mcm ( int *p, int n );

int main()
{	int n;
	cin>>n;
	int p[n+1];
	for ( int i=0; i<=n; i++ )
		cin>>p[i];			// matrix i -> p(i) * p(i+1) dimensions
	cout<<"minimum multiplications: "<<mcm(p,n)<<endl;
	return 0;
}

int mcm ( int *p, int n )
{	int a[n+1][n+1], tmp, min;
	memset(a,0,sizeof (a));
	for ( int i=n-1; i>=0; i-- )
	{	for ( int j=i+1; j<n; j++ )
		{	min=INT_MAX;
			for ( int k=i; k<j; k++ )
			{	tmp=a[i][k] + a[k+1][j] + p[i]*p[k+1]*p[j+1];
				if ( tmp < min )
					min=tmp;
			}
			a[i][j]=min;
		}
	}
	for ( int i=0; i<n; i++ )
	{	for ( int j=0; j<n; j++ )
			printf("%d ", a[i][j]);
		printf("\n");
	}
	return a[0][n-1];
}
