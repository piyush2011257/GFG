#include<cstdio>
using namespace std;

int bitonic ( int *a, int n, int s, int e );

int main()
{	int a[100];
	int d;
	scanf("%d",&d);
	for ( int i=0; i<d; i++ )
		scanf("%d",a+i);
	printf("%d\n", bitonic(a,d,0,d-1));
	return 0;
}

int bitonic ( int *a, int n, int s, int e )
{	if ( s > e )
		return -1;
	int m=(s+e)/2;
	printf("%d %d\n",s,e);
	bool l=0, r=0;
	// check if condition for bitonicity satisfied or not
	if ( m-1 < 0 )
		l=1;
	else if ( m-1 >= 0 && a[m-1] <= a[m] )
		l=1;
	if ( m+1 >= n )
		r=1;
	else if ( m+1 < n && a[m+1] < a[m] )
		r=1;
	if ( l == 1 && r == 1 )
		return m;
	if ( r == 1 )
		return bitonic ( a,n,s,m-1);
	else
		return bitonic (a,n,m+1,e);
}
