/*
http://www.geeksforgeeks.org/bipartite-graph/
DFS to check color of each node {-1,1}
We can use bfs alternatively and ensure that the color is synchronized even if already inserted in queue
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

bool bfs ( head h[], int i );

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
	printf("\n%d\n",bfs(h,0));
	return 0;
}

bool bfs ( head h[], int i )
{       queue<int> q;
        int in_queue[100]={0};                         // Corner Case- in_queue == 1 not visited == 1
        q.push(i);
	in_queue[i]=1;
        while ( q.empty() == 0 )
        {       i=q.front();
                q.pop();
                printf("%d ", i);
                node *tmp= h[i].lnext;
                while ( tmp != NULL )
                {       if ( in_queue[tmp->data] == 0 )
                        {       q.push(tmp->data);
                                in_queue[tmp->data]=in_queue[i]*(-1);
                        }
			else if ( in_queue[tmp->data] == in_queue[i] )
			{	printf("NOT BIPARTITE at %d\n",tmp->data);
				return 0;
			}
                        tmp=tmp->lnext;
                }
        }
	return 1;
}

