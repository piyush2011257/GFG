/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-154-sde2/
find Kth minimum element in a row-wise and column-wise sorted 2-d array.

http://www.geeksforgeeks.org/kth-smallest-element-in-a-row-wise-and-column-wise-sorted-2d-array-set-1/
Given an n x n matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the given 2D array.

LOGIC-
For a N * N Matrix, Consider this probklem to be like merging N sorted lists using Heaps. And finding out the kth smallest element
Each column is a N-Sized List. Total N sorted lists to be merged using Heap logic
*/

#include<cstdio>
using namespace std;

struct node
{	int data;
	int i,j;
}hp[100];

void insert ( node *a, int s );
void del ( node *a, int s );
void print( node *a, int s );

int main()
{	int a[10][10], s=0;
	int r,c;
	scanf("%d %d",&r,&c);
	for ( int i=0; i<r; i++ )
		for ( int j=0; j<c; j++ )
			scanf("%d",&a[i][j]);
	int k;
	scanf("%d",&k);
	for ( int i=0; i<c; i++ )
	{	hp[s].data=a[0][i];
		hp[s].i=0;
		hp[s].j=i;
		s++;
		insert(hp,s);
	}
	//print(hp,s);
	int ct=1;
	while ( ct <= r*c)
	{	node t= hp[0];
		hp[0]=hp[s-1];
		printf("del: %d %d %d\n", t.data, t.i, t.j);
		s--;
		del(hp,s);
		if ( (t.i)+1 < r )
		{	hp[s].data=a[(t.i)+1][t.j];
			hp[s].i=(t.i)+1;
			hp[s].j=t.j;
			s++;
			insert(hp,s);
		}
		ct++;
		//print(hp,s);
	}
	return 0;
}

void insert ( node *a, int s )
{	int p=s-1,q;
	q=p/2;
	while (p > 0 &&  a[q].data > a[p].data )
	{	node t=a[p];
		a[p]=a[q];
		a[q]=t;
		p=q;
		q=p/2;
	}
}

void del ( node *a, int s )
{	int p=0;
	int l=p*2+1;
	int r=l+1;
	while ( l < s ) 
	{	int min;
		if ( r < s )
			min = a[l].data < a[r].data ? l : r;
		else
			min=l;
		if ( a[min].data < a[p].data )
                {       node t=a[min];
                        a[min]=a[p];
                        a[p]=t;
                        p=min;
                        l=2*p+1;
                        r=l+1;
                }
		else
			break;
	}
}

void print( node *a, int s )
{	for ( int i=0; i<s; i++ )
		printf("%d %d %d\n", a[i].data, a[i].i, a[i].j);
	printf("\n");
}



