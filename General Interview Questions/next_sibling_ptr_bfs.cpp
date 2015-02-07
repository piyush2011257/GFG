/*
Pre-order traversal iterative
*/

#include<cstdio>
#include<stack>
#include<queue>
using namespace std;

struct node
{	int data;
	node *left, *right, *sibling;
	node()
	{	left=NULL, right=NULL, sibling=NULL;
		data=-1;
	}
	node (int d )
	{	left=NULL, right=NULL, sibling=NULL;
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

void pre_trav ( node *root )
{       if ( root == NULL )
                return;
        printf("%d ", root->data);
	pre_trav(root->left);
        pre_trav(root->right);
}

void func ( node *root );

void pre_trav_level ( node *root )
{       if ( root == NULL )
                return;
        printf("%d-> ", root->data);
	if ( root->sibling != NULL )
	        printf("%d ", root->sibling->data);
	printf("\n");
	pre_trav_level(root->left);
        pre_trav_level(root->right);
}

int main()
{	node *root=NULL;
	int d;
	while ( scanf("%d",&d) != EOF )
		insert(&root,d);
	pre_trav(root);
	printf("\n");
	func(root);
	pre_trav_level(root);
	printf("\n");
	return 0;
}

void func ( node *root )
{	queue <struct node *> q;
	node *prev=NULL;
	q.push(NULL);
	q.push(root);
	printf("front: %p\n", q.front());
	while (q.empty() == 0 )
	{	node *tmp=q.front();
		if ( tmp != NULL )
			printf("tmp-> %d\n", tmp->data);
		q.pop();
		if ( prev != NULL )
			printf("prev: %p\n", prev);
		if ( q.empty() == 0 )
			printf("front: %p\n", q.front());
		if ( tmp == NULL )			// Special case when only one node !!
		{	if ( q.empty() == 0 )
			{	q.push(NULL);
				prev=NULL;
			}
		}
		else
		{	if ( prev != NULL )
				prev->sibling=tmp;
			prev=tmp;
			if ( tmp->left != NULL )
				q.push(tmp->left);
			if ( tmp->right != NULL )
				q.push(tmp->right);
		}
	}
}
