/*
http://www.geeksforgeeks.org/dynamic-programming-set-16-floyd-warshall-algorithm/

http://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm#Behavior_with_negative_cycles
A negative cycle is a cycle whose edges sum to a negative value. There is no shortest path between any pair of vertices i, j which form part of a negative cycle, because path-lengths from i to j can be arbitrarily small (negative). For numerically meaningful output, the Floyd–Warshall algorithm assumes that there are no negative cycles. Nevertheless, if there are negative cycles, the Floyd–Warshall algorithm can be used to detect them. The intuition is as follows:

    The Floyd–Warshall algorithm iteratively revises path lengths between all pairs of vertices (i, j), including where i = j;
    Initially, the length of the path (i,i) is zero;
    A path {(i,k), (k,i)} can only improve upon this if it has length less than zero, i.e. denotes a negative cycle;
    Thus, after the algorithm, (i,i) will be negative if there exists a negative-length path from i back to i.

Hence, to detect negative cycles using the Floyd–Warshall algorithm, one can inspect the diagonal of the path matrix, and the presence of a negative number indicates that the graph contains at least one negative cycle.[2] To avoid numerical problems one should check for negative numbers on the diagonal of the path matrix within the inner for loop of the algorithm.[3] Obviously, in an undirected graph a negative edge creates a negative cycle (i.e., a closed walk) involving its incident vertices. Considering all edges of the above example graph as undirected, e.g. the vertice sequence 4 - 2 - 4 is a cycle with weight sum -2.


http://www.geeksforgeeks.org/dynamic-programming-set-23-bellman-ford-algorithm/
1) This step initializes distances from source to all vertices as infinite and distance to source itself as 0. Create an array dist[] of size |V| with all values as infinite except dist[src] where src is source vertex.

2) This step calculates shortest distances. Do following |V|-1 times where |V| is the number of vertices in given graph.
…..a) Do following for each edge u-v
………………If dist[v] > dist[u] + weight of edge uv, then update dist[v]
………………….dist[v] = dist[u] + weight of edge uv

3) This step reports if there is a negative weight cycle in graph. Do following for each edge u-v
……If dist[v] > dist[u] + weight of edge uv, then “Graph contains negative weight cycle”
The idea of step 3 is, step 2 guarantees shortest distances if graph doesn’t contain negative weight cycle. If we iterate through all edges one more time and get a shorter path for any vertex, then there is a negative weight cycle
*/

#include<cstdio>
#include<climits>
using namespace std;

int main()
{	int n,e,u,v,wt;
	scanf("%d %d",&n,&e);
	int a[n][n];
	for ( int i=0; i<n; i++ )
		for ( int j=0; j<n; j++ )
			if ( i != j )
				a[i][j]=INT_MAX;
			else
				a[i][j]=0;
		// overflow if INT_MAX + any positive number and hence we will place a check. int_max + 1 -> -int_max ( cyclic nature )
	for ( int i=0; i<e; i++ )
	{	scanf("%d %d %d",&u,&v,&wt);
		a[u][v]=wt;
	}
	for ( int k=0; k<n; k++ )
		for ( int i=0; i<n; i++ )
			for ( int j=0; j<n; j++ )
			{	if ( a[i][k] != INT_MAX && a[k][j] != INT_MAX )
					if ( a[i][k]+a[k][j] < a[i][j] )
						a[i][j]= a[i][k]+a[k][j];
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
			
	return 0;
}
