#include<cstdio>
#include<algorithm>
using namespace std;

struct edges
{	int u, v, wt;
};

bool cmp ( edges a, edges b )
{	if (a.wt <= b.wt )
		return 1;
	return 0;
}

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
		scanf("%d %d %d",&edge[i].u, &edge[i].v, &edge[i].wt);
	sort(edge,edge+e,cmp);
	int a[n];
	int shortest_edges[e][2], pos=0;
	for ( int i=0; i<n; i++ )
		a[i]=i;
	for ( int i=0; i<e; i++ )
	{	int p1=find_parent(a,edge[i].u);
		int p2=find_parent(a,edge[i].v);
		if ( p1 == p2 )
			continue;
		a[p2]=p1;
		shortest_edges[pos][0]=edge[i].u;
                shortest_edges[pos][1]=edge[i].v;		// add the edge in the solution set
		pos++;		
	}
	for ( int i=0; i<pos; i++ )
		printf("%d %d\n", shortest_edges[i][0], shortest_edges[i][1]);
	return 0;
}
