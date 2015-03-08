/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-175-sde/
Given a tree, implement a function which replaces a node’s value with the sum of all its childrens’ value, considering only those children whose value is less than than the main node’s value.
Eg: input = 60->50->80->40 , output = 90->40->40->0

O(n^2)
*/
#include<cstdio>
#include<iostream>

using namespace std;

struct node
{	node *left, *right;
	int data;
	node( int v)
	{	left=right=NULL;
		data=v;
	}
};

void in_trav( node *root );
int post_trav ( node *root, int ele );
void func ( node *root );

int main()
{	node *root=NULL;
	root=new node(5);
	root->left=new node(4);
	root->right=new node(5);
	root->left->left=new node(13);
	root->left->right=new node(2);
	root->left->left->left=new node(4);
	root->right->right=new node(3);
	root->right->left=new node(12);
	root->right->right->right=new node(11);
	in_trav(root);
	cout<<endl;
	func(root);
	in_trav(root);
	cout<<endl;
	return 0;
}

void in_trav( node *root )
{	if ( root != NULL )
	{	in_trav(root->left);
		cout<<root->data<<" ";
		in_trav(root->right);
	}
}
	
int post_trav ( node *root, int ele )
{	if ( root == NULL )
		return 0;
	return post_trav(root->left,ele) + post_trav(root->right,ele) + ( ( root->data < ele ) ? root->data : 0 ); 

}

void func ( node *root )
{	if ( root != NULL )
	{	int l=post_trav(root->left,root->data);
		l += post_trav(root->right, root->data);
		root->data=l;
		func(root->left);
		func(root->right);
	}
}
