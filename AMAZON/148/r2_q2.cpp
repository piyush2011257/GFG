/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-148/
How to find two sets(of size m,n) are dis-joint(have no elements common) efficiently

Simple method is using hash maps

Anothe new algorithm using Set ADT implementation using arrays

Consider
S1={1,2,3,4}
S2={5,6,7,4}

Now first thing that we know range of i/p and all positive -> [1,7]
for ( int i=1->7 )
	a[i]=i;

S1[0] be the head / parent for all elements in S1
Now using the same array for S2, if we encounter any elemnt whose parent / head is head of S1 -> means common element !!!
O(n1 + n2 )

Constraint-
We need to know the elements range previously.

This is optimized using Hash Maps but still a new solution
*/

#include<cstdio>
using namespace std;

const int l1=4, l2=4;
const int lower_range=1, upper_range=7;
int main()
{	int s1[l1]={1,2,3,4};
	int s2[l2]={5,6,7,4};
	int a[upper_range+1];
	for ( int i=lower_range; i<=upper_range; i++ )
		a[i]=i;
	int head_of_s1=s1[0];
	for ( int i=1; i<l1; i++ )
		a[s1[i]]=s1[0];				// make s1[0] as head / paren for all nodes in set s1

	for ( int i=0; i<l2; i++ )
		if ( a[s2[i]] == head_of_s1 )
			printf("Not disjoint: %d\n", s2[i]);
	return 0;
}
