/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-157-campus/
http://www.geeksforgeeks.org/a-product-array-puzzle/

Using a segment tree. In efficient for finding product for queestion. This technique more effective if we need product of a range 
Time- O(logN) for each query
*/

#include<cstdio>
using namespace std;

struct node
{	node *right, *left;
	int data;
	node()
	{	right=left=NULL;	}
	node ( int d )
	{	data=d;		}
};

int query ( node *root, int s , int e, int l, int r );
node * build ( int *a, int s, int e );

int main()
{	int d;
	scanf("%d",&d);
	int a[d];
	for ( int i=0; i<d; i++ )
		scanf("%d",a+i);
	node *root=build(a,0,d-1);
	int ele;
	while ( scanf("%d",&ele))
	{	ele--;
		int l,r;
		if ( ele < 0 || ele > d-1 )
		{	printf("invalid\n");
			continue;
		}
		if ( ele-1 >= 0 )
			l=query(root,0,d-1,0,ele-1);
		else
			l=1;
		if ( ele+1 <= d-1 )
			r=query(root,0,d-1,ele+1,d-1);
		else
			r=1;
		printf("%d\n", l*r);
	}
	return 0;
}

node * build ( int *a, int s, int e )
{	if ( s > e )
		return NULL;
	if ( s == e )
	{	node  *tmp= new node(a[s]);
		return tmp;
	}
	int m=(s+e)/2;
	node *l=build(a,s,m);
	node *r=build(a,m+1,e);
	node *tmp= new node ();
	tmp->data = 1;
	if ( l )
		tmp->data *= l->data;
	if ( r )
		tmp->data *= r->data;
	tmp->left=l;
	tmp->right=r;
	return tmp;
}

int query ( node *root, int s , int e, int l, int r )
{	if ( s > e )
		return 0;
	if ( s > r || e < l )
		return 1;
	if ( s == l && e == r )
		return root->data;
	if ( s >= l && e <= r )
		return root->data;
	int m=(s+e)/2;
	int lp=query(root->left,s,m,l,r);
	int rp=query(root->right,m+1,e,l,r);
	return lp*rp;
}
