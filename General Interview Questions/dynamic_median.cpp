#include<cstdio>
using namespace std;

void insert_max ( int *a, int s );
void del_max ( int *a, int s );
void insert_min ( int *a, int s );
void del_min ( int *a, int s );
void print( int *a, int s );

int main()
{	int max_heap[100], min_heap[100], s1=0, s2=0;
	int d;
	while ( scanf("%d",&d) != EOF )
	{	if ( s2 == 0 )
			min_heap[s2++]=d;
		else
		{	if ( d >= min_heap[0] )
			{	min_heap[s2++]=d;
				insert_min(min_heap,s2);
			}
			else
			{	if ( s1 == 0 )
					max_heap[s1++]=d;
				else
				{	max_heap[s1++]=d;
					insert_max(max_heap,s1);
				}
			}
			if ( s2 > s1 + 1 )
			{	int d=min_heap[0];
				min_heap[0]=min_heap[s2-1];
				s2--;
				del_min(min_heap,s2);
				max_heap[s1++]=d;
				insert_max(max_heap,s1);
			}
			else if ( s1 > s2 )
			{       int d=max_heap[0];
                                max_heap[0]=max_heap[s1-1];
                                s1--;
                                del_max(max_heap,s1);
                                min_heap[s2++]=d;
                                insert_min(min_heap,s2);
                        }
		}
		/*
		printf("max heap: ");
		print(max_heap,s1);
		printf("\nmin_heap: ");
		print(min_heap,s2);
		*/
		if ( s1 == s2 )
			printf("%d %d\n", max_heap[0], min_heap[0]);
		else
			printf("%d\n", min_heap[0]);
	}
	return 0;
}

void insert_max ( int *a, int s )
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

void insert_min ( int *a, int s )
{       int p=s-1,q;
        q=p/2;
        while (p > 0 &&  a[q] > a[p] )
        {       int t=a[p];
                a[p]=a[q];
                a[q]=t;
                p=q;
                q=p/2;
        }
}

void del_max ( int *a, int s )
{	int p=0;
	int l=p*2+1;
	int r=l+1;
	while ( l < s ) 
	{	int max;
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

void del_min ( int *a, int s )
{       int p=0;
        int l=p*2+1;
        int r=l+1;
        while ( l < s )
        {       int min;
                if ( r < s )
                        min = a[l] < a[r] ? l : r;
                else
                        min=l;
                if ( a[min] < a[p] )
                {       int t=a[min];
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

void print( int *a, int s )
{	if ( s == 0 )
		return;
	for ( int i=0; i<s; i++ )
		printf("%d ", a[i]);
	printf("\n");
}
