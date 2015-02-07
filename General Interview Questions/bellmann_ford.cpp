/*
http://www.geeksforgeeks.org/dynamic-programming-set-23-bellman-ford-algorithm/

Shortest graph for directed graphs with negative edges using Priority Queue
Refer notes in NK
*/

#include<cstdio>
#include<climits>
using namespace std;

struct hp
{	int data, wt;
}heap[100];

int size=0, pos[100];

struct head
{       struct node *lnext, *end;
        head()
        {       lnext=end=NULL; }
};

struct node
{       int data,wt;
        struct node *lnext;
        node()
        {       lnext=NULL;     }
};

void del ( );
void bellman( int *dist, head *h, int n, int s, int e );
void insert( int data, int wt );
void update( int data, int wt );
void print_heap();

int main()
{	int n,e,wt,u,v;
	scanf("%d %d",&n,&e);
        head h[n];
        for ( int i=0; i<e; i++ )
        {       scanf("%d %d %d",&u,&v,&wt);
                if ( h[u].end == NULL )
                {       node *tmp=new node();
                        tmp->data=v;
                        tmp->wt=wt;
			h[u].lnext=h[u].end=tmp;
                }
                else
                {       node *tmp= new node();
                        tmp->wt=wt;
			tmp->data=v;
                        h[u].end->lnext=tmp;
                        h[u].end=tmp;
                }
        }
	int s;
	scanf("%d %d",&s,&e);
	int dist[n];
	for ( int i=0; i<n; i++ )
		dist[i]=INT_MAX;		// distances can be -ve now
	printf("distance matrix\n");
	bellman(dist,h,n,s,e);
	for ( int i=0; i<n; i++ )
		printf("%d ", dist[i]);
	printf("\n");
	return 0;
}

void bellman( int *dist, head *h, int n, int s, int e )
{	dist[s]=0;
	node *temp=h[s].lnext;
	insert(s,0);
	int ct=0, val;
	print_heap();
	while ( ct < n )
	{	ct++;
		val=heap[0].data;
		printf("element popped: %d\n", val);
		del();
		printf("after delete\n");
		print_heap();
		node *temp=h[val].lnext;
		while ( temp != NULL )
		{	printf("data: %d %d %d\n", temp->data, dist[val], temp->wt);
			if ( dist[temp->data] == INT_MAX )
			{	insert(temp->data, temp->wt+dist[val]);
				dist[temp->data]=temp->wt+dist[val];
			}
			else if ( dist[temp->data] > dist[val] + temp->wt  )
			{	if ( pos[temp->data] == -1 )			// if not in queue, means we had solved it earlier, but now we have a shorter path available so re-insert and update shortest path
					insert(temp->data, dist[val] + temp->wt);
				else
					update(temp->data, dist[val] + temp->wt);
				dist[temp->data]= dist[val] + temp->wt;
			}
			temp=temp->lnext;
		}
		printf("after insert/update\n");
		print_heap();
	}
	/*
	Using heap complexity is O(EVlogV)
	*/
}

void insert( int data, int wt )
{	printf("insert\n");
	heap[size].data=data;
	heap[size].wt=wt;
	pos[data]=size;
	size++;
	int q=size-1;
	int p=(q-1)/2;
	while ( q > 0 && heap[p].wt > heap[q].wt )
	{	hp t=heap[p];
		heap[p]=heap[q];
		heap[q]=t;
		pos[heap[p].data]=p;
		pos[heap[q].data]=q;
		q=p;
		p=(q-1)/2;
	}
}

void del ( )
{	printf("delete\n");
	pos[heap[0].data]=-1;
	heap[0]=heap[size-1];
	pos[heap[0].data]=0;
	int q=0;
	int l=1;
	size--;
	while ( l < size )
	{	int min;
		if ( l+1 < size )
			min=heap[l].wt < heap[l+1].wt ? l : l+1;
		else
			min=l;
		//print_heap();
		if ( heap[q].wt > heap[min].wt )
		{	hp t=heap[q];;
			heap[q]=heap[min];
			heap[min]=t;
			pos[heap[q].data]=q;
			pos[heap[min].data]=min;
			q=min;
			l=min*2+1;
		}
		else
			break;
		//print_heap();
	}
}

void update( int data, int wt )
{	printf("update\n");
	int q=pos[data];
        heap[q].wt=wt;
	int p=(q-1)/2;
	while ( q > 0 && heap[p].wt > heap[q].wt )
        {       hp t=heap[p];
                heap[p]=heap[q];
                heap[q]=t;
                pos[heap[p].data]=p;
                pos[heap[q].data]=q;
                q=p;
                p=(q-1)/2;
        }
}


void print_heap()
{	printf("print heap\n");
	for ( int i=0; i<size; i++ )
		printf("%d %d %d\n", heap[i].data, heap[i].wt, pos[heap[i].data]);
	printf("\n");
}
