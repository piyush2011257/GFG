/*
Tree to double linked list
*/

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

void zig_zag ( node *root );

int main()
{	node *root=NULL;
	//int d;
	//while ( scanf("%d",&d) != EOF )
	//	insert(&root,d);
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
	zig_zag(root);
	return 0;
}

void zig_zag ( node *root )
{	stack <node *> s1;
	stack <node *> s2;
	s1.push(root);
	while ( s1.empty() == 0 || s2.empty() == 0 )
	{	if ( s1.empty() == 0 )
		{	while ( s1.empty() == 0 )
			{	node *t=s1.top();
				cout<<t->data<<" ";
				s1.pop();
				if ( t->right != NULL )
					s2.push(t->right);
				if ( t->left != NULL )
					s2.push(t->left);
			}
		}
		else if ( s2.empty() == 0 )
                {       while ( s2.empty() == 0 )
                        {       node *t=s2.top();
                                cout<<t->data<<" ";
				s2.pop();
                                if ( t->left != NULL )
                                        s1.push(t->left);
                                if ( t->right != NULL )
                                        s1.push(t->right);
                        }
                }
	}
	cout<<endl;
}
				
