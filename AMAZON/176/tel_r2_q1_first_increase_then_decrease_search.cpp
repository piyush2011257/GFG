/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-176-sde-1/

Array such that first increasing then decreasing. Search for element
Bitonic array search
e.g. 1 2 3 4 5 6 5 4 3

http://www.algoqueue.com/algoqueue/default/view/2818048/search-in-a-bitonic-array
*/

#include<cstdio>
#include<iostream>
using namespace std;

int find_point_of_inflection ( int *a, int n );
int bsearch_inc ( int *a, int s, int e, int ele );
int bsearch_dec ( int *a, int s, int e, int ele );

int main()
{	int n, ele;
	cin>>n>>ele;
	int a[n];
	for ( int i=0; i<n; i++ )
		cin>>a[i];
	int idx= find_point_of_inflection(a,n);
	cout<<"point of inflection: "<<idx<<endl;
	cout<<bsearch_inc(a,0,idx,ele)<<endl;
	cout<<bsearch_dec(a,idx,n-1,ele)<<endl;
	return 0;
}

int find_point_of_inflection ( int *a, int n )
{	int m,s=0,e=n-1;
	while ( s <= e )
	{	m=(s+e)/2;
		bool l=0, r=0;
		if ( m-1 < s )
			l=1;
		else if ( a[m] >= a[m-1] )
			l=1;
		if ( m+1 > e )
			r=1;
		else if ( a[m] >= a[m+1] )
			r=1;
		if ( l == 1 && r == 1 )
			return m;
		if ( l == 1 && r == 0 )		// go right.. we are on increasing side
			s=m+1;
		else if ( l == 0 && r == 1 )	// go left... we are on decreasing side
			e=m-1;
	}
	return -1;
}

/*
First find point of inflection
Remember, first increasing and then decreasing. Now using this property decide where does the mid lie
Now search opn both sides of inflection point
O(3*logN)
*/

int bsearch_inc ( int *a, int s, int e, int ele )
{	while ( s<=e )
	{	int m=(s+e)/2;
		if ( a[m] == ele )
			return m;
		else if ( a[m] > ele )
			e=m-1;
		else
			s=m+1;
	}
	return -1;
}

int bsearch_dec ( int *a, int s, int e, int ele )
{       while ( s<=e )
        {       int m=(s+e)/2;
                if ( a[m] == ele )
                        return m;
                else if ( a[m] > ele )
                        s=m+1;
                else
                        e=m-1;
        }
        return -1;
}

