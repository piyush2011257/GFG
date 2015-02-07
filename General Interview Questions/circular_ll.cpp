/*
circular linked lists
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
		(*h)->next=(*h)->prev=*h;
		return;
	}
	node *t=*h;
	while ( t->next != *h )
		t=t->next;
	node *tmp=new node(d);
	t->next=tmp;
	tmp->prev=t;
	tmp->next=*h;
	(*h)->prev=tmp;
}

void print(node *h)
{	if ( h != NULL )
	{	node *tmp=h;
		printf("%d-> ", tmp->data);
		tmp=tmp->next; 
		while( tmp != h )
		{	printf("%d-> ", tmp->data);
			tmp=tmp->next;
		}
	}
	printf("\n");
}

void del ( node **root, int d )
{	if (*root == NULL )
		return;
	node *tmp=(*root)->next,*p=*root;
	if ( (*root)->next == *root )
	{	if ( (*root)->data == d )
			*root=NULL;
		else
			printf("Not present\n");
		return;
	}
	if ( (*root)->data == d )
	{	(*root)->next->prev=(*root)->prev;
		(*root)->prev->next=(*root)->next;
		*root =(*root)->next;
		return;
	}		
	while ( tmp != *root && tmp->data != d )
	{	p=tmp;
		tmp=tmp->next;
	}
	if ( tmp == *root )
		printf("Not present\n");
	else
	{	p->next=tmp->next;
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
