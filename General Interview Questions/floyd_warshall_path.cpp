/*
http://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm#Path_reconstruction
*/

#include<cstdio>
#include<climits>
using namespace std;

int main()
{	int n,e,u,v,wt,src,dst;
	scanf("%d %d",&n,&e);
	int a[n][n], next_on_path[n][n];
	for ( int i=0; i<n; i++ )
		for ( int j=0; j<n; j++ )
		{	if ( i != j )
				a[i][j]=INT_MAX;
			else
				a[i][j]=0;
			next_on_path[i][j]=INT_MAX;
		}

	for ( int i=0; i<e; i++ )
	{	scanf("%d %d %d",&u,&v,&wt);
		a[u][v]=wt;
		next_on_path[u][v]=v;		// next node to visit if i am on u and want to go to v
	}
	scanf("%d %d",&src,&dst);
	for ( int k=0; k<n; k++ )
		for ( int i=0; i<n; i++ )
			for ( int j=0; j<n; j++ )
			{	if ( a[i][k] != INT_MAX && a[k][j] != INT_MAX )
					if ( a[i][k]+a[k][j] < a[i][j] )
					{	a[i][j]= a[i][k]+a[k][j];
						next_on_path[i][j]=next_on_path[i][k];
					}
				if( i == j && a[i][j] < 0 )
				{	printf("Negative Cycle\n");
					return 0;
				}
			}
	for ( int i=0; i<n; i++ )
	{	for ( int j=0; j<n; j++ )
			printf("%d\t", a[i][j]);
		printf("\n");
	}
	printf("path from %d to %d\n",src,dst);
	printf("%d ", src);
	while ( next_on_path[src][dst] != INT_MAX  )
	{	printf("%d ", next_on_path[src][dst]);
		src=next_on_path[src][dst];
	}
	printf("\n");
	return 0;
}
