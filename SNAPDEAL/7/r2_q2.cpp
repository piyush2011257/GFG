/*
http://www.geeksforgeeks.org/snapdeal-interview-experience-set-7-campus/
Output the no of binary strings of length n having no consecutive 0’s http://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/
*/

#include <iostream>
using namespace std;
 
int count_strings ( int n )
{	int a[n], b[n];
 	a[0]=b[0]=1;
 	for ( int i=1; i<n; i++ )
 	{	a[i] = a[i-1]+b[i-1];
		b[i] = a[i-1];
	}
	return a[n-1] + b[n-1];
}
 
int main()
{	int n;
	cin>>n;
	cout<<count_strings(n)<<endl;
	return 0;
}

/*
a[i] - strings starting with 1 and having non-consecutive 0's of length i
b[i] - strings starting with 0 and having non-consecutive 0's of length i

i=2

00
01
10
11

a[2]= {10, 11}
b[2]= {01}

For non-consecutive 0 of length 3
0a[2]	010, 011	<- b[3]
1a[2]	110, 111	<- a[3]

1b[2]	101		<- a[3]

a(i) = a(i-1) + b(i-1)
b(i) = a(i-1)
*/

