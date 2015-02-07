/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-167-sde-1-year-6-months-experience/

SOlution Idea-
Using Brute force type of methodology
For each node as root try to find all critical pairs
Do a BFS
visited -> order[]
order[i] = position in height
is a node is already visited and new ordering != old_ordering -> NOT critical with root node
Now all nodes at height 2 ( o is height of root taken ) and valid for critical node are critical nodes
*/

#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;

struct node
{	int data;
	node *next;
	node()
	{	next=NULL;	}
	node ( int d  )
	{	data=d;	}
};


struct header
{	node *lnext, *end;
	header()
	{	lnext=end=NULL;		}
};

void critical_node ( header *h, int n, int i );

int main()
{	int n,e,u,v;
	cin>>n>>e;
	header h[n];
	for ( int j=0; j<e; j++ )
	{	cin>>u>>v;
		if ( h[u].end == NULL )
			h[u].lnext = h[u].end=new node(v);
		else
		{	h[u].end->next=new node(v);
			h[u].end=h[u].end->next;
		}
		u=u^v;
		v=u^v;
		u=u^v;
                if ( h[u].end == NULL )
                        h[u].lnext = h[u].end=new node(v);
                else
                {       h[u].end->next=new node(v);
                        h[u].end=h[u].end->next;
                }
	}
	for ( int i=0; i<n; i++ )
		critical_node(h,n,i);		//O(EV + V^2)
	return 0;
}

void critical_node ( header *h, int n, int i )
{	int order[n];				// optimization, we need only order[0] and order[2] to get critical nodes
	for ( int j=0; j<n; j++ )
		order[j]=-1;
	bool critical[n];
	memset(critical,0,sizeof(critical));
	order[i]=0;
	queue<int> q;
	q.push(i);
	while ( q.empty() == 0 )
	{	int t=q.front();
		q.pop();
		int probable_order=order[t]+1;
		node *tmp=h[t].lnext;
		while (tmp != NULL )
		{	if ( order[tmp->data] != -1 && order[tmp->data] != probable_order )
				critical[tmp->data]=0;
			else if ( order[tmp->data] == -1 )
			{	order[tmp->data]= probable_order;
				critical[tmp->data]=1;
				q.push(tmp->data);
			}
			tmp=tmp->next;
		}
	}
	cout<<"Critical for "<<i<<": ";
	for ( int j=0; j<n; j++ )
	{	if ( i != j )
		{	if ( critical[j] == 1 && order[j] == 2 )
				cout<<"{"<<i<<","<<j<<"}  ";
		}
	}
	cout<<endl;
	// We can remove redundant o/p by using maps if i,j are critical pair m[i].push_back(j) and m[j].push_back[i] ( DLL + MAP ). Alternately use a 2d matrix for chechking this criticality of nodes.
}
