/*
http://mw2.haifa.ac.il/pluginfile.php/239578/mod_resource/content/0/In-Place%20Merge%20Sort.html

The recursive base case, as usual, is the array of length one (or zero):  first>=last.

Otherwise, compute a mid-point (mid=(first+last)/2;), and then recursively sort the data from first up through  mid, and from mid+1 up through last.

inPlaceSort (x, first,  mid);
inPlaceSort (x, mid+1, last);

The slightly tricky part is the merge logic.  As usual, you have a subscript into the left array segment (x[left]) and the right array segment (x[right]).  If x[left] tests as less than or equal to x[right], then it is already in place within the sorted array segment, so just increment left.  Otherwise, the array element in x[right] needs to move down into the space currently occupied by x[left], and to accommodate this, the entire array segment from x[left] through x[right-1] needs to move up by one — effectively you need to rotate that little segment of the array.  In the process, everything moves up by one, including the end of the left segment (mid).

      left = first;  right = mid+1;
      // One extra check:  can we SKIP the merge?
      if ( x[mid].compareTo(x[right]) <= 0 )
         return;

      while (left <= mid && right <= last)
      {  // Select from left:  no change, just advance left
         if ( x[left].compareTo(x[right]) <= 0 )
            left++;
         // Select from right:  rotate [left..right] and correct
         else
         {  tmp = x[right];     // Will move to [left]
            System.arraycopy(x, left, x, left+1, right-left);
            x[left] = tmp;
            // EVERYTHING has moved up by one
            left++;  mid++;  right++;
         }
      }
      // Whatever remains in [right..last] is in place

Complexity- O(N ^2)
*/

#include<cstdio>
using namespace std;

void merge ( int *a, int s, int m, int e );
void merge_sort ( int *a, int start, int end );

int main()
{	int a[100];
	int n;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ )
		scanf("%d",a+i);
	merge_sort(a,0,n-1);
	for ( int i=0; i<n; i++ )
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}

void merge_sort ( int *a, int s, int e )
{	if ( s >= e )
		return;
	int m=(s+e)/2;
	merge_sort(a,s,m);
	merge_sort(a,m+1,e);
	merge(a,s,m+1,e);
}

void merge ( int *a, int s, int m, int e )		// O(N^2) due to shifting
{	int l=s;
	int r=m;
	// [l,m-1] represent the left array and [r,e] represent right array
	while ( l < m && r <= e )		// until either of the two array is not exhausted
	{	if ( a[l] <= a[r] )
			l++;
		else
		{	int tmp=a[r];
			for ( int i=r; i>l; i-- )
				a[i]=a[i-1];
			a[l]=tmp;
			l++;
			r++;
			m++;
		}
	}
}
