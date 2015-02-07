/*
http://www.geeksforgeeks.org/snapdeal-interview-experience-set-2-software-engineer-2/

You have given two arrays, all the elements of first array is same as second array except 1, You have to find out distinct pair.
*/
#include<cstdio>
#include<iostream>
using namespace std;

void func ( int *a, int *b, int n );

int main()
{	int n;
	cin>>n;
	int a[n], b[n];
	for ( int i=0; i<n; i++ )
		cin>>a[i];
	for ( int i=0; i<n; i++ )
                cin>>b[i];
	func(a,b,n);
	return 0;
}

void func ( int *a, int *b, int n )
{	int S=a[0];
	for ( int i=1; i<n; i++ )
		S=S^a[i];
	for ( int i=0; i<n; i++ )
                S=S^b[i];
	int v= (S & (~(S-1)));
	cout<<v<<endl;
	int P=0, Q=0;
	for ( int i=0; i<n; i++ )
	{	if ( (a[i]&v) == 0 )
			P = P^a[i];
		else
			Q = Q^a[i];
		if ( (b[i]&v) == 0 )
			P= P^b[i];
		else
			Q= Q^b[i];
	}
	cout<<P<<" "<<Q<<endl;
}
