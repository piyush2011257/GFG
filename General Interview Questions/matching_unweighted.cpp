/*
http://en.wikipedia.org/wiki/Matching_%28graph_theory%29#Algorithms_and_computational_complexity
http://www.geeksforgeeks.org/maximum-bipartite-matching/

http://stackoverflow.com/questions/22747088/maximum-bipartite-matching-ford-fulkerson
*/

#include<cstdio>
#include<queue>
#include<climits>
#include<cstdlib>
#include<cstring>
using namespace std;

void ford_fulkerson ( int s, int t, int n );
int bfs ( int s, int t, int n );
bool dfs_bipartite ( int s, int t, int n, int *visited );

int G[100][100];

void print ( int n )
{	for ( int i=0; i<n; i++ )
	{	for ( int j=0; j<n; j++ )
			printf("%d ", G[i][j]);
		printf("\n");
	}
}

int main()
{	int n,e,s,t,u,v,wt;
	printf("Enter points assuming 0 is taken as source and n-1 as destination\n");
	scanf("%d %d",&n,&e);
	for ( int i=0; i<e; i++ )
	{	scanf("%d %d",&u,&v);		// unweighted direc ted graph maximal matching
		G[u][v]=1;
		G[v][u]=0;
		G[0][u]=1;
		G[v][n-1]=1;
	}
	ford_fulkerson(0,n-1,n);
	printf("\n");
	return 0;
}

void ford_fulkerson ( int s, int t, int n )
{	int tmp, sum=0;
	int visited[n];
	memset(visited,0,n*sizeof(int));
	while ( tmp=dfs_bipartite (s,t,n,visited), tmp != 0 )		// there exists a directed path still
	{	sum += tmp;
		memset(visited,0,n*sizeof(int));
	}
	printf("Max flow / Min Cut: %d\n", sum);
}

bool dfs_bipartite ( int s, int t, int n, int *visited )
{	Visited[s]=1;
	if ( s == t )
		return 1;
	for ( int i=1; i<n; i++ )
	{	if ( visited[i] == 0 && G[s][i] > 0 )
		{	if ( dfs_bipartite(i,t,n,visited) == 1 )
			{	G[s][i]--;
				G[i][s]++;
				return 1;
			}
		}
	}
	return 0;
}
