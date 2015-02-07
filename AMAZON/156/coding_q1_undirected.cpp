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

void dfs ( head h[], int i, bool *in_stack, int parent, list<int> &l );

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
	bool in_stack[100]={0};
	list<int> l;
	for ( int i=0; i<n; i++ )
	dfs(h,i,in_stack,-1,l);
	printf("\n");
	return 0;
}

// cycle detection only. Additionally remove ambiguous cycles
void dfs ( head h[], int i, bool *in_stack, int parent, list<int> &l )
{	//printf("visited: %d\n", i);
	in_stack[i]=1;
	l.push_front(i);
	node *tmp= h[i].lnext;
	while ( tmp != NULL )
	{	if ( in_stack[tmp->data] == 0 )
			dfs(h, tmp->data,in_stack,i,l);
		else if ( tmp->data != parent )
		{	printf("cycle: ");
			for ( list <int>::iterator iter=l.begin(); *iter != tmp->data && iter != l.end(); iter++ )
				printf("%d ", *iter);
			printf("%d\n", tmp->data);
		}
		tmp=tmp->lnext;
	}
	l.pop_front();
	in_stack[i]=0;
}
