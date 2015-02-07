/*
http://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
Method 5
*/
#include<cstdio>
#include<iostream>
using namespace std;

void multiply ( int a[2][2], int b[2][2], int c[2][2]);
int fibo ( int n );
void print ( int a[2][2] );

int main()
{	int n;
	cin>>n;
	cout<<fibo(n)<<endl;
	return 0;
}

void print ( int a[2][2] )
{	for ( int i=0; i<2; i++ )
	{	for ( int j=0; j<2; j++ )	
			printf("%d ", a[i][j]);
		printf("\n");
	}
}
int fibo ( int n )
{	int base[2][2]={{1,1,},{1,0}};
	int tmp[2][2]={{0,0},{0,0}};
	int result[2][2]={{1,0},{0,1}};
	if ( n == 1 || n == 2 )
		return n-1;
	n-=2;
	while ( n > 1 )
	{	//cout<<n<<endl;
		if ( n % 2  == 1 )
		{	multiply(result,base,tmp);
			for ( int i=0; i<2; i++ )
				for ( int j=0; j<2; j++ )
					result[i][j]=tmp[i][j];
		}
		multiply(base,base,tmp);
		for ( int i=0; i<2; i++ )
                	for ( int j=0; j<2; j++ )
                        	base[i][j]=tmp[i][j];
		n=n/2;
	}
	multiply(base,result,tmp);
	/*
	cout<<"base"<<endl;
	print(base);
	cout<<"result"<<endl;
	print(result);
	*/
        for ( int i=0; i<2; i++ )
        	for ( int j=0; j<2; j++ )
                	result[i][j]=tmp[i][j];
	return result[0][0];
}

void multiply ( int a[2][2], int b[2][2], int c[2][2])
{	for ( int i=0; i<2; i++ )
		for ( int j=0; j<2; j++ )
		{	c[i][j]=0;
			for ( int k=0; k<2; k++ )
				c[i][j] += a[i][k] * b[k][j];
		}
}
