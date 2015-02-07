/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-145-campus/
You r given a matrix of 0s and 1s. WAP that check if an element is 0 or not and places zeros to all the col and row of that element.

       eg: i/p:    1 1 1 1       o/p    :  1 1 0 1
                   1 1 0 1                 0 0 0 0
                   1 1 1 1                 1 1 0 1
                   1 1 1 1                 1 1 0 1

Approach
http://n00tc0d3r.blogspot.in/2013/05/set-matrix-to-zeroes.html

Solution 1
As we go through the matrix, if we find a zero, we cannot set its row and column to zeroes yet. If we do that, we would not know whether or not to set the next row and next column to zeroes.

So, we iterate through the matrix twice.
    In the first iteration, we find out all of the zeroes and store their row and column numbers.
    In the next iteration, we set a cell to zero if it is on a row or a column that we stored.

This solution uses extra space O(m+n) for marking if the row / column contains 0 or not


Optimization

Consider we traverse each elemnt of matrix column wise.
Now if we encounter a[i][j] = 0 
Mark all a[i][k] 0 <= k < n 	-1 if a[i][k]=1
				else let it be 0

Similarly do for all elements for all elements in column. 
Use a variable zero_in_current_col and set it to 1 is the current column contains a 0. After traversing the column. If zero_in_current_col == 1, then set al elements a[k][i] 0 <= k < n 	-1 if a[k][i]=1
						else let it be 0

Now do it for all columns
Now traverse again,
if (a[i][j] == -1 ) 
	a[i][j]=0

E.g.
0 0 1 0 1
1 1 1 1 1
1 0 1 1 1
0 1 0 0 1

First col

0 0 -1 0 -1
1 1 1 1 1
1 0 1 1 1
0 -1 0 0 -1

zero_in_current_col=1

0 0 -1 0 -1
-1 1 1 1 1
-1 0 1 1 1
0 -1 0 0 -1

Second col
0   0 -1  0 -1
-1  1  1  1  1
-1  0  -1  -1  -1
0  -1  0  0 -1

0   0 -1  0 -1
-1  -1  1  1  1
-1  0  -1  -1  -1
0  -1  0  0 -1

Third Col / Fourth Col
0   0  -1   0  -1
-1 -1   1   1   1
-1  0  -1  -1  -1
0  -1   0   0  -1

zero_in_current_col=1
0   0  -1   0  -1
-1 -1  -1  -1   1
-1  0  -1  -1  -1
0  -1   0   0  -1


0 0 0 0 0
0 0 0 0 1
0 0 0 0 0 
0 0 0 0 0

Each element visited by each row
(n*n)*n = (n^3) solution
O(1) space

Now how to optimize space??
http://n00tc0d3r.blogspot.in/2013/05/set-matrix-to-zeroes.html
We have an entire matrix and thus we can use one row and one column of the matrix to store the zero information. Before we revise the values in that row and column, we need to know whether the original row/column contain zero. If so, we also need to set the row/column to zeros; If not, leave other values as they are.

So a[0][i] -> if a[0][i] = -1 means ith col needs to be 0
   a[i][0] -> if a[i][0] = -1 means ith row needs to be 0

0	0	1	0	1
1 	1 	1 	1 	1
1 	0 	1 	1 	1
0 	1 	0 	0 	1

Traverse row wise

First iter after traversing 1st row

-1	-1	1	-1	1
1 	1 	1 	1 	1
1 	0 	1 	1 	1
0 	1 	0 	0 	1

Second iter after traversing 2nd row

-1	-1	1	-1	1
1 	1 	1 	1 	1
1 	0 	1 	1 	1
0 	1 	0 	0 	1

Third iter after traversing 3rd row

-1	-1	1	-1	1
1 	1 	1 	1 	1
-1 	0 	1 	1 	1
0 	1 	0 	0 	1

Fourth iter after traversing 4th row

-1	-1	-1	-1	1
1 	1 	1 	1 	1
-1 	0 	1 	1 	1
-1	1 	0 	0 	1


Now change if a[i][0] = -1 means mkae ith row 0 and if a[0][i] =-1 means make ith col 0. DOnt change 1st row / col !!
-1	-1	-1	-1	1
1 	0 	0 	0 	1
-1 	0 	0 	0 	0
-1	0 	0 	0 	0


Now change a[0][i] except a[i][0]

-1	0	0	0	0
1 	0 	0 	0 	1
-1 	0 	0 	0 	0
-1	0 	0 	0 	0

Now go row wise

-1	0	0	0	0
1 	0 	0 	0 	1
-1 	0 	0 	0 	0
-1	0 	0 	0 	0

At last change according to a[0][0]
0	0	0	0	0
0 	0 	0 	0 	1
0 	0 	0 	0 	0
0	0 	0 	0 	0

O(N^2)
Each element visited thrice. O(1) space
*/
#include<cstdio>
using namespace std;

const int row=4, col=5;
void func ( int a[row][col] );

int main()
{	int a[row][col]={{1,0,1,0,1},
			{1,1,1,1,1},
			{1,0,1,1,1},
			{1,1,0,0,1},
		    };
	func(a);
	return 0;
}

void func ( int a[row][col] )
{	
	/*
	 special case of a[0][0]
	{{1,0,1,0,1},
         {1,1,1,1,1},
         {1,0,1,1,1},
         {1,1,0,0,1},
	}
	*/
	int row_zero=0, col_zero=0;
	for ( int i=0; i<col; i++ )		// for 0th row
		if ( a[0][i] == 0 )
			row_zero=1;
        for ( int i=0; i<row; i++ )		// for 0th col
                if ( a[i][0] == 0 )
                        col_zero=1;
	/*
	a[0][i] -> ith column
	a[i][0] -> ith row
	row_zero -> 0th row
	col_zero -> 0th col
	*/
	for ( int i=0; i<row; i++)
	{	for ( int j=0; j<col; j++ )
		{	if ( a[i][j] == 0 )
			{	a[0][j]=-1;
				a[i][0]=-1;
			}
		}
	}
	for ( int i=1; i<col; i++ )
	{	if ( a[0][i] == -1 )
		{	for ( int j=0; j<row; j++ )
				a[j][i]=0;
		}
	}
        for ( int i=1; i<row; i++ )
        {       if ( a[i][0] == -1 )
                {       for ( int j=0; j<col; j++ )
                                a[i][j]=0;
                }
        }
	/*
	for ( int i=0; i<col; i++ )
		printf("%d ", a[0][i]);
	printf("\n");
        for ( int i=0; i<row; i++ )
                printf("%d ", a[i][0]);
        printf("\n");
	*/
	if ( row_zero == 1 ) 				// for 0th row
		for ( int i=0; i<col; i++ )
			a[0][i]=0;
	if ( col_zero == 1 )				// for 0th col
		for ( int i=0; i<col; i++ )
			a[i][0]=0;
	for ( int i=0; i<row; i++ )
	{	for ( int j=0; j<col; j++ )
			printf("%d ",a[i][j]);
		printf("\n");
	}
}
