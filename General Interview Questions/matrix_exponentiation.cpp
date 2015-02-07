/*
http://zobayer.blogspot.in/2010/11/matrix-exponentiation.html
https://codeaccepted.wordpress.com/2014/06/01/algorithm-12-matrix-exponentiation/
*/

#include<cstdio>
using namespace std;

void matmult( int a[][2], int b[][2], int c[][2], int mod )		// O(d^3)
{	int i,j,k;
	for( int i=0;i<2;i++)
	{	for(int j=0;j<2;j++)
		{	c[i][j]=0;
			for(int k=0;k<2;k++)
			{	c[i][j]+=(a[i][k]*b[k][j]);
				c[i][j]=c[i][j]%mod;
			}
		}
	} 
}

void matpow( int Z[][2], int n, int ans[][2], int M)
//find ( Z^n )% M and return result in ans
{	int temp[2][2];
	//assign ans= the identity matrix
	// ans = IDENTITY MATRIX
	ans[0][0]=1;
	ans[1][0]=0;
	ans[0][1]=0;
	ans[1][1]=1;
	int i,j;
	while(n>0)
	{	if(n&1)
		{	matmult(ans,Z,temp,M);
			for(i=0;i<2;i++)
				for(j=0;j<2;j++)
					ans[i][j]=temp[i][j];
		}
		matmult(Z,Z,temp,M);
		for(i=0;i<2;i++)
			for(j=0;j<2;j++)
				Z[i][j]=temp[i][j];
 		n=n/2;
		/*
		(3,13) -> (9,6) result *= 3
			  (9,6) -> (81,3) -> (81*81,1)	result *= 81
					     n == 1     result *= (81*81)
		3^13=(81)*(81)*(81)*3
		*/
	}
	return;
}

int findFibonacci( int n, int M)
{	int fib;
	if(n>2)
	{	int Z[2][2]={{1,1},{1,0}},result[2][2];
		matpow(Z,n-2,result,M);
		fib=result[0][0]*1 + result[0][1]*0;
	}
	else
		fib=n-1;
	return fib;
}

int main()
{	int k;
	while ( scanf("%d",&k) != 0 )
		printf("%d\n",findFibonacci(k,1000000007));
	return 0;
}
