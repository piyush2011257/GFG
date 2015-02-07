/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-155-campus/
You are given an UNsorted array, find majority element in it. If there is no such element output -1.

http://www.geeksforgeeks.org/majority-element/
A majority element in an array A[] of size n is an element that appears more than n/2 times (and hence there is at most one such element).
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
	return 0;
}
