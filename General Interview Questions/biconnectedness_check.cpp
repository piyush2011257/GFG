/*
http://www.geeksforgeeks.org/biconnectivity-in-a-graph/
Undirected Graphs

http://en.wikipedia.org/wiki/Biconnected_graph
Biconnectedness vs k-connectedness
In graph theory, a biconnected graph is a connected and "nonseparable" graph, meaning that if any vertex were to be removed, the graph will remain connected. Therefore a biconnected graph has no articulation vertices.

The property of being 2-connected is equivalent to biconnectivity, with the caveat that the complete graph of two vertices is sometimes regarded as biconnected but not 2-connected.

http://math.stackexchange.com/questions/810295/biconnected-graphs-versus-k-connected-graph
If G is k-connected for k≥2, then it is indeed biconnected. However, the converse does not hold. You can have a biconnected graph that is not k-connected for k≥2.

Ig a graph is k-connected for k>=2 implies graph is biconnected BUT if graph is biconnected does not imply that graph is 2-connected always. It will K-connected for some fixed K

*/

#include<cstdio>
#include<queue>
using namespace std;

struct head
{	struct node *lnext, *end;
	head()
	{	lnext=end=NULL;	}
};

struct node
{	int data;
	struct node *lnext;
	node()
	{	lnext=NULL;	}
};

bool cut_vertex ( head h[], int i, int *dfsnum, int *low, int num, int *parent );

int main()
{	int n, e, u, v;
	scanf("%d %d",&n,&e);
	head h[n];
	for ( int i=0; i<e; i++ )
	{	scanf("%d %d",&u,&v);
		if ( h[u].end == NULL )
		{	node *tmp=new node();
			tmp->data=v;
			h[u].lnext=h[u].end=tmp;
		}
		else
		{	node *tmp= new node();
			tmp->data=v;
			h[u].end->lnext=tmp;
			h[u].end=tmp;
		}
                if ( h[v].end == NULL )
                {       node *tmp=new node();
                        tmp->data=u;
                        h[v].lnext=h[v].end=tmp;
                }
                else
                {       node *tmp= new node();
                        tmp->data=u;
                        h[v].end->lnext=tmp;
                        h[v].end=tmp;
                }
	}
	int dfsnum[100], low[100], parent[100];
	for ( int i=0; i<n; i++ )
		parent[i]=dfsnum[i]=low[i]=-1;
	printf("%d\n",cut_vertex(h,0,dfsnum,low,0,parent));
	return 0;
}

bool cut_vertex ( head h[], int i, int *dfsnum, int *low, int num, int *parent )
{ 	dfsnum[i]=low[i]=num;
	//printf("%d ", i);
	node *tmp= h[i].lnext;
	int child=0;
	while ( tmp != NULL )
	{	if ( dfsnum[tmp->data] == -1 )
		{	parent[tmp->data]=i;
			child++;
			if (  cut_vertex(h, tmp->data,dfsnum, low, num+1, parent) == 0 )
				return 0;
			if ( low[tmp->data] >= dfsnum[i] && parent[i] != -1)
				return 0;
			low[i]= low[i] < low[tmp->data] ? low[i] : low[tmp->data];
			if ( parent[i] == -1 && child > 1 )		// root node of DFS MST having more than 1 child in DFS MST
				return 0;
		}
		else if ( tmp->data != parent[i] )		// for back edge. if tmp->data == parent[i] NOT  a back edge. Undirected graph edge repeated!! Undirected graphs NOT directed!!
			low[i]=low[i] < dfsnum[tmp->data] ? low[i] : dfsnum[tmp->data];
		tmp=tmp->lnext;
	}
	return 1;
}

/*
7 8
0 1
1 2
2 3
3 0
2 6
3 4
4 5
5 3

7 8
0 1
1 2
2 3
3 0
0 4
4 5
5 6
6 0

5 6
0 1
1 2
2 3
2 4
3 4
2 0
*/
