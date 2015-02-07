/*
http://www.geeksforgeeks.org/median-of-two-sorted-arrays-of-different-sizes/
*/

#include <cstdio>
#include <cstdlib>
#include<iostream>
using namespace std;
 
int max( int a, int b )
{	return a > b ? a : b;	 }
 
int min( int a, int b )
{ 	return a < b ? a : b; 	}
 
float MO2( int a, int b )
{ 	return ( a + b ) / 2.0; 	}
 
float MO3( int a, int b, int c )
{	return a + b + c - max( a, max( b, c ) ) - min( a, min( b, c ) );	}
 
float MO4( int a, int b, int c, int d )
{	int Max = max( a, max( b, max( c, d ) ) );
 	int Min = min( a, min( b, min( c, d ) ) );
  	return ( a + b + c + d - Max - Min ) / 2.0;
}

float findMedianUtil( int *a, int s1, int e1, int *b, int s2, int e2 )
{	int n=e1-s1+1;
        int m=e2-s2+1;
	cout<<s1<<" "<<e1<<" "<<n<<" "<<s2<<" "<<e2<<" "<<m<<endl;
	if( n == 1 )
    	{	if( m == 1 )
            		return MO2( a[s1], b[s2] );
 
        	if( m & 1 )
            		return MO2( b[(s2+e2)/2], MO3(a[s1], b[(s2+e2)/2 - 1], b[(s2+e2)/2 + 1]) );
        	return MO3( b[(s2+e2)/2], b[(s2+e2)/2 + 1], a[s1] );
    	}
    	else if( n == 2 )
    	{	if( m == 2 )
            		return MO4( a[s1], a[e1], b[s2], b[e2] );
 		if( m & 1 )
            		return MO3 ( b[(s2+e2)/2], max( a[s1], b[(s2+e2)/2 - 1] ), min( a[e1], b[(s2+e2)/2 + 1] ) );
        	return MO4 ( b[(s2+e2)/2], b[(s2+e2)/2 + 1], max( a[s1], b[(s2+e2)/2 - 1] ), min( a[e1], b[(s2+e2)/2 + 2] ) );
    	}
 	float mid_a, mid_b;
	int mid_a_ele, mid_b_ele;
	if ( n % 2 == 0 )
	{	mid_a = a[(s1+e1)/2] + a[(s1+e1)/2+1];
		mid_a /=2.0;
	}
	else
		mid_a=a[(s1+e1)/2];
	mid_a_ele=(s1+e1)/2;
        if ( m % 2 == 0 ) 
        {       mid_b = b[(s2+e2)/2] + b[(s2+e2)/2+1];
                mid_b /=2.0;
        }
        else
                mid_b=b[(s2+e2)/2];
    	mid_b_ele=(s2+e2)/2;
	cout<<mid_a_ele<<" "<<mid_b_ele<<endl;
	if( mid_a <= mid_b )
        {	if ( m % 2 == 0 )
			return findMedianUtil( a, mid_a_ele, e1, b, s2, mid_b_ele);
		else
                        return findMedianUtil( a, mid_a_ele, e1, b, s2, mid_b_ele);
	}
	else
        {       if ( n % 2 == 0 )
                        return findMedianUtil( a, s1, mid_a_ele, b, mid_b_ele, e2);
                else
                        return findMedianUtil( a, s1, mid_a_ele, b, mid_b_ele, e2);
        }               
}
 
float findMedian( int *a, int s1, int e1, int *b, int s2, int e2 )
{	int n=e1-s1+1;
	int m=e2-s2+1;
	if ( n > m )
       		return findMedianUtil( b,s2,e2,a,s1,e1 );
 	return findMedianUtil( a,s1,e1,b,s2,e2 );
}
 
int main()
{	int A[] = {1,2,3,4,5,6,7,8,9};
 	int B[] = {5, 8, 10, 20};
 	int N = sizeof(A) / sizeof(A[0]);
 	int M = sizeof(B) / sizeof(B[0]);
 	printf( "%f", findMedian( A, 0, N-1, B, 0, M-1 ) );
 	return 0;
}
