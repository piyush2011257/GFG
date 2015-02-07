/*
Level order traversal of tree
*/

#include<cstdio>
#include<queue>
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

void level_order ( node *root );

int main()
{	node *root=NULL;
	int d;
	while ( scanf("%d",&d) != EOF )
		insert(&root,d);
	in_trav(root);
	printf("\n");
	level_order ( root );
	return 0;
}

void level_order ( node *root )
{	queue<node *> q;
	q.push(root);
	while ( q.empty() == 0 )
	{	node *t=q.front();
		q.pop();
		printf("%d ", t->data);
		if ( t->left )
			q.push(t->left);
		if (t->right)
			q.push(t->right);
	}
	printf("\n");
}
