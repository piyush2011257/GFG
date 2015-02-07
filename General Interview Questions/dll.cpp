/*
double linked lists
*/

#include<cstdio>
using namespace std;

struct node
{	node *next, *prev;
	int data;
	node(int d=-1, node *n=NULL, node *p=NULL)
	{	data=d;
		next=n;
		prev=p;
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
	tmp->prev=t;
}

void print(node *h)
{	while(h != NULL )
	{	printf("%d-> ", h->data);
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

void del ( node **root, int d )
{	node *tmp=*root,*p=NULL;
	while ( tmp != NULL && tmp->data != d )
	{	p=tmp;
		tmp=tmp->next;
	}
	if ( tmp == NULL )
		printf("Not present\n");
	else if ( p == NULL )
	{	*root= (*root)->next;
		if (*root != NULL )
			(*root)->prev=NULL;
	}
	else
	{	p->next=tmp->next;
		if ( tmp->next != NULL )
			tmp->next->prev=p;
	}
}

int main()
{	int c;
	node *root=NULL;
	printf("1- Insert\n2- Delete\n");
	while ( scanf("%d\n",&c) != EOF )
	{	if ( c == 1 )
		{	int d;
			scanf("%d",&d);
			push(&root,d);
		}
		else
		{	int d;
			scanf("%d",&d);
			del(&root,d);
		}
		print(root);	
	}
	return 0;
}
