/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-145-campus/
How to compute A^n where n<1 million

http://www.geeksforgeeks.org/write-a-c-program-to-calculate-powxn/


2 ways to see it-

f(a,n) = f(a*a,n/2) * a  	if n%2 != 0 
	 f(a*a,n/2)	 	else

OR
f(a,n) = 	temp = f(a,n/2) 
		temp * temp * a		if n%2 != 0
		temp * temp		if n%2 == 0
*/

#include<cstdio>
using namespace std;

/*
(3,9)=(3,4)*(3,4)*3
(3,4)=(3,2)*(3,2)
(3,2)=(3,1)*(3,1)
*/

int func (int a, int n )
{	if ( n == 0 )			// spl case
		return 1;
	if ( n == 1 )
		return a;
	int tmp=func(a,n/2);
	if ( n%2 == 0 )
		return tmp*tmp;
	else
		return tmp*tmp*a;
}

// extend the pow function to work for negative y and float x.
float power(float x, int y)
{	if ( y == 0 )			// spl case
		return 1;
	if( y == 1)
		return x;
    	else if ( y == -1 )
		return 1/x;
	temp = power(x, y/2);
	if (y%2 == 0)
		return temp*temp;
	else
	{	if( y > 0)
        		return x*temp*temp;
		else
			return (temp*temp)/x;
	}
}
/*
(2,-3)=(2,-1)*(2,-1)*(1/2)
(2,-1)= 1/2

(2,-4)=(2,-2)*(2,-2)
(2,-2)=(2,-1)*(2,-1)
(2,-1)=1/2
*/

int main()
{	printf("%d\n",func(2,3));
	printf("%lf\n",power(2,-2));
	return 0;
}
