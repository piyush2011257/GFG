/*
http://www.geeksforgeeks.org/dynamic-programming-set-5-edit-distance/
Given two strings of size m, n and set of operations replace (R), insert (I) and delete (D) all at equal cost. Find minimum number of edits (operations) required to convert one string into another.
*/

// Assuming all costs to be 1
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int edit_dist ( string s1, string s2 );

int main()
{	string s1,s2;
	cin>>s1>>s2;
	cout<<edit_dist ( s1,s2)<<endl;
	return 0;
}

int edit_dist ( string s1, string s2 )
{	int n=s1.length();
	int m=s2.length();
	int a[n+2][m+2];
	memset(a,0,sizeof(a));
	//for ( int i=0; i<=m; i++ )
	//	a[0][i]=i;
	//for ( int i=0; i<=n; i++ )
	//	a[i][0]=i;
	for ( int i=1; i<=m; i++ )
		a[n+1][i]=m-i+1;
	for ( int i=1; i<=n; i++ )
		a[i][m+1]=n-i+1;
	for ( int i=n; i>0; i-- )
	{	for ( int j=m; j>0; j-- )
		{	if (s1[i-1] == s2[j-1] )
				a[i][j]=a[i+1][j+1];
			else
			{	a[i][j]= a[i][j+1] < a[i+1][j] ? a[i][j+1] : a[i+1][j];
				if ( a[i+1][j+1] < a[i][j] )
					a[i][j]=a[i+1][j+1];
				a[i][j]++;
			}
		}
	}
	/*
	for ( int i=1; i<=n+1; i++ )
	{	for ( int j=1; j<=m+1; j++ )
			printf("%d ",a[i][j]);
		printf("\n");
	}
	*/
	return a[1][1];
}

/*
f(i,j) 	= f(i-1,j-1)	if S1[i]=S2[j]
	  min ( f(i-1,j-1) + cr
		f(i,j-1) + ci
		f(i-1,j) + cd
		)
		assuming all costs =1

indexing in code is 1 based

a[i][j] -> minimum no. of operations needed for S1[i->n] and S2[j->n]

Now spl case is when eg.
a
bc

or

a
ab

a[len1+1][j]	means S1 is empty and has no characters and S2 has m-j+1 characters NOT j characters left
Remeber a[i][j] solves substring S1[i->N] and S2[J->M]
so we need to add all M-j+1 characters
        for ( int i=1; i<=m; i++ )
                a[n+1][i]=m-i+1;

similarly if a[i][len2+1] means S2 is empty and has no characters and S1 has n-i+1 characters NOT i characters left
Remeber a[i][j] solves substring S1[i->N] and S2[J->M]
so we need to add all N-i+1 characters
        for ( int i=1; i<=n; i++ )
                a[i][m+1]=n-i+1;

Above 2 cases handle following in GFG code link-
http://www.geeksforgeeks.org/dynamic-programming-set-5-edit-distance/
if( m == 0 && n == 0 )
        return 0;
 
    if( m == 0 )
        return n;
 
    if( n == 0 )
        return m;

 a[len1+1][len2+2]=0 (both empty)
*/
