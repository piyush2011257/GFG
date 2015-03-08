/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-175-sde/

Given a function rev(int i) which reverses the segment of array ar[] from 0-i, Implement a function sort() using rev().

1 2 3 5 6 4 ....
6 5 3 2 1 4 ...
4 1 2 3 5 6 ...
3 2 1 4 5 6 ...
1 2 3 4 5 6 ...

*/

#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

void rev ( int *a, int i );
int find_pos ( int *a, int n, int ele );
void func ( int *a, int n );

int main()
{	int n;
	cin>>n;
	int a[n];
	for ( int i=0; i<n; i++ )
		cin>>a[i];
	func(a,n);
	for ( int i=0; i<n; i++ )
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}

void rev ( int *a, int i )
{	int s=0, e=i;
	while ( s < e )
	{	a[s]=a[s]^a[e];
		a[e]=a[s]^a[e];
		a[s]=a[s]^a[e];
		s++, e--;
	}
}

int find_pos ( int *a, int n, int ele )
{	int i=0;
	while ( i < n && a[i] <= ele )
		i++;
	return i;
}

void func ( int *a, int n )
{	for ( int i=1; i<n; i++ )
	{	int pos=find_pos ( a, i, a[i]);
		rev(a,i-1);
		rev(a,i);
		rev(a,pos);
		rev(a,pos-1);
	}
}
