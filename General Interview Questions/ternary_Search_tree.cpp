/*
Narasimaha Karumanchi- String - Ternary Search Tree

http://www.geeksforgeeks.org/ternary-search-tree/
Representation of ternary search trees:
Unlike trie(standard) data structure where each node contains 26 pointers for its children, each node in a ternary search tree contains only 3 pointers:
1. The left pointer points to the node whose value is less than the value in the current node.
2. The equal pointer points to the node whose value is equal to the value in the current node.
3. The right pointer points to the node whose value is greater than the value in the current node.

*/

#include<cstdio>
#include<cstring>
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
struct tst * del ( struct tst* root, char *word, int pos );
void print_tst ( tst *root );

const int len=7;

int main()
{	struct tst *root=NULL;
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
		root= insert ( root, ch[i], 0 );
	print_tst(root);
	printf("\n");
	char ch2[10];
	while ( scanf("%s",ch2) != EOF )
	{	root = del ( root, ch2, 0 );
        	print_tst(root);
        	printf("\n");
        }
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

// check before delete that not an empty string!!
/*
Deleteion cases same as that in Trie. Refer to trie.cpp for the cases
*/
struct tst * del ( struct tst* root, char *word, int pos )
{	//printf("%p %c\n", root, word[pos]);
	if ( root == NULL && word[pos] != '\0' )
	{	printf("Not present\n");
		return root;
	}
	if ( root->data == word[pos] && word[pos+1] == '\0' )
	{	if ( root->is_word== 0 )
		{	printf("Not present as a word\n");
			return root;
		}
		if ( root->left == root->right && root->right == root->eq && root->eq == NULL )
			return NULL;
		else
		{	root->is_word=0;
			return root;
		}
	}
	tst *tmp_old, *tmp_new;
	if ( word[pos] < root->data )
	{	tmp_old=root->left;
		root->left=del(root->left,word,pos);
		tmp_new=root->left;
	}
	else if ( word[pos] > root->data )
        {       tmp_old=root->right;
		root->right=del(root->right,word,pos);
		tmp_new=root->left;
	}
	else
        {       tmp_old=root->eq;
		root->eq=del(root->eq,word,pos+1);
		tmp_new=root->left;
	}
	if ( tmp_old != NULL && tmp_new == NULL )
	{	if ( root->is_word == 1 )
			return root;
		if ( root->left == root->right && root->right == root->eq && root->eq == NULL )
			return NULL;
		return root;
	}
	else
		return root;
}
