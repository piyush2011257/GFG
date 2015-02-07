/*
https://www.youtube.com/watch?v=TtkN2xRAgv4
https://www.site.uottawa.ca/~lucia/courses/2131-02/lect19.ps
https://www.site.uottawa.ca/~lucia/courses/2131-02/lect18.pdf
http://www.cs.sfu.ca/CourseCentral/354/zaiane/material/notes/Chapter11/node20.html
*/
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

const int bucket_size=2;

struct list
{	int key, data;
};

struct node
{	list *next;
	int size;
	int local_depth;			// local_depth
	node(int local=1 )
	{	next= new list[bucket_size];
		size=0;
		local_depth=1;
	}
};

struct trie
{	trie *child[2];
	char ch;
	node *bucket;
	trie()
	{	bucket=	NULL;
		child[0]=child[1]=NULL;
		ch=0;
	}
	trie ( char c, trie * c0=NULL, trie *c1=NULL )
	{	bucket=NULL;
		ch=c;
		child[0]=c0;
		child[1]=c1;
	}
};

void insert ( trie **root, int &global_depth, int key, int val );
string hash ( int key, int depth );
void resize( trie **root, int &global_depth );
void add_new_location ( trie *root, int global_depth, string s, int local_depth );
void copy ( trie *root1, trie *root2 );
void print ( trie *root, string s );
void del ( trie **root, int key, int &global_depth );
bool try_collapse ( trie *root1, trie *root2 );
void delete_collapse ( trie **root, trie *tmp, int &global_depth, string s );

int main()
{	trie *root= new trie();
	root->child[0]=new trie('0');
	root->child[0]->bucket=new node();
        root->child[1]=new trie('1');
	root->child[1]->bucket=new node();
	int key, val, global_depth=1, ch;
	string s;
	while ( scanf("%d",&ch) != EOF )
	{	if ( ch == 1 )
		{	scanf("%d %d",&key, &val);
			insert(&root, global_depth, key, val );
		}
		else
                {       scanf("%d",&key);
                        del(&root, key, global_depth );
		}
		printf("global depth: %d %p %p %p\n", global_depth, root, root->child[0], root->child[1]);
		print(root,s);
		printf("\n");
	}
	return 0;
}

void insert ( trie **root, int &global_depth, int key, int val )
{	string s=hash(key,global_depth);
	trie *tmp=*root;
	//cout<<"key: "<<key<<" string: "<<s<<endl;
	for ( int i=global_depth-1; i>=0; i-- )
		if ( s[i] == '0' )
			tmp=tmp->child[0];
		else
			tmp=tmp->child[1];
	node *bucket=tmp->bucket;
	if ( bucket->size == bucket_size )
	{	printf("Overflow in bucket\n");
		if ( bucket->local_depth == global_depth )
			resize(root,global_depth);
		bucket->local_depth++;
		list temp_vals[bucket_size];
		for ( int i=0; i<bucket_size; i++ )
		{	temp_vals[i].key=(bucket->next)[i].key;
			temp_vals[i].data=(bucket->next)[i].data;
		}
		add_new_location(*root,global_depth,s,bucket->local_depth);
		int old_size=bucket->size;
		bucket->size=0;
		for ( int i=0; i<old_size; i++ )
			insert(root,global_depth, temp_vals[i].key, temp_vals[i].data);
		insert(root,global_depth,key,val);
	}
	else
	{	int size=bucket->size;
		(bucket->next)[size].key=key;
		(bucket->next)[size].data=val;
		(bucket->size)++;
	}
	/*
	printf("depth: %d size: %d\n", global_depth, bucket->size);
	for ( int i=0; i<bucket->size; i++ )
		printf("%d %d\n", (bucket->next)[i].key, (bucket->next)[i].data);
	*/
}

string hash ( int key, int depth )
{	string s;
	int ctr=0;
	while ( key > 0 )
	{	if ( key % 2 == 0 )
			s+='0';
		else
			s+='1';
		key=key/2;
		ctr++;
	}
	while ( ctr++ < depth )
		s += '0';
	return s;
}

void resize( trie **root, int &global_depth )
{	trie *tmp=(*root);
	(*root)=new trie();
        (*root)->child[0]=new trie('0',tmp->child[0],tmp->child[1]);
	(*root)->child[1]=new trie('1');
	copy((*root)->child[1], (*root)->child[0] );
	global_depth++;
}

void add_new_location ( trie *root, int global_depth, string s, int local_depth )
{	//printf("add new location\n");
	trie *tmp=root;
	tmp=tmp->child[1];
	for ( int i=global_depth-2; i >= 0; i-- )
        {	//printf("%p %p %p %p\n", tmp, tmp->child[0], tmp->child[1], tmp->bucket);
		if ( s[i] == '0' )
                        tmp=tmp->child[0];
                else
                        tmp=tmp->child[1];
	}
	tmp->bucket=new node(local_depth);
	tmp->bucket->local_depth=local_depth;
}

