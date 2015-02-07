/*
split linked lists in odd and even
*/

#include<cstdio>
using namespace std;

struct node
{	node *next;
	int data;
	node(int d=-1, node *n=NULL)
	{	data=d;
		next=n;
	}
	
};

void push(node **h, int d )
{	if ( *h == NULL )
	{	*h= new node(d);
		return;
	}
	node *t=*h;
	while ( t->next != NULL )
		t=t->next;
	node *tmp=new node(d);
	t->next=tmp;
}

void print(node *h)
{	while(h != NULL )
	{	printf("%d -> ", h->data);
		h=h->next;
	}
	printf("\n");
}

void split(node *root, node **odd, node **even );

int main()
{	int c;
	node *root=NULL;
	while ( scanf("%d",&c) != EOF )
		push(&root,c);
	print(root);
	node *odd=NULL, *even=NULL;
	split(root,&odd,&even);
        print(odd);    
        print(even);    
	return 0;
}

void split(node *root, node **odd, node **even )
{	node *odd_t=NULL, *even_t=NULL;
	while ( root != NULL )
	{	if ( root->data % 2 == 0 )
		{	if ( *even == NULL )
			{	*even=root;
				even_t=root;
			}
			else
			{	even_t->next=root;
				even_t=root;
			}
		}
		else
                {       if ( *odd == NULL )
                        {       *odd=root;
                                odd_t=root;
                        }
                        else
                        {       odd_t->next=root;
				odd_t=root;
			}
		}
		root=root->next;
	}
	// Corner Case
	if ( odd_t != NULL )
		odd_t->next=NULL;
	if ( even_t != NULL )
		even_t->next=NULL;
}
