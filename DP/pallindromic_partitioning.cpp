/*
http://www.geeksforgeeks.org/dynamic-programming-set-17-palindrome-partitioning/
Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome. For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. Determine the fewest cuts needed for palindrome partitioning of a given string. For example, minimum 3 cuts are needed for “ababbbabbababa”. The three cuts are “a|babbbab|b|ababa”. If a string is palindrome, then minimum 0 cuts are needed. If a string of length n containing all different characters, then minimum n-1 cuts are needed.

Similar to Matrix Chain Multiplication
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

int partition ( string str );
void pallindrome_preprocess ( bool ** a, string s );

int main()
{	string str;
	cin>>str;
	cout<<"minimum pallindromic partitioning: "<<partition(str)<<endl;
	return 0;
}

void pallindrome_preprocess ( bool ** a, string str )
{	int n=str.length();
	for ( int i=0; i<n; i++ )
		a[i][i]=1;
	for ( int i=n-1; i>=0; i-- )
	{	for ( int j=i+1; j<n; j++ )
		{	if ( str[i] == str[j] )
			{	if ( i+1 < n && j-1 >= i && i+1 <= j-1)
					a[i][j] = a[i+1][j-1];
				else
					a[i][j]=1;
			}
			else
				a[i][j]=0;
		}
	}
}

int partition ( string str )
{	int n=str.length();
	int a[n][n], min;
	bool **is_pal;
	is_pal=new bool*[n];
	for ( int i=0; i<n; i++ )
		is_pal[i]=new bool[n];
	pallindrome_preprocess(is_pal,str);
	memset(a,0,sizeof(a));
	/*
	for ( int i=0; i<n; i++ )
	{	for ( int j=0; j<n; j++ )
			printf("%d ", is_pal[i][j]);
		printf("\n");
	}
	*/
	for ( int i=0; i<n; i++ )
		a[i][i]=0;
	for ( int i=n-1; i>=0; i-- )
	{	for ( int j=i+1; j<n; j++ )
		{ 	if ( is_pal[i][j] == 1 )
				a[i][j]=0;
			else
			{	min=INT_MAX;
				for ( int k=i; k<j; k++ )
				{	//cout<<i<<" "<<k<<" "<<j<<endl;
					if ( a[i][k] + 1 + a[k+1][j] < min )
						min=a[i][k] + 1 + a[k+1][j];		// create a partition betweem i,k and k+1,j
				// f(i,j) -> min cuts for partitioning (i,j)
				// recurrence -> f(i,k) + partition (1) + f(k+1,j)
				}
				a[i][j]=min;
			}
		}
	}
        /*
	for ( int i=0; i<n; i++ )
        {       for ( int j=0; j<n; j++ )
                        printf("%d ", a[i][j]);
                printf("\n");
	}
	*/
	return a[0][n-1];
}
