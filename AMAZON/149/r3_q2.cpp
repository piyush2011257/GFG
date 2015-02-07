/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-149-campus-internship/
Given a log file of page visits of a website by different users for a day.

Entry in the log file is like this:
User 1 visited Page 4
User 3 visited Page 2
User 7 visited Page 9
.
.
.

Design an efficient data structure which supports queries like the following:
Which page was visited by exactly 2 users in day?
Which page was visited by only one user exactly 2 times in a day?
Which page was visited by ‘User 3? more than 5 times in a day?

Design Overview
struct page
{       map <int , node * > m;
        node *head, *tail;
        page()
        {       head=tail=NULL; }
};

This is a structure which contains detailsof users on each page
Each user detail is represented by a node in a LL
LL + Map concept
m[user] -> node

struct node
{	node *next;
	int user, int count;
}

so structure
For page P->
page[P] :  {user1,visits_by_user1} -> {user3,visits_by_user1} -> {user5,visits_by_user1} -> {user2,visits_by_user1}
	      |												|
	     head										      tail
	     m[user1]			m[user3]			m[user5]]		   m[user2]

Similarly for each page x page[x] contains the details
Details of page P by user X -> O(1)

Another DLL+Map for visits_on_page and page
*/

#include<cstdio>
#include<map>
using namespace std;

struct node
{	node *next;
	int user, count;
	node ( int u )
	{	user=u;
		count=1;
		next=NULL;
	}
};

struct page
{	map <int , node * > m;
	int users_count;
	node *head, *tail;
	page()
	{	users_count=0;
		head=tail=NULL;
	}
};

const int pages=10;			// assumed pages is known

void insert ( page * pg, int user, int page );
void print ( page *p );

int main()
{	// Max pages = P
	int n,p,u;
	scanf("%d",&n);
	page pg[pages];
	printf("Enter details in the form- {user,page}\n");
	for ( int i=0; i<n; i++ )
	{	scanf("%d %d",&u,&p);
		insert(pg,u,p);
	}
	print(pg);
	return 0;
}

void insert ( page * pg, int user, int page )
{	if ( pg[page].m.count(user) == 0 )
	{	if ( pg[page].head == NULL )
			pg[page].head = pg[page].tail= new node(user);
		else
		{	pg[page].tail->next=new node(user);
			pg[page].tail=pg[page].tail->next;
		}
		pg[page].m[user]=pg[page].tail;
		pg[page].users_count++;
	}
	else
		pg[page].m[user]->count++;
}

void print ( page *p )
{	for ( int i=0; i<pages; i++ )
	{	if ( p[i].users_count == 0 )
			continue;
		printf("page: %d contains %d users visits->\n",i,p[i].users_count);
		for ( map<int, node *>::iterator iter=p[i].m.begin(); iter != p[i].m.end(); iter++ )
			printf("user: %d visited: %d\n", iter->first, iter->second->count);
		printf("\n");
	}
}
