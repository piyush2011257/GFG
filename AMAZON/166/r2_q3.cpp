/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-166-sde/
 You have been given time intervals of a you tube video watched mostly. You have to find out the most watched time interval, so that you can put an ad in between that section.

1 4	1
2 6	2
3 7	3
4 8	4
5 10	5
2 9	6
7 8	7
3 9	8


time interval  	+1 +2 +2 +3 +3 -4 +4 +5 -6 -7 +7 -8 -8 -9 -9 -10		( + start - stop )
interval index	 1  2  6  3  8  1  4  5  2  3  7  4  7  6  8  5

no. of intervals 1  2  3  4  5  4  5  6  5  4  5  4  3  2  1  0
		         (1,2,6,3,8)
			      (2,6,3,8,4)

	        		  (2,6,3,8,4,5)				5 -> 6th interval


	 		             (6,3,8,4,5)
	                   		(6,8,4,5,7)
max_interval found -> start time= time_interval[i]
		      end time= time_interval[i+1]

for ( i=0 -> N-2 )
N-1 will be -ve for sure

O(nlogn) solution ->  reduced to nlog2
Merge 2 sorted arrays - start and end ( using heap of size 2 )
log2 is a constant -> O(N)

Alternate- MergeSort merging- O(N)

2N entries
*/

#include<cstdio>
#include<algorithm>
using namespace std;

const int len=5;

inline int mod ( int a )
{	if ( a < 0 )
		return a*(-1);
	return a;
}

bool cmp ( int a, int b )
{	if ( mod(a) < mod(b) )
		return 1;
	if ( mod(a) == mod(b) )
	{	if ( a == b )
			return 1;			// take care of this
		if ( a < b )
			return 1;
		return 0;
	}
	return 0;
}

int main()
{	/*int inter[len][2]={ 	{1,4},
				{2,6},
				{3,7},
				{4,8},
				{5,10},
				{2,9},
				{7,8},
				{3,9},
				};
	*/
	int inter[len][2]={	{1,6},
				{2,6},
				{3,6},
				{4,6},
				{5,6},
			  };
	int intervals[2*len];
	for ( int i=0,j=0; i<len; i++, j+=2 )
	{	intervals[j]=inter[i][0];
                intervals[j+1]=inter[i][1]*(-1);
	}
	sort(intervals, intervals+(2*len),cmp);			// preference in ending over starting in sorting order
	for ( int i=0; i<2*len; i++ )
		printf("%d ", intervals[i]);
	printf("\n");
	int max=0;
	int max_s, max_e;
	for ( int i=0, count=0; i<(2*len)-1; i++ )		// for sure n-1 is -ve to be valid entry of intervals
	{	if ( intervals[i] > 0 )				// at each i either increment or decrement in count. Not steady for consecutive
		{	count++;
			if ( count > max )
			{	max=count;
				max_s=intervals[i];
				max_e=intervals[i+1];		// if next is greater then it will override
			}
		}
		else
			count--;
	}
	// we could use a DLL + Map to maintain index of intervals currently in the interval
	printf("max: %d max_start: %d max_end: %d\n", max, max_s, mod(max_e));
	return 0;
}