void copy ( trie *root1, trie *root2 )
{	//printf("double size by copying\n");
	if ( root2->child[0] != NULL && root2->child[1] != NULL )
	{	root1->child[0]=new trie(root2->child[0]->ch);
		root1->child[1]=new trie(root2->child[1]->ch);
		root1->bucket=NULL;
		copy(root1->child[0], root2->child[0]);
		copy(root1->child[1], root2->child[1]);
	}
	else
		root1->bucket = root2->bucket;
}

void print ( trie *root, string s )
{	if ( root == NULL )
		return;
	s += root->ch;
	if ( root->bucket != NULL )
	{	cout<<"binary string: "<<s<<endl;
		//cout<<root->bucket->size<<endl;
		cout<<"Bucket size filled: "<<root->bucket->size<<" internal_depth: "<<root->bucket->local_depth<<endl;
		for ( int i=0; i<root->bucket->size; i++ )
			printf("{%d,%d}\n", (root->bucket->next)[i].key, (root->bucket->next)[i].data);
		
	}
	else
	{	printf("%p %p\n", root->child[0], root->child[1]);
		print(root->child[0],s);
		print(root->child[1],s);
	}
}

void del ( trie **root, int key, int &global_depth )
{	string s=hash(key,global_depth);
	trie *tmp=*root;
        //cout<<"key: "<<key<<" string: "<<s<<endl;
        for ( int i=global_depth-1; i>=0; i-- )
                if ( s[i] == '0' )
                        tmp=tmp->child[0];
                else
                        tmp=tmp->child[1];
        node *bucket=tmp->bucket;
	bool found=0;
        for ( int i=0; i<bucket->size; i++ )
        {       if ( (bucket->next)[i].key == key )
		{	found=1;
			for ( int j=i+1; j < bucket_size; j++ )
			{	(bucket->next)[j-1].key = (bucket->next)[j].key;
				(bucket->next)[j-1].data = (bucket->next)[j].data;
			}
			(bucket->size)--;
			break;
		}
        }
	if ( found == 0 )
	{	printf("No such key!!\n");
		return;
	}
	if ( global_depth > 1 )
		delete_collapse(root,tmp,global_depth,s);
}
	
void delete_collapse ( trie **root, trie *tmp, int &global_depth, string s )
{	node *bucket=tmp->bucket;
	string buddy_bucket_string;
	buddy_bucket_string=s;
	if ( buddy_bucket_string[global_depth-1] == '0' )
		buddy_bucket_string[global_depth-1]='1';
	else
		buddy_bucket_string[global_depth-1]='0';
	cout<<"string s: "<<s<<" bucket_string: "<<buddy_bucket_string<<endl;
	trie *tmp_2=*root;
        //cout<<"key: "<<key<<" string: "<<s<<endl;
        for ( int i=global_depth-1; i>=0; i-- )
                if ( buddy_bucket_string[i] == '0' )
                        tmp_2=tmp_2->child[0];
                else
                        tmp_2=tmp_2->child[1];
        node *bucket_buddy=tmp_2->bucket;
	if ( bucket == bucket_buddy )
	{	printf("Bucket == buddy_bucket\n");
		return;
	}
        if ( bucket->size + bucket_buddy->size > bucket_size )
        {       printf("Combined size overflow\n");
                return;
        }
	trie *t1, *t2;
	if ( s[global_depth-1] == '0' )
	{	t1=tmp;
		t2=tmp_2;
	}
	else
	{	t1=tmp_2;
		t2=tmp;
	}
	//cout<<(t1->bucket->next)[0].key<<" "<<(t2->bucket->next)[0].key<<endl;
	//cout<<"sizes: "<<t1->bucket->size<<" "<<t2->bucket->size<<endl;
	list temp_vals[t2->bucket->size];
        for ( int i=0, j=t1->bucket->size; i<t2->bucket->size; i++, j++, (t1->bucket->size)++ )
        {       (t1->bucket->next)[j].key=(t2->bucket->next)[i].key;
                (t1->bucket->next)[j].data=(t2->bucket->next)[i].data;
        }
	t2->bucket=t1->bucket;
	(t2->bucket->local_depth)--;			// local_deph decreases
	if ( global_depth <= 1 || try_collapse( (*root)->child[0], (*root)->child[1] ) == 0 )		// global_depth has to be >= 1 always
	{	printf("Cannot collapse\n");
		return;
	}
	printf("Collapsing\n");
	(*root)=(*root)->child[0];
	(*root)->ch=0;
	global_depth--;
	
	if ( t1 == tmp_2 )
		s=buddy_bucket_string;
	string tmp_str;
	printf("BEFORE COLLAPSE RECURSIVE\n");
	print(*root,tmp_str);
	printf("\n");
	delete_collapse(root, t1, global_depth, s);
        printf("AFTER COLLAPSE RECURSIVE\n");
        print(*root,tmp_str);            
        printf("\n");
	
}

bool try_collapse ( trie *root1, trie *root2 )
{	if ( root1->child[0] == NULL && root1->child[1] == NULL )
	{	if ( root1->bucket == root2->bucket )
			return 1;
		else
			return 0;
	}
	return ( try_collapse(root1->child[0],root2->child[0]) && try_collapse(root1->child[1],root2->child[1]) );
}
