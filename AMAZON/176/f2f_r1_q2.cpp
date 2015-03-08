/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-176-sde-1/

You are given a binary tree. A light source is placed on the right of the tree. Print the list of all the nodes over which the light is falling directly.
*/

#include<cstdio>
#include<iostream>
#include<map>
using namespace std;

struct node
{	node *left, *right;
	int data;
	node( int v)
	{	left=right=NULL;
		data=v;
	}
};

void pre_trav ( node *root, map<int,bool> &m, int ht );

int main()
{	node *root=NULL;
	root=new node(5);
	root->left=new node(4);
	root->right=new node(5);
	root->left->left=new node(13);
	root->left->right=new node(2);
	root->left->left->left=new node(14);
	root->right->right=new node(3);
	root->right->left=new node(12);
	map<int,bool>m;
	pre_trav(root,m,0);
	return 0;
}

void pre_trav ( node *root, map<int,bool> &m, int ht )
{	if ( root == NULL )
		return;
	if ( m.count(ht) == 0 )
	{	cout<<root->data<<endl;
		m[ht]=1;
	}
	pre_trav(root->right,m,ht+1);
	pre_trav(root->left,m,ht+1);
}

