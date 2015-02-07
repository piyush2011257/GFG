#include<cstdio>
#include<queue>
#include<iostream>
#include<cstring>
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

void left_view ( node *root, int n );

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
	left_view(root,15);
	cout<<endl;
	return 0;
}

void left_view ( node *root, int n )
{	queue<node *> q;
	q.push(NULL);
	q.push(root);
	bool ctr=0;
	int ct;
	while ( q.empty() == 0 )
	{	node *t=q.front();
		q.pop();
		/*
		cout<<t<<" ";
		if ( t!= NULL )
			cout<<t->data;
		cout<<" "<<q.empty()<<endl;
		*/
		//cin>>ct;
		if ( t == NULL )
		{	if ( q.empty() == 0 )
			{	ctr=1;
				q.push(NULL);		// avoid infdinite loop
			}
			continue;
		}
		else
		{	if ( ctr == 1 )
			{	cout<<t->data<<" ";
				ctr=0;
			}
			if ( t->left != NULL )
				q.push(t->left);
			if ( t->right != NULL )
				q.push(t->right);
		}
	}
}
