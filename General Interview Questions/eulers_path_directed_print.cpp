/*
http://www.geeksforgeeks.org/euler-circuit-directed-graph/

How to check if a directed graph is eulerian?
A directed graph has an eulerian cycle if following conditions are true (Source: Wiki)
1) All vertices with nonzero degree belong to a single strongly connected component.
2) In degree and out degree of every vertex is same.	( 1 for going out and 1 for coming back to complete smaller eulerian cycles )

http://en.wikipedia.org/wiki/Eulerian_path#Properties

Assuming that there is an eulerian circuit

For eulerian path just like case of directed graphs
A directed graph has an Eulerian trail if and only if at most one vertex has (out-degree) − (in-degree) = 1, at most one vertex has (in-degree) − (out-degree) = 1, every other vertex has equal in-degree and out-degree, and all of its vertices with nonzero degree belong to a single connected component of the underlying undirected graph.
Start from such vertex if any


Why degree should be even for cycle?
EUler cycle path - union of multiple disjoint eulerian cycles
One edge for going out and another to come back and complete the cycle and hence for each outgoing edge to start one cycle there is correspondi
ng incoming edge to handle the return to complete the eulerian disjoint cycle

Same case extened for directed graphs - 
start is outgoing edge and return edge for completing cycle is indegree edge

For eulerian path in undirected- 
2 nodes odd-? 1  having start only and 1 having end only

Extending for directed - 1 having ingree + 1 == outdegree for start of path and other having outdegree + 1 == indegree to terminate the path

*/

#include<cstdio>
#include<queue>
#include<list>
using namespace std;

struct head
{	struct node *lnext, *end;
	head()
	{	lnext=end=NULL;	}
};

struct node
{	int data, visited;
	struct node *lnext;
	node()
	{	lnext=NULL;	}
};

void dfs ( head h[], int i, list<int> &l, list<int>::iterator iter );
void print(list<int> l);

int mod ( int a )
{	if ( a< 0 )
		a*=(-1);
	return a;
}

int main()
{	int n, e, u, v;
	scanf("%d %d",&n,&e);
	head h[n];
	int indegree[100]={0}, outdegree[100]={0};
	for ( int i=0; i<e; i++ )
	{	scanf("%d %d",&u,&v);
		indegree[v]++;
		outdegree[u]++;
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
	int ct=-1, ct2=-1;
	for ( int i=0; i<n; i++ )
		if ( mod(outdegree[i] - indegree[i]) > 1 )
		{	printf("Outdegree-indegree > 1\n");
			return 0;
		}
		else if ( outdegree[i] - indegree[i] == 1 )
		{	if ( ct != -1 )
			{	printf("Multiple nodes with outdegree-indegree == 1\n");
				return 0;
			}
			else
				ct=i;
		}
		else if ( indegree[i] - outdegree[i] == 1 )
		{	if ( ct2 != -1 )
			{	printf("Multiple nodes with indegree-outdegree == 1\n");
				return 0;
			}
			else
				ct2=i;
		}
	list<int>l;
	if ( ct == -1 )
		ct=0;
	//printf("Ct: %d\n",ct);
	dfs(h,ct,l,l.begin());
	printf("\n");
	print(l);
	return 0;
}

void print ( list <int> l )
{        for ( list<int>::iterator iter=l.begin(); iter != l.end(); iter++ )
                printf("%d ",*iter);
	printf("\n");
}
void dfs ( head h[], int i, list<int> &l1 , list<int>::iterator iter )
{	l1.push_back(i);
	iter++;
	//printf("dfs: %d ", i);
	node *tmp= h[i].lnext;
	list<int> l2;
	while ( tmp != NULL )
	{	if ( tmp->visited == 0 )
		{	tmp->visited=1;
			l2.clear();
			dfs(h, tmp->data, l2, l2.begin() );
		}
		/*printf("\nl1: ");
		print(l1);
		printf("l2: ");
		print(l2);
		printf("iter: %d\n",*iter);*/
		list<int>::iterator iter2=iter;
		iter2++;
		l1.splice(iter2,l2);
		tmp=tmp->lnext;
	}
}

/*
5 5
2 1
0 2
4 3
3 4
2 4

0 2 4 3 4 1 
Eulerian Path with 0 having odd vertex

5 6
1 0
2 1
0 2
0 3
3 4
4 0

0 2 1 0 3 4 0

6 10        
0 1
1 2
2 0
1 3
3 4 3 5
5 4
4 1 4 2
2 3

0 1 2 3 4 1 3 5 4 2 0 

6 7
0 1 1 2 2 3 3 0
3 1
1 5
4 3

4 3 0 1 2 3 1 5 
*/
