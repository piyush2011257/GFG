/*
http://www.geeksforgeeks.org/dynamic-programming-set-23-bellman-ford-algorithm/

Shortest graph for directed graphs with negative edges using Queues
Why did we need Priority Queue in Dijkstra's Algorithm?
So that we can find the shortest distance vertex. Here this step is useless since we can get another shorter path in near future. Hence we can diectly use plain Queue instead of Priority QUeue.
Advantage
Popping / pushing from priority queue -> O(logV)
Popping / pushing from simple queue-> O(1)
Refer notes in NK

Proof-
https://www.youtube.com/watch?v=Ttezuzs39nk
*/

#include<cstdio>
#include<climits>
#include<queue>
using namespace std;

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

void bellman( int *dist, head *h, int n, int s, int e );
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
{	queue<int> q;			// we do not want any ordering in the order of weights
	dist[s]=0;
	node *temp=h[s].lnext;
	q.push(s);
	pos[s]=1;
	/* Queue contains
	   All elements that are yet not solved
	   All elements that were solved earlier but now in future we found new path which is shortera
	   Outside Queue
	   Shortest found so far

Since we do not need priority queue anymore since we do not care for getting minimum distance in a greedy manner and hence no need of weight, since it was needed for maintaing the heap structures
	dist[i[ -> minimum distance to i so far
	*/
	int ct=0, val;
	while ( ct < n )
	{	ct++;
		val=q.front();
		printf("element popped: %d %d\n", val, dist[val] );
		q.pop();
		pos[val]=0;
		node *temp=h[val].lnext;
		while ( temp != NULL )
		{	printf("data: %d %d %d\n", temp->data, dist[val], temp->wt);
			if ( dist[temp->data] == INT_MAX )
			{	q.push(temp->data);
				dist[temp->data]=temp->wt+dist[val];
				pos[temp->data]=1;
			}
			else if ( dist[temp->data] > dist[val] + temp->wt  )
			{	if ( pos[temp->data] == 0 )			// new shorter path found in future
				{	q.push(temp->data);
					pos[temp->data]=1;
				}
				dist[temp->data]= dist[val] + temp->wt;
			}
			temp=temp->lnext;
		}
	}
}
