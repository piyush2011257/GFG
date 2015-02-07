/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-157-campus/

Rotating an array. (All approaches)
http://www.geeksforgeeks.org/program-for-array-rotation-continued-reversal-algorithm/
http://www.geeksforgeeks.org/array-rotation/
*/
#include<cstdio>
using namespace std;

int main()
{	int d;
	scanf("%d",&d);
	int a[d];
	for ( int i=0; i<d; i++ )
		scanf("%d",a+i);
	int start_idx=0, new_idx,t1=a[0],i=0,k;
	scanf("%d",&k);
	do
	{	int new_idx= (i+k)%(d);
		//printf("i: %d new_idx: %d\n",i,new_idx);
		int t2=a[new_idx];
		a[new_idx]=t1;
		t1=t2;
		i=new_idx;
	        /*for ( int i=0; i<d; i++ )
        	        printf("%d ", a[i]);
        	printf("\n");*/

	} while ( i != start_idx);
	for ( int i=0; i<d; i++ )
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
