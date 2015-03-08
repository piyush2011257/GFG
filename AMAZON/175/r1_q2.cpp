/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-175-sde/

Given an array ar[] of length ‘n’ and an integer ‘k’ such that k < n. You need to maintain a window of size 'k' starting from i=0 to i=k and print the MAX of that segment. The window moves forward by 1 element. 

http://www.geeksforgeeks.org/maximum-of-all-subarrays-of-size-k/
*/

#include<cstdio>
#include<iostream>
#include<deque>			// deque - push / pos in front / back
using namespace std;

bool func ( int *a, int n , deque<int> q, int k );

int main()
{	int n, k;
	cin>>n;
	int a[n];
	for ( int i=0; i<n; i++ )
		cin>>a[i];
	cin>>k;
	deque<int> q;
	func (a,n,q,k);
	return 0;
}

bool func ( int *a, int n , deque<int> q, int k )
{	for ( int i=0; i<n && i < k; i++ )
	{	while( q.empty() == 0 && q.back() < a[i] )		// NOT <=
			q.pop_back();
		q.push_back(a[i]);
	}
	cout<<q.front()<<endl;
	int s=1, e=k;
	while ( e < n )
	{	if ( a[s-1] == q.front() )
			q.pop_front();
		while( q.empty() == 0 && q.back() < a[e] )
                        q.pop_back();
                q.push_back(a[e]);
		cout<<q.front()<<endl;
		s++;
		e++;
	}
}

