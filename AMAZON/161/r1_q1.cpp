/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-161-off-campus-sde-1-banglore/

http://www.geeksforgeeks.org/connect-leaves-doubly-linked-list/
Given a Binary Tree, extract all leaves of it in a Doubly Linked List (DLL). Note that the DLL need to be created in-place. Assume that the node structure of DLL and Binary Tree is same, only the meaning of left and right pointers are different. In DLL, left means previous pointer and right means next pointer.
a
Let the following be input binary tree
        1
     /     \
    2       3
   / \       \
  4   5       6
 / \         / \
7   8       9   10


Output:
Doubly Linked List
7<->8<->5<->9<->10

Modified Tree:
        1
     /     \
    2       3
   /         \
  4           6

*/

#include<cstdio>
using namespace std;

struct node
{	int data;
	node *left, *right;
	node(int d=-1, node *l=NULL, node *r=NULL )
	{	left=l;
		right=r;
		data=d;
	}
};

struct list
{	int data;
	list *next;
	list ( int d=-1, list *n=NULL )
	{	data=d;
		next=n;
	}
};

void in_trav(struct node *root)
{	if (root != NULL)
	{	in_trav(root->left);
        	printf("%d ",root->data);
        	in_trav(root->right);
  	}
}

void print_list ( list *root )
{	while ( root != NULL )
	{	printf("%d ", root->data);
		root=root->next;
	}
	printf("\n");
}

bool func ( node *root , list **head, list **tail );

int main()
{	struct node *root = new node(1);	
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->right = new node(6);
	root->left->left->left = new node(7);
	root->left->left->right = new node(8);
	root->right->right->left = new node(9);	
	root->right->right->right = new node(10);
	in_trav(root);
	printf("\n");
	list *head=NULL, *tail=NULL;
	func(root,&head,&tail);
	in_trav(root);
	printf("\n");
	print_list(head);
	return 0;
}

bool func ( node *root , list **head, list **tail )
{	if ( root == NULL )
		return 0;
	if ( root->left==NULL && root->right == NULL )
	{	if (*head == NULL )
		{	*head= new list(root->data);
			*tail=*head;
		}
		else
		{	(*tail)->next= new list(root->data);
			*tail=(*tail)->next;
		}
		return 1;
	}
	bool l = func(root->left,head,tail);
	bool r= func ( root->right, head,tail);
	if ( l == 1 )
		root->left=NULL;
	if ( r == 1 )
		root->right=NULL;
	return 0;
}
