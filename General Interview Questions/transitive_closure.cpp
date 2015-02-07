/*
http://www.geeksforgeeks.org/transitive-closure-of-a-graph/
Given a directed graph, find out if a vertex j is reachable from another vertex i for all vertex pairs (i, j) in the given graph. Here reachable mean that there is a path from vertex i to j. The reach-ability matrix is called transitive closure of a graph.
The graph is given in the form of adjacency matrix say ‘graph[V][V]’ where graph[i][j] is 1 if there is an edge from vertex i to vertex j or i is equal to j, otherwise graph[i][j] is 0.

Floyd Warshall Algorithm can be used, we can calculate the distance matrix dist[V][V] using Floyd Warshall, if dist[i][j] is infinite, then j is not reachable from i, otherwise j is reachable and value of dist[i][j] will be less than V.
Instead of directly using Floyd Warshall, we can optimize it in terms of space and time, for this particular problem. Following are the optimizations:

1) Instead of integer resultant matrix (dist[V][V] in floyd warshall), we can create a boolean reach-ability matrix reach[V][V] (we save space). The value reach[i][j] will be 1 if j is reachable from i, otherwise 0.
*/

#include<cstdio>
#include<climits>
using namespace std;

int main()
{	int n,e,u,v;
	scanf("%d %d",&n,&e);
	bool a[n][n];
	for ( int i=0; i<n; i++ )
		for ( int j=0; j<n; j++ )
			a[i][j]= ( i != j ) ? 0 : 1;
	for ( int i=0; i<e; i++ )
	{	scanf("%d %d",&u,&v);
		a[u][v]=1;
	}
	for ( int k=0; k<n; k++ )
		for ( int i=0; i<n; i++ )
			for ( int j=0; j<n; j++ )
				if ( a[i][k] == 1 && a[k][j] == 1 )
					a[i][j]=1;
	for ( int i=0; i<n; i++ )
	{	for ( int j=0; j<n; j++ )
			printf("%d\t", a[i][j]);
		printf("\n");
	}
	return 0;
}
