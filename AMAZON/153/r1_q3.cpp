/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-153-sde1/
Q3. http://www.geeksforgeeks.org/count-possible-decodings-given-digit-sequence/

Count Possible Decodings of a given Digit Sequence
http://www.geeksforgeeks.org/count-possible-decodings-given-digit-sequence/
*/

#include<cstdio>
#include<cstring>
using namespace std;

int main()
{	char a[100];
	scanf("%s",a);
	int n=strlen(a);
	int func[100]={0};
	func[0]=func[1]=1;
	for ( int i=2; i<=n; i++ )
	{	func[i]=func[i-1];
		if ( a[i-1-1] == '1' || ( a[i-1-1] =='2' && a[i-1] <= '6' ))
			func[i] += func[i-2];
	}
	printf("%d\n", func[n]);
	return 0;
}
