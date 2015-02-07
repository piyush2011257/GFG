/*
http://www.geeksforgeeks.org/bipartite-graph/
DFS to check color of each node {-1,1}
We can use bfs alternatively and ensure that the color is synchronized even if already inserted in queue
*/
#include<cstdio>
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

bool bipartite ( head h[], int i, int *visited, int color );

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
	int visited[100]={0};
	printf("\n%d\n",bipartite(h,0,visited,1));
	return 0;
}

bool bipartite ( head h[], int i, int *visited, int color )
{	printf("%d ", i);
	visited[i]=color;
	node *tmp= h[i].lnext;
	bool val=0;
	while ( tmp != NULL )
	{	if ( visited[tmp->data] == 0 )
		{	val=bipartite(h, tmp->data,visited,color*(-1));
			if ( val == 0 )
				return 0;
		}
		else if ( visited[tmp->data] == color )
		{	printf("\nNOT bipartite at %d\n", tmp->data);
			return 0;
		}
		tmp=tmp->lnext;
	}
	return 1;
}
