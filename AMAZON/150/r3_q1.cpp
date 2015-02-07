/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-150-sde1-1-year-experienced/
word frequency of a stream of words (no code required, explain trie method)
*/

#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

struct trie
{	char data;
	int is_word;
	struct trie* child[26];			// Overhead of memory of storing 26 size pointer array for each node
	trie( char d=0, int is_word=0 )
	{	data=d;
		is_word=0;			// counts occurence of the word
		for ( int i=0; i<26; i++ )
			child[i]=NULL;
	}
};


struct trie* insert ( struct trie* root, char *word, int pos );
void print_trie ( trie *root, string s );

const int len=11;

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
			 {"boats"},
			 {"bats"},
			 {"raman"},
			 {"bats"},
		       };
	for ( int i=0; i<len; i++ )
		root[ch[i][0]-'a'] = insert ( root[ch[i][0]-'a'], ch[i], 0 );
	string s;
	for ( int i=0; i<26; i++ )
	{	if ( root[i] != NULL )
		{	print_trie(root[i],s);
			printf("\n");
		}
	}
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
        {       root->is_word++;
                return root;
        }
        else
        {       root->child[word[pos+1]-'a']= insert(root->child[word[pos+1]-'a'], word, pos+1);
                return root;
        }
}
