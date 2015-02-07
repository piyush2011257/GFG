/*
Tree to double linked list
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

void pre_trav ( node *root )
{       if ( root == NULL )
                return;
        printf("%d ", root->data);
	pre_trav(root->left);
        pre_trav(root->right);
}

void print ( node *root )
{	while ( root != NULL )
	{	printf("%d %p %p %p\n", root->data, root->left, root, root->right);
		root=root->right;
	}
	printf("\n");
}

void tree_to_dll ( node *root, node **head, node **tail );

int main()
{	node *root=NULL;
	int d;
	while ( scanf("%d",&d) != EOF )
		insert(&root,d);
	in_trav(root);
	printf("\n");
	node *head=NULL, *tail=NULL;
	tree_to_dll(root,&head,&tail);
	print(head);
	return 0;
}

void tree_to_dll ( node *root, node **head, node **tail )
{	if ( root == NULL )
	{	*head=*tail=NULL;
		return;
	}
	node *ltail,*rtail,*lhead,*rhead;
	ltail=rtail=lhead=rhead=NULL;
	if ( root->left != NULL )
	{	tree_to_dll(root->left,head,tail);
		ltail=*tail;
		lhead=*head;
	}
	if ( root->right != NULL )
        {       tree_to_dll(root->right,head,tail);
                rtail=*tail;
                rhead=*head;
        }
	if ( root->left == NULL )
		*head=root;
	else
	{	*head=lhead;
		ltail->right=root;
		root->left=ltail;
	}
	if ( root->right == NULL )
		*tail=root;
	else
	{	*tail=rtail;
		root->right=rhead;
		rhead->left=root;
	}
}
