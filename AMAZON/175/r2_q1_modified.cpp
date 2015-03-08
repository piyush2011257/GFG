/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-175-sde/
Given a tree, implement a function which replaces a node’s value with the sum of all its childrens’ value, considering only those children whose value is less than than the main node’s value.
Eg: input = 60->50->80->40 , output = 90->40->40->0

http://www.quora.com/Given-an-unbalanced-rooted-tree-how-would-you-replace-each-nodes-value-with-the-sum-of-all-the-values-in-its-subtree-that-are-smaller-than-the-nodes-value

This solution will still use simple array for finding sum. Replace it with segment tree for optimization to O(logn)
*/

#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

struct node
{	node *left, *right;
	int data;
	node( int v)
	{	left=right=NULL;
		data=v;
	}
};

int *a;

void in_trav ( node *root );
void func ( node *root );
int calc ( int ele );

int main()
{	node *root=NULL;
	int n=9;
	a=new int[9];
	memset(a,0,sizeof(a)*n);
	root=new node(2);
	root->left=new node(4);
	root->right=new node(8);
	root->left->left=new node(3);
	root->left->right=new node(5);
	root->left->left->left=new node(1);
	root->right->right=new node(5);
	root->right->left=new node(6);
	root->right->right->right=new node(2);
	in_trav(root);
	cout<<endl;
	func(root);
	in_trav(root);
	cout<<endl;
	return 0;
}

// under assumption that range is [0,n-1]
void func ( node *root )
{	if ( root == NULL )
		return;
	int old_sum=calc(root->data);
	func(root->left);
	func(root->right);
	a[root->data]+=root->data;
	int new_sum=calc(root->data);
	root->data=new_sum-old_sum;
}

void in_trav ( node *root )
{	if ( root == NULL )
		return;
	in_trav(root->left);
	cout<<root->data<<" ";
	in_trav(root->right);
}

int calc ( int ele )			// this can be optimized using segment tree to O(logN)
{	int sum=0;
	for ( int i=0; i<ele; i++ )
		sum += a[i];
	return sum;
}
