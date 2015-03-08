/*
www.geeksforgeeks.org/amazon-interview-experience-set-177-first-round-pool-campus/
Simple and same Vertical traversal of a BST
*/

#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
using namespace std;

struct node
{       node *left, *right;
        int data;
        node( int v)
        {       left=right=NULL;
                data=v;
        }
};

void func ( node *root, map<int, vector<int> >&m, int ele );

int main()
{       node *root=NULL;
        root=new node(5);
        root->left=new node(4);
        root->right=new node(5);
        root->left->left=new node(13);
        root->left->right=new node(2);
        root->left->left->left=new node(4);
        root->right->right=new node(3);
        root->right->left=new node(12);
        root->right->right->right=new node(11);
	map<int,vector<int> > m;
	func(root,m,0);
	for ( map<int, vector<int> >::iterator iter=m.begin(); iter != m.end(); iter++ )
	{	cout<<iter->first<<"-> ";
		for ( int i=0; i<iter->second.size(); i++)
			cout<<iter->second[i]<<" ";
		cout<<endl;
	}
	return 0;
}

void func ( node *root, map<int,vector<int> > &m, int ele )
{	if ( root == NULL )
		return;
	m[ele].push_back(root->data);
	func(root->left, m, ele-1);
	func(root->right, m, ele+1);
}
