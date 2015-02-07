/*
http://slientcode.blogspot.in/2012/05/partition-of-array.html

Given an array of positive and negative integers, re-arrange it so that positives on one end and negatives on the other, but retain the original order of appearance, e.g. 2,7,-5, 9,-1, 10,-3 => -5, -1, -3, 2, 7, 9, 10.  Do it in-place, in O(nlogn).

Using the partition method in quick sort, the order of those elements may change. Using the bubble sort to exchange one by one, the order is kept but the time complexity will be O(n^2). Merge sort can be a help here to get the O(nLogn) and in place method: i.e. assume each half of the array has been in right order (negatives on the left, positives on the right), then merge two half into one.

https://csjobinterview.wordpress.com/2012/03/30/array-stable-partition/

-1 -2 3 4 5 6 61 62		-7 -8 -9 -10 11 12
      |				 	     |	
    firstpos_l			         firstpos_r

reverse [firstpos_l,firstpos_r-1]
-1 -2 [ -10 -9 -8 -7 62 61 6 5 4 3 ] 11 12
	|			 |
      firstpos_l	      firstpos_r-1

Reverse [ firstpos_l, firstpos_l+firstpos_r-1-med]
			i-1     +    j-med

-1 -2 [ -7 -8 -9 -10 62 61 6 5 4 3 ] 11 12
	 |	      |		 |
      firstpos_l      |	      firstpos_r-1
		      |
	    firstpos_l+firstpos_r-med

[firstpos_l+firstpos_r-med, firstpos_r-1] all +ve elements in left subarray in reverse order
reverse [firstpos_l+firstpos_r-med, firstpos_r-1]

-1 -2 [ -7 -8 -9 -10 3 4 5 6 61 62 ] 11 12
*/

#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

void merge ( int *a, int s, int e );
void merge_sort ( int *a, int s, int m, int e );
void reverse ( int *a, int s, int e );

int main()
{	int n;
	cin>>n;
	int a[n];
	for ( int i=0; i<n; i++ )
		cin>>a[i];
	merge(a,0,n-1);
	for ( int i=0; i<n; i++ )
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}

void merge ( int *a, int s, int e )
{	if ( s == e )
		return;
	int m=(s+e)/2;
	merge(a,s,m);
	merge(a,m+1,e);
	merge_sort(a,s,m,e);
}
void merge_sort ( int *a, int s, int m, int e )
{	/*
	cout<<"before"<<endl;
	for ( int i=s; i<=e; i++ )
        	cout<<a[i]<<" ";
        cout<<endl;
        */
	int first_pos_l=s;
	while ( first_pos_l <= m && a[first_pos_l] < 0 )
		first_pos_l++;
	int first_pos_r=m+1;
        while ( first_pos_r <= e && a[first_pos_r] < 0 ) 
                first_pos_r++;
	//cout<<first_pos_l<<" "<<first_pos_r<<" "<<m<<endl;
	reverse(a,first_pos_l,first_pos_r-1);
	/*
	cout<<"after 1st rotation"<<endl;
        for ( int i=s; i<=e; i++ )
                cout<<a[i]<<" ";
        cout<<endl;
	*/
	reverse(a,first_pos_l, first_pos_l+first_pos_r-(m+1)-1);
	/*
	cout<<"after 2nd rotation"<<endl;
        for ( int i=s; i<=e; i++ )
                cout<<a[i]<<" ";
        cout<<endl;
	*/
	reverse(a, first_pos_l+first_pos_r-(m+1),first_pos_r-1);
	/*
	cout<<"after 3rd rotation"<<endl;
        for ( int i=s; i<=e; i++ )
                cout<<a[i]<<" ";
        cout<<endl;
	*/
}

void reverse ( int *a, int s, int e )
{	while ( s < e )
	{	a[s]=a[s]^a[e];	
		a[e]=a[s]^a[e];
		a[s]=a[s]^a[e];
		s++,e--;
	}
}
