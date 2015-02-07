/*
http://www.geeksforgeeks.org/snapdeal-interview-experience-set-7-campus/
Given a string of parenthesis only, check if it’s valid or no
*/

#include<cstdio>
#include<stack>
#include<iostream>
#include<cstring>
using namespace std;

/*
[))
+2-1-1
*/
int main()
{	int n;
	cin>>n;
	char ch[n];
	int val[n];
	memset(val,0,sizeof(0));
	stack<char> s;
	cin>>ch;
	//cout<<ch;
	bool wrong=0;
	if ( n%2 == 1 )
		wrong=1;
	else
	{	int pos=0;
		for ( int i=0; i<n; i++ )
		{	if ( ch[i] == '(' )
				val[pos++]=1;
			else if ( ch[i] == '{' )
				val[pos++]=2;
			else if ( ch[i] == '[' )
				val[pos++]=3;
			else
			{	if ( ch[i] == ')' )
				{	if ( pos == 0 || val[pos-1] != 1 )
					{	wrong=1;
						break;
					}
					pos--;
				}
				else if ( ch[i] == '}' )
                        	{       if ( pos == 0 || val[pos-1] != 2 )
                        	        {       wrong=1;        
                        	                break;
                        	        }
					pos--;
                        	}
				else if ( ch[i] == ']' )
                        	{       if ( pos == 0 || val[pos-1] != 3 )
                        	        {       wrong=1;        
                        	                break;
                        	        }
					pos--;
                        	}
			}
		}
		if ( pos > 0  )
			wrong=1;
	}
	if ( wrong == 1 )
		printf("Error\n");
	else
		printf("Balanced\n");
	return 0;
}
	
