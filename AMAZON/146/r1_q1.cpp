/*
http://www.geeksforgeeks.org/amazon-interview-questions-set-146/

You are given the position of each word in the paragraph. Meaning, you know that word ‘Amazon’ occurs at positions 1 and 10, and ‘The’ occurs at 3 and 9. You do not have to parse the paragraph to gather this info.

Sub questions :
*Which data structure will you use to store the given info?
*Compute the minimum distance in the most efficient way.
*Give a working code for the same.

Amazon -1, 10
The- 3,9
Merge sort
(1,10)	(3,9)
(+1,-3,-9,+10)

All positive, negative and 0,0 pairs denote (The,Amazon pairs)
Answer- Minimum difference amongst these adjacent pairs
(+1,-3)
(-9,+10)

O(N) time / space
is positions are sorted else
O(NlogN) time, O(N) space

http://www.geeksforgeeks.org/forums/topic/minimum-distance-between-two-words/
http://www.geeksforgeeks.org/find-the-minimum-distance-between-two-numbers/
*/

#include<cstdio>
#include<climits>
using namespace std;

const int l1=2, l2=2;

void merge ( int *a, int *a1, int n1, int *a2, int n2 );
void solve ( int *a, int n);

int mod ( int n )
{	if ( n < 0 )
		n*=-1;
	return n;
}

int main()
{	int a1[l1]={1,10};			// assume positions are sorted
	int a2[l2]={3,9};			// assume positions are sorted
	int a[l1+l2];
	merge(a,a1,l1,a2,l2);
	solve(a,l1+l2);
	return 0;
}
void merge ( int *a, int *a1, int n1, int *a2, int n2 )
{	int ctr=0, ctr1=0, ctr2=0;
	while ( ctr1 < n1 && ctr2 < n2 )
	{	if ( a1[ctr1] <= a2[ctr2] )
			a[ctr++]=a1[ctr1++];
		else
			a[ctr++]=-1*a2[ctr2++];
	}
	while ( ctr1 < n1 )
		a[ctr++]=a1[ctr1++];
	while ( ctr2 < n2 )
		a[ctr++]=a2[ctr2++];
}
		
void solve ( int *a, int n)
{	int min=INT_MAX;
	for ( int i=0; i<n-1; i++ )
	{	if ( a[i] >= 0 && a[i+1] <= 0 )
		{	if ( mod(a[i+1]) - mod(a[i]) < min )
				min= mod(a[i+1]) - mod(a[i]);
		}
	}
	printf("%d\n", min);
}
