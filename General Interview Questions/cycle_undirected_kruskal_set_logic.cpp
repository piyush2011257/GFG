/*
http://www.geeksforgeeks.org/union-find/
http://www.geeksforgeeks.org/greedy-algorithms-set-2-kruskals-minimum-spanning-tree-mst/

Refer notes in NK
*/
#include<cstdio>
#include<algorithm>
using namespace std;

struct edges
{	int u, v;
};

int find_parent( int *a, int i )
{	if ( a[i] == i )
		return i;
	a[i]=find_parent(a,a[i]);
	return a[i];
}

int main()
{	int n,e;
	scanf("%d %d",&n,&e);
	edges edge[e];
	for ( int i=0; i<e; i++ )
		scanf("%d %d",&edge[i].u, &edge[i].v);
	int a[n],p1,p2;
	for ( int i=0; i<n; i++ )
		a[i]=i;
	for ( int i=0; i<e; i++ )
	{	p1=find_parent(a,edge[i].u);
		p2=find_parent(a,edge[i].v);
		if ( p1 == p2 )
		{	printf("Cycle detected with edge: %d %d\n", edge[i].u, edge[i].v);
			return 0;
		}
		a[p2]=p1;
	}
	// each set represents a set of vertices which form a spanning tree from those vertices
	printf("No cycle\n");
	return 0;
}
