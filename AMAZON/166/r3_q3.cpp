http://www.geeksforgeeks.org/amazon-interview-experience-set-166-sde/
Write a hashing function for storing stream of words.

http://homepage.cs.uiowa.edu/~kvaradar/sp2009/SeparateChainingHashTable.java

    /**
     * Construct the hash table.
     */
    public SeparateChainingHashTable( )
    {
        this( DEFAULT_TABLE_SIZE );
    }
    DEFAULT_TABLE_SIZE=101			// prime initially. Try to use prime only
					// using sieve to get get a list of primes and put an upper limit on the primes and else do 2*size


Create a default hash table from table size and Load Factor usage

    /**
     * A hash routine for String objects.
     * @param key the String to hash.
     * @param tableSize the size of the hash table.
     * @return the hash value.
     */
    public static int hash( String key, int tableSize )	
    {	int hashVal = 0;
	for( int i = 0; i < key.length( ); i++ )
        	hashVal = 37 * hashVal + key.charAt( i );	
/*
	int hashvalue, may go negative, let it become negative andc have c yclic nature - > 
	optimize ( hashvalue<<5 + hashvalue<<2 + hashvalue ) + key[i]
*/
	hashVal %= tableSize;
        if( hashVal < 0 )
        	hashVal += tableSize;			// if negative value
	return hashVal;
    }

hash(i) = hash(i-1)*33 + (int)ch[i]
hash(-1)=0
hash(n-1) -> hash value

Hash function for string- 
http://www.cse.yorku.ca/~oz/hash.html

1- djb2  ( above mentioned algorithm )
this algorithm (k=33) was first reported by dan bernstein many years ago in comp.lang.c. another version of this algorithm (now favored by bernstein) uses xor: hash(i) = hash(i - 1) * 33 ^ str[i]; the magic of number 33 (why it works better than many other constants, prime or not) has never been adequately explained.

    unsigned long
    hash(unsigned char *str)
    {
        unsigned long hash = 5381;
        int c;
        while (c = *str++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */	-> C-ASCII value of character

        return hash;
    }

Other trivial algorithms

2-
map[]= a-1, b=2, c=3, d=5, e=7, f=11,... z=101
mod=1000000007
str[N]
prod=1;
for ( int =0; i<n; i++ )
	prod = prod * map[str[i]]
	prod=prod%mod
if prod < mod
	prod += mod

Product of elements using prime and modulo a prime

Optimize
a,e,i,o,u - most common elements
a=1
e=2
i=3
o=5
u=7


3- instead of prime, use index of character and its ACII value-ASCII value of 'a' % mod
for ( int =0; i<n; i++ )
        prod += i * (str[i]-'a')
        prod=prod%mod
if prod < mod			// incase overflow intermediate,
        prod += mod



Then we do hash_value % table_size to get the memory location
