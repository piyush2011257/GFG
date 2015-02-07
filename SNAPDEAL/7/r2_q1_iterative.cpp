/*
http://www.geeksforgeeks.org/snapdeal-interview-experience-set-7-campus/

Print the power set of a given set. http://www.geeksforgeeks.org/power-set/
*/

#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

void power_set ( char *a, int n );

int main()
{	int n;
	cin>>n;
	char a[n+1];
	cin>>a;
	power_set(a,n);
	return 0;
}

void power_set ( char *a, int n )
{	int ctr=pow(2,n)-1;
	for ( int i=0; i<=ctr; i++ )
	{	for ( int j=0; j<n; j++ )
		{	int t=pow(2,j);
			if ( ( i&t) != 0 )
				cout<<a[j];
		}
		cout<<endl;		// empty set for initial endline
	}
}
