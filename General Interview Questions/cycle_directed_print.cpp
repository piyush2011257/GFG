/*
http://www.geeksforgeeks.org/detect-cycle-in-a-graph/
Given a directed graph, how to check if there is a cycle in the graph?
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

void dfs ( head h[], int i, bool *visited, bool *in_stack, int parent, list<int> l );

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
	bool in_stack[100]={0}, visited[100]={0};
	list<int> l;
	dfs(h,0,visited,in_stack,-1,l);
	printf("\n");
	return 0;
}

// cycle detection only
void dfs ( head h[], int i, bool *visited, bool *in_stack, int parent, list<int> l )
{	//printf("visited: %d\n", i);
	visited[i]=in_stack[i]=1;
	l.push_front(i);
	node *tmp= h[i].lnext;
	while ( tmp != NULL )
	{	if ( in_stack[tmp->data] == 0 && visited[tmp->data] == 0 )
			dfs(h, tmp->data,visited,in_stack,i,l);
		else if ( in_stack[tmp->data] == 1 )
		{	printf("cycle: ");
			for ( list<int>::iterator iter=l.begin(); iter != l.end() && (*iter) != tmp->data; iter++ )
				printf("%d ", *iter);
			printf("%d\n", tmp->data);
		}
		tmp=tmp->lnext;
	}
	in_stack[i]=0;
	l.pop_front();
}
