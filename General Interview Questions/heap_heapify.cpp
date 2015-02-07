#include<cstdio>
using namespace std;

void heapify ( int *a, int i, int k );

void print( int *a, int k )
{	for ( int i=0; i<=k; i++ )
		printf("%d ", a[i]);
	printf("\n");
}

int main()
{	int d;
	int k=-1;
	int a[100];
	while ( scanf("%d",&d) != EOF )
		a[++k]=d;
	for ( int i=k; i>=0; i-- )
		heapify(a,i,k);
	print(a,k);
	return 0;
}

void heapify ( int *a, int i, int k )
{	int p=i;
	int l, r;
	while ( 1 )
	{	l=2*p+1;
		r=l+1;
		if ( l > k )
			return;
		if ( a[l] < a[p] )
		{	if ( r <= k && a[r] < a[l] )
			{	int t=a[p];
				a[p]=a[r];
				a[r]=t;
				p=r;
			}
			else
			{	int t=a[l];
				a[l]=a[p];
				a[p]=t;
				p=l;
			}
		}
		else if (  r <= k && a[r] < a[p] )
		{	int t=a[p];
                        a[p]=a[r];
                        a[r]=t;
			p=r;
		}
		else
			return;
	}
}
