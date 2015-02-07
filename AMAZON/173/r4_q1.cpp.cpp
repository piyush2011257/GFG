/*
k-most occuring words using trie.cpp
http://www.geeksforgeeks.org/find-the-k-most-frequent-words-from-a-file/

We can use Trie and Min Heap to get the k most frequent words efficiently. The idea is to use Trie for searching existing words adding new words efficiently. Trie also stores count of occurrences of words. A Min Heap of size k is used to keep track of k most frequent words at any point of time(Use of Min Heap is same as we used it to find k largest elements in this post).
Trie and Min Heap are linked with each other by storing an additional field in Trie ‘indexMinHeap’ and a pointer ‘trNode’ in Min Heap. The value of ‘indexMinHeap’ is maintained as -1 for the words which are currently not in Min Heap (or currently not among the top k frequent words). For the words which are present in Min Heap, ‘indexMinHeap’ contains, index of the word in Min Heap. The pointer ‘trNode’ in Min Heap points to the leaf node corresponding to the word in Trie.

http://www.geeksforgeeks.org/amazon-interview-experience-set-173-campus/

Q1.website having several web-pages. And also there are lot many user who are accessing the web-site.
say user 1 has access pattern : x->y->z->a->b->c->d->e->f
user 2 has access pattern : z->a->b->c->d
user 3 has access pattern : y->z->a->b->c->d
user 4 has access pattern : a->b->c->d
and list goes on for lot many users which are finite and numbered.
Now the question is we have to determine the top 3 most occurring k-Page-sequence.
for the above example result will be : (k=3) a->b->c , b->c->d , z->a->b.

http://www.careercup.com/question?id=9981709
http://stackoverflow.com/questions/8683060/finding-the-most-common-three-item-sequence-in-a-very-large-file
http://stackoverflow.com/questions/2991480/most-frequent-3-page-sequence-in-a-weblog

xyz,1
yza,2
zab,3
abc,4
bcd,4
cde,1
def,1

bcd,3
abc,4
zab,4




	a		b		c	abc,4
	
	
	b		c		d	bcd,4
	
	
	c		d		e	cde,1
	
		
	d		e		f	def,1
	
	
	x		y		z	xyz,1
	
	
	y		z		a	yza,2
	
	
	z		a		b	zab,3


Heap of size 3
m<string,pos> m
m[xyz]=pos_in_heap		-1 if not present

struct heap_data
{	string str;
	int ct;
}

Creation of trie- O(WK)			W- no. of words, K- k-Page-sequence
Updation in min-heap of size S- O(logS)	here S=3

At the end we have top 3 K sized pages as string
Space 26*sizeof(node *)
sizeof(node)	= (4*26+K+1+4) bytes
	 	= 109+K bytes per node

Space can be optimized using TST
*/

#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

struct trie
{	char data;
	int is_word, idx;
	struct trie* child[26];			// Overhead of memory of storing 26 size pointer array for each node
	trie( char d=0 )
	{	data=d;
		idx=-1;
		is_word=0;			// counts occurence of the word
		for ( int i=0; i<26; i++ )
			child[i]=NULL;
	}
};

struct heap
{	trie *node;
	int occur;
	char word[100];
	heap(trie *n=NULL)
	{	node=n;
		occur=0;
		word[0]='\0';
	}
};

struct trie* insert ( struct trie* root, struct heap *h, int *heap_size, char *word, int pos, string s, int k );
void print_trie ( trie *root, string s );
void insert_word ( trie *root, heap *h, int *size, int k, string s );
void insert_heap ( heap *a, int s );
void insert_heap_down ( heap *h, int s, int idx );

const int len=69;

int main()
{	struct trie *root[26]={NULL};
	// All small letter words assumed
	/*
	char ch[len][10]={ {"boats"},
			 {"boat"},
			 {"bat"},
			 {"bats"},
			 {"ram"},
			 {"raman"},
			 {"piyush"},
			 {"boats"},
			 {"bats"},
			 {"raman"},
			 {"bats"},
			 {"piyush"},
			 {"raman"},
			 {"raman"},
			 {"bat"},
		       };
	*/
	
	char ch[len][14]={"welcome","to", "the", "world", "of", "geeks", "this", "portal", "has", "been", "created", "to", "provide", "well", "written", "well", "thought", "and", "well", "explained", "solutions", "for", "selected", "questions", "if", "you", "like", "geeks", "for", "geeks", "and", "would", "like", "to", "contribute", "here", "is", "your", "chance", "You", "can", "write", "article", "and", "mail", "your", "article", "to", "contribute", "at", "geeksforgeeks", "org", "see", "your", "article", "appearing", "on", "the", "geeks", "for", "geeks", "main", "page", "and", "help", "thousands", "of", "other", "geeks"};
	
        string s;
	int k=5;		// assume k != 0. This corner case not handled
	heap h[k];
	int heap_size=0;
	for ( int i=0; i<len; i++ )
		root[ch[i][0]-'a'] = insert ( root[ch[i][0]-'a'], h, &heap_size, ch[i], 0, s, k );
	for ( int i=0; i<26; i++ )
	{	if ( root[i] != NULL )
		{	print_trie(root[i],s);
			printf("\n");
		}
	}
	printf("Top k elements\n");
	for ( int i=0; i<k && i < heap_size; i++ )
		printf("%s %d\n", h[i].word, h[i].occur);
		
	return 0;	
}

