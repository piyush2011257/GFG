/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-157-campus/
2) You are given ‘n’ appointments. Each appointment contains startime and endtime. You have to return all conflicting appointments.

E.g. i/p
index
0	[1,2]
1	[1,5]
2	[2,3]
3	[2,5]
4	[3,4]

Any order, sorted / unsorted

New structure

Sorted in the order of time ( end prefered over starr -> [1,2] and [2,3] NOT an overlap !!

time				1	1	2	2	2	3	3	4	5	5
start/end			s	s	e	s	s	e	s	e	e	e
index in input interval		0	1	0	2	3	2	4	4	1	3

Now go sequentially from start and keep a list storing entry of all started intervals and remove all over intervals an keeping count of overlapping intervals. Using index parameter we can determine overlapping intervals. An interval overlaps if there is any started and NOT yet ended interval in the list and a new interval starts

LIST- Represents set of ongoing interval NOT ended yet
O(NlogN) - sorting
O(N)- print all conflicting intervals

http://stackoverflow.com/questions/18365107/maximum-no-of-overlaps-of-all-time-intervals
http://programmers.stackexchange.com/questions/149197/algorithm-for-finding-overlapping-times
*/

#include<cstdio>
#include<algorithm>
#include<list>
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

struct nod
{	bool start;			// 1 start 0 end
	int time;			// time stamp
	int index;			// index in i/p interval
};

bool func ( nod i, nod j );
void overlap ( nod *node, interval *inter, int n, int N );

int main()
{	int n;
        scanf("%d",&n);
	interval inter[n];
	nod node[n*2];
	for ( int i=0, j=0; i<n; i++ )
	{	scanf("%d %d",&inter[i].start, &inter[i].end);
		node[j].time=inter[i].start;
		node[j].start=1;
		node[j].index=i;
		j++;
                node[j].time=inter[i].end;
                node[j].start=0;
                node[j].index=i;
		j++;
	}
	sort(node, node+(2*n), func);
        printf("node\n");
	for ( int i=0; i<2*n; i++ )
		printf("%d %d %d\n", node[i].time, node[i].start, node[i].index);
	printf("\n");
	overlap(node,inter,2*n,n);
	return 0;
}

bool func ( nod i, nod j )
{	if ( i.time < j.time )
		return 1;
	if ( i.time == j.time && i.start == 0 )
		return 1;
	return 0;
}

void overlap ( nod *node, interval *inter, int n, int N )
{	bool conflict[N];
	for ( int i=0; i<N; i++ )
		conflict[i]=0;
	list<int> l;
	if ( node[0].start == 0 )
	{	printf("first element is end!!\n");
		exit(0);
	}
	l.push_back(node[0].index);
	for ( int i=1; i<n; i++ )
	{	if ( node[i].start == 0 )
		{	if ( l.size() == 0 )
			{	printf("end before start\n");
				exit(0);
			}
		 	else
				l.remove(node[i].index);
		}
		else
		{	if ( l.size() != 0 )
			{	if ( conflict[l.back()] == 0 )
                                	conflict[l.back()]=1;
				l.push_back(node[i].index);
				conflict[node[i].index]=1;
			}
			else
				l.push_back(node[i].index);
		}
	}
	for ( int i=0; i<N; i++ )
		if ( conflict[i] == 1 )
			printf("%d %d\n", inter[i].start, inter[i].end);
}
