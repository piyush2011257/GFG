/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-142-campus-sde-1/
Given M sorted linked lists of each of size N, we need to merge them to single linked list of size M x N using no extra space.

Solution
Pairwise merging
L1
L2
L3
L4

L1+L2
L3+L4

(L1+L2)+(L3+L4)

pseudocode
func( list *L[], int n)
{	list L'[N/2+ (1 if odd )]
	for ( i=0 -> N/2 )
		h=merge(h[i], h[i+1])
		L'.push(h);
	if n is odd
		L'.push(L[n-1])
	return func(L', n/2 + ( 1 if n is odd ))


termination condition
	if n == 2
		h= merge(l[0],l[1])
	return h		// new merged head

Complexity
n+n	2n	N/2		1st iter
2n+2n	4n	N/4		2nd iter
4n+4n	8n	N/8		3rd iter
so on till k=log2(N)


N*K where k=log2N
O(NlogN)
*/

#include<cstdio>
using namespace std;

struct node
{	node *next;
	int data;
	node(int d=-1)
	{	data=d;
		next=NULL;
	}
};

void insert ( node **head, node **tail, int data )
{	if ( *head == NULL )
	{	*head=*tail=new node(data);
		return;
	}
	(*tail)->next=new node(data);
	(*tail)=(*tail)->next;
}

void merge ( node *h1, node *h2, node **h3 );

int main()
{	node *h1,*t1, *h2, *t2;
	h1=h2=t1=t2=NULL;
	int d;
	while ( scanf("%d",&d) != EOF )
		insert(&h1,&t1,d);
        while ( scanf("%d",&d) != EOF )
                insert(&h2,&t2,d);
	node *h3;
	h3=NULL;
	merge(h1,h2,&h3);
	while ( h3 != NULL )
	{	printf("%d ", h3->data);
		h3=h3->next;
	}
	printf("\n");
	return 0;
}

void merge ( node *h1, node *h2, node **h3 )
{	node *h,*t;
	h=t=NULL;
	while ( h1 != NULL && h2 != NULL )
	{	if ( h1->data < h2->data )
		{	if ( *h3 == NULL )
				t=(*h3)=new node(h1->data);
			else
			{	t->next=h1;
				t=h1;
			}
			h1=h1->next;
			t->next=NULL;
		}
		else
		{       if ( *h3 == NULL )
                                t=(*h3)=new node(h1->data);
                        else
                        {       t->next=h2;
                                t=h2;
                        }
                        h2=h2->next;
                        t->next=NULL;
                }
	}
	if ( h1 != NULL )
		t->next=h1;
	if ( h2 != NULL )
		t->next=h2;
}
