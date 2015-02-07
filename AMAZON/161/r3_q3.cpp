/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-161-off-campus-sde-1-banglore/
Given an array. Find the maximum number of groups of size of 2 or 3 that can be formed such that sum of the numbers in group is divisible by 3. No number can be reused.

http://www.geeksforgeeks.org/count-possible-groups-size-2-3-sum-multiple-3/
Count all possible groups of size 2 or 3 that have sum as multiple of 3

Given an unsorted integer (positive values only) array of size ‘n’, we can form a group of two or three, the group should be such that the sum of all elements in that group is a multiple of 3. Count all possible number of groups that can be generated in this way.

Input: arr[] = {3, 6, 7, 2, 9}
Output: 8
// Groups are {3,6}, {3,9}, {9,6}, {7,2}, {3,6,9},
//            {3,7,2}, {7,2,6}, {7,2,9}


Input: arr[] = {2, 1, 3, 4}
Output: 4
// Groups are {2,1}, {2,4}, {2,1,3}, {2,4,3}

We strongly recommend to minimize the browser and try this yourself first.

The idea is to see remainder of every element when divided by 3. A set of elements can form a group only if sun of their remainders is multiple of 3. Since the task is to enumerate groups, we count all elements with different remainders.

1. Hash all elements in a count array based on remainder, i.e, 
   for all elements a[i], do c[a[i]%3]++;
2. Now c[0] contains the number of elements which when divided
   by 3 leave remainder 0 and similarly c[1] for remainder 1 
   and c[2] for 2.
3. Now for group of 2, we have 2 possibilities
   a. 2 elements of remainder 0 group. Such possibilities are 
      c[0]*(c[0]-1)/2
   b. 1 element of remainder 1 and 1 from remainder 2 group
      Such groups are c[1]*c[2].
4. Now for group of 3,we have 4 possibilities
   a. 3 elements from remainder group 0.
      No. of such groups are c[0]C3
   b. 3 elements from remainder group 1.
      No. of such groups are c[1]C3
   c. 3 elements from remainder group 2.
      No. of such groups are c[2]C3
   d. 1 element from each of 3 groups. 
      No. of such groups are c[0]*c[1]*c[2].
5. Add all the groups in steps 3 and 4 to obtain the result.
*/
#include<stdio.h>
 
int findgroups(int arr[], int n)
{	int c[3] = {0}, i;
	int res = 0;
	for (i=0; i<n; i++)
        	c[arr[i]%3]++;
	res += ((c[0]*(c[0]-1))>>1);
	res += c[1] * c[2];
	res += (c[0] * (c[0]-1) * (c[0]-2))/6;
	res += (c[1] * (c[1]-1) * (c[1]-2))/6;
	res += ((c[2]*(c[2]-1)*(c[2]-2))/6);
	res += c[0]*c[1]*c[2];
	return res;
}
 
int main()
{	int arr[] = {3, 6, 7, 2, 9};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Required number of groups are %d\n", findgroups(arr,n));
	return 0;
}

/*
		0
	0	1
		2

		0
0	1	1
		2

		0
	2	1
		2



		0
	0	1
		2

		0
1	1	1
		2

		0
	2	1
		2

		0
	0	1
		2



		0
2	1	1
		2

		0
	2	1
		2
*/
