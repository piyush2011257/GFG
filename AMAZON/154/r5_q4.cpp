/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-154-sde2/
Spiral matrix puzzle.
Approach 1- Approach based on traversing index and matrix

*/

#include<cstdio>
using namespace std;

bool print_top_row(int a[][6], int i, int r, int c);
void func ( int a[][6], int r, int c );
bool print_bottom_row(int a[][6],int i,int r,int c);
bool print_right_col(int a[][6],int i, int r,int c);
bool print_left_col(int a[][6], int i, int r, int c);

int main()
{	int a[6][6]={	{1,2,3,4,5,6},
			{7,8,9,10,11,12},
			{13,14,15,16,17,18},
			{19,20,21,22,23,24},
			{25,26,27,28,29,30},
			{31,32,33,34,35,36}
		    };
	func(a,6,6);
	return 0;
}

void func ( int a[][6], int r, int c )
{	int i=0;
	bool v1=0;
	do
	{	v1 = print_top_row(a,i,r,c);
		if ( v1 == 0 )
			return;
		v1 = print_right_col(a,i,r,c);
		if ( v1 == 0 )
                        return;
                v1 = print_bottom_row(a,i,r,c);
		if ( v1 == 0 )
                        return;
                v1 = print_left_col(a,i,r,c);
		if ( v1 == 0 )
                        return;
                i++;
	} while(v1 == 1 );
	
}

bool print_top_row(int a[][6], int i, int r, int c)
{	bool v1=0;
	if ( i > r-1 )
		return 0;
	for ( int j=i; j<=c-i-1; j++ )
	{	v1=1;
		printf("%d ", a[i][j]);
	}
	return v1;
}

bool print_bottom_row(int a[][6], int i, int r, int c)
{       bool v1=0;
        if ( r-i-1 < 0 )
		return 0;
	for ( int j=c-i-1; j>=i; j-- )
        {       v1=1;
                printf("%d ", a[r-i-1][j]);
        }
        return v1;
}

bool print_right_col(int a[][6],int i, int r,int c)
{       bool v1=0;
        if ( c-i-1 < 0 )
		return 0;
	for ( int j=i+1; j<r-i-1; j++ )
        {       v1=1;
                printf("%d ", a[j][c-i-1]);
        }
        return v1;
}

bool print_left_col(int a[][6], int i, int r, int c)
{       bool v1=0;
        if ( r-i-1 < 0 )
                return 0;
        for ( int j=r-i-2; j>i; j-- )
        {       v1=1;
                printf("%d ", a[j][i]);
        }
        return v1;
}

