/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-157-campus/
2) You are given ‘n’ appointments. Each appointment contains startime and endtime. You have to return all conflicting appointments.

Sort on the basis of start time. All intervals having start time less than a given interval's ending collide with the given interval
O(NlonN) to find colliding space. O(N^2) to print intervals despite only N colliding intervals at max
*/

#include<cstdio>
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
void overlap ( interval *inter, int n );
int find_collision ( interval *a, int ele, int s, int e, int start, int end );

int main()
{	int n;
        scanf("%d",&n);
	interval inter[n];
	for ( int i=0; i<n; i++ )
		scanf("%d %d",&inter[i].start, &inter[i].end);
	sort(inter,inter+n,func);
        printf("intervals\n");
	for ( int i=0; i<n; i++ )
		printf("%d %d\n", inter[i].start, inter[i].end);
	printf("\n");
	overlap(inter,n);
	return 0;
}

bool func ( interval i, interval j )
{	if ( i.start < j.start )
		return 1;
	if ( i.start == j.start && i.end <= j.end )
		return 1;
	return 0;
}

void overlap ( interval *inter, int n )
{	bool conflict[n];
	for ( int i=0; i<n; i++ )
		conflict[i]=0;
	for ( int i=0; i<n; i++ )
	{	int idx=find_collision(inter,inter[i].end,i+1,n-1,i+1,n-1);
		for ( int l=i; l <= idx; l++ )
			conflict[l]=1;
	}
	for ( int i=0; i<n; i++ )
		if ( conflict[i] == 1 )
			printf("%d %d\n", inter[i].start, inter[i].end);
	printf("\n");
}

int find_collision ( interval *a, int ele, int s, int e, int start, int end )
{	if ( s > e )
		return -1;
	int m=(s+e)/2;
	if ( a[m].start < ele )
	{	if ( m < end && a[m+1].start < ele )
			return find_collision(a,ele,m+1,e,start,end);
		else
			return m;
	}
	else
		return find_collision(a,ele,s,m-1,start,end);
}
