/*
Reverse linked lists- recursive
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

node * reverse ( node *n, node **nh )
{	if ( n->next == NULL )
	{	*nh=n;
		return n;
	}
	node *head=reverse(n->next, nh);
	head->next=n;
	return n;
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
	node *nh=NULL;
	node *tmp=reverse(h1,&nh);
	if ( tmp != NULL )
		tmp->next=NULL;
	print(nh);
	return 0;
}
