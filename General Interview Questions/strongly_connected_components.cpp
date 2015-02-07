/*
http://www.geeksforgeeks.org/tarjan-algorithm-find-strongly-connected-components/
http://www.geeksforgeeks.org/strongly-connected-components/
Directed Graphs
*/

#include<cstdio>
#include<stack>
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

void cut_vertex ( head h[], int i, int *dfsnum, int *low, int num, int *parent, stack<int> &s );

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
	}
	int dfsnum[100], low[100], parent[100];
	for ( int i=0; i<n; i++ )
		parent[i]=dfsnum[i]=low[i]=-1;
	stack<int>s;
	cut_vertex(h,0,dfsnum,low,0,parent,s);
	printf("\n");
	return 0;
}

void cut_vertex ( head h[], int i, int *dfsnum, int *low, int num, int *parent, stack<int> &s )
{ 	dfsnum[i]=low[i]=num;
	//printf("%d ", i);
	s.push(i);
	node *tmp= h[i].lnext;
	while ( tmp != NULL )
	{	if ( dfsnum[tmp->data] == -1 )
		{	parent[tmp->data]=i;
			cut_vertex(h, tmp->data,dfsnum, low, num+1, parent,s);
			low[i]= low[i] < low[tmp->data] ? low[i] : low[tmp->data];
		}
		else /* if in_stack[tmp->data] == 1*/		// <- no effect as low[i[ < dfsnum[tmp->data] in case of cross edge
			low[i]=low[i] < dfsnum[tmp->data] ? low[i] : dfsnum[tmp->data];
		tmp=tmp->lnext;
	}
	if ( low[i] == dfsnum[i] )
	{	printf("\nComponent\n");
		int pop=s.top();
		s.pop();
		while ( s.empty() == 0 && pop != i )
		{	printf("%d ", pop);
			pop=s.top();
			s.pop();
		}
		printf("%d\n",pop);
	}		
}

/*
Cross edge vs Forward Edge vs Backward Edge
http://en.wikipedia.org/wiki/Depth-first_search#Output_of_a_depth-first_search

E.g.

6 8
0 1
1 2
2 0
1 3
3 4
4 5
5 3
1 4	<- Cross edge

Tarjan Algorithm is based on following facts:
1. DFS search produces a DFS tree/forest
2. Strongly Connected Components form subtrees of the DFS tree.
3. If we can find head of such subtrees, we can print/store all the nodes in that subtree (including head) and that will be one SCC.
4. There is no back edge from one SCC to another (There can be cross edges, but cross edges will not be used while processing the graph).



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
