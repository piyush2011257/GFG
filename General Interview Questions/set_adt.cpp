#include<cstdio>
using namespace std;

int find ( int *a, int x );
void print( int *a, int n );

int main()
{	int a[100];
	int n;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ )
		a[i]=i;
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
				a[f2]=f1;
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
{	if ( a[x] == x )
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
