/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-174-sde/
Count Inversions in an array
Inversion Count for an array indicates – how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum.
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j
Example:
The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

http://www.geeksforgeeks.org/counting-inversions/
*/
#include<cstdio>
#include<iostream>
using namespace std;

void merge_count ( int *a, int s, int m, int e );
void merge ( int *a, int s, int e );

int ct;

int main()
{	int n;
	cin>>n;
	int a[n];
	for ( int i=0; i<n; i++ )
		cin>>a[i];
	merge(a,0,n-1);
	cout<<"inversions: "<<ct<<endl;
	return 0;
}

void merge ( int *a, int s, int e )
{	if ( s >= e )
		return;
	int m=(s+e)/2;
	merge(a,s,m);
	merge(a,m+1,e);
	merge_count(a,s,m,e);
}

void merge_count ( int *a, int s, int m, int e )
{	int ct1=m-s+1;
	int ct2=e-m;
	int a1[ct1], a2[ct2];
	for ( int i=s,j=0; i<=m; i++,j++ )
		a1[j]=a[i];
	for ( int i=m+1, j=0; i<=e; i++, j++ )
		a2[j]=a[i];
	int c1=0, c2=0, c=s;					// c=s NOT c=0 !!
	while ( c1 < ct1 && c2 < ct2 )
	{	if (  a1[c1] > a2[c2] )
		{	ct += ct1-c1;
			a[c++]=a2[c2];
			c2++;
		}
		else
		{	a[c++]=a1[c1];
			c1++;
		}
	}
	while ( c1 < ct1 )
	{	a[c++]=a1[c1];
		c1++;
	}
	while ( c2 < ct2 )
	{	a[c++]=a2[c2];
		c2++;
	}
	/*
	cout<<"s: "<<s<<" m: "<<m<<" e: "<<e<<endl;
	for ( int i=s; i<=e; i++ )
		cout<<a[i]<<" ";
	cout<<endl;
	*/
}
