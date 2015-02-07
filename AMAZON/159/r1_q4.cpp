/*
Topological Sort
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

void topological ( head h[], int i, int *in, int *visit  );

int main()
{	int n, e, u, v;
	scanf("%d %d",&n,&e);
	head h[n];
	int in[100]={0};
	for ( int i=0; i<e; i++ )
	{	scanf("%d %d",&u,&v);
		in[v]++;
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
	int visit[100]={0};
	for ( int i=0; i<n; i++ )
		if ( in[i] == 0 )
		{	topological(h,i,in,visit);
			printf("\n");
		}
	printf("\n");
	return 0;
}

void topological ( head h[], int i, int *in, int *visit  )
{	printf("%d ",i);
	//printf("%d %d\n", visit[i], in[i]);
	node *tmp= h[i].lnext;
	while ( tmp != NULL )
	{	visit[tmp->data]++;
		if ( in[tmp->data] == visit[tmp->data] )
			topological(h, tmp->data,in,visit);
		tmp=tmp->lnext;
	}
}
