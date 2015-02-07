/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-161-off-campus-sde-1-banglore/
http://www.geeksforgeeks.org/largest-subarray-with-equal-number-of-0s-and-1s/

http://www.geeksforgeeks.org/largest-subarray-with-equal-number-of-0s-and-1s/
Given an array containing only 0s and 1s, find the largest subarray which contain equal no of 0s and 1s. Expected time complexity is O(n). 

Change 0 -> -1
The new problem is finding largest subarray having sum=0
How?
sum[i] = a[0]+a[1]+...a+a[i]
So if sum[i] ==  sum[j]  and j > i then [i+1,j] is a subarray whose sum is 0 and hence the logic

There are two cases, the output subarray may start from 0th index or may start from some other index. We will return the max of the values obtained by two cases.

To find the maximum length subarray starting from 0th index, scan the sumleft[] and find the maximum i where sumleft[i] = 0.

Now, we need to find the subarray where subarray sum is 0 and start index is not 0. This problem is equivalent to finding two indexes i & j in sumleft[] such that sumleft[i] = sumleft[j] and j-i is maximum. To solve this, we can create a hash table with size = max-min+1 where min is the minimum value in the sumleft[] and max is the maximum value in the sumleft[]. The idea is to hash the leftmost occurrences of all different values in sumleft[]. The size of hash is chosen as max-min+1 because there can be these many different possible values in sumleft[]. Initialize all values in hash as -1

To fill and use hash[], traverse sumleft[] from 0 to n-1. If a value is not present in hash[], then store its index in hash. If the value is present, then calculate the difference of current index of sumleft[] and previously stored value in hash[]. If this difference is more than maxsize, then update the maxsize.

*/

#include<cstdio>
#include<map>
using namespace std;

int main()
{	int a[]={1, 0, 1, 1, 1, 0, 0};
	int n=7;
	for ( int i=0; i<n; i++ )
		if (  a[i] == 0 )
			a[i]=-1;
	int sum[n];
	sum[0]=a[0];
	for ( int i=1;i<n; i++ )
		sum[i]=sum[i-1]+a[i];
	map<int,int> m;
	int max=0, start=-1, end=-1;
	for ( int i=0; i<n; i++ )
		if ( m.count(sum[i]) == 0 )
			m[sum[i]]=i;
		else if ( (i-m[sum[i]]-1) >  max )
		{	max=(i-m[sum[i]]-1);
			start=m[sum[i]]+1;
			end=i;
		}
	/*
	 for cases like-	1 -1 1 1 1 -1 -1 1 -1 -1
			  	1  0 1 2 3  2  1 2  1  0
	 			[0 -> end] interval whose sum=0 i.e last occurence of sum=0
	*/
	for ( int i=0; i<n; i++ )
		if ( sum[i] == 0 && i + 1 > max )
		{	max=i+1;
			start=0;
			end=i;
		}
	if ( max != -1 )
		printf("%d %d %d\n", max,start,end);
	else
		printf("No sub-array\n");
	return 0;
}
