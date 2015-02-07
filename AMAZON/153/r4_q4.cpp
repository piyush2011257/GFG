/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-153-sde1/
Q4. Write program to find max size BST from given binary tree. Algorithm and full working code was required for all the problems. Discussed space and time complexity of every problem.

http://www.geeksforgeeks.org/find-the-largest-subtree-in-a-tree-that-is-also-a-bst/
Find the largest BST subtree in a given Binary Tree
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

int func ( node * root, int *min, int *max, int *size );

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

int main()
{	node *root1=NULL;
	int d;
	//while ( scanf("%d",&d) != EOF )
	//	insert(&root1,d);
	struct node *root = new node(50);
	root->left        = new node(10);
	root->right       = new node(60);
	root->left->left  = new node(5);
	root->left->right = new node(20);
	root->right->left  = new node(55);
	root->right->left->left  = new node(45);
	root->right->right = new node(70);
	root->right->right->left = new node(65);
	root->right->right->right = new node(80);
	root1=root;
	in_trav(root1);
	pre_trav(root1);
	int max_size=0;
	int min,max;
	func(root1, &min, &max, &max_size);
	printf("%d\n", max_size);
	return 0;
}

int func ( node * root, int *min, int *max, int *size )
{	int l,r,d;
	d=root->data;
	if ( root->left == NULL && root->right==NULL )
	{	if ( 1 > *size )
			*size=1;
		*min=*max=d;
		return 1;
	}
	if ( root->left != NULL && root->right != NULL )
	{	int ls = func(root->left,min,max,size);
		int lmin=*min;
		int lmax=*max;
		int rs = func(root->right,min,max,size);
		int rmin=*min;
		int rmax=*max;
		*min=lmin;
		*max=rmax;
		if ( ls == -1 || rs == -1 )
			return -1;
		if ( lmax < d && d <= rmin )
		{	if ( ls + rs + 1 > *size )
				*size=ls+rs+1;
			return ls+rs+1;
		}
		else
			return -1;
		
	}
	if ( root->left == NULL )
        {    	int rs = func(root->right,min,max,size);
                int rmin=*min;
                int rmax=*max;
                *min=d;
                *max=rmax;
                if ( rs == -1 )
                        return -1;
                if ( d <= rmin )
                {       if (  rs + 1 > *size )
                                *size=rs+1;
                        return rs+1;
                }
                else
                        return -1;
	}
        if ( root->right == NULL )
        {       int ls = func(root->left,min,max,size);
                int lmin=*min;
                int lmax=*max;
                *min=lmin;
                *max=d;
                if ( ls == -1 )
                        return -1;
                if ( d > lmax )
                {       if (  ls + 1 > *size )
                                *size=ls+1;
                        return ls+1;
                }
                else
                        return -1;
        }
}
