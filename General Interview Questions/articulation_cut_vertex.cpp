/*
http://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/
Refer NK
Undirected Graphs
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

void cut_vertex ( head h[], int i, int *dfsnum, int *low, int num, int *parent );

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
	cut_vertex(h,0,dfsnum,low,0,parent);
	printf("\n");
	return 0;
}

void cut_vertex ( head h[], int i, int *dfsnum, int *low, int num, int *parent )
{ 	dfsnum[i]=low[i]=num;
	printf("%d ", i);
	node *tmp= h[i].lnext;
	int child=0;
	while ( tmp != NULL )
	{	if ( dfsnum[tmp->data] == -1 )
		{	parent[tmp->data]=i;
			child++;
			cut_vertex(h, tmp->data,dfsnum, low, num+1, parent);
			if ( low[tmp->data] >= dfsnum[i] && parent[i] != -1)
			// the subtree can reach any ancestor of u and hence u is cut-vertex
				printf("Cut vertex: %d\n",i);
			low[i]= low[i] < low[tmp->data] ? low[i] : low[tmp->data];
			if ( parent[i] == -1 && child > 1 )		// root node of DFS MST having more than 1 child in DFS MST
				printf("Cut Vertex: %d\n",i);
		}
		else if ( tmp->data != parent[i] )		// for back edge. if tmp->data == parent[i] NOT  a back edge. Undirected graph edge repeated!! Undirected graphs NOT directed!!
			low[i]=low[i] < dfsnum[tmp->data] ? low[i] : dfsnum[tmp->data];
		tmp=tmp->lnext;
	}
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
