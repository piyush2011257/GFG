/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-162/

http://www.geeksforgeeks.org/dice-throw-problem/
Given n dice each with m faces, numbered from 1 to m, find the number of ways to get sum X. X is the summation of values on each face when all the dice are thrown.

Observations-
f(n,x) = f(n-1,x-1) + f(n-1, x-2) + f(n-1,x-3) + f(n-1,x-4) + .... + f(n-1,x-m)

Also
n dice will make at least n sum ( each having 1 on it )
so f(i,j) where i>j -> 0 since sum > n

11 12 13 14 15 16
21 22 23 24 25 26
31 32 33 34 35 36
41 42 43 44 45 46

f(i,i)=1 ( all dices get 1 )
f(i,j) where i>j = 0 since i cannot be < j

for ( i=2; i<N; i++ )
	for ( j=2; j<X; j++ )
		for ( k=1; k<=m; k++ )		k <= m and k >= j-1 as well
			a[i][j]=a[i-1][j-k]		i-1 <= j-k and j-k >= 1

answer -> a[n][x]
O(N*X*M)
*/

#include <iostream>
#include <string.h>
using namespace std;
 
// The main function that returns number of ways to get sum 'x'
// with 'n' dice and 'm' with m faces.
int findWays(int m, int n, int x)
{	int table[n + 1][x + 1];
    	memset(table, 0, sizeof(table)); // Initialize all entries as 0, set lower triangle to 0
    	for (int j = 1; j <= m && j <= x; j++)
        	table[1][j] = 1;
 	for (int i = 2; i <= n; i++)
        	for (int j = 1; j <= x; j++)
            		for (int k = 1; k <= m && k < j; k++)
                		table[i][j] += table[i-1][j-k];	// j-k >= 1 -> k < j
 	/* Uncomment these lines to see content of table
	for (int i = 0; i <= n; i++)
	{	for (int j = 0; j <= x; j++)
			cout << table[i][j] << " ";
		cout << endl;
	} */
	return table[n][x];
}
 
int main()
{	cout << findWays(4, 2, 1) << endl;
	cout << findWays(2, 2, 3) << endl;
	cout << findWays(6, 3, 8) << endl;
	cout << findWays(4, 2, 5) << endl;
	cout << findWays(4, 3, 5) << endl;
	return 0;
}
