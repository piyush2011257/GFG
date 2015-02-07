/*
http://www.geeksforgeeks.org/dynamic-programming-set-23-bellman-ford-algorithm/

Shortest graph for directed graphs with negative edges using Queues
Why did we need Priority Queue in Dijkstra's Algorithm?
So that we can find the shortest distance vertex. Here this step is useless since we can get another shorter path in near future. Hence we can diectly use plain Queue instead of Priority QUeue.
Advantage
Popping / pushing from priority queue -> O(logV)
Popping / pushing from simple queue-> O(1)
Refer notes in NK

Proof-
https://www.youtube.com/watch?v=Ttezuzs39nk
*/

#include<cstdio>
#include<climits>
#include<queue>
using namespace std;

int size=0, pos[100];

struct edges
{	int u,v,wt;	};

void bellman( int *dist, edges *edge, int n, int s, int e );
void print_heap();

int main()
{	int n,e,wt,u,v;
	scanf("%d %d",&n,&e);
        edges edge[e];
        for ( int i=0; i<e; i++ )
               scanf("%d %d %d",&edge[i].u,&edge[i].v,&edge[i].wt);
	int s;
	scanf("%d",&s);
	int dist[n];
	for ( int i=0; i<n; i++ )
		dist[i]=INT_MAX;		// distances can be -ve now
	printf("distance matrix\n");
	dist[s]=0;
	bellman(dist,edge,n,s,e);
	for ( int i=0; i<n; i++ )
		printf("%d ", dist[i]);
	printf("\n");
	return 0;
}

void bellman( int *dist, edges * edge, int n, int s, int e )
{	for ( int i=1; i<n; i++ )
	{	for ( int i=0; i<e; i++ )
		{	int u=edge[i].u;
			int v=edge[i].v;
			if (  dist[u] != INT_MAX && dist[u]+edge[i].wt < dist[v] )	// dist[u] != INT_MAX is important since we can have -ve weights as well so INT_MAX would appear to be a valid weight
				dist[v]=dist[u]+edge[i].wt;
		}
		for ( int i=0; i<n; i++ )
			printf("%d ", dist[i]);
		printf("\n");
	}
	for ( int i=0; i<n; i++ )
	{	if ( dist[edge[i].v] > dist[edge[i].u]+edge[i].wt )
		{	printf("Negative Cycle\n");
			return;
		}
	}
}

/* INT_MAX+1 -> -INT_MAX
5 8
0 1 -1     
1 2 3     
0 2 4
3 2 5
3 1 1
1 3 2
4 3 -3
1 4 2
0
distance matrix
0 -2147483648 -2147483644 -2147483646 -2147483646 
0 -2147483648 -2147483645 -2147483646 -2147483646 
0 -2147483648 -2147483645 -2147483646 -2147483646 
0 -2147483648 -2147483645 -2147483646 -2147483646 
0 -2147483648 -2147483645 -2147483646 -2147483646 

5 8
0 1 -1     
1 2 3     
0 2 4
3 2 5
3 1 1
1 3 2
4 3 -3
1 4 2
0
distance matrix
0 -1 2 1 1 
0 -1 2 -2 1 
0 -1 2 -2 1 
0 -1 2 -2 1 
0 -1 2 -2 1 
*/
