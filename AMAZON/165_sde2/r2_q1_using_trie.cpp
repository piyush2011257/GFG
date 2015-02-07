#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

struct trie
{	char data;
	string word;
	struct trie* child[26];	
	trie( char d=0 )
	{	data=d;
		word.clear();
		for ( int i=0; i<26; i++ )
			child[i]=NULL;
	}
};


struct trie* insert ( struct trie* root, char *word, int pos, char *words );
void print_trie ( trie *root );

const int len=11;

int main()
{	struct trie *root[26]={NULL};
	// All small letter words assumed
	char ch[len][10]={ {"bota"},
			 {"boat"},
			 {"bat"},
			 {"tab"},
			 {"raman"},
			 {"cat"},
			 {"tac"},
			 {"manra"},
			 {"act"},
			 {"mar"},
			 {"ram"},
		       };
	for ( int i=0; i<len; i++ )
	{	char tmp[10];
		strcpy(tmp,ch[i]);
		sort(tmp,tmp+strlen(tmp));
		//cout<<"tmp: "<<tmp<<" "<<tmp[0]-'a'<<endl;
		root[tmp[0]-'a'] = insert ( root[tmp[0]-'a'], tmp, 0, ch[i] );
	}
	for ( int i=0; i<26; i++ )
	{	if ( root[i] != NULL )
		{	printf("Strings starting with: %c\n",i+'a');
			print_trie(root[i]);
			printf("\n");
		}
	}
	return 0;
	
}

void print_trie ( trie *root )
{	if ( root->word.length() > 0 )
		cout<<"{"<<root->word<<"}\n";
	for ( int i=0; i<26; i++ )
		if ( root->child[i] != NULL )
			print_trie(root->child[i]);
}

struct trie* insert ( struct trie* root, char *word, int pos, char *words )
{       if ( root == NULL && word[pos] != '\0' )
        {       trie *tmp=new trie(word[pos]);
                if ( word[pos+1] == '\0' )
                {       if ( tmp->word.length() == 0 )
				tmp->word = words;
			else
			{	tmp->word += " ";
				tmp->word += words;
			}
                        return tmp;
                }
                else
                {       tmp->child[word[pos+1]-'a']= insert(tmp->child[word[pos+1]-'a'], word, pos+1, words);
                        return tmp;
                }
        }
        if ( word[pos] == '\0' )                // not encountered actually due to earlier check at pos-1
                return NULL;
        if ( word[pos+1] == '\0' )
        {       if ( root->word.length() == 0 )
			root->word = words;
		else
		{	root->word += " ";
			root->word +=words;
		}
                return root;
        }
        else
        {       root->child[word[pos+1]-'a']= insert(root->child[word[pos+1]-'a'], word, pos+1, words);
                return root;
        }
}

/*
e.g.
bat	-> abt
tab	-> abt
raman	-> aanmr
amran	-> aamnr
rom	-> mor
mor	-> mor



a	a	n	m	r (raman, amran)
	b	t ( bat, tab )

m	o	r ( rom.mor)
*/
