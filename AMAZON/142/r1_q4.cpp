/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-142-campus-sde-1/
Given a node in a binary tree, find all the nodes which are at distance K from it. Root node is also given.
*/

#include<cstdio>
using namespace std;

struct node
{	node *left, *right;
	int data;
	node()
	{	left=right=NULL;
		data=-1;
	}
        node( int d )
        {       left=right=NULL;
                data=d;
        }

};

bool dfs ( node *root, int ele, int &k, int &count );
int count_ele ( node *root, int depth );

int main()
{	node *root=new node(20);
	root->left = new node(8);
	root->right = new node(22);
	root->left->left = new node(4);
	root->left->right = new node(12);
	root->left->right->left = new node(10);
	root->left->right->right = new node(14);
	root->left->left->right= new node(15);
	root->left->left->left= new node(6);
	root->left->left->left->right= new node(10);
	root->left->left->left->left= new node(8);
	root->left->left->left->left->left= new node(4);
	root->left->left->left->left->right= new node(8);
	root->left->left->left->right->left= new node(40);
	root->left->left->left->right->right= new node(80);

	
	int k, ele, count=0;
	scanf("%d %d",&k,&ele);
	dfs(root,ele,k,count);
	printf("%d\n", count);
	return 0;
}

bool dfs ( node *root, int ele, int &k, int &count )
{	if ( root == NULL )
		return 0;
	if ( root->data == ele )
	{	count += count_ele ( root->left, k-1);
		count += count_ele ( root->right,k-1);
		//printf("ele found!! %d %d\n", count,k);
		k--;
		return 1;
	}
	bool l=0, r=0;
	l=dfs(root->left, ele, k, count);
	if ( l == 1 )
	{	if ( k == 0 )
		{       printf("%d\n", root->data);
                        count++;                        // if this node is at k distance itself!!
                }
		count += count_ele ( root->right,k-1);
		k--;
		return 1;
	}
	r=dfs(root->right, ele, k, count);
	if ( r == 1 )
	{	if ( k == 0 )
                {       printf("%d\n", root->data);
                        count++;                        // if this node is at k distance itself!!
                }
                count += count_ele ( root->left,k-1);
		k--;
		return 1;
	}
	return 0;
}

int count_ele ( node *root, int depth )
{	if ( root== NULL )
		return 0;
	if ( depth == 0 )
	{	printf("%d\n", root->data);
		return 1;
	}
	int l=count_ele(root->left,depth-1);
	int r=count_ele(root->right,depth-1);
	return l+r;
}

/*
At first look the time complexity looks more than O(n), but if we take a closer look, we can observe that no node is traversed more than twice. Therefore the time complexity is O(n).
*/
