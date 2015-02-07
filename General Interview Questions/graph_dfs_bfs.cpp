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
void bfs ( head h[], int i );

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
	bool visited[100]={0};
	for ( int i=0; i<n; i++ )
		if ( visited[i] == 0 )
		{	dfs(h,i,visited);
			printf("\n");
			bfs(h,i);
		}
	printf("\n");
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

void bfs ( head h[], int i )
{	queue<int> q;
	bool in_queue[100]={0};				// Corner Case- in_queue == 1 not visited == 1
	q.push(i);
	in_queue[i]=1;
	do
	{	i=q.front();
		q.pop();
		printf("%d ", i);
		node *tmp= h[i].lnext;
		while ( tmp != NULL )
		{	if ( in_queue[tmp->data] == 0 )
			{	q.push(tmp->data);
				in_queue[tmp->data]=1;
			}
			tmp=tmp->lnext;
		}
	} while ( q.empty() == 0 );
}

/*
Corner Case-
9
11
0 1 0 2 0 3 
1 4
4 2
2 5
5 3
3 7
5 8
4 6
4 7
0 1 4 2 5 3 7 8 6 
0 1 2 3 4 5 7 6 8
*/
