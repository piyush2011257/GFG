/*
http://www.geeksforgeeks.org/amazon-interview-questions-set-147/
Given a 2D rectangle.In this rectangle there is some blocked areas which are shown in shaded part.Find the area which is left.Ex-like in this image one unbounded area is T1 and second is T2.You have to find both areas differently and print it. Hint-Take each block as 1*1 and apply dfs for all blocks.

Algorithm
f(i,j) = area of rectangle whose top-left corner is (i,j) and bottom-right corner is (N-1,N-1)

then for f(i,j) = f(i+1,j) + right(i,j)
where
right(i,j) -> no. of non-blck area in ith row starting and incluing jth col

right(i,j) = 1 + right(i,j+1) if a[i][j]=non-shaded
	     right[i,j+1)     if a[i][j] is shaded

Pre-process right[][] - O(N^2)
calculating f(0,0) - O(N^2)

O(N^2) time, O(N^2) space
space can be optimized to O(N) if considering right for only the row being calculated
and to O(1) if storing right(i,j+1) and then calculating right(i,j) and storing it for right(i,j-1)
*/

#include<cstdio>
using namespace std;

// starting from n-1,n-1. By help of data dependancy graph
const int row=4, col=8;

void func ( int a[][col] );
void pre_process ( int a[][col], int right[][col] );

int main()
{	int a[row][col]={{1,1,1,1,0,0,1,1},
			{1,0,0,1,0,0,1,1},
			{1,0,0,1,0,0,1,1},
			{1,1,1,1,0,0,1,1},
		   };
	func (a);
	return 0;
}

void func ( int a[][col] )
{	int right[row][col];
	pre_process(a,right);
	int val[row][col];
	for ( int i=row-1; i>=0; i-- )
	{	for ( int j=col-1; j>=0; j-- )
		{	int v1=0, v2=0;
			if ( i+1 < row )
				v1=val[i+1][j];
			v2=right[i][j];
			val[i][j]=v1+v2;
		}
	}
	/*
	for ( int i=0; i<row; i++)
	{	for ( int j=0; j<col; j++ )
			printf("%d ", val[i][j]);
		printf("\n");
	}
	*/
	printf("%d\n", val[0][0]);
}

void pre_process ( int a[][col], int right[][col] )
{	for ( int i=0; i<row; i++ )
		for ( int j=col-1; j>=0; j-- )
		{	if ( j ==col-1 )
				right[i][j]= (a[i][j] == 1 );
			else
				right[i][j]=right[i][j+1] + ( a[i][j] == 1 );
		}
}
