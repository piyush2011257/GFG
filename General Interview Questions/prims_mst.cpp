/*
http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-mst-for-adjacency-list-representation/

Instead of maintaining explicit pointers to heap positions. Just update the entry and heapify!!!
http://www.geeksforgeeks.org/greedy-algorithms-set-7-dijkstras-algorithm-for-adjacency-list-representation/

Refer notes in NK
*/

#include<cstdio>
using namespace std;

struct hp
{	int data, wt;
}heap[100];

int size=0, pos[100], parent[100];

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
void prims( int *dist, head *h, int n );
void insert( int data, int wt );
void update( int data, int wt );
void print_heap();
void print_parent ( int n );

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
                if ( h[v].end == NULL )
                {       node *tmp=new node();
                        tmp->wt=wt;
			tmp->data=u;
                        h[v].lnext=h[v].end=tmp;
                }
                else
                {       node *tmp= new node();
                        tmp->wt=wt;
			tmp->data=u;
                        h[v].end->lnext=tmp;
                        h[v].end=tmp;
                }
        }
	int s;
	int dist[n];
	for ( int i=0; i<n; i++ )
		dist[i]=-1;
	printf("distance matrix\n");
	prims(dist,h,n);
	print_parent(n);
	return 0;
}

void print_parent ( int n )
{	printf("parent\n");
	for ( int i=0; i<n; i++ )
		printf("%d ", parent[i]);
	printf("\n");
}

void prims( int *dist, head *h, int n )
{	for ( int i=0; i<n; i++ )
		parent[i]=-1;
	dist[0]=0;
	node *temp=h[0].lnext;
	insert(0,0);
	int ct=0, val;
	print_heap();
	while ( ct < n )
	{	ct++;
		val=heap[0].data;
		printf("element popped: %d\n", val);
		del();
		//printf("after delete\n");
		//print_heap();
		node *temp=h[val].lnext;
		while ( temp != NULL )
		{	printf("data: %d wt: %d\n", temp->data, temp->wt);
			if ( dist[temp->data] == -1 )
			{	insert(temp->data, temp->wt);
				dist[temp->data]=temp->wt;
				parent[temp->data]=val;
			}
			else if ( dist[temp->data] > temp->wt && pos[temp->data] != -1 )	// tricky case here!! If element is already solved. COnsider below test case
			{	update(temp->data, temp->wt);
				dist[temp->data]= temp->wt;
				parent[temp->data]=val;
			}
			temp=temp->lnext;
		}
		print_parent(n);
		//printf("after while\n");
		print_heap();
	}
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
{	//printf("delete\n");
	pos[heap[0].data]=-1;			// this is needed to tell that this element has been solved
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

void update( int data, int wt )		// update up in this case!!
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
