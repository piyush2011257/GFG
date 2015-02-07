#include<cstdio>
using namespace std;

void insert ( int *a, int s );
void del ( int *a, int s );
void print( int *a, int s );

int main()
{	int a[100], s=0;
	int d;
	while ( scanf("%d",&d) != EOF )
	{	a[s++]=d;
		insert(a,s);
		print(a,s);
	}
	while ( s > 0 )
	{	int d=a[0];
		a[0]=a[s-1];
		s--;
		//print(a,s);
		del(a,s);
		printf("del: %d\n",d);
		print(a,s);
	}
	return 0;
}

void insert ( int *a, int s )
{	int p=s-1,q;
	q=p/2;
	while (p > 0 &&  a[q] < a[p] )
	{	int t=a[p];
		a[p]=a[q];
		a[q]=t;
		p=q;
		q=p/2;
	}
}

void del ( int *a, int s )
{	//printf("s: %d\n",s);
	//a[s-1]=a[0];
	int p=0;
	int l=p*2+1;
	int r=l+1;
	//printf("p: %d l:%d r: %d\n",p,l,r);
        //printf("%d %d %d\n",a[p],a[l],a[r]);
	while ( l < s ) 
	{	//printf("p: %d l:%d r: %d\n",p,l,r);
		int max;
		if ( r < s )
			max = a[l] > a[r] ? l : r;
		else
			max=l;
		if ( a[max] > a[p] )
                {       int t=a[max];
                        a[max]=a[p];
                        a[p]=t;
                        p=max;
                        l=2*p+1;
                        r=l+1;
                }
		else
			break;
	}
}

void print( int *a, int s )
{	for ( int i=0; i<s; i++ )
		printf("%d ", a[i]);
	printf("\n");
}
