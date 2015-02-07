/*
http://www.geeksforgeeks.org/snapdeal-interview-experience-set-7-campus/
Given a string of parenthesis only, check if it’s valid or no
*/

#include<cstdio>
#include<stack>
#include<iostream>
using namespace std;

int main()
{	int n;
	cin>>n;
	char ch[n];
	stack<char> s;
	cin>>ch;
	cout<<ch;
	bool wrong=0;
	if ( n%2 == 1 )
		wrong=1;
	else
	{	for ( int i=0; i<n; i++ )
		{	if ( ch[i] == '(' || ch[i] == '{' || ch[i] == '[' )
				s.push(ch[i]);
			else
			{	if ( ch[i] == ')' )
				{	if ( s.empty() == 1 || s.top() != '(' )
					{	wrong=1;
						break;
					}
					s.pop();
				}
				else if ( ch[i] == '}' )
                        	{       if ( s.empty() == 1 || s.top() != '{' )
                        	        {       wrong=1;        
                        	                break;
                        	        }
					s.pop();
                        	}
				else if ( ch[i] == ']' )
                        	{       if ( s.empty() == 1 || s.top() != '[' )
                        	        {       wrong=1;        
                        	                break;
                        	        }
					s.pop();
                        	}
			}
		}
		if ( s.empty() == 0 )
			wrong=1;
	}
	if ( wrong == 1 )
		printf("Error\n");
	else
		printf("Balanced\n");
	return 0;
}
	
