/*
Hashing- Separate Chain COllision Resolution Technique
*/
#include<cstdio>
using namespace std;

const int load_factor=2;		// ideally 5 -> 20

struct node
{	node *next;
	int key, data;
	node( int k=0, int d=0)
	{	key=k;
		data=d;
		next=NULL;
	}
};

struct hashtable_node
{	node *next, *end;
	int count;			// no. of elements in block
	hashtable_node()
	{	next=end=NULL;
		count=0;
	}
};

struct hashtable
{	int count;			// total number of elements currently in the Hash Table
	int tsize;			// size of Hash Table
	struct hashtable_node **table;
	hashtable()
	{	table=NULL;
		tsize=count=0;
	}
};

bool search ( struct hashtable *h, int key );
void create_hash_table ( struct hashtable **t, int n );
int hash( int key, int size );
void insert ( struct hashtable *h, int key, int data );
void print ( struct hashtable *h );
void rehash ( hashtable *h );

int main()
{	int n, key, val;
	scanf("%d",&n);
	struct hashtable *h;
	create_hash_table(&h,n);
	for ( int i=0; i<n; i++ )
	{	scanf("%d %d",&key,&val);
		insert(h,key,val);
		print(h);
	}
	//print(h);		
	return 0;
}

void create_hash_table ( struct hashtable **t, int n )
{	*t= new hashtable();
	(*t)->tsize=n/load_factor + 1;
	(*t)->table = new hashtable_node*[(*t)->tsize];
	for ( int i=0; i<(*t)->tsize; i++ )
		(*t)->table[i]= new hashtable_node();
	/*
	printf("%d\n", (*t)->tsize);
	for ( int i=0; i<(*t)->tsize; i++ )
		printf("%d %p\n",(*t)->table[i]->count, (*t)->table[i]->next);
	*/
}

int hash( int key, int size )
{	return key%size;	}

void insert ( struct hashtable *h, int key, int data )
{	int n=h->tsize;
	/*
	if ( search(h,key) == 1 )
	{	printf("Already present\n");
		return;
	}
	*/
	int idx=hash(key,n);
	node *tmp=h->table[idx]->next;
	if ( tmp == NULL )
		h->table[idx]->next = new node(key,data);
	else
	{	node *prev=NULL;
		while ( tmp != NULL )
		{	prev=tmp;
			if ( tmp->key == key )
			{	tmp->data=data;
				break;
			}
			tmp=tmp->next;
		}
		if ( tmp == NULL )
			prev->next= new node(key,data);
		else
			return;
	}
	h->table[idx]->count++;
	h->count++;
	if ( h->table[idx]->count > load_factor )
		rehash(h);
}

bool search ( struct hashtable *h, int key )
{	int n= h->tsize;
	int idx=hash(key,n);
	//printf("%d\n", idx);
	node *tmp=h->table[idx]->next;
	while ( tmp != NULL )
	{	if ( tmp->key == key )
			return 1;
		tmp=tmp->next;
	}
	return 0;
}

void print ( struct hashtable *h )
{	int n= h->tsize;
	for ( int i=0; i<n; i++ )
	{	if ( h->table[i]->next == NULL )
			continue;
		printf("index in hash_table: %d of size: %d->\n",i,h->table[i]->count);
		node *tmp=h->table[i]->next;
		if ( tmp == NULL )
			continue;
		while ( tmp != NULL )
		{	printf("key: %d  data: %d\n", tmp->key, tmp->data );
			tmp=tmp->next;
		}
		printf("\n");
	}
}

void rehash ( hashtable *h )			// Thi provides the dynamic nature!!
{	int old_size=h->tsize;
	h->tsize *= 2;
	hashtable_node **temp= h->table;
	h->table = new hashtable_node*[h->tsize];
        for ( int i=0; i<h->tsize; i++ )
                h->table[i]= new hashtable_node();
	for ( int i=0; i<old_size; i++ )
	{	node *tmp= temp[i]->next;
		while ( tmp != NULL )
		{	int idx=hash(tmp->key,h->tsize);
			if ( h->table[idx]->next == NULL )
				h->table[idx]->next=new node(tmp->key, tmp->data);
			else
			{	node *prev=NULL;
				node *curr=h->table[idx]->next;	// insert at head for re-hash to be easy and change pointer linkgae directly
				while ( curr != NULL )
				{	prev=curr;
					curr=curr->next;
				}
				prev->next=new node(tmp->key, tmp->data);
			}
			tmp= tmp->next;
			h->table[idx]->count++;
		}
	}
}

/* For rehash this code creates a new memory location dynamically.
This needs to be optimized by-
1-> Insertion at head only- O(1)
2-> Pointer adjustment for old location instead of creating new locations
*/
