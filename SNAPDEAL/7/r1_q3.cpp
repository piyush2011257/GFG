/*
http://www.geeksforgeeks.org/snapdeal-interview-experience-set-7-campus/
Given an array where each element is the money a person have and there is only Rs. 3 note. We need to check whether it is possible to divide the money equally among all the persons or not. If it is possible then find Minimum number of transactions needed.

Idea similar to-
http://www.geeksforgeeks.org/minimize-cash-flow-among-given-set-friends-borrowed-money/
*/

#include<cstdio>
#include<iostream>
using namespace std;

void func ( int *a, int n );

int abs ( int a )
{	if ( a < 0 )
		a*=-1;
	return a;
}

int main()
{	int n;
	cin>>n;
	int a[n];
	for ( int i=0; i<n; i++ )
		cin>>a[i];
	func(a,n);
	return 0;
}

void func ( int *a, int n )
{	int cost[n];
	float avg=0;
	for ( int i=0; i<n; i++ )
		avg+=a[i];
	avg/=(float)n;
	if ( avg != (int)avg )				// should be integral only
	{	printf("Not possible. Avg: %f\n",avg);
		return;
	}
	//cout<<"avg: "<<avg<<endl;
	for ( int i=0; i<n; i++ )
	{	cost[i]=0;
		cost[i]=(int)a[i]-avg;
		if ( cost[i] % 3 != 0 )			// only 3 ruppees notes
		{	printf("Not possible. Cost[%d]: %d\n", i, cost[i]);
			return;
		}
	}
	/*
	for ( int i=0; i<n; i++ )
		cout<<cost[i]<<" ";
	cout<<endl;
	*/
	// cost sum of +ve and -ve
	int max_pos, min_pos, max, min, transaction=0;
	do
	{	max_pos=min_pos=-1;
		max=min=0;
		for ( int i=0; i<n; i++ )
		{	if ( cost[i] > 0 && a[i] > max )
			{	max_pos=i;
				max=cost[i];
			}
			else if ( cost[i] < 0 && abs(a[i]) > min )
			{	min_pos=i;
				min=abs(cost[i]);
			}
		}
		if ( ( max_pos == -1 && min_pos != -1 ) || ( max_pos == -1 && min_pos != -1 ) )
		{	printf("Not possible\n");
			return;
		}
		else if ( !(max_pos == -1 && min_pos == -1 ) )
		{	int val = abs(cost[min_pos]) < cost[max_pos] ? abs(cost[min_pos]) : cost[max_pos];
			cost[min_pos] += val;
			cost[max_pos] -= val;
			transaction++;
		}
	} while ( min_pos != -1 && max_pos != -1 );
	cout<<transaction<<endl;
}
