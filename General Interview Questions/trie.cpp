/*
Narasimaha Karumanchi- String - Trie

http://www.geeksforgeeks.org/trie-insert-and-search/
Trie is an efficient information retrieval data structure. Using trie, search complexities can be brought to optimal limit (key length). If we store keys in binary search tree, a well balanced BST will need time proportional to M * log N, where M is maximum string length and N is number of keys in tree. Using trie, we can search the key in O(M) time. However the penalty is on trie storage requirements.

Every node of trie consists of multiple branches. Each branch represents a possible character of keys. We need to mark the last node of every key as leaf node. A trie node field value will be used to distinguish the node as leaf node (there are other uses of the value field). A simple structure to represent nodes of English alphabet can be as following,
struct trie_node
{
    int value;
    trie_node_t *children[ALPHABET_SIZE];
};

Inserting a key into trie is simple approach. Every character of input key is inserted as an individual trie node. Note that the children is an array of pointers to next level trie nodes. The key character acts as an index into the array children. If the input key is new or an extension of existing key, we need to construct non-existing nodes of the key, and mark leaf node. If the input key is prefix of existing key in trie, we simply mark the last node of key as leaf. The key length determines trie depth.

Searching for a key is similar to insert operation, however we only compare the characters and move down. The search can terminate due to end of string or lack of key in trie. In the former case, if the value field of last node is non-zero then the key exists in trie. In the second case, the search terminates without examining all the characters of key, since the key is not present in trie.

The following picture explains construction of trie using keys given in the example below,

                       root
                    /   \    \
                    t   a     b
                    |   |     |
                    h   n     y
                    |   |  \  |
                    e   s  y  e
                 /  |   |
                 i  r   w
                 |  |   |
                 r  e   e
                        |
                        r

In the picture, every character is of type trie_node_t. For example, the root is of type trie_node_t, and it’s children a, b and t are filled, all other nodes of root will be NULL. Similarly, “a” at the next level is having only one child (“n”), all other children are NULL. The leaf nodes are in blue.

Insert and search costs O(key_length), however the memory requirements of trie is O(ALPHABET_SIZE * key_length * N) where N is number of keys in trie. There are efficient representation of trie nodes (e.g. compressed trie, ternary search tree, etc.) to minimize memory requirements of trie.


http://www.geeksforgeeks.org/trie-delete/

During delete operation we delete the key in bottom up manner using recursion. The following are possible conditions when deleting key from trie,

    Key may not be there in trie. Delete operation should not modify trie. ( either not valid or if matched but is_word=0 )
    Key present as unique key (no part of key contains another key (prefix), nor the key itself is prefix of another key in trie). Delete all the nodes.
    Key is prefix key of another long key in trie. Unmark the leaf node.
    Key present in trie, having atleast one other key as prefix key. Delete nodes from end of key until first leaf node of longest prefix key.

*/

#include<cstdio>
#include<cstring>
using namespace std;

struct trie
{	char data;
	bool is_word;
	struct trie* child[26];			// Overhead of memory of storing 26 size pointer array for each node
	trie( char d=0, bool is_word=0 )
	{	data=d;
		is_word=0;
		for ( int i=0; i<26; i++ )
			child[i]=NULL;
	}
};


struct trie* insert ( struct trie* root, char *word, int pos );
struct trie * del ( struct trie* root, char *word, int pos );
void print_trie ( trie *root );

const int len=7;

int main()
{	struct trie *root[26]={NULL};
	// All small letter words assumed
	char ch[len][10]={ {"boats"},
			 {"boat"},
			 {"bat"},
			 {"bats"},
			 {"ram"},
			 {"raman"},
			 {"piyush"},
		       };
	for ( int i=0; i<len; i++ )
		root[ch[i][0]-'a'] = insert ( root[ch[i][0]-'a'], ch[i], 0 );
	for ( int i=0; i<26; i++ )
	{	if ( root[i] != NULL )
		{	print_trie(root[i]);
			printf("\n");
		}
	}
	char ch2[10];
	while ( scanf("%s",ch2) != EOF )
	{	root[ch2[0]-'a'] = del ( root[ch2[0]-'a'], ch2, 0 );
        	for ( int i=0; i<26; i++ )
        	{       if ( root[i] != NULL )
        	        {       print_trie(root[i]);
        	                printf("\n");
                	}
		}
        }
	return 0;
	
}

/*
Structure proposed in GFG
                       root
                    /   \    \
                    t   a     b
                    |   |     |
                    h   n     y
                    |   |  \  |
                    e   s  y  e
                 /  |   |
                 i  r   w
                 |  |   |
                 r  e   e
                        |
                        r

But we have used
                    t   a     b
                    |   |     |
                    h   n     y
                    |   |  \  |
                    e   s  y  e
                 /  |   |
                 i  r   w
                 |  |   |
                 r  e   e
                        |
                        r

single root -> root[26]
*/

void print_trie ( trie *root )
{	printf("{%c,%d} ", root->data, root->is_word);
	for ( int i=0; i<26; i++ )
		if ( root->child[i] != NULL )
			print_trie(root->child[i]);
}

// check before delete that not an empty string!!
struct trie* insert ( struct trie* root, char *word, int pos )
{       if ( root == NULL && word[pos] != '\0' )
        {       trie *tmp=new trie(word[pos]);
                //printf("%c\n", tmp->data);
                if ( word[pos+1] == '\0' )
                {       tmp->is_word=1;
                        return tmp;
                }
                else
                {       tmp->child[word[pos+1]-'a']= insert(tmp->child[word[pos+1]-'a'], word, pos+1);
                        return tmp;
                }
        }
        if ( word[pos] == '\0' )                // not encountered actually due to earlier check at pos-1
                return NULL;
        if ( word[pos+1] == '\0' )
        {       root->is_word=1;
                return root;
        }
        else
        {       root->child[word[pos+1]-'a']= insert(root->child[word[pos+1]-'a'], word, pos+1);
                return root;
        }
}

// check before delete that not an empty string!!
/*
Deletion 4 cases
1- Not found ->
		Word not present at all
		Word present but as a prefix of another word i.e. is_word == 0  at the end of pattern to be searched
2- Present 
		
	b
	|
	a
	|
	t,1
	|
	s,1

delete bat
                
        b
        |
        a
        |
        t,1
        |
        s,1

delete bats
                
        b
        |
        a,1
        |
        t
        |
        s
	|
	e,1

delete batse

*/
struct trie * del ( struct trie* root, char *word, int pos )
{	//printf("%p %c\n", root, word[pos]);
	if ( root == NULL && word[pos] != '\0' )
	{	printf("Not present\n");
		return root;
	}
	if ( word[pos+1] == '\0' )
	{	if ( root->is_word== 0 )
		{	printf("Not present as a word\n");
			return root;
		}
		bool ctr=0;
		for ( int i=0; i<26; i++ )
			if ( root->child[i] != NULL )
			{	ctr=1;
				break;
			}
		if ( ctr == 1 )
		{	root->is_word=0;
			return root;
		}
		else
			return NULL;
	}
	trie *tmp= root->child[word[pos+1]-'a'];
	root->child[word[pos+1]-'a']= del (  root->child[word[pos+1]-'a'], word, pos+1 );
	if ( tmp != NULL && root->child[word[pos+1]-'a'] == NULL )
	{	if ( root->is_word==1 )
			return root;
		bool ctr=0;
                for ( int i=0; i<26; i++ )
                       	if ( root->child[i] != NULL )
                       	{       ctr=1;
                       	        break;
                       	}
                if ( ctr == 1 )
                       return root;
                else
                        return NULL;
	}
	else
		return root;
}
