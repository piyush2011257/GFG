/*
Hashing- Open Addressing / Quadratic Probing Collision resolution technique
http://en.wikipedia.org/wiki/Quadratic_probing

Algorithm to insert key in hash table

 1. Get the key k
 2. Set counter j = 0
 3. Compute hash function h[k] = k % SIZE
 4. If hashtable[h[k]] is empty
         (4.1) Insert key k at hashtable[h[k]]
         (4.2) Stop
    Else
        (4.3) The key space at hashtable[h[k]] is occupied, so we need to find the next available key space
        (4.4) Increment j
        (4.5) Compute new hash function h[k] = ( k + j * j ) % SIZE
        (4.6) Repeat Step 4 till j is equal to the SIZE of hash table
 5. The hash table is full
 6. Stop


Algorithm to search element in hash table

 1. Get the key k to be searched
 2. Set counter j = 0
 3. Compute hash function h[k] = k % SIZE
 4. If the key space at hashtable[h[k]] is occupied
         (4.1) Compare the element at hashtable[h[k]] with the key k.
         (4.2) If they are equal
         (4.2.1) The key is found at the bucket h[k]
         (4.2.2) Stop
    Else
         (4.3) The element might be placed at the next location given by the quadratic function
         (4.4) Increment j
         (4.5) Compute new hash function h[k] = ( k + j * j ) % SIZE
         (4.6) Repeat Step 4 till j is greater than SIZE of hash table
 5. The key was not found in the hash table
 6. Stop

Limitations

For linear probing it is a bad idea to let the hash table get nearly full, because performance is degraded as the hash table gets filled. In the case of quadratic probing, the situation is even more drastic. With the exception of the triangular number case for a power-of-two-sized hash table, there is no guarantee of finding an empty cell once the table gets more than half full, or even before the table gets half full if the table size is not prime. This is because at most half of the table can be used as alternative locations to resolve collisions. If the hash table size is b (a prime greater than 3), it can be proven that the first b / 2 alternative locations including the initial location h(k) are all distinct and unique.

How to optimize as only first b/2 alternative locations are unique??

Alternating sign

If the sign of the offset is alternated (e.g. +1, -4, +9, -16, +25, -36, +49, -64, +81,  etc.), and if the number of buckets is a prime number p congruent to 3 modulo 4 (i.e. one of 3, 7, 11, 19, 23, 31 and so on), then the first p offsets will be unique modulo p.

In other words, a permutation of 0 through p-1 is obtained, and, consequently, a free bucket will always be found as long as there exists at least one.

The insertion algorithm only receives a minor modification (but do note that SIZE has to be a suitable prime number as explained above):
1. Get the key k
2. Set counter j = 0
3. Compute hash function h[k] = k % SIZE
4. If hashtable[h[k]] is empty
        (4.1) Insert key k at hashtable[h[k]]
        (4.2) Stop
   Else
       (4.3) The key space at hashtable[h[k]] is occupied, so we need to find the next available key space
       (4.4) Increment j
       (4.5) Compute new hash function h[k]. If j is odd, then					THE CHANGE IS HERE
             h[k] = ( k + j * j ) % SIZE, else h[k] = ( k - j * j ) % SIZE
       (4.6) Repeat Step 4 till j is equal to the SIZE of hash table
5. The hash table is full
6. Stop

Now first p alternative locations are unique instead of b/2 wher p-> prime number : p%4 = 3 and b -> table size

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
/*
Secondary clstering
i/p
1 2 5 6 
at 6 it gives hashing overflow

For linear probing it is a bad idea to let the hash table get nearly full, because performance is degraded as the hash table gets filled. In the case of quadratic probing, the situation is even more drastic. With the exception of the triangular number case for a power-of-two-sized hash table, there is no guarantee of finding an empty cell once the table gets more than half full, or even before the table gets half full if the table size is not prime. This is because at most half of the table can be used as alternative locations to resolve collisions. If the hash table size is b (a prime greater than 3), it can be proven that the first b / 2 alternative locations including the initial location h(k) are all distinct and unique. 

*/
void insert ( int **h, int n, int key )
{	int idx=hash(key,n);
	if ( (*h)[idx] == -1 || (*h)[idx] == key )
	{	(*h)[idx]=key;
		return;
	}
	int ctr=1;
	while ( ctr <= n )
	{	int pos=(idx+(ctr*ctr))%n;
		printf("pos: %d\n",pos);
		if ( (*h)[pos] == -1 || (*h)[pos] == key )		// if already present update
		{	(*h)[pos]=key;
			return;
		}
		ctr++;
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
