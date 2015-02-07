/*
http://www.geeksforgeeks.org/dynamic-programming-set-9-binomial-coefficient/
Following are common definition of Binomial Coefficients.
1) A binomial coefficient C(n, k) can be defined as the coefficient of X^k in the expansion of (1 + X)^n.

2) A binomial coefficient C(n, k) also gives the number of ways, disregarding order, that k objects can be chosen from among n objects; more formally, the number of k-element subsets (or k-combinations) of an n-element set.

nCr + nCr-1 = n+1Cr
*/

#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int binomial( int n, int k );

int main()
{	int n,k;
	cin>>n>>k;
	cout<<binomial(n,k)<<endl;
	return 0;
}

int binomial( int n, int k )
{	int ncr[k+1];
        memset(ncr,0,sizeof(ncr));
	ncr[0]=1;	//nC0 = 1 for all
	for ( int i=1; i<=n; i++ )
	{	for ( int j=min(k,i); j>0; j-- )
			ncr[j]=ncr[j]+ncr[j-1];
		/*
		for ( int i=0; i<=k; i++ )
			printf("%d ",ncr[i]);
		printf("\n");
		*/
	}
	return ncr[k];
}
