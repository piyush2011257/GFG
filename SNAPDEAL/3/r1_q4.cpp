/*
Reverse linked lists k  blocks- iteration
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

void reverse ( node *h, bool has_k, int k );

int main()
{	int c;
	node *h1=NULL;
	printf("Enter list\n");
	while ( scanf("%d",&c) != EOF )
		if ( h1 == NULL )
		{	h1= new node();
			h1->data=c;
		}
		else
			push(h1,c);
	print(h1);
	int k;
	scanf("%d",&k);
	node *tmp_head=h1, *tmp=NULL,*nh,*oh,*nt,*ot;
	ot=oh=nt=nh=NULL;
	while ( tmp_head != NULL )
	{	oh=nh;
		ot=nt;
		nt=tmp=tmp_head;
		int i=1;
		while ( i<=k && tmp != NULL)
		{	if ( tmp->next == NULL || ( i == k ) )
				nh=tmp;
			i++;
			tmp=tmp->next;
		}
		tmp_head=nh->next;
		printf("i: %d\n",i);
		if ( i > k )
			reverse(nt,1,k);
		else
			reverse(nt,0,k);
		if ( ot != NULL )
			ot->next=nh;
		else
			h1=nh;
		print(h1);
		if ( tmp_head != NULL )
			printf("%d %p\n", tmp_head->data, tmp_head);
		//scanf("%d",&k);
	}
	print(h1);
	return 0;
}

void reverse ( node *h, bool has_k, int k )
{	node *curr=NULL, *prev=NULL, *next=NULL;
	curr=h;
	int ct=1;
	if ( has_k == 1 )
	{	while ( ct <= k )
		{	printf("%d %d %d\n",ct,k,curr->data);
			node *next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
			ct++;
		}
	}
	else
	{	while ( curr != NULL )
		{	node *next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
		}
	}
	printf("reverse-> ");
	print(prev);
}
