/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-155-campus/
You are given a binary tree. Print the vertical order traversal starting from the root element.

http://www.geeksforgeeks.org/print-binary-tree-vertical-order-set-2/
*/
#include<map>
#include<cstdio>
#include<vector>
using namespace std;

struct node
{	int data;
	node *left, *right;
	node( int d, node *l=NULL, node *r=NULL )
	{	left=l;
		right=r;
		data=d;
	}
};

void vertical_trav(node *root );
void in_trav ( node *root, map<int, vector<node *> > &m, int pos );

int main()
{	node *root= new node(1);
	root->right=new node(3);
	root->left=new node(2);
	root->right->right=new node(7);
	root->right->left= new node(6);
	root->left->left= new node(4);
	root->left->right= new node(5);
	root->right->left->right= new node(8);
	root->right->right->right=new node(9);
	vertical_trav(root);
	return 0;
}


void vertical_trav(node *root )
{	map<int, vector<node *> > m;
	in_trav(root,m,0);
	//printf("%d\n", m.size());
	for ( map < int, vector<node *> >::iterator iter=m.begin(); iter != m.end(); iter++ )
	// in sorted ordering itself
	{	printf("%d -> ", iter->first);
		for ( vector<node *>::iterator iter_2=(iter->second).begin(); iter_2 != (iter->second).end(); iter_2++ )
			printf("%d ", (*iter_2)->data );
		printf("\n");
	}

}

void in_trav ( node *root, map<int, vector<node *> > &m, int pos )
{	if ( root== NULL )
		return;
	m[pos].push_back(root);
	in_trav(root->left,m,pos-1);
	in_trav(root->right,m,pos+1);
}
