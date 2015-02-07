/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-161-off-campus-sde-1-banglore/
http://stackoverflow.com/questions/20026243/find-2-missing-numbers-in-an-array-of-integers-with-two-missing-values

http://stackoverflow.com/questions/20026243/find-2-missing-numbers-in-an-array-of-integers-with-two-missing-values
EDIT

Suppose the maximum element of the array a[] is B i.e. suppose a[]={1,2,4} and here 3 and 5 are not present in a[] so max element is B=5.

    xor all the elements of the array a to X
    xor all the elements from 1 to B to x
    find the left most bit set of x by x = x &(~(x-1));
    Now if a[i] ^ x == x than xor a[i] to p else xor with q
    Now for all k from 1 to B if k ^ x == x than xor with p else xor with q
    Now print p and q

proof:

Let a = {1,2,4} and B is 5 i.e. from 1 to 5 the missing numbers are 3 and 5

Once we XOR elements of a and the numbers from 1 to 5 we left with XOR of 3 and 5 i.e. x.

Now when we find the leftmost bit set of x it is nothing but the left most different bit among 3 and 5. (3--> 011, 5 --> 101 and x = 010 where x = 3 ^ 5)

After this we are trying to divide into two groups according to the bit set of x so the two groups will be:

p = 2 , 2 , 3 (all has the 2nd last bit set)

q = 1, 1, 4, 4, 5 (all has the 2nd last bit unset)

if we XOR the elements of p among themselves we will find 3 and similarly if we xor all the elements of q among themselves than we will get 5. Hence the answer.
*/

#include<cstdio>
using namespace std;

int main()
{	int a[]={1,2,4};
	int n=5;
	int all=0, given=0;
	for ( int i=1; i<=n; i++ )
		all = all ^ i;
	for ( int i=0; i<n-2; i++ )
		given = given^a[i];
	int x=given^all;
	x= ( x&(~(x-1)));
	//printf("%d\n",x);
	int set1=0, set2=0;
	for ( int i=1; i<=n; i++ )
	{	if ( (i&x) == x )
			set1 = set1 ^ i;
		else
			set2 = set2 ^ i;
	}
	int v1, v2;
	//printf("%d %d\n",set1,set2);
	for ( int i=0; i<n-2; i++ )
	{	if ( (a[i]&x) == x )
			set1= set1 ^ a[i];
		else
			set2= set2 ^ a[i];
	}
	printf("%d %d\n", set1, set2);
	return 0;
}
