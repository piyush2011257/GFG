/*
http://www.geeksforgeeks.org/snapdeal-interview-experience-set-6-campus/
Overlapping paintings, find no. of paintings that can be seen distinctly, extreme co-ordinates of paintings are given!
*/

#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

struct interval
{	int s,e;
};

bool cmp ( struct interval a, struct interval b )
{	if ( a.s <= b.s )
		return 1;
	return 0;
}

int main()
{	int n;
	cin>>n;
	interval inter[n];
	for ( int i=0; i<n; i++ )
		scanf("%d %d",&(inter[i].s), &(inter[i].e));
	sort(inter, inter+n, cmp );
	//for ( int i=0; i<n; i++ )
	//	cout<<inter[i].s<<" "<<inter[i].e<<endl;
	int ct=0;
	int end;
	for ( int i=0; i<n;  )
	{	end=inter[i].e;
		int j=i+1;
		while ( j < n && inter[j].s < end )
		{	j++;
			if ( inter[j].e > end )
				end= inter[j].e;
			// Consider in tervals: {1,4}  {2,7}, {6,9}
		}
		if ( j == i+1 )			// no overlap at all
			ct++;
		//cout<<"i: "<<i<<" j: "<<j<<endl;
		i=j;
	}
	cout<<ct<<endl;
	return 0;
}
