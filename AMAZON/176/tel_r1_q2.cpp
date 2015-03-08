/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-176-sde-1/
You are given a Binary Search Tree. Write an algorithm to print the Path Array of a given key.
PATH ARRAY:
a) If the given key is not present in the tree than the Path Array is equal to “-1”
b) If the given key is present in the BST, path array tells you the path (in terms of left & right direction) that you take from root to reach the given key. If you go towards right add “0” to the path array and if you go towards left add “1” to Path Array.
*/

#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

struct node
{       node *left, *right;
        int data;
        node( int v)
        {       left=right=NULL;
                data=v;
        }
};

void func ( node *root, string str, int ele );

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
	string str;
	func(root,str,4);
	return 0;
}

void func ( node *root, string str, int ele )
{	if ( root == NULL )
		return;
	if ( root->data == ele )
		cout<<str<<endl;
	func(root->left, str+'1', ele);
	func(root->right, str+'0', ele);
}
