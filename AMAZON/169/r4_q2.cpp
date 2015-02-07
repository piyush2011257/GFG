/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-169-sde-2/
 Given inorder and postorder traversal of a tree give the preorder traversal without creating the tree.
*/

#include<cstdio>
#include<iostream>

using namespace std;

struct node
{	char data;
	node *left, *right;
	node( char c='\0', node *l=NULL, node *r=NULL )
	{	left=l;
		right=r;
		data=c;
	}
};

const int len=7;

void in_trav ( node *root );
void post_trav ( node *root );
node * func ( char *in, char *out, int &out_pos, int s, int e );

int main()
{	char in[len+1]="dbeafcg";
	char post[len+1]="debfgca";
	int pos_in=0;
	int pos_out=len-1;
	node *root=func(in, post, pos_out, 0, len-1 );
	in_trav(root);
	cout<<endl;
	post_trav(root);
	cout<<endl;
	return 0;
}

void in_trav ( node *root )
{	if ( root != NULL )
	{	in_trav(root->left);
		cout<<root->data<<" ";
		in_trav(root->right);
	}
}

void post_trav( node *root )
{	if ( root != NULL )
	{	post_trav(root->left);
		post_trav(root->right);
		cout<<root->data<<" ";
	}
}
	
node * func ( char *in, char *out, int &out_pos, int s, int e )
{	if ( s > e )
		return NULL;
	if ( s == e )
	{	node *tmp=new node(in[s]);
		out_pos--;
		return tmp;
	}
	int i;
	for ( i=s; i<=e; i++ )
		if ( in[i] == out[out_pos] )
			break;
	node *tmp= new node(out[out_pos]);
	out_pos--;
        tmp->right=func ( in, out, out_pos, i+1,e);
	tmp->left=func ( in, out, out_pos, s,i-1);
	return tmp;
}
