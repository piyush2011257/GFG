/*
linked lists
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
		*root= (*root)->next;
	else
		p->next=tmp->next;
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
