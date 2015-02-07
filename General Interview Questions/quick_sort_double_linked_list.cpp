/*
http://www.geeksforgeeks.org/quicksort-for-linked-list/
*/
#include<cstdio>
using namespace std;

struct node
{	node *next, *prev;
	int data;
	node()
	{	prev=next=NULL;
	}
};

void quick_ll ( node *head, node *tail, node **h, node **t );

int main()
{	node *head=NULL, *tail=NULL;
	int d;
	while ( scanf("%d",&d) != EOF )
	{	node *t= new node();
		t->data=d;
		if ( head == NULL )
			head=tail=t;
		else
		{	tail->next=t;
			t->prev=tail;
			tail=t;
		}
	}
	node *root_h=NULL, *root_t=NULL;
	quick_ll (head,tail,&root_h,&root_t);
	node *tmp=root_h;
	while ( tmp != NULL )
	{	printf("%d ", tmp->data);
		tmp=tmp->next;
	}
	printf("\n");
	return 0;
}

void quick_ll ( node *head, node *tail, node **h, node **t )
{	if ( head == NULL || tail == NULL )
	{	*h=*t=NULL;
		return;
	}
	//printf("%d %d\n", head->data, tail->data);
	if ( head == tail )
	{	*h=head, *t=tail;
		return;
	}
	node *pivot=head;
	node *before_h=NULL, *before_t=NULL, *after_h=NULL, *after_t=NULL;
	node *tmp=head->next;
	while ( tmp != NULL )
	{	if ( tmp->data <= pivot->data )
		{	if ( before_h == NULL )
				before_h=before_t=tmp;
			else
			{	before_t->next=tmp;
				before_t=tmp;
			}
		}
		else
		{	if ( after_h == NULL )
                                after_h=after_t=tmp;
                        else
                        {       after_t->next=tmp;
                                after_t=tmp;
                        }
                }
		tmp=tmp->next;
	}
	if ( after_t != NULL )
		after_t->next=NULL;
	if ( before_t != NULL )
		before_t->next=NULL;
	pivot->next=NULL;
	quick_ll(before_h, before_t,h,t);
	node *left_h=*h;
	node *left_t=*t;
	quick_ll(after_h,after_t,h,t);
	node *right_h=*h;
	node *right_t=*t;
	if ( left_h == NULL || left_t == NULL )
		*h=pivot;
	else
	{	*h=left_h;
		left_t->next=pivot;
	}
	if ( right_h == NULL || right_t == NULL )
		*t=pivot;
	else
	{	*t=right_t;
		pivot->next=right_h;
	}
}
