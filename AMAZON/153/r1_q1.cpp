/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-153-sde1/
Q1. Given two link list that represents no. write a program to add two given two link list and return new link list that represents sum of no. represented by given two link lists.

Add two numbers represented by linked lists | Set 2
http://www.geeksforgeeks.org/sum-of-two-linked-lists/
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

node * func ( node *h1, node *h2, int *carry )
{	if ( h1==NULL && h2==NULL )
	{	*carry=0;
		return NULL;
	}
	node *tmp=new node();
	node *next=func(h1->next, h2->next, carry);
	tmp->data= (h1->data + h2->data + (*carry) )%10;
	*carry=(h1->data + h2->data + (*carry) )/10;
	tmp->next=next;
	return tmp;
}

node * add_to_left_over ( node *h, node *t, node *sumlist, int *carry )
{	if ( h==t )
		return sumlist;
	node *next=add_to_left_over(h->next, t, sumlist, carry);
	node *tmp=new node();
	tmp->data = ( h->data + (*carry))%10;
	tmp->next=next;
	*carry = ( h->data + (*carry))/10;
	return tmp;
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
	printf("Enter list2\n");
	while ( scanf("%d",&c) != EOF )
		if ( h2 == NULL )
		{	h2= new node();
			h2->data=c;
		}
		else
			push(h2,c);
	print(h1);
	print(h2);
	int l1=getlength(h1);
	int l2=getlength(h2);
	if ( l2 > l1 )
	{	node *t=h1;
		h1=h2;
		h2=t;
		l1=l1^l2;
		l2=l1^l2;
		l1=l1^l2;
	}
	// assuming l1 >= l2
	node *tmp=h1;
	for ( int i=1; i<= l1-l2; i++ )
		tmp=tmp->next;
	int carry=0;
	
	printf("%d %d\n", l1, l2);
	node *sumlist=func(tmp, h2, &carry);
	print(sumlist);
	if ( l1 == l2 )
	{	print(sumlist);
		return 0;
	}
	node *h3=NULL;
	node *next=add_to_left_over(h1,tmp,sumlist,&carry);
	if ( carry != 0 )
	{	node *tmp=new node();
		tmp->data=carry;
		tmp->next=next;
		h3=tmp;
	}
	else
		h3=next;
	print(h3);
	return 0;
}
