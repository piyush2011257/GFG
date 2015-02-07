/*
Union by height
S[i] -> -ve means root and its depth
S[i] -> +ve means points to the root node

Using path compression
*/

#include<cstdio>
using namespace std;

int find ( int *a, int x );
void print( int *a, int n );

int main()
{	int a[100];
	int n;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ )
		a[i]=-1;
	int ch;
	printf("1- Union\n2- Find\n");
	while ( scanf("%d",&ch) != EOF )
	{	if ( ch == 1 )
		{	int s1, s2;
			scanf("%d %d",&s1,&s2);
			int f1=find(a,s1);
			int f2=find(a,s2);
			if ( f1 == f2 )
				printf("Already in same set\n");
			else
			{	if ( a[f1] > a[f2] )
					a[f1]=f2;
				else if ( a[f2] > a[f1] )
                                        a[f2]=f1;
                                else
				{	a[f1]--;
					a[f2]=f1;
				}       
			}
		}
		else if ( ch == 2 )
		{	int s;
			scanf("%d",&s);
			printf("%d\n", find(a,s));
		}
		print(a,n);	
	}
	return 0;
}

// Path Compression
int find ( int *a, int x )
{	if ( a[x] < 0  )
		return x;
	else
	{	a[x]=find(a,a[x]);
		return a[x];
	}
}

void print( int *a, int n )
{	for ( int i=0; i<n; i++ )
		printf("%d ", a[i]);
	printf("\n");
}
