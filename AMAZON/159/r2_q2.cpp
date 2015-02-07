/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-159-off-campus/
Given a singly linked list of 0s and 1s, sort it keeping the order intact. I gave O(N) time and O(1) space complexity solution.

O(n)
Assume a linked list
Find first occurence of 1 and use quick sort logic
e.g
0a 	0b 	1a 	1b	0c 	1c 	0d 	0e 	0f 	1d
     		 |		|
    		 first1	       first 0 after 1

All elements from root -> first1 all 0s in the order of occurence

now remove first 0 after 1 and put is justg before first occurence of 1

0a      0b      0c	1a      1b     1c      0d      0e      0f      1d
                 	|              		|
                 	first1        	     new first 0
						after 1
repeat same step

0a      0b      0c	0d	0e	0f	1a      1b     1c      1d

*/
#include<cstdio>
#include<cstdlib>
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

void sort ( node **root );

int main()
{	int c;
	node *root=NULL;
	while ( scanf("%d",&c) != EOF )
		push(&root,c);
	print(root);
	sort(&root);
	print(root);
	return 0;
}

void sort ( node **root )
{	node *first_1=*root, *first_0_after_1, *prev=NULL;
	while ( first_1 != NULL && first_1->data == 0 )
	{	prev=first_1;
		first_1=first_1->next;
	}
	if ( first_1 == NULL )
	{	printf("All 0's\n");
		exit(0);
	}
	else
		first_0_after_1=first_1->next;
	if ( first_0_after_1 == NULL )
	{	printf("Already sorted\n");
		exit(0);
	}
	node *p=first_1;
	while ( first_0_after_1 != NULL )
	{	while ( first_0_after_1 != NULL && first_0_after_1->data == 1 )
		{	p=first_0_after_1;
			first_0_after_1=first_0_after_1->next;
		}
		if ( first_0_after_1 != NULL )
		{	if ( prev == NULL)
			{	node *tmp=first_0_after_1->next;
				first_0_after_1->next=first_1;
				*root=first_0_after_1;
				p->next=tmp;
				prev=first_0_after_1;
			}
			else
			{	node *tmp=first_0_after_1->next;
				first_0_after_1->next=first_1;
				prev->next=first_0_after_1;
                                p->next=tmp;
                                prev=first_0_after_1;

			}
			first_0_after_1=first_0_after_1->next;
		}
	}
}
