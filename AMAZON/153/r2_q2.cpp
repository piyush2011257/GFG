/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-153-sde1/
Q2. Check whether given link list represents palindrome.

METHOD 1 (Use a Stack)
http://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/
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

bool func ( node *t, node **h )
{	if ( t==NULL )
		return 1;
	int d= t->data;
	bool val=func(t->next, h);
	//printf("%d %d %p\n", d, (*h)->data, *h);
	if ( val == 0 )
		return 0;
	if ( d != (*h)->data )
		return 0;
	(*h) = (*h)->next;
	//printf("%p\n", *h);
	return 1;
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
	bool val=0;
	node *tmp=h1;
	val= func(h1, &tmp);
	printf("List is pallindrome: %d\n", val);
	return 0;
}
