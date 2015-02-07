/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-160-sde-2/
Construct Full Binary Tree from given preorder and postorder traversals

Logic similar to-
http://www.geeksforgeeks.org/full-and-complete-binary-tree-from-given-preorder-and-postorder-traversals/

It is not possible to construct a general Binary Tree from preorder and postorder traversals 

Let us consider the two given arrays as pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7} and post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
In pre[], the leftmost element is root of tree. Since the tree is full and array size is more than 1. The value next to 1 in pre[], must be left child of root. So we know 1 is root and 2 is left child. How to find the all nodes in left subtree? We know 2 is root of all nodes in left subtree. All nodes before 2 in post[] must be in left subtree. Now we know 1 is root, elements {8, 9, 4, 5, 2} are in left subtree, and the elements {6, 7, 3} are in right subtree.

                  1
                /   \
               /      \
     {8, 9, 4, 5, 2}     {6, 7, 3}

We recursively follow the above approach and get the following tree.

          1
        /   \
      2       3
    /  \     /  \
   4    5   6    7
  / \
 8   9 

The below code works for any kind of tree NOT just complete / full / balanced tree.
It will generate a tree whose pre / post order traversal matched the input
*/

#include<cstdio>
#include<cstdlib>
using namespace std;

struct node
{       char data;
        node *left, *right;
        node(char c=0, node *l=NULL, node *r=NULL)
        {       data=c;
                left=l;
                right=r;
        }
};

void pre_trav ( node *root );
void post_trav ( node *root );
node * func ( char *pre, char *post, int *start, int *end, int *pre_pos );
int find_pos( char *post, char ele, int s, int e );

int main()
{	// Remember input tree is complete binary tree
	char pre[]="ABCFGDE";
	char post[]="FGCBEDA";
	int len=7;
	int start=0, end=len-1, pre_pos=0;
	node *root=func(pre,post,&start,&end,&pre_pos);
	pre_trav(root);
	printf("\n");
	post_trav(root);
	printf("\n");
	return 0;
}
void pre_trav ( node *root )
{	if ( root == NULL )
		return;
	printf("%c ", root->data);
	pre_trav(root->left);
	pre_trav(root->right);
}

void post_trav ( node *root )
{       if ( root == NULL )
                return;
        post_trav(root->left);
        post_trav(root->right);
        printf("%c ", root->data);
}

node * func ( char *pre, char *post, int *start, int *end, int *pre_pos )
{	//printf("%d %d %d\n", *pre_pos, *start,*end);
	if ( *start > *end )
		return NULL;
	node *tmp= new node(pre[*pre_pos]);
	int idx=find_pos(post,pre[*pre_pos],*start, *end);
	(*pre_pos)++;
	int start1=*start;				// Tricky and logic
	int end1=idx-1;
	node *l= func(pre,post,&start1,&end1,pre_pos);
	tmp->left=l;
	node *r= func(pre,post,&start1,&end1,pre_pos);
	tmp->right=r;
	*start=idx+1;					// Tricky and logic
	//printf("return %d\n", *pre_pos);
	return tmp;
}
	
int find_pos( char *post, char ele, int s, int e )
{	for ( int i=s; i<=e; i++ )
		if ( post[i] == ele )
			return i;
	printf("character not found\n");
	printf("%c %d %d\n",ele,s,e);
	exit(0);
}
