/*
http://www.austinrochford.com/posts/2013-10-28-median-of-medians.html

Finally, we arrive at the median-of-medians algorithm, which solves the general selection problem in linear time. The idea behind the algorithm is similar to the idea behind quicksort.

    Select a pivot element, and partition the list into two sublists, the first of which contains all elements smaller than the pivot, and the second of which contains all elements greater than the pivot.
    Call the index of the pivot in the partitioned list k. If k=i, then return the pivot element.
    If i<k, recurse into the sublist of elements smaller than the pivot, looking for the i-th smallest element.
    If i>k, recurse into the sublist of elements larger than the pivot, looking for the (i−k−1)-th smallest element.

The median-of-medians algorithm chooses its pivot in the following clever way.

    Divide the list into sublists of length five. (Note that the last sublist may have length less than five.)
    Sort each sublist and determine its median directly.
    Use the median of medians algorithm to recursively determine the median of the set of all medians from the previous step. (This step is what gives the algorithm its name.)
    Use the median of the medians from step 3 as the pivot.


As in case of quick sort, we need to partition the data. For most efficient partitioning we need median. So we find median of medians and that gives us a value close to medians and use it as the pivot.
So this idea of medians of medians is actually used to get the pivot element and  then regular quick sort works

That is why for the first call of median we pass ele as the element to be found but for successive calls we manke ele - n/2 ( j, j/2 )... since we need median of medians to be the pivot element. 

Then we partition the input array as in case of quick sort and use the methoid recursively
O(N)- median finding / kth smallest element

*/
#include<cstdio>
#include<algorithm>
using namespace std;

int median ( int *a, int n, int ele );

int main()
{	int n;
	scanf("%d",&n);
	int a[n];
	for ( int i=0; i<n; i++ )
		scanf("%d",&a[i]);
	int k;
	scanf("%d",&k);
	printf("%d\n",median(a,n,k));
	return 0;
}


int median ( int *a, int n, int ele )
{	if ( n < 5 )
	{	sort(a,a+n);
		return a[ele-1];
	}
	int N=n/5 + (n%5 != 0 );
	int A[N];
	int j=0, i=0,pos=0;
	for ( ; i<N-1; i++ )
	{	pos=i*5;
		sort(a+pos,a+pos+5);
		A[j++]=a[pos+2];
	}
	pos=i*5;
	sort(a+pos, a+n);
	A[j++]=a[(pos+n-1)/2];
	// find probable median / pivot for further partition
	int med=median(A,j,j/2 + ( j%2 != 0 ));		// special case when j=1, j/2=0 and in next call a[ele-1] -> ele=0 -> ele-1 = -1 !!!
	// for j -> odd, we need mid element- j/2 th element e.g. 5 -> we need mid -> 3rd element -> 5/2 + 1
	int low[n];
	int high[n];
	int c1=0,c2=0,c3=0;
	for ( int k=0; k<n; k++ )
	{	if ( a[k] < med )
			low[c1++]=a[k];
		else if ( a[k] > med )
			high[c2++]=a[k];
		else
			c3++;
	}
	//printf("%d %d %d %d %d\n", med, ele, c1, c2, c3);
	if ( ele > c1 && ele <= c1+c3 )
		return med;
	if ( c1  >= ele )
		return median(low,c1,ele);
	return median(high,c2,ele-c1-c3);
}

/* Logic again-
Basic quick sort-
    Select a pivot element, and partition the list into two sublists, the first of which contains all elements smaller than the pivot, and the second of which contains all elements greater than the pivot.
    Call the index of the pivot in the partitioned list k. If k=i, then return the pivot element.
    If i<k, recurse into the sublist of elements smaller than the pivot, looking for the i-th smallest element.
    If i>k, recurse into the sublist of elements larger than the pivot, looking for the (i−k−1)-th smallest element.

Problem. Pivot may lead to O(n^2)
Solve this problem-> use median as a pivot - O(NlogN). Mainly it would give even partition.
So
suppose we need to find kth element in
a1 a2 a3 .... an-1 an
so we call median(a,n,k)
now we use quick sort partitioning such that one array (low[] ) represents all number < pivot and other array (high[] ) represents all number > pivot
How to find pivot?
Group i/p array a[] in sets of 5
Take median of each set of 5-> A[]
and find the median of A[] ( median of medians )	m=median(a,n,n/2) array a[] ofd size n, find median -> n/2th element
This will give a value close to median and hence a good pivot
Now we get a value close to median as a pivot and then divide a[] into low[] and high[] and use the same logic recursively of either low or high
*/
