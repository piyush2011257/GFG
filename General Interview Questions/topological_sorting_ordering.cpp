/*
http://www.geeksforgeeks.org/topological-sorting/
Refer noes in NK
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

void topological ( head h[], int i, int *visited, int *group );

int main()
{	int n, e, u, v;
	scanf("%d %d",&n,&e);
	head h[n];
	int indegree[100]={0}, group[100]={0};
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
		indegree[v]++;
	}
	for ( int i=0; i<n; i++ )
		if ( indegree[i] == 0 )
			topological(h,i,indegree,group);
	printf("\n");
	return 0;
}

void topological ( head h[], int i, int *indegree, int *group )
{	printf("-> %d %d\n", i, group[i]);
	node *tmp= h[i].lnext;
	while ( tmp != NULL )
	{	indegree[tmp->data]--;
		group[tmp->data]=group[i]+1 > group[tmp->data] ? group[i]+1 : group[tmp->data];		// logic, we need max to handle all old dependencies
		if ( indegree[tmp->data] == 0 )
		{	indegree[tmp->data]--;
			topological(h, tmp->data,indegree, group);
		}
		tmp=tmp->lnext;
	}
}
