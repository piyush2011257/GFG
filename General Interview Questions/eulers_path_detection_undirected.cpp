/*
http://www.geeksforgeeks.org/eulerian-path-and-circuit/
http://www.geeksforgeeks.org/fleurys-algorithm-for-printing-eulerian-path/

A graph is called Eulerian if it has an Eulerian Cycle and called Semi-Eulerian if it has an Eulerian Path. We can find whether a given graph has a Eulerian Path or not in polynomial time. In fact, we can find it in O(V+E) time.

Following are some interesting properties of undirected graphs with an Eulerian path and cycle. We can use these properties to find whether a graph is Eulerian or not.

Eulerian Cycle
An undirected graph has Eulerian cycle if following two conditions are true.
a) All vertices with non-zero degree are connected. We don’t care about vertices with zero degree because they don’t belong to Eulerian Cycle or Path (we only consider all edges).
b) All vertices have even degree.

Eulerian Path
An undirected graph has Eulerian Path if following two conditions are true.
a) Same as condition (a) for Eulerian Cycle
b) If zero or two vertices have odd degree and all other vertices have even degree. Note that only one vertex with odd degree is not possible in an undirected graph (sum of all degrees is always even in an undirected graph)

Note that a graph with no edges is considered Eulerian because there are no edges to traverse.

NOTE-
Above discussion wrt undirected graph, so edge{a,b} is treated as one single edge {a,b} == {b,a}
In case of directed graph, we treat them as 2 different edges only


Why degree should be even for cycle?
EUler cycle path - union of multiple disjoint eulerian cycles
One edge for going out and another to come back and complete the cycle and hence for each outgoing edge to start one cycle there is correspondi
ng incoming edge to handle the return to complete the eulerian disjoint cycle

Same case extened for directed graphs - 
start is outgoing edge and return edge for completing cycle is indegree edge

For eulerian path in undirected- 
2 nodes odd-? 1  having start only and 1 having end only

Extending for directed - 1 having ingree + 1 == outdegree for start of path and other having outdegree + 1 == indegree to terminate the path

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

void dfs ( head h[], int i, bool *visited );

int main()
{	int n, e, u, v;
	scanf("%d %d",&n,&e);
	head h[n];
	int degree[100]={0};
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
		degree[u]++;
		degree[v]++;
                u=u^v;
		v=u^v;
		u=u^v;
		if ( h[u].end == NULL )
                {       node *tmp=new node();
                        tmp->data=v;
                        h[u].lnext=h[u].end=tmp;
                }
                else
                {       node *tmp= new node();
                        tmp->data=v;
                        h[u].end->lnext=tmp;
                        h[u].end=tmp;
                }
	}
	// check connectedness for the given input graph
	bool visited[100]={0};
	dfs(h,0,visited);
	printf("\n");
	for ( int i=0; i<n; i++ )
		if ( visited[i] == 0 && h[i].lnext != NULL )		// avoid 0 degree vertices as they dont affect 
		{	printf("Non-Connected\n");
			return 0;
		}
	int count=0;
	for ( int i=0; i<n; i++ )
	{	printf("%d ", degree[i]);
		if ( degree[i] % 2 != 0 )
			count++;
	}
	printf("count: %d\n",count);
	if ( ! ( count == 0 || count == 2 ) )
	{	printf("Odd degree : %d\n", count);
		return 0;
	}
	if ( count == 2 )
		printf("Semi-Eulerian Graph\n");
	else
		printf("Eulerian Graph\n");
	return 0;
}

void dfs ( head h[], int i, bool *visited )
{	if ( visited[i] == 1 )
		return;
	printf("%d ", i);
	visited[i]=1;
	node *tmp= h[i].lnext;
	while ( tmp != NULL )
	{	if ( visited[tmp->data] == 0 )
			dfs(h, tmp->data,visited);
		tmp=tmp->lnext;
	}
}
