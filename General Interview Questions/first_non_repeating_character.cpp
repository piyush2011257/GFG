/*
http://www.geeksforgeeks.org/find-first-non-repeating-character-stream-characters/
*/
#include<map>
#include<cstdio>
using namespace std;

struct node
{	node *next, *prev;
	char data;
	node(char d=-1, node *n=NULL, node *p=NULL)
	{	data=d;
		next=n;
		prev=p;
	}
	
};

map<char, node *> m;

void push(node **h, char d )
{	if ( *h == NULL )
	{	*h= new node(d);
		m[d]=*h;
		return;
	}
	node *t=*h;
	while ( t->next != NULL )
		t=t->next;
	node *tmp=new node(d);
	t->next=tmp;
	tmp->prev=t;
	m[d]=tmp;
}

void print(node *h)
{	while(h != NULL )
	{	printf("%c-> ", h->data);
		h=h->next;
	}
	printf("\n");
}

void del ( node **root, char d )		// can be done in O(1), now we have a map to the node as well!!
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
{	node *root=NULL;
	char ch[100];
	scanf("%s",ch);
	bool occur[256]={0};
	for ( int i=0; ch[i] != '\0'; i++ )
	{	if ( occur[ch[i]] == 0 )
		{	occur[ch[i]]=1;
			push(&root,ch[i]);
		}
		else
		{	if ( m.count((char)ch[i]) != 0 )
			{	del(&root, ch[i]);
				m.erase(ch[i]);
			}
		}
		if ( root != NULL )
			printf("%c\n", root->data);
		else
			printf("All repeated\n");
		//print(root);
	}
	return 0;
}
