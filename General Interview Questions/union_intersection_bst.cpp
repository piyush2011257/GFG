/*
Union-Intersection of two trees
*/

#include<cstdio>
#include<stack>
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

void insert ( node **root, int d )
{	if ( *root == NULL )
	{	*root=new node();
		(*root)->data=d;
		return;
	}
	node *p, *q;
	p=NULL;
	q=*root;
	while ( q != NULL )
	{	if ( d < q->data )
		{	p=q;
			q=q->left;
		}
		else
		{	p=q;
			q=q->right;
		}
	}
	node *t=new node();
	t->data=d;
	if ( d < p->data )
		p->left=t;
	else
		p->right=t;
}

void in_trav ( node *root )
{	if ( root == NULL )
		return;
	in_trav(root->left);
	printf("%d ", root->data);
	in_trav(root->right);
}

void pre_trav ( node *root )
{       if ( root == NULL )
                return;
        printf("%d ", root->data);
	pre_trav(root->left);
        pre_trav(root->right);
}

void union_intersect ( node *root1, node *root2 );

int main()
{	node *root1=NULL, *root2=NULL;
	int d;
	while ( scanf("%d",&d) != EOF )
		insert(&root1,d);
	in_trav(root1);
	printf("\n");
        while ( scanf("%d",&d) != EOF )
                insert(&root2,d);
        in_trav(root2);
        printf("\n");
	union_intersect(root1,root2);
	return 0;
}

void union_intersect ( node *root1, node *root2 )
{	stack <node *> s1;
	stack <node *> s2;
	node *t1=root1, *t2=root2;
	stack <node *> un;
	stack <node *> in;
	while ( t1 != NULL )
        {       s1.push(t1);
        	t1=t1->left;
        }
        while (t2 != NULL )
        {       s2.push(t2);
        	t2=t2->left;
	}          
	printf("size- %d %d\n",s1.size(), s2.size());
	while (  s1.empty() == 0 && s2.empty() == 0) 
	{	if ( s1.empty() == 0 && s2.empty() == 0 )
		{	t1=s1.top();
			t2=s2.top();
			printf("%d %p %p\n", t1->data, t1->left,t1->right);
			printf("%d %p %p\n", t2->data, t2->left,t2->right);
			if ( t1->data  == t2->data )
			{	in.push(t1);
				un.push(t1);
				t1=t1->right;
				t2=t2->right;
				s1.pop();
				s2.pop();
				while ( t1 != NULL )
		                {       s1.push(t1);
        		                t1=t1->left;
                		}
				while (t2 != NULL )
		                {       s2.push(t2);
        		                t2=t2->left;
                		}
			}
			else if ( t1->data < t2->data )
			{	s1.pop();
				un.push(t1);
				t1=t1->right;
				while ( t1 != NULL )
		                {       s1.push(t1);
        		                t1=t1->left;
                		}
                	}
			else
			{       s2.pop();
                                un.push(t2);
                                t2=t2->right;
				while (t2 != NULL )
		                {       s2.push(t2);
        		                t2=t2->left;
                		}
			}
		}
		printf("size- %d %d\n",s1.size(), s2.size());
	}
	printf("yo\n");
	while ( s1.empty() == 0 )
	{	t1=s1.top();
		un.push(t1);
		s1.pop();
		t1=t1->right;
		while ( t1 != NULL )
		{	s1.push(t1);
			t1=t1->left;
		}
	}
	while ( s2.empty() == 0 )
	{	t2=s2.top();
		un.push(t2);
		printf("%d %d %p\n",s2.size(), t2->data, t2->right);
		s2.pop();
		t2=t2->right;
		while ( t2 != NULL )
		{	s2.push(t2);
			t2=t2->left;
		}
	}
	printf("intersection\n");
	while ( in.empty() == 0 )
	{	printf("%d ", (in.top())->data);
		in.pop();
        }
	printf("\nunion\n");
        while ( un.empty() == 0 )
        {       printf("%d ", (un.top())->data);
                un.pop();
        }
	printf("\n");
}
