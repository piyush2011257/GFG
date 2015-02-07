/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-174-sde/
Given an array with lengths, you have to select 3 lengths (a, b and c) for a triangle such that it satisfies condition a+b>c,b+c>a, a+c>b. Find the number of possible triangles can be created from the given array.
ex: 3 5 6 9 10
(3,9,10), (3 5 6), (5 6 10), (5 9 10), (5 6 9), (6 9 10)
so number of possible triangles is 6

http://www.geeksforgeeks.org/find-number-of-triangles-possible/
http://codeforces.com/blog/entry/13500

Logic, let
a<b<c
then
assume a+b > c
so, b+c > a	since b,c > a
and a+c > b 	since c > b

*/

#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int max_triangle ( int *a, int n );

int main()
{	int n;
	cin>>n;
	int a[n];
	for ( int i=0; i<n; i++ )
		cin>>a[i];
	sort(a,a+n);
	cout<<"max triangle: "<<max_triangle(a,n)<<endl;
	return 0;
}

int max_triangle ( int *a, int n )
{	int ct=0;
	for ( int i=0; i<n-2; i++ )
	{	int k=i+2;
		for ( int j=i+1; j<n-1; j++ )		// i,j,k triplet so j < n-1
		{	while ( k < n && a[k] < a[i]+a[j] )			// A[I]+A[K] > A[K] and hence why this logic/loop works
				k++;
			ct += k-j-1;		// k-1th element satisfies the criteria
		}
	}
	return ct;
}

/*
Analysis on why the complexity is O(N^2) and not O(N^3)
The time complexity looks more because of 3 nested loops. If we take a closer look at the algorithm, we observe that k is initialized only once in the outermost loop. The innermost loop executes at most O(n) time for every iteration of outer most loop, because k starts from i+2 and goes upto n for all values of j. Therefore, the time complexity is O(n^2).

Consider
10 20 22 25 28 30 32 40
|  |	       |
i  j  	       k			After 1st iteration
So we have following triplets
(10,20,22)
(10,20,25)
(10,20,28)

Now k is still unchanged:
10 20 22 25 28 30 32 40
|     |        |
i     j        k                        Before start of 2nd iteration of while() for k

Note that following is also true
(10,22,25)		<- already covered in k for previous j
(10,22,28)			""
(10,22,30)			""

after 2nd loop
10 20 22 25 28 30 32 40
|     |           |
i     j           k                        After end of 2nd iteration of while() for k
k-j-1 additional for (i,j,K) triplets, hence we are not required to start k in while loop from j+1 again and can use previously solved k for current j for loop.
Each element is visited at max twice for i-for loop - once by j-for loop and second once by k while loop
O(N*2N) - O(N^2)
*/


