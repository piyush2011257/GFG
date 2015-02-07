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

void func ( node *root, stack <node *>s1, stack <node*> s2 );

int main()
{	node *root=NULL;
	int d;
	while ( scanf("%d",&d) != EOF )
		insert(&root,d);
	pre_trav(root);
	printf("\n");
	stack <struct node*> s1;
	stack <struct node*>s2;
	func(root,s1,s2);
	return 0;
}

void func ( node *root, stack <node *>s1, stack <node*> s2 )
{	int ctr=-1;
	s2.push(root);
	while( s1.empty() ==0 || s2.empty() == 0 )
	{	if ( ctr == -1 )
		{	while ( s1.empty() == 0 )
			{	node *tmp=s1.top();
				s1.pop();
				printf("%d ", tmp->data);
                                if ( tmp->right != NULL )
					s2.push(tmp->right);
                                if ( tmp->left != NULL )
					s2.push(tmp->left);
			}
		}
		else
                {       while ( s2.empty() == 0 )
                        {       node *tmp=s2.top();
                                s2.pop();
				printf("%d ", tmp->data);
                                if ( tmp->left != NULL )
					s1.push(tmp->left);
                                if ( tmp->right != NULL )
					s1.push(tmp->right);
                        }
		}
		ctr=ctr*(-1);
	}
}
