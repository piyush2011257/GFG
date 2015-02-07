/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-153-sde1/
Q2. Design data structure that supports insert(), remove(), find-max(), delete-max() operations. All operations should run in O(1) time. Lots of discussion was there, discussed many approaches.

http://www.geeksforgeeks.org/a-data-structure-question/
Design an efficient data structure for given operations
*/

#include<cstdio>
#include<map>
#include<list>
using namespace std;

struct node
{	node *next,*prev;
	int data;
	node()
	{	next=NULL, prev=NULL;
		data=-1;
	}
};

node * insert ( node **head, node **tail, int d )
{	if ( *head==NULL )
	{	*head=new node();
		*tail=*head;
		(*head)->data=d;
		return *head;
	}
	node *tmp=*head;
	while ( tmp != NULL && tmp->data < d )
		tmp=tmp->next;
	if ( tmp == NULL )
	{	tmp=new node();
		tmp->data=d;
		tmp->prev=*tail;
		(*tail)->next=tmp;
		*tail=tmp;
		return tmp;
	}
	else
	{	node *prev=tmp->prev;
		node *t=new node();
		t->data=d;
		t->next=tmp;
		t->prev=prev;
		tmp->prev=t;
		if ( prev != NULL )
			prev->next=t;
		else
			*head=t;
		return t;
	}
}

void del ( node **head, node **tail, node *p )
{	if ( p == *head )
	{	*head = (*head)->next;
		if ( *head != NULL )
			(*head)->prev=NULL;
		if ( p == *tail )
			*tail=NULL;
	}
	else if ( p == *tail )
        {       *tail = (*tail)->prev;
		(*tail)->next=NULL;
        }
	else
	{	node *t=p->prev;
		t->next=p->next;
		p->next->prev=t;
	}
}

void print ( node *h, node *t )
{	while ( h != t )
	{	printf("%d %p %p->\n", h->data, h->prev, h->next);
		h=h->next;
	}
	if ( t != NULL )
		printf("%d %p %p\n", t->data, t->prev, t->next);
}

int main()
{	map<int,list<node *> >m;
	node *head=NULL, *tail=NULL;
	printf("1- Insert\n2- Delete\n3-Find-Max\n4-Delete-Max\n");
	char ch;
	while ( scanf("%c", &ch) != EOF )
	{	if ( ch == '1' )
		{	int d;
			scanf("%d",&d);
			node *p = insert(&head,&tail, d );
			print(head,tail);
			m[d].push_back(p);
		}
		else if ( ch == '2' )
		{	int d;
			scanf("%d",&d);
			if ( m.count(d) != 0 )
			{	node *p = m[d].front();
				m[d].pop_front();
				if ( m[d].empty() == 1 )
					m.erase(d);
				del(&head,&tail,p);
				print(head,tail);
			}
			else
				printf("Element not present\n");
		}
		else if ( ch =='3' )
		{	if ( head == NULL )
				printf("Empty list\n");
			else
				printf("%d\n", tail->data);
		}
		else if ( ch == '4' )
		{	node *p = tail;
                        if ( p != NULL )
				del(&head,&tail,p);
			else
				printf("Empty list\n");
                        print(head,tail);
		}
	}	
	return 0;	
}

/*
Our way DLL + MAP + ALMOST SORTED INSERTION
	INSERT - O(N)
	DELETE- O(1)
	FINDMAX- O(1)
	DELMAX- O(1)

OTHER WAY OF USING HEAP STRUCTURE AND DLL
        INSERT - O(LOGN)
        DELETE- O(LOGN)
        FINDMAX- O(1)
        DELMAX- O(LOGN)
*/
