/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-148/
Incoming stream of characters () defines an onion of depth 1, (()) of 2. Find all onions with their in an incoming stream of characters. Discuss complexity.
Stream can be (()) () )) ((( (
*/

#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;

int main()
{	stack<char> s;
	char ch[100];
	scanf("%s",ch);
	int n=strlen(ch);
        int ctr=0, max_ctr=0;
	for ( int i=0; i<n; )
	{	if ( ch[i] == ')' )
		{	ctr=0;
			while ( s.empty() == 0 && i < n && ( ch[i] == ')' && s.top() == '(' ) )
			{	ctr++;			// max continuous pops is the depth
				s.pop();
				i++;
			}
			if ( ctr > max_ctr )
				max_ctr=ctr;
		}
		if ( i<n)
			s.push(ch[i++]);
	}
	printf("%d\n", max_ctr);
	return 0;
}
