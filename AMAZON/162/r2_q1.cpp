/*
www.geeksforgeeks.org/amazon-interview-experience-set-162/

In a tennis tournament of N players every player plays with every other player.
The following condition always hold-
If player P1 has won the match with P2 and player P2 has won from P3, then Player P1 has also defeated P3.
Find winner of tournament in O(N) time and O(1) space. Find rank of players in O(NlogN) time.

Since each player plays with another player we have record for each player. Let us have N player and the result of the match denoted by a matrix mat[N][N]
 mat[i][j]=	1	if i defeated j
	= 	0 	if i was defeated by j


Asuume solution to be ( in the order of ranking )
	1			
	|
	2
`	|
	5
	|
	4
	|
	3
	|
	6
Using tournament method
1 2	3 4	5 6

using mat[1][2],mat[3][4], mat[5][6], taking winner from each pair

1	4	5

1 4	5

using mat[1][4]

1	5

winner is 1

Steps- 
O(logN)
T(N)=T(N/2)+O(1)
O(logN)

ow how to find the ranking-> Use any sorting method
But for comparing use following criteria
bool cmp ( int a, int b )
{	if ( mat[a][b] == 1 )		'a' defeated 'b' then 'a' is larger ( higher rank )
		return 1;
	else
		return 0;
}

e.g.
1 2 3 4 5 6
using bubble sort and mat[][]
2 3 4 5 6 ,1				1 is highest ranked player
3 4 5 6 ,2 1				2 is ranked 2nd
3 4 6 ,5 2 1				5 is ranked 3rd
3 6 ,4 5 2 1				4 is ranked 4th
6 ,3 4 5 2 1				3 is ranked 5th
6 3 4 5 2 1				6 is ranked 6h

Use same logic on Merge / Quick Sort
O(NlogN)
*/

#include<cstdio>
#include<algorithm>
using namespace std;

bool mat[6][6]={	{0,1,1,1,1,1},
			{0,0,1,1,1,1},
			{0,0,0,0,0,1},
			{0,0,1,0,0,1},
			{0,0,1,1,0,1},
			{0,0,0,0,0,0}
		};

int cmp ( int a, int b )
{	if ( mat[a-1][b-1] == 0 )
		return 1;
	else
		return 0;
}

int find_winner( int a[], int n );

int main()
{	int a[6]={1,2,3,4,5,6};
	sort(a,a+6,cmp);
	for ( int i=0; i<6; i++ )
		printf("%d ", a[i]);
	printf("\n");
	printf("winner: %d\n",find_winner(a,6));
	return 0;
}

int find_winner( int a[], int n )
{	if ( n == 2 )
	{	if ( mat[a[0]-1][a[1]-1] == 1 ) 
			return a[0];
		else
			return a[1];
	}
	int N=n/2 + (n%2 != 0 );
	int A[100];
	for ( int i=0, j=0; i<n-1; i+=2, j++ )
	{	if ( mat[a[i]-1][a[i+1]-1] == 1 )
			A[j]=a[i];
		else
			A[j]=a[i+1];
	}
	if ( n %2 != 0 )
		A[N-1]=a[n-1];
	return find_winner(A,N);
}	
