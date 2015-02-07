#include<cstdio>
using namespace std;

int search_rotated ( int *a, int s, int e, int ele );

int main()
{	int a[100],d,ele;
	scanf("%d",&d);
	for ( int i=0; i<d; i++ )
		scanf("%d",a+i);
	scanf("%d",&ele);
	printf("%d\n", search_rotated(a,0,d-1,ele));
	return 0;
}

int search_rotated ( int *a, int s, int e, int ele )
{	if ( s > e )
		return -1;
	int m=(s+e)/2;
	if ( a[m] == ele )
		return m;
	if ( a[s] <= a[m] )						// first half is sorted
	{	if ( ele < a[m] && ele >= a[s]  )			// lies in first half
			return search_rotated(a,s,m-1,ele);
		else
			return search_rotated(a,m+1,e,ele);
	}
	else								// second half is sorted
	{	if ( ele > a[m] && ele <= a[e] )
			return search_rotated(a,m+1,e,ele);		// lies in second half
		else
			return search_rotated(a,s,m-1,ele);
	}
}

