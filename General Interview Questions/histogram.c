#include<stdio.h>

struct node
{	long long int height,index;
}stack[100010];

int main()
{	int n;
	while(scanf("%d",&n), n != 0 )
	{	long long  a[n+1],top=-1,curr_area=0, max_area=0,i,left;
		for ( i=0; i<n; i++)
			scanf("%lld",&a[i]);
		for ( i=0; i<=n; i++)
		{	while ( top>=0 && ( i==n || stack[top].height > a[i] ) )		// i==n for nth iteration to empty stack!!
			{	if ( top > 0 )
					left=stack[top-1].index;		// stack[top-1] not top, explanation by simulation
				else
					left=-1;
				curr_area= (i-left-1)*(stack[top].height);		// i-left-1 because i points to the index taht has not been
				top--;						// pushed in stack till now
				if ( curr_area>max_area)
					max_area=curr_area;
			}
			if ( i < n )		// if ( i==n) means all elements are entered and no more pushing
			{	++top;
				stack[top].height=a[i];		// push new subproblem
				stack[top].index=i;
			}
		}
		printf("%lld\n",max_area);
	}
	return 0;
}
