#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
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
bool find_next_word ( struct trie  *root, char *word, int pos, string s );
void go_left ( trie *root, string s );
void get_next_word ( trie *root[], char *word );
int find_next_non_null_child ( trie *root, int i=0 );


const int len=8;

int main()
{	struct trie *root[26]={NULL};
	// All small letter words assumed
	char ch[len][10]={ {"b"},
			 {"boats"},
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
	char ch2[100];
	while (scanf("%s",ch2) != EOF )
		get_next_word(root,ch2);
      	return 0;
	
}

void get_next_word ( trie *root[], char *word )
{	string s;
	int ctr=0;
	if ( root[word[0]-'a'] == NULL )
		ctr=1;				// No word starting with this character
	else if ( word[1] =='\0' )
		ctr=2;
	int val=0;
	if ( ctr == 0 )
		val=find_next_word(root[word[0]-'a']->child[word[1]-'a'], word, 1, s+word[0]);
	if ( val == 1 )
        {       int i=find_next_non_null_child(root[word[0]-'a'],word[1]-'a'+1);
		if ( i != 26 )
                	go_left(root[word[0]-'a']->child[i],s+word[0]);
		else
		{	i=word[0]-'a'+1;
			for ( ; i<26; i++ )
                        	if ( root[i] != NULL )
                                	break;
                	if ( i != 26 )
                        	go_left(root[i],s);
		}
        }
	else if ( ctr == 1 )
	{	int i=word[0]-'a'+1;
                for ( ; i<26; i++ )
                	if ( root[i] != NULL )
                        	break;
                if ( i != 26 )
                	go_left(root[i],s);
	}
	else if ( ctr == 2 )
        {	int i=find_next_non_null_child(root[word[0]-'a'],0);
          	if ( i != 26 )
		{	go_left(root[word[0]-'a']->child[i],s+word[0]);
			return;
		}
		else
		{	int i=word[0]-'a'+1;
                	for ( ; i<26; i++ )
                       		if ( root[i] != NULL )
                               		break;
			if ( i != 26 ) 
                       		go_left(root[i],s);
		}
	}
}

void print_trie ( trie *root )
{	printf("{%c,%d} ", root->data, root->is_word);
	for ( int i=0; i<26; i++ )
		if ( root->child[i] != NULL )
			print_trie(root->child[i]);
}

struct trie* insert ( struct trie* root, char *word, int pos )
{       if ( root == NULL && word[pos] != '\0' )
        {       trie *tmp=new trie(word[pos]);
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

bool find_next_word ( trie *root, char *word, int pos, string s )
{	if ( root == NULL )
		return 1;
	s += root->data;
	if ( word[pos+1] == '\0' )			// if this root node has a child or not
	{	int i=find_next_non_null_child (root);
		if ( i == 26 )
			return 1;
		go_left(root->child[i],s);		// find smallest string 
		return 0;
	}
	bool val= find_next_word(root->child[word[pos+1]-'a'], word, pos+1,s );
	if ( val == 1 )
	{	int i=find_next_non_null_child(root,word[pos+1]-'a'+1);
		if ( i == 26 )
               	        return 1;
               	go_left(root->child[i],s);
        }
	return 0;
}

void go_left ( trie *root, string s )			// find smallest string from root
{	s += root->data;
	int i=find_next_non_null_child(root);
	if ( i == 26 || root->is_word == 1  )
        	cout<<s<<endl;
        else    
               go_left(root->child[i],s);
        return;
}

int find_next_non_null_child ( trie *root, int i )
{	for ( ; i<26; i++ )
		if ( root->child[i] != NULL )
			return i;
	return 26;
}
