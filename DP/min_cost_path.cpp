/*
http://www.geeksforgeeks.org/dynamic-programming-set-6-min-cost-path/
Given a cost matrix cost[][] and a position (m, n) in cost[][], write a function that returns cost of minimum cost path to reach (m, n) from (0, 0). Each cell of the matrix represents a cost to traverse through that cell. Total cost of a path to reach (m, n) is sum of all the costs on that path (including both source and destination). You can only traverse down, right and diagonally lower cells from a given cell, i.e., from a given cell (i, j), cells (i+1, j), (i, j+1) and (i+1, j+1) can be traversed. You may assume that all costs are positive integers.
*/
#include<cstdio>
#include<iostream>
#include<climits>
using namespace std;

int min_cost ( int **a, int n, int m );

int main()
{	int n,m;
	cin>>n>>m;
	int **a=new int*[n];
	for ( int i=0; i<n; i++ )
		a[i]=new int[m];
	for ( int i=0; i<n; i++ )
		for ( int j=0; j<m; j++ )
			scanf("%d",&a[i][j]);
	cout<<"min cost: "<<min_cost(a,n,m)<<endl;
	return 0;
}

int min_cost ( int **a, int n, int m )
{	int v1,v2,v3,min;
	for ( int i=0; i<n; i++ )
	{	for ( int j=0; j<m; j++ )
		{	v1=v2=v3=INT_MAX;
			if ( i-1 >= 0 )
				v1=a[i-1][j];
			if ( j-1 >= 0 )
				v2=a[i][j-1];
			if ( i-1 >= 0 && j-1 >= 0 )
				v3=a[i-1][j-1];
			min= v1 < v2 ? v1 : v2;
			min= v3 < min ? v3 : min;
			if ( min != INT_MAX )
				a[i][j] += min;
		}
	}
	return a[n-1][m-1];
}
