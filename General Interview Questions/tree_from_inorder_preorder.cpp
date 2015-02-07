#include<cstdio>
#include<cstring>
using namespace std;

struct node
{	node *left, *right;
	char data;
	node()
	{	left=right=NULL;
		data=-1;
	}
};

void in_trav ( node *root );
void pre_trav ( node *root );
node * func ( char *in, char *pre, int *pre_pos, int s, int e );

int find_pos(char *ch, char c, int s, int e)
{	for ( int i=s; i<=e; i++ )
		if ( ch[i] == c )
			return i;
}

int main()
{	char in[]="beadc";
	char pre[]="abecd";
	int pre_pos=0;
	node *root=func(in,pre,&pre_pos,0,strlen(in)-1);
	in_trav(root);
	printf("\n");
	pre_trav(root);
	printf("\n");
	return 0;
}

void in_trav ( node *root )
{	if ( root == NULL )
		return;
	in_trav(root->left);
	printf("%c ", root->data);
	in_trav(root->right);
}

void pre_trav ( node *root )
{       if ( root == NULL )
                return;
        printf("%c ", root->data);
        pre_trav(root->left);
        pre_trav(root->right);
}

node * func ( char *in, char *pre, int *pre_pos, int s, int e )
{	if ( s > e )
		return NULL;
	printf("s: %d e: %d\n",s,e);
	if ( s == e )
	{	node *tmp=new node();
		tmp->data=in[s];
		*pre_pos= (*pre_pos)+1;
		return tmp;
	}
	int idx=find_pos(in,pre[*pre_pos],s,e);
	printf("%d %c %c\n", idx,in[idx],pre[*pre_pos]);
	*pre_pos= (*pre_pos)+1;
	node *left=func(in,pre,pre_pos,s,idx-1);
	node *right=func(in,pre,pre_pos,idx+1,e);
	node *tmp= new node;
	tmp->data = in[idx];
	tmp->left=left;
	tmp->right=right;
	return tmp;
}
