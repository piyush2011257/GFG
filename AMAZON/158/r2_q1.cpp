#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct interval
{	int start, end;
	interval(int s, int e )
	{	start=s;
		end=e;
	}
	interval()
	{}
};

bool func ( interval i, interval j );
void find_next_continuous( interval *inter, int n, vector< vector<int> > &next );
int find_next ( interval *a, int ele, int s, int e );
int function ( interval *inter, vector< vector<int> > next, int *val, int i );
void find_max_consecutive ( interval *inter, int n, vector < vector<int> > next);

int main()
{	int n;
        scanf("%d",&n);
	interval inter[n];
	for ( int i=0; i<n; i++ )
		scanf("%d %d",&inter[i].start, &inter[i].end);
	sort(inter,inter+n,func);
        /*
	printf("intervals\n");
	for ( int i=0; i<n; i++ )
		printf("%d %d\n", inter[i].start, inter[i].end);
	printf("\n");
	*/
	vector< vector<int> > next(n);
	find_next_continuous(inter,n,next);
	printf("find next\n");
	for ( int i=0; i<n; i++ )
	{	printf("%d-> ",i);
		for ( int j=0; j<next[i].size(); j++ )
			printf("%d ", next[i][j]);
		printf("\n");
	}
	find_max_consecutive(inter,n,next);
	return 0;
}

bool func ( interval i, interval j )
{	if ( i.start < j.start )
		return 1;
	if ( i.start == j.start && i.end <= j.end )
		return 1;
	return 0;
}

void find_next_continuous( interval *inter, int n, vector< vector<int> > &next )
{	for ( int i=0; i<n-1; i++ )
	{	int tmp=find_next(inter,inter[i].end,i+1,n-1);
		if ( tmp != -1 )
		{	while ( tmp < n && inter[tmp].start == inter[i].end )
			{	next[i].push_back(tmp);
				tmp++;
			}
		}
	}
}

int find_next ( interval *a, int ele, int s, int e )
{	if ( s > e )
		return -1;
	int m=(s+e)/2;
	if ( a[m].start == ele )
	{	if ( m > 0 && a[m-1].start == ele )
			return find_next(a,ele,s,m-1);
		else 
			return m;
	}
	else if ( a[m].start < ele )
		return find_next(a,ele,m+1,e);
	else
		return find_next(a,ele,s,m-1);
}

void find_max_consecutive ( interval *inter, int n, vector < vector<int> > next)
{	int val[n];
	for ( int i=0; i<n; i++ )
		val[i]=-1;
	for ( int i=0; i<n; i++ )
		if ( val[i] == -1 )
			function(inter,next,val,i);
	printf("val\n");
	for ( int i=0; i<n; i++ )
		printf("%d ", val[i]);
	printf("\n");
		
}

int function ( interval *inter, vector< vector<int> > next, int *val, int i )
{	int mx=0;
	if ( next[i].size() != 0 )
	{	for ( int j=0; j<next[i].size(); j++ )
		{	int tmp;
			if ( val[next[i][j]] == -1 )
				tmp= function(inter,next,val,next[i][j]);
			else
				tmp= val[next[i][j]];
			mx= max(mx,tmp);
		}
		val[i]=mx+inter[i].end-inter[i].start;
	}
	else
		val[i]=inter[i].end-inter[i].start;
	return val[i];
}