void print_trie ( trie *root, string s )
{	if ( root == NULL )
		return;
	s += root->data;
	if ( root->is_word != 0 )
		cout<<s<<" "<<root->is_word<<endl;
	//printf("{%c,%d} ", root->data, root->is_word);
	for ( int i=0; i<26; i++ )
		if ( root->child[i] != NULL )
			print_trie(root->child[i],s);
}

/*
Check before delete that not an empty string!!
This function- is_word ->occurence of the word ( 0  means no occurence of this word )
*/ 
struct trie* insert ( struct trie* root, struct heap *h, int *heap_size, char *word, int pos, string s, int k )
{       s += word[pos];
	if ( root == NULL && word[pos] != '\0' )
        {       trie *tmp=new trie(word[pos]);
                //printf("%c\n", tmp->data);
                if ( word[pos+1] == '\0' )
                {       tmp->is_word=1;
			s += '\0';
			insert_word(tmp,h,heap_size,k,s);
                        return tmp;
                }
                else
                {       tmp->child[word[pos+1]-'a']= insert(tmp->child[word[pos+1]-'a'], h, heap_size, word, pos+1,s,k);
                        return tmp;
                }
        }
        if ( word[pos] == '\0' )                // not encountered actually due to earlier check at pos-1
                return NULL;
        if ( word[pos+1] == '\0' )
        {       root->is_word++;
		s += '\0';
		insert_word(root,h,heap_size,k,s);
                return root;
        }
        else
        {      	root->child[word[pos+1]-'a']= insert(root->child[word[pos+1]-'a'], h, heap_size, word, pos+1,s,k);
                return root;
        }
}

void insert_heap ( heap *a, int s )
{       int p=s-1,q;
        q=p/2;
        while ( p > 0 &&  a[q].occur > a[p].occur )
        {       heap t=a[p];
                a[p]=a[q];
                a[q]=t;
                a[p].node->idx=p;
                a[q].node->idx=q;
                p=q;
                q=p/2;
        }
}
void insert_heap_down ( heap *h, int s, int idx )
{	int p=idx;
        int l=p*2+1;
        int r=l+1;
        while ( l < s )
        {       int min;
                if ( r < s )
                        min = h[l].occur <= h[r].occur ? l : r;
                else
                        min=l;
                if ( h[min].occur < h[p].occur )
                {       heap t=h[min];
                        h[min]=h[p];
                        h[p]=t;
			h[p].node->idx=p;
			h[min].node->idx=min;
                        p=min;
                        l=2*p+1;
                        r=l+1;
                }
                else
                        break;
        }
}

void insert_word ( trie *root, heap *h, int *size, int k, string s )
{	//cout<<s<<" count: "<<root->is_word<<" index: "<<root->idx<<endl;
	if ( root->idx != -1 )
	{	h[root->idx].occur=root->is_word;
		insert_heap_down(h,*size,root->idx);
		return;
	}
	if ( *size == k )
	{	if ( root->is_word > h[0].occur )
		{	h[0].node->idx=-1;
			h[0].occur=root->is_word;
			h[0].node=root;
			int i;
			for ( i=0; s[i] != '\0'; i++ )
				h[0].word[i]=s[i];
			h[0].word[i]='\0';
			h[0].node->idx=0;
			insert_heap_down(h,*size,0);
		}
	}
	else
	{	h[*size].node=root;
		h[*size].occur=root->is_word;
        	int i;
		for ( i=0; s[i] != '\0'; i++ )
                	h[*size].word[i]=s[i];
		h[*size].word[i]='\0';
		*size = (*size) + 1;
		insert_heap(h,*size);
	}
	/*
	printf("heap\n");
	for ( int i=0; i< *size; i++ )
		printf("%s %d\n", h[i].word, h[i].occur);
	printf("\n");
	*/
}
