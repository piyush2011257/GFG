/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-155-campus/
ou are given a long array and window size w. You can only view elements that are currently in the window. Window starts at the extreme left and moves one position at a time to the right. You are required to output minimum numbers in the current window.
All the possible approaches were discussed. Starting from brute force, o(nw) to o(nlogw) using heaps, BSTs. He asked me to implement them. But he was not satisfied with o(nlogw) solution. He wanted me to give a o(n) solution. Finally after few hints I’ve solved it using doubly linked lists.

http://softwarelearner.blogspot.in/2011/04/minima-in-sliding-window.html
http://www.geeksforgeeks.org/maximum-of-all-subarrays-of-size-k/
http://leetcode.com/2011/01/sliding-window-maximum.html
Minima in a sliding window
*/
#include<cstdio>
#include<deque>
using namespace std;

int main()
{	int a[100];
	int n,w;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ )
		scanf("%d",&a[i]);
	scanf("%d",&w);
	deque<int> q;
	if ( n > 0 )
		q.push_front(0);
	for ( int i=1; i<w && i < n; i++ )
	{	while ( q.empty() == 0 && a[i] < a[q.front()] )
			q.pop_front();
		if ( q.empty() == 1 || a[i] > a[q.front()] )
			q.push_front(i);
	}
	int min= q.empty() == 0 ? q.back() : -1;
	//printf("min: %d rear: %d front: %d\n", a[min], q.back(), q.front());
	for ( int in=w, rem=0; in < n; in++, rem++ )
	{	if ( q.back() == rem )
			q.pop_back();
		while ( q.empty() == 0 && a[in] < a[q.front()] )
			q.pop_front();
		if ( q.empty() == 1 || a[in] > a[q.front()] )
                        q.push_front(in);
		min= a[q.back()] < a[min] ? q.back() : min;
	        printf("min: %d rear: %d front: %d\n", a[min], q.back(), q.front());
	}
	if ( min != -1 )
		printf("%d\n", a[min]);
	else
		printf("No min. Empty input array\n");
	return 0;
}
