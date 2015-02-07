/*
http://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/
Given a binary matrix, find out the maximum size square sub-matrix with all 1s.
*/

#include<cstdio>
#include<iostream>
using namespace std;

int max_square_matrix ( bool **a, int n, int m );

int main()
{	int n,m;
	cin>>n>>m;
	bool **a;
	a= new bool*[n];
	for ( int i=0; i<n; i++ )
		a[i]=new bool[m];
	for ( int i=0; i<n; i++ )
		for ( int j=0; j<m; j++ )
			cin>>a[i][j];
	cout<<"maximum size: "<<max_square_matrix(a,n,m)<<endl;
	return 0;
}

int max_square_matrix ( bool **a, int n, int m )
{	int mat[n][m];
	for ( int i=0; i<m; i++ )
		mat[0][i]=a[0][i];
	for ( int i=0; i<n; i++ )
		mat[i][0]=a[i][0];
	int min, max=0,i0=-1,j0=-1;
	for ( int i=1; i<n; i++ )
	{	for ( int j=1; j<m; j++ )
		{	if ( a[i][j] == 0 )
			{	mat[i][j]=0;
				continue;
			}
			min=mat[i-1][j] < mat[i-1][j-1] ? mat[i-1][j] : mat[i-1][j-1];
			if ( mat[i][j-1] < min )
				min=mat[i][j-1];
			mat[i][j]=min+1;
			if ( mat[i][j] > max )
			{	max=mat[i][j];
				i0=i;
				j0=j;
			}
		}
	}
	printf("Mat matrix\n");
	for ( int i=0; i<n; i++ )
	{	for ( int j=0; j<m; j++ )
			printf("%d ", mat[i][j]);
		printf("\n");
	}
	printf("Bottom right coordinates: %d %d\n",i0,j0);
	return max;
}
