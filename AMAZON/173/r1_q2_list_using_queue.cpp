/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-173-campus/
You are given an array of both negative and positive integers. You need to rearrange the array such that positive and negative numbers alternate. Also, the order should be same as previous array and only O(1) auxiliary space can be used and time complexity O(n).
eg. -2 3 4 5 -1 -6 7 9 1
result – 3 -2 4 -1 5 -6 7 9 1.

http://stackoverflow.com/questions/4897280/given-an-array-of-positive-and-negative-integers-re-arrange-it-so-that-you-have
http://www.careercup.com/question?id=4748947486670848

Take two queues
1) In first scan put all +ve's in one queue and -ve's in other queue.
2) In second scan Dequeue alternatively.
3) If any queue is empty Dequeue other queue until empty.

Separate odd and even numbers in a list
*/

#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

struct node
{	node *next;
	int data;
	node( int d=-1, node *n=NULL )
	{	data=d;
		next=n;
	}
};

void insert ( node **root, int d )
{	if ( *root == NULL )
	{	*root= new node(d);
		return;
	}
	node *tmp=*root;
	while ( tmp->next != NULL )
		tmp=tmp->next;
	tmp->next=new node(d);
}

void insert_list ( node **head, node **tail, node *root )
{	if (*head == NULL )
		*head=*tail=root;
	else
	{	(*tail)->next=root;
		*tail=root;
	}
}

void print ( node *root )
{	while ( root != NULL )
	{	cout<<root->data<<" ";
		root=root->next;
	}
	cout<<endl;
}

int main()
{	int n, ch;
	cin>>n;
	node *root=NULL;
	for ( int i=0; i<n; i++ )
	{	cin>>ch;
		insert(&root,ch);
	}
	print(root);
	node *pos_h, *pos_t, *neg_h, *neg_t, *zero_h, *zero_t;
	pos_h=pos_t=neg_h=neg_t=zero_h=zero_t=NULL;
	while ( root != NULL )
	{	if ( root->data == 0 )
			insert_list ( &zero_h, &zero_t,root);
		else if ( root->data > 0 )
			insert_list (&pos_h,&pos_t,root);
		else
			insert_list (&neg_h,&neg_t,root);
		root=root->next;
	}
	if ( pos_t != NULL )
		pos_t->next=NULL;
        if ( neg_t != NULL )
                neg_t->next=NULL;
        if ( zero_t != NULL )
                zero_t->next=NULL;
	//print(pos_h);				// ordered +ve number
	//print(neg_h);				// ordered -ve number
	//print(zero_h);				// all zeroes
	root=NULL;
	node *prev=NULL;
	// merge 2 lists
	while ( pos_h != NULL && neg_h != NULL )
	{	node *pos_next=pos_h->next;
		node *neg_next=neg_h->next;
		if ( root == NULL )
		{	prev=root=pos_h;
			prev->next=neg_h;
			prev=prev->next;
		}
		else
		{	prev->next=pos_h;
			prev->next->next=neg_h;
			prev=prev->next->next;
		}
		pos_h=pos_next;
		neg_h=neg_next;
		//cout<<"prev: "<<prev<<" root: "<<root<<" pos_h: "<<pos_h<<" neg_h: "<<neg_h<<endl;
	}
	//print(root);
	while ( pos_h != NULL )
	{	node *pos_next=pos_h->next;
		if ( root == NULL )
			root=prev=pos_h;
		else
		{	prev->next=pos_h;
			prev=prev->next;
		}
		pos_h=pos_next;
	}
        while ( neg_h != NULL )
        {       node *neg_next=neg_h->next;
                if ( root == NULL )
                        root=prev=neg_h;
                else    
                {	prev->next=neg_h;
                	prev=prev->next;
		}
                neg_h=neg_next;
        }
	while ( zero_h != NULL )
	{	node *zero_next=zero_h->next;
		if ( root == NULL )
			root=prev=zero_h;
		else
		{	prev->next=zero_h;
			prev=prev->next;
		}
		zero_h=zero_next;
	}
	print(root);
	return 0;
}
