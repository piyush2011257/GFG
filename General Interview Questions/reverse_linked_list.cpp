/*
Reverse linked lists- iteration
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

void push(node *h, int d )
{	while ( h->next != NULL )
		h=h->next;
	node *tmp=new node(d);
	h->next=tmp;
}

void print(node *h)
{	while(h != NULL )
	{	printf("%d -> ", h->data);
		h=h->next;
	}
	printf("\n");
}

int getlength ( node *h)
{	int i=0;
	while ( h!=NULL )
	{	i++;
		h=h->next;
	}
	return i;
}

int main()
{	int c;
	node *h1=NULL, *h2=NULL;
	printf("Enter list1\n");
	while ( scanf("%d\n",&c) != EOF )
		if ( h1 == NULL )
		{	h1= new node();
			h1->data=c;
		}
		else
			push(h1,c);
	print(h1);
	node *curr=NULL, *prev=NULL, *next=NULL;
	curr=h1;
	while ( curr != NULL )
	{	node *next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	print(prev);
	return 0;
}
