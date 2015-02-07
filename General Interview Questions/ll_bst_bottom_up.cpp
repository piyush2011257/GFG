/*
linked lists
*/

#include<cstdio>
using namespace std;

struct node
{	node *next;
	int data;
	node(int d=-1, node *n=NULL)
	{	data=d;
		next=n;
	}
	
};

struct node_tree
{	node_tree *left, *right;
	int data;
	node_tree()
	{	left=right=NULL;
	}
};

void push(node **h, int d )
{	if ( *h == NULL )
	{	*h= new node(d);
		return;
	}
	node *t=*h;
	while ( t->next != NULL )
		t=t->next;
	node *tmp=new node(d);
	t->next=tmp;
}

void print(node *h)
{	while(h != NULL )
	{	printf("%d -> ", h->data);
		h=h->next;
	}
	printf("\n");
}

int getlength ( node *h)
{	int i=0;
	while ( h!=NULL )
	{	i++;
		h=h->next;
	}
	return i;
}

node_tree * func(node **root, int s, int e );

void in_trav (node_tree *root)
{	if ( root== NULL )
		return;
	in_trav(root->left);
	printf("%d ", root->data);
	in_trav(root->right);
}

int main()
{	int c;
	node *root=NULL;
	while ( scanf("%d",&c) != EOF )
		push(&root,c);
	print(root);	
	int len=getlength(root);
	node_tree *root_t=func(&root,1,len);
	in_trav(root_t);
	return 0;
}

node_tree * func(node **root, int s, int e )
{	if ( s > e )
		return NULL;
	if ( s==e )
	{	node_tree *tmp= new node_tree();
		tmp->data=(*root)->data;
		(*root)=(*root)->next;
		return tmp;
	}
	int m=(s+e)/2;
	node_tree *l= func(root, s, m-1);
	node_tree *tmp= new node_tree();
	tmp->data=(*root)->data;
	(*root)=(*root)->next;
	node_tree *r= func(root, m+1,e);
	tmp->left=l;
	tmp->right=r;
	return tmp;
}
