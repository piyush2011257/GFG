/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-176-sde-1/

You are given two array of “n” length. First array contains the arrival time of various trains on a particular station. Second array contains the departure time of those trains. Write an algorithm to find out the minimum number of platforms that will be required to accommodate all the trains.
http://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/
*/

#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int mod ( int a )
{	return a < 0 ? -a : a;
}

bool cmp ( int a, int b )
{	if ( mod(a) <= mod(b) )
		return 1;
	return 0;
}

int main()
{	int n;
	cin>>n;
	int a[n][2];
	for ( int i=0; i<n; i++ )
		cin>>a[i][0]>>a[i][1];
	int inter[n*2];
	for ( int i=0; i<n; i++ )
	{	inter[i*2]=a[i][0];
		inter[i*2+1]=-a[i][1];
	}
	sort(inter,inter+(2*n),cmp);
        for ( int i=0; i<n*2; i++ )
                cout<<inter[i]<<" ";
	cout<<endl;
	int ct=0, max_ct=0;
	for ( int i=0; i<2*n; i++ )
	{	if ( inter[i] > 0 )
		{	ct++;
			if ( ct > max_ct )
				max_ct=ct;
		}
		else
			ct--;
	}
	cout<<max_ct<<endl;
	return 0;
}
