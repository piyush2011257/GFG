/*
intersection / union of 2 sorted linked lists using Merge Sort Algo
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

void merge ( node *root1, node *root2 );

int main()
{	int c;
	node *root1=NULL, *root2=NULL;
	while ( scanf("%d",&c) != EOF )
		push(&root1,c);
	print(root1);	
        while ( scanf("%d",&c) != EOF )
                push(&root2,c);
        print(root2);    
	merge(root1, root2);
	return 0;
}

void merge ( node *root1, node *root2 )
{	node *union_h=NULL, *union_t=NULL, *intersect_h=NULL, *intersect_t=NULL;
	while ( root1 && root2 )
	{	if ( root1->data < root2->data )
		{	if ( union_h == NULL )
			{	union_h=union_t=new node();
				union_h->data=root1->data;
			}
			else
			{	node *tmp= new node();
				tmp->data=root1->data;
				union_t->next=tmp;
				union_t=tmp;
			}
			root1=root1->next;
		}
		else if ( root2->data < root1->data )
                {       if ( union_h == NULL )
                         {       union_h=union_t=new node();
				union_h->data=root2->data;
			}
                        else
                        {       node *tmp= new node();
                                tmp->data=root2->data;
                                union_t->next=tmp;
                                union_t=tmp;
                        }       
                        root2=root2->next;
                }
		else
		{       if ( union_h == NULL )
                        {	union_h=union_t=new node();
				union_h->data=root1->data;
			}
			else
                        {       node *tmp= new node();
				tmp->data=root1->data;
				union_t->next=tmp;
                                union_t=tmp;
                        }
			if ( intersect_h == NULL )
			{	intersect_h=intersect_t=new node();
				intersect_h->data=root1->data;
			}
			else
                        {       node *tmp= new node();
				tmp->data=root1->data;
				intersect_t->next=tmp;
                                intersect_t=tmp;
                        }
                        root2=root2->next;
			root1=root1->next;
                }
	}
	while ( root1 != NULL )
	{	if ( union_h == NULL )
                {       union_h=union_t=new node();
                        union_h->data=root1->data;
                }
                else
                {       node *tmp= new node();
                        tmp->data=root1->data;
                        union_t->next=tmp;
                        union_t=tmp;
                 }
		root1=root1->next;
	}
        while ( root2 != NULL )
        {       if ( union_h == NULL )
                {       union_h=union_t=new node();
                        union_h->data=root2->data;
                }
                else
                {       node *tmp= new node();
                        tmp->data=root2->data;
                        union_t->next=tmp;
                        union_t=tmp;
                 }
                root2=root2->next;

	}
	printf("union: ");
	print(union_h);
	printf("\nintersect: ");
	print(intersect_h);
	printf("\n");
}
