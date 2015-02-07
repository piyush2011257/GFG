/*
Pre-order traversal iterative
O(n) solution
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

int lt[100], rt[100], par[100], max_depth1=-1, max_depth2=-1;
void post_order ( node *root, node *parent, int *left, int *right );
void pre_order ( node *root, node *parent );

int main()
{	node *root=NULL;
	int d;
	while ( scanf("%d",&d) != EOF )
		insert(&root,d);
	int left=0, right=0;
	par[root->data]=root->data;
	post_order(root,NULL,&left,&right);
	for ( int i=1; i<=15; i++ )
		printf("%d %d %d %d\n", i, lt[i], rt[i], par[i]);
        pre_order(root,NULL);
	printf("max_depth1: %d\n", max_depth1);
        printf("max_depth2: %d\n", max_depth2);	
	return 0;
}

void post_order ( node *root, node *parent, int *left, int *right )
/* max_depth1 for V shaped bents
	10
      5	    6
This type of bents
*/
{	if ( root == NULL )
	{	*left=*right=-1;
		return;
	}
	if ( parent != NULL )
		printf("parent: %d %d\n", parent->data, root->data );
	
        if ( parent != NULL )
        {       if ( parent->left == root )
                {       if ( root->left != NULL )
                                par[root->left->data]=par[root->data];
                        if ( root->right != NULL )
                                par[root->right->data]=root->data;
                }
                else
                {      if ( root->left != NULL )
                                par[root->left->data]=root->data;
                       if ( root->right != NULL )
                                par[root->right->data]=par[root->data];
                }
        }
        else
        {       if ( root->left != NULL )
                        par[root->left->data]=root->data;
                if ( root->right != NULL )
                        par[root->right->data]=root->data;
        }
	post_order(root->left,root,left,right);
	int l1=*left;
	int r1=*right;
        post_order(root->right,root,left,right);
        int l2=*left;
        int r2=*right;
	*left=l1+1;
	*right=r2+1;
	lt[root->data]=*left;
	rt[root->data]=*right;
	if ( (*left) + (*right)  > max_depth1 )
		max_depth1= (*left)+(*right);
}

void pre_order ( node *root, node *parent )
{	if ( root == NULL )
		return;
	if ( parent != NULL )	
	{	int upper_diam, low_diam;
		if ( parent->left == root )
		{	upper_diam= lt[par[root->data]]-lt[root->data];
			low_diam= rt[root->data];
		}
		else
		{	upper_diam= rt[par[root->data]]-rt[root->data];
                        low_diam= lt[root->data];
		}
		if ( upper_diam + low_diam > max_depth2 )
			max_depth2 = upper_diam + low_diam;
	
	}
	pre_order(root->left, root);
	pre_order(root->right, root);
}

/*
Solution developed keeping graph in mind for trees and input type constraint!!
9 4 10
1 8 13
2 6 12 14
3 5 7 11 15
parent: 9 4
parent: 4 1
parent: 1 2
parent: 2 3
parent: 4 8
parent: 8 6
parent: 6 5
parent: 6 7
parent: 9 10
parent: 10 13
parent: 13 12
parent: 12 11
parent: 13 14
parent: 14 15
1 0 2 9
2 0 1 1
3 0 0 1
4 1 1 9
5 0 0 8
6 1 1 8
7 0 0 6
8 2 0 4
9 2 4 9
10 0 3 9
11 0 0 13
12 1 0 13
13 2 2 9
14 0 1 9
15 0 0 9
max_depth1: 6

8 9
7
5
6
1
2
3
4
parent: 8 7
parent: 7 5
parent: 5 1
parent: 1 2
parent: 2 3
parent: 3 4
parent: 5 6
parent: 8 9
1 0 3 8
2 0 2 1
3 0 1 1
4 0 0 1
5 1 1 8
6 0 0 5
7 2 0 8
8 3 1 8
9 0 0 8
max_depth1: 4
max_depth2: 6

5
4
2
1
3
6
8
7
9
parent: 5 4
parent: 4 2
parent: 2 1
parent: 2 3
parent: 5 6
parent: 6 8
parent: 8 7
parent: 8 9
1 0 0 5
2 1 1 5
3 0 0 2
4 2 0 5
5 3 3 5
6 0 2 5
7 0 0 8
8 1 1 5
9 0 0 5
max_depth1: 6
max_depth2: 3
*/
	

