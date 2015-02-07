/*
http://www.geeksforgeeks.org/detect-cycle-undirected-graph/
Given an undirected graph, how to check if there is a cycle in the graph?
*/

#include<cstdio>
#include<list>
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

void dfs ( head h[], int i, bool *visited, int parent );

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
	bool visited[100]={0};
	for ( int i=0; i<n; i++ )
		if ( visited[i] == 0 )
		{	dfs(h,i,visited,-1);
			printf("\n");
		}
	printf("\n");
	return 0;
}

// cycle detection only
void dfs ( head h[], int i, bool *visited, int parent )
{	printf("visited: %d\n", i);
	visited[i]=1;
	node *tmp= h[i].lnext;
	while ( tmp != NULL )
	{	if ( visited[tmp->data] == 0 )
			dfs(h, tmp->data,visited,i);
		else if ( tmp->data != parent )
		{	printf("cycle: ");
			printf("%d\n", tmp->data);
		}
		tmp=tmp->lnext;
	}
}
