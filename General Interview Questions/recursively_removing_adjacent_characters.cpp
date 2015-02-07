/*
ABCCBCBA -> ACBA
*/

#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

void func ( char *ch, int  n );

int main()
{	char ch[]="ABCCBCBA";
	int n=strlen(ch);
	func(ch,n);
	return 0;
}

void func ( char *ch, int  n )							// Can be done with simple O() function
{	stack<char> s;
	for ( int i=0; i<n; )
	{	bool ctr=0;
		while ( s.empty() == 0 && s.top() == ch[i] )			// O(n) Each element inserted and deleted max twice
		{	ctr=1;
			s.pop();
		}
		if ( ctr == 0 )
			s.push(ch[i]);
		i++;
		/*
		AAB -> B
		AAAB -> AB
		*/
	}
	int size=s.size();
	char ch2[size+1];
	ch2[size--]='\0';
	while ( s.empty() == 0  )
	{	ch2[size--]=s.top();
		s.pop();
	}
	printf("%s\n",ch2);
}
	

	
