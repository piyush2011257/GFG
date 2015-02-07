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

void post_trav ( node *root )
{       if ( root == NULL )
                return;
        post_trav(root->left);
        post_trav(root->right);
	printf("%d ", root->data);
}

void post_trav_iter ( node *root );

int main()
{	node *root=NULL;
	int d;
	while ( scanf("%d",&d) != EOF )
		insert(&root,d);
	post_trav(root);
	printf("\n");
	post_trav_iter(root);
	return 0;
}

void post_trav_iter ( node *root )
{	if ( root == NULL )
		return;
	stack <struct node *> s;
	s.push(root);
	node *tmp=root->left;
	do
	{	while ( tmp != NULL )
		{	s.push(tmp);
			tmp=tmp->left;
		}
		if ( s.empty() == 0 )
		{	tmp=s.top();
			if ( tmp->right == NULL )
			{	printf("%d ", tmp->data);
				s.pop();
				if ( s.empty() == 1 )
					return;
				node *p=s.top();
				while ( s.empty() == 0 && p->right == tmp )
				{	printf("%d ", p->data);
					tmp=p;
					s.pop();
					if ( s.empty() == 0 )
						p=s.top();
					else
						p=NULL;
				}
				if ( p != NULL && p->right != tmp )
					tmp=p->right;
			}
			else
				tmp=tmp->right;
		}
	} while (s.empty() == 0);			// tmp != NULL corner case.
}

/* Corner case- right skewed tree
		left skewed tree
		one node tree
		empty tree
*/
