/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-162/

http://www.geeksforgeeks.org/maximum-sum-path-across-two-arrays/
Given two sorted arrays such the arrays may have some common elements. Find the sum of the maximum sum path to reach from beginning of any array to end of any of the two arrays. We can switch from one array to another array only at common elements.

Expected time complexity is O(m+n) where m is the number of elements in ar1[] and n is the number of elements in ar2[].

In every iteration of while loops, we process an element from either of the two arrays. There are total m + n elements. Therefore, time complexity is O(m+n).
*/

#include<cstdio>
using namespace std;

const int l1=7, l2=8;
int merge ( int *a1, int n1, int *a2, int n2 );

int main()
{	int a1[l1]={2,3,7,8,9,10,12};
	int a2[l2]={1,6,7,8,3,10,14,15};
	printf("%d\n", merge(a1,l1,a2,l2));
	return 0;
}

int merge ( int *a1, int n1, int *a2, int n2 )
{	int c1=0, c2=0;
	int sum1=0, sum2=0, sum=0;
	while ( c1 < n1 && c2 < n2 )
	{	if ( a1[c1] < a1[c2] )
			sum1+=a1[c1++];
		else if ( a1[c1] > a2[c2] )
			sum2 += a2[c2++];
		else
		{	sum1+=a1[c1++];
			sum2+=a2[c2++];
			if ( sum1 > sum2 )
				sum += sum1;
			else
				sum+= sum2;
			sum1=sum2=0;
		}
	}
	while ( c1 < n1 )
		sum1 +=a1[c1++];
	while ( c2 < n2 )
		sum2 +=a2[c2++];
	sum += sum1 > sum2 ? sum1 : sum2;
	return sum;
}

/*
Proof-
(    ) 	7 (	) 10 (	)		( 	) 7 (	) 10 ( 	)
	Arr1					Arr2
sum1	  sum2				sum1'	    sum2'

SUM1 > SUM1'
SUM2 < SUM2'

TO SHOW THAT BY USING GREEDY AND CHOOSING INTERVAL MAXIMUM WE GET GLOBAL MAXIMUM i.e.
SUM1 + SUM2' > SUM1 + SUM2, and also, 
SUM1 + SUM2' > SUM1' + SUM2'

TO SHOW-
SUM1 + SUM2' > SUM1 + SUM2
removing SUM1
SUM2' > SUM2 	( Alread known )
Hence proved. Thus global maxima is obtained by local maxima's sum
*/
