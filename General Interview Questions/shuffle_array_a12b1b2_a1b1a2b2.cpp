/*
http://prpds.blogspot.in/2011/08/a1a2a3anb1b2b3bn-to-a1b1a2b2a3b3anbn.html
Convert a1a2a3....anb1b2b3.....bn to a1b1a2b2a3b3.....anbn
in O(n) time and O(1) space
*/
#include<cstdio>
using namespace std;

void shuffle ( int *a, int n);

int main()
{	int d;
	scanf("%d",&d);
	int a[100];
	while ( d%2 != 0 )
	{	printf("Error size\n");
		scanf("%d",&d);
	}
	for ( int i=0; i<d; i++ )
		scanf("%d",a+i);
	shuffle(a,d);
	for ( int i=0; i<d; i++ )
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}

void shuffle ( int *a, int n)
{	int i=1, t1, t2, start_idx, new_idx;
	bool visited[n];
	for ( int i=0; i<n; i++ )
		visited[i]=0;
	visited[0]=1;
	visited[n-1]=1;
	while ( i < n )
	{	start_idx=i;
		t1=a[start_idx];
		do
		{	printf("%d %d\n", i, start_idx);
			if ( i < n/2 )
			{	printf("less\n");
				new_idx=2*i;
				t2=a[new_idx];
				a[new_idx]=t1;
				t1=t2;
			}
			else
			{       new_idx=2*(i-n/2)+1;
                                t2=a[new_idx];
                                a[new_idx]=t1;
                                t1=t2;
                        }
                        visited[new_idx]=1;
			i=new_idx;
			printf("yo t1: %d\n", t1);
		} while ( i != start_idx );
		while ( visited[i] == 1 && i < n )
			i++;
	}	
}
