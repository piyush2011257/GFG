/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-159-off-campus/
Rotate an image represented by a 2D matrix by 90 degree.

Rotate an image represented by a 2D matrix by 90 degree
http://stackoverflow.com/questions/3488691/how-to-rotate-a-matrix-90-degrees-without-using-any-extra-space
*/

#include<cstdio>
using namespace std;

int main()
{	int a[5][5]={	{1,2,3,4,5},
			{6,7,8,9,10},
			{11,12,13,14,15},
			{0,0,0,0,0},
			{0,0,0,0,0}
		    };
	int row=3, col=5;
        for ( int i=0; i<row; i++ )
        {       for ( int j=0; j<col; j++ )
                        printf("%d\t", a[i][j]);
                printf("\n");
        }
	printf("\n");
	if ( row <= col )
	{	int n=row;
		int f= n/2;
		int c=n/2;
		c--;			// till mid of column
		for ( int i=0; i<=f; i++ )
		{	for ( int j=0; j<=c; j++ )
			{	int temp=a[i][j];
				a[i][j]=a[n-1-j][i];
				a[n-1-j][i]=a[n-1-i][n-1-j];
				a[n-1-i][n-1-j]=a[j][n-1-i];
				a[j][n-1-i]=temp;
			}
		}
	}
	/*
        for ( int i=0; i<row; i++ )
        {       for ( int j=0; j<col; j++ )
                        printf("%d\t", a[i][j]);
                printf("\n");
        }
	*/
	// inmdividually for out of range parameters. No cyclic
	for ( int i=0; i<row; i++ )
		for ( int j=row; j<col; j++ )
			a[j][row-i-1]=a[i][j];
	
	for ( int i=0; i<col; i++ )
	{	for ( int j=0; j<row; j++ )
			printf("%d\t", a[i][j]);
		printf("\n");
	}
	
	return 0;
}
