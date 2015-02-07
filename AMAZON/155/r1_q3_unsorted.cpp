/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-155-campus/
You are given an UNsorted array, find majority element in it. If there is no such element output -1.

http://www.geeksforgeeks.org/majority-element/
A majority element in an array A[] of size n is an element that appears more than n/2 times (and hence there is at most one such element).
*/

#include<cstdio>
using namespace std;

void find_majority ( int *a, int n  );

int main()
{	int d;
	scanf("%d",&d);
	int a[100];
	for ( int i=0; i<d; i++ )
		scanf("%d",a+i);
	int pos=0, count=1;
	for ( int i=1; i<d; i++ )
	{	if ( a[i] == a[pos] )
			count++;
		else
		{	if ( count == 0 )
			{	count++;
				pos=i;
			}
			else
				count--;
		}
		//printf("%d %d %d\n",i,pos,count);
	}
	count=0;
	printf("%d\n",pos);
	for ( int i=0; i<d; i++ )
		if ( a[i] == a[pos] )
			count++;
	if ( count > d/2 )
		printf("1: %d\n", a[pos]);
	else
		printf("0\n");
	return 0;
}
