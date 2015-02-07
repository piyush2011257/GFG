/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-167-sde-1-year-6-months-experience/
Given a list of N coins, their values (V1, V2, … , VN), and the total sum S. Find the minimum number of coins the sum of which is S (we can use as many coins of one type as we want), or report that it’s not possible to select coins in such a way that they sum up to S.
Example: Given coins with values 1, 3, and 5.
And the sum S is 11.
Output: 3, 2 coins of 3 and 1 coin of 5.

func(N,i) = min ( func(N-val(i),i) + 1 , func(N,i-1 ) )
			N-val(i) >= 0 

for i=0 first
FUNC[][]={-1} INITIALIZE ALL WITH -1
ALL FUNC[0][I]=0;
FOR ( I=V(0),J=1 ; I<=C; I+=V(0),J++ )
	FUNC(I][0]=J;

FOR (i=1; i<n-1; i++ )
	for ( j=0; j<v(1); j++ )
		func(j)(i)=func(j)(i-1);
	for (j=v(1); j<=C; j++ )
	{	m1=func(j-v1(1),i)+1
		m2=func(j,i-1)
		func(j)(i)=min(m1,m2)
	}

O(C*N)- time / space
Space can be optimize, since we need only 2 rows at max at a time- O(C) space
*/

#include<cstdio>
#include<climits>
using namespace std;

const int len=3;

// all are integers so max coins used <= sum if we use all 1. hence max value is sum+1
int main()
{	int coins[len]={1,2,3};
	int sum=7;
	int func[len][sum+1];
	for ( int i=0; i<len; i++ )
		for ( int j=0; j<=sum; j++ )
			func[i][j]=INT_MAX;
	for ( int i=0; i<len; i++ )
		func[i][0]=0;			// base case
	for ( int i=coins[0], j=1; i<=sum; i+=coins[0], j++ )
		func[0][i]=j;			// initial for 0th row
	for ( int i=1; i<len; i++ )
	{	for ( int j=1; j<coins[i]; j++ )
			func[i][j]=func[i-1][j];
		for ( int j=coins[i]; j<=sum; j++ )
		{	int m1=INT_MAX, m2=INT_MAX;
			if ( func[i][j-coins[i]] != INT_MAX )	// if func[i][j-coins[i]] has a valid solution
				m1=func[i][j-coins[i]]+1;
			m2=func[i-1][j];
			if ( m1 < m2 )
				func[i][j]=m1;
			else
				func[i][j]=m2;
		}
	}
	for ( int i=0; i<len; i++ )
	{	for ( int j=0; j<=sum; j++ )
			printf("%d\t", func[i][j]);
		printf("\n");
	}
	printf("%d\n", func[len-1][sum]);
	return 0;
}


/*
Finding minimum coins
for finding no. of ways
f(i,N) = f(i,N-1) + f(i-val(i),N)
*/
