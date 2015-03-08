/*
www.geeksforgeeks.org/amazon-interview-experience-set-177-first-round-pool-campus/
given 3 Numbers in Linked list, we had to return the Linked List of representing sum of all three, covering all base and condition of addition.*/
#include<cstdio>
#include<iostream>
using namespace std;

struct node
{	node *next;
	int data;
	node(int d )
	{	data=d;
		next=NULL;
	}
};

void print ( node *tmp )
{	while ( tmp != NULL )
	{	cout<<tmp->data<<" ";
		tmp=tmp->next;
	}
	cout<<endl;
}

node * func ( node *l1, node *l2, node *l3 );

int main()
{	node *l1=NULL, *l2=NULL,  *l3=NULL, *t=NULL;
	int d;
	while ( scanf("%d",&d) != EOF )
	{	if ( l1 == NULL )
			l1=t=new node(d);
		else
		{	t->next= new node(d);
			t=t->next;
		}
	}
        while ( scanf("%d",&d) != EOF )
        {       if ( l2 == NULL )
                        l2=t=new node(d);
                else
                {       t->next= new node(d);
                        t=t->next;
                }
        }
        while ( scanf("%d",&d) != EOF )
        {       if ( l3 == NULL )
                        l3=t=new node(d);
                else
                {       t->next= new node(d);
                        t=t->next;
                }
        }
	print(l1);
	print(l2);
	print(l3);
	print(func(l1,l2,l3));
	return 0;
}

node * func ( node *l1, node *l2, node *l3 )
{	int carry=0, c1, c2, c3, sum;
	node *l4=NULL, *t;
	while ( l1 != NULL || l2 != NULL || l3 != NULL )
	{	c1 = ( l1 == NULL ) ? 0 : l1->data;
		c2 = ( l2 == NULL ) ? 0 : l2->data;
		c3 = ( l3 == NULL ) ? 0 : l3->data;
		sum = (c1+c2+c3+carry);
		carry=sum/10;
		sum=sum%10;
		if ( l4 == NULL )
			l4=t=new node(sum);
		else
		{	t->next=new node(sum);
			t=t->next;
		}
		if ( l1 != NULL )
			l1=l1->next;
                if ( l2 != NULL )
                        l2=l2->next;
                if ( l3 != NULL )
                        l3=l3->next;
	}
	if ( carry != 0 )
	{	if ( l4 == NULL )
                        l4=t=new node(carry);
                else
                {       t->next=new node(carry);
                        t=t->next;
                }
	}
	return l4;
}
