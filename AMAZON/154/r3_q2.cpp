/*
Level order traversal of tree
*/

#include<cstdio>
using namespace std;

struct node
{	int data;
	node *left, *right;
	node()
	{	left=NULL, right=NULL;
		data=-1;
	}
	node (int d )
	{	left=NULL, right=NULL;
		data=d;
	}
};

void insert ( node **root, int d )
{	if ( *root == NULL )
	{	*root=new node();
		(*root)->data=d;
		return;
	}
	node *p, *q;
	p=NULL;
	q=*root;
	while ( q != NULL )
	{	if ( d < q->data )
		{	p=q;
			q=q->left;
		}
		else
		{	p=q;
			q=q->right;
		}
	}
	node *t=new node();
	t->data=d;
	if ( d < p->data )
		p->left=t;
	else
		p->right=t;
}

void in_trav ( node *root )
{	if ( root == NULL )
		return;
	in_trav(root->left);
	printf("%d ", root->data);
	in_trav(root->right);
}

int dist ( node *root, int c1, int c2, int h );

int main()
{	node *root=NULL;
	int d;
	while ( scanf("%d",&d) != EOF )
		insert(&root,d);
	in_trav(root);
	printf("\n");
	int c1,c2;
	scanf("%d %d",&c1,&c2);
	printf("%d\n", dist(root,c1,c2,0));
	return 0;
}

int dist ( node *root, int c1, int c2, int h )
{	if ( root == NULL )
		return -1;
	int l= dist(root->left,c1,c2,h+1);
        int r= dist(root->right,c1,c2,h+1);
	if ( root->data == c1 || root->data == c2 )
	{	if ( l != -1 || r != -1 )
			return l != -1 ? l-h : r-h;
		else
			return h;
	}
	if ( l != -1 && r != -1 )
		return (l-h)+(r-h);
	else
		return l != -1 ? l : r;
}
