/*
Merge sort of a single linked list
*/
#include<cstdio>
using namespace std;

struct node
{	node *next;
	int data;
	node()
	{	next=NULL;	}
	node ( int d )
	{	data=d;	}
	node ( node * t )
	{	data=t->data;
		next=NULL;
	}
};

node * find_mid ( node * root, node *end )
{	if ( root == NULL )
		return NULL;
	node *slow, *fast;
	slow=fast=root;
	while ( 1 )
	{	fast=fast->next;
		if ( fast != end->next )
			fast=fast->next;
		else
			return slow;
		if ( fast == end->next )
			return slow;
		slow= slow->next;
	}
}

void merge_sort ( node *head, node *tail );
void merge( node *start, node *mid, node *end );

int main()
{	node *root=NULL, *end=NULL;
	int d;
	while ( scanf("%d",&d) != EOF )
		if ( root == NULL )
			end=root=new node(d);
		else
		{	end->next=new node(d);
			end=end->next;
		}
	merge_sort(root,end);
	for ( node *tmp=root; tmp != NULL; tmp=tmp->next )
		printf("%d ", tmp->data);
	printf("\n");
	return 0;
}

void merge_sort ( node *head, node *tail )
{	if ( head == NULL || tail == NULL )
                return;
	if ( head == tail )
		return;
	//printf("%d %d\n", head->data, tail->data);
	node *mid=find_mid(head,tail);
	merge_sort(head,mid);
	if ( mid != tail )
		merge_sort(mid->next,tail);
	merge(head,mid,tail);
}

void merge( node *start, node *mid, node *end )
{	node *l1_s=NULL, *l1_e=NULL, *l2_s=NULL, *l2_e=NULL;
	node *tmp=start;
	while ( tmp != mid->next )
	{	if ( l1_s == NULL )
			l1_s=l1_e=new node(tmp);
		else
		{	l1_e->next=new node(tmp);
			l1_e=l1_e->next;
		}
		tmp=tmp->next;
	}
	if ( mid != end )
	{	tmp=mid->next;
		while ( tmp != end->next )
		{	if ( l2_s == NULL )
                	        l2_s=l2_e=new node(tmp);
                	else
                	{       l2_e->next=new node(tmp);
                	        l2_e=l2_e->next;
                	}
			tmp=tmp->next;
		}
	}
	node *curr1=l1_s, *curr2=l2_s, *curr=start;
	while ( curr1 != l1_e->next  && curr2 != l2_e->next )
	{	if ( curr1->data <= curr2->data )
		{	curr->data=curr1->data;
			curr=curr->next;
			curr1=curr1->next;
		}
		else
		{	curr->data=curr2->data;
                        curr=curr->next;
                        curr2=curr2->next;
                }
	}
	while ( curr1 != l1_e->next )
	{	curr->data = curr1->data;
		curr1=curr1->next;
		curr=curr->next;
	}
        while ( curr2 != l2_e->next )
        {       curr->data = curr2->data;
                curr2=curr2->next;
		curr=curr->next;
        }
	/*
	printf("merge\n");
	for ( node * tmp= l1_s; tmp != l1_e->next; tmp=tmp->next )
		printf("%d ", tmp->data);
	printf("\n");
        for ( node * tmp= l2_s; tmp != l2_e->next; tmp=tmp->next )
                printf("%d ", tmp->data);
        printf("\n");
        for ( node * tmp= start; tmp != end->next; tmp=tmp->next )
                printf("%d ", tmp->data);
        printf("\n");
	printf("\n");
	*/
}
