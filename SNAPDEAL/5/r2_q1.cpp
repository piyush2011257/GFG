#include<cstdio>
#include<stack>
#include<iostream>
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

int diameter ( node *root, int *max_diam );

int main()
{	node *root=NULL;
	root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	root->left->right=new node(5);
	root->right->left= new node(6);
	root->right->right=new node(7);
	root->left->left->left=new node(8);
	root->left->left->right=new node(9);
	root->left->right->left=new node(10);
	root->left->right->right=new node(11);
	root->right->left->left= new node(12);
	root->right->left->right=new node(13);
	root->right->right->left=new node(14);
	root->right->right->right= new node(15);
	int max_diameter=0;
	diameter(root,&max_diameter);
	cout<<max_diameter<<endl;
	return 0;
}

int diameter ( node *root, int *max_diam )
{	if (root == NULL )
		return 0;
	int l=diameter(root->left,max_diam);
	int r=diameter(root->right,max_diam);
	if ( l + r  > *max_diam )
		*max_diam=l+r;
	return l >= r ? l+1 : r+1;
}
