#include<cstdio>
using namespace std;

struct node
{	node *left, *right;
	int data;
	node()
	{	left=right=NULL;
	}
};

node * func ( int *a, int s, int e )
{	if ( s > e )
		return NULL;
	if ( s ==  e )
	{	node *tmp= new node();
		tmp->data= a[s];
		return tmp;
	}
	int mid=(s+e)/2;
	printf("%d %d %d\n", s, e, mid);
	node *tmp= new node();
	tmp->data=a[mid];
	tmp->left=func(a,s,mid-1);
	tmp->right=func(a,mid+1,e);
	return tmp;
}

void in_trav(node *root)
{	if ( root == NULL )
		return;
	in_trav(root->left);
	printf("%d ",root->data);
	in_trav(root->right);
}

void pre_trav(node *root)
{	if ( root == NULL )
		return;
	printf("%d ",root->data);
	pre_trav(root->left);
	pre_trav(root->right);
}

int main()
{	int n, a[100];
	scanf("%d",&n);
	for ( int i=0; i<n; i++)
		scanf("%d",&a[i]);
	node *root= func(a, 0, n-1);
	in_trav(root);
	printf("\n");
	pre_trav(root);
	return 0;
}
