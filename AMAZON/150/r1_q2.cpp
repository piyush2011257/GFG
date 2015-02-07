/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-150-sde1-1-year-experienced/
http://www.geeksforgeeks.org/find-a-peak-in-a-given-array/

http://www.geeksforgeeks.org/find-a-peak-in-a-given-array/
Given an array of integers. Find a peak element in it. An array element is peak if it is NOT smaller than its neighbors. For corner elements, we need to consider only one neighbor. For example, for input array {5, 10, 20, 15}, 20 is the only peak element. For input array {10, 20, 15, 2, 23, 90, 67}, there are two peak elements: 20 and 90. Note that we need to return any one peak element.
*/

/*
Proof-
http://www.geeksforgeeks.org/find-a-peak-in-a-given-array/

Given an array of integers. Find a peak element in it. An array element is peak if it is NOT smaller than its neighbors. For corner elements, we need to consider only one neighbor. For example, for input array {5, 10, 20, 15}, 20 is the only peak element. For input array {10, 20, 15, 2, 23, 90, 67}, there are two peak elements: 20 and 90. 
NOTE- we need to return ANY ONE peak element ONLY!!

Following corner cases give better idea about the problem.
1) If input array is sorted in strictly increasing order, the last element is always a peak element. For example, 50 is peak element in {10, 20, 30, 40, 50}.
2) If input array is sorted in strictly decreasing order, the first element is always a peak element. 100 is the peak element in {100, 80, 60, 50, 20}.
3) If all elements of input array are same, every element is a peak element.

It is clear from above examples that there is always a peak element in input array in any input array.

Lets consider an array a[] of size n

For peak: a[k-1] < a[k] > a[k+1]

let an element be a[m]. Now if a[m] > a[m-1] ->		a[m-1] > a[m] < a[m+1]

if a[m-1] > a[m] < a[m+1]
then,	a[m-2] < a[m-1] > a[m]			a[m-1] is peak
	a[m-2] > a[m-1] > a[m+1]		no peak if a[m-3] NOT a boundary
then,
	a[m-3] < a[m-2] > a[m-1] > a[m+1]	a[m-2] is peak
	a[m-3] > a[m-2] > a[m-1] > a[m+1]	no peak if a[m-3] NOT a boundary
so on
let m=4
	a[1] < a[2] > a[3] > a[4]		a[2] is peak
	a[1] > a[2] > a[3] > a[4]		a[1] is peak

if m=3
	a[1] < a[2] > a[3]			a[2] is peak
	a[1] > a[2] > a[3]			a[1] is peak

Thus either a[1] will be peak or any other node [2,m-1] is a peak ->THERE ALWAYS EXISTS A PEAK IN THE LEFT SUB-ARRAY

Now the other way round, for
a[m] < a[m+1]

then,
	a[m] < a[m+1] < a[m+2]			no peak if a[m+2] NOT a boundary
	a[m] < a[m+1] > a[m+2]			a[m+1] is peak
and then,
	a[m] < a[m+1] < a[m+2] < a[m+3]		no peak if a[m+2] NOT a boundary
	a[m] < a[m+1] < a[m+2] > a[m+3]		a[m+2] is peak

Hence, we will have a boundary on the right
T(N) = T(N/2) + O(1)
O(LogN) complexity

Now what about equality condition??
peak- a[m-1] <= a[m] >= a[m+1]

				a[m-2] > a[m-1] > a[m]			no peak if a[m-2] NOT a boundary
a[m-1] > a[m]			a[m-2] = a[m-1] > a[m]			a[m-1] is peak
				a[m-2] < a[m-1] > a[m]			a[m-1] is peak

				a[m-2] > a[m-1] == a[m]			no peak if a[m-2] NOT a boundary
a[m-1] == a[m]			a[m-2] == a[m-1] == a[m]		a[m-1] is peak
				a[m-2] < a[m-1] == a[m]			a[m-1] is peak

Considering is a[m-2] is not a peak element and a[m-3 ] is boundary

				a[m-3] > a[m-2] > a[m-1] > a[m]		a[m-3] is peak and boundary
				a[m-3] == a[m-2] > a[m-1] > a[m]	a[m-2] is peak
				a[m-3] < a[m-2] > a[m-1] > a[m]		a[m-2] is peak

				a[m-3] > a[m-2] > a[m-1] == a[m]	a[m-3] is peak and boundary
				a[m-3] == a[m-2] > a[m-1] == a[m]	a[m-2] is peak
				a[m-3] < a[m-2] > a[m-1] == a[m]	a[m-2] is peak

Thus each element is either boundary or non-boundary and so peak WILL lie on the left side for sure
*/

#include<cstdio>
using namespace std;

int peak ( int *A, int s, int e, int n );

//const int len=6;

int main()
{	int n, len;
	int a[100];
	while ( scanf("%d",&n) != EOF )
	{	len=n;
		for ( int i=0; i<n; i++ )
			scanf("%d",a+i);
		/*int a[len]={1, 3, 20, 4, 1, 0};*/
		if ( len == 1 )
			printf("0\n");
		else
			printf("%d\n", peak(a,0,len-1,len));
	}
	return 0;
}

int peak ( int *a, int s, int e, int n )	// we need only one peak element and hence we need to locate optimal area where peak will lie
{	if ( s > e )
		return -1;
	if ( s == e )
	{	if ( s == 0 && a[s] > a[s+1] )
			return s;
		if ( s == n-1 && a[s] > a[s-1] )
			return s;
	}
	int m=(s+e)/2;
	bool l=0, r=0;
	if ( ( m-1 >= 0 && a[m-1] <= a[m] ) || ( m-1 < 0 ) )
		l=1;
	if ( ( m+1 < n && a[m+1] <= a[m] ) || ( m+1 >= n ) )
		r=1;
	if ( l==1 && r == 1 )
		return m;
	/*
	if ( ( mid == 0 || arr[mid-1] <= arr[mid] ) && ( mid == n-1 || arr[mid+1] <= arr[mid] ) )
        	return mid;
	*/
	if ( m-1 >= 0 && a[m-1] >= a[m] )
		return peak(a,s,m-1,n);
	else
		return peak(a,m+1,e,n);
}
