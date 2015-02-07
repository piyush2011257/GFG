/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-159-off-campus/
Given two arrays S1 and S2 of characters. You need to find the smallest length of substring in S1 which contains all the characters of S2. Characters need not be in the same order as in S2. Characters might be repeating in S1.

http://leetcode.com/2010/11/finding-minimum-window-in-s-which.html
Finding the Minimum Window in S which Contains All Elements from T
*/

#include<cstdio>
#include<cstring>
using namespace std;

void func ( char *s1, char *s2, int n1, int n2, int *count2 );

int main()
{	char s1[100], s2[100];
	scanf("%s %s",s1,s2);
	int count[256]={0};
	int n1=strlen(s1);
	int n2=strlen(s2);
	for ( int i=0; i < n2; i++ )
		count[s2[i]]++;
	func(s1,s2,n1,n2,count);
	return 0;
}

void func ( char *s1, char *s2, int n1, int n2, int *count2 )
{	int low=-1, high=0, min_high, min_low;
	int ct1=0;
	int count1[256]={0};
	// initial window
	while ( ct1 < n2 && high < n1 )
	{	if ( count2[s1[high]] > 0 )
		{	count1[s1[high]]++;
			if ( count1[s1[high]] <= count2[s1[high]] )
				ct1++;
			if ( low == -1 )
				low=high;
		}
		high++;
	}
	min_high=high-1;
	min_low=low;
	if ( ct1 < n2 )
	{	printf("No window\n ");
		return;
	}
	if ( high == n1 )
	{	printf("%d low: %d high: %d\n", high-low, min_low, min_high );
		return;
	}
	if ( n2 == 1 )
	{	printf("%d low: %d high: %d\n", high-low, min_low, min_high );
		return;
	}
	// Now we have a window and more elements present to scan
	int min=high-low;
	// corner case if single element s2
	while ( high < n1)
	{	while ( ct1 == n2 || count2[s1[low]] == 0 || count1[s1[low]] > count2[s1[low]] )		// corner conditions last 2
		{	if ( count2[s1[low]] > 0 )
			{	count1[s1[low]]--;
				if ( count1[s1[low]] < count2[s1[low]] )
					ct1--;
			}
			low++;
		}
		while ( ct1 < n2 && high < n1 )
        	{       if ( count2[s1[high]] > 0 )
        	        {       count1[s1[high]]++;
                	        if ( count1[s1[high]] <= count2[s1[high]] )
					ct1++;
                	}
                	high++;
        	}
		if ( min > (high-low) )
		{	min=(high-low);
			min_high=high-1;
			min_low=low;
		}
	}
	printf("%d low: %d high: %d\n", min, min_low, min_high );
}
