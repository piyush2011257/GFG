/*
Hashing- Open Addressing / Linear Probing Collision resolution technique
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

// Load Factor is 1

void create_hash_table ( int **h, int n );
void delete_hash_table ( int **h, int n, int key );
void insert ( int **h, int n, int key );
int hash ( int key, int size );
void print ( int *h, int n );

int main()
{	int n, key, val;
	scanf("%d",&n);
	int *h;
	create_hash_table(&h,n);
	for ( int i=0; i<n; i++ )
	{	scanf("%d",&key);
		insert(&h,n,key);
		print(h,n);
	}
	return 0;
}

void print ( int *a, int n )
{	for ( int i=0; i<n; i++ )
		if ( a[i] != -1 )
			printf("%d %d\n",i,a[i]);
	printf("\n");
}


void create_hash_table ( int **h, int n )
{	*h= new int[n];
	for ( int i=0; i<n; i++ )
		(*h)[i]=-1;
}

void insert ( int **h, int n, int key )
{	int idx=hash(key,n);
	if ( (*h)[idx] == -1 || (*h)[idx] == key )
	{	(*h)[idx]=key;
		return;
	}
	int old_pos=idx;
	idx=(idx+1)%n;			// rehash
	while ( idx != old_pos )
	{	if ( (*h)[idx] == -1 || (*h)[idx] == key )		// if already present update
		{	(*h)[idx]=key;
			return;
		}
		idx=(idx+1)%n;
	}
	printf("Hash overflow\n");
	exit(0);
}

int hash ( int key, int size )
{	return key%size;	}

void delete_hash_table ( int **h, int n, int key )
{	int idx=hash(key,n);
	if ( (*h)[idx] == key )
	{	(*h)[idx]=-1;
		return;
	}
	int old_pos=idx;
	idx=(idx+1)%n;
	while ( idx != old_pos )
	{	if ( (*h)[idx] == key )
		{	(*h)[idx]=-1;
			return;
		}
		idx=(idx+1)%n;
	}
	printf("Not Found\n");
}
