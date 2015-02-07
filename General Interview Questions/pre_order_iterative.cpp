/*
Pre-order traversal iterative
*/

#include<cstdio>
#include<stack>
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

void pre_trav ( node *root )
{       if ( root == NULL )
                return;
        printf("%d ", root->data);
	pre_trav(root->left);
        pre_trav(root->right);
}

void pre_trav_iter ( node *root );

int main()
{	node *root=NULL;
	int d;
	while ( scanf("%d",&d) != EOF )
		insert(&root,d);
	pre_trav(root);
	printf("\n");
	pre_trav_iter(root);
	return 0;
}

void pre_trav_iter ( node *root )
{	if ( root == NULL )
		return;
	stack <struct node *> s;
	s.push(root);
	printf("%d ", root->data);
	node *tmp=root->left;
	do
	{	while ( tmp != NULL )
		{	printf("%d ", tmp->data);
			s.push(tmp);
			tmp=tmp->left;
		}
		while ( s.empty() == 0 && tmp == NULL )
		{	tmp=s.top();
			s.pop();
			tmp=tmp->right;
		}
	} while (s.empty() == 0 || tmp != NULL );			// tmp != NULL corner case.
}

/* Corner case- right skewed tree
		left skewed tree
		one node tree
		empty tree
*/
