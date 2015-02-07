#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;

struct tst
{	char data;
	bool is_word;
	struct tst* left, *eq, *right;	
	tst( char d=0, bool is_word=0 )
	{	data=d;
		is_word=0;
		left=right=eq=NULL;
	}
};


struct tst* insert ( struct tst* root, char *word, int pos );
void print_tst ( tst *root );
bool find_next_word ( tst *root, char *word, int pos, string s );
void go_left ( tst *root, string s );

const int len=8;

int main()
{	struct tst *root=NULL;
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
		root= insert ( root, ch[i], 0 );
	print_tst(root);
	printf("\n");
	char ch2[10];
	string s;
	while ( scanf("%s",ch2) != EOF )
		find_next_word(root, ch2, 0, s);
	return 0;
	
}

void print_tst ( tst *root )
{	if ( root == NULL )
		return;
	printf("{%c,%d} ", root->data, root->is_word);
	print_tst(root->left);
        print_tst(root->eq);
        print_tst(root->right);	
}

// check before delete that not an empty string!!
struct tst* insert ( struct tst* root, char *word, int pos )
{       if ( root == NULL && word[pos] != '\0' )
        {       tst *tmp=new tst(word[pos]);
                //printf("%c\n", tmp->data);
                if ( word[pos+1] == '\0' )
                {       tmp->is_word=1;
                        return tmp;
                }
                else
                {       tmp->eq= insert(tmp->eq, word, pos+1);
                        return tmp;
                }
        }
        if ( word[pos] == '\0' )                // not encountered actually due to earlier check at pos-1
                return NULL;
        if ( root->data == word[pos] && word[pos+1] == '\0' )
        {       root->is_word=1;
                return root;
        }
	if ( word[pos] < root->data )
		root->left= insert(root->left, word, pos);
	else if ( word[pos] > root->data )
		root->right= insert(root->right, word, pos );
	else
		root->eq= insert(root->eq, word,pos+1);
	return root;
}

bool find_next_word ( tst *root, char *word, int pos, string s )
{	if ( root  == NULL )
		return 1;
	bool val;
	int loc;
	if ( root->data == word[pos] )
	{	//s += root->data;
		if ( word[pos+1] == '\0' )
		{	if ( root->eq != NULL )
			{	go_left(root->eq,s+root->data);
				return 0;
			}
			else if ( root->right != NULL )
			{	go_left(root->right,s+root->data);
				return 0;
			}
			return 1;
		}
		val = find_next_word(root->eq,word,pos+1,s+root->data);
		loc=0;
	}
	else if ( root->data < word[pos] )
	{	val=find_next_word(root->right,word,pos,s);
		loc=1;
	}
	else 
	{	val=find_next_word(root->left,word,pos,s);
		loc=-1;
	}
	if ( val == 1 )
	{	if ( loc == 1 )
			return 1;
		if ( loc == -1 )
		{	if ( root->is_word != 1 )
				go_left(root->eq,s+root->data);		// to avoid it gong back to root->left where it came from
			else
				go_left(root,s);
		}
		else
		{	if ( root->right != NULL )
				go_left(root->right,s);
			else
				return 1;
		}
	}
	return 0;
}

void go_left ( tst *root, string s )
{	if ( root == NULL )
		return;
	if ( root->left == NULL )
	{	s+=root->data;
		if ( root->is_word == 1 )
		{	cout<<s<<endl;
			return;
		}
		go_left(root->eq,s);
	}
	else
		go_left(root->left,s);
}
