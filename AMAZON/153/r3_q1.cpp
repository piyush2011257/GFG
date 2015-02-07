/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-153-sde1/
Q1. Count no. of inversion in a given array.

http://www.geeksforgeeks.org/counting-inversions/
Count Inversions in an array
*/
#include<cstdio>
#include<iostream>
using namespace std;

void merge_sort ( int *a, int s, int e );
void merge ( int *a, int s, int m, int e );
int count=0;

int main()
{	int a[100], n;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ )
		scanf("%d",a+i);
	merge_sort(a,0,n-1);
	printf("%d\n", count);
	for ( int i=0; i<n; i++ )
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}

void merge_sort ( int *a, int s, int e )
{	if ( s >= e )
		return;
	int m=(s+e)/2;
	merge_sort(a,s,m);
	merge_sort(a,m+1,e);
	merge(a,s,m,e);
}

void merge ( int *a, int s, int m, int e )
{	cout<<s<<" "<<m<<" "<<e<<endl;
	int l1=m-s+1, l2=e-m;
	int *t1= new int[l1];
	int *t2= new int[l2];
	for ( int i=s; i<=e; i++ )
		printf("%d ", a[i]);
	printf("\n");
	for ( int i=0; i<l1; i++ )
		t1[i]=a[s+i];
	for ( int i=0; i<l2; i++ )
		t2[i]=a[m+1+i];
	for ( int i=0; i<l1; i++ )
                printf("%d ", t1[i]);
        printf("\n");
        for ( int i=0; i<l2; i++ )
                printf("%d ", t2[i]);
        printf("\n");
        int c=s, k1=0, k2=0;
	while ( k1 < l1 && k2 < l2 )
	{	if ( t1[k1] <= t2[k2] )
		{	a[c++]=t1[k1];
			k1++;
		}
		else
		{       a[c++]=t2[k2];
                        k2++;
			printf("count: %d %d\n", t2[k2-1], t1[k1]);
			count += (l1-k1);
                }
	}
        while ( k1 < l1 )
		a[c++]=t1[k1++];
        while ( k2 < l2 )
                a[c++]=t2[k2++];
}
