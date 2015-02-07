/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-155-campus/
You are given a sorted array, find majority element in it. If there is no such element output -1. You have to do it in single o(logn) operation

http://www.geeksforgeeks.org/check-for-majority-element-in-a-sorted-array/
Write a C function to find if a given integer x appears more than n/2 times in a sorted array of n integers. 
*/

#include<cstdio>
using namespace std;

void find_majority ( int *a, int n  );
bool check_majority(int *a, int n, int ele );
int find_first_occ ( int *a, int ele, int s, int e );
int find_last_occ ( int *a, int ele, int n, int s, int e );

int main()
{	int d;
	scanf("%d",&d);
	int a[100];
	for ( int i=0; i<d; i++ )
		scanf("%d",a+i);
	find_majority(a,d);
	return 0;
}

void find_majority ( int *a, int n  )
{	int p=a[n/2];
	printf("%d\n", check_majority(a,n,p));
}

bool check_majority(int *a, int n, int ele )
{	int idx_s= find_first_occ(a,ele,0,n-1);
	int idx_e= find_last_occ(a,ele,n,0,n-1);
	printf("%d %d\n", idx_s, idx_e);
	if (idx_e-idx_s+1 > n/2 )
		return 1;
	else
		return 0;
}

int find_first_occ ( int *a, int ele, int s, int e )
{	if ( s > e )
		return -1;
	int m=(s+e)/2;
	if ( a[m] == ele )
	{	if ( m > 0 && a[m-1] == ele )
			return find_first_occ(a,ele,s,m-1);
		else
			return m;
	}
	else if ( a[m] < ele )
		return find_first_occ(a,ele,m+1,e);
	else
		return find_first_occ(a,ele,s,m-1);
}

int find_last_occ ( int *a, int ele, int n, int s, int e )
{       if ( s > e )
                return -1;
        int m=(s+e)/2;
        if ( a[m] == ele )
        {       if ( m+1 < n  && a[m+1] == ele )
                        return find_last_occ(a,ele,n,m+1,e);
                else
                        return m;
        }
        else if ( a[m] < ele )
                return find_last_occ(a,ele,n,m+1,e);
        else
                return find_last_occ(a,ele,s,n,m-1);
}
