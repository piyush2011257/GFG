/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-173-campus/
Given Two sorted array of size size n each. Find the Kth largest element in these two array (Expected Time Complexity Log(n))
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int find_median ( int *a, int s1, int e1, int *b, int s2, int e2, int k );

int main()
{	int n,m,k;
	cin>>n>>m;
	int a[n], b[m];
	for ( int i=0; i<n; i++ )
		cin>>a[i];
	for ( int i=0; i<m; i++ )
		cin>>b[i];
	cin>>k;
	cout<<find_median(a,0,n-1,b,0,m-1,k)<<endl;;
	return 0;
}

int find_median ( int *a, int s1, int e1, int *b, int s2, int e2, int k )
{	int n=e1-s1+1;
	int m=e2-s2+1;
	//cout<<s1<<" "<<e1<<" "<<s2<<" "<<e2<<" "<<k<<endl;
	if ( n > 0 & m > 0 && n + m <= 4 )
	{	int tmp[4];
		for ( int i=0; i<n; i++ )
			tmp[i]=a[i];
		for ( int i=0,j=n; i<m; i++, j++ )
			tmp[j]=b[i];
		sort(tmp,tmp+n);
		return tmp[k-1];
	}
	else if ( n == 0 || m == 0 )
	{	if ( n == 0 )
			return b[s2+k-1];
		else
			return a[s1+k-1];
	}
	int m1=(s1+e1)/2;
	int m2=(s2+e2)/2;
	//cout<<"m1: "<<m1<<" m2: "<<m2<<endl;
	if ( a[m1] <= b[m2] )
	{	if ( k <= n/2 + ( n%2 !=0 ) )			// smallest half
		/* If k asks for first n/2 + ( n%2 != 0 ) smallest numbers, then answer in the first half of a 
		*/
		{	//cout<<"yo"<<endl;
			return a[s1+k-1];		// Wrong !!
		}
		else if ( k >= n+m/2+(m%2 != 0) )			// largest half
		/* If k asks for last m/2 + ( m%2 != 0 ) largest numbers, then answer in the last  half of b 
                */
		{	//cout<<"yo2 "<<s2+k-n-m/2-(m%2 != 0)<<endl;
			return b[s2+k-n-1];
		}
		else
			return find_median(a,m1+1,e1,b,s2,e2,k-(n/2)-(n%2 != 0 ));
		/* Else prune the unnecessary smallest elements only. We cannot prune largest elements since we do  not know
		Consider
		1 2 3 4 5
		6 7 8 9 10
		3 < 8
		so 1 2 are for sure not amongst solution range if k >= 3  since 1 and 2 are smaller than 3
		so we can prune them for sure
		*/ 
	}
	else
        {       if ( k <= m/2 + ( m%2 !=0 ) )                   // smallest half
                        return b[s2+k-1];
                else if ( k >= m+n/2+(n%2 != 0) )                       // largest half
                        return a[s1+k-m-1];
                else
                        return find_median(a,s1,e1,b,m2+1,e2,k-(m/2)-(m%2 != 0 ));
        }

}
