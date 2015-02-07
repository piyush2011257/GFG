/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-164-sde/
Count the decoding for a given digit string. Let say ‘A’ -> 1, B -> 2 and so on
Eg :

Input: digits[] = “123”
Output: 3  //”ABC”, “ LC” ,  “AW”

http://www.geeksforgeeks.org/count-possible-decodings-given-digit-sequence/

Algorithm

f(str,i) = f(str,i+2) if str(i)str(i+1) >= '10' && <= '26'
				4 is valid 04 is invalid
	   +
	   f(str1,i+1) if str(i) >= '1' && <='9'
			'0' is invalid
func ( str, i, n )
{	if ( i == n )
		return 1;
	if ( i > n )
		return 0;
	val=0;
	if ( i+2 <= n )
	{	if ( str[i][str[i+1] is valid ) 
			val += func ( str,i+2,n);
	}
	if ( str[i[ is valid )
		val += func(str,i+1,n)
	return val;
}

Adding memoization
func[n]=1;
func[n+1]=0;
func[i]= func[i+2] if str[i]str[i+1] is valid 	else 0
	 +
	 func[i+1] if str[i] is valid else 0
O(n) solution
func[i]-> no. of decodings for substring str(i,n-1)
O(n)- TIME / SPACE
can be optimized as for each i we need only i+1, i+2 at a time
O(N) time
O(1) space
*/

#include<cstdio>
using namespace std;

const int len=4;		// +1 for '\0'
int main()
{	char ch[len]="123";
	int val[len+1]={0};
	val[len]=1;
	val[len+1]=0;
	val[len-1]=1;
	for ( int i=len-2; i>=0; i-- )
	{	if ( ( ch[i] == '1' && ch[i+1] <= '9' && ch[i+1] >= '0' ) || ( ch[i] == '2' && ch[i+1] >= '0' && ch[i+1] <= '6' ) )
			val[i] += val[i+2];
		if ( ch[i] >= '1' && ch[i] <= '9' )
			val[i] += val[i+1];
	}
	for ( int i=0; i<len; i++ )
		printf("%d ",val[i]);
	printf("\ncount: %d\n", val[0]);
	return 0;
}
