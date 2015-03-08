/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-175-sde/

Given a function rev(int i) which reverses the segment of array ar[] from 0-i, Implement a function sort() using rev().

http://www.geeksforgeeks.org/pancake-sorting/

*/

#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

/*
Pancake sort based on Selection Sort- Pancake Sort
*/

void rev ( int *a, int i );
int find_max ( int *a, int n );
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

int find_max ( int *a, int n )
{	int pos=0;
	for ( int i=1; i<=n; i++ )
		if ( a[i] > a[pos] )
			pos=i;
	return pos;
}

void func ( int *a, int n )
{	for ( int i=n-1; i>0; i-- )
	{	int pos=find_max ( a, i);
		rev(a,pos);
		rev(a,i);
	}
}
