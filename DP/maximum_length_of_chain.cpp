/*
http://www.geeksforgeeks.org/dynamic-programming-set-20-maximum-length-chain-of-pairs/

You are given n pairs of numbers. In every pair, the first number is always smaller than the second number. A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. Find the longest chain which can be formed from a given set of pairs.
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;


struct inter
{	int s,e;
};

bool cmp ( struct inter a, struct inter b )
{	if ( a.s <= b.s )
		return 1;		// no effect of end since the two cant be scheduled together anyways
	return 0;
}

int lis ( struct inter *a, int n );

int main()
{	int n;
	cin>>n;
	inter a[n];
	for ( int i=0; i<n; i++ )
		cin>>a[i].s>>a[i].e;
	cout<<"maximum length of chain: "<<lis(a,n)<<endl;
	return 0;
}

int lis ( inter *a, int n )
{	sort(a,a+n,cmp);
	int max[n];
	memset(max,0,sizeof max);
	max[0]=1;
	for ( int i=1; i<n; i++ )
	{	for ( int j=i-1; j>=0; j-- )
			if ( a[i].s >= a[j].e )
			{	if ( max[j]+1 > max[i] )
					max[i]=max[j]+1;
			}
	}
	int mx=0;
	for (int i=0; i<n; i++ )
		if ( max[i] > mx )
			mx=max[i];
	return mx;
}
